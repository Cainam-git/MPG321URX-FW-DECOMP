# leon2m FUN_a00ad970 0xa00ad970-0xa00adaf4 (388 bytes)
a00ad970:  9d e3 bf 98  save  %sp, -104, %sp
a00ad974:  90 10 20 02  mov  2, %o0
a00ad978:  40 02 64 7d  call  0xa0146b6c
a00ad97c:  92 10 20 00  clr  %o1
a00ad980:  90 10 20 6f  mov  0x6f, %o0
a00ad984:  40 02 64 73  call  0xa0146b50
a00ad988:  92 10 20 00  clr  %o1
a00ad98c:  67 ff 82 46  call  0x4008e2a4
a00ad990:  b2 10 20 04  mov  4, %i1
a00ad994:  b4 10 20 04  mov  4, %i2
a00ad998:  94 10 00 1a  mov  %i2, %o2
a00ad99c:  90 10 20 00  clr  %o0
a00ad9a0:  92 10 20 03  mov  3, %o1
a00ad9a4:  96 10 20 10  mov  0x10, %o3
a00ad9a8:  98 10 20 00  clr  %o4
a00ad9ac:  40 02 64 5d  call  0xa0146b20
a00ad9b0:  9a 10 20 00  clr  %o5
a00ad9b4:  92 10 00 1a  mov  %i2, %o1
a00ad9b8:  90 10 20 03  mov  3, %o0
a00ad9bc:  94 10 20 10  mov  0x10, %o2
a00ad9c0:  96 10 27 92  mov  0x792, %o3
a00ad9c4:  98 10 20 00  clr  %o4
a00ad9c8:  40 02 64 2e  call  0xa0146a80
a00ad9cc:  b2 06 60 01  inc  %i1
a00ad9d0:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00ad9d4:  80 a6 a0 0b  cmp  %i2, 0xb
a00ad9d8:  08 bf ff f1  bleu  0xa00ad99c
a00ad9dc:  94 10 00 1a  mov  %i2, %o2
a00ad9e0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ad9e4:  80 a6 20 00  cmp  %i0, 0
a00ad9e8:  12 80 00 2a  bne  0xa00ada90
a00ad9ec:  b2 10 20 00  clr  %i1
a00ad9f0:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00ad9f4:  21 00 06 24  sethi  %hi(0x189000), %l0
a00ad9f8:  b4 10 20 00  clr  %i2
a00ad9fc:  9b 2e a0 03  sll  %i2, 3, %o5
a00ada00:  96 23 40 1a  sub  %o5, %i2, %o3
a00ada04:  93 2a e0 02  sll  %o3, 2, %o1
a00ada08:  94 14 62 90  or  %l1, 0x290, %o2
a00ada0c:  90 02 40 1a  add  %o1, %i2, %o0
a00ada10:  c2 0a a0 08  ldub  [ %o2 + 8 ], %g1
a00ada14:  9e 02 00 01  add  %o0, %g1, %o7
a00ada18:  99 2b e0 10  sll  %o7, 0x10, %o4
a00ada1c:  93 33 20 10  srl  %o4, 0x10, %o1
a00ada20:  7f ff d7 89  call  0xa00a3844
a00ada24:  90 14 20 d4  or  %l0, 0xd4, %o0
a00ada28:  9a 06 80 1a  add  %i2, %i2, %o5
a00ada2c:  98 10 00 08  mov  %o0, %o4
a00ada30:  94 03 60 05  add  %o5, 5, %o2
a00ada34:  90 10 20 00  clr  %o0
a00ada38:  92 10 20 06  mov  6, %o1
a00ada3c:  96 10 20 0a  mov  0xa, %o3
a00ada40:  9a 10 20 00  clr  %o5
a00ada44:  7f ff d5 d8  call  0xa00a31a4
a00ada48:  b2 06 60 01  inc  %i1
a00ada4c:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00ada50:  80 a6 a0 03  cmp  %i2, 3
a00ada54:  08 bf ff eb  bleu  0xa00ada00
a00ada58:  9b 2e a0 03  sll  %i2, 3, %o5
a00ada5c:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a00ada60:  d0 0e a0 56  ldub  [ %i2 + 0x56 ], %o0	! 0xa8025c56
a00ada64:  a1 32 20 02  srl  %o0, 2, %l0
a00ada68:  80 a6 00 10  cmp  %i0, %l0
a00ada6c:  12 80 00 1e  bne  0xa00adae4
a00ada70:  b0 10 20 04  mov  4, %i0
a00ada74:  90 0a 20 03  and  %o0, 3, %o0
a00ada78:  7f ff ff 7d  call  0xa00ad86c
a00ada7c:  92 10 20 00  clr  %o1
a00ada80:  f0 0e a0 56  ldub  [ %i2 + 0x56 ], %i0
a00ada84:  b0 0e 20 03  and  %i0, 3, %i0
a00ada88:  40 00 16 e3  call  0xa00b3614
a00ada8c:  93 e8 20 01  restore  %g0, 1, %o1
a00ada90:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00ada94:  d4 0a e2 98  ldub  [ %o3 + 0x298 ], %o2	! 0xa802d298
a00ada98:  82 02 a0 74  add  %o2, 0x74, %g1
a00ada9c:  93 28 60 10  sll  %g1, 0x10, %o1
a00adaa0:  11 00 06 24  sethi  %hi(0x189000), %o0
a00adaa4:  93 32 60 10  srl  %o1, 0x10, %o1
a00adaa8:  7f ff d7 67  call  0xa00a3844
a00adaac:  90 12 20 d4  or  %o0, 0xd4, %o0
a00adab0:  98 10 00 08  mov  %o0, %o4
a00adab4:  90 10 20 00  clr  %o0
a00adab8:  92 10 20 06  mov  6, %o1
a00adabc:  94 10 20 05  mov  5, %o2
a00adac0:  96 10 20 0a  mov  0xa, %o3
a00adac4:  7f ff d5 b8  call  0xa00a31a4
a00adac8:  9a 10 20 00  clr  %o5
a00adacc:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a00adad0:  d0 0e a0 56  ldub  [ %i2 + 0x56 ], %o0	! 0xa8025c56
a00adad4:  a1 32 20 02  srl  %o0, 2, %l0
a00adad8:  80 a6 00 10  cmp  %i0, %l0
a00adadc:  02 bf ff e6  be  0xa00ada74
a00adae0:  b0 10 20 04  mov  4, %i0
a00adae4:  b2 10 20 00  clr  %i1
a00adae8:  40 02 64 56  call  0xa0146c40
a00adaec:  95 e8 20 00  restore  %g0, 0, %o2
a00adaf0:  01 00 00 00  nop
