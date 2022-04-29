% state machine for matching regExp a+b+a
t(start,1,a).
t(1,1,a).
t(1,2,b).
t(2,2,b).
t(2,3,a).
t(3,finish,end).
% apply iterative deepening to avoid infinte string
matches([],0,finish,_).
matches([H|T],N,FROM,TO) :- N > 0, M is N - 1, t(FROM,VIA,H), matches(T,M,VIA,TO).
matches(L,N) :- matches(L,N,start,finish).
matches(L,N) :- M is N + 1, matches(L,M).
matches(L) :- matches(L,0).