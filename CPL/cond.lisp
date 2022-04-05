(cond ((< 2 1) 2) ((< 1 2) 1))
(cond ((< 2 1) 2) ((< 3 2) 3))
(cond (diverge 1) (true 0))
(cond (true 0) (diverge 1))