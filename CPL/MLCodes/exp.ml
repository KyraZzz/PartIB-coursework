type exp =
  | Var of char
  | Neg of exp
  | Divide of exp * exp
type expType = MKEXP of int * exp