# leon2m FUN_a014a768 0xa014a768-0xa014a7f4 (140 bytes)
a014a768:  9d e3 bf 98  save  %sp, -104, %sp
a014a76c:  7f ff 6a 8b  call  0xa0125198
a014a770:  90 0e 20 ff  and  %i0, 0xff, %o0
a014a774:  7f ff de a9  call  0xa0142218
a014a778:  90 0a 20 ff  and  %o0, 0xff, %o0
a014a77c:  7f ff de 92  call  0xa01421c4
a014a780:  90 0a 20 ff  and  %o0, 0xff, %o0
a014a784:  82 0a 20 ff  and  %o0, 0xff, %g1
a014a788:  b0 10 20 00  clr  %i0
a014a78c:  90 10 20 10  mov  0x10, %o0
a014a790:  80 a0 60 71  cmp  %g1, 0x71
a014a794:  02 80 00 12  be  0xa014a7dc
a014a798:  92 10 20 01  mov  1, %o1
a014a79c:  80 a0 60 81  cmp  %g1, 0x81
a014a7a0:  02 80 00 0c  be  0xa014a7d0
a014a7a4:  b0 10 3f ff  mov  -1, %i0
a014a7a8:  82 0e 20 ff  and  %i0, 0xff, %g1
a014a7ac:  92 0e 60 ff  and  %i1, 0xff, %o1
a014a7b0:  90 10 00 01  mov  %g1, %o0
a014a7b4:  80 a0 60 ff  cmp  %g1, 0xff
a014a7b8:  02 80 00 0d  be  0xa014a7ec
a014a7bc:  b2 10 20 00  clr  %i1
a014a7c0:  7f ff 82 a8  call  0xa012b260
a014a7c4:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a014a7c8:  40 00 24 6a  call  0xa0153970
a014a7cc:  91 ee 21 a0  restore  %i0, 0x1a0, %o0
a014a7d0:  b0 10 20 01  mov  1, %i0
a014a7d4:  90 10 20 20  mov  0x20, %o0
a014a7d8:  92 10 20 01  mov  1, %o1
a014a7dc:  40 00 1c b2  call  0xa0151aa4
a014a7e0:  01 00 00 00  nop
a014a7e4:  10 bf ff f2  b  0xa014a7ac
a014a7e8:  82 0e 20 ff  and  %i0, 0xff, %g1
a014a7ec:  81 c7 e0 08  ret
a014a7f0:  81 e8 00 00  restore
