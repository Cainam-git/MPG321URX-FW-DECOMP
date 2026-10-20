# leon2m FUN_a00dfb30 0xa00dfb30-0xa00dfc50 (136 bytes)
a00dfb30:  9d e3 bf 98  save  %sp, -104, %sp
a00dfb34:  82 06 3f fd  add  %i0, -3, %g1
a00dfb38:  80 a0 60 01  cmp  %g1, 1
a00dfb3c:  18 80 00 04  bgu  0xa00dfb4c
a00dfb40:  a0 10 20 00  clr  %l0
a00dfb44:  10 80 00 41  b  0xa00dfc48
a00dfb48:  a0 10 20 01  mov  1, %l0
a00dfb4c:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00dfb50:  da 02 e1 30  ld  [ %o3 + 0x130 ], %o5	! 0xa802b530
a00dfb54:  11 00 06 64  sethi  %hi(0x199000), %o0
a00dfb58:  80 a3 60 0c  cmp  %o5, 0xc
a00dfb5c:  18 80 00 0a  bgu  0xa00dfb84
a00dfb60:  92 12 22 88  or  %o0, 0x288, %o1
a00dfb64:  93 2b 60 02  sll  %o5, 2, %o1
a00dfb68:  15 00 01 fd  sethi  %hi(0x7f400), %o2
a00dfb6c:  9a 12 a3 34  or  %o2, 0x334, %o5	! 0x7f734
a00dfb70:  d8 03 40 09  ld  [ %o5 + %o1 ], %o4
a00dfb74:  81 c3 00 00  jmp  %o4
a00dfb78:  01 00 00 00  nop
a00dfb7c:  15 00 06 64  sethi  %hi(0x199000), %o2
a00dfb80:  92 12 a2 90  or  %o2, 0x290, %o1	! 0x199290
a00dfb84:  82 12 e1 30  or  %o3, 0x130, %g1
a00dfb88:  11 00 06 64  sethi  %hi(0x199000), %o0
a00dfb8c:  d6 00 60 08  ld  [ %g1 + 8 ], %o3
a00dfb90:  d4 00 60 04  ld  [ %g1 + 4 ], %o2
a00dfb94:  7f ff fd 77  call  0xa00df170
a00dfb98:  90 12 22 98  or  %o0, 0x298, %o0
a00dfb9c:  40 00 04 0f  call  0xa00e0bd8
a00dfba0:  01 00 00 00  nop
a00dfba4:  17 00 06 64  sethi  %hi(0x199000), %o3
a00dfba8:  90 12 e3 60  or  %o3, 0x360, %o0	! 0x199360
a00dfbac:  7f ff fd 71  call  0xa00df170
a00dfbb0:  92 10 00 18  mov  %i0, %o1
a00dfbb4:  30 80 00 25  b,a   0xa00dfc48
a00dfbb8:  1f 00 06 64  sethi  %hi(0x199000), %o7
a00dfbbc:  10 bf ff f2  b  0xa00dfb84
a00dfbc0:  92 13 e2 b0  or  %o7, 0x2b0, %o1	! 0x1992b0
a00dfbc4:  1f 00 06 64  sethi  %hi(0x199000), %o7
a00dfbc8:  10 bf ff ef  b  0xa00dfb84
a00dfbcc:  92 13 e3 20  or  %o7, 0x320, %o1	! 0x199320
a00dfbd0:  03 00 06 64  sethi  %hi(0x199000), %g1
a00dfbd4:  10 bf ff ec  b  0xa00dfb84
a00dfbd8:  92 10 63 10  or  %g1, 0x310, %o1	! 0x199310
a00dfbdc:  11 00 06 64  sethi  %hi(0x199000), %o0
a00dfbe0:  10 bf ff e9  b  0xa00dfb84
a00dfbe4:  92 12 23 08  or  %o0, 0x308, %o1	! 0x199308
a00dfbe8:  19 00 06 64  sethi  %hi(0x199000), %o4
a00dfbec:  10 bf ff e6  b  0xa00dfb84
a00dfbf0:  92 13 23 00  or  %o4, 0x300, %o1	! 0x199300
a00dfbf4:  1b 00 06 64  sethi  %hi(0x199000), %o5
a00dfbf8:  10 bf ff e3  b  0xa00dfb84
a00dfbfc:  92 13 62 f8  or  %o5, 0x2f8, %o1	! 0x1992f8
a00dfc00:  15 00 06 64  sethi  %hi(0x199000), %o2
a00dfc04:  10 bf ff e0  b  0xa00dfb84
a00dfc08:  92 12 a2 f0  or  %o2, 0x2f0, %o1	! 0x1992f0
a00dfc0c:  1f 00 06 64  sethi  %hi(0x199000), %o7
a00dfc10:  10 bf ff dd  b  0xa00dfb84
a00dfc14:  92 13 e2 e8  or  %o7, 0x2e8, %o1	! 0x1992e8
a00dfc18:  03 00 06 64  sethi  %hi(0x199000), %g1
a00dfc1c:  10 bf ff da  b  0xa00dfb84
a00dfc20:  92 10 62 d8  or  %g1, 0x2d8, %o1	! 0x1992d8
a00dfc24:  11 00 06 64  sethi  %hi(0x199000), %o0
a00dfc28:  10 bf ff d7  b  0xa00dfb84
a00dfc2c:  92 12 22 d0  or  %o0, 0x2d0, %o1	! 0x1992d0
a00dfc30:  19 00 06 64  sethi  %hi(0x199000), %o4
a00dfc34:  10 bf ff d4  b  0xa00dfb84
a00dfc38:  92 13 22 c8  or  %o4, 0x2c8, %o1	! 0x1992c8
a00dfc3c:  1b 00 06 64  sethi  %hi(0x199000), %o5
a00dfc40:  10 bf ff d1  b  0xa00dfb84
a00dfc44:  92 13 62 b8  or  %o5, 0x2b8, %o1	! 0x1992b8
a00dfc48:  81 c7 e0 08  ret
a00dfc4c:  91 e8 00 10  restore  %g0, %l0, %o0
