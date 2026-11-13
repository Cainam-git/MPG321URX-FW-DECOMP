# leon2m FUN_a0095fb0 0xa0095fb0-0xa00961a4 (500 bytes)
a0095fb0:  9d e3 bf 98  save  %sp, -104, %sp
a0095fb4:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a0095fb8:  98 12 a2 90  or  %o2, 0x290, %o4	! 0xa802d290
a0095fbc:  13 2a 00 97  sethi  %hi(0xa8025c00), %o1
a0095fc0:  da 0b 21 81  ldub  [ %o4 + 0x181 ], %o5
a0095fc4:  c2 0a 60 56  ldub  [ %o1 + 0x56 ], %g1
a0095fc8:  80 a3 40 01  cmp  %o5, %g1
a0095fcc:  02 80 00 6d  be  0xa0096180
a0095fd0:  17 2a 00 97  sethi  %hi(0xa8025c00), %o3
a0095fd4:  2b 00 3f ff  sethi  %hi(0xfffc00), %l5
a0095fd8:  e6 03 21 80  ld  [ %o4 + 0x180 ], %l3
a0095fdc:  a8 15 63 00  or  %l5, 0x300, %l4
a0095fe0:  a4 0c c0 14  and  %l3, %l4, %l2
a0095fe4:  80 a4 a1 00  cmp  %l2, 0x100
a0095fe8:  02 80 00 56  be  0xa0096140
a0095fec:  aa 10 20 01  mov  1, %l5
a0095ff0:  e4 0a e0 55  ldub  [ %o3 + 0x55 ], %l2
a0095ff4:  a8 12 a2 90  or  %o2, 0x290, %l4
a0095ff8:  9a 0c a0 01  and  %l2, 1, %o5
a0095ffc:  d4 05 20 a8  ld  [ %l4 + 0xa8 ], %o2
a0096000:  83 2b 60 0b  sll  %o5, 0xb, %g1
a0096004:  98 0a b7 ff  and  %o2, -2049, %o4
a0096008:  1f 2a 00 97  sethi  %hi(0xa8025c00), %o7
a009600c:  e6 0a 60 56  ldub  [ %o1 + 0x56 ], %l3
a0096010:  96 13 00 01  or  %o4, %g1, %o3
a0096014:  e2 0b e0 54  ldub  [ %o7 + 0x54 ], %l1
a0096018:  d6 25 20 a8  st  %o3, [ %l4 + 0xa8 ]
a009601c:  e2 2d 20 11  stb  %l1, [ %l4 + 0x11 ]
a0096020:  e6 2d 21 81  stb  %l3, [ %l4 + 0x181 ]
a0096024:  90 0c e0 ff  and  %l3, 0xff, %o0
a0096028:  40 00 82 d8  call  0xa00b6b88
a009602c:  92 10 20 00  clr  %o1
a0096030:  a2 10 00 08  mov  %o0, %l1
a0096034:  27 2a 00 ab  sethi  %hi(0xa802ac00), %l3
a0096038:  d0 04 e3 ec  ld  [ %l3 + 0x3ec ], %o0	! 0xa802afec
a009603c:  21 09 24 92  sethi  %hi(0x24924800), %l0
a0096040:  96 02 3f a4  add  %o0, -92, %o3
a0096044:  a0 14 21 25  or  %l0, 0x125, %l0
a0096048:  80 52 c0 10  umul  %o3, %l0, %g0
a009604c:  95 40 00 00  rd  %y, %o2
a0096050:  a4 22 c0 0a  sub  %o3, %o2, %l2
a0096054:  9b 34 a0 01  srl  %l2, 1, %o5
a0096058:  92 02 80 0d  add  %o2, %o5, %o1
a009605c:  83 32 60 02  srl  %o1, 2, %g1
a0096060:  99 28 60 03  sll  %g1, 3, %o4
a0096064:  9e 23 00 01  sub  %o4, %g1, %o7
a0096068:  a4 22 c0 0f  sub  %o3, %o7, %l2
a009606c:  40 00 4c d4  call  0xa00a93bc
a0096070:  90 0c a0 ff  and  %l2, 0xff, %o0
a0096074:  d4 04 e3 ec  ld  [ %l3 + 0x3ec ], %o2
a0096078:  92 02 bf a4  add  %o2, -92, %o1
a009607c:  a4 0c 60 ff  and  %l1, 0xff, %l2
a0096080:  80 52 40 10  umul  %o1, %l0, %g0
a0096084:  9f 40 00 00  rd  %y, %o7
a0096088:  80 54 80 10  umul  %l2, %l0, %g0
a009608c:  99 40 00 00  rd  %y, %o4
a0096090:  90 24 80 0c  sub  %l2, %o4, %o0
a0096094:  82 22 40 0f  sub  %o1, %o7, %g1
a0096098:  9b 32 20 01  srl  %o0, 1, %o5
a009609c:  a3 30 60 01  srl  %g1, 1, %l1
a00960a0:  94 03 c0 11  add  %o7, %l1, %o2
a00960a4:  96 03 00 0d  add  %o4, %o5, %o3
a00960a8:  a3 32 e0 02  srl  %o3, 2, %l1
a00960ac:  93 32 a0 02  srl  %o2, 2, %o1
a00960b0:  90 0c 60 ff  and  %l1, 0xff, %o0
a00960b4:  80 a2 40 08  cmp  %o1, %o0
a00960b8:  02 80 00 05  be  0xa00960cc
a00960bc:  9f 2c 60 03  sll  %l1, 3, %o7
a00960c0:  40 00 82 cb  call  0xa00b6bec
a00960c4:  01 00 00 00  nop
a00960c8:  9f 2c 60 03  sll  %l1, 3, %o7
a00960cc:  96 23 c0 11  sub  %o7, %l1, %o3
a00960d0:  90 24 80 0b  sub  %l2, %o3, %o0
a00960d4:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00960d8:  90 10 00 10  mov  %l0, %o0
a00960dc:  40 00 4d 5d  call  0xa00a9650
a00960e0:  92 10 20 00  clr  %o1
a00960e4:  92 10 00 10  mov  %l0, %o1
a00960e8:  90 10 20 01  mov  1, %o0
a00960ec:  40 00 48 14  call  0xa00a813c
a00960f0:  94 10 20 01  mov  1, %o2
a00960f4:  92 10 20 15  mov  0x15, %o1
a00960f8:  d2 24 e3 ec  st  %o1, [ %l3 + 0x3ec ]
a00960fc:  90 10 20 00  clr  %o0
a0096100:  40 00 4b c3  call  0xa00a900c
a0096104:  92 10 20 01  mov  1, %o1
a0096108:  80 8d 60 ff  btst  0xff, %l5
a009610c:  02 80 00 09  be  0xa0096130
a0096110:  90 10 20 02  mov  2, %o0
a0096114:  ea 05 20 a8  ld  [ %l4 + 0xa8 ], %l5
a0096118:  80 8d 68 00  btst  0x800, %l5
a009611c:  12 80 00 12  bne  0xa0096164
a0096120:  01 00 00 00  nop
a0096124:  40 01 16 f3  call  0xa00dbcf0
a0096128:  01 00 00 00  nop
a009612c:  90 10 20 02  mov  2, %o0	! 0x2
a0096130:  40 00 52 e1  call  0xa00aacb4
a0096134:  92 10 20 01  mov  1, %o1
a0096138:  40 00 5a c2  call  0xa00acc40
a009613c:  81 e8 00 00  restore
a0096140:  d0 03 20 a8  ld  [ %o4 + 0xa8 ], %o0
a0096144:  83 32 20 0b  srl  %o0, 0xb, %g1
a0096148:  98 08 60 01  and  %g1, 1, %o4
a009614c:  da 0a e0 55  ldub  [ %o3 + 0x55 ], %o5
a0096150:  80 a3 40 0c  cmp  %o5, %o4
a0096154:  12 bf ff a7  bne  0xa0095ff0
a0096158:  aa 10 20 00  clr  %l5
a009615c:  10 bf ff a5  b  0xa0095ff0
a0096160:  aa 10 20 01  mov  1, %l5
a0096164:  40 01 15 75  call  0xa00db738
a0096168:  01 00 00 00  nop
a009616c:  90 10 20 02  mov  2, %o0	! 0x2
a0096170:  40 00 52 d1  call  0xa00aacb4
a0096174:  92 10 20 01  mov  1, %o1
a0096178:  40 00 5a b2  call  0xa00acc40
a009617c:  81 e8 00 00  restore
a0096180:  e2 03 20 a8  ld  [ %o4 + 0xa8 ], %l1
a0096184:  a1 34 60 0b  srl  %l1, 0xb, %l0
a0096188:  90 0c 20 01  and  %l0, 1, %o0
a009618c:  de 0a e0 55  ldub  [ %o3 + 0x55 ], %o7
a0096190:  80 a3 c0 08  cmp  %o7, %o0
a0096194:  12 bf ff 90  bne  0xa0095fd4
a0096198:  aa 10 20 00  clr  %l5
a009619c:  10 bf ff 96  b  0xa0095ff4
a00961a0:  e4 0a e0 55  ldub  [ %o3 + 0x55 ], %l2
