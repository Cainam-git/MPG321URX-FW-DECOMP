# leon2m FUN_a013d018 0xa013d018-0xa013d0ec (212 bytes)
a013d018:  9d e3 bf 98  save  %sp, -104, %sp
a013d01c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a013d020:  91 2e 20 04  sll  %i0, 4, %o0
a013d024:  13 2a 00 b7  sethi  %hi(0xa802dc00), %o1
a013d028:  82 22 00 18  sub  %o0, %i0, %g1
a013d02c:  a2 12 63 30  or  %o1, 0x330, %l1
a013d030:  a1 28 60 03  sll  %g1, 3, %l0
a013d034:  80 a6 20 03  cmp  %i0, 3
a013d038:  b2 0e 60 ff  and  %i1, 0xff, %i1
a013d03c:  18 80 00 2a  bgu  0xa013d0e4
a013d040:  b4 0e a0 ff  and  %i2, 0xff, %i2
a013d044:  b0 0e 60 0f  and  %i1, 0xf, %i0
a013d048:  d0 04 40 10  ld  [ %l1 + %l0 ], %o0
a013d04c:  97 2e 20 0c  sll  %i0, 0xc, %o3
a013d050:  1f 00 00 3c  sethi  %hi(0xf000), %o7
a013d054:  83 32 20 0c  srl  %o0, 0xc, %g1
a013d058:  9a 2a 00 0f  andn  %o0, %o7, %o5
a013d05c:  b0 08 60 0f  and  %g1, 0xf, %i0
a013d060:  9e 1e 40 18  xor  %i1, %i0, %o7
a013d064:  80 a0 00 0f  cmp  %g0, %o7
a013d068:  96 13 40 0b  or  %o5, %o3, %o3
a013d06c:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a013d070:  9a 40 20 00  addx  %g0, 0, %o5
a013d074:  92 13 22 24  or  %o4, 0x224, %o1
a013d078:  80 a0 00 1a  cmp  %g0, %i2
a013d07c:  94 5e 60 2a  smul  %i1, 0x2a, %o2
a013d080:  98 40 20 00  addx  %g0, 0, %o4
a013d084:  80 93 40 0c  orcc  %o5, %o4, %g0
a013d088:  02 80 00 17  be  0xa013d0e4
a013d08c:  94 02 80 09  add  %o2, %o1, %o2
a013d090:  d6 24 40 10  st  %o3, [ %l1 + %l0 ]
a013d094:  40 00 14 76  call  0xa014226c
a013d098:  d0 0a a0 0a  ldub  [ %o2 + 0xa ], %o0
a013d09c:  d4 04 40 10  ld  [ %l1 + %l0 ], %o2
a013d0a0:  90 0a 20 0f  and  %o0, 0xf, %o0
a013d0a4:  b5 2a 20 08  sll  %o0, 8, %i2
a013d0a8:  82 0a b0 ff  and  %o2, -3841, %g1
a013d0ac:  9a 10 40 1a  or  %g1, %i2, %o5
a013d0b0:  b3 33 60 1c  srl  %o5, 0x1c, %i1
a013d0b4:  98 04 00 11  add  %l0, %l1, %o4
a013d0b8:  80 a6 60 05  cmp  %i1, 5
a013d0bc:  08 80 00 0a  bleu  0xa013d0e4
a013d0c0:  da 24 40 10  st  %o5, [ %l1 + %l0 ]
a013d0c4:  1f 3c 00 00  sethi  %hi(0xf0000000), %o7
a013d0c8:  96 2b 40 0f  andn  %o5, %o7, %o3
a013d0cc:  1b 14 00 00  sethi  %hi(0x50000000), %o5
a013d0d0:  d2 0b 20 70  ldub  [ %o4 + 0x70 ], %o1
a013d0d4:  80 8a 60 01  btst  1, %o1
a013d0d8:  02 80 00 03  be  0xa013d0e4
a013d0dc:  82 12 c0 0d  or  %o3, %o5, %g1
a013d0e0:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a013d0e4:  81 c7 e0 08  ret
a013d0e8:  81 e8 00 00  restore
