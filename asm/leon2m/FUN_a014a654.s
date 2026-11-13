# leon2m FUN_a014a654 0xa014a654-0xa014a6e0 (140 bytes)
a014a654:  9d e3 bf 98  save  %sp, -104, %sp
a014a658:  7f ff 6a d0  call  0xa0125198
a014a65c:  90 0e 20 ff  and  %i0, 0xff, %o0
a014a660:  7f ff de ee  call  0xa0142218
a014a664:  90 0a 20 ff  and  %o0, 0xff, %o0
a014a668:  7f ff de d7  call  0xa01421c4
a014a66c:  90 0a 20 ff  and  %o0, 0xff, %o0
a014a670:  82 0a 20 ff  and  %o0, 0xff, %g1
a014a674:  b0 10 20 00  clr  %i0
a014a678:  90 10 20 10  mov  0x10, %o0
a014a67c:  80 a0 60 71  cmp  %g1, 0x71
a014a680:  02 80 00 12  be  0xa014a6c8
a014a684:  92 10 20 01  mov  1, %o1
a014a688:  80 a0 60 81  cmp  %g1, 0x81
a014a68c:  02 80 00 0c  be  0xa014a6bc
a014a690:  b0 10 3f ff  mov  -1, %i0
a014a694:  82 0e 20 ff  and  %i0, 0xff, %g1
a014a698:  92 0e 60 ff  and  %i1, 0xff, %o1
a014a69c:  90 10 00 01  mov  %g1, %o0
a014a6a0:  80 a0 60 ff  cmp  %g1, 0xff
a014a6a4:  02 80 00 0d  be  0xa014a6d8
a014a6a8:  b2 10 20 00  clr  %i1
a014a6ac:  7f ff 82 ae  call  0xa012b164
a014a6b0:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a014a6b4:  40 00 24 af  call  0xa0153970
a014a6b8:  91 ee 21 a0  restore  %i0, 0x1a0, %o0
a014a6bc:  b0 10 20 01  mov  1, %i0
a014a6c0:  90 10 20 20  mov  0x20, %o0
a014a6c4:  92 10 20 01  mov  1, %o1
a014a6c8:  40 00 1c f7  call  0xa0151aa4
a014a6cc:  01 00 00 00  nop
a014a6d0:  10 bf ff f2  b  0xa014a698
a014a6d4:  82 0e 20 ff  and  %i0, 0xff, %g1
a014a6d8:  81 c7 e0 08  ret
a014a6dc:  81 e8 00 00  restore
