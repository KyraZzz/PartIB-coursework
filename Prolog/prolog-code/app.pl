% app(L1,L2,L3) succeeds if L3 is the concatenation of list L1 and L2
app([],L,L).
app([H|T],L1,[H|L2]) :- app(T,L1,L2).

% append with difference list
dapp(A-B,B-C,A-C).
% correct empty difference list P-P, unify P with [1,2,3|Q], unify R with P, unify S with Q
% dapp(P-P,[1,2,3|Q]-Q,R-S).
% wrong empty difference list []-[], cannot unify [] with [1,2,3|Q]
% dapp([]-[],[1,2,3|Q]-Q,R-S).