% choose(N,L,R,S) succeeds if R is the result of choosing N items from L and S is the remaining left in L
choose(0,L,[],L).
choose(N,[H|L],[H|R],S) :- N > 0, N1 is N - 1, choose(N1,L,R,S).
choose(N,[H|L],R,[H|S]) :- N > 0, choose(N,L,R,S).

% chooseAll(N,L,Res) succeeds if Res is a list of lists contains all possible
% ways of choosing N items from List L
chooseAll(N,L,Res) :- chooseAll(N,L,[],Res).
chooseAll(0,_,Picked,[Picked]).
chooseAll(N,[],_,[]) :- N > 0.
chooseAll(N,[H|T],Picked,Res) :- N > 0, M is N - 1, chooseAll(N,T,Picked,NCL), chooseAll(M,T,[H|Picked],CL), append(NCL,CL,Res).