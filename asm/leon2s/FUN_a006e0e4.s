# leon2s FUN_a006e0e4 0xa006e0e4-0xa006e2c4 (480 bytes)
a006e0e4:  9d e3 bf 98  save  %sp, -104, %sp
a006e0e8:  c2 0e a0 2d  ldub  [ %i2 + 0x2d ], %g1
a006e0ec:  80 a0 60 00  cmp  %g1, 0
a006e0f0:  02 80 00 04  be  0xa006e100
a006e0f4:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006e0f8:  10 80 00 03  b  0xa006e104
a006e0fc:  82 10 60 02  or  %g1, 2, %g1
a006e100:  82 08 7f fd  and  %g1, -3, %g1
a006e104:  c2 2e 20 0d  stb  %g1, [ %i0 + 0xd ]
a006e108:  c2 0e a0 06  ldub  [ %i2 + 6 ], %g1
a006e10c:  80 88 60 01  btst  1, %g1
a006e110:  32 80 00 05  bne,a   0xa006e124
a006e114:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006e118:  80 88 60 04  btst  4, %g1
a006e11c:  02 80 00 04  be  0xa006e12c
a006e120:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006e124:  10 80 00 03  b  0xa006e130
a006e128:  82 10 60 04  or  %g1, 4, %g1
a006e12c:  82 08 7f fb  and  %g1, -5, %g1
a006e130:  c2 2e 20 0d  stb  %g1, [ %i0 + 0xd ]
a006e134:  c2 0e a0 06  ldub  [ %i2 + 6 ], %g1
a006e138:  80 88 60 02  btst  2, %g1
a006e13c:  02 80 00 04  be  0xa006e14c
a006e140:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006e144:  10 80 00 03  b  0xa006e150
a006e148:  82 10 60 08  or  %g1, 8, %g1
a006e14c:  82 08 7f f7  and  %g1, -9, %g1
a006e150:  c2 2e 20 0d  stb  %g1, [ %i0 + 0xd ]
a006e154:  c2 0e a0 06  ldub  [ %i2 + 6 ], %g1
a006e158:  80 88 60 10  btst  0x10, %g1
a006e15c:  02 80 00 04  be  0xa006e16c
a006e160:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006e164:  10 80 00 03  b  0xa006e170
a006e168:  82 10 60 10  or  %g1, 0x10, %g1
a006e16c:  82 08 7f ef  and  %g1, -17, %g1
a006e170:  c2 2e 20 0d  stb  %g1, [ %i0 + 0xd ]
a006e174:  c2 0e a0 06  ldub  [ %i2 + 6 ], %g1
a006e178:  80 88 60 08  btst  8, %g1
a006e17c:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006e180:  02 80 00 04  be  0xa006e190
a006e184:  b4 0e 60 ff  and  %i1, 0xff, %i2
a006e188:  10 80 00 03  b  0xa006e194
a006e18c:  82 10 7f 80  or  %g1, -128, %g1
a006e190:  82 08 60 7f  and  %g1, 0x7f, %g1
a006e194:  c2 2e 20 0d  stb  %g1, [ %i0 + 0xd ]
a006e198:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a006e19c:  c2 08 60 35  ldub  [ %g1 + 0x35 ], %g1	! 0xa8078c35
a006e1a0:  9a 06 a0 02  add  %i2, 2, %o5
a006e1a4:  83 38 40 0d  sra  %g1, %o5, %g1
a006e1a8:  80 88 60 01  btst  1, %g1
a006e1ac:  02 80 00 04  be  0xa006e1bc
a006e1b0:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006e1b4:  10 80 00 03  b  0xa006e1c0
a006e1b8:  82 10 60 40  or  %g1, 0x40, %g1
a006e1bc:  82 08 7f bf  and  %g1, -65, %g1
a006e1c0:  c2 2e 20 0d  stb  %g1, [ %i0 + 0xd ]
a006e1c4:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a006e1c8:  c2 08 60 5b  ldub  [ %g1 + 0x5b ], %g1	! 0xa8078c5b
a006e1cc:  9a 06 a0 02  add  %i2, 2, %o5
a006e1d0:  83 38 40 0d  sra  %g1, %o5, %g1
a006e1d4:  80 88 60 01  btst  1, %g1
a006e1d8:  02 80 00 04  be  0xa006e1e8
a006e1dc:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006e1e0:  10 80 00 03  b  0xa006e1ec
a006e1e4:  82 10 60 20  or  %g1, 0x20, %g1
a006e1e8:  82 08 7f df  and  %g1, -33, %g1
a006e1ec:  c2 2e 20 0d  stb  %g1, [ %i0 + 0xd ]
a006e1f0:  40 00 d1 e2  call  0xa00a2978
a006e1f4:  90 10 00 1a  mov  %i2, %o0
a006e1f8:  80 8a 20 ff  btst  0xff, %o0
a006e1fc:  02 80 00 05  be  0xa006e210
a006e200:  da 16 20 0e  lduh  [ %i0 + 0xe ], %o5
a006e204:  03 00 00 10  sethi  %hi(0x4000), %g1
a006e208:  10 80 00 04  b  0xa006e218
a006e20c:  82 13 40 01  or  %o5, %g1, %g1
a006e210:  03 00 00 10  sethi  %hi(0x4000), %g1
a006e214:  82 2b 40 01  andn  %o5, %g1, %g1
a006e218:  c2 36 20 0e  sth  %g1, [ %i0 + 0xe ]
a006e21c:  40 00 d1 de  call  0xa00a2994
a006e220:  90 10 00 1a  mov  %i2, %o0
a006e224:  80 8a 20 ff  btst  0xff, %o0
a006e228:  da 16 20 0e  lduh  [ %i0 + 0xe ], %o5
a006e22c:  02 80 00 05  be  0xa006e240
a006e230:  d8 0e 00 00  ldub  [ %i0 ], %o4
a006e234:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a006e238:  10 80 00 04  b  0xa006e248
a006e23c:  82 13 40 01  or  %o5, %g1, %g1
a006e240:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a006e244:  82 2b 40 01  andn  %o5, %g1, %g1
a006e248:  80 a3 20 05  cmp  %o4, 5
a006e24c:  02 80 00 07  be  0xa006e268
a006e250:  c2 36 20 0e  sth  %g1, [ %i0 + 0xe ]
a006e254:  92 10 00 1a  mov  %i2, %o1
a006e258:  40 00 cf f6  call  0xa00a2230
a006e25c:  90 10 20 01  mov  1, %o0
a006e260:  10 80 00 0a  b  0xa006e288
a006e264:  c2 16 20 12  lduh  [ %i0 + 0x12 ], %g1
a006e268:  92 10 00 1a  mov  %i2, %o1
a006e26c:  40 00 cf f1  call  0xa00a2230
a006e270:  90 10 20 00  clr  %o0
a006e274:  80 8a 20 ff  btst  0xff, %o0
a006e278:  02 80 00 04  be  0xa006e288
a006e27c:  c2 16 20 12  lduh  [ %i0 + 0x12 ], %g1
a006e280:  10 80 00 03  b  0xa006e28c
a006e284:  82 10 60 40  or  %g1, 0x40, %g1
a006e288:  82 08 7f bf  and  %g1, -65, %g1
a006e28c:  c2 36 20 12  sth  %g1, [ %i0 + 0x12 ]
a006e290:  40 00 d1 c8  call  0xa00a29b0
a006e294:  90 0e 60 ff  and  %i1, 0xff, %o0
a006e298:  80 8a 20 ff  btst  0xff, %o0
a006e29c:  02 80 00 05  be  0xa006e2b0
a006e2a0:  da 16 20 0e  lduh  [ %i0 + 0xe ], %o5
a006e2a4:  03 00 00 08  sethi  %hi(0x2000), %g1
a006e2a8:  10 80 00 04  b  0xa006e2b8
a006e2ac:  82 13 40 01  or  %o5, %g1, %g1
a006e2b0:  03 00 00 08  sethi  %hi(0x2000), %g1
a006e2b4:  82 2b 40 01  andn  %o5, %g1, %g1
a006e2b8:  c2 36 20 0e  sth  %g1, [ %i0 + 0xe ]
a006e2bc:  81 c7 e0 08  ret
a006e2c0:  81 e8 00 00  restore
