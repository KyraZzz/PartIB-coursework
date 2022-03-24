:- include('./take.pl').

% perm(L1,L2) succeeds if L1 is a permutation of L2
perm([],[]).
perm(L,[H|T]) :- take(L,H,R), perm(R,T).

sameLength([],[]).
sameLength([_|L],[_|R]) :- sameLength(L,R).

safePerm([],[]).
safePerm(L,[H|B]) :- sameLength(L,[H|B]), take(L,H,R), safePerm(R,B). 