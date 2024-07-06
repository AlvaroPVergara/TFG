(defvar a 0)
(defvar b 0)
(defvar *vector* (make-array 10)
(defun main () (
(setf (aref vector 2) 5)
(setf (aref vector 4) 9)
(setf (aref vector 7) 17)
(setq a 0)
(dotimes (i (length vector) a)
(incf a (aref vector i))
a
)
(main)
