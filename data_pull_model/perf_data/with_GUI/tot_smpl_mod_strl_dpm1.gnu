set xlabel "Total samples: the original udp transmitter"
set xtics ("StrlFileSource" 1, "StrlBits2Symbols" 2, "StrlDigMod" 3, "StrlSum" 4, "StrlUDPSink" 5, "StrlScopeSink" 6)
set ylabel "Samples"
set ytics nomirror
set title "Performance Results on 602.3 MHz machine (for 20.000000 seconds)"
set time
set grid
set boxwidth 0.33
plot [0:7][0:2200000] "-" title "samples" w boxes
0.833333 5000.000000
1.833333 10000.000000
2.833333 2000000.000000
3.833333 2000000.000000
4.833333 2000000.000000
5.833333 1938500.000000
e
