# leon2m FUN_a00d5bb8 0xa00d5bb8-0xa00d5c2c (116 bytes)
a00d5bb8:  9d e3 bf 88  save  %sp, -120, %sp
a00d5bbc:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00d5bc0:  e0 0b 22 d6  ldub  [ %o4 + 0x2d6 ], %l0	! 0xa802d2d6
a00d5bc4:  13 00 06 61  sethi  %hi(0x198400), %o1
a00d5bc8:  90 12 60 c8  or  %o1, 0xc8, %o0	! 0x1984c8
a00d5bcc:  9f 2c 20 04  sll  %l0, 4, %o7
a00d5bd0:  82 03 c0 08  add  %o7, %o0, %g1
a00d5bd4:  d6 12 00 0f  lduh  [ %o0 + %o7 ], %o3
a00d5bd8:  d2 10 60 08  lduh  [ %g1 + 8 ], %o1
a00d5bdc:  d0 10 60 0a  lduh  [ %g1 + 0xa ], %o0
a00d5be0:  e0 10 60 0e  lduh  [ %g1 + 0xe ], %l0
a00d5be4:  d4 10 60 02  lduh  [ %g1 + 2 ], %o2
a00d5be8:  da 10 60 04  lduh  [ %g1 + 4 ], %o5
a00d5bec:  d8 10 60 06  lduh  [ %g1 + 6 ], %o4
a00d5bf0:  de 10 60 0c  lduh  [ %g1 + 0xc ], %o7
a00d5bf4:  d2 37 bf f0  sth  %o1, [ %fp + -16 ]
a00d5bf8:  d0 37 bf f2  sth  %o0, [ %fp + -14 ]
a00d5bfc:  d6 37 bf e8  sth  %o3, [ %fp + -24 ]
a00d5c00:  d4 37 bf ea  sth  %o2, [ %fp + -22 ]
a00d5c04:  da 37 bf ec  sth  %o5, [ %fp + -20 ]
a00d5c08:  d8 37 bf ee  sth  %o4, [ %fp + -18 ]
a00d5c0c:  de 37 bf f4  sth  %o7, [ %fp + -12 ]
a00d5c10:  e0 37 bf f6  sth  %l0, [ %fp + -10 ]
a00d5c14:  90 10 20 00  clr  %o0
a00d5c18:  40 01 d7 3a  call  0xa014b900
a00d5c1c:  92 07 bf e8  add  %fp, -24, %o1
a00d5c20:  01 00 00 00  nop
a00d5c24:  81 c7 e0 08  ret
a00d5c28:  81 e8 00 00  restore
