# leon2s FUN_a009c09c 0xa009c09c-0xa009c188 (236 bytes)
a009c09c:  90 0a 20 ff  and  %o0, 0xff, %o0
a009c0a0:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a009c0a4:  9a 13 63 e0  or  %o5, 0x3e0, %o5	! 0xa807d7e0
a009c0a8:  82 5a 21 90  smul  %o0, 0x190, %g1
a009c0ac:  82 00 40 0d  add  %g1, %o5, %g1
a009c0b0:  c2 08 60 2d  ldub  [ %g1 + 0x2d ], %g1
a009c0b4:  80 a0 60 00  cmp  %g1, 0
a009c0b8:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009c0bc:  02 80 00 28  be  0xa009c15c
a009c0c0:  9a 5a 20 34  smul  %o0, 0x34, %o5
a009c0c4:  82 10 63 00  or  %g1, 0x300, %g1
a009c0c8:  82 03 40 01  add  %o5, %g1, %g1
a009c0cc:  d8 00 60 20  ld  [ %g1 + 0x20 ], %o4
a009c0d0:  c2 03 20 58  ld  [ %o4 + 0x58 ], %g1
a009c0d4:  83 30 60 10  srl  %g1, 0x10, %g1
a009c0d8:  80 a0 60 00  cmp  %g1, 0
a009c0dc:  02 80 00 05  be  0xa009c0f0
a009c0e0:  1b 2a 01 e4  sethi  %hi(0xa8079000), %o5
a009c0e4:  c2 03 20 58  ld  [ %o4 + 0x58 ], %g1
a009c0e8:  10 80 00 20  b  0xa009c168
a009c0ec:  83 30 60 10  srl  %g1, 0x10, %g1
a009c0f0:  9a 13 60 a8  or  %o5, 0xa8, %o5
a009c0f4:  d0 0b 40 08  ldub  [ %o5 + %o0 ], %o0
a009c0f8:  c2 03 20 54  ld  [ %o4 + 0x54 ], %g1
a009c0fc:  da 03 20 4c  ld  [ %o4 + 0x4c ], %o5
a009c100:  83 30 60 02  srl  %g1, 2, %g1
a009c104:  9b 2b 40 08  sll  %o5, %o0, %o5
a009c108:  80 a3 60 00  cmp  %o5, 0
a009c10c:  02 80 00 12  be  0xa009c154
a009c110:  83 28 40 08  sll  %g1, %o0, %g1
a009c114:  9b 28 60 10  sll  %g1, 0x10, %o5
a009c118:  97 33 60 10  srl  %o5, 0x10, %o3
a009c11c:  80 a2 e0 00  cmp  %o3, 0
a009c120:  22 80 00 12  be,a   0xa009c168
a009c124:  82 10 20 00  clr  %g1
a009c128:  c2 03 20 4c  ld  [ %o4 + 0x4c ], %g1
a009c12c:  83 28 40 08  sll  %g1, %o0, %g1
a009c130:  9b 33 60 11  srl  %o5, 0x11, %o5
a009c134:  82 00 40 0d  add  %g1, %o5, %g1
a009c138:  81 80 00 00  mov  %g0, %y
a009c13c:  01 00 00 00  nop
a009c140:  01 00 00 00  nop
a009c144:  01 00 00 00  nop
a009c148:  82 70 40 0b  udiv  %g1, %o3, %g1
a009c14c:  10 80 00 08  b  0xa009c16c
a009c150:  83 28 60 10  sll  %g1, 0x10, %g1
a009c154:  10 80 00 05  b  0xa009c168
a009c158:  82 10 20 00  clr  %g1
a009c15c:  82 10 63 00  or  %g1, 0x300, %g1
a009c160:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a009c164:  c2 00 60 3c  ld  [ %g1 + 0x3c ], %g1
a009c168:  83 28 60 10  sll  %g1, 0x10, %g1
a009c16c:  83 30 60 10  srl  %g1, 0x10, %g1
a009c170:  80 a0 60 00  cmp  %g1, 0
a009c174:  02 80 00 03  be  0xa009c180
a009c178:  90 10 20 01  mov  1, %o0
a009c17c:  90 10 00 01  mov  %g1, %o0
a009c180:  81 c3 e0 08  retl
a009c184:  01 00 00 00  nop
