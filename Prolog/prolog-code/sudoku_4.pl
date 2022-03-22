:- ['./permutation.pl'].
% Vars      Example   Solution
% A B C D   A B 4 D   3 1 4 2
% E F G H   E 2 G H   4 2 3 1
% I J K L   I J 1 L   2 4 1 3
% M N O P   M 3 O P   1 3 2 4

% diff(L) succeeds if all elements in L are different
diff(L) :- perm([1,2,3,4],L).

% check for rows, columns and boxes
rows([A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P]) :- diff([A,B,C,D]), diff([E,F,G,H]), diff([I,J,K,L]), diff([M,N,O,P]).
columns([A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P]) :- diff([A,E,I,M]), diff([B,F,J,N]), diff([C,G,K,O]), diff([D,H,L,P]).
boxes([A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P]) :- diff([A,B,E,F]), diff([C,D,G,H]), diff([I,J,M,N]), diff([K,L,O,P]).

sudoku4(L) :- rows(L), columns(L), boxes(L).