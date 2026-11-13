# leon2m FUN_a0127154 0xa0127154-0xa01272c8 (372 bytes)
a0127154:  9d e3 bf 90  save  %sp, -112, %sp
a0127158:  2b 2a 00 b6  sethi  %hi(0xa802d800), %l5
a012715c:  a2 15 60 90  or  %l5, 0x90, %l1	! 0xa802d890
a0127160:  f0 2c 60 01  stb  %i0, [ %l1 + 1 ]
a0127164:  7f ff f5 d9  call  0xa01248c8
a0127168:  c0 2d 60 90  clrb  [ %l5 + 0x90 ]
a012716c:  80 8a 20 ff  btst  0xff, %o0
a0127170:  02 80 00 54  be  0xa01272c0
a0127174:  15 00 06 91  sethi  %hi(0x1a4400), %o2
a0127178:  92 0e 20 ff  and  %i0, 0xff, %o1
a012717c:  7f fe df fd  call  0xa00df170
a0127180:  90 12 a3 f0  or  %o2, 0x3f0, %o0
a0127184:  82 10 20 01  mov  1, %g1
a0127188:  a4 10 20 02  mov  2, %l2
a012718c:  c2 23 a0 60  st  %g1, [ %sp + 0x60 ]
a0127190:  9a 10 00 11  mov  %l1, %o5
a0127194:  92 10 20 02  mov  2, %o1
a0127198:  94 10 21 b4  mov  0x1b4, %o2
a012719c:  96 10 20 05  mov  5, %o3
a01271a0:  98 10 20 00  clr  %o4
a01271a4:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a01271a8:  40 00 82 3e  call  0xa0147aa0
a01271ac:  90 10 20 60  mov  0x60, %o0
a01271b0:  67 fd 97 fc  call  0x4008d1a0
a01271b4:  90 10 20 32  mov  0x32, %o0
a01271b8:  2d 2a 00 b6  sethi  %hi(0xa802d800), %l6
a01271bc:  96 10 20 05  mov  5, %o3
a01271c0:  98 10 20 00  clr  %o4
a01271c4:  9a 15 a0 88  or  %l6, 0x88, %o5
a01271c8:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a01271cc:  92 10 20 02  mov  2, %o1
a01271d0:  94 10 21 b4  mov  0x1b4, %o2
a01271d4:  40 00 82 45  call  0xa0147ae8
a01271d8:  90 10 20 60  mov  0x60, %o0
a01271dc:  a0 15 a0 88  or  %l6, 0x88, %l0
a01271e0:  11 00 06 92  sethi  %hi(0x1a4800), %o0
a01271e4:  d4 0c 20 01  ldub  [ %l0 + 1 ], %o2
a01271e8:  d2 0d a0 88  ldub  [ %l6 + 0x88 ], %o1
a01271ec:  7f fe df e1  call  0xa00df170
a01271f0:  90 12 20 18  or  %o0, 0x18, %o0
a01271f4:  a4 10 00 11  mov  %l1, %l2
a01271f8:  90 10 20 32  mov  0x32, %o0
a01271fc:  67 fd 97 e9  call  0x4008d1a0
a0127200:  a2 10 00 10  mov  %l0, %l1
a0127204:  a8 10 00 15  mov  %l5, %l4
a0127208:  a6 10 00 16  mov  %l6, %l3
a012720c:  10 80 00 1f  b  0xa0127288
a0127210:  a0 10 20 02  mov  2, %l0
a0127214:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a0127218:  80 a2 e0 09  cmp  %o3, 9
a012721c:  18 80 00 29  bgu  0xa01272c0
a0127220:  d2 0d 20 90  ldub  [ %l4 + 0x90 ], %o1
a0127224:  7f fe df d3  call  0xa00df170
a0127228:  d6 0c e0 88  ldub  [ %l3 + 0x88 ], %o3
a012722c:  98 10 20 01  mov  1, %o4
a0127230:  d8 23 a0 60  st  %o4, [ %sp + 0x60 ]
a0127234:  92 10 20 02  mov  2, %o1
a0127238:  94 10 21 b4  mov  0x1b4, %o2
a012723c:  96 10 20 05  mov  5, %o3
a0127240:  98 10 20 00  clr  %o4
a0127244:  9a 10 00 12  mov  %l2, %o5
a0127248:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a012724c:  40 00 82 15  call  0xa0147aa0
a0127250:  90 10 20 60  mov  0x60, %o0
a0127254:  67 fd 97 d3  call  0x4008d1a0
a0127258:  90 10 20 05  mov  5, %o0
a012725c:  92 10 20 02  mov  2, %o1
a0127260:  96 10 20 05  mov  5, %o3
a0127264:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a0127268:  90 10 20 60  mov  0x60, %o0
a012726c:  94 10 21 b4  mov  0x1b4, %o2
a0127270:  98 10 20 00  clr  %o4
a0127274:  40 00 82 1d  call  0xa0147ae8
a0127278:  9a 10 00 11  mov  %l1, %o5
a012727c:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a0127280:  92 02 e0 01  add  %o3, 1, %o1
a0127284:  d2 2e 21 fd  stb  %o1, [ %i0 + 0x1fd ]
a0127288:  31 00 06 92  sethi  %hi(0x1a4800), %i0
a012728c:  da 0c a0 01  ldub  [ %l2 + 1 ], %o5
a0127290:  de 0c 60 01  ldub  [ %l1 + 1 ], %o7
a0127294:  90 16 20 40  or  %i0, 0x40, %o0
a0127298:  31 2a 00 b2  sethi  %hi(0xa802c800), %i0
a012729c:  94 10 00 0d  mov  %o5, %o2
a01272a0:  80 a3 40 0f  cmp  %o5, %o7
a01272a4:  12 bf ff dc  bne  0xa0127214
a01272a8:  98 10 00 0f  mov  %o7, %o4
a01272ac:  d2 0d 60 90  ldub  [ %l5 + 0x90 ], %o1
a01272b0:  c2 0d a0 88  ldub  [ %l6 + 0x88 ], %g1
a01272b4:  80 a2 40 01  cmp  %o1, %g1
a01272b8:  12 bf ff d8  bne  0xa0127218
a01272bc:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a01272c0:  81 c7 e0 08  ret
a01272c4:  81 e8 00 00  restore
