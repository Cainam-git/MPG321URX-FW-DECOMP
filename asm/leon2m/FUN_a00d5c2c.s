# leon2m FUN_a00d5c2c 0xa00d5c2c-0xa00d5ca0 (116 bytes)
a00d5c2c:  9d e3 bf 88  save  %sp, -120, %sp
a00d5c30:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00d5c34:  e0 0b 22 d8  ldub  [ %o4 + 0x2d8 ], %l0	! 0xa802d2d8
a00d5c38:  13 00 06 61  sethi  %hi(0x198400), %o1
a00d5c3c:  90 12 60 c8  or  %o1, 0xc8, %o0	! 0x1984c8
a00d5c40:  9f 2c 20 04  sll  %l0, 4, %o7
a00d5c44:  82 03 c0 08  add  %o7, %o0, %g1
a00d5c48:  d6 12 00 0f  lduh  [ %o0 + %o7 ], %o3
a00d5c4c:  d2 10 60 08  lduh  [ %g1 + 8 ], %o1
a00d5c50:  d0 10 60 0a  lduh  [ %g1 + 0xa ], %o0
a00d5c54:  e0 10 60 0e  lduh  [ %g1 + 0xe ], %l0
a00d5c58:  d4 10 60 02  lduh  [ %g1 + 2 ], %o2
a00d5c5c:  da 10 60 04  lduh  [ %g1 + 4 ], %o5
a00d5c60:  d8 10 60 06  lduh  [ %g1 + 6 ], %o4
a00d5c64:  de 10 60 0c  lduh  [ %g1 + 0xc ], %o7
a00d5c68:  d2 37 bf f0  sth  %o1, [ %fp + -16 ]
a00d5c6c:  d0 37 bf f2  sth  %o0, [ %fp + -14 ]
a00d5c70:  d6 37 bf e8  sth  %o3, [ %fp + -24 ]
a00d5c74:  d4 37 bf ea  sth  %o2, [ %fp + -22 ]
a00d5c78:  da 37 bf ec  sth  %o5, [ %fp + -20 ]
a00d5c7c:  d8 37 bf ee  sth  %o4, [ %fp + -18 ]
a00d5c80:  de 37 bf f4  sth  %o7, [ %fp + -12 ]
a00d5c84:  e0 37 bf f6  sth  %l0, [ %fp + -10 ]
a00d5c88:  90 10 20 01  mov  1, %o0
a00d5c8c:  40 01 d7 1d  call  0xa014b900
a00d5c90:  92 07 bf e8  add  %fp, -24, %o1
a00d5c94:  01 00 00 00  nop
a00d5c98:  81 c7 e0 08  ret
a00d5c9c:  81 e8 00 00  restore
