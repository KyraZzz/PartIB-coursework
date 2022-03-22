% ring(A,B,C) represents the states of the three pegs A,B,C.
% start state: ring([1,2,3],[],[]).
% finish state: ring([],[],[1,2,3]).

% moveBetwen(+A1,+B1,-A2,-B2) succeeds if we can move the head of A1 onto B1, forms A2 and B2 respectively
moveBetwen([AH|T],[],T,[AH]).
moveBetwen([AH|AT],[BH|BT],AT,[AH,BH|BT]) :- AH < BH.

% state(+Before, -After) succeeds if we can move from the state Before to the state After
state(ring(A,B,C),ring(AF,BF,C)) :- moveBetwen(A,B,AF,BF).
state(ring(A,B,C),ring(AF,BF,C)) :- moveBetwen(B,A,BF,AF).
state(ring(A,B,C),ring(AF,B,CF)) :- moveBetwen(A,C,AF,CF).
state(ring(A,B,C),ring(AF,B,CF)) :- moveBetwen(C,A,CF,AF).
state(ring(A,B,C),ring(A,BF,CF)) :- moveBetwen(B,C,BF,CF).
state(ring(A,B,C),ring(A,BF,CF)) :- moveBetwen(C,B,CF,BF).

search(State_from,State_to,Path) :- state(State_from,State_to), print(Path).
search(State_from,State_to,Path) :- state(State_from,Next_State), \+member(Next_State,Path), search(Next_State,State_to,[Next_State|Path]).

% solve :- search(ring([1,2,3],[],[]),ring([],[],[1,2,3]),[]). 