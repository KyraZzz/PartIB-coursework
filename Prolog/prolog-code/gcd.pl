% gcd(+A,+B,-R) succeeds if R is gcd(A,B).
gcd(A,0,A).
gcd(A,B,R) :- B > 0, C is A mod B, gcd(B,C,R). 