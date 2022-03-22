last([H],H).
last([_|T],H) :- last(H,T).

:- last([a,b,c],H), print(H), nl.