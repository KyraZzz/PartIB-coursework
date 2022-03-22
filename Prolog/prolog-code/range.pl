% range(+LB, +UB, ?D) succeeds if D is a number within LB and UB, left-inclusive, right-exclusive.
range(LB, UB, LB) :- UB > LB.
range(LB, UB, D) :- LB1 is LB + 1, UB > LB1, range(LB1, UB, D).