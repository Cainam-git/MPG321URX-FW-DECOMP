# leon2m FUN_a00df170 0xa00df170-0xa00df278 (264 bytes)
a00df170:  9d e3 bf 48  save  %sp, -184, %sp
a00df174:  a2 07 bf a8  add  %fp, -88, %l1
a00df178:  f2 27 a0 48  st  %i1, [ %fp + 0x48 ]
a00df17c:  f4 27 a0 4c  st  %i2, [ %fp + 0x4c ]
a00df180:  f6 27 a0 50  st  %i3, [ %fp + 0x50 ]
a00df184:  f8 27 a0 54  st  %i4, [ %fp + 0x54 ]
a00df188:  fa 27 a0 58  st  %i5, [ %fp + 0x58 ]
a00df18c:  94 10 00 18  mov  %i0, %o2
a00df190:  90 10 00 11  mov  %l1, %o0
a00df194:  92 10 20 50  mov  0x50, %o1
a00df198:  40 01 e9 17  call  0xa01595f4
a00df19c:  96 07 a0 48  add  %fp, 0x48, %o3
a00df1a0:  80 a2 20 01  cmp  %o0, 1
a00df1a4:  02 80 00 2f  be  0xa00df260
a00df1a8:  a0 10 00 08  mov  %o0, %l0
a00df1ac:  b4 10 20 00  clr  %i2
a00df1b0:  80 a6 80 10  cmp  %i2, %l0
a00df1b4:  16 80 00 2f  bge  0xa00df270
a00df1b8:  11 00 03 ff  sethi  %hi(0xffc00), %o0
a00df1bc:  a4 12 23 fe  or  %o0, 0x3fe, %l2	! 0xffffe
a00df1c0:  33 30 02 c0  sethi  %hi(0xc00b0000), %i1
a00df1c4:  b0 10 00 12  mov  %l2, %i0
a00df1c8:  f8 0c 40 1a  ldub  [ %l1 + %i2 ], %i4
a00df1cc:  ba 10 20 00  clr  %i5
a00df1d0:  67 fe b4 20  call  0x4008c250
a00df1d4:  90 16 60 14  or  %i1, 0x14, %o0
a00df1d8:  80 8a 20 20  btst  0x20, %o0
a00df1dc:  12 80 00 05  bne  0xa00df1f0
a00df1e0:  ba 07 60 01  inc  %i5
a00df1e4:  80 a7 40 18  cmp  %i5, %i0
a00df1e8:  08 bf ff fa  bleu  0xa00df1d0
a00df1ec:  01 00 00 00  nop
a00df1f0:  95 2f 20 18  sll  %i4, 0x18, %o2
a00df1f4:  93 3a a0 18  sra  %o2, 0x18, %o1
a00df1f8:  67 fe b4 19  call  0x4008c25c
a00df1fc:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a00df200:  d2 4c 40 1a  ldsb  [ %l1 + %i2 ], %o1
a00df204:  80 a2 60 0a  cmp  %o1, 0xa
a00df208:  ba 10 20 00  clr  %i5
a00df20c:  37 30 02 c0  sethi  %hi(0xc00b0000), %i3
a00df210:  02 80 00 0a  be  0xa00df238
a00df214:  b8 10 00 12  mov  %l2, %i4
a00df218:  b4 06 a0 01  inc  %i2
a00df21c:  80 a6 80 10  cmp  %i2, %l0
a00df220:  26 bf ff eb  bl,a   0xa00df1cc
a00df224:  f8 0c 40 1a  ldub  [ %l1 + %i2 ], %i4
a00df228:  30 80 00 12  b,a   0xa00df270
a00df22c:  80 a7 40 1c  cmp  %i5, %i4
a00df230:  18 80 00 08  bgu  0xa00df250
a00df234:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a00df238:  67 fe b4 06  call  0x4008c250
a00df23c:  90 16 e0 14  or  %i3, 0x14, %o0
a00df240:  80 8a 20 20  btst  0x20, %o0
a00df244:  02 bf ff fa  be  0xa00df22c
a00df248:  ba 07 60 01  inc  %i5
a00df24c:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a00df250:  67 fe b4 03  call  0x4008c25c
a00df254:  92 10 20 0d  mov  0xd, %o1
a00df258:  10 bf ff f1  b  0xa00df21c
a00df25c:  b4 06 a0 01  inc  %i2
a00df260:  c2 4f bf a8  ldsb  [ %fp + -88 ], %g1
a00df264:  80 a0 60 00  cmp  %g1, 0
a00df268:  12 bf ff d2  bne  0xa00df1b0
a00df26c:  b4 10 20 00  clr  %i2
a00df270:  81 c7 e0 08  ret
a00df274:  91 e8 20 00  restore  %g0, 0, %o0
