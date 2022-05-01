; (assoc. x y) takes an atom x and a list y of the form created by pair., 
; and returns the second element of the first list in y whose first element is x.
(defun lookup. (x y)
    (cond ((eq (caar y) x) (cadar y)) ; (caar e) = (car (car e)) , (cadar e) = (car (cdr (car e)))
            ('t (lookup. x (cdr y)))))