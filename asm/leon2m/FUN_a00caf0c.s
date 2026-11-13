# leon2m FUN_a00caf0c 0xa00caf0c-0xa00cb1c8 (700 bytes)
a00caf0c:  9d e3 bf 98  save  %sp, -104, %sp
a00caf10:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00caf14:  80 a4 20 02  cmp  %l0, 2
a00caf18:  02 80 00 86  be  0xa00cb130
a00caf1c:  80 a4 20 03  cmp  %l0, 3
a00caf20:  02 80 00 8e  be  0xa00cb158
a00caf24:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00caf28:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00caf2c:  96 08 60 ff  and  %g1, 0xff, %o3
a00caf30:  94 02 ff d0  add  %o3, -48, %o2
a00caf34:  82 0a a0 ff  and  %o2, 0xff, %g1
a00caf38:  80 a0 60 02  cmp  %g1, 2
a00caf3c:  18 80 00 a1  bgu  0xa00cb1c0
a00caf40:  b0 10 20 ff  mov  0xff, %i0
a00caf44:  80 a0 60 01  cmp  %g1, 1
a00caf48:  02 80 00 7d  be  0xa00cb13c
a00caf4c:  80 a0 60 00  cmp  %g1, 0
a00caf50:  02 80 00 4a  be  0xa00cb078
a00caf54:  31 2a 00 b3  sethi  %hi(0xa802cc00), %i0
a00caf58:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00caf5c:  92 16 22 90  or  %i0, 0x290, %o1	! 0xa802d290
a00caf60:  31 2a 00 b3  sethi  %hi(0xa802cc00), %i0
a00caf64:  da 02 61 dc  ld  [ %o1 + 0x1dc ], %o5
a00caf68:  90 16 23 f4  or  %i0, 0x3f4, %o0
a00caf6c:  17 20 00 00  sethi  %hi(0x80000000), %o3
a00caf70:  d4 12 20 0e  lduh  [ %o0 + 0xe ], %o2
a00caf74:  98 13 40 0b  or  %o5, %o3, %o4
a00caf78:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a00caf7c:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00caf80:  9a 2a 80 01  andn  %o2, %g1, %o5
a00caf84:  d6 0b e0 8e  ldub  [ %o7 + 0x8e ], %o3
a00caf88:  15 10 00 00  sethi  %hi(0x40000000), %o2
a00caf8c:  da 32 20 0e  sth  %o5, [ %o0 + 0xe ]
a00caf90:  98 13 00 0a  or  %o4, %o2, %o4
a00caf94:  82 12 e0 02  or  %o3, 2, %g1
a00caf98:  d8 22 61 dc  st  %o4, [ %o1 + 0x1dc ]
a00caf9c:  c2 2b e0 8e  stb  %g1, [ %o7 + 0x8e ]
a00cafa0:  9e 10 20 01  mov  1, %o7
a00cafa4:  de 2a 61 ee  stb  %o7, [ %o1 + 0x1ee ]
a00cafa8:  92 16 23 f4  or  %i0, 0x3f4, %o1
a00cafac:  d8 12 60 14  lduh  [ %o1 + 0x14 ], %o4
a00cafb0:  11 3f ff e0  sethi  %hi(0xffff8000), %o0
a00cafb4:  9e 2b 00 08  andn  %o4, %o0, %o7
a00cafb8:  de 32 60 14  sth  %o7, [ %o1 + 0x14 ]
a00cafbc:  7f ff 9f 52  call  0xa00b2d04
a00cafc0:  01 00 00 00  nop
a00cafc4:  7f ff b6 42  call  0xa00b88cc
a00cafc8:  01 00 00 00  nop
a00cafcc:  80 a4 20 02  cmp  %l0, 2
a00cafd0:  02 80 00 3c  be  0xa00cb0c0
a00cafd4:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00cafd8:  80 a4 20 03  cmp  %l0, 3
a00cafdc:  02 80 00 62  be  0xa00cb164
a00cafe0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cafe4:  94 12 20 78  or  %o0, 0x78, %o2	! 0xa802d078
a00cafe8:  96 10 20 30  mov  0x30, %o3
a00cafec:  98 10 20 35  mov  0x35, %o4
a00caff0:  9e 10 20 36  mov  0x36, %o7
a00caff4:  92 10 20 2b  mov  0x2b, %o1
a00caff8:  b0 10 20 0d  mov  0xd, %i0
a00caffc:  d8 2a 20 78  stb  %o4, [ %o0 + 0x78 ]
a00cb000:  de 2a a0 01  stb  %o7, [ %o2 + 1 ]
a00cb004:  d6 2a a0 03  stb  %o3, [ %o2 + 3 ]
a00cb008:  d2 2a a0 04  stb  %o1, [ %o2 + 4 ]
a00cb00c:  f0 2a a0 05  stb  %i0, [ %o2 + 5 ]
a00cb010:  80 a4 20 02  cmp  %l0, 2
a00cb014:  02 80 00 37  be  0xa00cb0f0
a00cb018:  d6 2a a0 02  stb  %o3, [ %o2 + 2 ]
a00cb01c:  80 a4 20 03  cmp  %l0, 3
a00cb020:  02 80 00 5e  be  0xa00cb198
a00cb024:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00cb028:  92 13 e0 d0  or  %o7, 0xd0, %o1	! 0xa802d0d0
a00cb02c:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00cb030:  c0 2a 20 9c  clrb  [ %o0 + 0x9c ]	! 0xa802b09c
a00cb034:  c0 2b e0 d0  clrb  [ %o7 + 0xd0 ]
a00cb038:  c0 2a 60 19  clrb  [ %o1 + 0x19 ]
a00cb03c:  c0 2a 60 01  clrb  [ %o1 + 1 ]
a00cb040:  c0 2a 60 07  clrb  [ %o1 + 7 ]
a00cb044:  80 a4 20 02  cmp  %l0, 2
a00cb048:  02 80 00 33  be  0xa00cb114
a00cb04c:  c0 2a 60 0a  clrb  [ %o1 + 0xa ]
a00cb050:  80 a4 20 03  cmp  %l0, 3
a00cb054:  12 80 00 33  bne  0xa00cb120
a00cb058:  90 10 00 10  mov  %l0, %o0
a00cb05c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00cb060:  94 14 21 08  or  %l0, 0x108, %o2	! 0xa802d108
a00cb064:  90 10 20 03  mov  3, %o0
a00cb068:  40 01 f5 e0  call  0xa01487e8
a00cb06c:  92 10 20 06  mov  6, %o1
a00cb070:  10 80 00 54  b  0xa00cb1c0
a00cb074:  b0 10 20 00  clr  %i0
a00cb078:  90 16 23 f4  or  %i0, 0x3f4, %o0
a00cb07c:  d6 12 20 0e  lduh  [ %o0 + 0xe ], %o3
a00cb080:  15 3f ff e0  sethi  %hi(0xffff8000), %o2
a00cb084:  92 2a c0 0a  andn  %o3, %o2, %o1
a00cb088:  d2 32 20 0e  sth  %o1, [ %o0 + 0xe ]
a00cb08c:  92 16 23 f4  or  %i0, 0x3f4, %o1
a00cb090:  d8 12 60 14  lduh  [ %o1 + 0x14 ], %o4
a00cb094:  11 3f ff e0  sethi  %hi(0xffff8000), %o0
a00cb098:  9e 2b 00 08  andn  %o4, %o0, %o7
a00cb09c:  de 32 60 14  sth  %o7, [ %o1 + 0x14 ]
a00cb0a0:  7f ff 9f 19  call  0xa00b2d04
a00cb0a4:  01 00 00 00  nop
a00cb0a8:  7f ff b6 09  call  0xa00b88cc
a00cb0ac:  01 00 00 00  nop
a00cb0b0:  80 a4 20 02  cmp  %l0, 2
a00cb0b4:  12 bf ff ca  bne  0xa00cafdc
a00cb0b8:  80 a4 20 03  cmp  %l0, 3
a00cb0bc:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00cb0c0:  a0 16 21 28  or  %i0, 0x128, %l0	! 0xa802d128
a00cb0c4:  94 10 20 30  mov  0x30, %o2
a00cb0c8:  92 10 20 35  mov  0x35, %o1
a00cb0cc:  96 10 20 0d  mov  0xd, %o3
a00cb0d0:  9a 10 20 36  mov  0x36, %o5
a00cb0d4:  82 10 20 2b  mov  0x2b, %g1
a00cb0d8:  d2 2e 21 28  stb  %o1, [ %i0 + 0x128 ]
a00cb0dc:  d6 2c 20 05  stb  %o3, [ %l0 + 5 ]
a00cb0e0:  da 2c 20 01  stb  %o5, [ %l0 + 1 ]
a00cb0e4:  d4 2c 20 03  stb  %o2, [ %l0 + 3 ]
a00cb0e8:  c2 2c 20 04  stb  %g1, [ %l0 + 4 ]
a00cb0ec:  d4 2c 20 02  stb  %o2, [ %l0 + 2 ]
a00cb0f0:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00cb0f4:  a0 12 a0 40  or  %o2, 0x40, %l0	! 0xa802d040
a00cb0f8:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00cb0fc:  c0 2b 60 9a  clrb  [ %o5 + 0x9a ]	! 0xa802b09a
a00cb100:  c0 2a a0 40  clrb  [ %o2 + 0x40 ]
a00cb104:  c0 2c 20 19  clrb  [ %l0 + 0x19 ]
a00cb108:  c0 2c 20 01  clrb  [ %l0 + 1 ]
a00cb10c:  c0 2c 20 07  clrb  [ %l0 + 7 ]
a00cb110:  c0 2c 20 0a  clrb  [ %l0 + 0xa ]
a00cb114:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cb118:  94 13 21 28  or  %o4, 0x128, %o2	! 0xa802d128
a00cb11c:  90 10 20 02  mov  2, %o0
a00cb120:  40 01 f5 b2  call  0xa01487e8
a00cb124:  92 10 20 06  mov  6, %o1
a00cb128:  10 80 00 26  b  0xa00cb1c0
a00cb12c:  b0 10 20 00  clr  %i0
a00cb130:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00cb134:  10 bf ff 7e  b  0xa00caf2c
a00cb138:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00cb13c:  31 2a 00 b3  sethi  %hi(0xa802cc00), %i0
a00cb140:  9e 16 23 f4  or  %i0, 0x3f4, %o7	! 0xa802cff4
a00cb144:  c2 13 e0 0e  lduh  [ %o7 + 0xe ], %g1
a00cb148:  19 3f ff e0  sethi  %hi(0xffff8000), %o4
a00cb14c:  9a 10 40 0c  or  %g1, %o4, %o5
a00cb150:  10 bf ff 96  b  0xa00cafa8
a00cb154:  da 33 e0 0e  sth  %o5, [ %o7 + 0xe ]
a00cb158:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cb15c:  10 bf ff 74  b  0xa00caf2c
a00cb160:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00cb164:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00cb168:  9e 13 61 08  or  %o5, 0x108, %o7	! 0xa802d108
a00cb16c:  90 10 20 30  mov  0x30, %o0
a00cb170:  82 10 20 35  mov  0x35, %g1
a00cb174:  94 10 20 0d  mov  0xd, %o2
a00cb178:  a0 10 20 36  mov  0x36, %l0
a00cb17c:  98 10 20 2b  mov  0x2b, %o4
a00cb180:  c2 2b 61 08  stb  %g1, [ %o5 + 0x108 ]
a00cb184:  d4 2b e0 05  stb  %o2, [ %o7 + 5 ]
a00cb188:  e0 2b e0 01  stb  %l0, [ %o7 + 1 ]
a00cb18c:  d0 2b e0 03  stb  %o0, [ %o7 + 3 ]
a00cb190:  d8 2b e0 04  stb  %o4, [ %o7 + 4 ]
a00cb194:  d0 2b e0 02  stb  %o0, [ %o7 + 2 ]
a00cb198:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00cb19c:  96 16 20 98  or  %i0, 0x98, %o3	! 0xa802d098
a00cb1a0:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00cb1a4:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00cb1a8:  c0 2e 20 98  clrb  [ %i0 + 0x98 ]
a00cb1ac:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00cb1b0:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00cb1b4:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00cb1b8:  10 bf ff a9  b  0xa00cb05c
a00cb1bc:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00cb1c0:  81 c7 e0 08  ret
a00cb1c4:  81 e8 00 00  restore
