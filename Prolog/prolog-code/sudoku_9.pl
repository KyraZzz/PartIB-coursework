:- include('./permutation.pl'). 
:- include('./take.pl').

% for a board of 9 * 9, call rows from A - I
% need to test the 9 boxes (3 * 3), 9 columns and 9 rows, each containing 0 - 9

% gen_digits(?L) succeeds if L is a permutation of [1,2,3,4,5,6,7,8,9]
% NB: it will deliver multiple results if there are _ in L
gen_digits(L) :- perm([1,2,3,4,5,6,7,8,9],L).

% test_digits(L) succeeds if L contains digits and(or) variables
% 	digits are unique from 1 - 9
test_digits(L) :- test_set(L, [1,2,3,4,5,6,7,8,9]).

% test_set(L1,L2) succeeds if
%   input list L1 contains digits and(or) variables or is [] and
%   all the digits in L1 are unique from input list L2
test_set([], _).
test_set([H|T],Digits) :- var(H), test_set(T, Digits).
test_set([H|T],Digits) :- ground(H), take(Digits,H,RemainingDigits), test_set(T,RemainingDigits).

% heads(+LL,?LHeads,?LTails) succeeds if:
%	LL is an input list of lists
%	LHeads is a list of the heads of each list in LL
%	LTails is LL with the head of each list removed.
heads([],[],[]).
heads([[H|T1]|T],[H|Hs],[T1|Tails]) :- heads(T,Hs,Tails).

% test_cols(Rows) succeeds if
% 	input Rows is a list of lists of digits and variables
%	each 'column' of digits and variables contain unique digits from 1 - 9
test_cols([[]|_]).
test_cols(Rows) :- heads(Rows,Heads,Tails), test_digits(Heads), test_cols(Tails).

% test_boxes(RowA, RowB, RowC) succeeds if:
% 	RowA, RowB, RowC are input lists of 9 unique digits 1 - 9
%	each aligned 3 * 3 box contains 9 unique digits 1 - 9
% NB: by time of test, boxes are fully initiated
test_boxes([A1,A2,A3,A4,A5,A6,A7,A8,A9],
		   [B1,B2,B3,B4,B5,B6,B7,B8,B9],
		   [C1,C2,C3,C4,C5,C6,C7,C8,C9]) :- test_digits([A1,A2,A3,B1,B2,B3,C1,C2,C3]),
		   									test_digits([A4,A5,A6,B4,B5,B6,C4,C5,C6]),
		   									test_digits([A7,A8,A9,B7,B8,B9,C7,C8,C9]).

% solve(A,B,C,D,E,F,G,H,I) procedure:
% 	generate numbers for each row, ensure each contains 1 - 9
% 	test the columns
%	test the 3 * 3 boxes once all entry in that box is initiated
solve(A,B,C,D,E,F,G,H,I) :- 
		gen_digits(A),
		test_cols([A,B,C,D,E,F,G,H,I]),
		gen_digits(B),
		test_cols([A,B,C,D,E,F,G,H,I]),
		gen_digits(C),
		test_cols([A,B,C,D,E,F,G,H,I]),
		test_boxes(A,B,C),
		gen_digits(D),
		test_cols([A,B,C,D,E,F,G,H,I]),
		gen_digits(E),
		test_cols([A,B,C,D,E,F,G,H,I]),
		gen_digits(F),
		test_cols([A,B,C,D,E,F,G,H,I]),
		test_boxes(D,E,F),
		gen_digits(G),
		test_cols([A,B,C,D,E,F,G,H,I]),
		gen_digits(H),
		test_cols([A,B,C,D,E,F,G,H,I]),
		gen_digits(I),
		test_cols([A,B,C,D,E,F,G,H,I]),
		test_boxes(G,H,I),
		test_cols([A,B,C,D,E,F,G,H,I]).

:- A = [5,3,_,_,7,_,_,_,_],
   B = [6,_,_,1,9,5,_,_,_],
   C = [_,9,8,_,_,_,_,6,_],
   D = [8,_,_,_,6,_,_,_,3],
   E = [4,_,_,8,_,3,_,_,1],
   F = [7,_,_,_,2,_,_,_,6],
   G = [_,6,_,_,_,_,2,8,_],
   H = [_,_,_,4,1,9,_,_,5],
   I = [_,_,_,_,8,_,_,7,9],
   solve(A,B,C,D,E,F,G,H,I),
   print(A),nl,
   print(B),nl,
   print(C),nl,
   print(D),nl,
   print(E),nl,
   print(F),nl,
   print(G),nl,
   print(H),nl,
   print(I),nl.
