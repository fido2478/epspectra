set xlabel "udp transmitter"
set xtics ("Running Time" 1, "Computing Time" 2, "Scheduling Time" 3)
set ylabel "MCycles"
set y2label "%CPU"
set ytics nomirror
set y2tics
set title "Performance Results on 602.3 MHz machine (for 20.000000 seconds)"
set time
set grid
set boxwidth 0.33
set y2range [0:109]
plot [0:4][0:13169] "-" title "cycles" w boxes
0.833333 11971.364864
1.833333 6176.221184
2.833333 5795.143680
e
