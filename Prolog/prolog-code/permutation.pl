:- include('./take.pl').

% perm(L1,L2) succeeds if L1 is a permutation of L2
perm([],[]).
perm(L,[H|T]) :- take(L,H,R), perm(R,T).