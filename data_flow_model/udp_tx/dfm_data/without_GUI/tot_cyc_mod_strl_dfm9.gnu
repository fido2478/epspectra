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
plot [0:7][0:3866] "-" title "cycles" w boxes
0.833333 6.691266
1.833333 14.993657
2.833333 681.178752
3.833333 676.042176
4.833333 1244.111104
5.833333 3514.533376
e
