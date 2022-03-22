% pos(L,R) succeeds if R contains all positive values from L 
pos([],[]).
pos([H|T],[H|R]) :- H >= 0, !, pos(T,R).
pos([_|T],R) :- pos(T,R).