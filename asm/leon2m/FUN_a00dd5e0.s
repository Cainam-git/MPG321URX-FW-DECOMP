# leon2m FUN_a00dd5e0 0xa00dd5e0-0xa00dd614 (52 bytes)
a00dd5e0:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00dd5e4:  80 a2 a0 00  cmp  %o2, 0
a00dd5e8:  02 80 00 06  be  0xa00dd600
a00dd5ec:  9a 10 00 0c  mov  %o4, %o5
a00dd5f0:  d4 03 20 b0  ld  [ %o4 + 0xb0 ], %o2
a00dd5f4:  82 12 80 08  or  %o2, %o0, %g1
a00dd5f8:  10 80 00 05  b  0xa00dd60c
a00dd5fc:  c2 23 20 b0  st  %g1, [ %o4 + 0xb0 ]
a00dd600:  c2 03 20 b0  ld  [ %o4 + 0xb0 ], %g1
a00dd604:  98 28 40 08  andn  %g1, %o0, %o4
a00dd608:  d8 23 60 b0  st  %o4, [ %o5 + 0xb0 ]
a00dd60c:  81 c3 e0 08  retl
a00dd610:  01 00 00 00  nop
