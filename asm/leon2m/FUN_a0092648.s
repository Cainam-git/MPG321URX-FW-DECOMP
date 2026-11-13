# leon2m FUN_a0092648 0xa0092648-0xa00926c8 (128 bytes)
a0092648:  9d e3 bf 98  save  %sp, -104, %sp
a009264c:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0092650:  d4 04 63 ec  ld  [ %l1 + 0x3ec ], %o2	! 0xa802afec
a0092654:  92 02 bf dd  add  %o2, -35, %o1
a0092658:  40 00 5a 24  call  0xa00a8ee8
a009265c:  90 0a 60 ff  and  %o1, 0xff, %o0
a0092660:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0092664:  a0 12 22 90  or  %o0, 0x290, %l0	! 0xa802d290
a0092668:  94 10 20 01  mov  1, %o2
a009266c:  90 10 20 00  clr  %o0
a0092670:  40 00 56 b3  call  0xa00a813c
a0092674:  d2 0c 20 1f  ldub  [ %l0 + 0x1f ], %o1
a0092678:  d0 0c 20 1f  ldub  [ %l0 + 0x1f ], %o0
a009267c:  40 00 5a 64  call  0xa00a900c
a0092680:  92 10 20 00  clr  %o1
a0092684:  82 10 20 07  mov  7, %g1
a0092688:  c2 24 63 ec  st  %g1, [ %l1 + 0x3ec ]
a009268c:  90 10 20 05  mov  5, %o0
a0092690:  40 00 86 ad  call  0xa00b4144
a0092694:  92 10 20 01  mov  1, %o1
a0092698:  40 00 6a 17  call  0xa00acef4
a009269c:  b0 10 20 23  mov  0x23, %i0
a00926a0:  90 10 20 01  mov  1, %o0
a00926a4:  40 00 5b 71  call  0xa00a9468
a00926a8:  92 10 20 02  mov  2, %o1
a00926ac:  90 10 20 00  clr  %o0
a00926b0:  40 00 83 89  call  0xa00b34d4
a00926b4:  92 10 20 01  mov  1, %o1
a00926b8:  f2 0c 20 1f  ldub  [ %l0 + 0x1f ], %i1
a00926bc:  40 00 73 64  call  0xa00af44c
a00926c0:  81 e8 00 00  restore
a00926c4:  01 00 00 00  nop
