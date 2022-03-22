:- use_module(library(bounds)).

% use the library bounds to ensure all elements in L are different, and within the range 1..4
diffConstraints(L) :- L in 1..4, all_different(L).

rowsConstraints([A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P]) :- diffConstraints([A,B,C,D]), diffConstraints([E,F,G,H]), diffConstraints([I,J,K,L]), diffConstraints([M,N,O,P]).
columnsConstraints([A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P]) :- diffConstraints([A,E,I,M]), diffConstraints([B,F,J,N]), diffConstraints([C,G,K,O]), diffConstraints([D,H,L,P]).
boxesConstraints([A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P]) :- diffConstraints([A,B,E,F]), diffConstraints([C,D,G,H]), diffConstraints([I,J,M,N]), diffConstraints([K,L,O,P]).

sudokuConstraints(L) :- rowsConstraints(L), columnsConstraints(L), boxesConstraints(L), label(L).