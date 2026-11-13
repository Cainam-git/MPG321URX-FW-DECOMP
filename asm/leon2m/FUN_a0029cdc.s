# leon2m FUN_a0029cdc 0xa0029cdc-0xa0029df4 (280 bytes)
a0029cdc:  9d e3 bf 98  save  %sp, -104, %sp
a0029ce0:  17 27 c0 00  sethi  %hi(0x9f000000), %o3
a0029ce4:  90 12 e0 90  or  %o3, 0x90, %o0	! 0x9f000090
a0029ce8:  92 10 20 00  clr  %o1
a0029cec:  40 00 09 5f  call  0xa002c268
a0029cf0:  94 10 20 10  mov  0x10, %o2
a0029cf4:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a0029cf8:  92 10 20 10  mov  0x10, %o1
a0029cfc:  94 10 20 10  mov  0x10, %o2
a0029d00:  40 00 09 5a  call  0xa002c268
a0029d04:  90 14 60 28  or  %l1, 0x28, %o0
a0029d08:  40 00 09 52  call  0xa002c250
a0029d0c:  90 14 60 7c  or  %l1, 0x7c, %o0
a0029d10:  a4 10 00 08  mov  %o0, %l2
a0029d14:  40 00 09 4f  call  0xa002c250
a0029d18:  90 14 60 44  or  %l1, 0x44, %o0
a0029d1c:  a0 2c 80 08  andn  %l2, %o0, %l0
a0029d20:  15 00 00 3f  sethi  %hi(0xfc00), %o2
a0029d24:  92 12 a3 ff  or  %o2, 0x3ff, %o1	! 0xffff
a0029d28:  91 32 20 10  srl  %o0, 0x10, %o0
a0029d2c:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a0029d30:  a4 0a 00 09  and  %o0, %o1, %l2
a0029d34:  a0 0c 00 09  and  %l0, %o1, %l0
a0029d38:  b0 10 61 70  or  %g1, 0x170, %i0
a0029d3c:  b2 10 20 00  clr  %i1
a0029d40:  98 10 20 01  mov  1, %o4
a0029d44:  b5 2b 00 19  sll  %o4, %i1, %i2
a0029d48:  80 8e 80 10  btst  %i2, %l0
a0029d4c:  22 80 00 0f  be,a   0xa0029d88
a0029d50:  b2 06 60 01  inc  %i1
a0029d54:  c2 06 21 00  ld  [ %i0 + 0x100 ], %g1
a0029d58:  80 a0 60 00  cmp  %g1, 0
a0029d5c:  22 80 00 0b  be,a   0xa0029d88
a0029d60:  b2 06 60 01  inc  %i1
a0029d64:  92 10 00 1a  mov  %i2, %o1
a0029d68:  80 8e 80 12  btst  %i2, %l2
a0029d6c:  02 80 00 1b  be  0xa0029dd8
a0029d70:  90 14 60 7c  or  %l1, 0x7c, %o0
a0029d74:  9f c0 40 00  call  %g1
a0029d78:  b2 06 60 01  inc  %i1
a0029d7c:  92 10 00 1a  mov  %i2, %o1
a0029d80:  40 00 09 37  call  0xa002c25c
a0029d84:  90 14 60 7c  or  %l1, 0x7c, %o0
a0029d88:  b0 06 20 04  add  %i0, 4, %i0
a0029d8c:  80 a6 60 06  cmp  %i1, 6
a0029d90:  08 bf ff ed  bleu  0xa0029d44
a0029d94:  98 10 20 01  mov  1, %o4
a0029d98:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a0029d9c:  90 14 60 34  or  %l1, 0x34, %o0	! 0x9f020034
a0029da0:  40 00 09 2f  call  0xa002c25c
a0029da4:  92 10 20 10  mov  0x10, %o1
a0029da8:  31 27 c0 00  sethi  %hi(0x9f000000), %i0
a0029dac:  90 16 20 9c  or  %i0, 0x9c, %o0	! 0x9f00009c
a0029db0:  40 00 09 2b  call  0xa002c25c
a0029db4:  92 10 20 10  mov  0x10, %o1
a0029db8:  90 14 60 28  or  %l1, 0x28, %o0
a0029dbc:  92 10 20 00  clr  %o1
a0029dc0:  40 00 09 2a  call  0xa002c268
a0029dc4:  94 10 20 10  mov  0x10, %o2
a0029dc8:  b0 16 20 90  or  %i0, 0x90, %i0
a0029dcc:  b2 10 20 10  mov  0x10, %i1
a0029dd0:  40 00 09 26  call  0xa002c268
a0029dd4:  95 e8 20 10  restore  %g0, 0x10, %o2
a0029dd8:  40 00 09 21  call  0xa002c25c
a0029ddc:  b2 06 60 01  inc  %i1
a0029de0:  da 06 21 00  ld  [ %i0 + 0x100 ], %o5
a0029de4:  9f c3 40 00  call  %o5
a0029de8:  b0 06 20 04  add  %i0, 4, %i0
a0029dec:  10 bf ff e9  b  0xa0029d90
a0029df0:  80 a6 60 06  cmp  %i1, 6
