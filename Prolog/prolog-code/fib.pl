% declarative file definition: a reversed list of fibonacci sequence until N
% facts and rules to store in the database
f(0,[0]).
f(1,[1,0]).
f(N,[R,X,Y|T]) :- 
	N > 1, 
	N1 is N - 1,
	f(N1, [X,Y|T]),
	R is X + Y.

% query
:- f(4,Z),
   print(Z),nl. % newline symbol
   % f(N,[5,3,2,1,1,0]) is not allowed