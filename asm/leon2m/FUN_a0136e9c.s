# leon2m FUN_a0136e9c 0xa0136e9c-0xa0136f4c (176 bytes)
a0136e9c:  9d e3 bf 90  save  %sp, -112, %sp
a0136ea0:  1b 2a 00 a9  sethi  %hi(0xa802a400), %o5
a0136ea4:  90 13 60 50  or  %o5, 0x50, %o0	! 0xa802a450
a0136ea8:  d4 0a 20 01  ldub  [ %o0 + 1 ], %o2
a0136eac:  d8 0a 20 02  ldub  [ %o0 + 2 ], %o4
a0136eb0:  d2 0b 60 50  ldub  [ %o5 + 0x50 ], %o1
a0136eb4:  83 2a a0 04  sll  %o2, 4, %g1
a0136eb8:  da 0a 20 03  ldub  [ %o0 + 3 ], %o5
a0136ebc:  96 12 40 01  or  %o1, %g1, %o3
a0136ec0:  9f 2b 20 08  sll  %o4, 8, %o7
a0136ec4:  d2 0a 20 04  ldub  [ %o0 + 4 ], %o1
a0136ec8:  82 12 c0 0f  or  %o3, %o7, %g1
a0136ecc:  95 2b 60 0c  sll  %o5, 0xc, %o2
a0136ed0:  d6 0a 20 05  ldub  [ %o0 + 5 ], %o3
a0136ed4:  9e 10 40 0a  or  %g1, %o2, %o7
a0136ed8:  99 2a 60 10  sll  %o1, 0x10, %o4
a0136edc:  d2 0a 20 06  ldub  [ %o0 + 6 ], %o1
a0136ee0:  94 13 c0 0c  or  %o7, %o4, %o2
a0136ee4:  9b 2a e0 14  sll  %o3, 0x14, %o5
a0136ee8:  de 0a 20 07  ldub  [ %o0 + 7 ], %o7
a0136eec:  82 12 80 0d  or  %o2, %o5, %g1
a0136ef0:  99 2a 60 18  sll  %o1, 0x18, %o4
a0136ef4:  94 10 40 0c  or  %g1, %o4, %o2
a0136ef8:  97 2b e0 1c  sll  %o7, 0x1c, %o3
a0136efc:  92 12 80 0b  or  %o2, %o3, %o1
a0136f00:  d2 27 bf f4  st  %o1, [ %fp + -12 ]
a0136f04:  90 10 20 01  mov  1, %o0
a0136f08:  92 10 20 04  mov  4, %o1
a0136f0c:  94 07 bf f4  add  %fp, -12, %o2
a0136f10:  96 10 20 01  mov  1, %o3
a0136f14:  67 fd 55 b9  call  0x4008c5f8
a0136f18:  c0 27 bf f0  clr  [ %fp + -16 ]
a0136f1c:  1b 2a 00 a9  sethi  %hi(0xa802a400), %o5
a0136f20:  d0 0b 60 57  ldub  [ %o5 + 0x57 ], %o0	! 0xa802a457
a0136f24:  83 2a 20 10  sll  %o0, 0x10, %g1
a0136f28:  c2 27 bf f0  st  %g1, [ %fp + -16 ]
a0136f2c:  90 10 20 01  mov  1, %o0
a0136f30:  92 10 20 08  mov  8, %o1
a0136f34:  94 07 bf f0  add  %fp, -16, %o2
a0136f38:  67 fd 55 b0  call  0x4008c5f8
a0136f3c:  96 10 20 01  mov  1, %o3
a0136f40:  01 00 00 00  nop
a0136f44:  81 c7 e0 08  ret
a0136f48:  81 e8 00 00  restore
