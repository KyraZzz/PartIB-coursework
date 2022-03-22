% fact(+N,?FN) succeeds if FN is N!
fact(1,1).
fact(N,FN) :- N > 1, M is N - 1, fact(M, FM), FN is N * FM.