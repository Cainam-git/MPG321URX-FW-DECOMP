# leon2m FUN_a0096ce4 0xa0096ce4-0xa0096e14 (304 bytes)
a0096ce4:  9d e3 bf 98  save  %sp, -104, %sp
a0096ce8:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a0096cec:  40 00 49 b4  call  0xa00a93bc
a0096cf0:  d0 0c 20 56  ldub  [ %l0 + 0x56 ], %o0	! 0xa8025c56
a0096cf4:  94 10 20 00  clr  %o2
a0096cf8:  90 10 20 01  mov  1, %o0
a0096cfc:  40 00 45 10  call  0xa00a813c
a0096d00:  d2 0c 20 56  ldub  [ %l0 + 0x56 ], %o1
a0096d04:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0096d08:  c2 04 63 ec  ld  [ %l1 + 0x3ec ], %g1	! 0xa802afec
a0096d0c:  a4 00 7f 89  add  %g1, -119, %l2
a0096d10:  90 0c a0 ff  and  %l2, 0xff, %o0
a0096d14:  92 10 20 00  clr  %o1
a0096d18:  40 00 4a 4e  call  0xa00a9650
a0096d1c:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a0096d20:  a4 14 e2 90  or  %l3, 0x290, %l2	! 0xa802d290
a0096d24:  de 04 a0 ac  ld  [ %l2 + 0xac ], %o7
a0096d28:  99 33 e0 12  srl  %o7, 0x12, %o4
a0096d2c:  92 0b 20 03  and  %o4, 3, %o1
a0096d30:  94 10 20 01  mov  1, %o2
a0096d34:  40 00 45 02  call  0xa00a813c
a0096d38:  90 10 20 01  mov  1, %o0
a0096d3c:  96 10 20 1d  mov  0x1d, %o3
a0096d40:  92 10 20 01  mov  1, %o1
a0096d44:  90 10 20 05  mov  5, %o0
a0096d48:  40 00 48 b1  call  0xa00a900c
a0096d4c:  d6 24 63 ec  st  %o3, [ %l1 + 0x3ec ]
a0096d50:  d2 04 a0 ac  ld  [ %l2 + 0xac ], %o1
a0096d54:  91 32 60 12  srl  %o1, 0x12, %o0
a0096d58:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a0096d5c:  da 0c 20 56  ldub  [ %l0 + 0x56 ], %o5
a0096d60:  82 0a 20 03  and  %o0, 3, %g1
a0096d64:  80 a3 40 01  cmp  %o5, %g1
a0096d68:  02 80 00 25  be  0xa0096dfc
a0096d6c:  a6 12 a3 f4  or  %o2, 0x3f4, %l3
a0096d70:  da 14 e0 04  lduh  [ %l3 + 4 ], %o5
a0096d74:  13 3f ff e0  sethi  %hi(0xffff8000), %o1
a0096d78:  a0 0b 40 09  and  %o5, %o1, %l0
a0096d7c:  91 2c 20 10  sll  %l0, 0x10, %o0
a0096d80:  80 a2 20 00  cmp  %o0, 0
a0096d84:  9a 13 64 00  or  %o5, 0x400, %o5
a0096d88:  92 10 20 00  clr  %o1
a0096d8c:  12 80 00 16  bne  0xa0096de4
a0096d90:  90 10 20 04  mov  4, %o0
a0096d94:  40 00 78 bb  call  0xa00b5080
a0096d98:  c0 24 63 ec  clr  [ %l1 + 0x3ec ]
a0096d9c:  40 01 10 ae  call  0xa00db054
a0096da0:  01 00 00 00  nop
a0096da4:  40 02 b5 ba  call  0xa014448c
a0096da8:  90 10 20 00  clr  %o0	! 0x0
a0096dac:  40 02 b6 14  call  0xa01445fc
a0096db0:  90 0a 20 ff  and  %o0, 0xff, %o0
a0096db4:  80 8a 20 ff  btst  0xff, %o0
a0096db8:  22 80 00 12  be,a   0xa0096e00
a0096dbc:  27 2a 00 ac  sethi  %hi(0xa802b000), %l3
a0096dc0:  d6 04 a0 ac  ld  [ %l2 + 0xac ], %o3
a0096dc4:  15 00 04 00  sethi  %hi(0x100000), %o2
a0096dc8:  23 00 00 04  sethi  %hi(0x1000), %l1
a0096dcc:  80 8a c0 0a  btst  %o3, %o2
a0096dd0:  92 14 63 88  or  %l1, 0x388, %o1
a0096dd4:  02 80 00 0a  be  0xa0096dfc
a0096dd8:  90 10 20 14  mov  0x14, %o0
a0096ddc:  10 80 00 05  b  0xa0096df0
a0096de0:  de 14 e0 0a  lduh  [ %l3 + 0xa ], %o7
a0096de4:  7f ff a6 b2  call  0xa00808ac
a0096de8:  da 34 e0 04  sth  %o5, [ %l3 + 4 ]
a0096dec:  30 bf ff ea  b,a   0xa0096d94
a0096df0:  98 13 e0 40  or  %o7, 0x40, %o4
a0096df4:  7f ff be ef  call  0xa00869b0
a0096df8:  d8 34 e0 0a  sth  %o4, [ %l3 + 0xa ]
a0096dfc:  27 2a 00 ac  sethi  %hi(0xa802b000), %l3
a0096e00:  c2 0c e0 8e  ldub  [ %l3 + 0x8e ], %g1	! 0xa802b08e
a0096e04:  a4 10 60 06  or  %g1, 6, %l2
a0096e08:  e4 2c e0 8e  stb  %l2, [ %l3 + 0x8e ]
a0096e0c:  81 c7 e0 08  ret
a0096e10:  81 e8 00 00  restore
