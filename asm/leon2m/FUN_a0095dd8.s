# leon2m FUN_a0095dd8 0xa0095dd8-0xa0095e54 (124 bytes)
a0095dd8:  9d e3 bf 98  save  %sp, -104, %sp
a0095ddc:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a0095de0:  a0 13 22 90  or  %o4, 0x290, %l0	! 0xa802d290
a0095de4:  c2 04 21 f4  ld  [ %l0 + 0x1f4 ], %g1
a0095de8:  91 30 60 1f  srl  %g1, 0x1f, %o0
a0095dec:  9e 38 00 08  xnor  %g0, %o0, %o7
a0095df0:  31 20 00 00  sethi  %hi(0x80000000), %i0
a0095df4:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a0095df8:  94 28 40 18  andn  %g1, %i0, %o2
a0095dfc:  d2 02 e3 ec  ld  [ %o3 + 0x3ec ], %o1
a0095e00:  9b 2b e0 1f  sll  %o7, 0x1f, %o5
a0095e04:  98 12 80 0d  or  %o2, %o5, %o4
a0095e08:  90 02 7f f2  add  %o1, -14, %o0
a0095e0c:  d8 24 21 f4  st  %o4, [ %l0 + 0x1f4 ]
a0095e10:  90 0a 20 ff  and  %o0, 0xff, %o0
a0095e14:  40 00 50 b5  call  0xa00aa0e8
a0095e18:  92 10 20 01  mov  1, %o1
a0095e1c:  c2 0c 21 a4  ldub  [ %l0 + 0x1a4 ], %g1
a0095e20:  80 a0 60 03  cmp  %g1, 3
a0095e24:  02 80 00 04  be  0xa0095e34
a0095e28:  b0 10 20 02  mov  2, %i0
a0095e2c:  40 01 10 6c  call  0xa00d9fdc
a0095e30:  81 e8 00 00  restore
a0095e34:  d2 04 21 f4  ld  [ %l0 + 0x1f4 ], %o1
a0095e38:  80 a2 60 00  cmp  %o1, 0
a0095e3c:  16 bf ff fc  bge  0xa0095e2c
a0095e40:  01 00 00 00  nop
a0095e44:  c0 2c 21 a4  clrb  [ %l0 + 0x1a4 ]
a0095e48:  40 01 10 65  call  0xa00d9fdc
a0095e4c:  81 e8 00 00  restore
a0095e50:  01 00 00 00  nop
