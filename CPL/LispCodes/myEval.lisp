(load "lookup.lisp")
(load "append.lisp")
(load "pair.lisp")
(defun eval. (e a) ;eval takes an expression e and an environment (a list of arguments a)
    (cond
        ((atom e) (lookup. e a)); case 1: e is an atom, lookup value in the environment
        ((atom (car e)); case 2: e is of the form (e1 e2 ... en)
            (cond
                ((eq (car e) 'quote) (cadr e)); case 2.1: e1 = quote
                ((eq (car e) 'atom) (atom (eval. (cadr e) a))); case 2.2: e1 = atom, recursively evaluate e2
                ((eq (car e) 'eq) (eq (eval. (cadr e) a)
                                    (eval. (caddr e) a))); case 2.3: e1 = eq, recursively evaluate e2 and e3 
                ((eq (car e) 'car) (car (eval. (cadr e) a))); case 2.4: e1 = car, recursively evaluate e2 and get the head element
                ((eq (car e) 'cdr) (cdr (eval. (cadr e) a))); case 2.5: e1 = cdr, recursively evaluate e2 and get the tail
                ((eq (car e) 'cons) (cons (eval. (cadr e) a)
                                    (eval. (caddr e) a))); case 2.6: e1 = cons, recursively evaluate e2 and e3 to v2 and v3, con v2 onto v3
                ((eq (car e) 'cond) (evcon. (cdr e) a)); case 2.7: e1 = cond
                ('t (eval. (cons (lookup. (car e) a) (cdr e))
                            a)))); case 2.8: e1 = customised function
        ((eq (caar e) 'label); case 3: recursive function call
                (eval. (cons (caddar e) (cdr e))
                (cons (list (cadar e) (car e)) a))); push a list of function name and the function itself into the enrironment
        ((eq (caar e) 'lambda); case 4: lambda function call
                (eval. (caddar e)
                (append. (pair. (cadar e) (evlis. (cdr e) a)); call evlis to get a list of values (v1...vn) of arguments (a1...an) then put (p1 v1)...(pn vn) into the environment
                a)))))

(defun evcon. (c a)
    (cond ((eval. (caar c) a) (eval. (cadar c) a))
            ('t (evcon. (cdr c) a))))
(defun evlis. (m a)
    (cond ((null. m) '())
            ('t (cons (eval. (car m) a)
            (evlis. (cdr m) a)))))