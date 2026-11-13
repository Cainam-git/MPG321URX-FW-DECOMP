# leon2m FUN_a00aaaac 0xa00aaaac-0xa00aabf0 (324 bytes)
a00aaaac:  9d e3 bf 98  save  %sp, -104, %sp
a00aaab0:  67 ff 8d fd  call  0x4008e2a4
a00aaab4:  a2 10 20 05  mov  5, %l1
a00aaab8:  a0 10 20 05  mov  5, %l0
a00aaabc:  94 10 00 10  mov  %l0, %o2
a00aaac0:  90 10 20 00  clr  %o0
a00aaac4:  92 10 20 13  mov  0x13, %o1
a00aaac8:  96 10 20 13  mov  0x13, %o3
a00aaacc:  98 10 20 00  clr  %o4
a00aaad0:  40 02 70 14  call  0xa0146b20
a00aaad4:  9a 10 20 00  clr  %o5
a00aaad8:  92 10 00 10  mov  %l0, %o1
a00aaadc:  90 10 20 13  mov  0x13, %o0
a00aaae0:  94 10 20 13  mov  0x13, %o2
a00aaae4:  96 10 27 92  mov  0x792, %o3
a00aaae8:  98 10 20 00  clr  %o4
a00aaaec:  40 02 6f e5  call  0xa0146a80
a00aaaf0:  a2 04 60 01  inc  %l1
a00aaaf4:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00aaaf8:  80 a4 20 14  cmp  %l0, 0x14
a00aaafc:  08 bf ff f1  bleu  0xa00aaac0
a00aab00:  94 10 00 10  mov  %l0, %o2
a00aab04:  96 10 20 02  mov  2, %o3
a00aab08:  98 10 20 00  clr  %o4
a00aab0c:  9a 10 20 00  clr  %o5
a00aab10:  90 10 20 00  clr  %o0
a00aab14:  92 10 20 1c  mov  0x1c, %o1
a00aab18:  40 02 70 02  call  0xa0146b20
a00aab1c:  94 10 20 15  mov  0x15, %o2
a00aab20:  94 10 20 00  clr  %o2
a00aab24:  90 10 20 05  mov  5, %o0
a00aab28:  40 02 70 46  call  0xa0146c40
a00aab2c:  92 10 20 00  clr  %o1
a00aab30:  90 10 20 92  mov  0x92, %o0
a00aab34:  40 02 70 07  call  0xa0146b50
a00aab38:  92 10 20 00  clr  %o1
a00aab3c:  90 10 20 00  clr  %o0
a00aab40:  40 02 70 0b  call  0xa0146b6c
a00aab44:  92 10 20 00  clr  %o1
a00aab48:  a4 10 20 00  clr  %l2
a00aab4c:  a0 10 20 00  clr  %l0
a00aab50:  29 2a 00 b4  sethi  %hi(0xa802d000), %l4
a00aab54:  27 00 06 28  sethi  %hi(0x18a000), %l3
a00aab58:  7f ff fe 72  call  0xa00aa520
a00aab5c:  90 10 00 10  mov  %l0, %o0
a00aab60:  80 8a 20 ff  btst  0xff, %o0
a00aab64:  a4 04 a0 01  inc  %l2
a00aab68:  a2 04 00 10  add  %l0, %l0, %l1
a00aab6c:  94 10 20 0d  mov  0xd, %o2
a00aab70:  96 10 22 92  mov  0x292, %o3
a00aab74:  98 10 20 00  clr  %o4
a00aab78:  12 80 00 04  bne  0xa00aab88
a00aab7c:  90 10 20 14  mov  0x14, %o0
a00aab80:  40 02 6f c0  call  0xa0146a80
a00aab84:  92 04 60 06  add  %l1, 6, %o1
a00aab88:  83 2c 20 03  sll  %l0, 3, %g1
a00aab8c:  94 20 40 10  sub  %g1, %l0, %o2
a00aab90:  9f 2a a0 02  sll  %o2, 2, %o7
a00aab94:  9a 15 22 90  or  %l4, 0x290, %o5
a00aab98:  96 03 c0 10  add  %o7, %l0, %o3
a00aab9c:  d8 0b 60 08  ldub  [ %o5 + 8 ], %o4
a00aaba0:  90 02 c0 0c  add  %o3, %o4, %o0
a00aaba4:  93 2a 20 10  sll  %o0, 0x10, %o1
a00aaba8:  93 32 60 10  srl  %o1, 0x10, %o1
a00aabac:  7f ff e3 26  call  0xa00a3844
a00aabb0:  90 14 e3 60  or  %l3, 0x360, %o0
a00aabb4:  82 04 60 06  add  %l1, 6, %g1
a00aabb8:  98 10 00 08  mov  %o0, %o4
a00aabbc:  95 28 60 10  sll  %g1, 0x10, %o2
a00aabc0:  95 32 a0 10  srl  %o2, 0x10, %o2
a00aabc4:  90 10 20 00  clr  %o0
a00aabc8:  92 10 20 14  mov  0x14, %o1
a00aabcc:  96 10 20 01  mov  1, %o3
a00aabd0:  7f ff e1 75  call  0xa00a31a4
a00aabd4:  9a 10 20 00  clr  %o5
a00aabd8:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00aabdc:  80 a4 20 02  cmp  %l0, 2
a00aabe0:  08 bf ff de  bleu  0xa00aab58
a00aabe4:  01 00 00 00  nop
a00aabe8:  81 c7 e0 08  ret
a00aabec:  81 e8 00 00  restore
