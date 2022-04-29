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

% map(H,L,Res) prepend H to all lists in L
map(H,[],[[H]]).
map(H,[[H1|T1]|T],[[H,H1|T1]|TR]) :- map(H,T,TR).

% chooseAll2(N,L,[],Res) succeeds if Res contains all sublists of L that contains N elements
chooseAll2(0,_,US,[US]).
chooseAll2(N,[H|T],US,L) :- N > 0, N1 is N - 1, chooseAll2(N1,T,[H|US],L1), chooseAll2(N,T,US,L2), append(L1,L2,L).
chooseAll2(N,_,_,[]) :- N < 0.
chooseAll2(N,[],_,[]) :- N > 0.