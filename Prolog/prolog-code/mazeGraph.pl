% route(A,B) succeeds if there is a direct route between vertex A and vertex B
route(a,g).
route(g,l).
route(l,s).
route(g,f).
route(a,b).
route(b,c).
route(c,d).
route(d,i).
route(i,p).
route(p,q).
route(d,j).
route(j,r).
route(r,u).
route(b,h).
route(h,o).
% add routes which causes a cycle
route(q,v).
route(v,d).

% start(A) succeeds if A is the start point
start(a).

% finish(B) succeeds if B is the end point
finish(u).

% travel(A,B) succeeds if either we stay in the same position (i.e., A and B are the same points), or we can travel from A to B via some direct route, and then travel from B to C 
travel(A,A).
travel(A,C) :- route(A,B), travel(B,C).

% travellog(A,B,L) keeps a log of the path from A to B if travel(A,B) succeeds
travellog(A,A,[]).
travellog(A,C,[A->B|Steps]) :- route(A,B), travellog(B,C,Steps).

% travelsafe(A,B,Closed) succeeds if we can travel from A to B without revisiting any nodes from the Closed set
travelsafe(A,A,_).
travelsafe(A,C,Closed) :- route(A,B), \+member(B,Closed), travelsafe(B,C,[B|Closed]).

% travelsafelog(A,B,Closed,L) keeps a log of the path from A to B if travelsafe(A,B) succeeds
travelsafelog(A,A,_,[]).
travelsafelog(A,C,Closed,[A->B|Steps]) :- route(A,B), \+member(B,Closed), travelsafelog(B,C,[B|Closed],Steps).

% solve(L) succeeds if we can start from A, and travel from A to finish point B via a log of path L
solve(L) :- start(A), finish(B), travellog(A,B,L).

% solvesafe(L) succeeds in a cyclic graph, as solve is not safe in a cyclic graph
solvesafe(L) :- start(A), finish(B), travelsafelog(A,B,[],L).


