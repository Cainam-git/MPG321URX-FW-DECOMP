# leon2m FUN_a0099c64 0xa0099c64-0xa0099cfc (152 bytes)
a0099c64:  9d e3 bf 98  save  %sp, -104, %sp
a0099c68:  23 2a 00 b3  sethi  %hi(0xa802cc00), %l1
a0099c6c:  a0 14 63 f4  or  %l1, 0x3f4, %l0	! 0xa802cff4
a0099c70:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a0099c74:  a2 13 22 90  or  %o4, 0x290, %l1	! 0xa802d290
a0099c78:  e4 04 61 dc  ld  [ %l1 + 0x1dc ], %l2
a0099c7c:  d2 14 20 04  lduh  [ %l0 + 4 ], %o1
a0099c80:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a0099c84:  1f 20 00 00  sethi  %hi(0x80000000), %o7
a0099c88:  90 0a 40 01  and  %o1, %g1, %o0
a0099c8c:  d4 14 20 0e  lduh  [ %l0 + 0xe ], %o2
a0099c90:  98 2c 80 0f  andn  %l2, %o7, %o4
a0099c94:  17 3f ff e0  sethi  %hi(0xffff8000), %o3
a0099c98:  82 2a 80 0b  andn  %o2, %o3, %g1
a0099c9c:  d8 24 61 dc  st  %o4, [ %l1 + 0x1dc ]
a0099ca0:  9b 2a 20 10  sll  %o0, 0x10, %o5
a0099ca4:  96 12 64 00  or  %o1, 0x400, %o3
a0099ca8:  25 2a 00 97  sethi  %hi(0xa8025c00), %l2
a0099cac:  c2 34 20 0e  sth  %g1, [ %l0 + 0xe ]
a0099cb0:  27 2a 00 ab  sethi  %hi(0xa802ac00), %l3
a0099cb4:  80 a3 60 00  cmp  %o5, 0
a0099cb8:  c0 2c a0 56  clrb  [ %l2 + 0x56 ]
a0099cbc:  90 10 20 04  mov  4, %o0
a0099cc0:  02 80 00 04  be  0xa0099cd0
a0099cc4:  92 10 20 00  clr  %o1
a0099cc8:  7f ff 9a f9  call  0xa00808ac
a0099ccc:  d6 34 20 04  sth  %o3, [ %l0 + 4 ]
a0099cd0:  40 00 6c ec  call  0xa00b5080
a0099cd4:  c0 24 e3 ec  clr  [ %l3 + 0x3ec ]
a0099cd8:  c0 2c 20 3f  clrb  [ %l0 + 0x3f ]
a0099cdc:  c0 2c 61 e4  clrb  [ %l1 + 0x1e4 ]
a0099ce0:  d0 0c a0 56  ldub  [ %l2 + 0x56 ], %o0
a0099ce4:  40 00 5f b0  call  0xa00b1ba4
a0099ce8:  92 10 20 04  mov  4, %o1
a0099cec:  a0 10 21 0a  mov  0x10a, %l0
a0099cf0:  e0 24 e3 ec  st  %l0, [ %l3 + 0x3ec ]
a0099cf4:  81 c7 e0 08  ret
a0099cf8:  81 e8 00 00  restore
