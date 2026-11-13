# leon2m FUN_a014a6e0 0xa014a6e0-0xa014a768 (136 bytes)
a014a6e0:  9d e3 bf 98  save  %sp, -104, %sp
a014a6e4:  a0 0e 20 ff  and  %i0, 0xff, %l0
a014a6e8:  7f ff 6a ac  call  0xa0125198
a014a6ec:  90 10 00 10  mov  %l0, %o0
a014a6f0:  7f ff de ca  call  0xa0142218
a014a6f4:  90 0a 20 ff  and  %o0, 0xff, %o0
a014a6f8:  7f ff de b3  call  0xa01421c4
a014a6fc:  90 0a 20 ff  and  %o0, 0xff, %o0
a014a700:  90 0a 20 ff  and  %o0, 0xff, %o0
a014a704:  80 a2 20 71  cmp  %o0, 0x71
a014a708:  b0 10 20 00  clr  %i0
a014a70c:  02 80 00 05  be  0xa014a720
a014a710:  82 10 20 00  clr  %g1
a014a714:  80 a2 20 81  cmp  %o0, 0x81
a014a718:  02 80 00 0a  be  0xa014a740
a014a71c:  82 10 3f ff  mov  -1, %g1
a014a720:  82 08 60 ff  and  %g1, 0xff, %g1
a014a724:  80 a0 60 ff  cmp  %g1, 0xff
a014a728:  02 80 00 08  be  0xa014a748
a014a72c:  90 10 00 01  mov  %g1, %o0
a014a730:  7f ff 82 bf  call  0xa012b22c
a014a734:  01 00 00 00  nop
a014a738:  10 80 00 04  b  0xa014a748
a014a73c:  b0 10 00 08  mov  %o0, %i0
a014a740:  10 bf ff f8  b  0xa014a720
a014a744:  82 10 20 01  mov  1, %g1
a014a748:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014a74c:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a014a750:  90 12 23 f8  or  %o0, 0x3f8, %o0	! 0x1a6ff8
a014a754:  92 10 00 10  mov  %l0, %o1
a014a758:  7f fe 52 86  call  0xa00df170
a014a75c:  94 10 00 18  mov  %i0, %o2
a014a760:  81 c7 e0 08  ret
a014a764:  81 e8 00 00  restore
