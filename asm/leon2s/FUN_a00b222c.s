# leon2s FUN_a00b222c 0xa00b222c-0xa00b229c (112 bytes)
a00b222c:  80 a2 20 00  cmp  %o0, 0
a00b2230:  02 80 00 18  be  0xa00b2290
a00b2234:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00b2238:  82 10 63 b8  or  %g1, 0x3b8, %g1	! 0xa80793b8
a00b223c:  96 10 00 01  mov  %g1, %o3
a00b2240:  9a 10 20 00  clr  %o5
a00b2244:  98 00 60 10  add  %g1, 0x10, %o4
a00b2248:  c2 03 00 00  ld  [ %o4 ], %g1
a00b224c:  80 a0 40 08  cmp  %g1, %o0
a00b2250:  82 10 00 0b  mov  %o3, %g1
a00b2254:  98 03 20 18  add  %o4, 0x18, %o4
a00b2258:  02 80 00 06  be  0xa00b2270
a00b225c:  96 02 e0 18  add  %o3, 0x18, %o3
a00b2260:  9a 03 60 01  inc  %o5
a00b2264:  80 a3 60 0f  cmp  %o5, 0xf
a00b2268:  24 bf ff f9  ble,a   0xa00b224c
a00b226c:  c2 03 00 00  ld  [ %o4 ], %g1
a00b2270:  80 a3 60 10  cmp  %o5, 0x10
a00b2274:  32 80 00 07  bne,a   0xa00b2290
a00b2278:  c0 20 60 10  clr  [ %g1 + 0x10 ]
a00b227c:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00b2280:  90 12 22 40  or  %o0, 0x240, %o0	! 0xa006c640
a00b2284:  82 13 c0 00  mov  %o7, %g1
a00b2288:  7f ff 03 6f  call  0xa0073044
a00b228c:  9e 10 40 00  mov  %g1, %o7
a00b2290:  01 00 00 00  nop
a00b2294:  81 c3 e0 08  retl
a00b2298:  01 00 00 00  nop
