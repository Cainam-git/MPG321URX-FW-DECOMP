# leon2s FUN_a00980a8 0xa00980a8-0xa0098240 (408 bytes)  [FUN_a0098238 = unreachable ret/restore tail, merged]
a00980a8:  9d e3 bf 98  save  %sp, -104, %sp
a00980ac:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00980b0:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00980b4:  82 5e 21 90  smul  %i0, 0x190, %g1
a00980b8:  9a 13 63 e0  or  %o5, 0x3e0, %o5
a00980bc:  b2 00 40 0d  add  %g1, %o5, %i1
a00980c0:  c2 0e 60 02  ldub  [ %i1 + 2 ], %g1
a00980c4:  80 a0 60 00  cmp  %g1, 0
a00980c8:  02 80 00 5b  be  0xa0098234
a00980cc:  90 10 00 18  mov  %i0, %o0
a00980d0:  40 00 21 2e  call  0xa00a0588
a00980d4:  92 10 20 04  mov  4, %o1
a00980d8:  80 8a 20 ff  btst  0xff, %o0
a00980dc:  02 80 00 17  be  0xa0098138
a00980e0:  01 00 00 00  nop
a00980e4:  c2 0e 61 89  ldub  [ %i1 + 0x189 ], %g1
a00980e8:  80 a0 60 02  cmp  %g1, 2
a00980ec:  02 80 00 48  be  0xa009820c
a00980f0:  21 2a 01 f6  sethi  %hi(0xa807d800), %l0
a00980f4:  23 2a 01 f6  sethi  %hi(0xa807d800), %l1
a00980f8:  a2 14 63 00  or  %l1, 0x300, %l1	! 0xa807db00
a00980fc:  a0 5e 20 34  smul  %i0, 0x34, %l0
a0098100:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a0098104:  92 02 60 0c  add  %o1, 0xc, %o1
a0098108:  40 00 3c a9  call  0xa00a73ac
a009810c:  90 10 20 18  mov  0x18, %o0
a0098110:  a0 04 00 11  add  %l0, %l1, %l0
a0098114:  d8 04 20 08  ld  [ %l0 + 8 ], %o4
a0098118:  da 03 20 9c  ld  [ %o4 + 0x9c ], %o5
a009811c:  03 3f c0 00  sethi  %hi(0xff000000), %g1
a0098120:  82 2b 40 01  andn  %o5, %g1, %g1
a0098124:  1b 02 40 00  sethi  %hi(0x9000000), %o5
a0098128:  82 10 40 0d  or  %g1, %o5, %g1
a009812c:  c2 23 20 9c  st  %g1, [ %o4 + 0x9c ]
a0098130:  10 80 00 21  b  0xa00981b4
a0098134:  82 10 20 02  mov  2, %g1
a0098138:  7f ff ff c4  call  0xa0098048
a009813c:  90 10 00 18  mov  %i0, %o0
a0098140:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a0098144:  a4 10 63 00  or  %g1, 0x300, %l2	! 0xa807db00
a0098148:  a2 5e 20 34  smul  %i0, 0x34, %l1
a009814c:  a0 04 40 12  add  %l1, %l2, %l0
a0098150:  c2 04 20 08  ld  [ %l0 + 8 ], %g1
a0098154:  c2 00 60 80  ld  [ %g1 + 0x80 ], %g1
a0098158:  83 30 60 08  srl  %g1, 8, %g1
a009815c:  80 88 60 10  btst  0x10, %g1
a0098160:  02 80 00 17  be  0xa00981bc
a0098164:  c2 0e 61 89  ldub  [ %i1 + 0x189 ], %g1
a0098168:  80 a0 60 01  cmp  %g1, 1
a009816c:  22 80 00 29  be,a   0xa0098210
a0098170:  21 2a 01 f6  sethi  %hi(0xa807d800), %l0
a0098174:  d2 04 80 11  ld  [ %l2 + %l1 ], %o1
a0098178:  92 02 60 0c  add  %o1, 0xc, %o1
a009817c:  40 00 3c 96  call  0xa00a73d4
a0098180:  90 10 20 18  mov  0x18, %o0
a0098184:  d8 04 20 08  ld  [ %l0 + 8 ], %o4
a0098188:  da 03 20 9c  ld  [ %o4 + 0x9c ], %o5
a009818c:  03 3f c0 00  sethi  %hi(0xff000000), %g1
a0098190:  82 2b 40 01  andn  %o5, %g1, %g1
a0098194:  1b 00 80 00  sethi  %hi(0x2000000), %o5
a0098198:  82 10 40 0d  or  %g1, %o5, %g1
a009819c:  d2 04 80 11  ld  [ %l2 + %l1 ], %o1
a00981a0:  c2 23 20 9c  st  %g1, [ %o4 + 0x9c ]
a00981a4:  92 02 60 0c  add  %o1, 0xc, %o1
a00981a8:  40 00 3c 81  call  0xa00a73ac
a00981ac:  90 10 20 17  mov  0x17, %o0
a00981b0:  82 10 20 01  mov  1, %g1
a00981b4:  10 80 00 15  b  0xa0098208
a00981b8:  c2 2e 61 89  stb  %g1, [ %i1 + 0x189 ]
a00981bc:  80 a0 60 00  cmp  %g1, 0
a00981c0:  22 80 00 13  be,a   0xa009820c
a00981c4:  21 2a 01 f6  sethi  %hi(0xa807d800), %l0
a00981c8:  d2 04 80 11  ld  [ %l2 + %l1 ], %o1
a00981cc:  92 02 60 0c  add  %o1, 0xc, %o1
a00981d0:  40 00 3c 81  call  0xa00a73d4
a00981d4:  90 10 20 18  mov  0x18, %o0
a00981d8:  d8 04 20 08  ld  [ %l0 + 8 ], %o4
a00981dc:  da 03 20 9c  ld  [ %o4 + 0x9c ], %o5
a00981e0:  03 3f c0 00  sethi  %hi(0xff000000), %g1
a00981e4:  82 2b 40 01  andn  %o5, %g1, %g1
a00981e8:  1b 00 80 00  sethi  %hi(0x2000000), %o5
a00981ec:  82 10 40 0d  or  %g1, %o5, %g1
a00981f0:  d2 04 80 11  ld  [ %l2 + %l1 ], %o1
a00981f4:  c2 23 20 9c  st  %g1, [ %o4 + 0x9c ]
a00981f8:  92 02 60 0c  add  %o1, 0xc, %o1
a00981fc:  40 00 3c 76  call  0xa00a73d4
a0098200:  90 10 20 17  mov  0x17, %o0
a0098204:  c0 2e 61 89  clrb  [ %i1 + 0x189 ]
a0098208:  21 2a 01 f6  sethi  %hi(0xa807d800), %l0
a009820c:  a2 5e 20 34  smul  %i0, 0x34, %l1
a0098210:  a0 14 23 00  or  %l0, 0x300, %l0
a0098214:  d2 04 00 11  ld  [ %l0 + %l1 ], %o1
a0098218:  92 02 60 84  add  %o1, 0x84, %o1
a009821c:  40 00 3c 64  call  0xa00a73ac
a0098220:  90 10 20 08  mov  8, %o0
a0098224:  f2 04 00 11  ld  [ %l0 + %l1 ], %i1
a0098228:  b2 06 60 84  add  %i1, 0x84, %i1
a009822c:  40 00 3c 6a  call  0xa00a73d4
a0098230:  91 e8 20 08  restore  %g0, 8, %o0
a0098234:  01 00 00 00  nop
a0098238:  81 c7 e0 08  ret
a009823c:  81 e8 00 00  restore
