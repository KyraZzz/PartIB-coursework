% decrement list with base case an empty list
% facts & rules
a([]).
a([_|T]) :- a(T).

% singleton variable X (only one occurrence), must be replaced by _
% query
:- a(X).