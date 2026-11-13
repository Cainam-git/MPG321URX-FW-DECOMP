# leon2s FUN_a00c8a80 0xa00c8a80-0xa00c8aec (108 bytes)
a00c8a80:  9d e3 bf 98  save  %sp, -104, %sp
a00c8a84:  90 0e 20 ff  and  %i0, 0xff, %o0
a00c8a88:  82 02 00 08  add  %o0, %o0, %g1
a00c8a8c:  82 00 40 08  add  %g1, %o0, %g1
a00c8a90:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a00c8a94:  a4 13 63 b0  or  %o5, 0x3b0, %l2	! 0xa8078bb0
a00c8a98:  b1 28 60 03  sll  %g1, 3, %i0
a00c8a9c:  21 3f ff 3f  sethi  %hi(0xfffcfc00), %l0
a00c8aa0:  c2 04 80 18  ld  [ %l2 + %i0 ], %g1
a00c8aa4:  a0 14 23 ff  or  %l0, 0x3ff, %l0
a00c8aa8:  23 00 00 40  sethi  %hi(0x10000), %l1
a00c8aac:  82 08 40 10  and  %g1, %l0, %g1
a00c8ab0:  82 10 40 11  or  %g1, %l1, %g1
a00c8ab4:  c2 24 80 18  st  %g1, [ %l2 + %i0 ]
a00c8ab8:  92 10 20 00  clr  %o1
a00c8abc:  40 3b bd 47  call  0xa0fb7fd8
a00c8ac0:  94 10 20 09  mov  9, %o2
a00c8ac4:  c2 04 80 18  ld  [ %l2 + %i0 ], %g1
a00c8ac8:  9a 08 40 10  and  %g1, %l0, %o5
a00c8acc:  80 8a 20 02  btst  2, %o0
a00c8ad0:  12 80 00 04  bne  0xa00c8ae0
a00c8ad4:  82 13 40 11  or  %o5, %l1, %g1
a00c8ad8:  10 80 00 03  b  0xa00c8ae4
a00c8adc:  da 24 80 18  st  %o5, [ %l2 + %i0 ]
a00c8ae0:  c2 24 80 18  st  %g1, [ %l2 + %i0 ]
a00c8ae4:  81 c7 e0 08  ret
a00c8ae8:  81 e8 00 00  restore
