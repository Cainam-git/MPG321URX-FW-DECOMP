# leon2m FUN_a015e008 0xa015e008-0xa015e05c (84 bytes)
a015e008:  9d e3 bf 98  save  %sp, -104, %sp
a015e00c:  03 2a 00 aa  sethi  %hi(0xa802a800), %g1
a015e010:  d0 00 62 18  ld  [ %g1 + 0x218 ], %o0	! 0xa802aa18
a015e014:  94 10 00 19  mov  %i1, %o2
a015e018:  96 10 00 1a  mov  %i2, %o3
a015e01c:  40 00 01 0a  call  0xa015e444
a015e020:  d2 56 20 0e  ldsh  [ %i0 + 0xe ], %o1
a015e024:  80 a2 3f ff  cmp  %o0, -1
a015e028:  02 80 00 07  be  0xa015e044
a015e02c:  1b 00 00 04  sethi  %hi(0x1000), %o5
a015e030:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a015e034:  82 10 40 0d  or  %g1, %o5, %g1
a015e038:  c2 36 20 0c  sth  %g1, [ %i0 + 0xc ]
a015e03c:  10 80 00 06  b  0xa015e054
a015e040:  d0 26 20 50  st  %o0, [ %i0 + 0x50 ]
a015e044:  da 16 20 0c  lduh  [ %i0 + 0xc ], %o5
a015e048:  03 00 00 04  sethi  %hi(0x1000), %g1
a015e04c:  82 2b 40 01  andn  %o5, %g1, %g1
a015e050:  c2 36 20 0c  sth  %g1, [ %i0 + 0xc ]
a015e054:  81 c7 e0 08  ret
a015e058:  91 e8 00 08  restore  %g0, %o0, %o0
