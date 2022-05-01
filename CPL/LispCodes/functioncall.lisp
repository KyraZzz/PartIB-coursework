(defun CountFrom(n) (CountFrom(+ n 1)))
(defun myTextIf (x y z) (cond (x (eval y)) (T (eval z))))
(defun myNameIf (x y z) (cond (x (apply y ()))(T (apply z ()))))

;; (myTextIf (eq x z) (quote y) (quote (CountFrom 0))) ; gives y, not 7
;; (myNameIf (eq x z) (lambda () y) (lambda () (CountFrom 0))) ; gives 7
