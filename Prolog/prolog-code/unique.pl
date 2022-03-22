:- ['./take.pl'].
% unique(+L1, -L2) succeeds if L2 contains a list of unique elements from L1.
unique([],[]).
unique([H|T],[H|R]) :- take_all(T,H,TRes), unique(TRes,R).