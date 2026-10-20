# leon2m FUN_a00d5a9c 0xa00d5a9c-0xa00d5b10 (116 bytes)
a00d5a9c:  9d e3 bf 88  save  %sp, -120, %sp
a00d5aa0:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00d5aa4:  e0 0b 22 b8  ldub  [ %o4 + 0x2b8 ], %l0	! 0xa802d2b8
a00d5aa8:  13 00 06 61  sethi  %hi(0x198400), %o1
a00d5aac:  90 12 60 88  or  %o1, 0x88, %o0	! 0x198488
a00d5ab0:  9f 2c 20 04  sll  %l0, 4, %o7
a00d5ab4:  82 03 c0 08  add  %o7, %o0, %g1
a00d5ab8:  d6 12 00 0f  lduh  [ %o0 + %o7 ], %o3
a00d5abc:  d2 10 60 08  lduh  [ %g1 + 8 ], %o1
a00d5ac0:  d0 10 60 0a  lduh  [ %g1 + 0xa ], %o0
a00d5ac4:  e0 10 60 0e  lduh  [ %g1 + 0xe ], %l0
a00d5ac8:  d4 10 60 02  lduh  [ %g1 + 2 ], %o2
a00d5acc:  da 10 60 04  lduh  [ %g1 + 4 ], %o5
a00d5ad0:  d8 10 60 06  lduh  [ %g1 + 6 ], %o4
a00d5ad4:  de 10 60 0c  lduh  [ %g1 + 0xc ], %o7
a00d5ad8:  d2 37 bf f0  sth  %o1, [ %fp + -16 ]
a00d5adc:  d0 37 bf f2  sth  %o0, [ %fp + -14 ]
a00d5ae0:  d6 37 bf e8  sth  %o3, [ %fp + -24 ]
a00d5ae4:  d4 37 bf ea  sth  %o2, [ %fp + -22 ]
a00d5ae8:  da 37 bf ec  sth  %o5, [ %fp + -20 ]
a00d5aec:  d8 37 bf ee  sth  %o4, [ %fp + -18 ]
a00d5af0:  de 37 bf f4  sth  %o7, [ %fp + -12 ]
a00d5af4:  e0 37 bf f6  sth  %l0, [ %fp + -10 ]
a00d5af8:  90 10 20 06  mov  6, %o0
a00d5afc:  40 01 d7 9b  call  0xa014b968
a00d5b00:  92 07 bf e8  add  %fp, -24, %o1
a00d5b04:  01 00 00 00  nop
a00d5b08:  81 c7 e0 08  ret
a00d5b0c:  81 e8 00 00  restore
