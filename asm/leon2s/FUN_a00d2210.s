# leon2s FUN_a00d2210 0xa00d2210-0xa00d2288 (120 bytes)
a00d2210:  9d e3 bf 90  save  %sp, -112, %sp
a00d2214:  21 34 00 4f  sethi  %hi(0xd0013c00), %l0
a00d2218:  90 14 23 d0  or  %l0, 0x3d0, %o0	! 0xd0013fd0
a00d221c:  80 8e 20 ff  btst  0xff, %i0
a00d2220:  c0 27 bf f4  clr  [ %fp + -12 ]
a00d2224:  12 80 00 0c  bne  0xa00d2254
a00d2228:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00d222c:  40 3a 7c bf  call  0xa0f71528
a00d2230:  01 00 00 00  nop
a00d2234:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a00d2238:  90 07 bf f4  add  %fp, -12, %o0
a00d223c:  96 10 00 19  mov  %i1, %o3
a00d2240:  92 10 20 1f  mov  0x1f, %o1
a00d2244:  40 3a 7c 9d  call  0xa0f714b8
a00d2248:  94 10 20 1f  mov  0x1f, %o2
a00d224c:  10 80 00 0b  b  0xa00d2278
a00d2250:  90 14 23 d0  or  %l0, 0x3d0, %o0
a00d2254:  40 3a 7c b5  call  0xa0f71528
a00d2258:  90 14 23 d0  or  %l0, 0x3d0, %o0
a00d225c:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a00d2260:  90 07 bf f4  add  %fp, -12, %o0
a00d2264:  96 10 00 19  mov  %i1, %o3
a00d2268:  92 10 20 1e  mov  0x1e, %o1
a00d226c:  40 3a 7c 93  call  0xa0f714b8
a00d2270:  94 10 20 1e  mov  0x1e, %o2
a00d2274:  90 14 23 d0  or  %l0, 0x3d0, %o0
a00d2278:  40 3a 7c af  call  0xa0f71534
a00d227c:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d2280:  81 c7 e0 08  ret
a00d2284:  91 e8 20 01  restore  %g0, 1, %o0
