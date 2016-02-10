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
plot [0:7][0:3898] "-" title "cycles" w boxes
0.833333 7.034375
1.833333 15.730980
2.833333 667.276672
3.833333 665.696576
4.833333 1247.369984
5.833333 3543.245824
e
