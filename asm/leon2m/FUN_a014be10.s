# leon2m FUN_a014be10 0xa014be10-0xa014bf64 (340 bytes)
a014be10:  9d e3 bf 98  save  %sp, -104, %sp
a014be14:  31 2a 00 b7  sethi  %hi(0xa802dc00), %i0
a014be18:  d6 06 23 30  ld  [ %i0 + 0x330 ], %o3	! 0xa802df30
a014be1c:  95 32 e0 0c  srl  %o3, 0xc, %o2
a014be20:  92 0a a0 0f  and  %o2, 0xf, %o1
a014be24:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a014be28:  82 5a 60 2a  smul  %o1, 0x2a, %g1
a014be2c:  9a 12 22 24  or  %o0, 0x224, %o5
a014be30:  d8 13 40 01  lduh  [ %o5 + %g1 ], %o4
a014be34:  80 8b 20 40  btst  0x40, %o4
a014be38:  12 80 00 24  bne  0xa014bec8
a014be3c:  d8 06 23 30  ld  [ %i0 + 0x330 ], %o4
a014be40:  9f 33 20 0c  srl  %o4, 0xc, %o7
a014be44:  90 0b e0 0f  and  %o7, 0xf, %o0
a014be48:  7f ff d0 84  call  0xa0140058
a014be4c:  01 00 00 00  nop
a014be50:  80 8a 20 ff  btst  0xff, %o0
a014be54:  02 80 00 10  be  0xa014be94
a014be58:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a014be5c:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a014be60:  da 12 62 16  lduh  [ %o1 + 0x216 ], %o5	! 0xa802e216
a014be64:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a014be68:  f0 0a 23 d8  ldub  [ %o0 + 0x3d8 ], %i0	! 0xa802e3d8
a014be6c:  82 03 7f 82  add  %o5, -126, %g1
a014be70:  9a 5e 00 01  smul  %i0, %g1, %o5
a014be74:  11 14 7a e1  sethi  %hi(0x51eb8400), %o0
a014be78:  82 12 21 1f  or  %o0, 0x11f, %g1	! 0x51eb851f
a014be7c:  9a 03 60 32  add  %o5, 0x32, %o5
a014be80:  80 53 40 01  umul  %o5, %g1, %g0
a014be84:  b1 40 00 00  rd  %y, %i0
a014be88:  99 36 20 05  srl  %i0, 5, %o4
a014be8c:  10 80 00 32  b  0xa014bf54
a014be90:  82 03 20 7e  add  %o4, 0x7e, %g1
a014be94:  82 12 a3 d0  or  %o2, 0x3d0, %g1
a014be98:  da 00 60 38  ld  [ %g1 + 0x38 ], %o5
a014be9c:  80 a3 60 01  cmp  %o5, 1
a014bea0:  02 80 00 1e  be  0xa014bf18
a014bea4:  80 a3 60 02  cmp  %o5, 2
a014bea8:  22 80 00 1d  be,a   0xa014bf1c
a014beac:  d0 08 60 08  ldub  [ %g1 + 8 ], %o0
a014beb0:  d4 08 60 08  ldub  [ %g1 + 8 ], %o2
a014beb4:  9f 2a a0 03  sll  %o2, 3, %o7
a014beb8:  96 23 c0 0a  sub  %o7, %o2, %o3
a014bebc:  93 2a e0 07  sll  %o3, 7, %o1
a014bec0:  10 bf ff ed  b  0xa014be74
a014bec4:  9a 02 40 0a  add  %o1, %o2, %o5
a014bec8:  7f ff b3 e5  call  0xa0138e5c
a014becc:  01 00 00 00  nop
a014bed0:  90 0a 20 ff  and  %o0, 0xff, %o0
a014bed4:  80 a2 20 01  cmp  %o0, 1
a014bed8:  02 80 00 0b  be  0xa014bf04
a014bedc:  82 10 20 01  mov  1, %g1
a014bee0:  80 a2 20 01  cmp  %o0, 1
a014bee4:  04 80 00 17  ble  0xa014bf40
a014bee8:  80 a2 20 02  cmp  %o0, 2
a014beec:  02 80 00 06  be  0xa014bf04
a014bef0:  82 10 20 02  mov  2, %g1
a014bef4:  80 a2 20 03  cmp  %o0, 3
a014bef8:  02 80 00 03  be  0xa014bf04
a014befc:  82 10 20 03  mov  3, %g1
a014bf00:  82 10 20 04  mov  4, %g1
a014bf04:  80 88 60 ff  btst  0xff, %g1
a014bf08:  12 bf ff d6  bne  0xa014be60
a014bf0c:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a014bf10:  10 bf ff cc  b  0xa014be40
a014bf14:  d8 06 23 30  ld  [ %i0 + 0x330 ], %o4
a014bf18:  d0 08 60 08  ldub  [ %g1 + 8 ], %o0
a014bf1c:  82 5a 22 5f  smul  %o0, 0x25f, %g1
a014bf20:  1b 14 7a e1  sethi  %hi(0x51eb8400), %o5
a014bf24:  98 00 60 32  add  %g1, 0x32, %o4
a014bf28:  b0 13 61 1f  or  %o5, 0x11f, %i0
a014bf2c:  80 53 00 18  umul  %o4, %i0, %g0
a014bf30:  9f 40 00 00  rd  %y, %o7
a014bf34:  97 33 e0 05  srl  %o7, 5, %o3
a014bf38:  10 80 00 07  b  0xa014bf54
a014bf3c:  82 02 e0 7e  add  %o3, 0x7e, %g1
a014bf40:  80 a2 20 00  cmp  %o0, 0
a014bf44:  02 bf ff f0  be  0xa014bf04
a014bf48:  82 10 20 00  clr  %g1
a014bf4c:  10 bf ff ee  b  0xa014bf04
a014bf50:  82 10 20 04  mov  4, %g1
a014bf54:  93 28 60 10  sll  %g1, 0x10, %o1
a014bf58:  b1 32 60 10  srl  %o1, 0x10, %i0
a014bf5c:  81 c7 e0 08  ret
a014bf60:  81 e8 00 00  restore
