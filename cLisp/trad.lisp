(defvar a 0)
(defvar *vec1* (make-array 10))
(defun main () 
(if  (<= a 3)  (progn
(setq a 3)
)
(progn
(setq a 2)
))
a
)
(main)
