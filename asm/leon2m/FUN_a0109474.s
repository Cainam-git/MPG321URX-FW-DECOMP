# leon2m FUN_a0109474 0xa0109474-0xa0109514 (160 bytes)
a0109474:  90 0a 20 ff  and  %o0, 0xff, %o0
a0109478:  80 a2 20 02  cmp  %o0, 2
a010947c:  22 80 00 14  be,a   0xa01094cc
a0109480:  11 33 c0 46  sethi  %hi(0xcf011800), %o0
a0109484:  04 80 00 07  ble  0xa01094a0
a0109488:  80 a2 20 01  cmp  %o0, 1
a010948c:  80 a2 20 03  cmp  %o0, 3
a0109490:  12 80 00 1f  bne  0xa010950c
a0109494:  1b 33 c0 46  sethi  %hi(0xcf011800), %o5
a0109498:  10 80 00 16  b  0xa01094f0
a010949c:  80 8a 60 ff  btst  0xff, %o1
a01094a0:  12 80 00 1b  bne  0xa010950c
a01094a4:  1b 33 c0 46  sethi  %hi(0xcf011800), %o5
a01094a8:  80 8a 60 ff  btst  0xff, %o1
a01094ac:  12 80 00 0d  bne  0xa01094e0
a01094b0:  9a 13 62 a4  or  %o5, 0x2a4, %o5
a01094b4:  03 33 c0 46  sethi  %hi(0xcf011800), %g1
a01094b8:  9a 10 62 a4  or  %g1, 0x2a4, %o5	! 0xcf011aa4
a01094bc:  d2 03 40 00  ld  [ %o5 ], %o1
a01094c0:  82 0a 7f 7f  and  %o1, -129, %g1
a01094c4:  c2 23 40 00  st  %g1, [ %o5 ]
a01094c8:  30 80 00 11  b,a   0xa010950c
a01094cc:  80 8a 60 ff  btst  0xff, %o1
a01094d0:  02 bf ff fb  be  0xa01094bc
a01094d4:  9a 12 22 a8  or  %o0, 0x2a8, %o5
a01094d8:  13 33 c0 46  sethi  %hi(0xcf011800), %o1
a01094dc:  9a 12 62 a8  or  %o1, 0x2a8, %o5	! 0xcf011aa8
a01094e0:  c2 03 40 00  ld  [ %o5 ], %g1
a01094e4:  82 10 60 80  or  %g1, 0x80, %g1
a01094e8:  c2 23 40 00  st  %g1, [ %o5 ]
a01094ec:  30 80 00 08  b,a   0xa010950c
a01094f0:  12 bf ff fc  bne  0xa01094e0
a01094f4:  9a 13 62 ac  or  %o5, 0x2ac, %o5
a01094f8:  11 33 c0 46  sethi  %hi(0xcf011800), %o0
a01094fc:  9a 12 22 ac  or  %o0, 0x2ac, %o5	! 0xcf011aac
a0109500:  d2 03 40 00  ld  [ %o5 ], %o1
a0109504:  10 bf ff f0  b  0xa01094c4
a0109508:  82 0a 7f 7f  and  %o1, -129, %g1
a010950c:  81 c3 e0 08  retl
a0109510:  01 00 00 00  nop
