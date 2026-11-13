# leon2m FUN_a012a1a0 0xa012a1a0-0xa012a228 (136 bytes)
a012a1a0:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a012a1a4:  80 a2 20 00  cmp  %o0, 0
a012a1a8:  02 80 00 10  be  0xa012a1e8
a012a1ac:  c0 32 e2 12  clrh  [ %o3 + 0x212 ]
a012a1b0:  13 2a 00 b2  sethi  %hi(0xa802c800), %o1
a012a1b4:  94 12 62 e0  or  %o1, 0x2e0, %o2	! 0xa802cae0
a012a1b8:  98 10 20 00  clr  %o4
a012a1bc:  9a 10 20 00  clr  %o5
a012a1c0:  d2 0b 40 08  ldub  [ %o5 + %o0 ], %o1
a012a1c4:  d2 2a 80 0d  stb  %o1, [ %o2 + %o5 ]
a012a1c8:  da 12 e2 12  lduh  [ %o3 + 0x212 ], %o5
a012a1cc:  82 02 40 0d  add  %o1, %o5, %g1
a012a1d0:  98 03 20 01  inc  %o4
a012a1d4:  9a 0b 20 ff  and  %o4, 0xff, %o5
a012a1d8:  80 a3 60 0f  cmp  %o5, 0xf
a012a1dc:  08 bf ff f9  bleu  0xa012a1c0
a012a1e0:  c2 32 e2 12  sth  %g1, [ %o3 + 0x212 ]
a012a1e4:  30 80 00 0f  b,a   0xa012a220
a012a1e8:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a012a1ec:  82 10 62 e0  or  %g1, 0x2e0, %g1	! 0xa802cae0
a012a1f0:  94 10 20 00  clr  %o2
a012a1f4:  9a 10 20 00  clr  %o5
a012a1f8:  90 10 20 3a  mov  0x3a, %o0
a012a1fc:  92 10 20 00  clr  %o1
a012a200:  d0 28 40 0d  stb  %o0, [ %g1 + %o5 ]
a012a204:  94 02 a0 01  inc  %o2
a012a208:  98 02 60 3a  add  %o1, 0x3a, %o4
a012a20c:  9a 0a a0 ff  and  %o2, 0xff, %o5
a012a210:  80 a3 60 0f  cmp  %o5, 0xf
a012a214:  08 bf ff fb  bleu  0xa012a200
a012a218:  92 10 00 0c  mov  %o4, %o1
a012a21c:  d8 32 e2 12  sth  %o4, [ %o3 + 0x212 ]
a012a220:  81 c3 e0 08  retl
a012a224:  01 00 00 00  nop
