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
set y2range [0:110]
plot [0:4][0:13207] "-" title "cycles" w boxes
0.833333 12006.696960
1.833333 6168.186368
2.833333 5838.510592
e
