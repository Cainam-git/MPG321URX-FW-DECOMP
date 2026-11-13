# leon2m FUN_a012f2dc 0xa012f2dc-0xa012f31c (64 bytes)
a012f2dc:  98 0a 20 ff  and  %o0, 0xff, %o4
a012f2e0:  03 00 06 94  sethi  %hi(0x1a5000), %g1
a012f2e4:  96 10 62 38  or  %g1, 0x238, %o3	! 0x1a5238
a012f2e8:  9a 10 20 00  clr  %o5
a012f2ec:  90 10 20 00  clr  %o0
a012f2f0:  c2 0a c0 08  ldub  [ %o3 + %o0 ], %g1
a012f2f4:  80 a3 00 01  cmp  %o4, %g1
a012f2f8:  02 80 00 07  be  0xa012f314
a012f2fc:  9a 03 60 01  inc  %o5
a012f300:  90 0b 60 ff  and  %o5, 0xff, %o0
a012f304:  80 a2 20 03  cmp  %o0, 3
a012f308:  28 bf ff fb  bleu,a   0xa012f2f4
a012f30c:  c2 0a c0 08  ldub  [ %o3 + %o0 ], %g1
a012f310:  90 10 20 ff  mov  0xff, %o0
a012f314:  81 c3 e0 08  retl
a012f318:  01 00 00 00  nop
