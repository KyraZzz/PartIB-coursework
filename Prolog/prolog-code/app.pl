% app(L1,L2,L3) succeeds if L3 is the concatenation of list L1 and L2
app([],L,L).
app([H|T],L1,[H|L2]) :- app(T,L1,L2).