set linestyle 1 lt 1 lw 1
set linestyle 2 lt 3 lw 1
set xrange [-1:1]
set yrange [-1:1]
set zrange [-1:1]
splot "antenna.dat" with points ls 2, "data.dat" u 1:2:3 with lines ls 1
pause -1