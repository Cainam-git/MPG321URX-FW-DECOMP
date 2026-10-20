# leon2m FUN_a0125230 0xa0125230-0xa0125264 (52 bytes)
a0125230:  1b 2a 00 b6  sethi  %hi(0xa802d800), %o5
a0125234:  90 0a 20 ff  and  %o0, 0xff, %o0
a0125238:  82 13 60 80  or  %o5, 0x80, %g1
a012523c:  da 08 40 08  ldub  [ %g1 + %o0 ], %o5
a0125240:  80 a3 60 ff  cmp  %o5, 0xff
a0125244:  9a 5b 60 16  smul  %o5, 0x16, %o5
a0125248:  02 80 00 05  be  0xa012525c
a012524c:  90 10 20 ff  mov  0xff, %o0
a0125250:  11 00 06 90  sethi  %hi(0x1a4000), %o0
a0125254:  82 12 22 a8  or  %o0, 0x2a8, %g1	! 0x1a42a8
a0125258:  d0 08 40 0d  ldub  [ %g1 + %o5 ], %o0
a012525c:  81 c3 e0 08  retl
a0125260:  90 0a 20 ff  and  %o0, 0xff, %o0
