:- ['./eval.pl','./choose.pl'].

% helper functions
notOne(A) :- eval(A,Av), Av =\= 1.
notZero(A) :- eval(A,Av), Av =\= 0.
isFactor(A,B) :- eval(A,Av), eval(B,Bv), 0 is Bv rem Av.

% arithop(A,B,C) succeeds if C is a valid combination of A and B
% e.g., arithop(A,B,plus(A,B)).
arithop(A,B,plus(A,B)).
arithop(A,B,minus(A,B)) :- eval(A,A1), eval(B,B1), A1 > B1.
arithop(A,B,minus(B,A)) :- eval(A,A1), eval(B,B1), B1 > A1. % since minus is not commutative
arithop(A,B,mult(A,B)) :- notOne(A), notOne(B). % since mult by one does not progress the calculuation
arithop(A,B,divide(A,B)) :- notOne(B), notZero(B), isFactor(B,A).
arithop(A,B,divide(B,A)) :- notOne(A), notZero(A), isFactor(A,B).