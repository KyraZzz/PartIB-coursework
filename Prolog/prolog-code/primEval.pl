% prim(+A,-B) succeeds if B is the primitive representation of A
% e.g., B = z for A = 0
prim(0,z).
prim(A,s(B)) :- A1 is A - 1, prim(A1,B).
% plus(+A,+B,-C) succeeds if C = A + B, all in primitive representations
plus(z,B,B).
plus(s(A),B,s(C)) :- plus(A,B,C).
% mult(+A,+B,-c) succeeds if C = A * B, all in primitive representations
mult(z,_,z).
mult(s(A),B,C) :- mult(A,B,C1), plus(B,C1,C).