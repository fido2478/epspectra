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
set y2range [0:33]
plot [0:7][0:3915] "-" title "cycles" w boxes
0.833333 6.703003
1.833333 15.326071
2.833333 676.055360
3.833333 663.623616
4.833333 1247.505152
5.833333 3558.973184
e
