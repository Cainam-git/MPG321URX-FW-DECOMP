# leon2m FUN_a0150df8 0xa0150df8-0xa0150e80 (136 bytes)
a0150df8:  9d e3 bf 98  save  %sp, -104, %sp
a0150dfc:  7f ff 12 12  call  0xa0115644
a0150e00:  90 10 20 01  mov  1, %o0
a0150e04:  7f ff 09 5e  call  0xa011337c
a0150e08:  90 10 20 03  mov  3, %o0
a0150e0c:  67 fc f5 98  call  0x4008e46c
a0150e10:  90 10 20 18  mov  0x18, %o0
a0150e14:  b0 02 20 30  add  %o0, 0x30, %i0
a0150e18:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a0150e1c:  1b 2a 00 b3  sethi  %hi(0xa802cc00), %o5
a0150e20:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a0150e24:  a8 12 22 90  or  %o0, 0x290, %l4
a0150e28:  a6 13 61 90  or  %o5, 0x190, %l3
a0150e2c:  a4 10 60 90  or  %g1, 0x90, %l2
a0150e30:  a0 10 20 00  clr  %l0
a0150e34:  a2 10 20 00  clr  %l1
a0150e38:  9f 2c 20 10  sll  %l0, 0x10, %o7
a0150e3c:  99 33 e0 10  srl  %o7, 0x10, %o4
a0150e40:  96 03 00 12  add  %o4, %l2, %o3
a0150e44:  90 10 00 18  mov  %i0, %o0
a0150e48:  92 03 00 14  add  %o4, %l4, %o1
a0150e4c:  7f ff 0a df  call  0xa01139c8
a0150e50:  94 03 00 13  add  %o4, %l3, %o2
a0150e54:  92 04 60 01  add  %l1, 1, %o1
a0150e58:  97 2a 60 10  sll  %o1, 0x10, %o3
a0150e5c:  95 32 e0 10  srl  %o3, 0x10, %o2
a0150e60:  80 a2 a0 0f  cmp  %o2, 0xf
a0150e64:  b0 06 20 78  add  %i0, 0x78, %i0
a0150e68:  a0 04 20 10  add  %l0, 0x10, %l0
a0150e6c:  08 bf ff f3  bleu  0xa0150e38
a0150e70:  a2 10 00 09  mov  %o1, %l1
a0150e74:  7f ff 09 42  call  0xa011337c
a0150e78:  91 e8 20 10  restore  %g0, 0x10, %o0
a0150e7c:  01 00 00 00  nop
