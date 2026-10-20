# leon2m FUN_a014eb14 0xa014eb14-0xa014eba4 (144 bytes)
a014eb14:  9d e3 bf 90  save  %sp, -112, %sp
a014eb18:  90 10 20 01  mov  1, %o0
a014eb1c:  9a 10 20 03  mov  3, %o5
a014eb20:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a014eb24:  d0 2f bf f0  stb  %o0, [ %fp + -16 ]
a014eb28:  da 2f bf f1  stb  %o5, [ %fp + -15 ]
a014eb2c:  d4 10 60 80  lduh  [ %g1 + 0x80 ], %o2
a014eb30:  b0 10 20 04  mov  4, %i0
a014eb34:  98 10 20 00  clr  %o4
a014eb38:  96 10 20 00  clr  %o3
a014eb3c:  92 07 bf f8  add  %fp, -8, %o1
a014eb40:  9a 02 40 0b  add  %o1, %o3, %o5
a014eb44:  d0 0b 7f f8  ldub  [ %o5 + -8 ], %o0
a014eb48:  83 2a 20 02  sll  %o0, 2, %g1
a014eb4c:  9f 3a 80 01  sra  %o2, %g1, %o7
a014eb50:  80 8b e0 0f  btst  0xf, %o7
a014eb54:  02 80 00 08  be  0xa014eb74
a014eb58:  98 03 20 01  inc  %o4
a014eb5c:  96 0b 20 ff  and  %o4, 0xff, %o3
a014eb60:  80 a2 e0 01  cmp  %o3, 1
a014eb64:  08 bf ff f8  bleu  0xa014eb44
a014eb68:  9a 02 40 0b  add  %o1, %o3, %o5
a014eb6c:  10 80 00 08  b  0xa014eb8c
a014eb70:  13 00 06 9c  sethi  %hi(0x1a7000), %o1
a014eb74:  80 a2 e0 01  cmp  %o3, 1
a014eb78:  38 80 00 05  bgu,a   0xa014eb8c
a014eb7c:  13 00 06 9c  sethi  %hi(0x1a7000), %o1
a014eb80:  94 02 40 0b  add  %o1, %o3, %o2
a014eb84:  f0 0a bf f8  ldub  [ %o2 + -8 ], %i0
a014eb88:  13 00 06 9c  sethi  %hi(0x1a7000), %o1
a014eb8c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014eb90:  90 12 63 28  or  %o1, 0x328, %o0
a014eb94:  7f fe 41 77  call  0xa00df170
a014eb98:  92 10 00 18  mov  %i0, %o1
a014eb9c:  81 c7 e0 08  ret
a014eba0:  81 e8 00 00  restore
