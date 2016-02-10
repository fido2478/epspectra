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
plot [0:7][0:320] "-" title "cycles" w boxes
0.833333 0.619424
1.833333 1.269356
2.833333 54.535268
3.833333 49.746536
4.833333 117.721360
5.833333 291.316224
e
