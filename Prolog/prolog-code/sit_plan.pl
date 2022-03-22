% assume Assigned is a list of seat(guest, left, right)
% nextTo(A,B,Assigned) succeeds if A is sitting adjancet to 
% or directly opposite B in the seating assignment Assigned
nextTo(A,B,[seat(A,B,_)|_]).
nextTo(A,B,[seat(A,_,B)|_]).
nextTo(A,B,[_|T]) := nextTo(A,B,T).


% satisfied(Assigned, Prefs) succeeds if Assigned satisfies all preferences indicated in Prefs
satisfied(_,[]).
satisfied(Assigned,[(A,[B|T1])|T2]) :- nextTo(A,B,Assigned), satisfied(Assigned, [(A,T1)|T2]).
satisfied(Assigned,[(_,[])|T1]) :- satisfied(Assigned, T1).