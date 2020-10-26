set terminal pdf
set out "x-t.pdf"
set xlabel "t"
set ylabel "x"
p 'data.txt' u 1:2 t "x(t)" w l lt 1
set out "y-t.pdf"
set xlabel "t"
set ylabel "y"
p 'data.txt' u 1:3 t "y(t)" w l lt 2
set out "z-t.pdf"
set xlabel "t"
set ylabel "z"
p 'data.txt' u 1:4 t "z(t)" w l lt 3
set out "y-x.pdf"
set xlabel "x"
set ylabel "y"
p 'data.txt' u 2:3 t "y vs x" w l lt 4
set out "z-x.pdf"
set xlabel "x"
set ylabel "z"
p 'data.txt' u 2:4 t "z vs x" w l lt 5
set out "E-t.pdf"
set xlabel "t"
set ylabel "E"
p 'data.txt' u 1:8 t "E vs t" w l lt 6