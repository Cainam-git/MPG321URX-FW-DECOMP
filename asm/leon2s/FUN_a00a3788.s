# leon2s FUN_a00a3788 0xa00a3788-0xa00a3810 (136 bytes)
a00a3788:  9d e3 bf 98  save  %sp, -104, %sp
a00a378c:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a3790:  a2 10 63 6c  or  %g1, 0x36c, %l1	! 0xa807db6c
a00a3794:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00a3798:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a379c:  a1 2e 20 02  sll  %i0, 2, %l0
a00a37a0:  a4 10 63 3c  or  %g1, 0x33c, %l2
a00a37a4:  11 28 01 ae  sethi  %hi(0xa006b800), %o0
a00a37a8:  da 04 40 10  ld  [ %l1 + %l0 ], %o5
a00a37ac:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a00a37b0:  80 a3 40 01  cmp  %o5, %g1
a00a37b4:  02 80 00 0a  be  0xa00a37dc
a00a37b8:  90 12 22 90  or  %o0, 0x290, %o0
a00a37bc:  7f ff 3f 42  call  0xa00734c4
a00a37c0:  01 00 00 00  nop
a00a37c4:  11 28 01 ae  sethi  %hi(0xa006b800), %o0
a00a37c8:  90 12 22 c0  or  %o0, 0x2c0, %o0	! 0xa006bac0
a00a37cc:  7f ff 3e 1e  call  0xa0073044
a00a37d0:  92 10 00 18  mov  %i0, %o1
a00a37d4:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00a37d8:  c2 24 80 10  st  %g1, [ %l2 + %l0 ]
a00a37dc:  90 10 00 18  mov  %i0, %o0
a00a37e0:  92 10 20 31  mov  0x31, %o1
a00a37e4:  7f ff b9 44  call  0xa0091cf4
a00a37e8:  94 10 20 00  clr  %o2
a00a37ec:  82 10 20 01  mov  1, %g1
a00a37f0:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00a37f4:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a37f8:  82 10 62 08  or  %g1, 0x208, %g1	! 0xa8079208
a00a37fc:  c0 28 40 18  clrb  [ %g1 + %i0 ]
a00a3800:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a3804:  c0 28 61 aa  clrb  [ %g1 + 0x1aa ]	! 0xa80791aa
a00a3808:  81 c7 e0 08  ret
a00a380c:  91 e8 20 00  restore  %g0, 0, %o0
