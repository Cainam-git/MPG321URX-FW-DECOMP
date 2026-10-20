# leon2m FUN_a012e004 0xa012e004-0xa012e2ac (680 bytes)
a012e004:  9d e3 bd 88  save  %sp, -632, %sp
a012e008:  94 10 20 0f  mov  0xf, %o2
a012e00c:  92 10 3f f0  mov  -16, %o1
a012e010:  90 10 20 10  mov  0x10, %o0
a012e014:  9a 10 20 01  mov  1, %o5
a012e018:  d4 2f bf f0  stb  %o2, [ %fp + -16 ]
a012e01c:  d2 2f bf f1  stb  %o1, [ %fp + -15 ]
a012e020:  d0 2f bf f2  stb  %o0, [ %fp + -14 ]
a012e024:  da 2f bf f3  stb  %o5, [ %fp + -13 ]
a012e028:  03 00 06 69  sethi  %hi(0x19a400), %g1
a012e02c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a012e030:  f8 18 62 38  ldd  [ %g1 + 0x238 ], %i4
a012e034:  b4 10 20 00  clr  %i2
a012e038:  b6 10 20 00  clr  %i3
a012e03c:  a8 07 bf f8  add  %fp, -8, %l4
a012e040:  80 a6 60 00  cmp  %i1, 0
a012e044:  a2 10 20 00  clr  %l1
a012e048:  02 80 00 2d  be  0xa012e0fc
a012e04c:  aa 10 20 00  clr  %l5
a012e050:  ac 0e a0 ff  and  %i2, 0xff, %l6
a012e054:  96 05 80 18  add  %l6, %i0, %o3
a012e058:  a6 02 e0 60  add  %o3, 0x60, %l3
a012e05c:  a4 10 20 00  clr  %l2
a012e060:  9b 3c a0 1f  sra  %l2, 0x1f, %o5
a012e064:  91 33 60 1e  srl  %o5, 0x1e, %o0
a012e068:  9e 04 80 08  add  %l2, %o0, %o7
a012e06c:  98 0b ff fc  and  %o7, -4, %o4
a012e070:  96 24 80 0c  sub  %l2, %o4, %o3
a012e074:  ae 05 00 0b  add  %l4, %o3, %l7
a012e078:  e0 0c c0 00  ldub  [ %l3 ], %l0
a012e07c:  d4 0d ff f8  ldub  [ %l7 + -8 ], %o2
a012e080:  ae 1c 00 0a  xor  %l0, %o2, %l7
a012e084:  93 2d 60 10  sll  %l5, 0x10, %o1
a012e088:  9b 32 60 10  srl  %o1, 0x10, %o5
a012e08c:  82 0d e0 ff  and  %l7, 0xff, %g1
a012e090:  90 03 40 01  add  %o5, %g1, %o0
a012e094:  40 00 a1 eb  call  0xa0156840
a012e098:  91 2a 20 04  sll  %o0, 4, %o0
a012e09c:  94 10 00 1c  mov  %i4, %o2
a012e0a0:  40 00 a0 03  call  0xa01560ac
a012e0a4:  96 10 00 1d  mov  %i5, %o3
a012e0a8:  40 00 9c 2e  call  0xa0155160
a012e0ac:  a0 0d e0 ff  and  %l7, 0xff, %l0
a012e0b0:  98 04 60 01  add  %l1, 1, %o4
a012e0b4:  9f 2c 60 10  sll  %l1, 0x10, %o7
a012e0b8:  97 33 e0 10  srl  %o7, 0x10, %o3
a012e0bc:  95 2b 20 10  sll  %o4, 0x10, %o2
a012e0c0:  9a 05 00 0b  add  %l4, %o3, %o5
a012e0c4:  83 32 a0 10  srl  %o2, 0x10, %g1
a012e0c8:  93 2a 20 02  sll  %o0, 2, %o1
a012e0cc:  d2 2b 7d f8  stb  %o1, [ %o5 + -520 ]
a012e0d0:  98 05 00 01  add  %l4, %g1, %o4
a012e0d4:  9f 32 20 06  srl  %o0, 6, %o7
a012e0d8:  a4 04 a0 01  inc  %l2
a012e0dc:  de 2b 3d f8  stb  %o7, [ %o4 + -520 ]
a012e0e0:  aa 05 40 10  add  %l5, %l0, %l5
a012e0e4:  a6 04 e0 01  inc  %l3
a012e0e8:  80 a4 a0 1f  cmp  %l2, 0x1f
a012e0ec:  04 bf ff dd  ble  0xa012e060
a012e0f0:  a2 04 60 02  add  %l1, 2, %l1
a012e0f4:  10 80 00 07  b  0xa012e110
a012e0f8:  27 00 06 8c  sethi  %hi(0x1a3000), %l3
a012e0fc:  c0 2f bd f0  clrb  [ %fp + -528 ]
a012e100:  c0 2f bd f1  clrb  [ %fp + -527 ]
a012e104:  a2 10 20 02  mov  2, %l1
a012e108:  ac 0e a0 ff  and  %i2, 0xff, %l6
a012e10c:  27 00 06 8c  sethi  %hi(0x1a3000), %l3
a012e110:  a0 10 20 00  clr  %l0
a012e114:  a6 14 e1 a8  or  %l3, 0x1a8, %l3
a012e118:  25 00 06 94  sethi  %hi(0x1a5000), %l2
a012e11c:  ee 04 a2 18  ld  [ %l2 + 0x218 ], %l7	! 0x1a5218
a012e120:  80 a0 00 10  cmp  %g0, %l0
a012e124:  92 60 3f ff  subx  %g0, -1, %o1
a012e128:  80 a0 00 19  cmp  %g0, %i1
a012e12c:  82 40 20 00  addx  %g0, 0, %g1
a012e130:  80 8a 40 01  btst  %o1, %g1
a012e134:  32 80 00 02  bne,a   0xa012e13c
a012e138:  a0 10 20 04  mov  4, %l0
a012e13c:  93 3c 20 1f  sra  %l0, 0x1f, %o1
a012e140:  83 32 60 1e  srl  %o1, 0x1e, %g1
a012e144:  a4 04 00 01  add  %l0, %g1, %l2
a012e148:  9a 0c bf fc  and  %l2, -4, %o5
a012e14c:  90 24 00 0d  sub  %l0, %o5, %o0
a012e150:  98 05 00 08  add  %l4, %o0, %o4
a012e154:  9e 05 80 18  add  %l6, %i0, %o7
a012e158:  d6 0b c0 10  ldub  [ %o7 + %l0 ], %o3
a012e15c:  d4 0b 3f f8  ldub  [ %o4 + -8 ], %o2
a012e160:  80 a6 60 00  cmp  %i1, 0
a012e164:  02 80 00 2a  be  0xa012e20c
a012e168:  a4 1a c0 0a  xor  %o3, %o2, %l2
a012e16c:  94 0c a0 ff  and  %l2, 0xff, %o2
a012e170:  97 2d 60 10  sll  %l5, 0x10, %o3
a012e174:  91 2a a0 04  sll  %o2, 4, %o0
a012e178:  9f 32 e0 0c  srl  %o3, 0xc, %o7
a012e17c:  94 10 20 04  mov  4, %o2
a012e180:  92 10 20 07  mov  7, %o1
a012e184:  9b 3a a0 1f  sra  %o2, 0x1f, %o5
a012e188:  99 33 60 1d  srl  %o5, 0x1d, %o4
a012e18c:  96 02 80 0c  add  %o2, %o4, %o3
a012e190:  9b 2c 60 10  sll  %l1, 0x10, %o5
a012e194:  83 3a e0 03  sra  %o3, 3, %g1
a012e198:  98 04 60 01  add  %l1, 1, %o4
a012e19c:  97 33 60 10  srl  %o5, 0x10, %o3
a012e1a0:  82 03 c0 01  add  %o7, %g1, %g1
a012e1a4:  9b 2b 20 10  sll  %o4, 0x10, %o5
a012e1a8:  99 28 60 02  sll  %g1, 2, %o4
a012e1ac:  96 05 00 0b  add  %l4, %o3, %o3
a012e1b0:  d8 2a fd f8  stb  %o4, [ %o3 + -520 ]
a012e1b4:  9b 33 60 10  srl  %o5, 0x10, %o5
a012e1b8:  98 05 00 0d  add  %l4, %o5, %o4
a012e1bc:  83 30 60 06  srl  %g1, 6, %g1
a012e1c0:  c2 2b 3d f8  stb  %g1, [ %o4 + -520 ]
a012e1c4:  94 02 80 08  add  %o2, %o0, %o2
a012e1c8:  92 82 7f ff  addcc  %o1, -1, %o1
a012e1cc:  1c bf ff ee  bpos  0xa012e184
a012e1d0:  a2 04 60 02  add  %l1, 2, %l1
a012e1d4:  9e 0c a0 ff  and  %l2, 0xff, %o7
a012e1d8:  a0 04 20 01  inc  %l0
a012e1dc:  80 a4 20 1f  cmp  %l0, 0x1f
a012e1e0:  04 bf ff d0  ble  0xa012e120
a012e1e4:  aa 05 40 0f  add  %l5, %o7, %l5
a012e1e8:  80 a6 60 00  cmp  %i1, 0
a012e1ec:  02 80 00 28  be  0xa012e28c
a012e1f0:  90 10 00 1b  mov  %i3, %o0
a012e1f4:  92 10 20 00  clr  %o1
a012e1f8:  94 10 22 00  mov  0x200, %o2
a012e1fc:  7f ff 73 24  call  0xa010ae8c
a012e200:  96 07 bd f0  add  %fp, -528, %o3
a012e204:  10 80 00 25  b  0xa012e298
a012e208:  b6 06 e0 01  inc  %i3
a012e20c:  83 2d 60 10  sll  %l5, 0x10, %g1
a012e210:  95 30 60 10  srl  %g1, 0x10, %o2
a012e214:  92 0c a0 ff  and  %l2, 0xff, %o1
a012e218:  90 02 40 0a  add  %o1, %o2, %o0
a012e21c:  9b 2a 20 14  sll  %o0, 0x14, %o5
a012e220:  97 33 60 10  srl  %o5, 0x10, %o3
a012e224:  d8 0c c0 10  ldub  [ %l3 + %l0 ], %o4
a012e228:  9e 5a c0 0c  smul  %o3, %o4, %o7
a012e22c:  92 04 60 01  add  %l1, 1, %o1
a012e230:  95 2c 60 10  sll  %l1, 0x10, %o2
a012e234:  80 53 c0 17  umul  %o7, %l7, %g0
a012e238:  83 40 00 00  rd  %y, %g1
a012e23c:  9f 30 60 05  srl  %g1, 5, %o7
a012e240:  91 32 a0 10  srl  %o2, 0x10, %o0
a012e244:  9b 2a 60 10  sll  %o1, 0x10, %o5
a012e248:  96 05 00 08  add  %l4, %o0, %o3
a012e24c:  99 2b e0 02  sll  %o7, 2, %o4
a012e250:  93 33 e0 06  srl  %o7, 6, %o1
a012e254:  95 33 60 10  srl  %o5, 0x10, %o2
a012e258:  de 37 bd e8  sth  %o7, [ %fp + -536 ]
a012e25c:  d8 2a fd f8  stb  %o4, [ %o3 + -520 ]
a012e260:  90 05 00 0a  add  %l4, %o2, %o0
a012e264:  9e 0c a0 ff  and  %l2, 0xff, %o7
a012e268:  a0 04 20 01  inc  %l0
a012e26c:  d2 2a 3d f8  stb  %o1, [ %o0 + -520 ]
a012e270:  a2 04 60 02  add  %l1, 2, %l1
a012e274:  80 a4 20 1f  cmp  %l0, 0x1f
a012e278:  04 bf ff aa  ble  0xa012e120
a012e27c:  aa 05 40 0f  add  %l5, %o7, %l5
a012e280:  80 a6 60 00  cmp  %i1, 0
a012e284:  12 bf ff dc  bne  0xa012e1f4
a012e288:  90 10 00 1b  mov  %i3, %o0
a012e28c:  7f ff 73 38  call  0xa010af6c
a012e290:  92 07 bd f0  add  %fp, -528, %o1
a012e294:  b6 06 e0 01  inc  %i3
a012e298:  80 a6 e0 02  cmp  %i3, 2
a012e29c:  04 bf ff 69  ble  0xa012e040
a012e2a0:  b4 06 a0 20  add  %i2, 0x20, %i2
a012e2a4:  81 c7 e0 08  ret
a012e2a8:  81 e8 00 00  restore
