# leon2m FUN_a0029bc4 0xa0029bc4-0xa0029cdc (280 bytes)
a0029bc4:  9d e3 bf 98  save  %sp, -104, %sp
a0029bc8:  17 27 c0 00  sethi  %hi(0x9f000000), %o3
a0029bcc:  90 12 e0 90  or  %o3, 0x90, %o0	! 0x9f000090
a0029bd0:  92 10 20 00  clr  %o1
a0029bd4:  40 00 09 a5  call  0xa002c268
a0029bd8:  94 10 20 08  mov  8, %o2
a0029bdc:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a0029be0:  92 10 20 08  mov  8, %o1
a0029be4:  94 10 20 08  mov  8, %o2
a0029be8:  40 00 09 a0  call  0xa002c268
a0029bec:  90 14 60 28  or  %l1, 0x28, %o0
a0029bf0:  40 00 09 98  call  0xa002c250
a0029bf4:  90 14 60 78  or  %l1, 0x78, %o0
a0029bf8:  a4 10 00 08  mov  %o0, %l2
a0029bfc:  40 00 09 95  call  0xa002c250
a0029c00:  90 14 60 40  or  %l1, 0x40, %o0
a0029c04:  a0 2c 80 08  andn  %l2, %o0, %l0
a0029c08:  15 00 00 3f  sethi  %hi(0xfc00), %o2
a0029c0c:  92 12 a3 ff  or  %o2, 0x3ff, %o1	! 0xffff
a0029c10:  91 32 20 10  srl  %o0, 0x10, %o0
a0029c14:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a0029c18:  a4 0a 00 09  and  %o0, %o1, %l2
a0029c1c:  a0 0c 00 09  and  %l0, %o1, %l0
a0029c20:  b0 10 61 70  or  %g1, 0x170, %i0
a0029c24:  b2 10 20 00  clr  %i1
a0029c28:  98 10 20 01  mov  1, %o4
a0029c2c:  b5 2b 00 19  sll  %o4, %i1, %i2
a0029c30:  80 8e 80 10  btst  %i2, %l0
a0029c34:  22 80 00 0f  be,a   0xa0029c70
a0029c38:  b2 06 60 01  inc  %i1
a0029c3c:  c2 06 20 c0  ld  [ %i0 + 0xc0 ], %g1
a0029c40:  80 a0 60 00  cmp  %g1, 0
a0029c44:  22 80 00 0b  be,a   0xa0029c70
a0029c48:  b2 06 60 01  inc  %i1
a0029c4c:  92 10 00 1a  mov  %i2, %o1
a0029c50:  80 8e 80 12  btst  %i2, %l2
a0029c54:  02 80 00 1b  be  0xa0029cc0
a0029c58:  90 14 60 78  or  %l1, 0x78, %o0
a0029c5c:  9f c0 40 00  call  %g1
a0029c60:  b2 06 60 01  inc  %i1
a0029c64:  92 10 00 1a  mov  %i2, %o1
a0029c68:  40 00 09 7d  call  0xa002c25c
a0029c6c:  90 14 60 78  or  %l1, 0x78, %o0
a0029c70:  b0 06 20 04  add  %i0, 4, %i0
a0029c74:  80 a6 60 03  cmp  %i1, 3
a0029c78:  08 bf ff ed  bleu  0xa0029c2c
a0029c7c:  98 10 20 01  mov  1, %o4
a0029c80:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a0029c84:  90 14 60 34  or  %l1, 0x34, %o0	! 0x9f020034
a0029c88:  40 00 09 75  call  0xa002c25c
a0029c8c:  92 10 20 08  mov  8, %o1
a0029c90:  31 27 c0 00  sethi  %hi(0x9f000000), %i0
a0029c94:  90 16 20 9c  or  %i0, 0x9c, %o0	! 0x9f00009c
a0029c98:  40 00 09 71  call  0xa002c25c
a0029c9c:  92 10 20 08  mov  8, %o1
a0029ca0:  90 14 60 28  or  %l1, 0x28, %o0
a0029ca4:  92 10 20 00  clr  %o1
a0029ca8:  40 00 09 70  call  0xa002c268
a0029cac:  94 10 20 08  mov  8, %o2
a0029cb0:  b0 16 20 90  or  %i0, 0x90, %i0
a0029cb4:  b2 10 20 08  mov  8, %i1
a0029cb8:  40 00 09 6c  call  0xa002c268
a0029cbc:  95 e8 20 08  restore  %g0, 8, %o2
a0029cc0:  40 00 09 67  call  0xa002c25c
a0029cc4:  b2 06 60 01  inc  %i1
a0029cc8:  da 06 20 c0  ld  [ %i0 + 0xc0 ], %o5
a0029ccc:  9f c3 40 00  call  %o5
a0029cd0:  b0 06 20 04  add  %i0, 4, %i0
a0029cd4:  10 bf ff e9  b  0xa0029c78
a0029cd8:  80 a6 60 03  cmp  %i1, 3
