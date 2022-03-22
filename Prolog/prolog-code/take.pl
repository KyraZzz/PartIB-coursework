% take(L1,R,L2) succeeds if L2 is the input list L1 omitting element R
take([H|T],H,T).
% can take R if (body is true) we can take R from T leaving S behind
take([H|T],R,[H|S]) :- take(T,R,S).

% take_path/4 with fact as 1 and rule as 2
take_path([H|T],H,T,[1]).
take_path([H|T],R,[H|S],[2|Path]) :- take_path(T,R,S,Path).

% take_all(+L1,+X,-L2) succeeds if List L2 is L1 minus all occurrence of element X.
take_all([],_,[]).
take_all([H|T],H,R) :- take_all(T,H,R).
take_all([H|T],X,[H|R]) :- H =\= X, take_all(T,X,R).