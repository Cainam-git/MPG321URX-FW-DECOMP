# leon2m FUN_a015373c 0xa015373c-0xa0153970 (356 bytes)
a015373c:  9d e3 bf 48  save  %sp, -184, %sp
a0153740:  7f ff 42 af  call  0xa01241fc
a0153744:  01 00 00 00  nop
a0153748:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a015374c:  de 02 00 00  ld  [ %o0 ], %o7
a0153750:  a2 10 00 08  mov  %o0, %l1
a0153754:  96 12 a1 a0  or  %o2, 0x1a0, %o3
a0153758:  93 33 e0 19  srl  %o7, 0x19, %o1
a015375c:  d0 0a a1 a3  ldub  [ %o2 + 0x1a3 ], %o0
a0153760:  d6 02 e0 04  ld  [ %o3 + 4 ], %o3
a0153764:  9a 0a 60 01  and  %o1, 1, %o5
a0153768:  83 2a 20 08  sll  %o0, 8, %g1
a015376c:  99 32 e0 18  srl  %o3, 0x18, %o4
a0153770:  98 93 00 01  orcc  %o4, %g1, %o4
a0153774:  02 80 00 21  be  0xa01537f8
a0153778:  da 2f bf d2  stb  %o5, [ %fp + -46 ]
a015377c:  a1 32 e0 08  srl  %o3, 8, %l0
a0153780:  82 10 20 01  mov  1, %g1
a0153784:  c2 2f bf d0  stb  %g1, [ %fp + -48 ]
a0153788:  d8 37 bf e0  sth  %o4, [ %fp + -32 ]
a015378c:  e0 37 bf e2  sth  %l0, [ %fp + -30 ]
a0153790:  d8 0c 60 07  ldub  [ %l1 + 7 ], %o4
a0153794:  80 a3 20 0a  cmp  %o4, 0xa
a0153798:  02 80 00 1e  be  0xa0153810
a015379c:  9a 10 20 02  mov  2, %o5
a01537a0:  c0 27 bf d4  clr  [ %fp + -44 ]
a01537a4:  7f ff 42 96  call  0xa01241fc
a01537a8:  a0 10 20 00  clr  %l0
a01537ac:  d2 0a 20 06  ldub  [ %o0 + 6 ], %o1
a01537b0:  96 0a 60 ff  and  %o1, 0xff, %o3
a01537b4:  82 02 ff f0  add  %o3, -16, %g1
a01537b8:  80 a0 60 32  cmp  %g1, 0x32
a01537bc:  38 80 00 44  bgu,a   0xa01538cc
a01537c0:  de 02 00 00  ld  [ %o0 ], %o7
a01537c4:  1b 00 03 c4  sethi  %hi(0xf1000), %o5
a01537c8:  9f 28 60 02  sll  %g1, 2, %o7
a01537cc:  98 13 62 8c  or  %o5, 0x28c, %o4
a01537d0:  d4 03 00 0f  ld  [ %o4 + %o7 ], %o2
a01537d4:  81 c2 80 00  jmp  %o2
a01537d8:  01 00 00 00  nop
a01537dc:  c2 02 00 00  ld  [ %o0 ], %g1
a01537e0:  1b 00 03 80  sethi  %hi(0xe0000), %o5
a01537e4:  98 08 40 0d  and  %g1, %o5, %o4
a01537e8:  80 a0 00 0c  cmp  %g0, %o4
a01537ec:  9e 10 20 06  mov  6, %o7
a01537f0:  10 80 00 36  b  0xa01538c8
a01537f4:  a0 63 e0 00  subx  %o7, 0, %l0
a01537f8:  c0 2f bf d0  clrb  [ %fp + -48 ]
a01537fc:  d8 0c 60 07  ldub  [ %l1 + 7 ], %o4
a0153800:  80 a3 20 0a  cmp  %o4, 0xa
a0153804:  32 bf ff e8  bne,a   0xa01537a4
a0153808:  c0 27 bf d4  clr  [ %fp + -44 ]
a015380c:  9a 10 20 02  mov  2, %o5
a0153810:  10 bf ff e5  b  0xa01537a4
a0153814:  da 27 bf d4  st  %o5, [ %fp + -44 ]
a0153818:  d8 02 00 00  ld  [ %o0 ], %o4
a015381c:  1b 00 03 80  sethi  %hi(0xe0000), %o5
a0153820:  82 0b 00 0d  and  %o4, %o5, %g1
a0153824:  1f 00 01 00  sethi  %hi(0x40000), %o7
a0153828:  80 a0 40 0f  cmp  %g1, %o7
a015382c:  02 80 00 27  be  0xa01538c8
a0153830:  a0 10 20 0d  mov  0xd, %l0
a0153834:  80 a0 00 01  cmp  %g0, %g1
a0153838:  82 10 20 0c  mov  0xc, %g1
a015383c:  10 80 00 23  b  0xa01538c8
a0153840:  a0 60 60 00  subx  %g1, 0, %l0
a0153844:  10 80 00 21  b  0xa01538c8
a0153848:  a0 10 20 01  mov  1, %l0
a015384c:  de 02 00 00  ld  [ %o0 ], %o7
a0153850:  19 00 03 80  sethi  %hi(0xe0000), %o4
a0153854:  96 0b c0 0c  and  %o7, %o4, %o3
a0153858:  15 00 00 80  sethi  %hi(0x20000), %o2
a015385c:  a0 1a c0 0a  xor  %o3, %o2, %l0
a0153860:  80 a0 00 10  cmp  %g0, %l0
a0153864:  82 40 20 00  addx  %g0, 0, %g1
a0153868:  10 80 00 19  b  0xa01538cc
a015386c:  a0 00 60 03  add  %g1, 3, %l0
a0153870:  10 80 00 16  b  0xa01538c8
a0153874:  a0 10 20 05  mov  5, %l0
a0153878:  d6 02 00 00  ld  [ %o0 ], %o3
a015387c:  15 00 03 80  sethi  %hi(0xe0000), %o2
a0153880:  a0 0a c0 0a  and  %o3, %o2, %l0
a0153884:  80 a0 00 10  cmp  %g0, %l0
a0153888:  82 60 20 00  subx  %g0, 0, %g1
a015388c:  9a 08 7f f7  and  %g1, -9, %o5
a0153890:  10 80 00 0e  b  0xa01538c8
a0153894:  a0 03 60 11  add  %o5, 0x11, %l0
a0153898:  10 80 00 0c  b  0xa01538c8
a015389c:  a0 10 20 0e  mov  0xe, %l0
a01538a0:  d6 02 00 00  ld  [ %o0 ], %o3
a01538a4:  15 00 03 80  sethi  %hi(0xe0000), %o2
a01538a8:  21 00 01 00  sethi  %hi(0x40000), %l0
a01538ac:  82 0a c0 0a  and  %o3, %o2, %g1
a01538b0:  80 a0 40 10  cmp  %g1, %l0
a01538b4:  02 80 00 05  be  0xa01538c8
a01538b8:  a0 10 20 0a  mov  0xa, %l0
a01538bc:  80 a0 00 01  cmp  %g0, %g1
a01538c0:  82 10 20 09  mov  9, %g1
a01538c4:  a0 60 60 00  subx  %g1, 0, %l0
a01538c8:  de 02 00 00  ld  [ %o0 ], %o7
a01538cc:  17 00 06 9d  sethi  %hi(0x1a7400), %o3
a01538d0:  95 33 e0 11  srl  %o7, 0x11, %o2
a01538d4:  90 12 e0 f0  or  %o3, 0xf0, %o0
a01538d8:  96 10 00 10  mov  %l0, %o3
a01538dc:  92 0a 60 ff  and  %o1, 0xff, %o1
a01538e0:  7f fe 2e 24  call  0xa00df170
a01538e4:  94 0a a0 07  and  %o2, 7, %o2
a01538e8:  e0 27 bf d8  st  %l0, [ %fp + -40 ]
a01538ec:  d2 04 60 54  ld  [ %l1 + 0x54 ], %o1
a01538f0:  a1 32 60 16  srl  %o1, 0x16, %l0
a01538f4:  83 32 60 1f  srl  %o1, 0x1f, %g1
a01538f8:  9a 0c 20 80  and  %l0, 0x80, %o5
a01538fc:  99 28 60 05  sll  %g1, 5, %o4
a0153900:  91 32 60 1a  srl  %o1, 0x1a, %o0
a0153904:  94 13 40 0c  or  %o5, %o4, %o2
a0153908:  9e 0a 20 10  and  %o0, 0x10, %o7
a015390c:  96 12 80 0f  or  %o2, %o7, %o3
a0153910:  d6 2f bf dc  stb  %o3, [ %fp + -36 ]
a0153914:  e0 04 60 54  ld  [ %l1 + 0x54 ], %l0
a0153918:  83 34 20 15  srl  %l0, 0x15, %g1
a015391c:  92 08 60 c0  and  %g1, 0xc0, %o1
a0153920:  d2 2f bf dd  stb  %o1, [ %fp + -35 ]
a0153924:  d0 0c 60 55  ldub  [ %l1 + 0x55 ], %o0
a0153928:  d8 1f bf d0  ldd  [ %fp + -48 ], %o4
a015392c:  d4 1f bf d8  ldd  [ %fp + -40 ], %o2
a0153930:  d0 2f bf e4  stb  %o0, [ %fp + -28 ]
a0153934:  d8 3f bf a8  std  %o4, [ %fp + -88 ]
a0153938:  d4 3f bf b0  std  %o2, [ %fp + -80 ]
a015393c:  d8 1f bf e0  ldd  [ %fp + -32 ], %o4
a0153940:  d4 1f bf e8  ldd  [ %fp + -24 ], %o2
a0153944:  e2 07 bf f0  ld  [ %fp + -16 ], %l1
a0153948:  d8 3f bf b8  std  %o4, [ %fp + -72 ]
a015394c:  d4 3f bf c0  std  %o2, [ %fp + -64 ]
a0153950:  90 07 bf a8  add  %fp, -88, %o0
a0153954:  7f fe cd 04  call  0xa0106d64
a0153958:  e2 27 bf c8  st  %l1, [ %fp + -56 ]
a015395c:  7f ff 98 35  call  0xa0139a30
a0153960:  01 00 00 00  nop
a0153964:  01 00 00 00  nop
a0153968:  81 c7 e0 08  ret
a015396c:  81 e8 00 00  restore
