# leon2m FUN_a00acef4 0xa00acef4-0xa00ad02c (312 bytes)
a00acef4:  9d e3 bf 98  save  %sp, -104, %sp
a00acef8:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00acefc:  a0 12 a2 90  or  %o2, 0x290, %l0	! 0xa802d290
a00acf00:  d4 0c 20 08  ldub  [ %l0 + 8 ], %o2
a00acf04:  80 a0 00 0a  cmp  %g0, %o2
a00acf08:  96 60 3f ff  subx  %g0, -1, %o3
a00acf0c:  82 1a a0 06  xor  %o2, 6, %g1
a00acf10:  80 a0 00 01  cmp  %g0, %g1
a00acf14:  98 60 3f ff  subx  %g0, -1, %o4
a00acf18:  90 10 21 91  mov  0x191, %o0
a00acf1c:  92 10 20 00  clr  %o1
a00acf20:  b0 10 20 00  clr  %i0
a00acf24:  b2 10 20 00  clr  %i1
a00acf28:  80 92 c0 0c  orcc  %o3, %o4, %g0
a00acf2c:  12 80 00 08  bne  0xa00acf4c
a00acf30:  9a 10 00 10  mov  %l0, %o5
a00acf34:  80 a2 a0 07  cmp  %o2, 7
a00acf38:  02 80 00 05  be  0xa00acf4c
a00acf3c:  a2 10 20 01  mov  1, %l1
a00acf40:  80 a2 a0 0a  cmp  %o2, 0xa
a00acf44:  12 80 00 03  bne  0xa00acf50
a00acf48:  01 00 00 00  nop
a00acf4c:  e2 0b 60 08  ldub  [ %o5 + 8 ], %l1
a00acf50:  40 02 67 00  call  0xa0146b50
a00acf54:  01 00 00 00  nop
a00acf58:  90 10 20 02  mov  2, %o0	! 0x2
a00acf5c:  40 02 67 04  call  0xa0146b6c
a00acf60:  92 10 20 00  clr  %o1
a00acf64:  94 10 20 0a  mov  0xa, %o2
a00acf68:  96 10 25 96  mov  0x596, %o3
a00acf6c:  98 10 20 00  clr  %o4
a00acf70:  90 10 20 2a  mov  0x2a, %o0
a00acf74:  40 02 66 c3  call  0xa0146a80
a00acf78:  92 10 20 01  mov  1, %o1
a00acf7c:  c2 0c 20 08  ldub  [ %l0 + 8 ], %g1
a00acf80:  96 00 60 91  add  %g1, 0x91, %o3
a00acf84:  1f 00 06 23  sethi  %hi(0x188c00), %o7
a00acf88:  99 2a e0 10  sll  %o3, 0x10, %o4
a00acf8c:  90 13 e1 a0  or  %o7, 0x1a0, %o0
a00acf90:  7f ff da 2d  call  0xa00a3844
a00acf94:  93 33 20 10  srl  %o4, 0x10, %o1
a00acf98:  98 10 00 08  mov  %o0, %o4
a00acf9c:  9a 10 20 00  clr  %o5
a00acfa0:  90 10 20 00  clr  %o0
a00acfa4:  92 10 20 2a  mov  0x2a, %o1
a00acfa8:  94 10 20 01  mov  1, %o2
a00acfac:  7f ff d8 7e  call  0xa00a31a4
a00acfb0:  96 10 20 0a  mov  0xa, %o3
a00acfb4:  94 10 20 0a  mov  0xa, %o2
a00acfb8:  96 10 25 96  mov  0x596, %o3
a00acfbc:  98 10 20 00  clr  %o4
a00acfc0:  90 10 20 2a  mov  0x2a, %o0
a00acfc4:  40 02 66 af  call  0xa0146a80
a00acfc8:  92 10 20 02  mov  2, %o1
a00acfcc:  d2 04 20 a8  ld  [ %l0 + 0xa8 ], %o1
a00acfd0:  91 32 60 07  srl  %o1, 7, %o0
a00acfd4:  82 0a 20 01  and  %o0, 1, %g1
a00acfd8:  95 28 60 03  sll  %g1, 3, %o2
a00acfdc:  9a 22 80 01  sub  %o2, %g1, %o5
a00acfe0:  97 2b 60 02  sll  %o5, 2, %o3
a00acfe4:  a0 02 c0 01  add  %o3, %g1, %l0
a00acfe8:  98 0c 60 ff  and  %l1, 0xff, %o4
a00acfec:  9e 04 00 0c  add  %l0, %o4, %o7
a00acff0:  93 2b e0 10  sll  %o7, 0x10, %o1
a00acff4:  11 00 06 4c  sethi  %hi(0x193000), %o0
a00acff8:  93 32 60 10  srl  %o1, 0x10, %o1
a00acffc:  7f ff da 12  call  0xa00a3844
a00ad000:  90 12 22 48  or  %o0, 0x248, %o0
a00ad004:  98 10 00 08  mov  %o0, %o4
a00ad008:  90 10 20 00  clr  %o0
a00ad00c:  92 10 20 2a  mov  0x2a, %o1
a00ad010:  94 10 20 02  mov  2, %o2
a00ad014:  96 10 20 0a  mov  0xa, %o3
a00ad018:  7f ff d8 63  call  0xa00a31a4
a00ad01c:  9a 10 20 00  clr  %o5
a00ad020:  40 02 66 d3  call  0xa0146b6c
a00ad024:  81 e8 00 00  restore
a00ad028:  01 00 00 00  nop
