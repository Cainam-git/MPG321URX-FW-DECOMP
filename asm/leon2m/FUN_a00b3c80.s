# leon2m FUN_a00b3c80 0xa00b3c80-0xa00b3d14 (148 bytes)
a00b3c80:  9d e3 bf 98  save  %sp, -104, %sp
a00b3c84:  90 10 20 92  mov  0x92, %o0
a00b3c88:  40 02 4b b2  call  0xa0146b50
a00b3c8c:  92 10 20 00  clr  %o1
a00b3c90:  90 10 20 00  clr  %o0
a00b3c94:  40 02 4b b6  call  0xa0146b6c
a00b3c98:  92 10 20 00  clr  %o1
a00b3c9c:  a2 10 20 00  clr  %l1
a00b3ca0:  a0 10 20 00  clr  %l0
a00b3ca4:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00b3ca8:  25 00 06 59  sethi  %hi(0x196400), %l2
a00b3cac:  95 2c 20 03  sll  %l0, 3, %o2
a00b3cb0:  9e 22 80 10  sub  %o2, %l0, %o7
a00b3cb4:  99 2b e0 02  sll  %o7, 2, %o4
a00b3cb8:  9a 14 e2 90  or  %l3, 0x290, %o5
a00b3cbc:  96 03 00 10  add  %o4, %l0, %o3
a00b3cc0:  c2 0b 60 08  ldub  [ %o5 + 8 ], %g1
a00b3cc4:  90 02 c0 01  add  %o3, %g1, %o0
a00b3cc8:  93 2a 20 10  sll  %o0, 0x10, %o1
a00b3ccc:  93 32 60 10  srl  %o1, 0x10, %o1
a00b3cd0:  7f ff be dd  call  0xa00a3844
a00b3cd4:  90 14 a2 78  or  %l2, 0x278, %o0
a00b3cd8:  98 10 00 08  mov  %o0, %o4
a00b3cdc:  94 04 00 10  add  %l0, %l0, %o2
a00b3ce0:  94 02 a0 06  add  %o2, 6, %o2
a00b3ce4:  90 10 20 00  clr  %o0
a00b3ce8:  92 10 20 16  mov  0x16, %o1
a00b3cec:  96 10 20 01  mov  1, %o3
a00b3cf0:  9a 10 20 00  clr  %o5
a00b3cf4:  7f ff bd 2c  call  0xa00a31a4
a00b3cf8:  a2 04 60 01  inc  %l1
a00b3cfc:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00b3d00:  80 a4 20 02  cmp  %l0, 2
a00b3d04:  08 bf ff eb  bleu  0xa00b3cb0
a00b3d08:  95 2c 20 03  sll  %l0, 3, %o2
a00b3d0c:  81 c7 e0 08  ret
a00b3d10:  81 e8 00 00  restore
