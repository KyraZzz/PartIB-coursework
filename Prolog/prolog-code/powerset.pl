% powerset(L,PowL) succeeds if PowL is a powerset of L
powerset([],[]).
powerset([_|T],R) :- powerset(T,R). % does not include head 
powerset([H|T],[H|R]) :- powerset(T,R). % does include head

% powersetAll(+S, -PS) unifies PS with the powerset of S
powersetAll([],[[]]).
powersetAll([H|T], Ans) :- powersetAll(T, PSofT), addToLists(H, PSofT, Ans).

addToLists(_,[],[]).
addToLists(H,[L|Ls],[[H|L],L|Rest]) :- addToLists(H,Ls,Rest).