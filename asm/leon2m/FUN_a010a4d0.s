# leon2m FUN_a010a4d0 0xa010a4d0-0xa010a558 (136 bytes)
a010a4d0:  9d e3 bf 98  save  %sp, -104, %sp
a010a4d4:  1b 33 c0 46  sethi  %hi(0xcf011800), %o5
a010a4d8:  98 13 62 80  or  %o5, 0x280, %o4	! 0xcf011a80
a010a4dc:  c2 03 00 00  ld  [ %o4 ], %g1
a010a4e0:  80 88 60 01  btst  1, %g1
a010a4e4:  12 80 00 0f  bne  0xa010a520
a010a4e8:  90 10 20 00  clr  %o0
a010a4ec:  d2 03 00 00  ld  [ %o4 ], %o1
a010a4f0:  80 8a 60 80  btst  0x80, %o1
a010a4f4:  02 80 00 08  be  0xa010a514
a010a4f8:  90 13 62 d8  or  %o5, 0x2d8, %o0
a010a4fc:  7f ff a2 df  call  0xa00f3078
a010a500:  01 00 00 00  nop
a010a504:  97 2a 20 10  sll  %o0, 0x10, %o3
a010a508:  95 32 e0 10  srl  %o3, 0x10, %o2
a010a50c:  10 80 00 07  b  0xa010a528
a010a510:  90 10 00 0a  mov  %o2, %o0
a010a514:  11 33 c0 47  sethi  %hi(0xcf011c00), %o0
a010a518:  10 bf ff f9  b  0xa010a4fc
a010a51c:  90 12 20 18  or  %o0, 0x18, %o0	! 0xcf011c18
a010a520:  7f ff ef 55  call  0xa0106274
a010a524:  01 00 00 00  nop
a010a528:  97 2a 20 10  sll  %o0, 0x10, %o3
a010a52c:  95 32 e0 12  srl  %o3, 0x12, %o2
a010a530:  13 33 c0 7a  sethi  %hi(0xcf01e800), %o1
a010a534:  9f 32 a0 08  srl  %o2, 8, %o7
a010a538:  90 12 62 c4  or  %o1, 0x2c4, %o0
a010a53c:  82 0a a0 ff  and  %o2, 0xff, %g1
a010a540:  c2 22 00 00  st  %g1, [ %o0 ]
a010a544:  9a 12 62 c0  or  %o1, 0x2c0, %o5
a010a548:  98 13 e0 80  or  %o7, 0x80, %o4
a010a54c:  d8 23 40 00  st  %o4, [ %o5 ]
a010a550:  81 c7 e0 08  ret
a010a554:  81 e8 00 00  restore
