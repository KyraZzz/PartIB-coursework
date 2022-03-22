:- include('./permutation.pl').
% eightQueen(R) succeeds if there is no queen sharing a diagonal/row/column for the arrangment R
eightQueen(R) :- perm([1,2,3,4,5,6,7,8],R), checkDiagonals(R).
checkDiagonals([]).
checkDiagonals([Q|Qs]) :- checkDiagonals(Qs,Q,1), checkDiagonals(Qs).
checkDiagonals([],_,_).
checkDiagonals([Q|Qs],Q0,D0) :- Q0 =\= Q, abs(Q0 - Q) =\= D0, D1 is D0 + 1, checkDiagonals(Qs,Q0,D1).