% treeNode(3,treeNode(2,treeNode(4,nil,nil),nil),treeNode(7,treeNode(2,nil,nil),treeNode(5,nil,nil))).
bfsUtil(nil,[]).
bfsUtil(treeNode(V,nil,nil),[V]).
bfsUtil(treeNode(V,Lc,nil),[V|LcRes]) :- bfsUtil(Lc,LcRes).
bfsUtil(treeNode(V,nil,Rc),[V|RcRes]) :- bfsUtil(Rc,RcRes).
bfsUtil(treeNode(V,Lc,Rc),Res) :- bfsUtil(Lc,LcRes), bfsUtil(Rc,RcRes), append([V|LcRes],RcRes,Res).

bfs(T,Res) :- bfsUtil(T,Res), !.

diffbfsUtil(nil,[]-[]). % special case
diffbfsUtil(treeNode(V,nil,nil),[V|A]-A).
diffbfsUtil(treeNode(V,Lc,nil),[V|LcRes]-A) :- diffbfsUtil(Lc,LcRes-A).
diffbfsUtil(treeNode(V,nil,Rc),[V|RcRes]-A) :- diffbfsUtil(Rc,RcRes-A).
diffbfsUtil(treeNode(V,Lc,Rc),[V|LcRes]-A) :- diffbfsUtil(Lc,LcRes-RcRes), !, diffbfsUtil(Rc,RcRes-A).

diffbfs(T,Res) :- diffbfsUtil(T,Res), !.