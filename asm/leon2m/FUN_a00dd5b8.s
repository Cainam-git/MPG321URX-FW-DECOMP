# leon2m FUN_a00dd5b8 0xa00dd5b8-0xa00dd614 (92 bytes)
a00dd5b8:  9d e3 bf 98  save  %sp, -104, %sp
a00dd5bc:  11 00 06 62  sethi  %hi(0x198800), %o0
a00dd5c0:  92 10 00 18  mov  %i0, %o1
a00dd5c4:  94 10 00 19  mov  %i1, %o2
a00dd5c8:  96 10 00 1a  mov  %i2, %o3
a00dd5cc:  40 00 06 e9  call  0xa00df170
a00dd5d0:  90 12 23 f8  or  %o0, 0x3f8, %o0
a00dd5d4:  40 01 6e 79  call  0xa0138fb8
a00dd5d8:  81 e8 00 00  restore
a00dd5dc:  01 00 00 00  nop
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
