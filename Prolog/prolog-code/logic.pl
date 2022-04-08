% and(A,B). lit(A). or(A,B). neg(A).
% remove double negation
cnf(neg(neg(A)), Av) :- cnf(A, Av). 
% demorgan1
cnf(neg(and(A,B)), R) :- cnf(or(neg(A), neg(B)), R). 
% demorgan2
cnf(neg(or(A,B)), R) :- cnf(and(neg(A), neg(B)), R). 
cnf(neg(lit(A)), neg(lit(A))).
%recursively applying distributive rule
cnf(or(A, and(B,C)), Rs) :- cnf(and(or(A,B), or(A,C)), R), !, cnf(R, Rs). 
cnf(or(and(A,B), C), Rs) :- cnf(and(or(A,B), or(A,C)), R), cnf(R,Rs).
% once no longer reduceable
cnf(and(A,B), and(Av, Bv)) :- cnf(A, Av), cnf(B, Bv).
cnf(or(A,B), or(Av, Bv)) :- cnf(A, Av), cnf(B, Bv).
% base case for literals
cnf(lit(A), lit(A)).