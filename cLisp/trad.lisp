(defvar a 0)
(defvar *vec1* (make-array 10))
(defun fun1 (b vec) 
(setq b (+ b 3))
)
(defun main () 
(fun1 a *vec1*)
(return-from main 3)
(loop while  (< a 5)  do 
(setq a (+ a 1))
)
)
(main)
