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
set y2range [0:1]
plot [0:7][0:150] "-" title "cycles" w boxes
0.833333 0.289313
1.833333 0.592703
2.833333 25.798992
3.833333 24.691830
4.833333 47.511548
5.833333 136.315936
e
