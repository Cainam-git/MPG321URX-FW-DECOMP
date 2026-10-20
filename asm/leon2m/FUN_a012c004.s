# leon2m FUN_a012c004 0xa012c004-0xa012c088 (132 bytes)
a012c004:  9d e3 bf 90  save  %sp, -112, %sp
a012c008:  a2 0e 20 ff  and  %i0, 0xff, %l1
a012c00c:  a1 2c 60 03  sll  %l1, 3, %l0
a012c010:  94 04 00 11  add  %l0, %l1, %o2
a012c014:  17 2a 00 b6  sethi  %hi(0xa802d800), %o3
a012c018:  a2 12 e0 dc  or  %o3, 0xdc, %l1	! 0xa802d8dc
a012c01c:  a1 2a a0 02  sll  %o2, 2, %l0
a012c020:  d0 04 40 10  ld  [ %l1 + %l0 ], %o0
a012c024:  83 32 20 1f  srl  %o0, 0x1f, %g1
a012c028:  13 20 00 00  sethi  %hi(0x80000000), %o1
a012c02c:  98 0e 60 01  and  %i1, 1, %o4
a012c030:  9a 2a 00 09  andn  %o0, %o1, %o5
a012c034:  9f 2e 60 1f  sll  %i1, 0x1f, %o7
a012c038:  80 a0 40 0c  cmp  %g1, %o4
a012c03c:  90 10 20 55  mov  0x55, %o0
a012c040:  92 10 20 04  mov  4, %o1
a012c044:  94 07 bf f0  add  %fp, -16, %o2
a012c048:  96 10 20 00  clr  %o3
a012c04c:  9a 13 40 0f  or  %o5, %o7, %o5
a012c050:  c0 27 bf f0  clr  [ %fp + -16 ]
a012c054:  02 80 00 04  be  0xa012c064
a012c058:  82 10 20 00  clr  %g1
a012c05c:  da 24 40 10  st  %o5, [ %l1 + %l0 ]
a012c060:  82 10 20 01  mov  1, %g1
a012c064:  80 88 60 ff  btst  0xff, %g1
a012c068:  02 80 00 05  be  0xa012c07c
a012c06c:  01 00 00 00  nop
a012c070:  f0 2f bf f0  stb  %i0, [ %fp + -16 ]
a012c074:  40 00 2c 1a  call  0xa01370dc
a012c078:  f2 2f bf f1  stb  %i1, [ %fp + -15 ]
a012c07c:  01 00 00 00  nop
a012c080:  81 c7 e0 08  ret
a012c084:  81 e8 00 00  restore
