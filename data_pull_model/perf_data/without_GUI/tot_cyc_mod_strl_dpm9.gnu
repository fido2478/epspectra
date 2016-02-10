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
plot [0:7][0:574] "-" title "cycles" w boxes
0.833333 1.145075
1.833333 2.174369
2.833333 95.840384
3.833333 90.536032
4.833333 179.848288
5.833333 522.070688
e
