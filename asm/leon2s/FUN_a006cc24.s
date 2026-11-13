# leon2s FUN_a006cc24 0xa006cc24-0xa006cfac (904 bytes)
a006cc24:  9d e3 b4 10  save  %sp, -3056, %sp
a006cc28:  92 10 20 00  clr  %o1
a006cc2c:  94 10 27 80  mov  0x780, %o2
a006cc30:  40 01 12 5f  call  0xa00b15ac
a006cc34:  90 07 b8 78  add  %fp, -1928, %o0
a006cc38:  90 07 b4 78  add  %fp, -2952, %o0
a006cc3c:  92 10 20 00  clr  %o1
a006cc40:  40 01 12 5b  call  0xa00b15ac
a006cc44:  94 10 24 00  mov  0x400, %o2
a006cc48:  19 22 22 22  sethi  %hi(0x88888800), %o4
a006cc4c:  98 13 20 89  or  %o4, 0x89, %o4	! 0x88888889
a006cc50:  80 56 00 0c  umul  %i0, %o4, %g0
a006cc54:  83 40 00 00  rd  %y, %g1
a006cc58:  83 30 60 08  srl  %g1, 8, %g1
a006cc5c:  9b 28 60 04  sll  %g1, 4, %o5
a006cc60:  9a 23 40 01  sub  %o5, %g1, %o5
a006cc64:  9b 2b 60 05  sll  %o5, 5, %o5
a006cc68:  82 06 21 df  add  %i0, 0x1df, %g1
a006cc6c:  9a 26 00 0d  sub  %i0, %o5, %o5
a006cc70:  80 50 40 0c  umul  %g1, %o4, %g0
a006cc74:  83 40 00 00  rd  %y, %g1
a006cc78:  83 30 60 08  srl  %g1, 8, %g1
a006cc7c:  99 2b 60 10  sll  %o5, 0x10, %o4
a006cc80:  ae 10 20 00  clr  %l7
a006cc84:  f2 27 a0 48  st  %i1, [ %fp + 0x48 ]
a006cc88:  f4 27 a0 4c  st  %i2, [ %fp + 0x4c ]
a006cc8c:  80 a3 20 00  cmp  %o4, 0
a006cc90:  b4 00 7f ff  add  %g1, -1, %i2
a006cc94:  a6 10 20 00  clr  %l3
a006cc98:  b8 10 00 0d  mov  %o5, %i4
a006cc9c:  02 80 00 1f  be  0xa006cd18
a006cca0:  b2 10 00 17  mov  %l7, %i1
a006cca4:  10 80 00 1d  b  0xa006cd18
a006cca8:  b2 10 20 01  mov  1, %i1
a006ccac:  11 28 01 96  sethi  %hi(0xa0065800), %o0
a006ccb0:  92 10 00 11  mov  %l1, %o1
a006ccb4:  94 10 00 12  mov  %l2, %o2
a006ccb8:  40 00 18 e3  call  0xa0073044
a006ccbc:  90 12 23 80  or  %o0, 0x380, %o0
a006ccc0:  10 80 00 a9  b  0xa006cf64
a006ccc4:  ae 10 20 01  mov  1, %l7
a006ccc8:  03 22 22 22  sethi  %hi(0x88888800), %g1
a006cccc:  98 04 a0 01  add  %l2, 1, %o4
a006ccd0:  82 10 60 89  or  %g1, 0x89, %g1
a006ccd4:  80 53 00 01  umul  %o4, %g1, %g0
a006ccd8:  83 40 00 00  rd  %y, %g1
a006ccdc:  83 30 60 08  srl  %g1, 8, %g1
a006cce0:  9b 28 60 04  sll  %g1, 4, %o5
a006cce4:  9a 23 40 01  sub  %o5, %g1, %o5
a006cce8:  9b 2b 60 05  sll  %o5, 5, %o5
a006ccec:  98 23 00 0d  sub  %o4, %o5, %o4
a006ccf0:  99 2b 20 02  sll  %o4, 2, %o4
a006ccf4:  82 07 80 0c  add  %fp, %o4, %g1
a006ccf8:  11 28 01 96  sethi  %hi(0xa0065800), %o0
a006ccfc:  90 12 23 a0  or  %o0, 0x3a0, %o0	! 0xa0065ba0
a006cd00:  92 10 00 11  mov  %l1, %o1
a006cd04:  94 10 00 12  mov  %l2, %o2
a006cd08:  40 00 18 cf  call  0xa0073044
a006cd0c:  d6 00 78 78  ld  [ %g1 + -1928 ], %o3
a006cd10:  10 80 00 95  b  0xa006cf64
a006cd14:  ae 10 20 01  mov  1, %l7
a006cd18:  03 33 c0 47  sethi  %hi(0xcf011c00), %g1
a006cd1c:  a4 10 20 00  clr  %l2
a006cd20:  9a 10 20 81  mov  0x81, %o5
a006cd24:  82 10 63 80  or  %g1, 0x380, %g1
a006cd28:  da 20 40 00  st  %o5, [ %g1 ]
a006cd2c:  80 a4 80 18  cmp  %l2, %i0
a006cd30:  ba 10 20 00  clr  %i5
a006cd34:  ac 10 20 00  clr  %l6
a006cd38:  1a 80 00 8b  bcc  0xa006cf64
a006cd3c:  03 22 22 22  sethi  %hi(0x88888800), %g1
a006cd40:  82 10 60 89  or  %g1, 0x89, %g1	! 0x88888889
a006cd44:  80 54 80 01  umul  %l2, %g1, %g0
a006cd48:  83 40 00 00  rd  %y, %g1
a006cd4c:  83 30 60 08  srl  %g1, 8, %g1
a006cd50:  9b 28 60 04  sll  %g1, 4, %o5
a006cd54:  9a 23 40 01  sub  %o5, %g1, %o5
a006cd58:  9b 2b 60 05  sll  %o5, 5, %o5
a006cd5c:  80 a4 80 0d  cmp  %l2, %o5
a006cd60:  12 80 00 14  bne  0xa006cdb0
a006cd64:  03 22 22 22  sethi  %hi(0x88888800), %g1
a006cd68:  83 2f 60 10  sll  %i5, 0x10, %g1
a006cd6c:  9b 2e a0 10  sll  %i2, 0x10, %o5
a006cd70:  83 30 60 10  srl  %g1, 0x10, %g1
a006cd74:  95 33 60 10  srl  %o5, 0x10, %o2
a006cd78:  80 a0 40 0a  cmp  %g1, %o2
a006cd7c:  38 80 00 0d  bgu,a   0xa006cdb0
a006cd80:  03 22 22 22  sethi  %hi(0x88888800), %g1
a006cd84:  da 07 a0 4c  ld  [ %fp + 0x4c ], %o5
a006cd88:  da 23 a0 5c  st  %o5, [ %sp + 0x5c ]
a006cd8c:  99 2f 20 10  sll  %i4, 0x10, %o4
a006cd90:  99 33 20 10  srl  %o4, 0x10, %o4
a006cd94:  9a 10 00 01  mov  %g1, %o5
a006cd98:  90 07 b8 78  add  %fp, -1928, %o0
a006cd9c:  d2 07 a0 48  ld  [ %fp + 0x48 ], %o1
a006cda0:  7f ff ff 7e  call  0xa006cb98
a006cda4:  96 0e 60 ff  and  %i1, 0xff, %o3
a006cda8:  ba 07 60 01  inc  %i5
a006cdac:  03 22 22 22  sethi  %hi(0x88888800), %g1
a006cdb0:  82 10 60 89  or  %g1, 0x89, %g1	! 0x88888889
a006cdb4:  80 54 80 01  umul  %l2, %g1, %g0
a006cdb8:  83 40 00 00  rd  %y, %g1
a006cdbc:  83 30 60 08  srl  %g1, 8, %g1
a006cdc0:  9b 28 60 04  sll  %g1, 4, %o5
a006cdc4:  9a 23 40 01  sub  %o5, %g1, %o5
a006cdc8:  9b 2b 60 05  sll  %o5, 5, %o5
a006cdcc:  9a 24 80 0d  sub  %l2, %o5, %o5
a006cdd0:  9b 2b 60 02  sll  %o5, 2, %o5
a006cdd4:  aa 07 bf f8  add  %fp, -8, %l5
a006cdd8:  9a 03 40 15  add  %o5, %l5, %o5
a006cddc:  e2 03 78 80  ld  [ %o5 + -1920 ], %l1
a006cde0:  83 2c 60 10  sll  %l1, 0x10, %g1
a006cde4:  9b 30 60 10  srl  %g1, 0x10, %o5
a006cde8:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a006cdec:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffff
a006cdf0:  80 a3 40 01  cmp  %o5, %g1
a006cdf4:  02 bf ff ae  be  0xa006ccac
a006cdf8:  a8 10 00 11  mov  %l1, %l4
a006cdfc:  a0 10 20 00  clr  %l0
a006ce00:  80 a4 00 0d  cmp  %l0, %o5
a006ce04:  1a 80 00 26  bcc  0xa006ce9c
a006ce08:  03 22 22 22  sethi  %hi(0x88888800), %g1
a006ce0c:  98 04 a0 01  add  %l2, 1, %o4
a006ce10:  82 10 60 89  or  %g1, 0x89, %g1
a006ce14:  80 53 00 01  umul  %o4, %g1, %g0
a006ce18:  83 40 00 00  rd  %y, %g1
a006ce1c:  83 30 60 08  srl  %g1, 8, %g1
a006ce20:  9b 28 60 04  sll  %g1, 4, %o5
a006ce24:  9a 23 40 01  sub  %o5, %g1, %o5
a006ce28:  9b 2b 60 05  sll  %o5, 5, %o5
a006ce2c:  98 23 00 0d  sub  %o4, %o5, %o4
a006ce30:  99 2b 20 02  sll  %o4, 2, %o4
a006ce34:  94 04 e0 01  add  %l3, 1, %o2
a006ce38:  83 2c e0 10  sll  %l3, 0x10, %g1
a006ce3c:  98 03 00 15  add  %o4, %l5, %o4
a006ce40:  9b 2a a0 10  sll  %o2, 0x10, %o5
a006ce44:  d6 03 38 80  ld  [ %o4 + -1920 ], %o3
a006ce48:  83 30 60 0e  srl  %g1, 0xe, %g1
a006ce4c:  93 2d a0 10  sll  %l6, 0x10, %o1
a006ce50:  82 00 40 15  add  %g1, %l5, %g1
a006ce54:  9b 33 60 10  srl  %o5, 0x10, %o5
a006ce58:  93 32 60 0b  srl  %o1, 0xb, %o1
a006ce5c:  99 36 e0 05  srl  %i3, 5, %o4
a006ce60:  a6 10 00 0a  mov  %o2, %l3
a006ce64:  a0 04 20 01  inc  %l0
a006ce68:  d6 20 74 80  st  %o3, [ %g1 + -2944 ]
a006ce6c:  80 a3 61 00  cmp  %o5, 0x100
a006ce70:  92 03 00 09  add  %o4, %o1, %o1
a006ce74:  90 07 b4 78  add  %fp, -2952, %o0
a006ce78:  12 80 00 05  bne  0xa006ce8c
a006ce7c:  94 10 20 20  mov  0x20, %o2
a006ce80:  a6 10 20 00  clr  %l3
a006ce84:  7f ff fe 41  call  0xa006c788
a006ce88:  ac 05 a0 01  inc  %l6
a006ce8c:  83 2d 20 10  sll  %l4, 0x10, %g1
a006ce90:  83 30 60 10  srl  %g1, 0x10, %g1
a006ce94:  10 bf ff dc  b  0xa006ce04
a006ce98:  80 a4 00 01  cmp  %l0, %g1
a006ce9c:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a006cea0:  9b 34 60 10  srl  %l1, 0x10, %o5
a006cea4:  82 10 63 ff  or  %g1, 0x3ff, %g1
a006cea8:  80 a3 40 01  cmp  %o5, %g1
a006ceac:  02 bf ff 87  be  0xa006ccc8
a006ceb0:  a8 10 00 0d  mov  %o5, %l4
a006ceb4:  a0 10 20 00  clr  %l0
a006ceb8:  80 a4 00 0d  cmp  %l0, %o5
a006cebc:  1a 80 00 27  bcc  0xa006cf58
a006cec0:  03 22 22 22  sethi  %hi(0x88888800), %g1
a006cec4:  98 04 a0 02  add  %l2, 2, %o4
a006cec8:  82 10 60 89  or  %g1, 0x89, %g1
a006cecc:  80 53 00 01  umul  %o4, %g1, %g0
a006ced0:  83 40 00 00  rd  %y, %g1
a006ced4:  83 30 60 08  srl  %g1, 8, %g1
a006ced8:  9b 28 60 04  sll  %g1, 4, %o5
a006cedc:  9a 23 40 01  sub  %o5, %g1, %o5
a006cee0:  9b 2b 60 05  sll  %o5, 5, %o5
a006cee4:  98 23 00 0d  sub  %o4, %o5, %o4
a006cee8:  83 2c e0 10  sll  %l3, 0x10, %g1
a006ceec:  96 07 bf f8  add  %fp, -8, %o3
a006cef0:  99 2b 20 02  sll  %o4, 2, %o4
a006cef4:  83 30 60 0e  srl  %g1, 0xe, %g1
a006cef8:  94 04 e0 01  add  %l3, 1, %o2
a006cefc:  98 03 00 0b  add  %o4, %o3, %o4
a006cf00:  82 00 40 0b  add  %g1, %o3, %g1
a006cf04:  9b 2a a0 10  sll  %o2, 0x10, %o5
a006cf08:  d6 03 38 80  ld  [ %o4 + -1920 ], %o3
a006cf0c:  93 2d a0 10  sll  %l6, 0x10, %o1
a006cf10:  9b 33 60 10  srl  %o5, 0x10, %o5
a006cf14:  93 32 60 0b  srl  %o1, 0xb, %o1
a006cf18:  99 36 e0 05  srl  %i3, 5, %o4
a006cf1c:  a6 10 00 0a  mov  %o2, %l3
a006cf20:  a0 04 20 01  inc  %l0
a006cf24:  d6 20 74 80  st  %o3, [ %g1 + -2944 ]
a006cf28:  80 a3 61 00  cmp  %o5, 0x100
a006cf2c:  92 03 00 09  add  %o4, %o1, %o1
a006cf30:  90 07 b4 78  add  %fp, -2952, %o0
a006cf34:  12 80 00 05  bne  0xa006cf48
a006cf38:  94 10 20 20  mov  0x20, %o2
a006cf3c:  a6 10 20 00  clr  %l3
a006cf40:  7f ff fe 12  call  0xa006c788
a006cf44:  ac 05 a0 01  inc  %l6
a006cf48:  83 2d 20 10  sll  %l4, 0x10, %g1
a006cf4c:  83 30 60 10  srl  %g1, 0x10, %g1
a006cf50:  10 bf ff db  b  0xa006cebc
a006cf54:  80 a4 00 01  cmp  %l0, %g1
a006cf58:  a4 04 a0 03  add  %l2, 3, %l2
a006cf5c:  10 bf ff 77  b  0xa006cd38
a006cf60:  80 a4 80 18  cmp  %l2, %i0
a006cf64:  83 2c e0 10  sll  %l3, 0x10, %g1
a006cf68:  95 30 60 10  srl  %g1, 0x10, %o2
a006cf6c:  80 a0 00 0a  cmp  %g0, %o2
a006cf70:  9a 40 20 00  addx  %g0, 0, %o5
a006cf74:  82 0d e0 ff  and  %l7, 0xff, %g1
a006cf78:  80 ab 40 01  andncc  %o5, %g1, %g0
a006cf7c:  02 80 00 09  be  0xa006cfa0
a006cf80:  93 2d a0 10  sll  %l6, 0x10, %o1
a006cf84:  83 36 e0 05  srl  %i3, 5, %g1
a006cf88:  93 32 60 0b  srl  %o1, 0xb, %o1
a006cf8c:  94 02 a0 07  add  %o2, 7, %o2
a006cf90:  92 00 40 09  add  %g1, %o1, %o1
a006cf94:  95 32 a0 03  srl  %o2, 3, %o2
a006cf98:  7f ff fd fc  call  0xa006c788
a006cf9c:  90 07 b4 78  add  %fp, -2952, %o0
a006cfa0:  01 00 00 00  nop
a006cfa4:  81 c7 e0 08  ret
a006cfa8:  81 e8 00 00  restore
