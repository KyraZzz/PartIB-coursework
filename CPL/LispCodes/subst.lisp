(defun subsitute (x y z)
                 (cond ((atom z) (cond ((eq z y) x) ('t z)))
                       ('t (cons (subsitute x y (car z))
                                (subsitute x y (cdr z))))))