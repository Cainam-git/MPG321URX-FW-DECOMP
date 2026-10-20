# leon2m FUN_a01181d4 0xa01181d4-0xa01182cc (248 bytes)
a01181d4:  15 2a 00 9e  sethi  %hi(0xa8027800), %o2
a01181d8:  96 12 a2 90  or  %o2, 0x290, %o3	! 0xa8027a90
a01181dc:  d8 0a e0 03  ldub  [ %o3 + 3 ], %o4
a01181e0:  9a 03 3f ff  add  %o4, -1, %o5
a01181e4:  82 0b 60 ff  and  %o5, 0xff, %g1
a01181e8:  80 a0 60 05  cmp  %g1, 5
a01181ec:  18 80 00 04  bgu  0xa01181fc
a01181f0:  82 0b 20 ff  and  %o4, 0xff, %g1
a01181f4:  10 80 00 34  b  0xa01182c4
a01181f8:  da 2a e0 03  stb  %o5, [ %o3 + 3 ]
a01181fc:  80 a0 60 00  cmp  %g1, 0
a0118200:  12 80 00 05  bne  0xa0118214
a0118204:  80 a0 60 0d  cmp  %g1, 0xd
a0118208:  82 10 20 08  mov  8, %g1
a011820c:  10 80 00 2e  b  0xa01182c4
a0118210:  c2 2a e0 03  stb  %g1, [ %o3 + 3 ]
a0118214:  08 80 00 0c  bleu  0xa0118244
a0118218:  82 03 20 01  add  %o4, 1, %g1
a011821c:  c2 0a e0 01  ldub  [ %o3 + 1 ], %g1
a0118220:  80 a0 60 02  cmp  %g1, 2
a0118224:  38 80 00 0a  bgu,a   0xa011824c
a0118228:  c2 0a e0 02  ldub  [ %o3 + 2 ], %g1
a011822c:  98 00 60 01  add  %g1, 1, %o4
a0118230:  d8 2a e0 01  stb  %o4, [ %o3 + 1 ]
a0118234:  96 12 a2 90  or  %o2, 0x290, %o3
a0118238:  94 10 20 06  mov  6, %o2
a011823c:  10 80 00 22  b  0xa01182c4
a0118240:  d4 2a e0 03  stb  %o2, [ %o3 + 3 ]
a0118244:  10 80 00 20  b  0xa01182c4
a0118248:  c2 2a e0 03  stb  %g1, [ %o3 + 3 ]
a011824c:  80 a0 60 01  cmp  %g1, 1
a0118250:  02 80 00 05  be  0xa0118264
a0118254:  98 18 60 01  xor  %g1, 1, %o4
a0118258:  d8 2a e0 02  stb  %o4, [ %o3 + 2 ]
a011825c:  10 bf ff f6  b  0xa0118234
a0118260:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a0118264:  da 0a a2 90  ldub  [ %o2 + 0x290 ], %o5
a0118268:  80 a3 60 00  cmp  %o5, 0
a011826c:  12 80 00 08  bne  0xa011828c
a0118270:  80 a3 60 02  cmp  %o5, 2
a0118274:  82 18 60 01  xor  %g1, 1, %g1
a0118278:  9a 10 20 02  mov  2, %o5
a011827c:  c2 2a e0 02  stb  %g1, [ %o3 + 2 ]
a0118280:  da 2a a2 90  stb  %o5, [ %o2 + 0x290 ]
a0118284:  10 bf ff ec  b  0xa0118234
a0118288:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a011828c:  02 80 00 04  be  0xa011829c
a0118290:  80 a3 60 01  cmp  %o5, 1
a0118294:  32 bf ff e9  bne,a   0xa0118238
a0118298:  96 12 a2 90  or  %o2, 0x290, %o3
a011829c:  82 10 20 06  mov  6, %g1
a01182a0:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a01182a4:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a01182a8:  c2 2a e0 03  stb  %g1, [ %o3 + 3 ]
a01182ac:  c0 2b 61 8d  clrb  [ %o5 + 0x18d ]
a01182b0:  c0 2b 21 8c  clrb  [ %o4 + 0x18c ]
a01182b4:  c0 2a a2 90  clrb  [ %o2 + 0x290 ]
a01182b8:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a01182bc:  10 bf ff de  b  0xa0118234
a01182c0:  c0 2a e0 02  clrb  [ %o3 + 2 ]
a01182c4:  81 c3 e0 08  retl
a01182c8:  01 00 00 00  nop
