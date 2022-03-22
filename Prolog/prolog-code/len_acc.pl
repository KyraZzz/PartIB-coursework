% len_acc(L,N) succeeds if N is length of input list L
len_acc(L,N) :- len_acc(L,0,N).

% len_acc(L,0,N) succeeds if 
%	input L is the remaining list to be counted
% 	input A is an accumulated length so far
% 	output N is the total length of the original list
len_acc([],A,A).
len_acc([_|T],A,N) :- A1 is A + 1, len_acc(T,A1,N).
