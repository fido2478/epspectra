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
set y2range [0:111]
plot [0:4][0:13317] "-" title "cycles" w boxes
0.833333 12106.164224
1.833333 521.153824
2.833333 11585.009664
e
