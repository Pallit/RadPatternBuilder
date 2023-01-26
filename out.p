set xrange [-1:1]
set yrange [-1:1]
set zrange [-1:1]
splot "data.dat" u 1:2:3 with lines
pause -1