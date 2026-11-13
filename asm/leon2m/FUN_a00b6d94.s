# leon2m FUN_a00b6d94 0xa00b6d94-0xa00b6e1c (136 bytes)
a00b6d94:  9d e3 bf 98  save  %sp, -104, %sp
a00b6d98:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00b6d9c:  9a 14 22 90  or  %l0, 0x290, %o5	! 0xa802d290
a00b6da0:  c2 03 61 1c  ld  [ %o5 + 0x11c ], %g1
a00b6da4:  98 08 7f ef  and  %g1, -17, %o4
a00b6da8:  80 88 60 10  btst  0x10, %g1
a00b6dac:  02 80 00 0f  be  0xa00b6de8
a00b6db0:  82 10 60 10  or  %g1, 0x10, %g1
a00b6db4:  d8 23 61 1c  st  %o4, [ %o5 + 0x11c ]
a00b6db8:  40 00 83 e4  call  0xa00d7d48
a00b6dbc:  01 00 00 00  nop
a00b6dc0:  80 a2 20 00  cmp  %o0, 0
a00b6dc4:  82 14 22 90  or  %l0, 0x290, %g1
a00b6dc8:  92 10 20 00  clr  %o1
a00b6dcc:  12 80 00 0a  bne  0xa00b6df4
a00b6dd0:  90 10 20 01  mov  1, %o0
a00b6dd4:  d0 00 61 1c  ld  [ %g1 + 0x11c ], %o0
a00b6dd8:  93 32 20 04  srl  %o0, 4, %o1
a00b6ddc:  92 0a 60 01  and  %o1, 1, %o1
a00b6de0:  10 80 00 05  b  0xa00b6df4
a00b6de4:  90 10 20 01  mov  1, %o0
a00b6de8:  c2 23 61 1c  st  %g1, [ %o5 + 0x11c ]
a00b6dec:  10 bf ff f3  b  0xa00b6db8
a00b6df0:  c0 2b 61 78  clrb  [ %o5 + 0x178 ]
a00b6df4:  7f ff cc 4f  call  0xa00a9f30
a00b6df8:  01 00 00 00  nop
a00b6dfc:  40 00 76 e7  call  0xa00d4998
a00b6e00:  01 00 00 00  nop
a00b6e04:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00b6e08:  d6 0b 60 8e  ldub  [ %o5 + 0x8e ], %o3	! 0xa802b08e
a00b6e0c:  94 12 e0 02  or  %o3, 2, %o2
a00b6e10:  d4 2b 60 8e  stb  %o2, [ %o5 + 0x8e ]
a00b6e14:  81 c7 e0 08  ret
a00b6e18:  81 e8 00 00  restore
