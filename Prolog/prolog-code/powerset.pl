% powerset(L,PowL) succeeds if PowL is a powerset of L
powerset([],[]).
powerset([_|T],R) :- powerset(T,R). % does not include head 
powerset([H|T],[H|R]) :- powerset(T,R). % does include head
