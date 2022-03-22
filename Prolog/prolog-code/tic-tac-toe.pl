% board
% 1 2 3
% 4 5 6
% 7 8 9

% move(Position,Player)
% game state = a list of move(Position,Player)

pos(Loc) :- member(Loc,[1,2,3,4,5,6,7,8,9]).
used(Loc,[move(Loc,_)|T]).
used(Loc,[_|T]) :- used(Loc,T).

% nextMove(Before,Player,After) succeeds if After represents the next state of the board after Player has made a move from state Before
nextMove(Before,P,[move(Loc,P)|Before]) :- pos(Loc), \+used(Loc,Before).