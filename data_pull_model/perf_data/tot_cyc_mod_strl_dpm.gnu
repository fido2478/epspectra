set xlabel "udp transmitter"
set xtics ("StrlFileSource" 1, "StrlBits2Symbols" 2, "StrlDigMod" 3, "StrlSum" 4, "StrlUDPSink" 5, "StrlScopeSink" 6)
set ylabel "MCycles"
set y2label "%CPU"
set ytics nomirror
set y2tics
set title "Performance Results on 365.8 MHz machine (for 20.000000 seconds)"
set time
set grid
set boxwidth 0.33
set y2range [0:1]
plot [0:7][0:78] "-" title "cycles" w boxes
0.833333 0.105820
1.833333 0.396385
2.833333 17.525364
3.833333 18.241200
4.833333 2.281301
5.833333 70.651520
e
