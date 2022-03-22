% last
% the final element of the list
%	last([],C). returns false

% write some facts
last([H],H).
last([_|T],H) :- last(T,H).

:- 	last([1,2,3],A),
	last(['B','B','A'],B),
	print(A),nl,
	print(B),nl.
