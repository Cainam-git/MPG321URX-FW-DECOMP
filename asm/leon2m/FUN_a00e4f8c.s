# leon2m FUN_a00e4f8c 0xa00e4f8c-0xa00e52e8 (860 bytes)
a00e4f8c:  9d e3 bf 98  save  %sp, -104, %sp
a00e4f90:  80 a6 60 04  cmp  %i1, 4
a00e4f94:  02 80 00 83  be  0xa00e51a0
a00e4f98:  80 a6 bf ff  cmp  %i2, -1
a00e4f9c:  02 80 00 4f  be  0xa00e50d8
a00e4fa0:  ab 2e a0 02  sll  %i2, 2, %l5
a00e4fa4:  13 2a 00 98  sethi  %hi(0xa8026000), %o1
a00e4fa8:  11 2a 00 98  sethi  %hi(0xa8026000), %o0
a00e4fac:  23 2a 00 ad  sethi  %hi(0xa802b400), %l1
a00e4fb0:  a4 12 23 d8  or  %o0, 0x3d8, %l2
a00e4fb4:  a8 14 62 a8  or  %l1, 0x2a8, %l4
a00e4fb8:  ac 12 63 e8  or  %o1, 0x3e8, %l6
a00e4fbc:  d2 05 80 15  ld  [ %l6 + %l5 ], %o1
a00e4fc0:  d4 04 80 15  ld  [ %l2 + %l5 ], %o2
a00e4fc4:  d6 05 00 15  ld  [ %l4 + %l5 ], %o3
a00e4fc8:  7f ff ed e3  call  0xa00e0754
a00e4fcc:  90 10 00 18  mov  %i0, %o0
a00e4fd0:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00e4fd4:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e4fd8:  17 2a 00 98  sethi  %hi(0xa8026000), %o3
a00e4fdc:  82 13 62 b8  or  %o5, 0x2b8, %g1
a00e4fe0:  98 12 e3 f8  or  %o3, 0x3f8, %o4
a00e4fe4:  80 a0 00 08  cmp  %g0, %o0
a00e4fe8:  a0 12 a0 08  or  %o2, 8, %l0
a00e4fec:  d6 00 40 15  ld  [ %g1 + %l5 ], %o3
a00e4ff0:  d4 03 00 15  ld  [ %o4 + %l5 ], %o2
a00e4ff4:  d2 04 00 15  ld  [ %l0 + %l5 ], %o1
a00e4ff8:  a8 60 3f ff  subx  %g0, -1, %l4
a00e4ffc:  7f ff ed d6  call  0xa00e0754
a00e5000:  90 10 00 18  mov  %i0, %o0
a00e5004:  a6 1a 20 ff  xor  %o0, 0xff, %l3
a00e5008:  33 2a 00 98  sethi  %hi(0xa8026000), %i1
a00e500c:  35 2a 00 98  sethi  %hi(0xa8026000), %i2
a00e5010:  11 2a 00 ad  sethi  %hi(0xa802b400), %o0
a00e5014:  9e 16 63 c8  or  %i1, 0x3c8, %o7
a00e5018:  80 a0 00 13  cmp  %g0, %l3
a00e501c:  ac 16 a3 b8  or  %i2, 0x3b8, %l6
a00e5020:  a4 12 22 98  or  %o0, 0x298, %l2
a00e5024:  d2 03 c0 15  ld  [ %o7 + %l5 ], %o1
a00e5028:  d4 05 80 15  ld  [ %l6 + %l5 ], %o2
a00e502c:  d6 04 80 15  ld  [ %l2 + %l5 ], %o3
a00e5030:  a6 60 3f ff  subx  %g0, -1, %l3
a00e5034:  7f ff ed c8  call  0xa00e0754
a00e5038:  90 10 00 18  mov  %i0, %o0
a00e503c:  13 2a 00 98  sethi  %hi(0xa8026000), %o1
a00e5040:  15 2a 00 98  sethi  %hi(0xa8026000), %o2
a00e5044:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00e5048:  80 a0 00 08  cmp  %g0, %o0
a00e504c:  a2 12 63 a8  or  %o1, 0x3a8, %l1
a00e5050:  98 12 e2 88  or  %o3, 0x288, %o4
a00e5054:  a0 12 a3 98  or  %o2, 0x398, %l0
a00e5058:  d2 04 40 15  ld  [ %l1 + %l5 ], %o1
a00e505c:  a4 60 3f ff  subx  %g0, -1, %l2
a00e5060:  d4 04 00 15  ld  [ %l0 + %l5 ], %o2
a00e5064:  d6 03 00 15  ld  [ %o4 + %l5 ], %o3
a00e5068:  7f ff ed bb  call  0xa00e0754
a00e506c:  90 10 00 18  mov  %i0, %o0
a00e5070:  9a 1a 20 ff  xor  %o0, 0xff, %o5
a00e5074:  90 10 00 18  mov  %i0, %o0
a00e5078:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00e507c:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00e5080:  31 2a 00 99  sethi  %hi(0xa8026400), %i0
a00e5084:  80 a0 00 0d  cmp  %g0, %o5
a00e5088:  b2 10 60 38  or  %g1, 0x38, %i1
a00e508c:  b4 13 e0 58  or  %o7, 0x58, %i2
a00e5090:  ac 16 20 48  or  %i0, 0x48, %l6
a00e5094:  d6 06 40 15  ld  [ %i1 + %l5 ], %o3
a00e5098:  a2 60 3f ff  subx  %g0, -1, %l1
a00e509c:  d2 06 80 15  ld  [ %i2 + %l5 ], %o1
a00e50a0:  d4 05 80 15  ld  [ %l6 + %l5 ], %o2
a00e50a4:  7f ff ed ac  call  0xa00e0754
a00e50a8:  b0 10 20 00  clr  %i0
a00e50ac:  aa 1a 20 01  xor  %o0, 1, %l5
a00e50b0:  80 a0 00 15  cmp  %g0, %l5
a00e50b4:  82 40 20 00  addx  %g0, 0, %g1
a00e50b8:  80 8d 00 13  btst  %l4, %l3
a00e50bc:  02 80 00 89  be  0xa00e52e0
a00e50c0:  80 8c 80 11  btst  %l2, %l1
a00e50c4:  02 80 00 87  be  0xa00e52e0
a00e50c8:  80 a0 60 00  cmp  %g1, 0
a00e50cc:  32 80 00 85  bne,a   0xa00e52e0
a00e50d0:  b0 10 20 01  mov  1, %i0
a00e50d4:  30 80 00 83  b,a   0xa00e52e0
a00e50d8:  11 2a 00 98  sethi  %hi(0xa8026000), %o0
a00e50dc:  92 12 23 e8  or  %o0, 0x3e8, %o1	! 0xa80263e8
a00e50e0:  29 2a 00 98  sethi  %hi(0xa8026000), %l4
a00e50e4:  27 2a 00 ad  sethi  %hi(0xa802b400), %l3
a00e50e8:  94 15 23 d8  or  %l4, 0x3d8, %o2
a00e50ec:  96 14 e2 a8  or  %l3, 0x2a8, %o3
a00e50f0:  7f ff ed 99  call  0xa00e0754
a00e50f4:  90 10 00 18  mov  %i0, %o0
a00e50f8:  80 a0 00 08  cmp  %g0, %o0
a00e50fc:  25 2a 00 99  sethi  %hi(0xa8026400), %l2
a00e5100:  23 2a 00 98  sethi  %hi(0xa8026000), %l1
a00e5104:  21 2a 00 ad  sethi  %hi(0xa802b400), %l0
a00e5108:  92 14 a0 08  or  %l2, 8, %o1
a00e510c:  94 14 63 f8  or  %l1, 0x3f8, %o2
a00e5110:  a8 60 3f ff  subx  %g0, -1, %l4
a00e5114:  96 14 22 b8  or  %l0, 0x2b8, %o3
a00e5118:  7f ff ed 8f  call  0xa00e0754
a00e511c:  90 10 00 18  mov  %i0, %o0
a00e5120:  92 1a 20 ff  xor  %o0, 0xff, %o1
a00e5124:  80 a0 00 09  cmp  %g0, %o1
a00e5128:  15 2a 00 98  sethi  %hi(0xa8026000), %o2
a00e512c:  92 12 a3 c8  or  %o2, 0x3c8, %o1	! 0xa80263c8
a00e5130:  17 2a 00 98  sethi  %hi(0xa8026000), %o3
a00e5134:  94 12 e3 b8  or  %o3, 0x3b8, %o2	! 0xa80263b8
a00e5138:  19 2a 00 ad  sethi  %hi(0xa802b400), %o4
a00e513c:  96 13 22 98  or  %o4, 0x298, %o3	! 0xa802b698
a00e5140:  a6 60 3f ff  subx  %g0, -1, %l3
a00e5144:  7f ff ed 84  call  0xa00e0754
a00e5148:  90 10 00 18  mov  %i0, %o0
a00e514c:  80 a0 00 08  cmp  %g0, %o0
a00e5150:  1b 2a 00 98  sethi  %hi(0xa8026000), %o5
a00e5154:  03 2a 00 98  sethi  %hi(0xa8026000), %g1
a00e5158:  33 2a 00 ad  sethi  %hi(0xa802b400), %i1
a00e515c:  a4 60 3f ff  subx  %g0, -1, %l2
a00e5160:  92 13 63 a8  or  %o5, 0x3a8, %o1
a00e5164:  94 10 63 98  or  %g1, 0x398, %o2
a00e5168:  96 16 62 88  or  %i1, 0x288, %o3
a00e516c:  7f ff ed 7a  call  0xa00e0754
a00e5170:  90 10 00 18  mov  %i0, %o0
a00e5174:  9e 1a 20 ff  xor  %o0, 0xff, %o7
a00e5178:  90 10 00 18  mov  %i0, %o0
a00e517c:  80 a0 00 0f  cmp  %g0, %o7
a00e5180:  35 2a 00 99  sethi  %hi(0xa8026400), %i2
a00e5184:  31 2a 00 99  sethi  %hi(0xa8026400), %i0
a00e5188:  2d 2a 00 99  sethi  %hi(0xa8026400), %l6
a00e518c:  a2 60 3f ff  subx  %g0, -1, %l1
a00e5190:  92 16 a0 58  or  %i2, 0x58, %o1
a00e5194:  94 16 20 48  or  %i0, 0x48, %o2
a00e5198:  10 bf ff c3  b  0xa00e50a4
a00e519c:  96 15 a0 38  or  %l6, 0x38, %o3
a00e51a0:  90 10 00 18  mov  %i0, %o0
a00e51a4:  7f ff ee 57  call  0xa00e0b00
a00e51a8:  92 10 00 1a  mov  %i2, %o1
a00e51ac:  a8 10 00 08  mov  %o0, %l4
a00e51b0:  aa 10 00 09  mov  %o1, %l5
a00e51b4:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00e51b8:  d4 00 61 88  ld  [ %g1 + 0x188 ], %o2	! 0xa8026988
a00e51bc:  ac 10 20 00  clr  %l6
a00e51c0:  a0 10 20 00  clr  %l0
a00e51c4:  a2 10 20 00  clr  %l1
a00e51c8:  a4 10 20 00  clr  %l2
a00e51cc:  a6 10 20 00  clr  %l3
a00e51d0:  96 10 20 00  clr  %o3
a00e51d4:  90 10 20 01  mov  1, %o0
a00e51d8:  92 10 20 07  mov  7, %o1
a00e51dc:  99 2a 00 0b  sll  %o0, %o3, %o4
a00e51e0:  9a 0b 00 0a  and  %o4, %o2, %o5
a00e51e4:  b3 33 40 0b  srl  %o5, %o3, %i1
a00e51e8:  82 22 40 0b  sub  %o1, %o3, %g1
a00e51ec:  9f 2e 40 01  sll  %i1, %g1, %o7
a00e51f0:  98 10 20 00  clr  %o4
a00e51f4:  96 02 e0 01  inc  %o3
a00e51f8:  a0 14 00 0c  or  %l0, %o4, %l0
a00e51fc:  80 a2 e0 07  cmp  %o3, 7
a00e5200:  04 bf ff f7  ble  0xa00e51dc
a00e5204:  a2 14 40 0f  or  %l1, %o7, %l1
a00e5208:  b2 10 20 00  clr  %i1
a00e520c:  94 10 00 19  mov  %i1, %o2
a00e5210:  90 10 00 10  mov  %l0, %o0
a00e5214:  40 01 bf a5  call  0xa01550a8
a00e5218:  92 10 00 11  mov  %l1, %o1
a00e521c:  95 2e 60 03  sll  %i1, 3, %o2
a00e5220:  80 8a 60 01  btst  1, %o1
a00e5224:  b2 06 60 01  inc  %i1
a00e5228:  90 10 20 00  clr  %o0
a00e522c:  02 80 00 06  be  0xa00e5244
a00e5230:  92 10 20 ff  mov  0xff, %o1
a00e5234:  40 01 bf b4  call  0xa0155104
a00e5238:  01 00 00 00  nop
a00e523c:  a4 14 80 08  or  %l2, %o0, %l2
a00e5240:  a6 14 c0 09  or  %l3, %o1, %l3
a00e5244:  80 a6 60 07  cmp  %i1, 7
a00e5248:  04 bf ff f2  ble  0xa00e5210
a00e524c:  94 10 00 19  mov  %i1, %o2
a00e5250:  80 a5 00 12  cmp  %l4, %l2
a00e5254:  02 80 00 04  be  0xa00e5264
a00e5258:  80 a5 40 13  cmp  %l5, %l3
a00e525c:  10 80 00 21  b  0xa00e52e0
a00e5260:  b0 10 00 16  mov  %l6, %i0
a00e5264:  32 80 00 1f  bne,a   0xa00e52e0
a00e5268:  b0 10 00 16  mov  %l6, %i0
a00e526c:  80 a6 bf ff  cmp  %i2, -1
a00e5270:  02 80 00 14  be  0xa00e52c0
a00e5274:  2b 2a 00 99  sethi  %hi(0xa8026400), %l5
a00e5278:  a1 2e a0 02  sll  %i2, 2, %l0
a00e527c:  90 15 60 38  or  %l5, 0x38, %o0
a00e5280:  29 2a 00 99  sethi  %hi(0xa8026400), %l4
a00e5284:  25 2a 00 99  sethi  %hi(0xa8026400), %l2
a00e5288:  d6 02 00 10  ld  [ %o0 + %l0 ], %o3
a00e528c:  a6 15 20 58  or  %l4, 0x58, %l3
a00e5290:  a2 14 a0 48  or  %l2, 0x48, %l1
a00e5294:  90 10 00 18  mov  %i0, %o0
a00e5298:  d2 04 c0 10  ld  [ %l3 + %l0 ], %o1
a00e529c:  d4 04 40 10  ld  [ %l1 + %l0 ], %o2
a00e52a0:  7f ff ed 2d  call  0xa00e0754
a00e52a4:  01 00 00 00  nop
a00e52a8:  80 a2 20 01  cmp  %o0, 1
a00e52ac:  22 80 00 0d  be,a   0xa00e52e0
a00e52b0:  b0 10 00 16  mov  %l6, %i0
a00e52b4:  ac 10 20 01  mov  1, %l6
a00e52b8:  10 80 00 0a  b  0xa00e52e0
a00e52bc:  b0 10 00 16  mov  %l6, %i0
a00e52c0:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00e52c4:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e52c8:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00e52cc:  90 10 00 18  mov  %i0, %o0
a00e52d0:  92 12 60 58  or  %o1, 0x58, %o1
a00e52d4:  94 12 a0 48  or  %o2, 0x48, %o2
a00e52d8:  10 bf ff f2  b  0xa00e52a0
a00e52dc:  96 12 e0 38  or  %o3, 0x38, %o3
a00e52e0:  81 c7 e0 08  ret
a00e52e4:  81 e8 00 00  restore
