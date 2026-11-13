# leon2m FUN_a00aabf0 0xa00aabf0-0xa00aacb4 (196 bytes)
a00aabf0:  9d e3 bf 98  save  %sp, -104, %sp
a00aabf4:  90 10 20 92  mov  0x92, %o0
a00aabf8:  40 02 6f d6  call  0xa0146b50
a00aabfc:  92 10 20 00  clr  %o1
a00aac00:  90 10 20 00  clr  %o0
a00aac04:  40 02 6f da  call  0xa0146b6c
a00aac08:  92 10 20 00  clr  %o1
a00aac0c:  a4 10 20 00  clr  %l2
a00aac10:  a0 10 20 00  clr  %l0
a00aac14:  29 2a 00 b4  sethi  %hi(0xa802d000), %l4
a00aac18:  27 00 06 32  sethi  %hi(0x18c800), %l3
a00aac1c:  7f ff fe 41  call  0xa00aa520
a00aac20:  90 10 00 10  mov  %l0, %o0
a00aac24:  80 8a 20 ff  btst  0xff, %o0
a00aac28:  a4 04 a0 01  inc  %l2
a00aac2c:  a2 04 00 10  add  %l0, %l0, %l1
a00aac30:  94 10 20 0d  mov  0xd, %o2
a00aac34:  96 10 22 92  mov  0x292, %o3
a00aac38:  98 10 20 00  clr  %o4
a00aac3c:  12 80 00 04  bne  0xa00aac4c
a00aac40:  90 10 20 14  mov  0x14, %o0
a00aac44:  40 02 6f 8f  call  0xa0146a80
a00aac48:  92 04 60 06  add  %l1, 6, %o1
a00aac4c:  83 2c 20 03  sll  %l0, 3, %g1
a00aac50:  94 20 40 10  sub  %g1, %l0, %o2
a00aac54:  9f 2a a0 02  sll  %o2, 2, %o7
a00aac58:  9a 15 22 90  or  %l4, 0x290, %o5
a00aac5c:  96 03 c0 10  add  %o7, %l0, %o3
a00aac60:  d8 0b 60 08  ldub  [ %o5 + 8 ], %o4
a00aac64:  90 02 c0 0c  add  %o3, %o4, %o0
a00aac68:  93 2a 20 10  sll  %o0, 0x10, %o1
a00aac6c:  93 32 60 10  srl  %o1, 0x10, %o1
a00aac70:  7f ff e2 f5  call  0xa00a3844
a00aac74:  90 14 e2 88  or  %l3, 0x288, %o0
a00aac78:  82 04 60 06  add  %l1, 6, %g1
a00aac7c:  98 10 00 08  mov  %o0, %o4
a00aac80:  95 28 60 10  sll  %g1, 0x10, %o2
a00aac84:  95 32 a0 10  srl  %o2, 0x10, %o2
a00aac88:  90 10 20 00  clr  %o0
a00aac8c:  92 10 20 14  mov  0x14, %o1
a00aac90:  96 10 20 01  mov  1, %o3
a00aac94:  7f ff e1 44  call  0xa00a31a4
a00aac98:  9a 10 20 00  clr  %o5
a00aac9c:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00aaca0:  80 a4 20 05  cmp  %l0, 5
a00aaca4:  08 bf ff de  bleu  0xa00aac1c
a00aaca8:  01 00 00 00  nop
a00aacac:  81 c7 e0 08  ret
a00aacb0:  81 e8 00 00  restore
