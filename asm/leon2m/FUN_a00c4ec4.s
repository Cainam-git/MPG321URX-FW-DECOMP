# leon2m FUN_a00c4ec4 0xa00c4ec4-0xa00c5478 (1460 bytes)
a00c4ec4:  9d e3 bf 98  save  %sp, -104, %sp
a00c4ec8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c4ecc:  80 a6 20 02  cmp  %i0, 2
a00c4ed0:  02 80 00 92  be  0xa00c5118
a00c4ed4:  80 a6 20 03  cmp  %i0, 3
a00c4ed8:  02 80 00 93  be  0xa00c5124
a00c4edc:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c4ee0:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c4ee4:  96 08 60 ff  and  %g1, 0xff, %o3
a00c4ee8:  94 02 ff d0  add  %o3, -48, %o2
a00c4eec:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c4ef0:  82 0a a0 ff  and  %o2, 0xff, %g1
a00c4ef4:  98 14 62 90  or  %l1, 0x290, %o4
a00c4ef8:  80 a0 60 08  cmp  %g1, 8
a00c4efc:  18 80 00 85  bgu  0xa00c5110
a00c4f00:  e4 0b 21 a4  ldub  [ %o4 + 0x1a4 ], %l2
a00c4f04:  da 0b 20 1f  ldub  [ %o4 + 0x1f ], %o5
a00c4f08:  80 a3 60 02  cmp  %o5, 2
a00c4f0c:  02 80 00 81  be  0xa00c5110
a00c4f10:  80 a0 60 03  cmp  %g1, 3
a00c4f14:  02 80 00 87  be  0xa00c5130
a00c4f18:  80 a0 60 05  cmp  %g1, 5
a00c4f1c:  02 80 01 15  be  0xa00c5370
a00c4f20:  80 a0 60 00  cmp  %g1, 0
a00c4f24:  12 80 00 6b  bne  0xa00c50d0
a00c4f28:  9a 10 20 00  clr  %o5
a00c4f2c:  a0 14 62 90  or  %l1, 0x290, %l0
a00c4f30:  da 2c 21 a4  stb  %o5, [ %l0 + 0x1a4 ]
a00c4f34:  40 00 50 b2  call  0xa00d91fc
a00c4f38:  90 10 20 00  clr  %o0
a00c4f3c:  d2 0c 20 4a  ldub  [ %l0 + 0x4a ], %o1
a00c4f40:  80 a2 60 01  cmp  %o1, 1
a00c4f44:  02 80 01 11  be  0xa00c5388
a00c4f48:  01 00 00 00  nop
a00c4f4c:  7f fe fa 26  call  0xa00837e4
a00c4f50:  01 00 00 00  nop
a00c4f54:  96 0a 20 ff  and  %o0, 0xff, %o3
a00c4f58:  80 a2 e0 01  cmp  %o3, 1
a00c4f5c:  02 80 00 fe  be  0xa00c5354
a00c4f60:  9a 14 62 90  or  %l1, 0x290, %o5
a00c4f64:  7f fe fa 20  call  0xa00837e4
a00c4f68:  01 00 00 00  nop
a00c4f6c:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00c4f70:  80 a3 60 01  cmp  %o5, 1
a00c4f74:  02 80 00 f0  be  0xa00c5334
a00c4f78:  9a 14 62 90  or  %l1, 0x290, %o5
a00c4f7c:  e0 0b 61 a4  ldub  [ %o5 + 0x1a4 ], %l0
a00c4f80:  80 a4 20 03  cmp  %l0, 3
a00c4f84:  22 80 00 e6  be,a   0xa00c531c
a00c4f88:  c2 0b 60 1f  ldub  [ %o5 + 0x1f ], %g1
a00c4f8c:  7f fe fa 16  call  0xa00837e4
a00c4f90:  01 00 00 00  nop
a00c4f94:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c4f98:  80 a2 20 01  cmp  %o0, 1
a00c4f9c:  02 80 00 d0  be  0xa00c52dc
a00c4fa0:  a0 14 62 90  or  %l1, 0x290, %l0
a00c4fa4:  d8 0c 21 a4  ldub  [ %l0 + 0x1a4 ], %o4
a00c4fa8:  80 a3 20 03  cmp  %o4, 3
a00c4fac:  22 80 00 bc  be,a   0xa00c529c
a00c4fb0:  da 04 20 a8  ld  [ %l0 + 0xa8 ], %o5
a00c4fb4:  96 14 62 90  or  %l1, 0x290, %o3
a00c4fb8:  d4 0a e1 a4  ldub  [ %o3 + 0x1a4 ], %o2
a00c4fbc:  92 1a a0 03  xor  %o2, 3, %o1
a00c4fc0:  80 a0 00 09  cmp  %g0, %o1
a00c4fc4:  90 0c a0 ff  and  %l2, 0xff, %o0
a00c4fc8:  a4 60 3f ff  subx  %g0, -1, %l2
a00c4fcc:  a0 1a 20 03  xor  %o0, 3, %l0
a00c4fd0:  80 a0 00 10  cmp  %g0, %l0
a00c4fd4:  a2 60 3f ff  subx  %g0, -1, %l1
a00c4fd8:  80 94 80 11  orcc  %l2, %l1, %g0
a00c4fdc:  02 80 00 64  be  0xa00c516c
a00c4fe0:  90 10 20 02  mov  2, %o0
a00c4fe4:  40 00 52 85  call  0xa00d99f8
a00c4fe8:  92 10 20 00  clr  %o1
a00c4fec:  90 10 20 00  clr  %o0
a00c4ff0:  40 02 0c 9e  call  0xa0148268
a00c4ff4:  92 10 20 01  mov  1, %o1
a00c4ff8:  90 10 20 01  mov  1, %o0
a00c4ffc:  40 02 0c 9b  call  0xa0148268
a00c5000:  92 10 20 01  mov  1, %o1
a00c5004:  90 10 20 04  mov  4, %o0
a00c5008:  92 10 20 01  mov  1, %o1
a00c500c:  40 02 16 32  call  0xa014a8d4
a00c5010:  94 10 23 e8  mov  0x3e8, %o2
a00c5014:  40 00 3e 61  call  0xa00d4998
a00c5018:  23 2a 00 ac  sethi  %hi(0xa802b000), %l1
a00c501c:  e0 0c 60 8e  ldub  [ %l1 + 0x8e ], %l0	! 0xa802b08e
a00c5020:  a4 14 20 02  or  %l0, 2, %l2
a00c5024:  80 a6 20 02  cmp  %i0, 2
a00c5028:  02 80 00 6c  be  0xa00c51d8
a00c502c:  e4 2c 60 8e  stb  %l2, [ %l1 + 0x8e ]
a00c5030:  80 a6 20 03  cmp  %i0, 3
a00c5034:  02 80 00 83  be  0xa00c5240
a00c5038:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c503c:  94 13 e0 78  or  %o7, 0x78, %o2	! 0xa802d078
a00c5040:  92 10 20 30  mov  0x30, %o1
a00c5044:  a2 10 20 35  mov  0x35, %l1
a00c5048:  9a 10 20 36  mov  0x36, %o5
a00c504c:  98 10 20 2b  mov  0x2b, %o4
a00c5050:  96 10 20 0d  mov  0xd, %o3
a00c5054:  e2 2b e0 78  stb  %l1, [ %o7 + 0x78 ]
a00c5058:  da 2a a0 01  stb  %o5, [ %o2 + 1 ]
a00c505c:  d2 2a a0 03  stb  %o1, [ %o2 + 3 ]
a00c5060:  d8 2a a0 04  stb  %o4, [ %o2 + 4 ]
a00c5064:  d6 2a a0 05  stb  %o3, [ %o2 + 5 ]
a00c5068:  80 a6 20 02  cmp  %i0, 2
a00c506c:  02 80 00 68  be  0xa00c520c
a00c5070:  d2 2a a0 02  stb  %o1, [ %o2 + 2 ]
a00c5074:  80 a6 20 03  cmp  %i0, 3
a00c5078:  02 80 00 7f  be  0xa00c5274
a00c507c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c5080:  92 12 e0 d0  or  %o3, 0xd0, %o1	! 0xa802d0d0
a00c5084:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00c5088:  c0 2b 20 9c  clrb  [ %o4 + 0x9c ]	! 0xa802b09c
a00c508c:  c0 2a e0 d0  clrb  [ %o3 + 0xd0 ]
a00c5090:  c0 2a 60 19  clrb  [ %o1 + 0x19 ]
a00c5094:  c0 2a 60 01  clrb  [ %o1 + 1 ]
a00c5098:  c0 2a 60 07  clrb  [ %o1 + 7 ]
a00c509c:  80 a6 20 02  cmp  %i0, 2
a00c50a0:  02 80 00 64  be  0xa00c5230
a00c50a4:  c0 2a 60 0a  clrb  [ %o1 + 0xa ]
a00c50a8:  80 a6 20 03  cmp  %i0, 3
a00c50ac:  12 80 00 05  bne  0xa00c50c0
a00c50b0:  90 10 00 18  mov  %i0, %o0
a00c50b4:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c50b8:  94 13 e1 08  or  %o7, 0x108, %o2	! 0xa802d108
a00c50bc:  90 10 20 03  mov  3, %o0
a00c50c0:  40 02 0d ca  call  0xa01487e8
a00c50c4:  92 10 20 06  mov  6, %o1
a00c50c8:  10 80 00 ea  b  0xa00c5470
a00c50cc:  82 10 20 00  clr  %g1
a00c50d0:  80 a0 60 01  cmp  %g1, 1
a00c50d4:  02 bf ff 96  be  0xa00c4f2c
a00c50d8:  9a 10 20 01  mov  1, %o5
a00c50dc:  80 a0 60 02  cmp  %g1, 2
a00c50e0:  02 bf ff 93  be  0xa00c4f2c
a00c50e4:  9a 10 20 02  mov  2, %o5
a00c50e8:  80 a0 60 03  cmp  %g1, 3
a00c50ec:  02 80 00 1e  be  0xa00c5164
a00c50f0:  80 a0 60 05  cmp  %g1, 5
a00c50f4:  02 80 00 a3  be  0xa00c5380
a00c50f8:  80 a0 60 07  cmp  %g1, 7
a00c50fc:  02 bf ff 8c  be  0xa00c4f2c
a00c5100:  9a 10 20 05  mov  5, %o5
a00c5104:  80 a0 60 08  cmp  %g1, 8
a00c5108:  02 bf ff 89  be  0xa00c4f2c
a00c510c:  9a 10 20 06  mov  6, %o5
a00c5110:  10 80 00 d8  b  0xa00c5470
a00c5114:  82 10 20 ff  mov  0xff, %g1
a00c5118:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c511c:  10 bf ff 72  b  0xa00c4ee4
a00c5120:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c5124:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c5128:  10 bf ff 6f  b  0xa00c4ee4
a00c512c:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c5130:  80 a3 60 01  cmp  %o5, 1
a00c5134:  02 bf ff f7  be  0xa00c5110
a00c5138:  92 10 20 07  mov  7, %o1
a00c513c:  40 02 01 49  call  0xa0145660
a00c5140:  90 10 20 00  clr  %o0
a00c5144:  a0 10 00 08  mov  %o0, %l0
a00c5148:  40 02 0c 8d  call  0xa014837c
a00c514c:  90 10 20 00  clr  %o0
a00c5150:  a1 2c 20 10  sll  %l0, 0x10, %l0
a00c5154:  99 2a 20 10  sll  %o0, 0x10, %o4
a00c5158:  80 a3 00 10  cmp  %o4, %l0
a00c515c:  02 80 00 95  be  0xa00c53b0
a00c5160:  92 10 20 08  mov  8, %o1
a00c5164:  10 bf ff 72  b  0xa00c4f2c
a00c5168:  9a 10 20 04  mov  4, %o5
a00c516c:  40 01 f9 9c  call  0xa01437dc
a00c5170:  90 10 20 32  mov  0x32, %o0
a00c5174:  90 10 20 00  clr  %o0
a00c5178:  40 02 0c 3c  call  0xa0148268
a00c517c:  92 10 20 01  mov  1, %o1
a00c5180:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a00c5184:  d8 0c 20 56  ldub  [ %l0 + 0x56 ], %o4	! 0xa8025c56
a00c5188:  80 a3 20 05  cmp  %o4, 5
a00c518c:  02 80 00 ae  be  0xa00c5444
a00c5190:  90 10 20 01  mov  1, %o0
a00c5194:  da 0c 20 56  ldub  [ %l0 + 0x56 ], %o5
a00c5198:  80 a3 60 06  cmp  %o5, 6
a00c519c:  02 80 00 9f  be  0xa00c5418
a00c51a0:  90 10 20 01  mov  1, %o0
a00c51a4:  de 0c 20 56  ldub  [ %l0 + 0x56 ], %o7
a00c51a8:  80 a3 e0 04  cmp  %o7, 4
a00c51ac:  02 80 00 93  be  0xa00c53f8
a00c51b0:  01 00 00 00  nop
a00c51b4:  7f fe f9 8c  call  0xa00837e4
a00c51b8:  01 00 00 00  nop
a00c51bc:  82 0a 20 ff  and  %o0, 0xff, %g1
a00c51c0:  80 a0 60 01  cmp  %g1, 1
a00c51c4:  12 bf ff 94  bne  0xa00c5014
a00c51c8:  01 00 00 00  nop
a00c51cc:  40 02 12 89  call  0xa0149bf0
a00c51d0:  90 10 20 00  clr  %o0	! 0x0
a00c51d4:  30 bf ff 90  b,a   0xa00c5014
a00c51d8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c51dc:  b0 13 21 28  or  %o4, 0x128, %i0	! 0xa802d128
a00c51e0:  90 10 20 30  mov  0x30, %o0
a00c51e4:  9a 10 20 35  mov  0x35, %o5
a00c51e8:  96 10 20 0d  mov  0xd, %o3
a00c51ec:  94 10 20 36  mov  0x36, %o2
a00c51f0:  92 10 20 2b  mov  0x2b, %o1
a00c51f4:  da 2b 21 28  stb  %o5, [ %o4 + 0x128 ]
a00c51f8:  d6 2e 20 05  stb  %o3, [ %i0 + 5 ]
a00c51fc:  d4 2e 20 01  stb  %o2, [ %i0 + 1 ]
a00c5200:  d0 2e 20 03  stb  %o0, [ %i0 + 3 ]
a00c5204:  d2 2e 20 04  stb  %o1, [ %i0 + 4 ]
a00c5208:  d0 2e 20 02  stb  %o0, [ %i0 + 2 ]
a00c520c:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00c5210:  94 14 a0 40  or  %l2, 0x40, %o2	! 0xa802d040
a00c5214:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c5218:  c0 28 60 9a  clrb  [ %g1 + 0x9a ]	! 0xa802b09a
a00c521c:  c0 2c a0 40  clrb  [ %l2 + 0x40 ]
a00c5220:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c5224:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c5228:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c522c:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c5230:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c5234:  94 13 61 28  or  %o5, 0x128, %o2	! 0xa802d128
a00c5238:  10 bf ff a2  b  0xa00c50c0
a00c523c:  90 10 20 02  mov  2, %o0
a00c5240:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c5244:  9e 16 21 08  or  %i0, 0x108, %o7	! 0xa802d108
a00c5248:  a2 10 20 30  mov  0x30, %l1
a00c524c:  90 10 20 35  mov  0x35, %o0
a00c5250:  a0 10 20 0d  mov  0xd, %l0
a00c5254:  a4 10 20 36  mov  0x36, %l2
a00c5258:  82 10 20 2b  mov  0x2b, %g1
a00c525c:  d0 2e 21 08  stb  %o0, [ %i0 + 0x108 ]
a00c5260:  e0 2b e0 05  stb  %l0, [ %o7 + 5 ]
a00c5264:  e4 2b e0 01  stb  %l2, [ %o7 + 1 ]
a00c5268:  e2 2b e0 03  stb  %l1, [ %o7 + 3 ]
a00c526c:  c2 2b e0 04  stb  %g1, [ %o7 + 4 ]
a00c5270:  e2 2b e0 02  stb  %l1, [ %o7 + 2 ]
a00c5274:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c5278:  a0 16 20 98  or  %i0, 0x98, %l0	! 0xa802d098
a00c527c:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00c5280:  c0 2a 20 98  clrb  [ %o0 + 0x98 ]	! 0xa802b098
a00c5284:  c0 2e 20 98  clrb  [ %i0 + 0x98 ]
a00c5288:  c0 2c 20 19  clrb  [ %l0 + 0x19 ]
a00c528c:  c0 2c 20 01  clrb  [ %l0 + 1 ]
a00c5290:  c0 2c 20 07  clrb  [ %l0 + 7 ]
a00c5294:  10 bf ff 88  b  0xa00c50b4
a00c5298:  c0 2c 20 0a  clrb  [ %l0 + 0xa ]
a00c529c:  80 8b 60 80  btst  0x80, %o5
a00c52a0:  22 bf ff 46  be,a   0xa00c4fb8
a00c52a4:  96 14 62 90  or  %l1, 0x290, %o3
a00c52a8:  7f ff 2f 4c  call  0xa0090fd8
a00c52ac:  01 00 00 00  nop
a00c52b0:  c2 04 20 a8  ld  [ %l0 + 0xa8 ], %g1
a00c52b4:  9e 08 7f 7f  and  %g1, -129, %o7
a00c52b8:  de 24 20 a8  st  %o7, [ %l0 + 0xa8 ]
a00c52bc:  40 01 7f 22  call  0xa0124f44
a00c52c0:  01 00 00 00  nop
a00c52c4:  40 00 4f ce  call  0xa00d91fc
a00c52c8:  90 10 20 00  clr  %o0	! 0x0
a00c52cc:  40 00 53 ae  call  0xa00da184
a00c52d0:  01 00 00 00  nop
a00c52d4:  10 bf ff 39  b  0xa00c4fb8
a00c52d8:  96 14 62 90  or  %l1, 0x290, %o3
a00c52dc:  d2 04 20 a8  ld  [ %l0 + 0xa8 ], %o1
a00c52e0:  80 8a 60 80  btst  0x80, %o1
a00c52e4:  22 bf ff 30  be,a   0xa00c4fa4
a00c52e8:  a0 14 62 90  or  %l1, 0x290, %l0
a00c52ec:  7f ff 2f 3b  call  0xa0090fd8
a00c52f0:  01 00 00 00  nop
a00c52f4:  d6 04 20 a8  ld  [ %l0 + 0xa8 ], %o3
a00c52f8:  94 0a ff 7f  and  %o3, -129, %o2
a00c52fc:  40 01 7f 12  call  0xa0124f44
a00c5300:  d4 24 20 a8  st  %o2, [ %l0 + 0xa8 ]
a00c5304:  40 00 4f be  call  0xa00d91fc
a00c5308:  90 10 20 00  clr  %o0
a00c530c:  40 00 53 9e  call  0xa00da184
a00c5310:  a0 14 62 90  or  %l1, 0x290, %l0
a00c5314:  10 bf ff 25  b  0xa00c4fa8
a00c5318:  d8 0c 21 a4  ldub  [ %l0 + 0x1a4 ], %o4
a00c531c:  80 a0 60 00  cmp  %g1, 0
a00c5320:  02 bf ff 1b  be  0xa00c4f8c
a00c5324:  01 00 00 00  nop
a00c5328:  40 00 53 cb  call  0xa00da254
a00c532c:  c0 2b 60 1f  clrb  [ %o5 + 0x1f ]
a00c5330:  30 bf ff 17  b,a   0xa00c4f8c
a00c5334:  de 0b 60 1f  ldub  [ %o5 + 0x1f ], %o7
a00c5338:  80 a3 e0 00  cmp  %o7, 0
a00c533c:  22 bf ff 10  be,a   0xa00c4f7c
a00c5340:  9a 14 62 90  or  %l1, 0x290, %o5
a00c5344:  40 00 53 c4  call  0xa00da254
a00c5348:  c0 2b 60 1f  clrb  [ %o5 + 0x1f ]
a00c534c:  10 bf ff 0c  b  0xa00c4f7c
a00c5350:  9a 14 62 90  or  %l1, 0x290, %o5
a00c5354:  d8 03 60 b0  ld  [ %o5 + 0xb0 ], %o4
a00c5358:  80 a3 20 00  cmp  %o4, 0
a00c535c:  02 bf ff 02  be  0xa00c4f64
a00c5360:  01 00 00 00  nop
a00c5364:  40 00 42 f6  call  0xa00d5f3c
a00c5368:  c0 23 60 b0  clr  [ %o5 + 0xb0 ]
a00c536c:  30 bf fe fe  b,a   0xa00c4f64
a00c5370:  d0 03 21 f4  ld  [ %o4 + 0x1f4 ], %o0
a00c5374:  80 a2 20 00  cmp  %o0, 0
a00c5378:  06 80 00 3e  bl  0xa00c5470
a00c537c:  82 10 20 ff  mov  0xff, %g1
a00c5380:  10 bf fe eb  b  0xa00c4f2c
a00c5384:  9a 10 20 03  mov  3, %o5
a00c5388:  7f fe f9 17  call  0xa00837e4
a00c538c:  01 00 00 00  nop
a00c5390:  94 0a 20 ff  and  %o0, 0xff, %o2
a00c5394:  80 a2 a0 01  cmp  %o2, 1
a00c5398:  12 bf fe ed  bne  0xa00c4f4c
a00c539c:  01 00 00 00  nop
a00c53a0:  c0 2c 20 4a  clrb  [ %l0 + 0x4a ]
a00c53a4:  40 00 42 c2  call  0xa00d5eac
a00c53a8:  90 10 20 00  clr  %o0
a00c53ac:  30 bf fe e8  b,a   0xa00c4f4c
a00c53b0:  40 02 00 ac  call  0xa0145660
a00c53b4:  90 10 20 00  clr  %o0
a00c53b8:  a0 10 00 08  mov  %o0, %l0
a00c53bc:  40 02 0b f0  call  0xa014837c
a00c53c0:  90 10 20 01  mov  1, %o0
a00c53c4:  9b 2c 20 10  sll  %l0, 0x10, %o5
a00c53c8:  9f 2a 20 10  sll  %o0, 0x10, %o7
a00c53cc:  80 a3 c0 0d  cmp  %o7, %o5
a00c53d0:  18 bf fe d7  bgu  0xa00c4f2c
a00c53d4:  9a 10 20 04  mov  4, %o5
a00c53d8:  40 01 fa 0f  call  0xa0143c14
a00c53dc:  90 10 20 00  clr  %o0
a00c53e0:  82 0a 20 ff  and  %o0, 0xff, %g1
a00c53e4:  80 a0 60 0a  cmp  %g1, 0xa
a00c53e8:  02 80 00 22  be  0xa00c5470
a00c53ec:  82 10 20 ff  mov  0xff, %g1
a00c53f0:  10 bf fe cf  b  0xa00c4f2c
a00c53f4:  9a 10 20 04  mov  4, %o5
a00c53f8:  7f fe f8 fb  call  0xa00837e4
a00c53fc:  01 00 00 00  nop
a00c5400:  80 8a 20 ff  btst  0xff, %o0
a00c5404:  12 bf ff 6c  bne  0xa00c51b4
a00c5408:  01 00 00 00  nop
a00c540c:  40 02 11 f9  call  0xa0149bf0
a00c5410:  90 10 20 02  mov  2, %o0	! 0x2
a00c5414:  30 bf ff 68  b,a   0xa00c51b4
a00c5418:  40 02 0b 94  call  0xa0148268
a00c541c:  92 10 20 01  mov  1, %o1
a00c5420:  7f fe f8 f1  call  0xa00837e4
a00c5424:  01 00 00 00  nop
a00c5428:  80 8a 20 ff  btst  0xff, %o0
a00c542c:  32 bf ff 5f  bne,a   0xa00c51a8
a00c5430:  de 0c 20 56  ldub  [ %l0 + 0x56 ], %o7
a00c5434:  40 02 11 ef  call  0xa0149bf0
a00c5438:  90 10 20 02  mov  2, %o0
a00c543c:  10 bf ff 5b  b  0xa00c51a8
a00c5440:  de 0c 20 56  ldub  [ %l0 + 0x56 ], %o7
a00c5444:  40 02 0b 89  call  0xa0148268
a00c5448:  92 10 20 01  mov  1, %o1
a00c544c:  7f fe f8 e6  call  0xa00837e4
a00c5450:  01 00 00 00  nop
a00c5454:  80 8a 20 ff  btst  0xff, %o0
a00c5458:  32 bf ff 50  bne,a   0xa00c5198
a00c545c:  da 0c 20 56  ldub  [ %l0 + 0x56 ], %o5
a00c5460:  40 02 11 e4  call  0xa0149bf0
a00c5464:  90 10 20 02  mov  2, %o0
a00c5468:  10 bf ff 4c  b  0xa00c5198
a00c546c:  da 0c 20 56  ldub  [ %l0 + 0x56 ], %o5
a00c5470:  81 c7 e0 08  ret
a00c5474:  91 e8 00 01  restore  %g0, %g1, %o0
