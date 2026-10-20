# leon2m FUN_a01492b8 0xa01492b8-0xa01492ec (52 bytes)
a01492b8:  82 10 00 08  mov  %o0, %g1
a01492bc:  98 0a 20 ff  and  %o0, 0xff, %o4
a01492c0:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a01492c4:  90 10 20 01  mov  1, %o0
a01492c8:  80 a3 20 01  cmp  %o4, 1
a01492cc:  02 80 00 05  be  0xa01492e0
a01492d0:  c2 2b 63 d7  stb  %g1, [ %o5 + 0x3d7 ]
a01492d4:  82 13 c0 00  mov  %o7, %g1
a01492d8:  7f ff 86 a3  call  0xa012ad64
a01492dc:  9e 10 40 00  mov  %g1, %o7
a01492e0:  82 13 c0 00  mov  %o7, %g1
a01492e4:  7f ff 85 24  call  0xa012a774
a01492e8:  9e 10 40 00  mov  %g1, %o7
