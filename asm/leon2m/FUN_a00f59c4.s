# leon2m FUN_a00f59c4 0xa00f59c4-0xa00f62ac (2280 bytes)
a00f59c4:  9d e3 bf 78  save  %sp, -136, %sp
a00f59c8:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00f59cc:  90 10 00 11  mov  %l1, %o0
a00f59d0:  40 00 b0 df  call  0xa0121d4c
a00f59d4:  a0 10 00 18  mov  %i0, %l0
a00f59d8:  80 8a 20 ff  btst  0xff, %o0
a00f59dc:  02 80 02 32  be  0xa00f62a4
a00f59e0:  b0 10 20 00  clr  %i0
a00f59e4:  92 10 20 2a  mov  0x2a, %o1
a00f59e8:  7f ff f2 1b  call  0xa00f2254
a00f59ec:  90 10 00 11  mov  %l1, %o0
a00f59f0:  d0 2f bf df  stb  %o0, [ %fp + -33 ]
a00f59f4:  92 10 20 4a  mov  0x4a, %o1
a00f59f8:  7f ff f0 26  call  0xa00f1a90
a00f59fc:  90 10 00 11  mov  %l1, %o0
a00f5a00:  d0 2f bf de  stb  %o0, [ %fp + -34 ]
a00f5a04:  90 10 00 11  mov  %l1, %o0
a00f5a08:  92 10 20 2a  mov  0x2a, %o1
a00f5a0c:  7f ff f2 23  call  0xa00f2298
a00f5a10:  94 10 20 00  clr  %o2
a00f5a14:  92 10 20 4a  mov  0x4a, %o1
a00f5a18:  94 10 20 20  mov  0x20, %o2
a00f5a1c:  96 10 20 00  clr  %o3
a00f5a20:  7f ff f0 4f  call  0xa00f1b5c
a00f5a24:  90 10 00 11  mov  %l1, %o0
a00f5a28:  29 2a 00 ad  sethi  %hi(0xa802b400), %l4
a00f5a2c:  7f ff f7 db  call  0xa00f3998
a00f5a30:  c0 2d 23 ac  clrb  [ %l4 + 0x3ac ]	! 0xa802b7ac
a00f5a34:  7f ff f7 de  call  0xa00f39ac
a00f5a38:  d0 2f bf f0  stb  %o0, [ %fp + -16 ]
a00f5a3c:  7f ff f7 e1  call  0xa00f39c0
a00f5a40:  d0 2f bf f1  stb  %o0, [ %fp + -15 ]
a00f5a44:  7f ff f7 c7  call  0xa00f3960
a00f5a48:  d0 2f bf f2  stb  %o0, [ %fp + -14 ]
a00f5a4c:  7f ff f7 ca  call  0xa00f3974
a00f5a50:  d0 2f bf f3  stb  %o0, [ %fp + -13 ]
a00f5a54:  7f ff f7 cd  call  0xa00f3988
a00f5a58:  d0 2f bf f4  stb  %o0, [ %fp + -12 ]
a00f5a5c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00f5a60:  d0 2f bf f5  stb  %o0, [ %fp + -11 ]
a00f5a64:  80 a6 60 00  cmp  %i1, 0
a00f5a68:  12 80 01 c6  bne  0xa00f6180
a00f5a6c:  ac 10 00 10  mov  %l0, %l6
a00f5a70:  80 a4 60 07  cmp  %l1, 7
a00f5a74:  a4 10 00 10  mov  %l0, %l2
a00f5a78:  08 80 00 e8  bleu  0xa00f5e18
a00f5a7c:  82 10 20 00  clr  %g1
a00f5a80:  15 33 c0 80  sethi  %hi(0xcf020000), %o2
a00f5a84:  92 08 60 ff  and  %g1, 0xff, %o1
a00f5a88:  9a 12 a1 0c  or  %o2, 0x10c, %o5
a00f5a8c:  d2 23 40 00  st  %o1, [ %o5 ]
a00f5a90:  7f ff f7 b4  call  0xa00f3960
a00f5a94:  b0 0c a0 ff  and  %l2, 0xff, %i0
a00f5a98:  7f ff f7 b7  call  0xa00f3974
a00f5a9c:  d0 2f bf e0  stb  %o0, [ %fp + -32 ]
a00f5aa0:  7f ff f7 ba  call  0xa00f3988
a00f5aa4:  d0 2f bf e1  stb  %o0, [ %fp + -31 ]
a00f5aa8:  7f ff f7 ae  call  0xa00f3960
a00f5aac:  d0 2f bf e2  stb  %o0, [ %fp + -30 ]
a00f5ab0:  7f ff f7 b1  call  0xa00f3974
a00f5ab4:  d0 2f bf e8  stb  %o0, [ %fp + -24 ]
a00f5ab8:  7f ff f7 b4  call  0xa00f3988
a00f5abc:  d0 2f bf e9  stb  %o0, [ %fp + -23 ]
a00f5ac0:  d0 2f bf ea  stb  %o0, [ %fp + -22 ]
a00f5ac4:  11 20 20 20  sethi  %hi(0x80808000), %o0
a00f5ac8:  a6 12 20 81  or  %o0, 0x81, %l3	! 0x80808081
a00f5acc:  aa 10 20 00  clr  %l5
a00f5ad0:  67 fe 5e ae  call  0x4008d588
a00f5ad4:  a4 10 20 00  clr  %l2
a00f5ad8:  a0 10 00 08  mov  %o0, %l0
a00f5adc:  90 10 00 18  mov  %i0, %o0
a00f5ae0:  92 10 20 36  mov  0x36, %o1
a00f5ae4:  7f ff ef fc  call  0xa00f1ad4
a00f5ae8:  94 10 20 6e  mov  0x6e, %o2
a00f5aec:  a1 2c 20 10  sll  %l0, 0x10, %l0
a00f5af0:  40 00 ae 21  call  0xa0121374
a00f5af4:  90 10 00 18  mov  %i0, %o0
a00f5af8:  82 0a 20 ff  and  %o0, 0xff, %g1
a00f5afc:  92 10 20 36  mov  0x36, %o1
a00f5b00:  80 a0 60 01  cmp  %g1, 1
a00f5b04:  02 80 01 aa  be  0xa00f61ac
a00f5b08:  90 10 00 18  mov  %i0, %o0
a00f5b0c:  7f ff ef e1  call  0xa00f1a90
a00f5b10:  01 00 00 00  nop
a00f5b14:  80 8a 20 02  btst  2, %o0
a00f5b18:  02 80 01 a7  be  0xa00f61b4
a00f5b1c:  91 34 20 10  srl  %l0, 0x10, %o0
a00f5b20:  67 fe 5e 9d  call  0x4008d594
a00f5b24:  01 00 00 00  nop
a00f5b28:  99 2a 20 10  sll  %o0, 0x10, %o4
a00f5b2c:  97 33 20 10  srl  %o4, 0x10, %o3
a00f5b30:  80 a2 e0 63  cmp  %o3, 0x63
a00f5b34:  08 bf ff ef  bleu  0xa00f5af0
a00f5b38:  01 00 00 00  nop
a00f5b3c:  80 8c a0 ff  btst  0xff, %l2
a00f5b40:  12 80 00 05  bne  0xa00f5b54
a00f5b44:  e4 0d 23 ac  ldub  [ %l4 + 0x3ac ], %l2
a00f5b48:  9e 10 20 01  mov  1, %o7
a00f5b4c:  de 2d 23 ac  stb  %o7, [ %l4 + 0x3ac ]
a00f5b50:  e4 0d 23 ac  ldub  [ %l4 + 0x3ac ], %l2
a00f5b54:  80 a4 a0 01  cmp  %l2, 1
a00f5b58:  02 80 01 bb  be  0xa00f6244
a00f5b5c:  92 10 20 43  mov  0x43, %o1
a00f5b60:  7f ff ef cc  call  0xa00f1a90
a00f5b64:  90 10 00 18  mov  %i0, %o0
a00f5b68:  d6 0f bf e8  ldub  [ %fp + -24 ], %o3
a00f5b6c:  ae 0a e0 ff  and  %o3, 0xff, %l7
a00f5b70:  a4 10 20 ff  mov  0xff, %l2
a00f5b74:  9e 24 80 17  sub  %l2, %l7, %o7
a00f5b78:  99 2b e0 10  sll  %o7, 0x10, %o4
a00f5b7c:  a1 33 20 10  srl  %o4, 0x10, %l0
a00f5b80:  95 2c 20 03  sll  %l0, 3, %o2
a00f5b84:  92 02 80 10  add  %o2, %l0, %o1
a00f5b88:  9b 2a 60 04  sll  %o1, 4, %o5
a00f5b8c:  80 5b 40 13  smul  %o5, %l3, %g0
a00f5b90:  83 40 00 00  rd  %y, %g1
a00f5b94:  ba 00 40 0d  add  %g1, %o5, %i5
a00f5b98:  b9 3f 60 07  sra  %i5, 7, %i4
a00f5b9c:  b6 07 20 60  add  %i4, 0x60, %i3
a00f5ba0:  b5 2e e0 10  sll  %i3, 0x10, %i2
a00f5ba4:  af 36 a0 10  srl  %i2, 0x10, %l7
a00f5ba8:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00f5bac:  80 a3 40 17  cmp  %o5, %l7
a00f5bb0:  0a 80 00 78  bcs  0xa00f5d90
a00f5bb4:  a0 10 20 00  clr  %l0
a00f5bb8:  80 a3 60 ef  cmp  %o5, 0xef
a00f5bbc:  18 80 00 09  bgu  0xa00f5be0
a00f5bc0:  98 10 00 0d  mov  %o5, %o4
a00f5bc4:  80 a2 e0 08  cmp  %o3, 8
a00f5bc8:  08 80 00 07  bleu  0xa00f5be4
a00f5bcc:  80 a3 20 f8  cmp  %o4, 0xf8
a00f5bd0:  b4 02 c0 08  add  %o3, %o0, %i2
a00f5bd4:  96 06 a0 10  add  %i2, 0x10, %o3
a00f5bd8:  d6 2f bf e8  stb  %o3, [ %fp + -24 ]
a00f5bdc:  a0 10 3f ff  mov  -1, %l0
a00f5be0:  80 a3 20 f8  cmp  %o4, 0xf8
a00f5be4:  08 80 00 0a  bleu  0xa00f5c0c
a00f5be8:  92 10 20 44  mov  0x44, %o1
a00f5bec:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00f5bf0:  80 a0 60 f7  cmp  %g1, 0xf7
a00f5bf4:  18 80 00 06  bgu  0xa00f5c0c
a00f5bf8:  b6 00 40 08  add  %g1, %o0, %i3
a00f5bfc:  90 06 e0 08  add  %i3, 8, %o0
a00f5c00:  d0 2f bf e8  stb  %o0, [ %fp + -24 ]
a00f5c04:  a0 10 3f ff  mov  -1, %l0
a00f5c08:  92 10 20 44  mov  0x44, %o1
a00f5c0c:  7f ff ef a1  call  0xa00f1a90
a00f5c10:  90 10 00 18  mov  %i0, %o0
a00f5c14:  d6 0f bf e9  ldub  [ %fp + -23 ], %o3
a00f5c18:  ba 0a e0 ff  and  %o3, 0xff, %i5
a00f5c1c:  b8 10 20 ff  mov  0xff, %i4
a00f5c20:  b6 27 00 1d  sub  %i4, %i5, %i3
a00f5c24:  b5 2e e0 10  sll  %i3, 0x10, %i2
a00f5c28:  af 36 a0 10  srl  %i2, 0x10, %l7
a00f5c2c:  a5 2d e0 03  sll  %l7, 3, %l2
a00f5c30:  9e 04 80 17  add  %l2, %l7, %o7
a00f5c34:  99 2b e0 04  sll  %o7, 4, %o4
a00f5c38:  80 5b 00 13  smul  %o4, %l3, %g0
a00f5c3c:  95 40 00 00  rd  %y, %o2
a00f5c40:  92 02 80 0c  add  %o2, %o4, %o1
a00f5c44:  9b 3a 60 07  sra  %o1, 7, %o5
a00f5c48:  82 03 60 60  add  %o5, 0x60, %g1
a00f5c4c:  bb 28 60 10  sll  %g1, 0x10, %i5
a00f5c50:  b9 37 60 10  srl  %i5, 0x10, %i4
a00f5c54:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00f5c58:  80 a3 40 1c  cmp  %o5, %i4
a00f5c5c:  0a 80 00 4d  bcs  0xa00f5d90
a00f5c60:  80 a3 60 ef  cmp  %o5, 0xef
a00f5c64:  18 80 00 09  bgu  0xa00f5c88
a00f5c68:  98 10 00 0d  mov  %o5, %o4
a00f5c6c:  80 a2 e0 08  cmp  %o3, 8
a00f5c70:  08 80 00 07  bleu  0xa00f5c8c
a00f5c74:  80 a3 20 f8  cmp  %o4, 0xf8
a00f5c78:  82 02 c0 08  add  %o3, %o0, %g1
a00f5c7c:  a0 00 60 10  add  %g1, 0x10, %l0
a00f5c80:  e0 2f bf e9  stb  %l0, [ %fp + -23 ]
a00f5c84:  a0 10 3f ff  mov  -1, %l0
a00f5c88:  80 a3 20 f8  cmp  %o4, 0xf8
a00f5c8c:  08 80 00 0a  bleu  0xa00f5cb4
a00f5c90:  92 10 20 45  mov  0x45, %o1
a00f5c94:  c2 0f bf e9  ldub  [ %fp + -23 ], %g1
a00f5c98:  80 a0 60 f7  cmp  %g1, 0xf7
a00f5c9c:  18 80 00 06  bgu  0xa00f5cb4
a00f5ca0:  9a 00 40 08  add  %g1, %o0, %o5
a00f5ca4:  96 03 60 08  add  %o5, 8, %o3
a00f5ca8:  d6 2f bf e9  stb  %o3, [ %fp + -23 ]
a00f5cac:  a0 10 3f ff  mov  -1, %l0
a00f5cb0:  92 10 20 45  mov  0x45, %o1
a00f5cb4:  7f ff ef 77  call  0xa00f1a90
a00f5cb8:  90 10 00 18  mov  %i0, %o0
a00f5cbc:  d6 0f bf ea  ldub  [ %fp + -22 ], %o3
a00f5cc0:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00f5cc4:  94 10 20 ff  mov  0xff, %o2
a00f5cc8:  92 22 80 0d  sub  %o2, %o5, %o1
a00f5ccc:  83 2a 60 10  sll  %o1, 0x10, %g1
a00f5cd0:  bb 30 60 10  srl  %g1, 0x10, %i5
a00f5cd4:  b9 2f 60 03  sll  %i5, 3, %i4
a00f5cd8:  b6 07 00 1d  add  %i4, %i5, %i3
a00f5cdc:  b5 2e e0 04  sll  %i3, 4, %i2
a00f5ce0:  80 5e 80 13  smul  %i2, %l3, %g0
a00f5ce4:  af 40 00 00  rd  %y, %l7
a00f5ce8:  a4 05 c0 1a  add  %l7, %i2, %l2
a00f5cec:  9f 3c a0 07  sra  %l2, 7, %o7
a00f5cf0:  98 03 e0 60  add  %o7, 0x60, %o4
a00f5cf4:  95 2b 20 10  sll  %o4, 0x10, %o2
a00f5cf8:  93 32 a0 10  srl  %o2, 0x10, %o1
a00f5cfc:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00f5d00:  80 a3 40 09  cmp  %o5, %o1
a00f5d04:  0a 80 00 23  bcs  0xa00f5d90
a00f5d08:  80 a3 60 ef  cmp  %o5, 0xef
a00f5d0c:  18 80 00 09  bgu  0xa00f5d30
a00f5d10:  98 10 00 0d  mov  %o5, %o4
a00f5d14:  80 a2 e0 08  cmp  %o3, 8
a00f5d18:  08 80 00 07  bleu  0xa00f5d34
a00f5d1c:  80 a3 20 f8  cmp  %o4, 0xf8
a00f5d20:  9e 02 c0 08  add  %o3, %o0, %o7
a00f5d24:  a0 03 e0 10  add  %o7, 0x10, %l0
a00f5d28:  e0 2f bf ea  stb  %l0, [ %fp + -22 ]
a00f5d2c:  a0 10 3f ff  mov  -1, %l0
a00f5d30:  80 a3 20 f8  cmp  %o4, 0xf8
a00f5d34:  08 80 00 0b  bleu  0xa00f5d60
a00f5d38:  80 8c 20 ff  btst  0xff, %l0
a00f5d3c:  c2 0f bf ea  ldub  [ %fp + -22 ], %g1
a00f5d40:  80 a0 60 f7  cmp  %g1, 0xf7
a00f5d44:  18 80 00 07  bgu  0xa00f5d60
a00f5d48:  80 8c 20 ff  btst  0xff, %l0
a00f5d4c:  96 00 40 08  add  %g1, %o0, %o3
a00f5d50:  90 02 e0 08  add  %o3, 8, %o0
a00f5d54:  d0 2f bf ea  stb  %o0, [ %fp + -22 ]
a00f5d58:  a0 10 3f ff  mov  -1, %l0
a00f5d5c:  80 8c 20 ff  btst  0xff, %l0
a00f5d60:  22 80 01 41  be,a   0xa00f6264
a00f5d64:  f0 0f bf e8  ldub  [ %fp + -24 ], %i0
a00f5d68:  7f ff f6 db  call  0xa00f38d4
a00f5d6c:  d0 0f bf e8  ldub  [ %fp + -24 ], %o0
a00f5d70:  7f ff f6 df  call  0xa00f38ec
a00f5d74:  d0 0f bf e9  ldub  [ %fp + -23 ], %o0
a00f5d78:  d0 0f bf ea  ldub  [ %fp + -22 ], %o0
a00f5d7c:  7f ff f6 e2  call  0xa00f3904
a00f5d80:  ba 05 60 01  add  %l5, 1, %i5
a00f5d84:  80 8f 60 80  btst  0x80, %i5
a00f5d88:  02 bf ff 52  be  0xa00f5ad0
a00f5d8c:  aa 10 00 1d  mov  %i5, %l5
a00f5d90:  7f ff f6 d1  call  0xa00f38d4
a00f5d94:  d0 0f bf e0  ldub  [ %fp + -32 ], %o0
a00f5d98:  7f ff f6 d5  call  0xa00f38ec
a00f5d9c:  d0 0f bf e1  ldub  [ %fp + -31 ], %o0
a00f5da0:  7f ff f6 d9  call  0xa00f3904
a00f5da4:  d0 0f bf e2  ldub  [ %fp + -30 ], %o0
a00f5da8:  82 10 20 01  mov  1, %g1
a00f5dac:  c2 2d 23 ac  stb  %g1, [ %l4 + 0x3ac ]
a00f5db0:  82 10 20 00  clr  %g1
a00f5db4:  80 a0 60 00  cmp  %g1, 0
a00f5db8:  12 80 00 f2  bne  0xa00f6180
a00f5dbc:  90 10 20 00  clr  %o0
a00f5dc0:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00f5dc4:  80 a4 20 01  cmp  %l0, 1
a00f5dc8:  02 80 00 17  be  0xa00f5e24
a00f5dcc:  a4 10 20 01  mov  1, %l2
a00f5dd0:  e4 2d 23 ac  stb  %l2, [ %l4 + 0x3ac ]
a00f5dd4:  ee 0d 23 ac  ldub  [ %l4 + 0x3ac ], %l7
a00f5dd8:  80 a5 e0 01  cmp  %l7, 1
a00f5ddc:  02 80 01 02  be  0xa00f61e4
a00f5de0:  01 00 00 00  nop
a00f5de4:  90 10 00 11  mov  %l1, %o0
a00f5de8:  d4 0f bf df  ldub  [ %fp + -33 ], %o2
a00f5dec:  7f ff f1 2b  call  0xa00f2298
a00f5df0:  92 10 20 2a  mov  0x2a, %o1
a00f5df4:  90 10 00 11  mov  %l1, %o0
a00f5df8:  d4 0f bf de  ldub  [ %fp + -34 ], %o2
a00f5dfc:  7f ff ef 36  call  0xa00f1ad4
a00f5e00:  92 10 20 4a  mov  0x4a, %o1
a00f5e04:  29 2a 00 ad  sethi  %hi(0xa802b400), %l4
a00f5e08:  e2 0d 23 ac  ldub  [ %l4 + 0x3ac ], %l1	! 0xa802b7ac
a00f5e0c:  80 a0 00 11  cmp  %g0, %l1
a00f5e10:  10 80 01 25  b  0xa00f62a4
a00f5e14:  b0 60 3f ff  subx  %g0, -1, %i0
a00f5e18:  83 2c 20 04  sll  %l0, 4, %g1
a00f5e1c:  10 bf ff 19  b  0xa00f5a80
a00f5e20:  82 10 40 10  or  %g1, %l0, %g1
a00f5e24:  80 a6 60 00  cmp  %i1, 0
a00f5e28:  12 80 00 da  bne  0xa00f6190
a00f5e2c:  01 00 00 00  nop
a00f5e30:  7f ff f6 cc  call  0xa00f3960
a00f5e34:  ae 10 20 00  clr  %l7	! 0x0
a00f5e38:  7f ff f6 cf  call  0xa00f3974
a00f5e3c:  d0 2f bf e0  stb  %o0, [ %fp + -32 ]
a00f5e40:  7f ff f6 d2  call  0xa00f3988
a00f5e44:  d0 2f bf e1  stb  %o0, [ %fp + -31 ]
a00f5e48:  d0 2f bf e2  stb  %o0, [ %fp + -30 ]
a00f5e4c:  92 10 20 32  mov  0x32, %o1
a00f5e50:  94 10 20 f8  mov  0xf8, %o2
a00f5e54:  7f ff ef 20  call  0xa00f1ad4
a00f5e58:  90 10 00 11  mov  %l1, %o0
a00f5e5c:  40 00 0b e5  call  0xa00f8df0
a00f5e60:  90 10 00 11  mov  %l1, %o0
a00f5e64:  9b 2a 20 10  sll  %o0, 0x10, %o5
a00f5e68:  a5 33 60 10  srl  %o5, 0x10, %l2
a00f5e6c:  95 2c a0 02  sll  %l2, 2, %o2
a00f5e70:  92 02 80 12  add  %o2, %l2, %o1
a00f5e74:  b2 02 40 09  add  %o1, %o1, %i1
a00f5e78:  f2 27 bf d8  st  %i1, [ %fp + -40 ]
a00f5e7c:  39 00 00 20  sethi  %hi(0x8000), %i4
a00f5e80:  37 33 c0 00  sethi  %hi(0xcf000000), %i3
a00f5e84:  ac 04 80 12  add  %l2, %l2, %l6
a00f5e88:  b0 10 20 02  mov  2, %i0
a00f5e8c:  aa 26 00 17  sub  %i0, %l7, %l5
a00f5e90:  a6 0d 60 ff  and  %l5, 0xff, %l3
a00f5e94:  96 04 c0 1c  add  %l3, %i4, %o3
a00f5e98:  91 2a e0 02  sll  %o3, 2, %o0
a00f5e9c:  9e 12 00 1b  or  %o0, %i3, %o7
a00f5ea0:  e0 03 c0 00  ld  [ %o7 ], %l0
a00f5ea4:  b0 0c 20 ff  and  %l0, 0xff, %i0
a00f5ea8:  80 a6 20 07  cmp  %i0, 7
a00f5eac:  08 80 00 54  bleu  0xa00f5ffc
a00f5eb0:  aa 10 00 10  mov  %l0, %l5
a00f5eb4:  82 0d e0 ff  and  %l7, 0xff, %g1
a00f5eb8:  b4 10 20 02  mov  2, %i2
a00f5ebc:  ba 26 80 01  sub  %i2, %g1, %i5
a00f5ec0:  99 2f 60 03  sll  %i5, 3, %o4
a00f5ec4:  ba 03 3f 80  add  %o4, -128, %i5
a00f5ec8:  90 10 00 11  mov  %l1, %o0
a00f5ecc:  92 10 20 30  mov  0x30, %o1
a00f5ed0:  7f ff ef 01  call  0xa00f1ad4
a00f5ed4:  94 10 20 00  clr  %o2
a00f5ed8:  a0 26 80 17  sub  %i2, %l7, %l0
a00f5edc:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00f5ee0:  94 03 40 1c  add  %o5, %i4, %o2
a00f5ee4:  93 2a a0 02  sll  %o2, 2, %o1
a00f5ee8:  b2 12 40 1b  or  %o1, %i3, %i1
a00f5eec:  90 10 00 11  mov  %l1, %o0
a00f5ef0:  92 10 20 30  mov  0x30, %o1
a00f5ef4:  94 0f 60 f8  and  %i5, 0xf8, %o2
a00f5ef8:  f0 26 40 00  st  %i0, [ %i1 ]
a00f5efc:  7f ff ee f6  call  0xa00f1ad4
a00f5f00:  a6 10 20 00  clr  %l3
a00f5f04:  67 fe 5d a1  call  0x4008d588
a00f5f08:  01 00 00 00  nop
a00f5f0c:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00f5f10:  40 00 ad 19  call  0xa0121374
a00f5f14:  90 10 00 11  mov  %l1, %o0
a00f5f18:  82 0a 20 ff  and  %o0, 0xff, %g1
a00f5f1c:  92 10 20 30  mov  0x30, %o1
a00f5f20:  80 a0 60 01  cmp  %g1, 1
a00f5f24:  02 80 00 ac  be  0xa00f61d4
a00f5f28:  90 10 00 11  mov  %l1, %o0
a00f5f2c:  7f ff ee d9  call  0xa00f1a90
a00f5f30:  01 00 00 00  nop
a00f5f34:  80 8a 20 80  btst  0x80, %o0
a00f5f38:  02 80 00 a9  be  0xa00f61dc
a00f5f3c:  91 34 20 10  srl  %l0, 0x10, %o0
a00f5f40:  67 fe 5d 95  call  0x4008d594
a00f5f44:  01 00 00 00  nop
a00f5f48:  91 2a 20 10  sll  %o0, 0x10, %o0
a00f5f4c:  9f 32 20 10  srl  %o0, 0x10, %o7
a00f5f50:  80 a3 e0 63  cmp  %o7, 0x63
a00f5f54:  08 bf ff ef  bleu  0xa00f5f10
a00f5f58:  01 00 00 00  nop
a00f5f5c:  80 8c e0 ff  btst  0xff, %l3
a00f5f60:  12 80 00 05  bne  0xa00f5f74
a00f5f64:  e6 0d 23 ac  ldub  [ %l4 + 0x3ac ], %l3
a00f5f68:  96 10 20 01  mov  1, %o3
a00f5f6c:  d6 2d 23 ac  stb  %o3, [ %l4 + 0x3ac ]
a00f5f70:  e6 0d 23 ac  ldub  [ %l4 + 0x3ac ], %l3
a00f5f74:  80 a4 e0 01  cmp  %l3, 1
a00f5f78:  02 80 00 ab  be  0xa00f6224
a00f5f7c:  a6 10 20 00  clr  %l3
a00f5f80:  b2 10 20 00  clr  %i1
a00f5f84:  94 10 20 00  clr  %o2
a00f5f88:  90 10 00 11  mov  %l1, %o0
a00f5f8c:  7f ff ee d2  call  0xa00f1ad4
a00f5f90:  92 10 20 31  mov  0x31, %o1
a00f5f94:  92 10 20 34  mov  0x34, %o1
a00f5f98:  7f ff ef 53  call  0xa00f1ce4
a00f5f9c:  90 10 00 11  mov  %l1, %o0
a00f5fa0:  95 2a 20 10  sll  %o0, 0x10, %o2
a00f5fa4:  a1 32 a0 08  srl  %o2, 8, %l0
a00f5fa8:  92 10 20 33  mov  0x33, %o1
a00f5fac:  7f ff ee b9  call  0xa00f1a90
a00f5fb0:  90 10 00 11  mov  %l1, %o0
a00f5fb4:  92 0a 20 ff  and  %o0, 0xff, %o1
a00f5fb8:  b2 06 60 01  inc  %i1
a00f5fbc:  98 04 00 09  add  %l0, %o1, %o4
a00f5fc0:  82 05 80 12  add  %l6, %l2, %g1
a00f5fc4:  80 a0 40 0c  cmp  %g1, %o4
a00f5fc8:  0a 80 00 7d  bcs  0xa00f61bc
a00f5fcc:  94 0e 60 ff  and  %i1, 0xff, %o2
a00f5fd0:  80 a2 a0 07  cmp  %o2, 7
a00f5fd4:  08 bf ff ee  bleu  0xa00f5f8c
a00f5fd8:  90 10 00 11  mov  %l1, %o0
a00f5fdc:  80 8c e0 ff  btst  0xff, %l3
a00f5fe0:  12 80 00 08  bne  0xa00f6000
a00f5fe4:  80 a6 20 00  cmp  %i0, 0
a00f5fe8:  aa 05 7f f8  add  %l5, -8, %l5
a00f5fec:  b0 0d 60 ff  and  %l5, 0xff, %i0
a00f5ff0:  80 a6 20 07  cmp  %i0, 7
a00f5ff4:  18 bf ff b6  bgu  0xa00f5ecc
a00f5ff8:  90 10 00 11  mov  %l1, %o0
a00f5ffc:  80 a6 20 00  cmp  %i0, 0
a00f6000:  02 80 00 87  be  0xa00f621c
a00f6004:  9a 0d e0 ff  and  %l7, 0xff, %o5
a00f6008:  b4 10 20 02  mov  2, %i2
a00f600c:  ba 26 80 0d  sub  %i2, %o5, %i5
a00f6010:  b3 2f 60 03  sll  %i5, 3, %i1
a00f6014:  ba 06 7f 80  add  %i1, -128, %i5
a00f6018:  a6 10 20 00  clr  %l3
a00f601c:  a0 10 20 00  clr  %l0
a00f6020:  90 10 00 11  mov  %l1, %o0
a00f6024:  92 10 20 30  mov  0x30, %o1
a00f6028:  7f ff ee ab  call  0xa00f1ad4
a00f602c:  94 10 20 00  clr  %o2
a00f6030:  92 26 80 17  sub  %i2, %l7, %o1
a00f6034:  82 0a 60 ff  and  %o1, 0xff, %g1
a00f6038:  98 00 40 1c  add  %g1, %i4, %o4
a00f603c:  97 2b 20 02  sll  %o4, 2, %o3
a00f6040:  9e 12 c0 1b  or  %o3, %i3, %o7
a00f6044:  90 26 00 10  sub  %i0, %l0, %o0
a00f6048:  d0 23 c0 00  st  %o0, [ %o7 ]
a00f604c:  90 10 00 11  mov  %l1, %o0
a00f6050:  92 10 20 30  mov  0x30, %o1
a00f6054:  7f ff ee a0  call  0xa00f1ad4
a00f6058:  94 0f 60 f8  and  %i5, 0xf8, %o2
a00f605c:  67 fe 5d 4b  call  0x4008d588
a00f6060:  b2 10 20 00  clr  %i1
a00f6064:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00f6068:  40 00 ac c3  call  0xa0121374
a00f606c:  90 10 00 11  mov  %l1, %o0
a00f6070:  82 0a 20 ff  and  %o0, 0xff, %g1
a00f6074:  92 10 20 30  mov  0x30, %o1
a00f6078:  80 a0 60 01  cmp  %g1, 1
a00f607c:  02 80 00 52  be  0xa00f61c4
a00f6080:  90 10 00 11  mov  %l1, %o0
a00f6084:  7f ff ee 83  call  0xa00f1a90
a00f6088:  01 00 00 00  nop
a00f608c:  80 8a 20 80  btst  0x80, %o0
a00f6090:  02 80 00 4f  be  0xa00f61cc
a00f6094:  91 34 20 10  srl  %l0, 0x10, %o0
a00f6098:  67 fe 5d 3f  call  0x4008d594
a00f609c:  01 00 00 00  nop
a00f60a0:  9b 2a 20 10  sll  %o0, 0x10, %o5
a00f60a4:  95 33 60 10  srl  %o5, 0x10, %o2
a00f60a8:  80 a2 a0 63  cmp  %o2, 0x63
a00f60ac:  08 bf ff ef  bleu  0xa00f6068
a00f60b0:  01 00 00 00  nop
a00f60b4:  80 8e 60 ff  btst  0xff, %i1
a00f60b8:  12 80 00 05  bne  0xa00f60cc
a00f60bc:  f2 0d 23 ac  ldub  [ %l4 + 0x3ac ], %i1
a00f60c0:  a0 10 20 01  mov  1, %l0
a00f60c4:  e0 2d 23 ac  stb  %l0, [ %l4 + 0x3ac ]
a00f60c8:  f2 0d 23 ac  ldub  [ %l4 + 0x3ac ], %i1
a00f60cc:  80 a6 60 01  cmp  %i1, 1
a00f60d0:  02 80 00 55  be  0xa00f6224
a00f60d4:  94 10 20 07  mov  7, %o2
a00f60d8:  90 10 00 11  mov  %l1, %o0
a00f60dc:  7f ff ee 7e  call  0xa00f1ad4
a00f60e0:  92 10 20 31  mov  0x31, %o1
a00f60e4:  92 10 20 34  mov  0x34, %o1
a00f60e8:  7f ff ee ff  call  0xa00f1ce4
a00f60ec:  90 10 00 11  mov  %l1, %o0
a00f60f0:  99 2a 20 10  sll  %o0, 0x10, %o4
a00f60f4:  a1 33 20 08  srl  %o4, 8, %l0
a00f60f8:  90 10 00 11  mov  %l1, %o0
a00f60fc:  7f ff ee 65  call  0xa00f1a90
a00f6100:  92 10 20 33  mov  0x33, %o1
a00f6104:  96 0a 20 ff  and  %o0, 0xff, %o3
a00f6108:  9e 04 00 0b  add  %l0, %o3, %o7
a00f610c:  d0 07 bf d8  ld  [ %fp + -40 ], %o0
a00f6110:  80 a2 00 0f  cmp  %o0, %o7
a00f6114:  0a 80 00 08  bcs  0xa00f6134
a00f6118:  9a 10 20 02  mov  2, %o5
a00f611c:  a6 04 e0 01  inc  %l3
a00f6120:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00f6124:  80 a4 20 0f  cmp  %l0, 0xf
a00f6128:  08 bf ff bf  bleu  0xa00f6024
a00f612c:  90 10 00 11  mov  %l1, %o0
a00f6130:  9a 10 20 02  mov  2, %o5
a00f6134:  94 23 40 17  sub  %o5, %l7, %o2
a00f6138:  92 0a a0 ff  and  %o2, 0xff, %o1
a00f613c:  ba 25 40 13  sub  %l5, %l3, %i5
a00f6140:  82 02 40 1c  add  %o1, %i4, %g1
a00f6144:  a7 28 60 02  sll  %g1, 2, %l3
a00f6148:  ae 05 e0 01  inc  %l7
a00f614c:  aa 14 c0 1b  or  %l3, %i3, %l5
a00f6150:  b0 0f 60 ff  and  %i5, 0xff, %i0
a00f6154:  b4 0d e0 ff  and  %l7, 0xff, %i2
a00f6158:  f0 25 40 00  st  %i0, [ %l5 ]
a00f615c:  80 a6 a0 02  cmp  %i2, 2
a00f6160:  08 bf ff 4b  bleu  0xa00f5e8c
a00f6164:  b0 10 20 02  mov  2, %i0
a00f6168:  82 10 20 01  mov  1, %g1
a00f616c:  80 a0 60 00  cmp  %g1, 0
a00f6170:  12 bf ff 1a  bne  0xa00f5dd8
a00f6174:  ee 0d 23 ac  ldub  [ %l4 + 0x3ac ], %l7
a00f6178:  10 bf ff 16  b  0xa00f5dd0
a00f617c:  a4 10 20 01  mov  1, %l2
a00f6180:  7f ff fc 0d  call  0xa00f51b4
a00f6184:  90 0d a0 ff  and  %l6, 0xff, %o0
a00f6188:  10 bf ff 0e  b  0xa00f5dc0
a00f618c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f6190:  7f ff fb 34  call  0xa00f4e60
a00f6194:  90 10 00 11  mov  %l1, %o0
a00f6198:  80 8a 20 ff  btst  0xff, %o0
a00f619c:  22 bf ff 0e  be,a   0xa00f5dd4
a00f61a0:  e0 2d 23 ac  stb  %l0, [ %l4 + 0x3ac ]
a00f61a4:  10 bf ff 0d  b  0xa00f5dd8
a00f61a8:  ee 0d 23 ac  ldub  [ %l4 + 0x3ac ], %l7
a00f61ac:  10 bf fe 64  b  0xa00f5b3c
a00f61b0:  c2 2d 23 ac  stb  %g1, [ %l4 + 0x3ac ]
a00f61b4:  10 bf fe 62  b  0xa00f5b3c
a00f61b8:  a4 10 20 01  mov  1, %l2
a00f61bc:  10 bf ff 88  b  0xa00f5fdc
a00f61c0:  a6 10 3f ff  mov  -1, %l3
a00f61c4:  10 bf ff bc  b  0xa00f60b4
a00f61c8:  c2 2d 23 ac  stb  %g1, [ %l4 + 0x3ac ]
a00f61cc:  10 bf ff ba  b  0xa00f60b4
a00f61d0:  b2 10 20 01  mov  1, %i1
a00f61d4:  10 bf ff 62  b  0xa00f5f5c
a00f61d8:  c2 2d 23 ac  stb  %g1, [ %l4 + 0x3ac ]
a00f61dc:  10 bf ff 60  b  0xa00f5f5c
a00f61e0:  a6 10 20 01  mov  1, %l3
a00f61e4:  7f ff f5 cd  call  0xa00f3918
a00f61e8:  d0 0f bf f0  ldub  [ %fp + -16 ], %o0
a00f61ec:  7f ff f5 d1  call  0xa00f3930
a00f61f0:  d0 0f bf f1  ldub  [ %fp + -15 ], %o0
a00f61f4:  7f ff f5 d5  call  0xa00f3948
a00f61f8:  d0 0f bf f2  ldub  [ %fp + -14 ], %o0
a00f61fc:  7f ff f5 b6  call  0xa00f38d4
a00f6200:  d0 0f bf f3  ldub  [ %fp + -13 ], %o0
a00f6204:  7f ff f5 ba  call  0xa00f38ec
a00f6208:  d0 0f bf f4  ldub  [ %fp + -12 ], %o0
a00f620c:  7f ff f5 be  call  0xa00f3904
a00f6210:  d0 0f bf f5  ldub  [ %fp + -11 ], %o0
a00f6214:  10 bf fe f5  b  0xa00f5de8
a00f6218:  90 10 00 11  mov  %l1, %o0
a00f621c:  ac 10 20 01  mov  1, %l6
a00f6220:  ec 2d 23 ac  stb  %l6, [ %l4 + 0x3ac ]
a00f6224:  7f ff f5 ac  call  0xa00f38d4
a00f6228:  d0 0f bf e0  ldub  [ %fp + -32 ], %o0
a00f622c:  7f ff f5 b0  call  0xa00f38ec
a00f6230:  d0 0f bf e1  ldub  [ %fp + -31 ], %o0
a00f6234:  7f ff f5 b4  call  0xa00f3904
a00f6238:  d0 0f bf e2  ldub  [ %fp + -30 ], %o0
a00f623c:  10 bf ff cc  b  0xa00f616c
a00f6240:  82 10 20 00  clr  %g1
a00f6244:  7f ff f5 a4  call  0xa00f38d4
a00f6248:  d0 0f bf e0  ldub  [ %fp + -32 ], %o0
a00f624c:  7f ff f5 a8  call  0xa00f38ec
a00f6250:  d0 0f bf e1  ldub  [ %fp + -31 ], %o0
a00f6254:  7f ff f5 ac  call  0xa00f3904
a00f6258:  d0 0f bf e2  ldub  [ %fp + -30 ], %o0
a00f625c:  10 bf fe d6  b  0xa00f5db4
a00f6260:  82 10 20 00  clr  %g1
a00f6264:  aa 06 3f f8  add  %i0, -8, %l5
a00f6268:  a6 0d 60 ff  and  %l5, 0xff, %l3
a00f626c:  80 a4 e0 f0  cmp  %l3, 0xf0
a00f6270:  18 bf fe c8  bgu  0xa00f5d90
a00f6274:  ee 0f bf e9  ldub  [ %fp + -23 ], %l7
a00f6278:  a4 05 ff f8  add  %l7, -8, %l2
a00f627c:  98 0c a0 ff  and  %l2, 0xff, %o4
a00f6280:  80 a3 20 f0  cmp  %o4, 0xf0
a00f6284:  18 bf fe c3  bgu  0xa00f5d90
a00f6288:  f8 0f bf ea  ldub  [ %fp + -22 ], %i4
a00f628c:  b6 07 3f f8  add  %i4, -8, %i3
a00f6290:  b4 0e e0 ff  and  %i3, 0xff, %i2
a00f6294:  80 a6 a0 f0  cmp  %i2, 0xf0
a00f6298:  08 bf fe c7  bleu  0xa00f5db4
a00f629c:  82 10 20 01  mov  1, %g1
a00f62a0:  30 bf fe bc  b,a   0xa00f5d90
a00f62a4:  81 c7 e0 08  ret
a00f62a8:  81 e8 00 00  restore
