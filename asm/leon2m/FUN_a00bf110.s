# leon2m FUN_a00bf110 0xa00bf110-0xa00bf2c8 (440 bytes)
a00bf110:  9d e3 bf 98  save  %sp, -104, %sp
a00bf114:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00bf118:  d4 0b e2 99  ldub  [ %o7 + 0x299 ], %o2	! 0xa802d299
a00bf11c:  1b 14 7a e1  sethi  %hi(0x51eb8400), %o5
a00bf120:  a0 0a a0 ff  and  %o2, 0xff, %l0
a00bf124:  92 13 61 1f  or  %o5, 0x11f, %o1
a00bf128:  80 54 00 09  umul  %l0, %o1, %g0
a00bf12c:  97 40 00 00  rd  %y, %o3
a00bf130:  a1 32 e0 05  srl  %o3, 5, %l0
a00bf134:  b2 0c 20 ff  and  %l0, 0xff, %i1
a00bf138:  90 5e 60 64  smul  %i1, 0x64, %o0
a00bf13c:  b2 22 80 08  sub  %o2, %o0, %i1
a00bf140:  03 33 33 33  sethi  %hi(0xcccccc00), %g1
a00bf144:  9e 0e 60 ff  and  %i1, 0xff, %o7
a00bf148:  98 10 60 cd  or  %g1, 0xcd, %o4
a00bf14c:  80 53 c0 0c  umul  %o7, %o4, %g0
a00bf150:  9b 40 00 00  rd  %y, %o5
a00bf154:  9f 33 60 03  srl  %o5, 3, %o7
a00bf158:  92 0b e0 ff  and  %o7, 0xff, %o1
a00bf15c:  91 2a 60 02  sll  %o1, 2, %o0
a00bf160:  82 02 00 09  add  %o0, %o1, %g1
a00bf164:  98 00 40 01  add  %g1, %g1, %o4
a00bf168:  92 26 40 0c  sub  %i1, %o4, %o1
a00bf16c:  96 04 20 30  add  %l0, 0x30, %o3
a00bf170:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a00bf174:  a0 16 60 78  or  %i1, 0x78, %l0	! 0xa802d078
a00bf178:  94 02 60 30  add  %o1, 0x30, %o2
a00bf17c:  9a 03 e0 30  add  %o7, 0x30, %o5
a00bf180:  d6 2c 20 07  stb  %o3, [ %l0 + 7 ]
a00bf184:  da 2c 20 08  stb  %o5, [ %l0 + 8 ]
a00bf188:  d4 2c 20 09  stb  %o2, [ %l0 + 9 ]
a00bf18c:  92 10 20 00  clr  %o1
a00bf190:  40 02 55 2b  call  0xa015463c
a00bf194:  90 10 20 02  mov  2, %o0
a00bf198:  d0 2e 60 78  stb  %o0, [ %i1 + 0x78 ]
a00bf19c:  90 10 20 62  mov  0x62, %o0
a00bf1a0:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00bf1a4:  92 10 20 02  mov  2, %o1
a00bf1a8:  40 02 55 25  call  0xa015463c
a00bf1ac:  90 10 20 02  mov  2, %o0
a00bf1b0:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00bf1b4:  92 10 20 03  mov  3, %o1
a00bf1b8:  40 02 55 21  call  0xa015463c
a00bf1bc:  90 10 20 02  mov  2, %o0
a00bf1c0:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00bf1c4:  92 10 20 04  mov  4, %o1
a00bf1c8:  40 02 55 1d  call  0xa015463c
a00bf1cc:  90 10 20 02  mov  2, %o0
a00bf1d0:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00bf1d4:  92 10 20 05  mov  5, %o1
a00bf1d8:  40 02 55 19  call  0xa015463c
a00bf1dc:  90 10 20 02  mov  2, %o0
a00bf1e0:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00bf1e4:  90 10 20 02  mov  2, %o0
a00bf1e8:  40 02 55 15  call  0xa015463c
a00bf1ec:  92 10 20 06  mov  6, %o1
a00bf1f0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bf1f4:  82 10 20 0d  mov  0xd, %g1
a00bf1f8:  c2 2c 20 0a  stb  %g1, [ %l0 + 0xa ]
a00bf1fc:  80 a6 20 02  cmp  %i0, 2
a00bf200:  02 80 00 26  be  0xa00bf298
a00bf204:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00bf208:  80 a6 20 03  cmp  %i0, 3
a00bf20c:  02 80 00 29  be  0xa00bf2b0
a00bf210:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00bf214:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00bf218:  9a 12 e0 d0  or  %o3, 0xd0, %o5	! 0xa802d0d0
a00bf21c:  c0 2c 20 9c  clrb  [ %l0 + 0x9c ]
a00bf220:  c0 2a e0 d0  clrb  [ %o3 + 0xd0 ]
a00bf224:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bf228:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bf22c:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bf230:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bf234:  94 16 60 78  or  %i1, 0x78, %o2
a00bf238:  90 10 00 18  mov  %i0, %o0
a00bf23c:  40 02 25 6b  call  0xa01487e8
a00bf240:  92 10 20 0b  mov  0xb, %o1
a00bf244:  33 00 06 60  sethi  %hi(0x198000), %i1
a00bf248:  40 00 7f ca  call  0xa00df170
a00bf24c:  90 16 62 c8  or  %i1, 0x2c8, %o0	! 0x1982c8
a00bf250:  92 10 20 10  mov  0x10, %o1
a00bf254:  94 10 20 00  clr  %o2
a00bf258:  96 10 20 00  clr  %o3
a00bf25c:  40 02 25 4e  call  0xa0148794
a00bf260:  90 10 20 00  clr  %o0
a00bf264:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a00bf268:  40 01 97 af  call  0xa0125124
a00bf26c:  d0 0e 21 4a  ldub  [ %i0 + 0x14a ], %o0	! 0xa802e14a
a00bf270:  92 0a 20 ff  and  %o0, 0xff, %o1
a00bf274:  90 10 20 00  clr  %o0
a00bf278:  94 10 20 00  clr  %o2
a00bf27c:  40 01 22 4c  call  0xa0107bac
a00bf280:  96 10 20 00  clr  %o3
a00bf284:  40 01 d3 40  call  0xa0133f84
a00bf288:  90 10 20 01  mov  1, %o0
a00bf28c:  b0 10 20 01  mov  1, %i0
a00bf290:  40 01 d2 fb  call  0xa0133e7c
a00bf294:  93 e8 20 6e  restore  %g0, 0x6e, %o1
a00bf298:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bf29c:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00bf2a0:  9a 13 20 40  or  %o4, 0x40, %o5
a00bf2a4:  c0 28 60 9a  clrb  [ %g1 + 0x9a ]
a00bf2a8:  10 bf ff df  b  0xa00bf224
a00bf2ac:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00bf2b0:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bf2b4:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00bf2b8:  9a 12 a0 98  or  %o2, 0x98, %o5
a00bf2bc:  c0 2a 20 98  clrb  [ %o0 + 0x98 ]
a00bf2c0:  10 bf ff d9  b  0xa00bf224
a00bf2c4:  c0 2a a0 98  clrb  [ %o2 + 0x98 ]
