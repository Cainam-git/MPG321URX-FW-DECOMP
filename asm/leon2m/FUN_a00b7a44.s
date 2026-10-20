# leon2m FUN_a00b7a44 0xa00b7a44-0xa00b7ae4 (160 bytes)
a00b7a44:  9d e3 bf 98  save  %sp, -104, %sp
a00b7a48:  90 10 21 11  mov  0x111, %o0
a00b7a4c:  40 02 3c 41  call  0xa0146b50
a00b7a50:  92 10 20 00  clr  %o1
a00b7a54:  90 10 20 00  clr  %o0
a00b7a58:  40 02 3c 45  call  0xa0146b6c
a00b7a5c:  92 10 20 00  clr  %o1
a00b7a60:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00b7a64:  a0 10 62 90  or  %g1, 0x290, %l0	! 0xa802d290
a00b7a68:  b2 10 20 00  clr  %i1
a00b7a6c:  b4 10 20 00  clr  %i2
a00b7a70:  31 00 06 42  sethi  %hi(0x190800), %i0
a00b7a74:  83 2e a0 03  sll  %i2, 3, %g1
a00b7a78:  9e 20 40 1a  sub  %g1, %i2, %o7
a00b7a7c:  9b 2b e0 02  sll  %o7, 2, %o5
a00b7a80:  96 03 40 1a  add  %o5, %i2, %o3
a00b7a84:  d8 0c 20 08  ldub  [ %l0 + 8 ], %o4
a00b7a88:  90 02 c0 0c  add  %o3, %o4, %o0
a00b7a8c:  93 2a 20 10  sll  %o0, 0x10, %o1
a00b7a90:  93 32 60 10  srl  %o1, 0x10, %o1
a00b7a94:  7f ff af 6c  call  0xa00a3844
a00b7a98:  90 16 21 ec  or  %i0, 0x1ec, %o0
a00b7a9c:  98 10 00 08  mov  %o0, %o4
a00b7aa0:  94 06 80 1a  add  %i2, %i2, %o2
a00b7aa4:  94 02 a0 06  add  %o2, 6, %o2
a00b7aa8:  90 10 20 00  clr  %o0
a00b7aac:  92 10 20 2a  mov  0x2a, %o1
a00b7ab0:  96 10 20 01  mov  1, %o3
a00b7ab4:  9a 10 20 00  clr  %o5
a00b7ab8:  7f ff ad bb  call  0xa00a31a4
a00b7abc:  b2 06 60 01  inc  %i1
a00b7ac0:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00b7ac4:  80 a6 a0 02  cmp  %i2, 2
a00b7ac8:  08 bf ff ec  bleu  0xa00b7a78
a00b7acc:  83 2e a0 03  sll  %i2, 3, %g1
a00b7ad0:  f2 0c 21 7c  ldub  [ %l0 + 0x17c ], %i1
a00b7ad4:  b0 10 20 01  mov  1, %i0
a00b7ad8:  7f ff c1 99  call  0xa00a813c
a00b7adc:  95 e8 20 01  restore  %g0, 1, %o2
a00b7ae0:  01 00 00 00  nop
