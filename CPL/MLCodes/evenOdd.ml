type cnt = 
	| EVEN of int
	| ODD of int

let rec apply = function
	| (EVEN(0)) -> true
	| (ODD(0)) -> false
	| (EVEN(n)) -> apply(ODD(n-1))
	| (ODD(n)) -> apply(EVEN(n-1))

let is_even n = apply(EVEN(n))
let is_odd n = apply(ODD(n))

type tag = 
  |Even
  |Odd

let iter_apply tag n =
  let r_tag = ref tag in
  let r_cnt = ref n in
  let _ =
      while (!r_cnt != 0) do
      match !r_tag with
      | Even -> r_cnt := !r_cnt - 1; r_tag := Odd;  
      | Odd -> r_cnt := !r_cnt - 1; r_tag := Even;
      done
  in if !r_tag == Even then true else false