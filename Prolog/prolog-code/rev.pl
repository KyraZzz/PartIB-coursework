% rev(L1,L2) succeeds if L2 is the reverse of the input list L1
rev([],[]).
% with built-in support append(L,L1,L2) which succeeds if L2 = L @ L1
rev([H|T],L2) :- rev(T,Trev), append(Trev,[H],L2). 