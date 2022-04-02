% flatten(+In, -Out) succeeds if Out is a flattened version of In
flatten([],[]).
flatten([[H|T1]|T2], Out) :- !, append(T1, T2, T), flatten([H|T], Out).
flatten([H|T], [H|R]) :- flatten(T,R).  

% flatten2
flatten2([],[]).
flatten2([X|Xs],Ans):- flatten2(X,FX), flatten2(Xs,FXs), append(FX,FXs,Ans).
flatten2(NL,[NL]):- NL \= [], NL \= [_|_]. % if NL is an atom