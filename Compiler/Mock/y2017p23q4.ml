let eval_2 e = eval_cps (fun x -> x) e

let eval_cps cnt e = eval_cps_util e cnt

let rec eval_cps_util = function 
  | Integer n, cnt -> cnt (INT n)
  | Pair(e1, e2), cnt -> eval_cps_util(e1, fun a -> eval_cps(e2, fun b -> cnt PAIR(a,b)))
  | Apply(f, e), cnt -> eval_cps_util(e, fun c -> cnt eval_function(f, c))

type cnt = 
  | ID (* fv = {} *)
  | CNT1 of expr * cnt
  | CNT2 of value * cnt
  | CNT3 of string * cnt

let eval_3 e = eval_cps_dfn e (fun x -> x)

let rec eval_cps_dfn = function
  | Integer n, cnt -> apply_cnt (cnt, INT n)
  | Pair(e1, e2), cnt -> eval_cps_dfn(e1, CNT1(e2, cnt))
  | Apply(f, e), cnt -> eval_cps_dfn(e, CNT3(f, cnt))

and apply_cnt = function
  | (ID, x) -> x 
  | (CNT1(e2, cnt), a) -> eval_cps_dfn(e2, CNT2(a, cnt))
  | (CNT2(a, cnt), b) -> apply_cnt (cnt, PAIR(a,b))
  | (CNT3(f, cnt), c) -> apply_cnt (cnt, eval_function(f, c))