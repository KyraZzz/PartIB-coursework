% prim(A,B) succeeds if A is a number and B is its primitiev representation
prim(0,z).
prim(A,s(B)) :- prim(DecA,B), A is DecA + 1.
% plus(A,B,C) succeeds if C is A + B (all in primitive representations, A and B are both ground terms)
plus(A,B,C) :- prim(NA,A), prim(NB,B), prim(NC,C), NC is NA + NB.
% mult(A,B,C) succeeds if C is A * B (all in primitive representations, A and B are both ground terms)
mult(A,B,C) :- prim(NA,A), prim(NB,B), prim(NC,C), NC is NA * NB.