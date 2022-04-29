% len(L,N) succeeds if N is length of input list L
len([],0).
len([_|T],N) :- len(T,M), N is M + 1.

% version 1 - infinite list
lend(A-A,0).
lend([_|T]-T1,N) :- lend(T-T1,M), N is M + 1.
% :- lend([1,2,3|A]-A,B). %query
% A = [1,2,3|**], B = 0.

% version2 - destructive len (destroy difference list)
lend2([]-[],0).
lend2([_|T]-T1,N) :- lend(T-T1,M), N is M + 1.
% :- lend2([1,2,3|A]-A,B).  %query
% A = [], B = 3. % no longer have difference list but an closed normal list

% version3 - force an occurs check
lend3(A-A1,0) :- unify_with_occurs_check(A,A1).
lend3([_|T]-T1,N) :- lend(T-T1,M), N is M + 1.
% :- lend3([1,2,3|A]-A,B). % query
% B = 3 ; % leave A not modified, still a free variable