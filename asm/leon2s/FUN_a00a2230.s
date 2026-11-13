# leon2s FUN_a00a2230 0xa00a2230-0xa00a22d4 (164 bytes)
a00a2230:  9d e3 bf 98  save  %sp, -104, %sp
a00a2234:  80 8e 20 ff  btst  0xff, %i0
a00a2238:  b0 0e 60 ff  and  %i1, 0xff, %i0
a00a223c:  27 2a 01 e4  sethi  %hi(0xa8079000), %l3
a00a2240:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a2244:  a5 2e 20 02  sll  %i0, 2, %l2
a00a2248:  9a 14 e1 a0  or  %l3, 0x1a0, %o5
a00a224c:  02 80 00 06  be  0xa00a2264
a00a2250:  a8 10 61 94  or  %g1, 0x194, %l4
a00a2254:  40 00 3f 84  call  0xa00b2064
a00a2258:  c0 2b 40 18  clrb  [ %o5 + %i0 ]
a00a225c:  10 80 00 18  b  0xa00a22bc
a00a2260:  d0 25 00 12  st  %o0, [ %l4 + %l2 ]
a00a2264:  40 00 3f 80  call  0xa00b2064
a00a2268:  01 00 00 00  nop
a00a226c:  c2 05 00 12  ld  [ %l4 + %l2 ], %g1
a00a2270:  90 22 00 01  sub  %o0, %g1, %o0
a00a2274:  80 a2 20 28  cmp  %o0, 0x28
a00a2278:  08 80 00 12  bleu  0xa00a22c0
a00a227c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a2280:  40 00 3f 79  call  0xa00b2064
a00a2284:  01 00 00 00  nop
a00a2288:  d0 25 00 12  st  %o0, [ %l4 + %l2 ]
a00a228c:  7f ff ff a4  call  0xa00a211c
a00a2290:  90 10 00 18  mov  %i0, %o0
a00a2294:  90 02 3e d3  add  %o0, -301, %o0
a00a2298:  91 2a 20 10  sll  %o0, 0x10, %o0
a00a229c:  91 32 20 10  srl  %o0, 0x10, %o0
a00a22a0:  80 a2 26 5c  cmp  %o0, 0x65c
a00a22a4:  18 80 00 05  bgu  0xa00a22b8
a00a22a8:  9a 14 e1 a0  or  %l3, 0x1a0, %o5
a00a22ac:  82 10 20 01  mov  1, %g1
a00a22b0:  10 80 00 03  b  0xa00a22bc
a00a22b4:  c2 2b 40 18  stb  %g1, [ %o5 + %i0 ]
a00a22b8:  c0 2b 40 18  clrb  [ %o5 + %i0 ]
a00a22bc:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a22c0:  9a 0e 60 ff  and  %i1, 0xff, %o5
a00a22c4:  82 10 61 a0  or  %g1, 0x1a0, %g1
a00a22c8:  f0 08 40 0d  ldub  [ %g1 + %o5 ], %i0
a00a22cc:  81 c7 e0 08  ret
a00a22d0:  81 e8 00 00  restore
