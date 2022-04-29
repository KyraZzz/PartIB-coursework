% eval(A,B) succeeds if the symbolic expression A evaluates to B
eval(plus(A,B),C) :- eval(A,A1), eval(B,B1), C is A1 + B1.
eval(minus(A,B),C) :- eval(A,A1), eval(B,B1), C is A1 - B1.
eval(mult(A,B),C) :- eval(A,A1), eval(B,B1), C is A1 * B1.
eval(divide(A,B),C) :- eval(A,A1), eval(B,B1), C is A1 / B1.
eval(A,A).


% eval_cut(A,B) is a version of eval with cut
eval_cut(plus(A,B),C) :- !, eval_cut(A,A1), eval_cut(B,B1), C is A1 + B1.
eval_cut(minus(A,B),C) :- !, eval_cut(A,A1), eval_cut(B,B1), C is A1 - B1.
eval_cut(mult(A,B),C) :- !, eval_cut(A,A1), eval_cut(B,B1), C is A1 * B1.
eval_cut(divide(A,B),C) :- !, eval_cut(A,A1), eval_cut(B,B1), C is A1 / B1.
eval_cut(A,A).