# leon2m FUN_a011a9e4 0xa011a9e4-0xa011abcc (488 bytes)
a011a9e4:  9d e3 bf 98  save  %sp, -104, %sp
a011a9e8:  98 0f 60 ff  and  %i5, 0xff, %o4
a011a9ec:  96 10 00 1d  mov  %i5, %o3
a011a9f0:  80 a3 20 02  cmp  %o4, 2
a011a9f4:  ba 60 20 00  subx  %g0, 0, %i5
a011a9f8:  82 0a c0 1d  and  %o3, %i5, %g1
a011a9fc:  3b 2a 00 9e  sethi  %hi(0xa8027800), %i5
a011aa00:  82 08 60 ff  and  %g1, 0xff, %g1
a011aa04:  94 17 62 a8  or  %i5, 0x2a8, %o2
a011aa08:  82 00 40 01  add  %g1, %g1, %g1
a011aa0c:  fa 12 80 01  lduh  [ %o2 + %g1 ], %i5
a011aa10:  9a 03 00 0c  add  %o4, %o4, %o5
a011aa14:  82 07 60 30  add  %i5, 0x30, %g1
a011aa18:  de 12 80 0d  lduh  [ %o2 + %o5 ], %o7
a011aa1c:  bb 28 60 02  sll  %g1, 2, %i5
a011aa20:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a011aa24:  82 03 e0 30  add  %o7, 0x30, %g1
a011aa28:  ba 17 40 0d  or  %i5, %o5, %i5
a011aa2c:  9f 28 60 02  sll  %g1, 2, %o7
a011aa30:  c0 27 40 00  clr  [ %i5 ]
a011aa34:  9e 13 c0 0d  or  %o7, %o5, %o7
a011aa38:  c2 03 c0 00  ld  [ %o7 ], %g1
a011aa3c:  ba 10 60 2f  or  %g1, 0x2f, %i5
a011aa40:  82 0f 60 ff  and  %i5, 0xff, %g1
a011aa44:  c2 23 c0 00  st  %g1, [ %o7 ]
a011aa48:  ba 0e 60 01  and  %i1, 1, %i5
a011aa4c:  c2 03 c0 00  ld  [ %o7 ], %g1
a011aa50:  b3 2f 60 04  sll  %i5, 4, %i1
a011aa54:  ba 10 40 19  or  %g1, %i1, %i5
a011aa58:  82 0f 60 ff  and  %i5, 0xff, %g1
a011aa5c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a011aa60:  c2 23 c0 00  st  %g1, [ %o7 ]
a011aa64:  b2 10 00 1c  mov  %i4, %i1
a011aa68:  80 a6 20 00  cmp  %i0, 0
a011aa6c:  9e 10 00 0a  mov  %o2, %o7
a011aa70:  12 80 00 1d  bne  0xa011aae4
a011aa74:  92 10 00 0d  mov  %o5, %o1
a011aa78:  80 a3 20 02  cmp  %o4, 2
a011aa7c:  b8 60 20 00  subx  %g0, 0, %i4
a011aa80:  b0 0a c0 1c  and  %o3, %i4, %i0
a011aa84:  ba 0e 20 ff  and  %i0, 0xff, %i5
a011aa88:  82 07 40 1d  add  %i5, %i5, %g1
a011aa8c:  f8 12 80 01  lduh  [ %o2 + %g1 ], %i4
a011aa90:  b0 0e a0 01  and  %i2, 1, %i0
a011aa94:  82 0e 60 1f  and  %i1, 0x1f, %g1
a011aa98:  ba 07 20 31  add  %i4, 0x31, %i5
a011aa9c:  b9 2e 20 07  sll  %i0, 7, %i4
a011aaa0:  b3 2f 60 02  sll  %i5, 2, %i1
a011aaa4:  b4 10 40 1c  or  %g1, %i4, %i2
a011aaa8:  b0 16 40 0d  or  %i1, %o5, %i0
a011aaac:  f4 26 00 00  st  %i2, [ %i0 ]
a011aab0:  80 a3 20 01  cmp  %o4, 1
a011aab4:  08 80 00 03  bleu  0xa011aac0
a011aab8:  82 10 00 0b  mov  %o3, %g1
a011aabc:  82 10 20 00  clr  %g1
a011aac0:  82 08 60 ff  and  %g1, 0xff, %g1
a011aac4:  b2 00 40 01  add  %g1, %g1, %i1
a011aac8:  f4 13 c0 19  lduh  [ %o7 + %i1 ], %i2
a011aacc:  ba 06 a0 34  add  %i2, 0x34, %i5
a011aad0:  bb 2f 60 02  sll  %i5, 2, %i5
a011aad4:  ba 17 40 09  or  %i5, %o1, %i5
a011aad8:  b8 0e e0 ff  and  %i3, 0xff, %i4
a011aadc:  f8 27 40 00  st  %i4, [ %i5 ]
a011aae0:  30 80 00 39  b,a   0xa011abc4
a011aae4:  80 a6 20 01  cmp  %i0, 1
a011aae8:  02 80 00 06  be  0xa011ab00
a011aaec:  80 a6 20 02  cmp  %i0, 2
a011aaf0:  12 80 00 35  bne  0xa011abc4
a011aaf4:  80 a3 20 02  cmp  %o4, 2
a011aaf8:  10 80 00 1b  b  0xa011ab64
a011aafc:  b8 60 20 00  subx  %g0, 0, %i4
a011ab00:  80 a3 20 02  cmp  %o4, 2
a011ab04:  b8 60 20 00  subx  %g0, 0, %i4
a011ab08:  b0 0a c0 1c  and  %o3, %i4, %i0
a011ab0c:  ba 0e 20 ff  and  %i0, 0xff, %i5
a011ab10:  82 07 40 1d  add  %i5, %i5, %g1
a011ab14:  f8 12 80 01  lduh  [ %o2 + %g1 ], %i4
a011ab18:  b0 0e a0 01  and  %i2, 1, %i0
a011ab1c:  ba 07 20 32  add  %i4, 0x32, %i5
a011ab20:  82 0e 60 1f  and  %i1, 0x1f, %g1
a011ab24:  b9 2e 20 07  sll  %i0, 7, %i4
a011ab28:  b5 2f 60 02  sll  %i5, 2, %i2
a011ab2c:  b0 10 40 1c  or  %g1, %i4, %i0
a011ab30:  ba 16 80 0d  or  %i2, %o5, %i5
a011ab34:  f0 27 40 00  st  %i0, [ %i5 ]
a011ab38:  80 a3 20 01  cmp  %o4, 1
a011ab3c:  08 80 00 03  bleu  0xa011ab48
a011ab40:  82 10 00 0b  mov  %o3, %g1
a011ab44:  82 10 20 00  clr  %g1
a011ab48:  82 08 60 ff  and  %g1, 0xff, %g1
a011ab4c:  b4 00 40 01  add  %g1, %g1, %i2
a011ab50:  f2 13 c0 1a  lduh  [ %o7 + %i2 ], %i1
a011ab54:  ba 06 60 35  add  %i1, 0x35, %i5
a011ab58:  bb 2f 60 02  sll  %i5, 2, %i5
a011ab5c:  10 bf ff df  b  0xa011aad8
a011ab60:  ba 17 40 09  or  %i5, %o1, %i5
a011ab64:  b0 0a c0 1c  and  %o3, %i4, %i0
a011ab68:  ba 0e 20 ff  and  %i0, 0xff, %i5
a011ab6c:  82 07 40 1d  add  %i5, %i5, %g1
a011ab70:  f8 12 80 01  lduh  [ %o2 + %g1 ], %i4
a011ab74:  b0 0e a0 01  and  %i2, 1, %i0
a011ab78:  ba 07 20 33  add  %i4, 0x33, %i5
a011ab7c:  b9 2e 20 07  sll  %i0, 7, %i4
a011ab80:  83 2f 60 02  sll  %i5, 2, %g1
a011ab84:  b4 0e 60 1f  and  %i1, 0x1f, %i2
a011ab88:  b0 10 40 0d  or  %g1, %o5, %i0
a011ab8c:  b2 16 80 1c  or  %i2, %i4, %i1
a011ab90:  f2 26 00 00  st  %i1, [ %i0 ]
a011ab94:  80 a3 20 01  cmp  %o4, 1
a011ab98:  08 80 00 03  bleu  0xa011aba4
a011ab9c:  82 10 00 0b  mov  %o3, %g1
a011aba0:  82 10 20 00  clr  %g1
a011aba4:  b0 08 60 ff  and  %g1, 0xff, %i0
a011aba8:  82 06 00 18  add  %i0, %i0, %g1
a011abac:  fa 12 80 01  lduh  [ %o2 + %g1 ], %i5
a011abb0:  b4 07 60 36  add  %i5, 0x36, %i2
a011abb4:  b3 2e a0 02  sll  %i2, 2, %i1
a011abb8:  ba 16 40 0d  or  %i1, %o5, %i5
a011abbc:  b8 0e e0 ff  and  %i3, 0xff, %i4
a011abc0:  f8 27 40 00  st  %i4, [ %i5 ]
a011abc4:  81 c7 e0 08  ret
a011abc8:  81 e8 00 00  restore
