% bubbleSort(X,Y) succeeds if Y is an ascending list of items in X
% (1) find out-of-order pair in X, i.e., X = A + [H1,H2] + B
% (2) swap the out-of-order pair and continue doing bubbleSort
% (3) base case is when all items in the tail is greater than the head, so no more sortiing needed
bubbleSort(X,Y) :- append(A,[H1,H2|B],X), H1 > H2, !, append(A,[H2,H1|B],X1), !, bubbleSort(X1,Y).
bubbleSort(X,X). 