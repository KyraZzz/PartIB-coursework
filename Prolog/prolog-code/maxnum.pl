% maxnum(+L,?M) :- M is the maximum number in the list L
maxnum([H],H).
maxnum([H|T],H) :- maxnum(T,Tmax), H > Tmax.
maxnum([H|T],Tmax) :- maxnum(T,Tmax), H =< Tmax.
