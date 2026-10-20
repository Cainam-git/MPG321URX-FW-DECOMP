# leon2m FUN_a0148120 0xa0148120-0xa0148230 (272 bytes)
a0148120:  9d e3 bf 98  save  %sp, -104, %sp
a0148124:  96 10 20 00  clr  %o3
a0148128:  98 10 20 00  clr  %o4
a014812c:  10 80 00 06  b  0xa0148144
a0148130:  9a 10 20 00  clr  %o5
a0148134:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0148138:  80 a3 60 2c  cmp  %o5, 0x2c
a014813c:  18 80 00 0e  bgu  0xa0148174
a0148140:  01 00 00 00  nop
a0148144:  c2 0b 40 18  ldub  [ %o5 + %i0 ], %g1
a0148148:  80 a0 60 00  cmp  %g1, 0
a014814c:  02 80 00 30  be  0xa014820c
a0148150:  80 a3 60 2c  cmp  %o5, 0x2c
a0148154:  32 bf ff f8  bne,a   0xa0148134
a0148158:  98 03 20 01  inc  %o4
a014815c:  96 10 00 0c  mov  %o4, %o3
a0148160:  98 03 20 01  inc  %o4
a0148164:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0148168:  80 a3 60 2c  cmp  %o5, 0x2c
a014816c:  28 bf ff f7  bleu,a   0xa0148148
a0148170:  c2 0b 40 18  ldub  [ %o5 + %i0 ], %g1
a0148174:  7f ff 6f fd  call  0xa0124168
a0148178:  a2 10 00 0b  mov  %o3, %l1
a014817c:  7f ff 6f fe  call  0xa0124174
a0148180:  a4 10 00 08  mov  %o0, %l2
a0148184:  a0 0c a0 ff  and  %l2, 0xff, %l0
a0148188:  15 00 00 3c  sethi  %hi(0xf000), %o2
a014818c:  96 12 a1 90  or  %o2, 0x190, %o3	! 0xf190
a0148190:  a0 04 00 10  add  %l0, %l0, %l0
a0148194:  92 04 00 0b  add  %l0, %o3, %o1
a0148198:  91 2a 60 02  sll  %o1, 2, %o0
a014819c:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a01481a0:  98 12 00 0b  or  %o0, %o3, %o4
a01481a4:  da 03 00 00  ld  [ %o4 ], %o5
a01481a8:  80 a3 60 96  cmp  %o5, 0x96
a01481ac:  32 80 00 1f  bne,a   0xa0148228
a01481b0:  b0 10 20 04  mov  4, %i0
a01481b4:  a6 12 a1 91  or  %o2, 0x191, %l3
a01481b8:  9e 04 00 13  add  %l0, %l3, %o7
a01481bc:  95 2b e0 02  sll  %o7, 2, %o2
a01481c0:  a6 12 80 0b  or  %o2, %o3, %l3
a01481c4:  a2 0c 60 ff  and  %l1, 0xff, %l1
a01481c8:  a0 10 00 0c  mov  %o4, %l0
a01481cc:  a4 10 00 13  mov  %l3, %l2
a01481d0:  7f ff 6d c6  call  0xa01238e8
a01481d4:  01 00 00 00  nop
a01481d8:  90 10 00 18  mov  %i0, %o0
a01481dc:  7f ff 6e a9  call  0xa0123c80
a01481e0:  92 10 00 11  mov  %l1, %o1
a01481e4:  98 0a 20 ff  and  %o0, 0xff, %o4
a01481e8:  80 a3 20 01  cmp  %o4, 1
a01481ec:  22 80 00 0a  be,a   0xa0148214
a01481f0:  a2 10 20 48  mov  0x48, %l1
a01481f4:  c2 04 00 00  ld  [ %l0 ], %g1
a01481f8:  80 a0 60 96  cmp  %g1, 0x96
a01481fc:  02 bf ff f5  be  0xa01481d0
a0148200:  01 00 00 00  nop
a0148204:  10 80 00 09  b  0xa0148228
a0148208:  b0 10 20 04  mov  4, %i0	! 0x4
a014820c:  10 bf ff da  b  0xa0148174
a0148210:  96 10 00 0c  mov  %o4, %o3
a0148214:  e2 24 c0 00  st  %l1, [ %l3 ]
a0148218:  f0 04 80 00  ld  [ %l2 ], %i0
a014821c:  80 a6 20 48  cmp  %i0, 0x48
a0148220:  02 bf ff fe  be  0xa0148218
a0148224:  b0 10 20 02  mov  2, %i0
a0148228:  81 c7 e0 08  ret
a014822c:  81 e8 00 00  restore
