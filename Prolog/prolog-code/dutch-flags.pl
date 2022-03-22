:- include('./permutation.pl').
% flag(In) succeeds if a permutation of In is in consecutive red, while, blue order
flag(In) :- perm(In,Out), checkRed(Out).
checkRed([red|T]) :- checkRed(T).
checkRed([white|T]) :- checkWhite(T).
checkWhite([white|T]) :- checkWhite(T).
checkWhite([blue|T]) :- checkBlue(T).
checkBlue([blue|T]) :- checkBlue(T).
checkBlue([]).
