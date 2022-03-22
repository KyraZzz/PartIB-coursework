% map(follow-up-lecture-2 p46/53)
% colouring the map with four difference ones where no touching regions have the same ones

% facts
diff(red, green).
diff(red, blue).
diff(red, yellow).
diff(green, blue).
diff(green, yellow).
diff(green, red).
diff(yellow, red).
diff(yellow, green).
diff(yellow, blue).
diff(blue, red).
diff(blue, green).
diff(blue, yellow).

% query
% clues first, then questions
:- diff(C1, C2), diff(C1, C4), diff(C1, C5), diff(C1, C6),
   diff(C2, C1), diff(C2, C3), diff(C2, C4), diff(C2, C7),
   diff(C3, C2), diff(C3, C7), diff(C3, C8),
   diff(C4, C1), diff(C4, C2), diff(C4, C6), diff(C4, C7),
   diff(C5, C1), diff(C5, C6), 
   diff(C6, C1), diff(C6, C4), diff(C6, C5), diff(C6, C7), diff(C6, C8),
   diff(C7, C2), diff(C7, C3), diff(C7, C4), diff(C7, C6), diff(C7, C8),
   diff(C8, C3), diff(C8, C6), diff(C8, C7),

   print([C1, C2, C3, C4, C5, C6, C7, C8]).

