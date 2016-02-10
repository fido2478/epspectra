set xlabel "udp transmitter"
set xtics ("StrlFileSource" 1, "StrlBits2Symbols" 2, "StrlDigMod" 3, "StrlSum" 4, "StrlUDPSink" 5, "StrlScopeSink" 6)
set ylabel "MCycles"
set y2label "%CPU"
set ytics nomirror
set y2tics
set title "Performance Results on 602.3 MHz machine (for 20.000000 seconds)"
set time
set grid
set boxwidth 0.33
set y2range [0:5]
plot [0:7][0:575] "-" title "cycles" w boxes
0.833333 1.145308
1.833333 2.186411
2.833333 93.043536
3.833333 92.225056
4.833333 178.489056
5.833333 522.929280
e
