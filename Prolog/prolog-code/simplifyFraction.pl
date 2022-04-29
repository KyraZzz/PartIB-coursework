:- ['gcd.pl'].
minimalDiv(div(A,1),A).
minimalDiv(div(A,-1),B) :- B is -1 * A.
minimalDiv(A,A).
simplify(div(A,B),R) :- gcd(A,B,GCD), Av is A / GCD, Bv is B / GCD, minimalDiv(div(Av,Bv),R), !.

% reduce(A,B) succeeds if the symbolic expression A evaluates to B
reduce(add(A,B),C) :- reduce(A,div(A1,A2)), reduce(B,div(B1,B2)), Num is A1 * B2 + B1 * A2, Denom is A2 * B2, C = div(Num, Denom).
reduce(sub(A,B),C) :- reduce(A,div(A1,A2)), reduce(B,div(B1,B2)), Num is A1 * B2 - B1 * A2, Denom is A2 * B2, C = div(Num, Denom).
reduce(mul(A,B),C) :- reduce(A,div(A1,A2)), reduce(B,div(B1,B2)), Num is A1 * B1, Denom is A2 * B2, C = div(Num, Denom).
reduce(div(A,B),C) :- reduce(A,div(A1,A2)), reduce(B,div(B1,B2)), Num is A1 * B2, Denom is A2 * B1, C = div(Num, Denom).
reduce(A,div(A,1)).

reduceUtil(E,A) :- reduce(E,B), !, simplify(B,A).