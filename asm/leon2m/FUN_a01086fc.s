# leon2m FUN_a01086fc 0xa01086fc-0xa0108e4c (1872 bytes)
a01086fc:  9d e3 bf 90  save  %sp, -112, %sp
a0108700:  ea 0f a0 5f  ldub  [ %fp + 0x5f ], %l5
a0108704:  80 a5 60 01  cmp  %l5, 1
a0108708:  02 80 01 cd  be  0xa0108e3c
a010870c:  fa 2f bf f7  stb  %i5, [ %fp + -9 ]
a0108710:  e0 16 60 08  lduh  [ %i1 + 8 ], %l0
a0108714:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0108718:  40 00 62 d0  call  0xa0121258
a010871c:  90 10 00 18  mov  %i0, %o0
a0108720:  90 0a 20 ff  and  %o0, 0xff, %o0
a0108724:  80 a2 20 01  cmp  %o0, 1
a0108728:  98 10 00 1b  mov  %i3, %o4
a010872c:  02 80 01 61  be  0xa0108cb0
a0108730:  ad 2e a0 10  sll  %i2, 0x10, %l6
a0108734:  e2 16 60 0c  lduh  [ %i1 + 0xc ], %l1
a0108738:  9f 35 a0 10  srl  %l6, 0x10, %o7
a010873c:  80 a4 40 0f  cmp  %l1, %o7
a0108740:  02 80 00 54  be  0xa0108890
a0108744:  97 2b 20 10  sll  %o4, 0x10, %o3
a0108748:  d4 16 60 0e  lduh  [ %i1 + 0xe ], %o2
a010874c:  ee 16 60 3a  lduh  [ %i1 + 0x3a ], %l7
a0108750:  3b 3f ff e0  sethi  %hi(0xffff8000), %i5
a0108754:  a8 0d c0 1d  and  %l7, %i5, %l4
a0108758:  a7 2d 20 10  sll  %l4, 0x10, %l3
a010875c:  80 a4 e0 00  cmp  %l3, 0
a0108760:  32 80 00 02  bne,a   0xa0108768
a0108764:  c0 2f bf f7  clrb  [ %fp + -9 ]
a0108768:  a1 2c 20 10  sll  %l0, 0x10, %l0
a010876c:  fa 16 60 0a  lduh  [ %i1 + 0xa ], %i5
a0108770:  af 34 20 10  srl  %l0, 0x10, %l7
a0108774:  29 04 18 93  sethi  %hi(0x10624c00), %l4
a0108778:  a4 5d c0 1d  smul  %l7, %i5, %l2
a010877c:  a6 15 21 d3  or  %l4, 0x1d3, %l3
a0108780:  80 54 80 13  umul  %l2, %l3, %g0
a0108784:  99 40 00 00  rd  %y, %o4
a0108788:  9b 33 20 06  srl  %o4, 6, %o5
a010878c:  e2 16 60 02  lduh  [ %i1 + 2 ], %l1
a0108790:  1f 34 6d c5  sethi  %hi(0xd1b71400), %o7
a0108794:  92 5b 40 11  smul  %o5, %l1, %o1
a0108798:  82 13 e3 59  or  %o7, 0x359, %g1
a010879c:  80 52 40 01  umul  %o1, %g1, %g0
a01087a0:  91 40 00 00  rd  %y, %o0
a01087a4:  80 a5 60 00  cmp  %l5, 0
a01087a8:  12 80 00 06  bne  0xa01087c0
a01087ac:  bb 32 20 0d  srl  %o0, 0xd, %i5
a01087b0:  11 33 c0 46  sethi  %hi(0xcf011800), %o0
a01087b4:  c2 02 00 00  ld  [ %o0 ], %g1
a01087b8:  92 08 7f ef  and  %g1, -17, %o1
a01087bc:  d2 22 00 00  st  %o1, [ %o0 ]
a01087c0:  93 2a a0 10  sll  %o2, 0x10, %o1
a01087c4:  91 32 60 10  srl  %o1, 0x10, %o0
a01087c8:  af 32 e0 10  srl  %o3, 0x10, %l7
a01087cc:  a8 5a 20 64  smul  %o0, 0x64, %l4
a01087d0:  81 80 00 00  mov  %g0, %y
a01087d4:  01 00 00 00  nop
a01087d8:  01 00 00 00  nop
a01087dc:  01 00 00 00  nop
a01087e0:  a6 75 00 17  udiv  %l4, %l7, %l3
a01087e4:  a5 2c e0 10  sll  %l3, 0x10, %l2
a01087e8:  19 14 7a e1  sethi  %hi(0x51eb8400), %o4
a01087ec:  a3 34 a0 10  srl  %l2, 0x10, %l1
a01087f0:  9a 13 21 1f  or  %o4, 0x11f, %o5
a01087f4:  80 54 40 0d  umul  %l1, %o5, %g0
a01087f8:  9f 40 00 00  rd  %y, %o7
a01087fc:  97 2b e0 0b  sll  %o7, 0xb, %o3
a0108800:  95 32 e0 11  srl  %o3, 0x11, %o2
a0108804:  80 a2 a0 00  cmp  %o2, 0
a0108808:  12 80 00 03  bne  0xa0108814
a010880c:  a6 10 00 0a  mov  %o2, %l3
a0108810:  a6 10 20 01  mov  1, %l3
a0108814:  90 10 00 18  mov  %i0, %o0
a0108818:  40 00 62 90  call  0xa0121258
a010881c:  a2 06 e0 14  add  %i3, 0x14, %l1
a0108820:  80 8a 20 ff  btst  0xff, %o0
a0108824:  02 80 00 22  be  0xa01088ac
a0108828:  ae 10 00 11  mov  %l1, %l7
a010882c:  80 8f 20 ff  btst  0xff, %i4
a0108830:  22 80 00 20  be,a   0xa01088b0
a0108834:  a3 3c 20 10  sra  %l0, 0x10, %l1
a0108838:  a1 3c 20 10  sra  %l0, 0x10, %l0
a010883c:  40 01 35 01  call  0xa0155c40
a0108840:  90 10 00 10  mov  %l0, %o0
a0108844:  80 a4 20 00  cmp  %l0, 0
a0108848:  06 80 01 73  bl  0xa0108e14
a010884c:  a4 10 00 08  mov  %o0, %l2
a0108850:  c2 16 60 0a  lduh  [ %i1 + 0xa ], %g1
a0108854:  40 01 34 fb  call  0xa0155c40
a0108858:  90 00 40 01  add  %g1, %g1, %o0
a010885c:  92 10 00 08  mov  %o0, %o1
a0108860:  40 01 33 f4  call  0xa0155830
a0108864:  90 10 00 12  mov  %l2, %o0
a0108868:  a4 10 00 08  mov  %o0, %l2
a010886c:  a9 2c e0 10  sll  %l3, 0x10, %l4
a0108870:  40 01 34 f4  call  0xa0155c40
a0108874:  91 35 20 10  srl  %l4, 0x10, %o0
a0108878:  92 10 00 08  mov  %o0, %o1
a010887c:  40 01 34 67  call  0xa0155a18
a0108880:  90 10 00 12  mov  %l2, %o0
a0108884:  a0 10 00 08  mov  %o0, %l0
a0108888:  10 80 00 1d  b  0xa01088fc
a010888c:  91 2c 60 10  sll  %l1, 0x10, %o0
a0108890:  d8 16 60 0e  lduh  [ %i1 + 0xe ], %o4
a0108894:  a5 32 e0 10  srl  %o3, 0x10, %l2
a0108898:  80 a3 00 12  cmp  %o4, %l2
a010889c:  12 bf ff ac  bne  0xa010874c
a01088a0:  94 10 00 0c  mov  %o4, %o2
a01088a4:  10 bf ff b1  b  0xa0108768
a01088a8:  c0 2f bf f7  clrb  [ %fp + -9 ]
a01088ac:  a3 3c 20 10  sra  %l0, 0x10, %l1
a01088b0:  40 01 34 e4  call  0xa0155c40
a01088b4:  90 10 00 11  mov  %l1, %o0
a01088b8:  80 a4 60 00  cmp  %l1, 0
a01088bc:  06 80 01 5b  bl  0xa0108e28
a01088c0:  a4 10 00 08  mov  %o0, %l2
a01088c4:  40 01 34 df  call  0xa0155c40
a01088c8:  d0 16 60 0a  lduh  [ %i1 + 0xa ], %o0
a01088cc:  92 10 00 08  mov  %o0, %o1
a01088d0:  40 01 33 d8  call  0xa0155830
a01088d4:  90 10 00 12  mov  %l2, %o0
a01088d8:  a0 10 00 08  mov  %o0, %l0
a01088dc:  a9 2c e0 10  sll  %l3, 0x10, %l4
a01088e0:  40 01 34 d8  call  0xa0155c40
a01088e4:  91 35 20 10  srl  %l4, 0x10, %o0
a01088e8:  92 10 00 08  mov  %o0, %o1
a01088ec:  40 01 34 4b  call  0xa0155a18
a01088f0:  90 10 00 10  mov  %l0, %o0
a01088f4:  a0 10 00 08  mov  %o0, %l0
a01088f8:  91 2d e0 10  sll  %l7, 0x10, %o0
a01088fc:  40 01 34 d1  call  0xa0155c40
a0108900:  91 32 20 10  srl  %o0, 0x10, %o0
a0108904:  92 10 00 08  mov  %o0, %o1
a0108908:  40 01 34 44  call  0xa0155a18
a010890c:  90 10 00 10  mov  %l0, %o0
a0108910:  40 01 35 20  call  0xa0155d90
a0108914:  01 00 00 00  nop
a0108918:  40 01 2f b1  call  0xa01547dc
a010891c:  01 00 00 00  nop
a0108920:  40 01 32 10  call  0xa0155160
a0108924:  01 00 00 00  nop
a0108928:  80 8a 20 01  btst  1, %o0
a010892c:  12 80 00 dd  bne  0xa0108ca0
a0108930:  93 2a 20 10  sll  %o0, 0x10, %o1
a0108934:  9a 22 00 1a  sub  %o0, %i2, %o5
a0108938:  9f 2b 60 10  sll  %o5, 0x10, %o7
a010893c:  17 2a aa aa  sethi  %hi(0xaaaaa800), %o3
a0108940:  b9 33 e0 10  srl  %o7, 0x10, %i4
a0108944:  a0 12 e2 ab  or  %o3, 0x2ab, %l0
a0108948:  80 57 00 10  umul  %i4, %l0, %g0
a010894c:  95 40 00 00  rd  %y, %o2
a0108950:  a7 32 a0 02  srl  %o2, 2, %l3
a0108954:  a2 04 c0 13  add  %l3, %l3, %l1
a0108958:  82 04 40 13  add  %l1, %l3, %g1
a010895c:  a4 00 40 01  add  %g1, %g1, %l2
a0108960:  98 27 00 12  sub  %i4, %l2, %o4
a0108964:  9b 2b 20 10  sll  %o4, 0x10, %o5
a0108968:  9f 2c e0 10  sll  %l3, 0x10, %o7
a010896c:  80 a3 60 00  cmp  %o5, 0
a0108970:  02 80 00 03  be  0xa010897c
a0108974:  a1 33 e0 0f  srl  %o7, 0xf, %l0
a0108978:  a0 04 20 02  add  %l0, 2, %l0
a010897c:  83 2f 60 10  sll  %i5, 0x10, %g1
a0108980:  98 02 3f f8  add  %o0, -8, %o4
a0108984:  b9 30 60 10  srl  %g1, 0x10, %i4
a0108988:  a5 35 20 10  srl  %l4, 0x10, %l2
a010898c:  81 80 00 00  mov  %g0, %y
a0108990:  01 00 00 00  nop
a0108994:  01 00 00 00  nop
a0108998:  01 00 00 00  nop
a010899c:  90 77 00 12  udiv  %i4, %l2, %o0
a01089a0:  ba 23 00 10  sub  %o4, %l0, %i5
a01089a4:  80 a2 20 27  cmp  %o0, 0x27
a01089a8:  18 80 00 a8  bgu  0xa0108c48
a01089ac:  98 27 40 1a  sub  %i5, %i2, %o4
a01089b0:  1b 33 c0 47  sethi  %hi(0xcf011c00), %o5
a01089b4:  e2 03 40 00  ld  [ %o5 ], %l1
a01089b8:  82 14 60 40  or  %l1, 0x40, %g1
a01089bc:  c2 23 40 00  st  %g1, [ %o5 ]
a01089c0:  a7 2b 20 10  sll  %o4, 0x10, %l3
a01089c4:  1b 00 00 07  sethi  %hi(0x1c00), %o5
a01089c8:  96 13 63 40  or  %o5, 0x340, %o3	! 0x1f40
a01089cc:  9f 34 e0 10  srl  %l3, 0x10, %o7
a01089d0:  80 a3 c0 0b  cmp  %o7, %o3
a01089d4:  08 80 00 05  bleu  0xa01089e8
a01089d8:  80 a5 60 01  cmp  %l5, 1
a01089dc:  a6 04 00 0c  add  %l0, %o4, %l3
a01089e0:  a0 24 c0 0b  sub  %l3, %o3, %l0
a01089e4:  27 07 d0 00  sethi  %hi(0x1f400000), %l3
a01089e8:  02 80 00 9c  be  0xa0108c58
a01089ec:  39 33 c0 47  sethi  %hi(0xcf011c00), %i4
a01089f0:  93 32 60 10  srl  %o1, 0x10, %o1
a01089f4:  7f ff a9 a6  call  0xa00f308c
a01089f8:  90 17 20 e0  or  %i4, 0xe0, %o0
a01089fc:  99 2d e0 10  sll  %l7, 0x10, %o4
a0108a00:  93 33 20 10  srl  %o4, 0x10, %o1
a0108a04:  7f ff a9 a2  call  0xa00f308c
a0108a08:  90 17 20 f8  or  %i4, 0xf8, %o0
a0108a0c:  a5 35 a0 10  srl  %l6, 0x10, %l2
a0108a10:  90 17 20 d8  or  %i4, 0xd8, %o0
a0108a14:  7f ff a9 9e  call  0xa00f308c
a0108a18:  92 10 00 12  mov  %l2, %o1
a0108a1c:  91 2e e0 10  sll  %i3, 0x10, %o0
a0108a20:  bb 32 20 10  srl  %o0, 0x10, %i5
a0108a24:  90 17 20 f0  or  %i4, 0xf0, %o0
a0108a28:  7f ff a9 99  call  0xa00f308c
a0108a2c:  92 10 00 1d  mov  %i5, %o1
a0108a30:  97 2c 20 10  sll  %l0, 0x10, %o3
a0108a34:  ab 32 e0 10  srl  %o3, 0x10, %l5
a0108a38:  92 10 00 15  mov  %l5, %o1
a0108a3c:  7f ff a9 94  call  0xa00f308c
a0108a40:  90 17 20 d0  or  %i4, 0xd0, %o0
a0108a44:  90 17 20 e8  or  %i4, 0xe8, %o0
a0108a48:  7f ff a9 91  call  0xa00f308c
a0108a4c:  92 10 20 08  mov  8, %o1
a0108a50:  90 17 22 80  or  %i4, 0x280, %o0
a0108a54:  7f ff a9 8e  call  0xa00f308c
a0108a58:  92 10 20 08  mov  8, %o1
a0108a5c:  93 34 e0 10  srl  %l3, 0x10, %o1
a0108a60:  7f ff a9 8b  call  0xa00f308c
a0108a64:  90 17 22 88  or  %i4, 0x288, %o0
a0108a68:  92 10 00 15  mov  %l5, %o1
a0108a6c:  7f ff a9 88  call  0xa00f308c
a0108a70:  90 17 22 90  or  %i4, 0x290, %o0
a0108a74:  92 10 00 12  mov  %l2, %o1
a0108a78:  7f ff a9 85  call  0xa00f308c
a0108a7c:  90 17 22 98  or  %i4, 0x298, %o0
a0108a80:  90 17 22 a0  or  %i4, 0x2a0, %o0
a0108a84:  7f ff a9 82  call  0xa00f308c
a0108a88:  92 10 20 08  mov  8, %o1
a0108a8c:  90 17 22 a8  or  %i4, 0x2a8, %o0
a0108a90:  7f ff a9 7f  call  0xa00f308c
a0108a94:  92 10 20 04  mov  4, %o1
a0108a98:  90 17 22 b0  or  %i4, 0x2b0, %o0
a0108a9c:  7f ff a9 7c  call  0xa00f308c
a0108aa0:  92 10 20 08  mov  8, %o1
a0108aa4:  92 10 00 1d  mov  %i5, %o1
a0108aa8:  7f ff a9 79  call  0xa00f308c
a0108aac:  90 17 22 b8  or  %i4, 0x2b8, %o0
a0108ab0:  a0 17 20 c0  or  %i4, 0xc0, %l0
a0108ab4:  c0 24 00 00  clr  [ %l0 ]
a0108ab8:  ee 16 60 3a  lduh  [ %i1 + 0x3a ], %l7
a0108abc:  13 3f ff e0  sethi  %hi(0xffff8000), %o1
a0108ac0:  b6 0d c0 09  and  %l7, %o1, %i3
a0108ac4:  ab 2e e0 10  sll  %i3, 0x10, %l5
a0108ac8:  80 a5 60 00  cmp  %l5, 0
a0108acc:  02 80 00 85  be  0xa0108ce0
a0108ad0:  9e 17 20 c4  or  %i4, 0xc4, %o7
a0108ad4:  a2 17 20 c4  or  %i4, 0xc4, %l1
a0108ad8:  82 10 20 20  mov  0x20, %g1
a0108adc:  c2 24 40 00  st  %g1, [ %l1 ]
a0108ae0:  98 17 22 c0  or  %i4, 0x2c0, %o4
a0108ae4:  f8 03 00 00  ld  [ %o4 ], %i4
a0108ae8:  82 0f 3f 7f  and  %i4, -129, %g1
a0108aec:  2f 33 c0 47  sethi  %hi(0xcf011c00), %l7
a0108af0:  c2 23 00 00  st  %g1, [ %o4 ]
a0108af4:  b6 15 e0 c8  or  %l7, 0xc8, %i3
a0108af8:  c0 26 c0 00  clr  [ %i3 ]
a0108afc:  67 fe 11 a9  call  0x4008d1a0
a0108b00:  90 10 20 64  mov  0x64, %o0
a0108b04:  e6 0f bf f7  ldub  [ %fp + -9 ], %l3
a0108b08:  80 8c e0 ff  btst  0xff, %l3
a0108b0c:  12 80 00 85  bne  0xa0108d20
a0108b10:  bb 35 20 10  srl  %l4, 0x10, %i5
a0108b14:  d6 16 60 3a  lduh  [ %i1 + 0x3a ], %o3
a0108b18:  11 3f ff e0  sethi  %hi(0xffff8000), %o0
a0108b1c:  aa 0a c0 08  and  %o3, %o0, %l5
a0108b20:  a5 2d 60 10  sll  %l5, 0x10, %l2
a0108b24:  80 a4 a0 00  cmp  %l2, 0
a0108b28:  12 80 00 84  bne  0xa0108d38
a0108b2c:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a0108b30:  1f 33 c0 45  sethi  %hi(0xcf011400), %o7
a0108b34:  94 13 e2 d0  or  %o7, 0x2d0, %o2	! 0xcf0116d0
a0108b38:  c0 22 80 00  clr  [ %o2 ]
a0108b3c:  03 00 06 6a  sethi  %hi(0x19a800), %g1
a0108b40:  90 10 63 e8  or  %g1, 0x3e8, %o0	! 0x19abe8
a0108b44:  92 10 20 04  mov  4, %o1
a0108b48:  7f ff 59 8a  call  0xa00df170
a0108b4c:  94 10 20 00  clr  %o2
a0108b50:  21 33 c0 46  sethi  %hi(0xcf011800), %l0
a0108b54:  98 14 23 f8  or  %l0, 0x3f8, %o4	! 0xcf011bf8
a0108b58:  e2 03 00 00  ld  [ %o4 ], %l1
a0108b5c:  b8 0c 7f ef  and  %l1, -17, %i4
a0108b60:  f8 23 00 00  st  %i4, [ %o4 ]
a0108b64:  aa 14 22 00  or  %l0, 0x200, %l5
a0108b68:  d0 05 40 00  ld  [ %l5 ], %o0
a0108b6c:  96 0a 3f ef  and  %o0, -17, %o3
a0108b70:  d6 25 40 00  st  %o3, [ %l5 ]
a0108b74:  e4 04 00 00  ld  [ %l0 ], %l2
a0108b78:  ba 0c bf ef  and  %l2, -17, %i5
a0108b7c:  fa 24 00 00  st  %i5, [ %l0 ]
a0108b80:  f6 16 60 3a  lduh  [ %i1 + 0x3a ], %i3
a0108b84:  2f 3f ff e0  sethi  %hi(0xffff8000), %l7
a0108b88:  a6 0e c0 17  and  %i3, %l7, %l3
a0108b8c:  9b 2c e0 10  sll  %l3, 0x10, %o5
a0108b90:  80 a3 60 00  cmp  %o5, 0
a0108b94:  22 80 00 84  be,a   0xa0108da4
a0108b98:  03 33 c0 47  sethi  %hi(0xcf011c00), %g1
a0108b9c:  11 33 c0 46  sethi  %hi(0xcf011800), %o0
a0108ba0:  a2 12 22 84  or  %o0, 0x284, %l1	! 0xcf011a84
a0108ba4:  d4 04 40 00  ld  [ %l1 ], %o2
a0108ba8:  82 12 a0 10  or  %o2, 0x10, %g1
a0108bac:  c2 24 40 00  st  %g1, [ %l1 ]
a0108bb0:  96 12 22 88  or  %o0, 0x288, %o3
a0108bb4:  f8 02 c0 00  ld  [ %o3 ], %i4
a0108bb8:  98 17 20 10  or  %i4, 0x10, %o4
a0108bbc:  d8 22 c0 00  st  %o4, [ %o3 ]
a0108bc0:  ba 12 22 8c  or  %o0, 0x28c, %i5
a0108bc4:  ea 07 40 00  ld  [ %i5 ], %l5
a0108bc8:  a4 0d 7f ef  and  %l5, -17, %l2
a0108bcc:  17 33 c0 47  sethi  %hi(0xcf011c00), %o3
a0108bd0:  e4 27 40 00  st  %l2, [ %i5 ]
a0108bd4:  a8 12 e1 c8  or  %o3, 0x1c8, %l4
a0108bd8:  e0 05 00 00  ld  [ %l4 ], %l0
a0108bdc:  92 0c 3f ef  and  %l0, -17, %o1
a0108be0:  b1 35 a0 10  srl  %l6, 0x10, %i0
a0108be4:  d2 25 00 00  st  %o1, [ %l4 ]
a0108be8:  80 8e 20 1f  btst  0x1f, %i0
a0108bec:  02 80 00 06  be  0xa0108c04
a0108bf0:  82 10 20 00  clr  %g1
a0108bf4:  9b 35 a0 15  srl  %l6, 0x15, %o5
a0108bf8:  9f 2b 60 05  sll  %o5, 5, %o7
a0108bfc:  ac 23 c0 1a  sub  %o7, %i2, %l6
a0108c00:  82 05 a0 20  add  %l6, 0x20, %g1
a0108c04:  b4 12 e1 dc  or  %o3, 0x1dc, %i2
a0108c08:  a6 08 60 ff  and  %g1, 0xff, %l3
a0108c0c:  e6 26 80 00  st  %l3, [ %i2 ]
a0108c10:  f0 16 60 0a  lduh  [ %i1 + 0xa ], %i0
a0108c14:  33 33 c0 47  sethi  %hi(0xcf011c00), %i1
a0108c18:  93 36 20 02  srl  %i0, 2, %o1
a0108c1c:  7f ff a9 1c  call  0xa00f308c
a0108c20:  90 16 61 08  or  %i1, 0x108, %o0
a0108c24:  90 16 61 00  or  %i1, 0x100, %o0
a0108c28:  7f ff a9 19  call  0xa00f308c
a0108c2c:  92 10 20 00  clr  %o1
a0108c30:  90 16 61 18  or  %i1, 0x118, %o0
a0108c34:  92 10 20 00  clr  %o1
a0108c38:  7f ff a9 15  call  0xa00f308c
a0108c3c:  b0 16 61 10  or  %i1, 0x110, %i0
a0108c40:  7f ff a9 13  call  0xa00f308c
a0108c44:  93 e8 20 00  restore  %g0, 0, %o1
a0108c48:  1b 33 c0 47  sethi  %hi(0xcf011c00), %o5
a0108c4c:  d4 03 40 00  ld  [ %o5 ], %o2
a0108c50:  10 bf ff 5b  b  0xa01089bc
a0108c54:  82 0a bf bf  and  %o2, -65, %g1
a0108c58:  31 33 c0 47  sethi  %hi(0xcf011c00), %i0
a0108c5c:  90 16 20 e0  or  %i0, 0xe0, %o0	! 0xcf011ce0
a0108c60:  93 32 60 10  srl  %o1, 0x10, %o1
a0108c64:  7f ff a9 0a  call  0xa00f308c
a0108c68:  b3 2c 20 10  sll  %l0, 0x10, %i1
a0108c6c:  b3 36 60 10  srl  %i1, 0x10, %i1
a0108c70:  90 16 20 d0  or  %i0, 0xd0, %o0
a0108c74:  7f ff a9 06  call  0xa00f308c
a0108c78:  92 10 00 19  mov  %i1, %o1
a0108c7c:  90 16 22 80  or  %i0, 0x280, %o0
a0108c80:  7f ff a9 03  call  0xa00f308c
a0108c84:  92 10 20 08  mov  8, %o1
a0108c88:  90 16 22 88  or  %i0, 0x288, %o0
a0108c8c:  7f ff a9 00  call  0xa00f308c
a0108c90:  93 34 e0 10  srl  %l3, 0x10, %o1
a0108c94:  b0 16 22 90  or  %i0, 0x290, %i0
a0108c98:  7f ff a8 fd  call  0xa00f308c
a0108c9c:  81 e8 00 00  restore
a0108ca0:  96 02 20 01  add  %o0, 1, %o3
a0108ca4:  93 2a e0 10  sll  %o3, 0x10, %o1
a0108ca8:  10 bf ff 23  b  0xa0108934
a0108cac:  90 10 00 0b  mov  %o3, %o0
a0108cb0:  80 8e e0 01  btst  1, %i3
a0108cb4:  12 80 00 54  bne  0xa0108e04
a0108cb8:  83 2e e0 10  sll  %i3, 0x10, %g1
a0108cbc:  80 8e a0 07  btst  7, %i2
a0108cc0:  02 bf fe 9d  be  0xa0108734
a0108cc4:  ad 2e a0 10  sll  %i2, 0x10, %l6
a0108cc8:  9b 35 a0 13  srl  %l6, 0x13, %o5
a0108ccc:  97 2b 60 03  sll  %o5, 3, %o3
a0108cd0:  94 02 e0 08  add  %o3, 8, %o2
a0108cd4:  ad 2a a0 10  sll  %o2, 0x10, %l6
a0108cd8:  10 bf fe 97  b  0xa0108734
a0108cdc:  b4 10 00 0a  mov  %o2, %i2
a0108ce0:  9a 10 20 a0  mov  0xa0, %o5
a0108ce4:  da 23 c0 00  st  %o5, [ %o7 ]
a0108ce8:  98 17 22 c0  or  %i4, 0x2c0, %o4
a0108cec:  d4 03 00 00  ld  [ %o4 ], %o2
a0108cf0:  82 12 a0 80  or  %o2, 0x80, %g1
a0108cf4:  2f 33 c0 47  sethi  %hi(0xcf011c00), %l7
a0108cf8:  c2 23 00 00  st  %g1, [ %o4 ]
a0108cfc:  b6 15 e0 c8  or  %l7, 0xc8, %i3
a0108d00:  c0 26 c0 00  clr  [ %i3 ]
a0108d04:  67 fe 11 27  call  0x4008d1a0
a0108d08:  90 10 20 64  mov  0x64, %o0
a0108d0c:  e6 0f bf f7  ldub  [ %fp + -9 ], %l3
a0108d10:  80 8c e0 ff  btst  0xff, %l3
a0108d14:  22 bf ff 81  be,a   0xa0108b18
a0108d18:  d6 16 60 3a  lduh  [ %i1 + 0x3a ], %o3
a0108d1c:  bb 35 20 10  srl  %l4, 0x10, %i5
a0108d20:  21 33 c0 45  sethi  %hi(0xcf011400), %l0
a0108d24:  92 07 7f ff  add  %i5, -1, %o1
a0108d28:  a8 14 22 d0  or  %l0, 0x2d0, %l4
a0108d2c:  d2 25 00 00  st  %o1, [ %l4 ]
a0108d30:  10 80 00 05  b  0xa0108d44
a0108d34:  13 00 06 6a  sethi  %hi(0x19a800), %o1
a0108d38:  98 17 22 d0  or  %i4, 0x2d0, %o4
a0108d3c:  c0 23 00 00  clr  [ %o4 ]
a0108d40:  13 00 06 6a  sethi  %hi(0x19a800), %o1
a0108d44:  90 12 63 e8  or  %o1, 0x3e8, %o0	! 0x19abe8
a0108d48:  94 10 20 01  mov  1, %o2
a0108d4c:  7f ff 59 09  call  0xa00df170
a0108d50:  92 10 20 04  mov  4, %o1
a0108d54:  1f 33 c0 46  sethi  %hi(0xcf011800), %o7
a0108d58:  e8 03 c0 00  ld  [ %o7 ], %l4
a0108d5c:  ae 15 20 10  or  %l4, 0x10, %l7
a0108d60:  ee 23 c0 00  st  %l7, [ %o7 ]
a0108d64:  9a 13 e2 00  or  %o7, 0x200, %o5
a0108d68:  f6 03 40 00  ld  [ %o5 ], %i3
a0108d6c:  a6 16 e0 10  or  %i3, 0x10, %l3
a0108d70:  e6 23 40 00  st  %l3, [ %o5 ]
a0108d74:  a2 13 e3 f8  or  %o7, 0x3f8, %l1
a0108d78:  d4 04 40 00  ld  [ %l1 ], %o2
a0108d7c:  82 12 a0 10  or  %o2, 0x10, %g1
a0108d80:  c2 24 40 00  st  %g1, [ %l1 ]
a0108d84:  f6 16 60 3a  lduh  [ %i1 + 0x3a ], %i3
a0108d88:  2f 3f ff e0  sethi  %hi(0xffff8000), %l7
a0108d8c:  a6 0e c0 17  and  %i3, %l7, %l3
a0108d90:  9b 2c e0 10  sll  %l3, 0x10, %o5
a0108d94:  80 a3 60 00  cmp  %o5, 0
a0108d98:  32 bf ff 82  bne,a   0xa0108ba0
a0108d9c:  11 33 c0 46  sethi  %hi(0xcf011800), %o0
a0108da0:  03 33 c0 47  sethi  %hi(0xcf011c00), %g1
a0108da4:  98 10 61 c8  or  %g1, 0x1c8, %o4	! 0xcf011dc8
a0108da8:  e2 03 00 00  ld  [ %o4 ], %l1
a0108dac:  13 33 c0 46  sethi  %hi(0xcf011800), %o1
a0108db0:  b8 0c 7f ef  and  %l1, -17, %i4
a0108db4:  f8 23 00 00  st  %i4, [ %o4 ]
a0108db8:  aa 12 62 84  or  %o1, 0x284, %l5
a0108dbc:  d6 05 40 00  ld  [ %l5 ], %o3
a0108dc0:  90 12 e0 10  or  %o3, 0x10, %o0
a0108dc4:  d0 25 40 00  st  %o0, [ %l5 ]
a0108dc8:  a0 12 62 88  or  %o1, 0x288, %l0
a0108dcc:  e4 04 00 00  ld  [ %l0 ], %l2
a0108dd0:  ba 0c bf ef  and  %l2, -17, %i5
a0108dd4:  b6 12 62 8c  or  %o1, 0x28c, %i3
a0108dd8:  fa 24 00 00  st  %i5, [ %l0 ]
a0108ddc:  e8 06 c0 00  ld  [ %i3 ], %l4
a0108de0:  ae 0d 3f ef  and  %l4, -17, %l7
a0108de4:  ee 26 c0 00  st  %l7, [ %i3 ]
a0108de8:  90 10 00 18  mov  %i0, %o0
a0108dec:  92 10 20 90  mov  0x90, %o1
a0108df0:  94 10 20 20  mov  0x20, %o2
a0108df4:  7f ff a5 4e  call  0xa00f232c
a0108df8:  96 10 20 01  mov  1, %o3
a0108dfc:  10 bf ff 86  b  0xa0108c14
a0108e00:  f0 16 60 0a  lduh  [ %i1 + 0xa ], %i0
a0108e04:  93 30 60 11  srl  %g1, 0x11, %o1
a0108e08:  82 02 40 09  add  %o1, %o1, %g1
a0108e0c:  10 bf ff ac  b  0xa0108cbc
a0108e10:  b6 00 60 02  add  %g1, 2, %i3
a0108e14:  39 00 06 68  sethi  %hi(0x19a000), %i4
a0108e18:  40 01 32 5d  call  0xa015578c
a0108e1c:  d2 07 22 d0  ld  [ %i4 + 0x2d0 ], %o1	! 0x19a2d0
a0108e20:  10 bf fe 8c  b  0xa0108850
a0108e24:  a4 10 00 08  mov  %o0, %l2
a0108e28:  15 00 06 68  sethi  %hi(0x19a000), %o2
a0108e2c:  40 01 32 58  call  0xa015578c
a0108e30:  d2 02 a2 d0  ld  [ %o2 + 0x2d0 ], %o1	! 0x19a2d0
a0108e34:  10 bf fe a4  b  0xa01088c4
a0108e38:  a4 10 00 08  mov  %o0, %l2
a0108e3c:  7f ff a9 bb  call  0xa00f3528
a0108e40:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0108e44:  10 bf fe 35  b  0xa0108718
a0108e48:  a0 10 00 08  mov  %o0, %l0
