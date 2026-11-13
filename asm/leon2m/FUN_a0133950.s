# leon2m FUN_a0133950 0xa0133950-0xa0133a10 (192 bytes)  [FUN_a0133a08 = unreachable ret/restore tail, merged]
a0133950:  9d e3 bf 98  save  %sp, -104, %sp
a0133954:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0133958:  96 10 00 1a  mov  %i2, %o3
a013395c:  80 a6 20 04  cmp  %i0, 4
a0133960:  18 80 00 26  bgu  0xa01339f8
a0133964:  9e 10 00 1b  mov  %i3, %o7
a0133968:  83 2e 60 10  sll  %i1, 0x10, %g1
a013396c:  b3 30 60 10  srl  %g1, 0x10, %i1
a0133970:  c0 36 c0 00  clrh  [ %i3 ]
a0133974:  80 a6 60 00  cmp  %i1, 0
a0133978:  02 80 00 23  be  0xa0133a04
a013397c:  b8 10 20 00  clr  %i4
a0133980:  83 2e 20 03  sll  %i0, 3, %g1
a0133984:  b6 00 40 18  add  %g1, %i0, %i3
a0133988:  b5 2e e0 02  sll  %i3, 2, %i2
a013398c:  3b 2a 00 b7  sethi  %hi(0xa802dc00), %i5
a0133990:  9a 26 80 18  sub  %i2, %i0, %o5
a0133994:  94 17 61 90  or  %i5, 0x190, %o2
a0133998:  98 10 00 19  mov  %i1, %o4
a013399c:  b6 03 40 0a  add  %o5, %o2, %i3
a01339a0:  b1 2f 20 10  sll  %i4, 0x10, %i0
a01339a4:  b8 07 20 01  inc  %i4
a01339a8:  b5 2f 20 10  sll  %i4, 0x10, %i2
a01339ac:  b3 36 20 10  srl  %i0, 0x10, %i1
a01339b0:  fa 0e e0 01  ldub  [ %i3 + 1 ], %i5
a01339b4:  b1 36 a0 10  srl  %i2, 0x10, %i0
a01339b8:  c2 0a 80 0d  ldub  [ %o2 + %o5 ], %g1
a01339bc:  80 a0 40 1d  cmp  %g1, %i5
a01339c0:  02 80 00 11  be  0xa0133a04
a01339c4:  b4 06 c0 1d  add  %i3, %i5, %i2
a01339c8:  fa 0e a0 02  ldub  [ %i2 + 2 ], %i5
a01339cc:  fa 2e 40 0b  stb  %i5, [ %i1 + %o3 ]
a01339d0:  f2 13 c0 00  lduh  [ %o7 ], %i1
a01339d4:  b4 06 60 01  add  %i1, 1, %i2
a01339d8:  f4 33 c0 00  sth  %i2, [ %o7 ]
a01339dc:  c2 0e e0 01  ldub  [ %i3 + 1 ], %g1
a01339e0:  ba 00 60 01  add  %g1, 1, %i5
a01339e4:  b2 0f 60 1f  and  %i5, 0x1f, %i1
a01339e8:  80 a6 00 0c  cmp  %i0, %o4
a01339ec:  0a bf ff ed  bcs  0xa01339a0
a01339f0:  f2 2e e0 01  stb  %i1, [ %i3 + 1 ]
a01339f4:  30 80 00 04  b,a   0xa0133a04
a01339f8:  31 00 06 94  sethi  %hi(0x1a5000), %i0
a01339fc:  7f fe ad dd  call  0xa00df170
a0133a00:  91 ee 23 e0  restore  %i0, 0x3e0, %o0
a0133a04:  01 00 00 00  nop
a0133a08:  81 c7 e0 08  ret
a0133a0c:  81 e8 00 00  restore
