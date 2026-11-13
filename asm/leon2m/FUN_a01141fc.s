# leon2m FUN_a01141fc 0xa01141fc-0xa011433c (320 bytes)
a01141fc:  9c 03 bf 80  add  %sp, -128, %sp
a0114200:  13 33 c0 56  sethi  %hi(0xcf015800), %o1
a0114204:  90 10 20 1d  mov  0x1d, %o0
a0114208:  96 12 63 7c  or  %o1, 0x37c, %o3
a011420c:  d0 22 c0 00  st  %o0, [ %o3 ]
a0114210:  98 12 63 80  or  %o1, 0x380, %o4
a0114214:  82 10 20 11  mov  0x11, %g1
a0114218:  c2 23 00 00  st  %g1, [ %o4 ]
a011421c:  9a 12 63 84  or  %o1, 0x384, %o5
a0114220:  94 10 20 ff  mov  0xff, %o2
a0114224:  d4 23 40 00  st  %o2, [ %o5 ]
a0114228:  96 12 63 88  or  %o1, 0x388, %o3
a011422c:  82 12 63 8c  or  %o1, 0x38c, %g1
a0114230:  c0 22 c0 00  clr  [ %o3 ]
a0114234:  d0 20 40 00  st  %o0, [ %g1 ]
a0114238:  98 10 20 2b  mov  0x2b, %o4
a011423c:  94 10 20 67  mov  0x67, %o2
a0114240:  92 10 20 12  mov  0x12, %o1
a0114244:  90 10 20 68  mov  0x68, %o0
a0114248:  9a 10 3f cf  mov  -49, %o5
a011424c:  82 10 20 24  mov  0x24, %g1
a0114250:  d8 2b a0 72  stb  %o4, [ %sp + 0x72 ]
a0114254:  d4 2b a0 62  stb  %o2, [ %sp + 0x62 ]
a0114258:  d2 2b a0 63  stb  %o1, [ %sp + 0x63 ]
a011425c:  d0 2b a0 64  stb  %o0, [ %sp + 0x64 ]
a0114260:  96 10 20 01  mov  1, %o3
a0114264:  98 10 3f d0  mov  -48, %o4
a0114268:  94 10 20 37  mov  0x37, %o2
a011426c:  92 10 20 45  mov  0x45, %o1
a0114270:  90 10 20 38  mov  0x38, %o0
a0114274:  da 2b a0 65  stb  %o5, [ %sp + 0x65 ]
a0114278:  c2 2b a0 66  stb  %g1, [ %sp + 0x66 ]
a011427c:  d6 2b a0 60  stb  %o3, [ %sp + 0x60 ]
a0114280:  d8 2b a0 67  stb  %o4, [ %sp + 0x67 ]
a0114284:  d4 2b a0 68  stb  %o2, [ %sp + 0x68 ]
a0114288:  d2 2b a0 69  stb  %o1, [ %sp + 0x69 ]
a011428c:  d0 2b a0 6a  stb  %o0, [ %sp + 0x6a ]
a0114290:  9a 10 3f 9f  mov  -97, %o5
a0114294:  d6 2b a0 70  stb  %o3, [ %sp + 0x70 ]
a0114298:  03 00 00 15  sethi  %hi(0x5400), %g1
a011429c:  da 2b a0 6b  stb  %o5, [ %sp + 0x6b ]
a01142a0:  c0 2b a0 71  clrb  [ %sp + 0x71 ]
a01142a4:  c0 2b a0 61  clrb  [ %sp + 0x61 ]
a01142a8:  92 10 62 e4  or  %g1, 0x2e4, %o1
a01142ac:  96 10 20 00  clr  %o3
a01142b0:  98 10 20 00  clr  %o4
a01142b4:  90 03 a0 78  add  %sp, 0x78, %o0
a01142b8:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a01142bc:  9a 03 00 09  add  %o4, %o1, %o5
a01142c0:  98 02 00 0c  add  %o0, %o4, %o4
a01142c4:  83 2b 60 02  sll  %o5, 2, %g1
a01142c8:  da 0b 3f e8  ldub  [ %o4 + -24 ], %o5
a01142cc:  96 02 e0 01  inc  %o3
a01142d0:  82 10 40 0a  or  %g1, %o2, %g1
a01142d4:  98 0a e0 ff  and  %o3, 0xff, %o4
a01142d8:  da 20 40 00  st  %o5, [ %g1 ]
a01142dc:  80 a3 20 0b  cmp  %o4, 0xb
a01142e0:  08 bf ff f8  bleu  0xa01142c0
a01142e4:  9a 03 00 09  add  %o4, %o1, %o5
a01142e8:  15 00 00 15  sethi  %hi(0x5400), %o2
a01142ec:  92 12 a2 a0  or  %o2, 0x2a0, %o1	! 0x56a0
a01142f0:  96 10 20 00  clr  %o3
a01142f4:  98 10 20 00  clr  %o4
a01142f8:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a01142fc:  9a 03 00 09  add  %o4, %o1, %o5
a0114300:  98 02 00 0c  add  %o0, %o4, %o4
a0114304:  83 2b 60 02  sll  %o5, 2, %g1
a0114308:  da 0b 3f f8  ldub  [ %o4 + -8 ], %o5
a011430c:  96 02 e0 01  inc  %o3
a0114310:  82 10 40 0a  or  %g1, %o2, %g1
a0114314:  98 0a e0 ff  and  %o3, 0xff, %o4
a0114318:  da 20 40 00  st  %o5, [ %g1 ]
a011431c:  80 a3 20 02  cmp  %o4, 2
a0114320:  28 bf ff f8  bleu,a   0xa0114300
a0114324:  9a 03 00 09  add  %o4, %o1, %o5
a0114328:  13 33 c0 56  sethi  %hi(0xcf015800), %o1
a011432c:  90 12 63 c0  or  %o1, 0x3c0, %o0	! 0xcf015bc0
a0114330:  c0 22 00 00  clr  [ %o0 ]
a0114334:  81 c3 e0 08  retl
a0114338:  9c 23 bf 80  sub  %sp, -128, %sp
