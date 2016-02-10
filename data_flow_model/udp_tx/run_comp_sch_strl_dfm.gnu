set xlabel "udp transmitter"
set xtics ("Running Time" 1, "Computing Time" 2, "Scheduling Time" 3)
set ylabel "MCycles"
set y2label "%CPU"
set ytics nomirror
set y2tics
set title "Performance Results on 365.8 MHz machine (for 20.000000 seconds)"
set time
set grid
set boxwidth 0.33
set y2range [0:102]
plot [0:4][0:7471] "-" title "cycles" w boxes
0.833333 6792.037376
1.833333 256.731600
2.833333 6535.305728
e
