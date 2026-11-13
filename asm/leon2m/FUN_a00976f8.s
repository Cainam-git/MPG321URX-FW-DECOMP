# leon2m FUN_a00976f8 0xa00976f8-0xa0097814 (284 bytes)
a00976f8:  9d e3 bf 98  save  %sp, -104, %sp
a00976fc:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0097700:  a4 12 22 90  or  %o0, 0x290, %l2	! 0xa802d290
a0097704:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a0097708:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a009770c:  d8 0c a0 1f  ldub  [ %l2 + 0x1f ], %o4
a0097710:  da 0c 60 56  ldub  [ %l1 + 0x56 ], %o5
a0097714:  a0 12 63 f4  or  %o1, 0x3f4, %l0
a0097718:  b0 10 20 01  mov  1, %i0
a009771c:  80 a3 00 0d  cmp  %o4, %o5
a0097720:  02 80 00 14  be  0xa0097770
a0097724:  b2 10 20 00  clr  %i1
a0097728:  d6 14 20 04  lduh  [ %l0 + 4 ], %o3
a009772c:  1b 3f ff e0  sethi  %hi(0xffff8000), %o5
a0097730:  9e 0a c0 0d  and  %o3, %o5, %o7
a0097734:  95 2b e0 10  sll  %o7, 0x10, %o2
a0097738:  9a 12 e4 00  or  %o3, 0x400, %o5
a009773c:  80 a2 a0 00  cmp  %o2, 0
a0097740:  92 10 20 00  clr  %o1
a0097744:  12 80 00 2a  bne  0xa00977ec
a0097748:  90 10 20 04  mov  4, %o0
a009774c:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a0097750:  40 00 76 4c  call  0xa00b5080
a0097754:  c0 22 e3 ec  clr  [ %o3 + 0x3ec ]	! 0xa802afec
a0097758:  d2 14 20 18  lduh  [ %l0 + 0x18 ], %o1
a009775c:  15 00 00 10  sethi  %hi(0x4000), %o2
a0097760:  90 12 40 0a  or  %o1, %o2, %o0
a0097764:  19 00 00 08  sethi  %hi(0x2000), %o4
a0097768:  82 12 00 0c  or  %o0, %o4, %g1
a009776c:  c2 34 20 18  sth  %g1, [ %l0 + 0x18 ]
a0097770:  e0 0c 60 56  ldub  [ %l1 + 0x56 ], %l0
a0097774:  e2 0c a0 1f  ldub  [ %l2 + 0x1f ], %l1
a0097778:  80 a4 40 10  cmp  %l1, %l0
a009777c:  02 80 00 24  be  0xa009780c
a0097780:  90 10 20 00  clr  %o0
a0097784:  40 01 06 9e  call  0xa00d91fc
a0097788:  01 00 00 00  nop
a009778c:  90 10 20 00  clr  %o0	! 0x0
a0097790:  40 02 c2 b6  call  0xa0148268
a0097794:  92 10 20 01  mov  1, %o1
a0097798:  92 10 20 01  mov  1, %o1
a009779c:  40 02 c2 b3  call  0xa0148268
a00977a0:  90 10 20 01  mov  1, %o0
a00977a4:  40 01 0a ac  call  0xa00da254
a00977a8:  01 00 00 00  nop
a00977ac:  7f ff ae 52  call  0xa00830f4
a00977b0:  90 10 20 00  clr  %o0	! 0x0
a00977b4:  40 01 05 1a  call  0xa00d8c1c
a00977b8:  01 00 00 00  nop
a00977bc:  40 00 f4 77  call  0xa00d4998
a00977c0:  01 00 00 00  nop
a00977c4:  de 04 a0 a8  ld  [ %l2 + 0xa8 ], %o7
a00977c8:  25 00 00 10  sethi  %hi(0x4000), %l2
a00977cc:  80 8b c0 12  btst  %o7, %l2
a00977d0:  12 80 00 0b  bne  0xa00977fc
a00977d4:  01 00 00 00  nop
a00977d8:  90 10 20 00  clr  %o0	! 0x0
a00977dc:  7f ff a4 34  call  0xa00808ac
a00977e0:  92 10 20 00  clr  %o1
a00977e4:  7f ff a4 32  call  0xa00808ac
a00977e8:  81 e8 00 00  restore
a00977ec:  7f ff a4 30  call  0xa00808ac
a00977f0:  da 34 20 04  sth  %o5, [ %l0 + 4 ]
a00977f4:  10 bf ff d7  b  0xa0097750
a00977f8:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a00977fc:  40 00 f9 37  call  0xa00d5cd8
a0097800:  01 00 00 00  nop
a0097804:  10 bf ff f6  b  0xa00977dc
a0097808:  90 10 20 00  clr  %o0	! 0x0
a009780c:  81 c7 e0 08  ret
a0097810:  81 e8 00 00  restore
