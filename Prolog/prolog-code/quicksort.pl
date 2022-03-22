% quicksort steps: (1) partition the list into two parts, LHS <= pivot, RHS > pivot (2) quicksort on each half

% partition(+Pivot,+List,-Left,-Right) succeeds if Left is all the elements in List less than or equal to the pivot and Right is all the elements greater than the pivot
partition(_,[],[],[]).
partition(P,[H|T],[H|L],R) :- H =< P, partition(P,T,L,R).
partition(P,[H|T],L,[H|R]) :- H > P, partition(P,T,L,R).
% quicksort(+L1,-L2) succeeds if L2 contains the elements in L1 in ascending order
quicksort([],[]).
quicksort([H|T],Sorted) :- partition(H,T,L,R), quicksort(L,LSort), quicksort(R,RSort), append(LSort,[H|RSort],Sorted).

% implement uses difference list
quicksortDiff([],A-A).
% simplify the following to get rid of append
% quicksortDiff([H|T],Sorted-T1) :- partition(H,T,L,R), quicksortDiff(L,LSort-T2), quicksortDiff(R,RSort-T3), append(LSort-T2,[H|RSort]-T3,Sorted-T1).
quicksortDiff([H|T],Sorted-T1) :- partition(H,T,L,R), quicksortDiff(L,Sorted-[H|RSort]), quicksortDiff(R,RSort-T1).