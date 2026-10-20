# leon2m FUN_a00aa9d8 0xa00aa9d8-0xa00aaaac (212 bytes)
a00aa9d8:  9d e3 bf 98  save  %sp, -104, %sp
a00aa9dc:  90 10 20 92  mov  0x92, %o0
a00aa9e0:  40 02 70 5c  call  0xa0146b50
a00aa9e4:  92 10 20 00  clr  %o1
a00aa9e8:  90 10 20 00  clr  %o0
a00aa9ec:  40 02 70 60  call  0xa0146b6c
a00aa9f0:  92 10 20 00  clr  %o1
a00aa9f4:  a4 10 20 00  clr  %l2
a00aa9f8:  a0 10 20 00  clr  %l0
a00aa9fc:  29 2a 00 b4  sethi  %hi(0xa802d000), %l4
a00aaa00:  10 80 00 1a  b  0xa00aaa68
a00aaa04:  27 00 06 21  sethi  %hi(0x188400), %l3
a00aaa08:  83 2c 20 03  sll  %l0, 3, %g1
a00aaa0c:  94 20 40 10  sub  %g1, %l0, %o2
a00aaa10:  9f 2a a0 02  sll  %o2, 2, %o7
a00aaa14:  9a 15 22 90  or  %l4, 0x290, %o5
a00aaa18:  96 03 c0 10  add  %o7, %l0, %o3
a00aaa1c:  d8 0b 60 08  ldub  [ %o5 + 8 ], %o4
a00aaa20:  90 02 c0 0c  add  %o3, %o4, %o0
a00aaa24:  93 2a 20 10  sll  %o0, 0x10, %o1
a00aaa28:  93 32 60 10  srl  %o1, 0x10, %o1
a00aaa2c:  7f ff e3 86  call  0xa00a3844
a00aaa30:  90 14 e2 34  or  %l3, 0x234, %o0
a00aaa34:  82 04 60 06  add  %l1, 6, %g1
a00aaa38:  98 10 00 08  mov  %o0, %o4
a00aaa3c:  95 28 60 10  sll  %g1, 0x10, %o2
a00aaa40:  95 32 a0 10  srl  %o2, 0x10, %o2
a00aaa44:  90 10 20 00  clr  %o0
a00aaa48:  92 10 20 14  mov  0x14, %o1
a00aaa4c:  96 10 20 01  mov  1, %o3
a00aaa50:  7f ff e1 d5  call  0xa00a31a4
a00aaa54:  9a 10 20 00  clr  %o5
a00aaa58:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00aaa5c:  80 a4 20 02  cmp  %l0, 2
a00aaa60:  18 80 00 10  bgu  0xa00aaaa0
a00aaa64:  01 00 00 00  nop
a00aaa68:  7f ff fe ae  call  0xa00aa520
a00aaa6c:  90 10 00 10  mov  %l0, %o0
a00aaa70:  80 8a 20 ff  btst  0xff, %o0
a00aaa74:  a4 04 a0 01  inc  %l2
a00aaa78:  a2 04 00 10  add  %l0, %l0, %l1
a00aaa7c:  94 10 20 0f  mov  0xf, %o2
a00aaa80:  96 10 22 92  mov  0x292, %o3
a00aaa84:  98 10 20 00  clr  %o4
a00aaa88:  12 bf ff e0  bne  0xa00aaa08
a00aaa8c:  90 10 20 14  mov  0x14, %o0
a00aaa90:  40 02 6f fc  call  0xa0146a80
a00aaa94:  92 04 60 06  add  %l1, 6, %o1
a00aaa98:  10 bf ff dd  b  0xa00aaa0c
a00aaa9c:  83 2c 20 03  sll  %l0, 3, %g1
a00aaaa0:  40 00 30 ae  call  0xa00b6d58
a00aaaa4:  81 e8 00 00  restore
a00aaaa8:  01 00 00 00  nop
