# leon2m FUN_a013ba14 0xa013ba14-0xa013bb50 (316 bytes)
a013ba14:  9d e3 bf 98  save  %sp, -104, %sp
a013ba18:  b0 0e 20 ff  and  %i0, 0xff, %i0
a013ba1c:  40 00 04 cc  call  0xa013cd4c
a013ba20:  90 10 00 18  mov  %i0, %o0
a013ba24:  a0 10 00 08  mov  %o0, %l0
a013ba28:  40 00 04 c9  call  0xa013cd4c
a013ba2c:  90 10 00 18  mov  %i0, %o0
a013ba30:  13 00 00 16  sethi  %hi(0x5800), %o1
a013ba34:  d6 12 20 3c  lduh  [ %o0 + 0x3c ], %o3
a013ba38:  94 12 63 01  or  %o1, 0x301, %o2
a013ba3c:  9e 1a c0 0a  xor  %o3, %o2, %o7
a013ba40:  15 00 00 17  sethi  %hi(0x5c00), %o2
a013ba44:  80 a0 00 0f  cmp  %g0, %o7
a013ba48:  90 12 a0 01  or  %o2, 1, %o0
a013ba4c:  98 60 3f ff  subx  %g0, -1, %o4
a013ba50:  9a 1a c0 08  xor  %o3, %o0, %o5
a013ba54:  80 a0 00 0d  cmp  %g0, %o5
a013ba58:  82 60 3f ff  subx  %g0, -1, %g1
a013ba5c:  80 93 00 01  orcc  %o4, %g1, %g0
a013ba60:  12 80 00 29  bne  0xa013bb04
a013ba64:  82 10 20 01  mov  1, %g1
a013ba68:  82 12 a1 01  or  %o2, 0x101, %g1
a013ba6c:  80 a2 c0 01  cmp  %o3, %g1
a013ba70:  02 80 00 24  be  0xa013bb00
a013ba74:  80 a2 e8 00  cmp  %o3, 0x800
a013ba78:  02 80 00 22  be  0xa013bb00
a013ba7c:  98 12 a3 01  or  %o2, 0x301, %o4
a013ba80:  80 a2 c0 0c  cmp  %o3, %o4
a013ba84:  02 80 00 1f  be  0xa013bb00
a013ba88:  1b 00 00 18  sethi  %hi(0x6000), %o5
a013ba8c:  90 13 60 01  or  %o5, 1, %o0	! 0x6001
a013ba90:  80 a2 c0 08  cmp  %o3, %o0
a013ba94:  02 80 00 1b  be  0xa013bb00
a013ba98:  9e 13 61 01  or  %o5, 0x101, %o7
a013ba9c:  80 a2 c0 0f  cmp  %o3, %o7
a013baa0:  02 80 00 18  be  0xa013bb00
a013baa4:  80 a2 c0 09  cmp  %o3, %o1
a013baa8:  02 80 00 16  be  0xa013bb00
a013baac:  94 12 61 00  or  %o1, 0x100, %o2
a013bab0:  80 a2 c0 0a  cmp  %o3, %o2
a013bab4:  02 80 00 13  be  0xa013bb00
a013bab8:  03 00 00 08  sethi  %hi(0x2000), %g1
a013babc:  b0 10 62 00  or  %g1, 0x200, %i0	! 0x2200
a013bac0:  80 a2 c0 18  cmp  %o3, %i0
a013bac4:  02 80 00 0f  be  0xa013bb00
a013bac8:  11 00 00 15  sethi  %hi(0x5400), %o0
a013bacc:  98 12 23 00  or  %o0, 0x300, %o4	! 0x5700
a013bad0:  80 a2 c0 0c  cmp  %o3, %o4
a013bad4:  02 80 00 0b  be  0xa013bb00
a013bad8:  9e 12 62 00  or  %o1, 0x200, %o7
a013badc:  80 a2 c0 0f  cmp  %o3, %o7
a013bae0:  02 80 00 08  be  0xa013bb00
a013bae4:  92 13 63 01  or  %o5, 0x301, %o1
a013bae8:  80 a2 c0 09  cmp  %o3, %o1
a013baec:  02 80 00 05  be  0xa013bb00
a013baf0:  94 13 62 01  or  %o5, 0x201, %o2
a013baf4:  80 a2 c0 0a  cmp  %o3, %o2
a013baf8:  12 80 00 03  bne  0xa013bb04
a013bafc:  82 10 20 00  clr  %g1
a013bb00:  82 10 20 01  mov  1, %g1
a013bb04:  80 a0 60 00  cmp  %g1, 0
a013bb08:  12 80 00 10  bne  0xa013bb48
a013bb0c:  b0 10 20 00  clr  %i0
a013bb10:  da 14 20 06  lduh  [ %l0 + 6 ], %o5
a013bb14:  80 a3 60 95  cmp  %o5, 0x95
a013bb18:  08 80 00 0c  bleu  0xa013bb48
a013bb1c:  b0 10 20 01  mov  1, %i0
a013bb20:  03 00 00 06  sethi  %hi(0x1800), %g1
a013bb24:  96 10 61 64  or  %g1, 0x164, %o3	! 0x1964
a013bb28:  80 a3 40 0b  cmp  %o5, %o3
a013bb2c:  18 80 00 07  bgu  0xa013bb48
a013bb30:  01 00 00 00  nop
a013bb34:  d0 14 20 08  lduh  [ %l0 + 8 ], %o0
a013bb38:  80 a2 20 c7  cmp  %o0, 0xc7
a013bb3c:  08 80 00 03  bleu  0xa013bb48
a013bb40:  80 a2 29 93  cmp  %o0, 0x993
a013bb44:  b0 60 3f ff  subx  %g0, -1, %i0
a013bb48:  81 c7 e0 08  ret
a013bb4c:  81 e8 00 00  restore
