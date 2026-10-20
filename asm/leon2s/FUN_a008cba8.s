# leon2s FUN_a008cba8 0xa008cba8-0xa008ced8 (816 bytes)
a008cba8:  9d e3 bf 98  save  %sp, -104, %sp
a008cbac:  23 2a 01 d9  sethi  %hi(0xa8076400), %l1
a008cbb0:  92 10 00 18  mov  %i0, %o1
a008cbb4:  94 10 20 03  mov  3, %o2
a008cbb8:  40 00 92 88  call  0xa00b15d8
a008cbbc:  90 14 62 88  or  %l1, 0x288, %o0
a008cbc0:  7f ff f5 9e  call  0xa008a238
a008cbc4:  90 10 20 04  mov  4, %o0
a008cbc8:  7f ff f6 2a  call  0xa008a470
a008cbcc:  b0 10 20 00  clr  %i0
a008cbd0:  7f ff f6 70  call  0xa008a590
a008cbd4:  a0 0e 20 ff  and  %i0, 0xff, %l0
a008cbd8:  7f ff f6 c7  call  0xa008a6f4
a008cbdc:  01 00 00 00  nop
a008cbe0:  90 10 20 01  mov  1, %o0	! 0x1
a008cbe4:  92 10 20 00  clr  %o1
a008cbe8:  94 10 20 00  clr  %o2
a008cbec:  7f ff ff 6f  call  0xa008c9a8
a008cbf0:  96 10 20 01  mov  1, %o3
a008cbf4:  90 10 00 10  mov  %l0, %o0
a008cbf8:  92 10 20 04  mov  4, %o1
a008cbfc:  40 00 69 5b  call  0xa00a7168
a008cc00:  94 10 20 95  mov  0x95, %o2
a008cc04:  90 10 00 10  mov  %l0, %o0
a008cc08:  92 10 20 05  mov  5, %o1
a008cc0c:  40 00 69 57  call  0xa00a7168
a008cc10:  94 10 20 18  mov  0x18, %o2
a008cc14:  90 10 00 10  mov  %l0, %o0
a008cc18:  92 10 20 06  mov  6, %o1
a008cc1c:  40 00 69 53  call  0xa00a7168
a008cc20:  94 10 20 04  mov  4, %o2
a008cc24:  b0 06 20 01  inc  %i0
a008cc28:  82 0e 20 ff  and  %i0, 0xff, %g1
a008cc2c:  80 a0 60 03  cmp  %g1, 3
a008cc30:  08 bf ff f1  bleu  0xa008cbf4
a008cc34:  a0 0e 20 ff  and  %i0, 0xff, %l0
a008cc38:  d6 0c 62 88  ldub  [ %l1 + 0x288 ], %o3
a008cc3c:  80 8a e0 80  btst  0x80, %o3
a008cc40:  21 2a 01 d9  sethi  %hi(0xa8076400), %l0
a008cc44:  02 80 00 11  be  0xa008cc88
a008cc48:  b0 14 62 88  or  %l1, 0x288, %i0
a008cc4c:  1b 33 c0 44  sethi  %hi(0xcf011000), %o5
a008cc50:  98 13 61 48  or  %o5, 0x148, %o4	! 0xcf011148
a008cc54:  82 10 20 07  mov  7, %g1
a008cc58:  c2 23 00 00  st  %g1, [ %o4 ]
a008cc5c:  98 13 61 40  or  %o5, 0x140, %o4
a008cc60:  82 10 20 03  mov  3, %g1
a008cc64:  c2 23 00 00  st  %g1, [ %o4 ]
a008cc68:  98 13 61 44  or  %o5, 0x144, %o4
a008cc6c:  82 10 20 08  mov  8, %g1
a008cc70:  c2 23 00 00  st  %g1, [ %o4 ]
a008cc74:  82 13 61 54  or  %o5, 0x154, %g1
a008cc78:  c0 20 40 00  clr  [ %g1 ]
a008cc7c:  9a 13 61 58  or  %o5, 0x158, %o5
a008cc80:  82 10 20 ff  mov  0xff, %g1
a008cc84:  c2 23 40 00  st  %g1, [ %o5 ]
a008cc88:  80 8a e0 40  btst  0x40, %o3
a008cc8c:  02 80 00 05  be  0xa008cca0
a008cc90:  c2 0c 22 88  ldub  [ %l0 + 0x288 ], %g1
a008cc94:  7f ff f5 59  call  0xa008a1f8
a008cc98:  90 10 20 00  clr  %o0
a008cc9c:  c2 0c 22 88  ldub  [ %l0 + 0x288 ], %g1
a008cca0:  80 88 60 20  btst  0x20, %g1
a008cca4:  02 80 00 05  be  0xa008ccb8
a008cca8:  c2 0c 22 88  ldub  [ %l0 + 0x288 ], %g1
a008ccac:  7f ff f5 53  call  0xa008a1f8
a008ccb0:  90 10 20 01  mov  1, %o0
a008ccb4:  c2 0c 22 88  ldub  [ %l0 + 0x288 ], %g1
a008ccb8:  80 88 60 18  btst  0x18, %g1
a008ccbc:  22 80 00 21  be,a   0xa008cd40
a008ccc0:  c2 0e 20 02  ldub  [ %i0 + 2 ], %g1
a008ccc4:  19 33 c0 44  sethi  %hi(0xcf011000), %o4
a008ccc8:  9a 13 21 d4  or  %o4, 0x1d4, %o5	! 0xcf0111d4
a008cccc:  c2 03 40 00  ld  [ %o5 ], %g1
a008ccd0:  82 08 7f fe  and  %g1, -2, %g1
a008ccd4:  c2 23 40 00  st  %g1, [ %o5 ]
a008ccd8:  c2 03 40 00  ld  [ %o5 ], %g1
a008ccdc:  82 10 60 20  or  %g1, 0x20, %g1
a008cce0:  c2 23 40 00  st  %g1, [ %o5 ]
a008cce4:  9a 13 21 d8  or  %o4, 0x1d8, %o5
a008cce8:  c2 03 40 00  ld  [ %o5 ], %g1
a008ccec:  82 10 60 20  or  %g1, 0x20, %g1
a008ccf0:  c2 23 40 00  st  %g1, [ %o5 ]
a008ccf4:  9a 13 21 dc  or  %o4, 0x1dc, %o5
a008ccf8:  82 10 20 87  mov  0x87, %g1
a008ccfc:  c2 23 40 00  st  %g1, [ %o5 ]
a008cd00:  9a 13 21 18  or  %o4, 0x118, %o5
a008cd04:  c2 03 40 00  ld  [ %o5 ], %g1
a008cd08:  82 10 60 01  or  %g1, 1, %g1
a008cd0c:  c2 23 40 00  st  %g1, [ %o5 ]
a008cd10:  c2 03 40 00  ld  [ %o5 ], %g1
a008cd14:  82 08 7f fe  and  %g1, -2, %g1
a008cd18:  c2 23 40 00  st  %g1, [ %o5 ]
a008cd1c:  82 13 21 e8  or  %o4, 0x1e8, %g1
a008cd20:  c0 20 40 00  clr  [ %g1 ]
a008cd24:  9a 13 21 ec  or  %o4, 0x1ec, %o5
a008cd28:  82 10 20 ff  mov  0xff, %g1
a008cd2c:  c2 23 40 00  st  %g1, [ %o5 ]
a008cd30:  98 13 21 e4  or  %o4, 0x1e4, %o4
a008cd34:  82 10 20 03  mov  3, %g1
a008cd38:  c2 23 00 00  st  %g1, [ %o4 ]
a008cd3c:  c2 0e 20 02  ldub  [ %i0 + 2 ], %g1
a008cd40:  80 88 60 01  btst  1, %g1
a008cd44:  02 80 00 06  be  0xa008cd5c
a008cd48:  01 00 00 00  nop
a008cd4c:  7f ff f5 c9  call  0xa008a470
a008cd50:  01 00 00 00  nop
a008cd54:  10 80 00 05  b  0xa008cd68
a008cd58:  82 14 62 88  or  %l1, 0x288, %g1
a008cd5c:  7f ff f6 91  call  0xa008a7a0
a008cd60:  01 00 00 00  nop
a008cd64:  82 14 62 88  or  %l1, 0x288, %g1
a008cd68:  c2 08 60 01  ldub  [ %g1 + 1 ], %g1
a008cd6c:  83 30 60 06  srl  %g1, 6, %g1
a008cd70:  80 a0 60 01  cmp  %g1, 1
a008cd74:  02 80 00 06  be  0xa008cd8c
a008cd78:  80 a0 60 02  cmp  %g1, 2
a008cd7c:  90 10 20 02  mov  2, %o0
a008cd80:  02 80 00 05  be  0xa008cd94
a008cd84:  92 10 20 02  mov  2, %o1
a008cd88:  30 80 00 0e  b,a   0xa008cdc0
a008cd8c:  90 10 20 02  mov  2, %o0
a008cd90:  92 10 20 01  mov  1, %o1
a008cd94:  40 00 90 f2  call  0xa00b115c
a008cd98:  01 00 00 00  nop
a008cd9c:  90 10 20 00  clr  %o0	! 0x0
a008cda0:  40 00 55 60  call  0xa00a2320
a008cda4:  92 10 20 01  mov  1, %o1
a008cda8:  90 10 20 01  mov  1, %o0
a008cdac:  40 00 55 5d  call  0xa00a2320
a008cdb0:  92 10 20 01  mov  1, %o1
a008cdb4:  90 10 20 02  mov  2, %o0
a008cdb8:  10 80 00 0c  b  0xa008cde8
a008cdbc:  92 10 20 01  mov  1, %o1
a008cdc0:  40 00 90 e7  call  0xa00b115c
a008cdc4:  92 10 20 00  clr  %o1
a008cdc8:  90 10 20 00  clr  %o0
a008cdcc:  40 00 55 55  call  0xa00a2320
a008cdd0:  92 10 20 00  clr  %o1
a008cdd4:  90 10 20 01  mov  1, %o0
a008cdd8:  40 00 55 52  call  0xa00a2320
a008cddc:  92 10 20 00  clr  %o1
a008cde0:  90 10 20 02  mov  2, %o0
a008cde4:  92 10 20 00  clr  %o1
a008cde8:  40 00 10 19  call  0xa0090e4c
a008cdec:  01 00 00 00  nop
a008cdf0:  82 14 62 88  or  %l1, 0x288, %g1
a008cdf4:  c2 08 60 01  ldub  [ %g1 + 1 ], %g1
a008cdf8:  83 30 60 04  srl  %g1, 4, %g1
a008cdfc:  82 08 60 03  and  %g1, 3, %g1
a008ce00:  80 a0 60 01  cmp  %g1, 1
a008ce04:  02 80 00 07  be  0xa008ce20
a008ce08:  90 10 20 02  mov  2, %o0
a008ce0c:  04 80 00 1b  ble  0xa008ce78
a008ce10:  80 a0 60 02  cmp  %g1, 2
a008ce14:  02 80 00 0e  be  0xa008ce4c
a008ce18:  01 00 00 00  nop
a008ce1c:  30 80 00 17  b,a   0xa008ce78
a008ce20:  40 00 91 01  call  0xa00b1224
a008ce24:  92 10 20 02  mov  2, %o1
a008ce28:  90 10 20 00  clr  %o0
a008ce2c:  40 00 55 52  call  0xa00a2374
a008ce30:  92 10 20 02  mov  2, %o1
a008ce34:  90 10 20 01  mov  1, %o0
a008ce38:  40 00 55 4f  call  0xa00a2374
a008ce3c:  92 10 20 02  mov  2, %o1
a008ce40:  90 10 20 02  mov  2, %o0
a008ce44:  10 80 00 17  b  0xa008cea0
a008ce48:  92 10 20 02  mov  2, %o1
a008ce4c:  40 00 90 f6  call  0xa00b1224
a008ce50:  92 10 20 01  mov  1, %o1
a008ce54:  90 10 20 00  clr  %o0
a008ce58:  40 00 55 47  call  0xa00a2374
a008ce5c:  92 10 20 01  mov  1, %o1
a008ce60:  90 10 20 01  mov  1, %o0
a008ce64:  40 00 55 44  call  0xa00a2374
a008ce68:  92 10 20 01  mov  1, %o1
a008ce6c:  90 10 20 02  mov  2, %o0
a008ce70:  10 80 00 0c  b  0xa008cea0
a008ce74:  92 10 20 01  mov  1, %o1
a008ce78:  40 00 90 eb  call  0xa00b1224
a008ce7c:  92 10 20 00  clr  %o1
a008ce80:  90 10 20 00  clr  %o0
a008ce84:  40 00 55 3c  call  0xa00a2374
a008ce88:  92 10 20 00  clr  %o1
a008ce8c:  90 10 20 01  mov  1, %o0
a008ce90:  40 00 55 39  call  0xa00a2374
a008ce94:  92 10 20 00  clr  %o1
a008ce98:  90 10 20 02  mov  2, %o0
a008ce9c:  92 10 20 00  clr  %o1
a008cea0:  40 00 0f f3  call  0xa0090e6c
a008cea4:  01 00 00 00  nop
a008cea8:  7f ff f6 45  call  0xa008a7bc
a008ceac:  01 00 00 00  nop
a008ceb0:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a008ceb4:  82 10 63 70  or  %g1, 0x370, %g1	! 0xcf014770
a008ceb8:  da 00 40 00  ld  [ %g1 ], %o5
a008cebc:  9a 0b 60 0f  and  %o5, 0xf, %o5
a008cec0:  da 20 40 00  st  %o5, [ %g1 ]
a008cec4:  da 00 40 00  ld  [ %g1 ], %o5
a008cec8:  9a 13 60 40  or  %o5, 0x40, %o5
a008cecc:  da 20 40 00  st  %o5, [ %g1 ]
a008ced0:  81 c7 e0 08  ret
a008ced4:  81 e8 00 00  restore
