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
plot [0:7][0:577] "-" title "cycles" w boxes
0.833333 1.133617
1.833333 2.178835
2.833333 93.911824
3.833333 96.641648
4.833333 188.116768
5.833333 524.836384
e
