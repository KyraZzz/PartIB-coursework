:- ['./choose.pl','./arithop.pl'].
% countdown(L,T,S) succeeds if the header of L is the solution for the target symbolic expressions
countdown([Soln|_], Target, Soln) :- eval(Soln, Target).
countdown(L, Target, Soln) :- choose(2, L, [A,B], R), arithop(A,B,C), countdown([C|R], Target, Soln).