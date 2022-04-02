% len(L,N) succeeds if N is length of input list L
len([],0).
len([_|T],N) :- len(T,M), N is M + 1.

:- len([1,2,3],A), len(B,2), print(A), print(B), nl.