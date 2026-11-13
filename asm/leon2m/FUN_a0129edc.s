# leon2m FUN_a0129edc 0xa0129edc-0xa012a128 (588 bytes)
a0129edc:  9d e3 bf 98  save  %sp, -104, %sp
a0129ee0:  7f ff 5f 61  call  0xa0101c64
a0129ee4:  90 10 20 00  clr  %o0
a0129ee8:  7f ff 5e 91  call  0xa010192c
a0129eec:  90 10 20 00  clr  %o0
a0129ef0:  90 10 20 00  clr  %o0
a0129ef4:  7f ff 5e 5d  call  0xa0101868
a0129ef8:  92 10 20 00  clr  %o1
a0129efc:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0129f00:  82 10 63 d0  or  %g1, 0x3d0, %g1	! 0xa802e3d0
a0129f04:  da 00 60 38  ld  [ %g1 + 0x38 ], %o5
a0129f08:  80 a3 60 01  cmp  %o5, 1
a0129f0c:  02 80 00 6b  be  0xa012a0b8
a0129f10:  80 a3 60 02  cmp  %o5, 2
a0129f14:  22 80 00 6a  be,a   0xa012a0bc
a0129f18:  e2 08 60 08  ldub  [ %g1 + 8 ], %l1
a0129f1c:  e0 08 60 08  ldub  [ %g1 + 8 ], %l0
a0129f20:  a5 2c 20 03  sll  %l0, 3, %l2
a0129f24:  a2 24 80 10  sub  %l2, %l0, %l1
a0129f28:  9f 2c 60 07  sll  %l1, 7, %o7
a0129f2c:  19 14 7a e1  sethi  %hi(0x51eb8400), %o4
a0129f30:  9a 03 c0 10  add  %o7, %l0, %o5
a0129f34:  96 13 21 1f  or  %o4, 0x11f, %o3
a0129f38:  94 03 60 32  add  %o5, 0x32, %o2
a0129f3c:  80 52 80 0b  umul  %o2, %o3, %g0
a0129f40:  93 40 00 00  rd  %y, %o1
a0129f44:  91 32 60 05  srl  %o1, 5, %o0
a0129f48:  82 02 20 7e  add  %o0, 0x7e, %g1
a0129f4c:  a5 30 60 02  srl  %g1, 2, %l2
a0129f50:  19 2a 00 a9  sethi  %hi(0xa802a400), %o4
a0129f54:  e4 2b 20 49  stb  %l2, [ %o4 + 0x49 ]	! 0xa802a449
a0129f58:  d0 0b 20 49  ldub  [ %o4 + 0x49 ], %o0
a0129f5c:  13 2a 00 a9  sethi  %hi(0xa802a400), %o1
a0129f60:  d0 2a 60 48  stb  %o0, [ %o1 + 0x48 ]	! 0xa802a448
a0129f64:  96 10 20 7e  mov  0x7e, %o3
a0129f68:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a0129f6c:  92 0a 20 ff  and  %o0, 0xff, %o1
a0129f70:  d6 2a a2 03  stb  %o3, [ %o2 + 0x203 ]
a0129f74:  7f ff 5e ad  call  0xa0101a28
a0129f78:  90 10 20 7e  mov  0x7e, %o0
a0129f7c:  7f ff 5e f3  call  0xa0101b48
a0129f80:  90 10 20 40  mov  0x40, %o0
a0129f84:  7f ff 5e f7  call  0xa0101b60
a0129f88:  90 10 20 40  mov  0x40, %o0
a0129f8c:  7f ff 5e 71  call  0xa0101950
a0129f90:  90 10 20 08  mov  8, %o0
a0129f94:  7f ff 5e 7c  call  0xa0101984
a0129f98:  90 10 20 01  mov  1, %o0
a0129f9c:  7f ff 5e 86  call  0xa01019b4
a0129fa0:  90 10 20 01  mov  1, %o0
a0129fa4:  90 10 20 00  clr  %o0
a0129fa8:  7f ff 5e 37  call  0xa0101884
a0129fac:  92 10 20 01  mov  1, %o1
a0129fb0:  7f ff 5f 41  call  0xa0101cb4
a0129fb4:  25 2a 00 a9  sethi  %hi(0xa802a400), %l2
a0129fb8:  96 0a 20 ff  and  %o0, 0xff, %o3
a0129fbc:  c2 0c a0 4b  ldub  [ %l2 + 0x4b ], %g1
a0129fc0:  80 a2 c0 01  cmp  %o3, %g1
a0129fc4:  08 80 00 26  bleu  0xa012a05c
a0129fc8:  a2 10 00 08  mov  %o0, %l1
a0129fcc:  21 2a 00 a9  sethi  %hi(0xa802a400), %l0
a0129fd0:  d8 0c 20 4a  ldub  [ %l0 + 0x4a ], %o4	! 0xa802a44a
a0129fd4:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0129fd8:  80 a3 60 3f  cmp  %o5, 0x3f
a0129fdc:  18 80 00 0c  bgu  0xa012a00c
a0129fe0:  1f 00 06 8c  sethi  %hi(0x1a3000), %o7
a0129fe4:  94 13 e1 28  or  %o7, 0x128, %o2	! 0x1a3128
a0129fe8:  c2 0a 80 0d  ldub  [ %o2 + %o5 ], %g1
a0129fec:  80 a0 40 0b  cmp  %g1, %o3
a0129ff0:  3a 80 00 07  bcc,a   0xa012a00c
a0129ff4:  d8 2c 20 4a  stb  %o4, [ %l0 + 0x4a ]
a0129ff8:  98 03 20 01  inc  %o4
a0129ffc:  9a 0b 20 ff  and  %o4, 0xff, %o5
a012a000:  80 a3 60 3f  cmp  %o5, 0x3f
a012a004:  28 bf ff fa  bleu,a   0xa0129fec
a012a008:  c2 0a 80 0d  ldub  [ %o2 + %o5 ], %g1
a012a00c:  80 a3 60 18  cmp  %o5, 0x18
a012a010:  18 80 00 05  bgu  0xa012a024
a012a014:  c2 0c 20 4a  ldub  [ %l0 + 0x4a ], %g1
a012a018:  98 10 20 18  mov  0x18, %o4
a012a01c:  d8 2c 20 4a  stb  %o4, [ %l0 + 0x4a ]
a012a020:  c2 0c 20 4a  ldub  [ %l0 + 0x4a ], %g1
a012a024:  97 28 60 02  sll  %g1, 2, %o3
a012a028:  7f ff 5e c8  call  0xa0101b48
a012a02c:  90 0a e0 fc  and  %o3, 0xfc, %o0
a012a030:  d4 0c 20 4a  ldub  [ %l0 + 0x4a ], %o2
a012a034:  9b 2a a0 02  sll  %o2, 2, %o5
a012a038:  7f ff 5e ca  call  0xa0101b60
a012a03c:  90 0b 60 fc  and  %o5, 0xfc, %o0
a012a040:  e2 2c a0 4b  stb  %l1, [ %l2 + 0x4b ]
a012a044:  7f ff 6a fc  call  0xa0104c34
a012a048:  90 10 20 08  mov  8, %o0
a012a04c:  80 8a 20 ff  btst  0xff, %o0
a012a050:  12 80 00 29  bne  0xa012a0f4
a012a054:  01 00 00 00  nop
a012a058:  30 80 00 25  b,a   0xa012a0ec
a012a05c:  21 2a 00 a9  sethi  %hi(0xa802a400), %l0
a012a060:  d8 0c 20 4a  ldub  [ %l0 + 0x4a ], %o4	! 0xa802a44a
a012a064:  9a 0b 20 ff  and  %o4, 0xff, %o5
a012a068:  80 a3 60 17  cmp  %o5, 0x17
a012a06c:  08 bf ff e8  bleu  0xa012a00c
a012a070:  13 00 06 8c  sethi  %hi(0x1a3000), %o1
a012a074:  94 12 61 28  or  %o1, 0x128, %o2	! 0x1a3128
a012a078:  de 0a 80 0d  ldub  [ %o2 + %o5 ], %o7
a012a07c:  80 a3 c0 0b  cmp  %o7, %o3
a012a080:  0a 80 00 0c  bcs  0xa012a0b0
a012a084:  90 03 20 01  add  %o4, 1, %o0
a012a088:  98 03 3f ff  add  %o4, -1, %o4
a012a08c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a012a090:  80 a3 60 17  cmp  %o5, 0x17
a012a094:  08 bf ff df  bleu  0xa012a010
a012a098:  80 a3 60 18  cmp  %o5, 0x18
a012a09c:  de 0a 80 0d  ldub  [ %o2 + %o5 ], %o7
a012a0a0:  80 a3 c0 0b  cmp  %o7, %o3
a012a0a4:  3a bf ff fa  bcc,a   0xa012a08c
a012a0a8:  98 03 3f ff  add  %o4, -1, %o4
a012a0ac:  90 03 20 01  add  %o4, 1, %o0
a012a0b0:  10 bf ff d7  b  0xa012a00c
a012a0b4:  d0 2c 20 4a  stb  %o0, [ %l0 + 0x4a ]
a012a0b8:  e2 08 60 08  ldub  [ %g1 + 8 ], %l1
a012a0bc:  a0 5c 62 5f  smul  %l1, 0x25f, %l0
a012a0c0:  1f 14 7a e1  sethi  %hi(0x51eb8400), %o7
a012a0c4:  98 04 20 32  add  %l0, 0x32, %o4
a012a0c8:  9a 13 e1 1f  or  %o7, 0x11f, %o5
a012a0cc:  80 53 00 0d  umul  %o4, %o5, %g0
a012a0d0:  97 40 00 00  rd  %y, %o3
a012a0d4:  95 32 e0 05  srl  %o3, 5, %o2
a012a0d8:  92 02 a0 7e  add  %o2, 0x7e, %o1
a012a0dc:  91 32 60 02  srl  %o1, 2, %o0
a012a0e0:  19 2a 00 a9  sethi  %hi(0xa802a400), %o4
a012a0e4:  10 bf ff 9d  b  0xa0129f58
a012a0e8:  d0 2b 20 49  stb  %o0, [ %o4 + 0x49 ]	! 0xa802a449
a012a0ec:  67 fd 90 6e  call  0x4008e2a4
a012a0f0:  01 00 00 00  nop
a012a0f4:  7f ff 5d 76  call  0xa01016cc
a012a0f8:  a2 10 3f 81  mov  -127, %l1	! 0xffffff81
a012a0fc:  90 10 20 07  mov  7, %o0
a012a100:  7f ff 5d d6  call  0xa0101858
a012a104:  92 10 20 0d  mov  0xd, %o1
a012a108:  7f ff 5d f8  call  0xa01018e8
a012a10c:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a012a110:  90 10 20 07  mov  7, %o0
a012a114:  7f ff d0 c9  call  0xa011e438
a012a118:  92 10 20 01  mov  1, %o1
a012a11c:  e2 2c 22 02  stb  %l1, [ %l0 + 0x202 ]
a012a120:  81 c7 e0 08  ret
a012a124:  81 e8 00 00  restore
