# leon2m FUN_a00ac718 0xa00ac718-0xa00acc40 (1092 bytes)
a00ac718:  9d e3 bf 78  save  %sp, -136, %sp
a00ac71c:  9a 10 20 00  clr  %o5
a00ac720:  98 10 20 00  clr  %o4
a00ac724:  d8 3f bf d8  std  %o4, [ %fp + -40 ]
a00ac728:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a00ac72c:  90 10 21 11  mov  0x111, %o0
a00ac730:  92 10 20 00  clr  %o1
a00ac734:  c0 27 bf f0  clr  [ %fp + -16 ]
a00ac738:  c0 37 bf f4  clrh  [ %fp + -12 ]
a00ac73c:  c0 2f bf f6  clrb  [ %fp + -10 ]
a00ac740:  c0 27 bf e0  clr  [ %fp + -32 ]
a00ac744:  c0 37 bf e4  clrh  [ %fp + -28 ]
a00ac748:  40 02 69 02  call  0xa0146b50
a00ac74c:  c0 2f bf e6  clrb  [ %fp + -26 ]
a00ac750:  90 10 20 00  clr  %o0
a00ac754:  40 02 69 06  call  0xa0146b6c
a00ac758:  92 10 20 00  clr  %o1
a00ac75c:  7f ff f1 4b  call  0xa00a8c88
a00ac760:  aa 10 20 07  mov  7, %l5
a00ac764:  83 2e 20 10  sll  %i0, 0x10, %g1
a00ac768:  83 30 60 10  srl  %g1, 0x10, %g1
a00ac76c:  80 a0 60 39  cmp  %g1, 0x39
a00ac770:  02 80 00 22  be  0xa00ac7f8
a00ac774:  9a 10 20 00  clr  %o5
a00ac778:  80 a0 60 39  cmp  %g1, 0x39
a00ac77c:  14 80 00 14  bg  0xa00ac7cc
a00ac780:  80 a0 60 ba  cmp  %g1, 0xba
a00ac784:  80 a0 60 36  cmp  %g1, 0x36
a00ac788:  02 80 00 ad  be  0xa00aca3c
a00ac78c:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a00ac790:  04 80 00 1d  ble  0xa00ac804
a00ac794:  80 a0 60 34  cmp  %g1, 0x34
a00ac798:  80 a0 60 37  cmp  %g1, 0x37
a00ac79c:  02 80 01 1e  be  0xa00acc14
a00ac7a0:  80 a0 60 38  cmp  %g1, 0x38
a00ac7a4:  12 80 00 06  bne  0xa00ac7bc
a00ac7a8:  a6 0b 60 ff  and  %o5, 0xff, %l3
a00ac7ac:  21 2a 00 b5  sethi  %hi(0xa802d400), %l0
a00ac7b0:  ea 0c 20 78  ldub  [ %l0 + 0x78 ], %l5	! 0xa802d478
a00ac7b4:  9a 10 20 03  mov  3, %o5
a00ac7b8:  a6 0b 60 ff  and  %o5, 0xff, %l3
a00ac7bc:  80 a4 e0 00  cmp  %l3, 0
a00ac7c0:  02 80 01 1e  be  0xa00acc38
a00ac7c4:  01 00 00 00  nop
a00ac7c8:  30 80 00 22  b,a   0xa00ac850
a00ac7cc:  02 bf ff fa  be  0xa00ac7b4
a00ac7d0:  80 a0 60 ba  cmp  %g1, 0xba
a00ac7d4:  14 80 00 11  bg  0xa00ac818
a00ac7d8:  80 a0 60 be  cmp  %g1, 0xbe
a00ac7dc:  80 a0 60 3a  cmp  %g1, 0x3a
a00ac7e0:  02 80 01 13  be  0xa00acc2c
a00ac7e4:  80 a0 60 3b  cmp  %g1, 0x3b
a00ac7e8:  22 bf ff f4  be,a   0xa00ac7b8
a00ac7ec:  9a 10 20 06  mov  6, %o5
a00ac7f0:  10 bf ff f3  b  0xa00ac7bc
a00ac7f4:  a6 0b 60 ff  and  %o5, 0xff, %l3
a00ac7f8:  23 2a 00 b5  sethi  %hi(0xa802d400), %l1
a00ac7fc:  10 bf ff ee  b  0xa00ac7b4
a00ac800:  ea 0c 60 7a  ldub  [ %l1 + 0x7a ], %l5	! 0xa802d47a
a00ac804:  12 bf ff ee  bne  0xa00ac7bc
a00ac808:  a6 0b 60 ff  and  %o5, 0xff, %l3
a00ac80c:  11 2a 00 b5  sethi  %hi(0xa802d400), %o0
a00ac810:  10 bf ff e9  b  0xa00ac7b4
a00ac814:  ea 0a 20 6d  ldub  [ %o0 + 0x6d ], %l5	! 0xa802d46d
a00ac818:  02 80 00 8a  be  0xa00aca40
a00ac81c:  80 a0 60 be  cmp  %g1, 0xbe
a00ac820:  04 80 00 8a  ble  0xa00aca48
a00ac824:  80 a0 60 bd  cmp  %g1, 0xbd
a00ac828:  80 a0 60 bf  cmp  %g1, 0xbf
a00ac82c:  12 bf ff e4  bne  0xa00ac7bc
a00ac830:  a6 0b 60 ff  and  %o5, 0xff, %l3
a00ac834:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a00ac838:  d8 0b e0 6f  ldub  [ %o7 + 0x6f ], %o4	! 0xa802d46f
a00ac83c:  80 a3 20 06  cmp  %o4, 6
a00ac840:  08 bf ff de  bleu  0xa00ac7b8
a00ac844:  9a 10 20 07  mov  7, %o5
a00ac848:  10 bf ff dc  b  0xa00ac7b8
a00ac84c:  9a 10 20 01  mov  1, %o5
a00ac850:  40 02 64 aa  call  0xa0145af8
a00ac854:  90 10 20 0f  mov  0xf, %o0
a00ac858:  ad 2a 20 10  sll  %o0, 0x10, %l6
a00ac85c:  40 02 64 a7  call  0xa0145af8
a00ac860:  90 10 20 0d  mov  0xd, %o0
a00ac864:  a9 2a 20 10  sll  %o0, 0x10, %l4
a00ac868:  40 02 64 a4  call  0xa0145af8
a00ac86c:  90 10 20 0b  mov  0xb, %o0
a00ac870:  a1 35 a0 10  srl  %l6, 0x10, %l0
a00ac874:  a3 35 20 10  srl  %l4, 0x10, %l1
a00ac878:  83 2a 20 10  sll  %o0, 0x10, %g1
a00ac87c:  ac 07 bf d8  add  %fp, -40, %l6
a00ac880:  29 00 06 60  sethi  %hi(0x198000), %l4
a00ac884:  99 30 60 10  srl  %g1, 0x10, %o4
a00ac888:  94 10 00 10  mov  %l0, %o2
a00ac88c:  96 10 00 11  mov  %l1, %o3
a00ac890:  90 10 00 16  mov  %l6, %o0
a00ac894:  40 02 ab d8  call  0xa01577f4
a00ac898:  92 15 21 c0  or  %l4, 0x1c0, %o1
a00ac89c:  98 10 20 00  clr  %o4
a00ac8a0:  82 10 20 00  clr  %g1
a00ac8a4:  a4 07 bf f8  add  %fp, -8, %l2
a00ac8a8:  92 04 80 01  add  %l2, %g1, %o1
a00ac8ac:  d0 0a 7f e0  ldub  [ %o1 + -32 ], %o0
a00ac8b0:  80 a2 20 00  cmp  %o0, 0
a00ac8b4:  02 80 00 08  be  0xa00ac8d4
a00ac8b8:  9e 03 3f ff  add  %o4, -1, %o7
a00ac8bc:  98 03 20 01  inc  %o4
a00ac8c0:  82 0b 20 ff  and  %o4, 0xff, %g1
a00ac8c4:  80 a0 60 0e  cmp  %g1, 0xe
a00ac8c8:  08 bf ff f9  bleu  0xa00ac8ac
a00ac8cc:  92 04 80 01  add  %l2, %g1, %o1
a00ac8d0:  9e 03 3f ff  add  %o4, -1, %o7
a00ac8d4:  de 2f bf d8  stb  %o7, [ %fp + -40 ]
a00ac8d8:  40 02 64 88  call  0xa0145af8
a00ac8dc:  90 10 20 0e  mov  0xe, %o0
a00ac8e0:  97 2a 20 10  sll  %o0, 0x10, %o3
a00ac8e4:  a3 32 e0 10  srl  %o3, 0x10, %l1
a00ac8e8:  40 02 64 84  call  0xa0145af8
a00ac8ec:  90 10 20 0c  mov  0xc, %o0
a00ac8f0:  95 2a 20 10  sll  %o0, 0x10, %o2
a00ac8f4:  a1 32 a0 10  srl  %o2, 0x10, %l0
a00ac8f8:  40 02 64 80  call  0xa0145af8
a00ac8fc:  90 10 20 0a  mov  0xa, %o0
a00ac900:  9b 2a 20 10  sll  %o0, 0x10, %o5
a00ac904:  99 33 60 10  srl  %o5, 0x10, %o4
a00ac908:  92 15 21 c0  or  %l4, 0x1c0, %o1
a00ac90c:  94 10 00 11  mov  %l1, %o2
a00ac910:  96 10 00 10  mov  %l0, %o3
a00ac914:  40 02 ab b8  call  0xa01577f4
a00ac918:  90 07 bf e8  add  %fp, -24, %o0
a00ac91c:  98 10 20 00  clr  %o4
a00ac920:  82 10 20 00  clr  %g1
a00ac924:  82 04 80 01  add  %l2, %g1, %g1
a00ac928:  e8 08 7f f0  ldub  [ %g1 + -16 ], %l4
a00ac92c:  80 a5 20 00  cmp  %l4, 0
a00ac930:  22 80 00 08  be,a   0xa00ac950
a00ac934:  a4 03 3f ff  add  %o4, -1, %l2
a00ac938:  98 03 20 01  inc  %o4
a00ac93c:  82 0b 20 ff  and  %o4, 0xff, %g1
a00ac940:  80 a0 60 0e  cmp  %g1, 0xe
a00ac944:  28 bf ff f9  bleu,a   0xa00ac928
a00ac948:  82 04 80 01  add  %l2, %g1, %g1
a00ac94c:  a4 03 3f ff  add  %o4, -1, %l2
a00ac950:  e4 2f bf e8  stb  %l2, [ %fp + -24 ]
a00ac954:  80 a4 e0 00  cmp  %l3, 0
a00ac958:  02 80 00 79  be  0xa00acb3c
a00ac95c:  a8 10 20 00  clr  %l4
a00ac960:  b1 2e 20 10  sll  %i0, 0x10, %i0
a00ac964:  10 80 00 0f  b  0xa00ac9a0
a00ac968:  a4 10 20 00  clr  %l2
a00ac96c:  92 04 80 12  add  %l2, %l2, %o1
a00ac970:  94 02 60 06  add  %o1, 6, %o2
a00ac974:  98 10 00 08  mov  %o0, %o4
a00ac978:  90 10 20 00  clr  %o0
a00ac97c:  92 10 20 2a  mov  0x2a, %o1
a00ac980:  96 10 20 01  mov  1, %o3
a00ac984:  7f ff da 08  call  0xa00a31a4
a00ac988:  9a 10 20 00  clr  %o5
a00ac98c:  a8 05 20 01  inc  %l4
a00ac990:  a4 0d 20 ff  and  %l4, 0xff, %l2
a00ac994:  80 a4 80 13  cmp  %l2, %l3
a00ac998:  1a 80 00 6a  bcc  0xa00acb40
a00ac99c:  a2 0d 60 ff  and  %l5, 0xff, %l1
a00ac9a0:  a1 36 20 10  srl  %i0, 0x10, %l0
a00ac9a4:  90 10 00 10  mov  %l0, %o0
a00ac9a8:  7f ff fd e4  call  0xa00ac138
a00ac9ac:  92 10 00 12  mov  %l2, %o1
a00ac9b0:  80 a4 20 3b  cmp  %l0, 0x3b
a00ac9b4:  12 bf ff ee  bne  0xa00ac96c
a00ac9b8:  a2 10 00 08  mov  %o0, %l1
a00ac9bc:  90 10 20 00  clr  %o0
a00ac9c0:  40 02 68 6b  call  0xa0146b6c
a00ac9c4:  92 10 20 00  clr  %o1
a00ac9c8:  90 05 3f fe  add  %l4, -2, %o0
a00ac9cc:  98 0a 20 ff  and  %o0, 0xff, %o4
a00ac9d0:  80 a3 20 02  cmp  %o4, 2
a00ac9d4:  18 80 00 06  bgu  0xa00ac9ec
a00ac9d8:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00ac9dc:  d2 0b 62 98  ldub  [ %o5 + 0x298 ], %o1	! 0xa802d298
a00ac9e0:  80 a2 60 0d  cmp  %o1, 0xd
a00ac9e4:  02 80 00 72  be  0xa00acbac
a00ac9e8:  82 1c a0 02  xor  %l2, 2, %g1
a00ac9ec:  90 04 80 12  add  %l2, %l2, %o0
a00ac9f0:  94 02 20 06  add  %o0, 6, %o2
a00ac9f4:  98 10 00 11  mov  %l1, %o4
a00ac9f8:  90 10 20 00  clr  %o0
a00ac9fc:  92 10 20 29  mov  0x29, %o1
a00aca00:  96 10 20 01  mov  1, %o3
a00aca04:  7f ff d9 e8  call  0xa00a31a4
a00aca08:  9a 10 20 00  clr  %o5
a00aca0c:  90 10 20 01  mov  1, %o0
a00aca10:  40 02 68 57  call  0xa0146b6c
a00aca14:  92 10 20 00  clr  %o1
a00aca18:  80 a4 a0 05  cmp  %l2, 5
a00aca1c:  38 bf ff dd  bgu,a   0xa00ac990
a00aca20:  a8 05 20 01  inc  %l4
a00aca24:  15 00 01 10  sethi  %hi(0x44000), %o2
a00aca28:  93 2c a0 02  sll  %l2, 2, %o1
a00aca2c:  9a 12 a1 3c  or  %o2, 0x13c, %o5
a00aca30:  e2 03 40 09  ld  [ %o5 + %o1 ], %l1
a00aca34:  81 c4 40 00  jmp  %l1
a00aca38:  01 00 00 00  nop
a00aca3c:  ea 0a e0 7e  ldub  [ %o3 + 0x7e ], %l5
a00aca40:  10 bf ff 5e  b  0xa00ac7b8
a00aca44:  9a 10 20 02  mov  2, %o5
a00aca48:  22 bf ff 5c  be,a   0xa00ac7b8
a00aca4c:  9a 10 20 02  mov  2, %o5
a00aca50:  10 bf ff 5b  b  0xa00ac7bc
a00aca54:  a6 0b 60 ff  and  %o5, 0xff, %l3
a00aca58:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00aca5c:  98 13 22 90  or  %o4, 0x290, %o4	! 0xa802d290
a00aca60:  c2 0b 21 ec  ldub  [ %o4 + 0x1ec ], %g1
a00aca64:  a1 28 60 03  sll  %g1, 3, %l0
a00aca68:  9e 24 00 01  sub  %l0, %g1, %o7
a00aca6c:  97 2b e0 02  sll  %o7, 2, %o3
a00aca70:  da 0b 20 08  ldub  [ %o4 + 8 ], %o5
a00aca74:  94 02 c0 01  add  %o3, %g1, %o2
a00aca78:  92 02 80 0d  add  %o2, %o5, %o1
a00aca7c:  99 2a 60 10  sll  %o1, 0x10, %o4
a00aca80:  23 00 06 4c  sethi  %hi(0x193000), %l1
a00aca84:  93 33 20 10  srl  %o4, 0x10, %o1
a00aca88:  90 14 62 48  or  %l1, 0x248, %o0
a00aca8c:  7f ff db 6e  call  0xa00a3844
a00aca90:  01 00 00 00  nop
a00aca94:  98 10 00 08  mov  %o0, %o4
a00aca98:  82 04 80 12  add  %l2, %l2, %g1
a00aca9c:  94 00 60 07  add  %g1, 7, %o2
a00acaa0:  90 10 20 00  clr  %o0
a00acaa4:  92 10 20 27  mov  0x27, %o1
a00acaa8:  10 bf ff b7  b  0xa00ac984
a00acaac:  96 10 20 0e  mov  0xe, %o3
a00acab0:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00acab4:  98 14 62 90  or  %l1, 0x290, %o4	! 0xa802d290
a00acab8:  10 bf ff eb  b  0xa00aca64
a00acabc:  c2 0b 21 ea  ldub  [ %o4 + 0x1ea ], %g1
a00acac0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00acac4:  98 12 22 90  or  %o0, 0x290, %o4	! 0xa802d290
a00acac8:  10 bf ff e7  b  0xa00aca64
a00acacc:  c2 0b 21 e8  ldub  [ %o4 + 0x1e8 ], %g1
a00acad0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00acad4:  98 12 22 90  or  %o0, 0x290, %o4	! 0xa802d290
a00acad8:  e0 03 21 dc  ld  [ %o4 + 0x1dc ], %l0
a00acadc:  83 34 20 0f  srl  %l0, 0xf, %g1
a00acae0:  10 bf ff e1  b  0xa00aca64
a00acae4:  82 08 60 01  and  %g1, 1, %g1
a00acae8:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00acaec:  98 13 e2 90  or  %o7, 0x290, %o4	! 0xa802d290
a00acaf0:  da 0b 21 dd  ldub  [ %o4 + 0x1dd ], %o5
a00acaf4:  97 2b 60 03  sll  %o5, 3, %o3
a00acaf8:  94 22 c0 0d  sub  %o3, %o5, %o2
a00acafc:  93 2a a0 02  sll  %o2, 2, %o1
a00acb00:  90 02 40 0d  add  %o1, %o5, %o0
a00acb04:  e2 0b 20 08  ldub  [ %o4 + 8 ], %l1
a00acb08:  a0 02 00 11  add  %o0, %l1, %l0
a00acb0c:  83 2c 20 10  sll  %l0, 0x10, %g1
a00acb10:  1f 00 06 2d  sethi  %hi(0x18b400), %o7
a00acb14:  93 30 60 10  srl  %g1, 0x10, %o1
a00acb18:  10 bf ff dd  b  0xa00aca8c
a00acb1c:  90 13 e1 e0  or  %o7, 0x1e0, %o0
a00acb20:  96 04 80 12  add  %l2, %l2, %o3
a00acb24:  94 02 e0 07  add  %o3, 7, %o2
a00acb28:  90 10 20 00  clr  %o0
a00acb2c:  92 10 20 27  mov  0x27, %o1
a00acb30:  96 10 20 0e  mov  0xe, %o3
a00acb34:  10 bf ff 94  b  0xa00ac984
a00acb38:  98 10 00 16  mov  %l6, %o4
a00acb3c:  a2 0d 60 ff  and  %l5, 0xff, %l1
a00acb40:  80 a4 60 07  cmp  %l1, 7
a00acb44:  02 80 00 3d  be  0xa00acc38
a00acb48:  90 10 00 11  mov  %l1, %o0
a00acb4c:  7f ff f2 c1  call  0xa00a9650
a00acb50:  92 10 20 00  clr  %o1
a00acb54:  a6 04 40 11  add  %l1, %l1, %l3
a00acb58:  80 a4 60 06  cmp  %l1, 6
a00acb5c:  08 80 00 04  bleu  0xa00acb6c
a00acb60:  82 04 e0 06  add  %l3, 6, %g1
a00acb64:  aa 04 40 11  add  %l1, %l1, %l5
a00acb68:  82 05 7f f8  add  %l5, -8, %g1
a00acb6c:  b0 08 60 ff  and  %g1, 0xff, %i0
a00acb70:  94 10 00 18  mov  %i0, %o2
a00acb74:  90 10 20 00  clr  %o0
a00acb78:  92 10 20 28  mov  0x28, %o1
a00acb7c:  96 10 20 01  mov  1, %o3
a00acb80:  98 10 20 0f  mov  0xf, %o4
a00acb84:  40 02 67 e7  call  0xa0146b20
a00acb88:  9a 10 20 00  clr  %o5
a00acb8c:  94 10 00 18  mov  %i0, %o2
a00acb90:  90 10 20 00  clr  %o0
a00acb94:  92 10 20 29  mov  0x29, %o1
a00acb98:  96 10 20 01  mov  1, %o3
a00acb9c:  98 10 20 10  mov  0x10, %o4
a00acba0:  40 02 67 e0  call  0xa0146b20
a00acba4:  9a 10 20 00  clr  %o5
a00acba8:  30 80 00 24  b,a   0xa00acc38
a00acbac:  80 a0 00 01  cmp  %g0, %g1
a00acbb0:  96 60 3f ff  subx  %g0, -1, %o3
a00acbb4:  9e 1c a0 04  xor  %l2, 4, %o7
a00acbb8:  80 a0 00 0f  cmp  %g0, %o7
a00acbbc:  94 60 3f ff  subx  %g0, -1, %o2
a00acbc0:  80 92 c0 0a  orcc  %o3, %o2, %g0
a00acbc4:  22 80 00 08  be,a   0xa00acbe4
a00acbc8:  98 04 80 12  add  %l2, %l2, %o4
a00acbcc:  a0 04 80 12  add  %l2, %l2, %l0
a00acbd0:  94 04 20 06  add  %l0, 6, %o2
a00acbd4:  98 10 00 11  mov  %l1, %o4
a00acbd8:  90 10 20 00  clr  %o0
a00acbdc:  10 bf ff 89  b  0xa00aca00
a00acbe0:  92 10 20 28  mov  0x28, %o1
a00acbe4:  a0 03 20 06  add  %o4, 6, %l0
a00acbe8:  92 10 00 10  mov  %l0, %o1
a00acbec:  90 10 20 26  mov  0x26, %o0
a00acbf0:  94 10 20 01  mov  1, %o2
a00acbf4:  98 10 20 00  clr  %o4
a00acbf8:  40 02 67 a2  call  0xa0146a80
a00acbfc:  96 10 27 96  mov  0x796, %o3
a00acc00:  94 10 00 10  mov  %l0, %o2
a00acc04:  98 10 00 11  mov  %l1, %o4
a00acc08:  90 10 20 00  clr  %o0
a00acc0c:  10 bf ff 7d  b  0xa00aca00
a00acc10:  92 10 20 26  mov  0x26, %o1
a00acc14:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00acc18:  d4 03 60 6c  ld  [ %o5 + 0x6c ], %o2	! 0xa802d46c
a00acc1c:  93 32 a0 0f  srl  %o2, 0xf, %o1
a00acc20:  aa 0a 60 01  and  %o1, 1, %l5
a00acc24:  10 bf fe e5  b  0xa00ac7b8
a00acc28:  9a 10 20 05  mov  5, %o5
a00acc2c:  25 2a 00 b5  sethi  %hi(0xa802d400), %l2
a00acc30:  10 bf fe e1  b  0xa00ac7b4
a00acc34:  ea 0c a0 7c  ldub  [ %l2 + 0x7c ], %l5	! 0xa802d47c
a00acc38:  81 c7 e0 08  ret
a00acc3c:  81 e8 00 00  restore
