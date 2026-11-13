# leon2m FUN_a0141964 0xa0141964-0xa0141a98 (308 bytes)
a0141964:  9d e3 be e8  save  %sp, -280, %sp
a0141968:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014196c:  98 10 61 10  or  %g1, 0x110, %o4	! 0xa802e110
a0141970:  9a 10 20 01  mov  1, %o5
a0141974:  c0 33 20 02  clrh  [ %o4 + 2 ]
a0141978:  7f ff 8a 21  call  0xa01241fc
a014197c:  da 28 61 10  stb  %o5, [ %g1 + 0x110 ]
a0141980:  96 10 20 00  clr  %o3
a0141984:  98 10 20 00  clr  %o4
a0141988:  94 07 bf f8  add  %fp, -8, %o2
a014198c:  de 0b 00 08  ldub  [ %o4 + %o0 ], %o7
a0141990:  92 02 80 0c  add  %o2, %o4, %o1
a0141994:  96 02 e0 01  inc  %o3
a0141998:  98 0a e0 ff  and  %o3, 0xff, %o4
a014199c:  80 a3 20 57  cmp  %o4, 0x57
a01419a0:  08 bf ff fb  bleu  0xa014198c
a01419a4:  de 2a 7f a8  stb  %o7, [ %o1 + -88 ]
a01419a8:  d4 02 00 00  ld  [ %o0 ], %o2
a01419ac:  91 32 a0 14  srl  %o2, 0x14, %o0
a01419b0:  82 0a 20 07  and  %o0, 7, %g1
a01419b4:  80 a0 60 01  cmp  %g1, 1
a01419b8:  22 80 00 08  be,a   0xa01419d8
a01419bc:  03 00 1c 00  sethi  %hi(0x700000), %g1
a01419c0:  04 80 00 10  ble  0xa0141a00
a01419c4:  80 a0 60 02  cmp  %g1, 2
a01419c8:  12 80 00 14  bne  0xa0141a18
a01419cc:  13 00 1c 00  sethi  %hi(0x700000), %o1
a01419d0:  10 80 00 08  b  0xa01419f0
a01419d4:  de 07 bf a0  ld  [ %fp + -96 ], %o7
a01419d8:  da 07 bf a0  ld  [ %fp + -96 ], %o5
a01419dc:  82 2b 40 01  andn  %o5, %g1, %g1
a01419e0:  19 00 08 00  sethi  %hi(0x200000), %o4
a01419e4:  82 10 40 0c  or  %g1, %o4, %g1
a01419e8:  10 80 00 0c  b  0xa0141a18
a01419ec:  c2 27 bf a0  st  %g1, [ %fp + -96 ]
a01419f0:  82 2b c0 09  andn  %o7, %o1, %g1
a01419f4:  19 00 04 00  sethi  %hi(0x100000), %o4
a01419f8:  10 bf ff fc  b  0xa01419e8
a01419fc:  82 10 40 0c  or  %g1, %o4, %g1
a0141a00:  80 a0 60 00  cmp  %g1, 0
a0141a04:  12 80 00 05  bne  0xa0141a18
a0141a08:  d8 07 bf a0  ld  [ %fp + -96 ], %o4
a0141a0c:  17 00 1c 00  sethi  %hi(0x700000), %o3
a0141a10:  82 2b 00 0b  andn  %o4, %o3, %g1
a0141a14:  c2 27 bf a0  st  %g1, [ %fp + -96 ]
a0141a18:  40 00 40 9b  call  0xa0151c84
a0141a1c:  01 00 00 00  nop
a0141a20:  d0 2f bf a6  stb  %o0, [ %fp + -90 ]
a0141a24:  d8 1f bf a0  ldd  [ %fp + -96 ], %o4
a0141a28:  d8 3f bf 48  std  %o4, [ %fp + -184 ]
a0141a2c:  d4 1f bf a8  ldd  [ %fp + -88 ], %o2
a0141a30:  d8 1f bf b0  ldd  [ %fp + -80 ], %o4
a0141a34:  d4 3f bf 50  std  %o2, [ %fp + -176 ]
a0141a38:  d8 3f bf 58  std  %o4, [ %fp + -168 ]
a0141a3c:  d4 1f bf b8  ldd  [ %fp + -72 ], %o2
a0141a40:  d8 1f bf c0  ldd  [ %fp + -64 ], %o4
a0141a44:  d4 3f bf 60  std  %o2, [ %fp + -160 ]
a0141a48:  d8 3f bf 68  std  %o4, [ %fp + -152 ]
a0141a4c:  d4 1f bf c8  ldd  [ %fp + -56 ], %o2
a0141a50:  d8 1f bf d0  ldd  [ %fp + -48 ], %o4
a0141a54:  d4 3f bf 70  std  %o2, [ %fp + -144 ]
a0141a58:  d8 3f bf 78  std  %o4, [ %fp + -136 ]
a0141a5c:  d4 1f bf d8  ldd  [ %fp + -40 ], %o2
a0141a60:  d8 1f bf e0  ldd  [ %fp + -32 ], %o4
a0141a64:  d4 3f bf 80  std  %o2, [ %fp + -128 ]
a0141a68:  d8 3f bf 88  std  %o4, [ %fp + -120 ]
a0141a6c:  d4 1f bf e8  ldd  [ %fp + -24 ], %o2
a0141a70:  d8 1f bf f0  ldd  [ %fp + -16 ], %o4
a0141a74:  d4 3f bf 90  std  %o2, [ %fp + -112 ]
a0141a78:  d8 3f bf 98  std  %o4, [ %fp + -104 ]
a0141a7c:  7f ff 10 64  call  0xa0105c0c
a0141a80:  90 07 bf 48  add  %fp, -184, %o0
a0141a84:  40 00 47 2e  call  0xa015373c
a0141a88:  01 00 00 00  nop
a0141a8c:  01 00 00 00  nop
a0141a90:  81 c7 e0 08  ret
a0141a94:  81 e8 00 00  restore
