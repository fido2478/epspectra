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
set y2range [0:3]
plot [0:7][0:321] "-" title "cycles" w boxes
0.833333 0.612336
1.833333 1.321052
2.833333 55.832400
3.833333 50.975024
4.833333 120.958120
5.833333 291.454880
e
