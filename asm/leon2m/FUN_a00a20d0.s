# leon2m FUN_a00a20d0 0xa00a20d0-0xa00a2264 (296 bytes)
a00a20d0:  9d e3 bf 98  save  %sp, -104, %sp
a00a20d4:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a00a20d8:  c2 0c 20 56  ldub  [ %l0 + 0x56 ], %g1	! 0xa8025c56
a00a20dc:  80 a0 60 02  cmp  %g1, 2
a00a20e0:  02 80 00 54  be  0xa00a2230
a00a20e4:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a00a20e8:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0	! 0xa802afec
a00a20ec:  82 02 3f 40  add  %o0, -192, %g1
a00a20f0:  80 a0 60 39  cmp  %g1, 0x39
a00a20f4:  08 80 00 18  bleu  0xa00a2154
a00a20f8:  92 10 20 00  clr  %o1
a00a20fc:  92 10 20 00  clr  %o1
a00a2100:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00a2104:  94 10 20 00  clr  %o2
a00a2108:  40 00 18 0d  call  0xa00a813c
a00a210c:  90 10 20 01  mov  1, %o0
a00a2110:  98 14 a2 90  or  %l2, 0x290, %o4
a00a2114:  e4 0c 20 56  ldub  [ %l0 + 0x56 ], %l2
a00a2118:  e4 2b 21 e8  stb  %l2, [ %o4 + 0x1e8 ]
a00a211c:  40 00 1c a8  call  0xa00a93bc
a00a2120:  90 0c a0 ff  and  %l2, 0xff, %o0
a00a2124:  d2 04 63 ec  ld  [ %l1 + 0x3ec ], %o1
a00a2128:  82 02 7f 40  add  %o1, -192, %g1
a00a212c:  80 a0 60 39  cmp  %g1, 0x39
a00a2130:  94 14 63 ec  or  %l1, 0x3ec, %o2
a00a2134:  18 80 00 0e  bgu  0xa00a216c
a00a2138:  96 10 20 00  clr  %o3
a00a213c:  11 00 00 c2  sethi  %hi(0x30800), %o0
a00a2140:  83 28 60 02  sll  %g1, 2, %g1
a00a2144:  9a 12 22 a8  or  %o0, 0x2a8, %o5
a00a2148:  de 03 40 01  ld  [ %o5 + %g1 ], %o7
a00a214c:  81 c3 c0 00  jmp  %o7
a00a2150:  01 00 00 00  nop
a00a2154:  17 00 00 c2  sethi  %hi(0x30800), %o3
a00a2158:  95 28 60 02  sll  %g1, 2, %o2
a00a215c:  9a 12 e1 c0  or  %o3, 0x1c0, %o5
a00a2160:  d8 03 40 0a  ld  [ %o5 + %o2 ], %o4
a00a2164:  81 c3 00 00  jmp  %o4
a00a2168:  01 00 00 00  nop
a00a216c:  82 10 20 00  clr  %g1	! 0x0
a00a2170:  96 00 60 34  add  %g1, 0x34, %o3
a00a2174:  d6 22 80 00  st  %o3, [ %o2 ]
a00a2178:  d0 0c 20 56  ldub  [ %l0 + 0x56 ], %o0
a00a217c:  40 00 1d 35  call  0xa00a9650
a00a2180:  92 10 20 00  clr  %o1
a00a2184:  d2 0c 20 56  ldub  [ %l0 + 0x56 ], %o1
a00a2188:  94 10 20 01  mov  1, %o2
a00a218c:  40 00 17 ec  call  0xa00a813c
a00a2190:  90 10 20 01  mov  1, %o0
a00a2194:  d4 04 63 ec  ld  [ %l1 + 0x3ec ], %o2
a00a2198:  a0 02 bf cc  add  %o2, -52, %l0
a00a219c:  90 0c 20 ff  and  %l0, 0xff, %o0
a00a21a0:  40 00 1b 9b  call  0xa00a900c
a00a21a4:  92 10 20 01  mov  1, %o1
a00a21a8:  90 10 20 01  mov  1, %o0
a00a21ac:  40 00 1c af  call  0xa00a9468
a00a21b0:  92 10 20 02  mov  2, %o1
a00a21b4:  90 10 20 00  clr  %o0
a00a21b8:  40 00 44 c7  call  0xa00b34d4
a00a21bc:  92 10 20 01  mov  1, %o1
a00a21c0:  30 80 00 21  b,a   0xa00a2244
a00a21c4:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00a21c8:  10 bf ff cf  b  0xa00a2104
a00a21cc:  92 0a 60 ff  and  %o1, 0xff, %o1
a00a21d0:  96 10 20 06  mov  6, %o3
a00a21d4:  10 bf ff e7  b  0xa00a2170
a00a21d8:  82 0a e0 ff  and  %o3, 0xff, %g1
a00a21dc:  96 10 20 05  mov  5, %o3
a00a21e0:  10 bf ff e4  b  0xa00a2170
a00a21e4:  82 0a e0 ff  and  %o3, 0xff, %g1
a00a21e8:  96 10 20 04  mov  4, %o3
a00a21ec:  10 bf ff e1  b  0xa00a2170
a00a21f0:  82 0a e0 ff  and  %o3, 0xff, %g1
a00a21f4:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00a21f8:  9e 14 a2 90  or  %l2, 0x290, %o7	! 0xa802d290
a00a21fc:  d2 0b e1 e8  ldub  [ %o7 + 0x1e8 ], %o1
a00a2200:  10 bf ff c1  b  0xa00a2104
a00a2204:  92 0a 60 ff  and  %o1, 0xff, %o1
a00a2208:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00a220c:  90 14 a2 90  or  %l2, 0x290, %o0	! 0xa802d290
a00a2210:  d2 0a 21 ec  ldub  [ %o0 + 0x1ec ], %o1
a00a2214:  10 bf ff bc  b  0xa00a2104
a00a2218:  92 0a 60 ff  and  %o1, 0xff, %o1
a00a221c:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00a2220:  82 14 a2 90  or  %l2, 0x290, %g1	! 0xa802d290
a00a2224:  d2 08 61 ea  ldub  [ %g1 + 0x1ea ], %o1
a00a2228:  10 bf ff b7  b  0xa00a2104
a00a222c:  92 0a 60 ff  and  %o1, 0xff, %o1
a00a2230:  25 2a 00 b5  sethi  %hi(0xa802d400), %l2
a00a2234:  d2 0c a0 79  ldub  [ %l2 + 0x79 ], %o1	! 0xa802d479
a00a2238:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a00a223c:  7f ff fe 0b  call  0xa00a1a68
a00a2240:  d2 2c 60 55  stb  %o1, [ %l1 + 0x55 ]	! 0xa8025c55
a00a2244:  40 00 e2 6f  call  0xa00dac00
a00a2248:  01 00 00 00  nop
a00a224c:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00a2250:  c2 0b 20 8e  ldub  [ %o4 + 0x8e ], %g1	! 0xa802b08e
a00a2254:  9e 10 60 02  or  %g1, 2, %o7
a00a2258:  de 2b 20 8e  stb  %o7, [ %o4 + 0x8e ]
a00a225c:  81 c7 e0 08  ret
a00a2260:  81 e8 00 00  restore
