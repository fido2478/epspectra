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
set y2range [0:32]
plot [0:7][0:3858] "-" title "cycles" w boxes
0.833333 6.693669
1.833333 15.285074
2.833333 679.470656
3.833333 659.273536
4.833333 1234.880512
5.833333 3507.281408
e
