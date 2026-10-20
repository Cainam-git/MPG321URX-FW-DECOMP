# leon2m FUN_a0141840 0xa0141840-0xa0141964 (292 bytes)
a0141840:  9d e3 be e8  save  %sp, -280, %sp
a0141844:  7f ff 8a 6e  call  0xa01241fc
a0141848:  01 00 00 00  nop
a014184c:  96 10 20 00  clr  %o3	! 0x0
a0141850:  98 10 20 00  clr  %o4
a0141854:  94 07 bf f8  add  %fp, -8, %o2
a0141858:  da 0b 00 08  ldub  [ %o4 + %o0 ], %o5
a014185c:  82 02 80 0c  add  %o2, %o4, %g1
a0141860:  96 02 e0 01  inc  %o3
a0141864:  98 0a e0 ff  and  %o3, 0xff, %o4
a0141868:  80 a3 20 57  cmp  %o4, 0x57
a014186c:  08 bf ff fb  bleu  0xa0141858
a0141870:  da 28 7f a8  stb  %o5, [ %g1 + -88 ]
a0141874:  d2 02 00 00  ld  [ %o0 ], %o1
a0141878:  91 32 60 14  srl  %o1, 0x14, %o0
a014187c:  82 0a 20 07  and  %o0, 7, %g1
a0141880:  80 a0 60 01  cmp  %g1, 1
a0141884:  22 80 00 08  be,a   0xa01418a4
a0141888:  19 00 1c 00  sethi  %hi(0x700000), %o4
a014188c:  04 80 00 10  ble  0xa01418cc
a0141890:  80 a0 60 02  cmp  %g1, 2
a0141894:  12 80 00 14  bne  0xa01418e4
a0141898:  03 00 1c 00  sethi  %hi(0x700000), %g1
a014189c:  10 80 00 08  b  0xa01418bc
a01418a0:  da 07 bf a0  ld  [ %fp + -96 ], %o5
a01418a4:  de 07 bf a0  ld  [ %fp + -96 ], %o7
a01418a8:  82 2b c0 0c  andn  %o7, %o4, %g1
a01418ac:  19 00 08 00  sethi  %hi(0x200000), %o4
a01418b0:  82 10 40 0c  or  %g1, %o4, %g1
a01418b4:  10 80 00 0c  b  0xa01418e4
a01418b8:  c2 27 bf a0  st  %g1, [ %fp + -96 ]
a01418bc:  82 2b 40 01  andn  %o5, %g1, %g1
a01418c0:  19 00 04 00  sethi  %hi(0x100000), %o4
a01418c4:  10 bf ff fc  b  0xa01418b4
a01418c8:  82 10 40 0c  or  %g1, %o4, %g1
a01418cc:  80 a0 60 00  cmp  %g1, 0
a01418d0:  12 80 00 05  bne  0xa01418e4
a01418d4:  d6 07 bf a0  ld  [ %fp + -96 ], %o3
a01418d8:  15 00 1c 00  sethi  %hi(0x700000), %o2
a01418dc:  82 2a c0 0a  andn  %o3, %o2, %g1
a01418e0:  c2 27 bf a0  st  %g1, [ %fp + -96 ]
a01418e4:  40 00 40 e8  call  0xa0151c84
a01418e8:  01 00 00 00  nop
a01418ec:  d0 2f bf a6  stb  %o0, [ %fp + -90 ]
a01418f0:  d8 1f bf a0  ldd  [ %fp + -96 ], %o4
a01418f4:  d8 3f bf 48  std  %o4, [ %fp + -184 ]
a01418f8:  d4 1f bf a8  ldd  [ %fp + -88 ], %o2
a01418fc:  d8 1f bf b0  ldd  [ %fp + -80 ], %o4
a0141900:  d4 3f bf 50  std  %o2, [ %fp + -176 ]
a0141904:  d8 3f bf 58  std  %o4, [ %fp + -168 ]
a0141908:  d4 1f bf b8  ldd  [ %fp + -72 ], %o2
a014190c:  d8 1f bf c0  ldd  [ %fp + -64 ], %o4
a0141910:  d4 3f bf 60  std  %o2, [ %fp + -160 ]
a0141914:  d8 3f bf 68  std  %o4, [ %fp + -152 ]
a0141918:  d4 1f bf c8  ldd  [ %fp + -56 ], %o2
a014191c:  d8 1f bf d0  ldd  [ %fp + -48 ], %o4
a0141920:  d4 3f bf 70  std  %o2, [ %fp + -144 ]
a0141924:  d8 3f bf 78  std  %o4, [ %fp + -136 ]
a0141928:  d4 1f bf d8  ldd  [ %fp + -40 ], %o2
a014192c:  d8 1f bf e0  ldd  [ %fp + -32 ], %o4
a0141930:  d4 3f bf 80  std  %o2, [ %fp + -128 ]
a0141934:  d8 3f bf 88  std  %o4, [ %fp + -120 ]
a0141938:  d4 1f bf e8  ldd  [ %fp + -24 ], %o2
a014193c:  d8 1f bf f0  ldd  [ %fp + -16 ], %o4
a0141940:  d4 3f bf 90  std  %o2, [ %fp + -112 ]
a0141944:  d8 3f bf 98  std  %o4, [ %fp + -104 ]
a0141948:  7f ff 10 b1  call  0xa0105c0c
a014194c:  90 07 bf 48  add  %fp, -184, %o0
a0141950:  40 00 47 7b  call  0xa015373c
a0141954:  01 00 00 00  nop
a0141958:  01 00 00 00  nop
a014195c:  81 c7 e0 08  ret
a0141960:  81 e8 00 00  restore
