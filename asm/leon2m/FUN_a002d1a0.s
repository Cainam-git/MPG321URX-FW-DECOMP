# leon2m FUN_a002d1a0 0xa002d1a0-0xa002d23c (156 bytes)
a002d1a0:  9d e3 bf 98  save  %sp, -104, %sp
a002d1a4:  9e 06 20 01  add  %i0, 1, %o7
a002d1a8:  19 2a 00 97  sethi  %hi(0xa8025c00), %o4
a002d1ac:  17 14 7a e1  sethi  %hi(0x51eb8400), %o3
a002d1b0:  b1 2b e0 10  sll  %o7, 0x10, %i0
a002d1b4:  d2 03 20 74  ld  [ %o4 + 0x74 ], %o1
a002d1b8:  94 12 e1 1f  or  %o3, 0x11f, %o2
a002d1bc:  23 2a 00 ac  sethi  %hi(0xa802b000), %l1
a002d1c0:  b1 36 20 10  srl  %i0, 0x10, %i0
a002d1c4:  80 52 40 0a  umul  %o1, %o2, %g0
a002d1c8:  91 40 00 00  rd  %y, %o0
a002d1cc:  9b 32 20 05  srl  %o0, 5, %o5
a002d1d0:  f0 24 60 c0  st  %i0, [ %l1 + 0xc0 ]
a002d1d4:  21 2a 00 b5  sethi  %hi(0xa802d400), %l0
a002d1d8:  c2 04 60 c0  ld  [ %l1 + 0xc0 ], %g1
a002d1dc:  da 24 22 38  st  %o5, [ %l0 + 0x238 ]
a002d1e0:  80 a0 60 00  cmp  %g1, 0
a002d1e4:  02 80 00 14  be  0xa002d234
a002d1e8:  9a 10 00 11  mov  %l1, %o5
a002d1ec:  25 00 06 63  sethi  %hi(0x198c00), %l2
a002d1f0:  d0 04 22 38  ld  [ %l0 + 0x238 ], %o0
a002d1f4:  82 02 3f ff  add  %o0, -1, %g1
a002d1f8:  80 a0 60 00  cmp  %g1, 0
a002d1fc:  12 80 00 06  bne  0xa002d214
a002d200:  c2 24 22 38  st  %g1, [ %l0 + 0x238 ]
a002d204:  d2 03 60 c0  ld  [ %o5 + 0xc0 ], %o1
a002d208:  80 a6 00 09  cmp  %i0, %o1
a002d20c:  02 80 00 07  be  0xa002d228
a002d210:  90 14 a3 68  or  %l2, 0x368, %o0
a002d214:  da 04 60 c0  ld  [ %l1 + 0xc0 ], %o5
a002d218:  80 a3 60 00  cmp  %o5, 0
a002d21c:  12 bf ff f5  bne  0xa002d1f0
a002d220:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a002d224:  30 80 00 04  b,a   0xa002d234
a002d228:  58 01 47 d2  call  0x7f170
a002d22c:  01 00 00 00  nop
a002d230:  30 bf ff f9  b,a   0xa002d214
a002d234:  81 c7 e0 08  ret
a002d238:  81 e8 00 00  restore
