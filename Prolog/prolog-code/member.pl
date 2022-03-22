member(H,[H|_]).
member(H,[_|T]) :- member(H,T).