(defvar a 0)
(defvar b 0)
(defvar *vector* (make-array 10))
(defun fun1 () 
(setf (aref *vector* 1) (+ 2 3))
(setf (aref *vector* 4) 5)
(setf (aref *vector* 7) 29)
(setf (aref *vector* 0) 1)
)
(defun main () 
(fun1)
(let ((c 0))
(setq c 0)
(dotimes (i (length *vector*) c)
(incf c (aref *vector* i)))
(print *vector*)
(setq *vector* (coerce (reverse (coerce *vector* 'list)) 'vector))
(print *vector*)
(dotimes (i (length *vector*))
(setf (aref *vector* i) (+ (aref *vector* i) 5)))
(setq b (reduce #'+ (map 'list #'* *vector* *vector*)))
(print *vector*)
(print "Hola mundo")
c
))
(main)