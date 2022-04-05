% preorder(+Tree, -ValueList)
preorder(nil, []).
preorder(Lc-R+Rc, [R|V]) :- preorder(Lc, VLc), preorder(Rc, VRc), append(VLc, VRc, V).

preorder2(nil-R+nil, [R]).
preorder2(nil-R+Rc, V) :- preorder2(Rc, VRc), append([R], VRc, V).
preorder2(Lc-R+nil, V) :- preorder2(Lc, VLc), append([R], VLc, V).
preorder2(Lc-R+Rc, V) :- preorder2(Lc, VLc), preorder2(Rc, VRc), 
												append([R], VLc, Temp), append(Temp, VRc, V).