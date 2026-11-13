# leon2s FUN_a00a211c 0xa00a211c-0xa00a2230 (276 bytes)
a00a211c:  9d e3 bf 98  save  %sp, -104, %sp
a00a2120:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a2124:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a2128:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a00a212c:  9a 5c 20 34  smul  %l0, 0x34, %o5
a00a2130:  9a 03 40 01  add  %o5, %g1, %o5
a00a2134:  d8 03 60 04  ld  [ %o5 + 4 ], %o4
a00a2138:  da 03 20 08  ld  [ %o4 + 8 ], %o5
a00a213c:  c2 03 20 04  ld  [ %o4 + 4 ], %g1
a00a2140:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00a2144:  9b 2b 60 10  sll  %o5, 0x10, %o5
a00a2148:  83 30 60 10  srl  %g1, 0x10, %g1
a00a214c:  a4 13 40 01  or  %o5, %g1, %l2
a00a2150:  da 03 20 0c  ld  [ %o4 + 0xc ], %o5
a00a2154:  03 3f c0 00  sethi  %hi(0xff000000), %g1
a00a2158:  a2 2b 40 01  andn  %o5, %g1, %l1
a00a215c:  80 a0 00 12  cmp  %g0, %l2
a00a2160:  9a 40 20 00  addx  %g0, 0, %o5
a00a2164:  80 a0 00 11  cmp  %g0, %l1
a00a2168:  82 40 20 00  addx  %g0, 0, %g1
a00a216c:  80 8b 40 01  btst  %o5, %g1
a00a2170:  02 80 00 2e  be  0xa00a2228
a00a2174:  b0 10 20 00  clr  %i0
a00a2178:  7f ff ff cc  call  0xa00a20a8
a00a217c:  90 10 00 10  mov  %l0, %o0
a00a2180:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a2184:  80 a2 20 06  cmp  %o0, 6
a00a2188:  18 80 00 1b  bgu  0xa00a21f4
a00a218c:  82 10 20 00  clr  %g1
a00a2190:  1b 28 02 88  sethi  %hi(0xa00a2000), %o5
a00a2194:  83 2a 20 02  sll  %o0, 2, %g1
a00a2198:  9a 13 61 00  or  %o5, 0x100, %o5
a00a219c:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00a21a0:  81 c0 40 00  jmp  %g1
a00a21a4:  01 00 00 00  nop
a00a21a8:  7f ff ff c7  call  0xa00a20c4
a00a21ac:  90 10 00 10  mov  %l0, %o0
a00a21b0:  91 2a 20 10  sll  %o0, 0x10, %o0
a00a21b4:  03 33 33 33  sethi  %hi(0xcccccc00), %g1
a00a21b8:  82 10 60 cd  or  %g1, 0xcd, %g1	! 0xcccccccd
a00a21bc:  91 32 20 10  srl  %o0, 0x10, %o0
a00a21c0:  80 52 00 01  umul  %o0, %g1, %g0
a00a21c4:  91 40 00 00  rd  %y, %o0
a00a21c8:  10 80 00 0b  b  0xa00a21f4
a00a21cc:  83 32 20 03  srl  %o0, 3, %g1
a00a21d0:  10 80 00 09  b  0xa00a21f4
a00a21d4:  82 10 20 a6  mov  0xa6, %g1
a00a21d8:  10 80 00 07  b  0xa00a21f4
a00a21dc:  82 10 21 4d  mov  0x14d, %g1
a00a21e0:  10 80 00 05  b  0xa00a21f4
a00a21e4:  82 10 21 bc  mov  0x1bc, %g1
a00a21e8:  10 80 00 03  b  0xa00a21f4
a00a21ec:  82 10 22 2b  mov  0x22b, %g1
a00a21f0:  82 10 22 9a  mov  0x29a, %g1
a00a21f4:  83 28 60 10  sll  %g1, 0x10, %g1
a00a21f8:  83 30 60 10  srl  %g1, 0x10, %g1
a00a21fc:  82 58 40 12  smul  %g1, %l2, %g1
a00a2200:  1b 00 00 09  sethi  %hi(0x2400), %o5
a00a2204:  81 80 00 00  mov  %g0, %y
a00a2208:  01 00 00 00  nop
a00a220c:  01 00 00 00  nop
a00a2210:  01 00 00 00  nop
a00a2214:  82 70 40 11  udiv  %g1, %l1, %g1
a00a2218:  9a 13 63 10  or  %o5, 0x310, %o5
a00a221c:  82 58 40 0d  smul  %g1, %o5, %g1
a00a2220:  83 28 60 09  sll  %g1, 9, %g1
a00a2224:  b1 30 60 10  srl  %g1, 0x10, %i0
a00a2228:  81 c7 e0 08  ret
a00a222c:  81 e8 00 00  restore
