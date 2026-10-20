# leon2m FUN_a00d5a28 0xa00d5a28-0xa00d5a9c (116 bytes)
a00d5a28:  9d e3 bf 88  save  %sp, -120, %sp
a00d5a2c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00d5a30:  e0 0b 22 b7  ldub  [ %o4 + 0x2b7 ], %l0	! 0xa802d2b7
a00d5a34:  13 00 06 61  sethi  %hi(0x198400), %o1
a00d5a38:  90 12 60 88  or  %o1, 0x88, %o0	! 0x198488
a00d5a3c:  9f 2c 20 04  sll  %l0, 4, %o7
a00d5a40:  82 03 c0 08  add  %o7, %o0, %g1
a00d5a44:  d6 12 00 0f  lduh  [ %o0 + %o7 ], %o3
a00d5a48:  d2 10 60 08  lduh  [ %g1 + 8 ], %o1
a00d5a4c:  d0 10 60 0a  lduh  [ %g1 + 0xa ], %o0
a00d5a50:  e0 10 60 0e  lduh  [ %g1 + 0xe ], %l0
a00d5a54:  d4 10 60 02  lduh  [ %g1 + 2 ], %o2
a00d5a58:  da 10 60 04  lduh  [ %g1 + 4 ], %o5
a00d5a5c:  d8 10 60 06  lduh  [ %g1 + 6 ], %o4
a00d5a60:  de 10 60 0c  lduh  [ %g1 + 0xc ], %o7
a00d5a64:  d2 37 bf f0  sth  %o1, [ %fp + -16 ]
a00d5a68:  d0 37 bf f2  sth  %o0, [ %fp + -14 ]
a00d5a6c:  d6 37 bf e8  sth  %o3, [ %fp + -24 ]
a00d5a70:  d4 37 bf ea  sth  %o2, [ %fp + -22 ]
a00d5a74:  da 37 bf ec  sth  %o5, [ %fp + -20 ]
a00d5a78:  d8 37 bf ee  sth  %o4, [ %fp + -18 ]
a00d5a7c:  de 37 bf f4  sth  %o7, [ %fp + -12 ]
a00d5a80:  e0 37 bf f6  sth  %l0, [ %fp + -10 ]
a00d5a84:  90 10 20 05  mov  5, %o0
a00d5a88:  40 01 d7 b8  call  0xa014b968
a00d5a8c:  92 07 bf e8  add  %fp, -24, %o1
a00d5a90:  01 00 00 00  nop
a00d5a94:  81 c7 e0 08  ret
a00d5a98:  81 e8 00 00  restore
