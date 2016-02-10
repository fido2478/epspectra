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
set y2range [0:65]
plot [0:4][0:4724] "-" title "cycles" w boxes
0.833333 4294.967296
1.833333 109.201592
2.833333 4185.765632
e
