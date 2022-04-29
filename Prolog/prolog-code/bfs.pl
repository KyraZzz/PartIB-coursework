% bfs(Tree, List) do a BFS search on tree, store the results in List 
bfs(Tree, List) :- bfsWalk([Tree], List).
bfsWalk([],[]).
bfsWalk([null|Q],List) :- bfsWalk(Q,List).
bfsWalk([(Lc,V,Rc)|Q],List) :- append(Q, [Lc,Rc], Qs), bfsWalk(Qs,R).

% diffbfs(Tree, List) do a BFS search on tree, store the results
diffbfs(Tree, List) :- diffbfsWalk([Tree|R]-R, List).
diffbfsWalk([]-[],[]).
diffbfsWalk([null|Q]-Q1,List) :- diffbfsWalk(Q-Q1,List).
diffbfsWalk([(Lc,V,Rc)|Q]-[Lc,Rc|B],[V|R]) :- diffbfsWalk(Q-B,R).