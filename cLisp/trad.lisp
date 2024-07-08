(defvar a 0)
(defvar *vec1* (make-array 10))
(defvar *vec2* (make-array 3))
(defun main () 
(let ((z 0))
(setq z (reduce #'+ (map 'list #'* *vec1* *vec2*)))
z
))
(main)
