:- ['./choose.pl','./arithop.pl','range.pl'].
% helper function 
diff(Target,Value,Diff) :- Delta is Target - Value, (Delta < 0, Diff is -Delta; Delta >= 0, Diff is Delta).
% countdownThresh(L,Target,Soln,Thresh) uses iterative deepening to find the closest possible solution for the count down problem
countdownThresh([Soln|_], Target, Soln, Thresh) :- eval(Soln,Value), diff(Target, Value, Thresh).
countdownThresh(L, Target, Soln, Thresh) :- choose(2, L, [A,B], R), arithop(A, B, C), countdownThresh([C|R], Target, Soln, Thresh).

% countdownClosest(L,Target,Soln,D)
countdownClosest(L,Target,Soln,D) :- range(0,100,D), countdownThresh(L,Target,Soln,D).