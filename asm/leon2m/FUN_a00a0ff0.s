# leon2m FUN_a00a0ff0 0xa00a0ff0-0xa00a105c (108 bytes)
a00a0ff0:  9d e3 bf 98  save  %sp, -104, %sp
a00a0ff4:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a00a0ff8:  98 14 23 f4  or  %l0, 0x3f4, %o4	! 0xa802cff4
a00a0ffc:  c2 13 20 36  lduh  [ %o4 + 0x36 ], %g1
a00a1000:  80 a0 63 c0  cmp  %g1, 0x3c0
a00a1004:  08 80 00 13  bleu  0xa00a1050
a00a1008:  9a 00 7f f8  add  %g1, -8, %o5
a00a100c:  da 33 20 36  sth  %o5, [ %o4 + 0x36 ]
a00a1010:  a0 14 23 f4  or  %l0, 0x3f4, %l0
a00a1014:  d4 14 20 36  lduh  [ %l0 + 0x36 ], %o2
a00a1018:  92 02 a0 04  add  %o2, 4, %o1
a00a101c:  97 2a 60 10  sll  %o1, 0x10, %o3
a00a1020:  97 32 e0 10  srl  %o3, 0x10, %o3
a00a1024:  90 10 20 06  mov  6, %o0
a00a1028:  d2 14 20 36  lduh  [ %l0 + 0x36 ], %o1
a00a102c:  94 10 20 00  clr  %o2
a00a1030:  d8 14 20 38  lduh  [ %l0 + 0x38 ], %o4
a00a1034:  40 02 96 0f  call  0xa0146870
a00a1038:  9a 10 20 00  clr  %o5
a00a103c:  31 00 04 20  sethi  %hi(0x108000), %i0
a00a1040:  f4 14 20 38  lduh  [ %l0 + 0x38 ], %i2
a00a1044:  f2 14 20 36  lduh  [ %l0 + 0x36 ], %i1
a00a1048:  40 00 f8 4a  call  0xa00df170
a00a104c:  91 ee 21 80  restore  %i0, 0x180, %o0
a00a1050:  90 10 23 c0  mov  0x3c0, %o0
a00a1054:  10 bf ff ef  b  0xa00a1010
a00a1058:  d0 33 20 36  sth  %o0, [ %o4 + 0x36 ]
