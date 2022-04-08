% parentListAtom(+Tree, +List, -ParentList) works for atoms
parentListAtom([L, N, R], Ns, Ps) :- parentListAtom(L, N, Ns, Ps1), parentListAtom(R, N, Ns, Ps2), append(Ps1, Ps2, Ps).
parentListAtom(null, _, _, []).
parentListAtom([L, N, R], E, Ns, [[N,E]|Ps]) :- member(N, Ns), !, parentListAtom(L, N, Ns, Ps1), parentListAtom(R, N, Ns, Ps2), append(Ps1, Ps2, Ps).
parentListAtom([L, N, R], _, Ns, Ps) :- parentListAtom(L, N, Ns, Ps1), parentListAtom(R, N, Ns, Ps2), append(Ps1, Ps2, Ps).

% parentListAtomDiff(+Tree, +List, -ParentList) works for atoms, append O(1)
parentListAtomDiff([L, N, R], Ns, Ps-T) :- parentListAtomDiff(L, N, Ns, Ps-Ps2), parentListAtomDiff(R, N, Ns, Ps2-T).
parentListAtomDiff(null, _, _, A-A).
parentListAtomDiff([L, N, R], E, Ns, [[N,E]|Ps]-T) :- member(N, Ns), !, parentListAtomDiff(L, N, Ns, Ps-Ps2), parentListAtomDiff(R, N, Ns, Ps2-T).
parentListAtomDiff([L, N, R], _, Ns, Ps-T) :- parentListAtomDiff(L, N, Ns, Ps-Ps2), parentListAtomDiff(R, N, Ns, Ps2-T).


% getParentList(+Tree, +List, -ParentList) works for arithmetic numbers
getParentList([L,N,R],Ns,Ps) :- getParentList(L,N,Ns,Ps1), getParentList(R,N,Ns,Ps2), append(Ps1, Ps2, Ps).
getParentList(null, _, _, []).
getParentList([L,N,R],Pt,Ns,[[N,Pt]|Ps]) :- member(N,Ns), !, getParentList(L, N, Ns, Ps1), getParentList(R, N, Ns, Ps2), append(Ps1, Ps2, Ps).
getParentList([L,N,R],_,Ns,Ps) :- getParentList(L, N, Ns, Ps1), getParentList(R, N, Ns, Ps2), append(Ps1, Ps2, Ps).

% getParent(+Tree,+Target,-Result,+CurrentParent) only works for arithmetic numbers
getParent(null, _, [], _).
getParent([_, N, _], N, [N,Pt], Pt).
getParent([_, N, Right], H, R, _) :- H > N, getParent(Right, H, R, N).
getParent([Left, N, _], H, R, _) :- H < N, getParent(Left, H, R, N).