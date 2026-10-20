# leon2m FUN_a009e694 0xa009e694-0xa009e708 (116 bytes)
a009e694:  9d e3 bf 98  save  %sp, -104, %sp
a009e698:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a009e69c:  b4 12 22 90  or  %o0, 0x290, %i2	! 0xa802d290
a009e6a0:  40 00 2b 47  call  0xa00a93bc
a009e6a4:  d0 0e a1 e1  ldub  [ %i2 + 0x1e1 ], %o0
a009e6a8:  c2 0e a1 e1  ldub  [ %i2 + 0x1e1 ], %g1
a009e6ac:  82 00 60 01  inc  %g1
a009e6b0:  9a 08 60 ff  and  %g1, 0xff, %o5
a009e6b4:  80 a3 60 01  cmp  %o5, 1
a009e6b8:  28 80 00 03  bleu,a   0xa009e6c4
a009e6bc:  c2 2e a1 e1  stb  %g1, [ %i2 + 0x1e1 ]
a009e6c0:  c0 2e a1 e1  clrb  [ %i2 + 0x1e1 ]
a009e6c4:  d0 0e a1 e1  ldub  [ %i2 + 0x1e1 ], %o0
a009e6c8:  40 00 2b e2  call  0xa00a9650
a009e6cc:  92 10 20 01  mov  1, %o1
a009e6d0:  15 2a 00 97  sethi  %hi(0xa8025c00), %o2
a009e6d4:  d8 0a a0 55  ldub  [ %o2 + 0x55 ], %o4	! 0xa8025c55
a009e6d8:  d2 0e a1 e1  ldub  [ %i2 + 0x1e1 ], %o1
a009e6dc:  b2 10 00 0c  mov  %o4, %i1
a009e6e0:  b0 10 20 01  mov  1, %i0
a009e6e4:  80 a2 40 0c  cmp  %o1, %o4
a009e6e8:  02 80 00 05  be  0xa009e6fc
a009e6ec:  b4 10 20 00  clr  %i2
a009e6f0:  b2 10 00 0c  mov  %o4, %i1
a009e6f4:  b0 10 20 01  mov  1, %i0
a009e6f8:  b4 10 20 01  mov  1, %i2
a009e6fc:  40 00 26 90  call  0xa00a813c
a009e700:  81 e8 00 00  restore
a009e704:  01 00 00 00  nop
