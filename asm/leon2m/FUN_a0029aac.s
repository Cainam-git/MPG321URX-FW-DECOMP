# leon2m FUN_a0029aac 0xa0029aac-0xa0029bc4 (280 bytes)
a0029aac:  9d e3 bf 98  save  %sp, -104, %sp
a0029ab0:  17 27 c0 00  sethi  %hi(0x9f000000), %o3
a0029ab4:  90 12 e0 90  or  %o3, 0x90, %o0	! 0x9f000090
a0029ab8:  92 10 20 00  clr  %o1
a0029abc:  40 00 09 eb  call  0xa002c268
a0029ac0:  94 10 20 04  mov  4, %o2
a0029ac4:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a0029ac8:  92 10 20 04  mov  4, %o1
a0029acc:  94 10 20 04  mov  4, %o2
a0029ad0:  40 00 09 e6  call  0xa002c268
a0029ad4:  90 14 60 28  or  %l1, 0x28, %o0
a0029ad8:  40 00 09 de  call  0xa002c250
a0029adc:  90 14 60 74  or  %l1, 0x74, %o0
a0029ae0:  a4 10 00 08  mov  %o0, %l2
a0029ae4:  40 00 09 db  call  0xa002c250
a0029ae8:  90 14 60 3c  or  %l1, 0x3c, %o0
a0029aec:  a0 2c 80 08  andn  %l2, %o0, %l0
a0029af0:  15 00 00 3f  sethi  %hi(0xfc00), %o2
a0029af4:  92 12 a3 ff  or  %o2, 0x3ff, %o1	! 0xffff
a0029af8:  91 32 20 10  srl  %o0, 0x10, %o0
a0029afc:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a0029b00:  a4 0a 00 09  and  %o0, %o1, %l2
a0029b04:  a0 0c 00 09  and  %l0, %o1, %l0
a0029b08:  b0 10 61 70  or  %g1, 0x170, %i0
a0029b0c:  b2 10 20 00  clr  %i1
a0029b10:  98 10 20 01  mov  1, %o4
a0029b14:  b5 2b 00 19  sll  %o4, %i1, %i2
a0029b18:  80 8e 80 10  btst  %i2, %l0
a0029b1c:  22 80 00 0f  be,a   0xa0029b58
a0029b20:  b2 06 60 01  inc  %i1
a0029b24:  c2 06 20 80  ld  [ %i0 + 0x80 ], %g1
a0029b28:  80 a0 60 00  cmp  %g1, 0
a0029b2c:  22 80 00 0b  be,a   0xa0029b58
a0029b30:  b2 06 60 01  inc  %i1
a0029b34:  92 10 00 1a  mov  %i2, %o1
a0029b38:  80 8e 80 12  btst  %i2, %l2
a0029b3c:  02 80 00 1b  be  0xa0029ba8
a0029b40:  90 14 60 74  or  %l1, 0x74, %o0
a0029b44:  9f c0 40 00  call  %g1
a0029b48:  b2 06 60 01  inc  %i1
a0029b4c:  92 10 00 1a  mov  %i2, %o1
a0029b50:  40 00 09 c3  call  0xa002c25c
a0029b54:  90 14 60 74  or  %l1, 0x74, %o0
a0029b58:  b0 06 20 04  add  %i0, 4, %i0
a0029b5c:  80 a6 60 03  cmp  %i1, 3
a0029b60:  08 bf ff ed  bleu  0xa0029b14
a0029b64:  98 10 20 01  mov  1, %o4
a0029b68:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a0029b6c:  90 14 60 34  or  %l1, 0x34, %o0	! 0x9f020034
a0029b70:  40 00 09 bb  call  0xa002c25c
a0029b74:  92 10 20 04  mov  4, %o1
a0029b78:  31 27 c0 00  sethi  %hi(0x9f000000), %i0
a0029b7c:  90 16 20 9c  or  %i0, 0x9c, %o0	! 0x9f00009c
a0029b80:  40 00 09 b7  call  0xa002c25c
a0029b84:  92 10 20 04  mov  4, %o1
a0029b88:  90 14 60 28  or  %l1, 0x28, %o0
a0029b8c:  92 10 20 00  clr  %o1
a0029b90:  40 00 09 b6  call  0xa002c268
a0029b94:  94 10 20 04  mov  4, %o2
a0029b98:  b0 16 20 90  or  %i0, 0x90, %i0
a0029b9c:  b2 10 20 04  mov  4, %i1
a0029ba0:  40 00 09 b2  call  0xa002c268
a0029ba4:  95 e8 20 04  restore  %g0, 4, %o2
a0029ba8:  40 00 09 ad  call  0xa002c25c
a0029bac:  b2 06 60 01  inc  %i1
a0029bb0:  da 06 20 80  ld  [ %i0 + 0x80 ], %o5
a0029bb4:  9f c3 40 00  call  %o5
a0029bb8:  b0 06 20 04  add  %i0, 4, %i0
a0029bbc:  10 bf ff e9  b  0xa0029b60
a0029bc0:  80 a6 60 03  cmp  %i1, 3
