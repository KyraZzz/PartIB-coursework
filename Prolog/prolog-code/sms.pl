replace(_, _,[],[]).
replace(OLD, NEW, [OLD|T], [NEW|R]) :- replace(OLD, NEW, T, R).
replace(OLD, NEW, [H|T], [H|R]) :- H \= OLD, replace(OLD, NEW, T, R).

textify(_, _, [],[]).
textify(_, _, [D],[D]).
textify(_, _, [D,E], [D,E]).
textify([A,B,C], NEW, [A,B,C|T], [NEW|R]) :- textify([A,B,C], NEW, T, R).
textify([A,B,C], NEW, [D,E,F|T], [D,E,F|R]) :- [D,E,F] \= [A,B,c], textify([A,B,C], NEW, T, R).

solve :- L = [s,e,e,' ',y,o,u,' ',l,a,t,e,r,' ',k,a,t,e], textify([a,t,e],8,L,L1), textify([s,e,e],c,L1,L2), textify([y,o,u],u,L2,Answer), print(Answer), nl.