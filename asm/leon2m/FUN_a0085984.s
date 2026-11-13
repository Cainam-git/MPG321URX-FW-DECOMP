# leon2m FUN_a0085984 0xa0085984-0xa00869b0 (3620 bytes)
a0085984:  9d e3 bf 98  save  %sp, -104, %sp
a0085988:  40 02 7b a8  call  0xa0124828
a008598c:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a0085990:  90 0a 20 ff  and  %o0, 0xff, %o0
a0085994:  80 a2 20 01  cmp  %o0, 1
a0085998:  02 80 02 3b  be  0xa0086284
a008599c:  01 00 00 00  nop
a00859a0:  40 02 dd 33  call  0xa013ce6c
a00859a4:  90 10 20 00  clr  %o0	! 0x0
a00859a8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00859ac:  80 a2 20 0c  cmp  %o0, 0xc
a00859b0:  02 80 02 18  be  0xa0086210
a00859b4:  01 00 00 00  nop
a00859b8:  40 02 8f 0b  call  0xa01295e4
a00859bc:  01 00 00 00  nop
a00859c0:  40 02 88 ae  call  0xa0127c78
a00859c4:  01 00 00 00  nop
a00859c8:  40 02 88 05  call  0xa01279dc
a00859cc:  01 00 00 00  nop
a00859d0:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00859d4:  80 a4 20 01  cmp  %l0, 1
a00859d8:  02 80 01 d1  be  0xa008611c
a00859dc:  82 10 3f ff  mov  -1, %g1
a00859e0:  19 2a 00 90  sethi  %hi(0xa8024000), %o4
a00859e4:  21 2a 00 90  sethi  %hi(0xa8024000), %l0
a00859e8:  c2 2b 20 00  stb  %g1, [ %o4 ]
a00859ec:  c2 2c 20 01  stb  %g1, [ %l0 + 1 ]
a00859f0:  40 02 87 fb  call  0xa01279dc
a00859f4:  01 00 00 00  nop
a00859f8:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00859fc:  80 a3 60 01  cmp  %o5, 1
a0085a00:  02 80 01 a3  be  0xa008608c
a0085a04:  23 2a 00 b3  sethi  %hi(0xa802cc00), %l1
a0085a08:  b0 14 63 f4  or  %l1, 0x3f4, %i0	! 0xa802cff4
a0085a0c:  d6 16 20 04  lduh  [ %i0 + 4 ], %o3
a0085a10:  1f 00 00 18  sethi  %hi(0x6000), %o7
a0085a14:  80 8b c0 0b  btst  %o7, %o3
a0085a18:  02 80 01 22  be  0xa0085ea0
a0085a1c:  82 14 a2 90  or  %l2, 0x290, %g1
a0085a20:  e0 08 60 1f  ldub  [ %g1 + 0x1f ], %l0
a0085a24:  80 a4 20 00  cmp  %l0, 0
a0085a28:  12 80 00 f5  bne  0xa0085dfc
a0085a2c:  98 14 a2 90  or  %l2, 0x290, %o4
a0085a30:  d0 03 20 ac  ld  [ %o4 + 0xac ], %o0
a0085a34:  31 00 04 00  sethi  %hi(0x100000), %i0
a0085a38:  80 8a 00 18  btst  %o0, %i0
a0085a3c:  02 80 00 06  be  0xa0085a54
a0085a40:  01 00 00 00  nop
a0085a44:  f2 0b 20 1f  ldub  [ %o4 + 0x1f ], %i1
a0085a48:  80 a6 60 00  cmp  %i1, 0
a0085a4c:  02 80 00 81  be  0xa0085c50
a0085a50:  01 00 00 00  nop
a0085a54:  40 03 07 4f  call  0xa0147790
a0085a58:  01 00 00 00  nop
a0085a5c:  40 00 03 f8  call  0xa0086a3c
a0085a60:  90 10 20 01  mov  1, %o0	! 0x1
a0085a64:  91 2a 20 10  sll  %o0, 0x10, %o0
a0085a68:  80 a2 20 00  cmp  %o0, 0
a0085a6c:  02 80 00 d2  be  0xa0085db4
a0085a70:  90 10 20 01  mov  1, %o0
a0085a74:  7f ff f9 5f  call  0xa0083ff0
a0085a78:  90 10 20 00  clr  %o0
a0085a7c:  40 00 03 f0  call  0xa0086a3c
a0085a80:  90 10 20 14  mov  0x14, %o0
a0085a84:  b3 2a 20 10  sll  %o0, 0x10, %i1
a0085a88:  80 a6 60 00  cmp  %i1, 0
a0085a8c:  12 80 00 0a  bne  0xa0085ab4
a0085a90:  a0 14 a2 90  or  %l2, 0x290, %l0
a0085a94:  9a 14 63 f4  or  %l1, 0x3f4, %o5
a0085a98:  c2 13 60 0a  lduh  [ %o5 + 0xa ], %g1
a0085a9c:  80 88 60 40  btst  0x40, %g1
a0085aa0:  22 80 00 06  be,a   0xa0085ab8
a0085aa4:  d8 0c 20 4a  ldub  [ %l0 + 0x4a ], %o4
a0085aa8:  82 08 7f bf  and  %g1, -65, %g1
a0085aac:  c2 33 60 0a  sth  %g1, [ %o5 + 0xa ]
a0085ab0:  a0 14 a2 90  or  %l2, 0x290, %l0
a0085ab4:  d8 0c 20 4a  ldub  [ %l0 + 0x4a ], %o4
a0085ab8:  80 a3 20 00  cmp  %o4, 0
a0085abc:  12 80 00 a6  bne  0xa0085d54
a0085ac0:  01 00 00 00  nop
a0085ac4:  40 00 03 de  call  0xa0086a3c
a0085ac8:  90 10 20 15  mov  0x15, %o0	! 0x15
a0085acc:  95 2a 20 10  sll  %o0, 0x10, %o2
a0085ad0:  80 a2 a0 00  cmp  %o2, 0
a0085ad4:  02 80 00 7b  be  0xa0085cc0
a0085ad8:  01 00 00 00  nop
a0085adc:  40 00 03 d8  call  0xa0086a3c
a0085ae0:  90 10 20 16  mov  0x16, %o0	! 0x16
a0085ae4:  93 2a 20 10  sll  %o0, 0x10, %o1
a0085ae8:  80 a2 60 00  cmp  %o1, 0
a0085aec:  12 80 00 0c  bne  0xa0085b1c
a0085af0:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0085af4:  9a 14 63 f4  or  %l1, 0x3f4, %o5
a0085af8:  c2 13 60 04  lduh  [ %o5 + 4 ], %g1
a0085afc:  80 88 68 00  btst  0x800, %g1
a0085b00:  02 80 00 08  be  0xa0085b20
a0085b04:  d6 0c 23 41  ldub  [ %l0 + 0x341 ], %o3
a0085b08:  b0 08 77 ff  and  %g1, -2049, %i0
a0085b0c:  f0 33 60 04  sth  %i0, [ %o5 + 4 ]
a0085b10:  40 02 80 2b  call  0xa0125bbc
a0085b14:  90 10 20 01  mov  1, %o0
a0085b18:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0085b1c:  d6 0c 23 41  ldub  [ %l0 + 0x341 ], %o3	! 0xa802af41
a0085b20:  80 8a e0 01  btst  1, %o3
a0085b24:  12 80 01 47  bne  0xa0086040
a0085b28:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0085b2c:  c2 16 63 42  lduh  [ %i1 + 0x342 ], %g1	! 0xa802af42
a0085b30:  80 88 60 10  btst  0x10, %g1
a0085b34:  02 80 00 e8  be  0xa0085ed4
a0085b38:  31 00 00 10  sethi  %hi(0x4000), %i0
a0085b3c:  a0 14 a2 90  or  %l2, 0x290, %l0
a0085b40:  c2 0c 21 d5  ldub  [ %l0 + 0x1d5 ], %g1
a0085b44:  80 a0 60 00  cmp  %g1, 0
a0085b48:  02 80 01 fa  be  0xa0086330
a0085b4c:  01 00 00 00  nop
a0085b50:  40 00 03 bb  call  0xa0086a3c
a0085b54:  90 10 20 0b  mov  0xb, %o0	! 0xb
a0085b58:  99 2a 20 10  sll  %o0, 0x10, %o4
a0085b5c:  80 a3 20 00  cmp  %o4, 0
a0085b60:  12 80 01 3e  bne  0xa0086058
a0085b64:  01 00 00 00  nop
a0085b68:  40 02 7b d2  call  0xa0124ab0
a0085b6c:  01 00 00 00  nop
a0085b70:  40 02 7b e2  call  0xa0124af8
a0085b74:  01 00 00 00  nop
a0085b78:  de 04 20 a8  ld  [ %l0 + 0xa8 ], %o7
a0085b7c:  94 13 e0 40  or  %o7, 0x40, %o2
a0085b80:  40 01 4f 7e  call  0xa00d9978
a0085b84:  d4 24 20 a8  st  %o2, [ %l0 + 0xa8 ]
a0085b88:  7f ff f3 de  call  0xa0082b00
a0085b8c:  a0 14 63 f4  or  %l1, 0x3f4, %l0
a0085b90:  90 10 20 ff  mov  0xff, %o0
a0085b94:  40 00 24 b6  call  0xa008ee6c
a0085b98:  92 10 20 00  clr  %o1
a0085b9c:  da 14 20 04  lduh  [ %l0 + 4 ], %o5
a0085ba0:  80 8b 62 00  btst  0x200, %o5
a0085ba4:  02 80 02 ec  be  0xa0086754
a0085ba8:  01 00 00 00  nop
a0085bac:  90 10 20 0b  mov  0xb, %o0	! 0xb
a0085bb0:  92 10 23 e8  mov  0x3e8, %o1
a0085bb4:  40 00 03 7f  call  0xa00869b0
a0085bb8:  01 00 00 00  nop
a0085bbc:  40 02 79 a2  call  0xa0124244
a0085bc0:  90 10 20 00  clr  %o0	! 0x0
a0085bc4:  40 01 21 e1  call  0xa00ce348
a0085bc8:  01 00 00 00  nop
a0085bcc:  40 00 d7 bc  call  0xa00bbabc
a0085bd0:  01 00 00 00  nop
a0085bd4:  92 14 a2 90  or  %l2, 0x290, %o1
a0085bd8:  e4 0a 60 1f  ldub  [ %o1 + 0x1f ], %l2
a0085bdc:  80 a4 a0 02  cmp  %l2, 2
a0085be0:  12 80 03 72  bne  0xa00869a8
a0085be4:  01 00 00 00  nop
a0085be8:  d0 0a 60 2f  ldub  [ %o1 + 0x2f ], %o0
a0085bec:  80 a2 20 00  cmp  %o0, 0
a0085bf0:  12 80 03 6e  bne  0xa00869a8
a0085bf4:  01 00 00 00  nop
a0085bf8:  40 02 f8 07  call  0xa0143c14
a0085bfc:  90 10 20 01  mov  1, %o0	! 0x1
a0085c00:  82 0a 20 ff  and  %o0, 0xff, %g1
a0085c04:  80 a0 60 07  cmp  %g1, 7
a0085c08:  08 80 03 68  bleu  0xa00869a8
a0085c0c:  01 00 00 00  nop
a0085c10:  40 02 fa 1f  call  0xa014448c
a0085c14:  90 10 20 01  mov  1, %o0	! 0x1
a0085c18:  98 0a 20 ff  and  %o0, 0xff, %o4
a0085c1c:  80 a3 20 0d  cmp  %o4, 0xd
a0085c20:  12 80 03 62  bne  0xa00869a8
a0085c24:  01 00 00 00  nop
a0085c28:  40 00 03 85  call  0xa0086a3c
a0085c2c:  90 10 20 11  mov  0x11, %o0	! 0x11
a0085c30:  91 2a 20 10  sll  %o0, 0x10, %o0
a0085c34:  80 a2 20 00  cmp  %o0, 0
a0085c38:  12 80 03 5c  bne  0xa00869a8
a0085c3c:  01 00 00 00  nop
a0085c40:  7f ff f9 bc  call  0xa0084330
a0085c44:  b0 10 20 11  mov  0x11, %i0	! 0x11
a0085c48:  40 00 03 5a  call  0xa00869b0
a0085c4c:  93 e8 20 c8  restore  %g0, 0xc8, %o1
a0085c50:  40 02 87 37  call  0xa012792c
a0085c54:  01 00 00 00  nop
a0085c58:  80 8a 20 ff  btst  0xff, %o0
a0085c5c:  12 bf ff 7e  bne  0xa0085a54
a0085c60:  01 00 00 00  nop
a0085c64:  40 02 87 38  call  0xa0127944
a0085c68:  01 00 00 00  nop
a0085c6c:  80 8a 20 ff  btst  0xff, %o0
a0085c70:  12 bf ff 79  bne  0xa0085a54
a0085c74:  01 00 00 00  nop
a0085c78:  40 03 06 c6  call  0xa0147790
a0085c7c:  01 00 00 00  nop
a0085c80:  a0 0a 20 ff  and  %o0, 0xff, %l0
a0085c84:  80 a4 20 00  cmp  %l0, 0
a0085c88:  02 80 00 07  be  0xa0085ca4
a0085c8c:  80 a4 20 07  cmp  %l0, 7
a0085c90:  03 00 03 fc  sethi  %hi(0xff000), %g1
a0085c94:  90 10 63 20  or  %g1, 0x320, %o0	! 0xff320
a0085c98:  40 01 65 36  call  0xa00df170
a0085c9c:  92 10 00 10  mov  %l0, %o1
a0085ca0:  80 a4 20 07  cmp  %l0, 7
a0085ca4:  18 bf ff 6e  bgu  0xa0085a5c
a0085ca8:  13 00 00 80  sethi  %hi(0x20000), %o1
a0085cac:  99 2c 20 02  sll  %l0, 2, %o4
a0085cb0:  9a 12 63 00  or  %o1, 0x300, %o5
a0085cb4:  e0 03 40 0c  ld  [ %o5 + %o4 ], %l0
a0085cb8:  81 c4 00 00  jmp  %l0
a0085cbc:  01 00 00 00  nop
a0085cc0:  40 02 7b 60  call  0xa0124a40
a0085cc4:  01 00 00 00  nop
a0085cc8:  80 8a 20 ff  btst  0xff, %o0
a0085ccc:  02 bf ff 84  be  0xa0085adc
a0085cd0:  17 00 00 13  sethi  %hi(0x4c00), %o3
a0085cd4:  92 12 e2 20  or  %o3, 0x220, %o1	! 0x4e20
a0085cd8:  40 00 03 36  call  0xa00869b0
a0085cdc:  90 10 20 15  mov  0x15, %o0
a0085ce0:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a0085ce4:  f0 0a e3 47  ldub  [ %o3 + 0x347 ], %i0	! 0xa802af47
a0085ce8:  82 06 20 01  add  %i0, 1, %g1
a0085cec:  9e 08 60 ff  and  %g1, 0xff, %o7
a0085cf0:  80 a3 e0 03  cmp  %o7, 3
a0085cf4:  28 bf ff 7a  bleu,a   0xa0085adc
a0085cf8:  c2 2a e3 47  stb  %g1, [ %o3 + 0x347 ]
a0085cfc:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a0085d00:  92 13 22 74  or  %o4, 0x274, %o1	! 0xa802d274
a0085d04:  c2 0a 60 11  ldub  [ %o1 + 0x11 ], %g1
a0085d08:  9a 00 60 01  add  %g1, 1, %o5
a0085d0c:  90 0b 60 ff  and  %o5, 0xff, %o0
a0085d10:  b2 10 20 01  mov  1, %i1
a0085d14:  80 a2 20 3b  cmp  %o0, 0x3b
a0085d18:  08 80 02 13  bleu  0xa0086564
a0085d1c:  f2 2a e3 47  stb  %i1, [ %o3 + 0x347 ]
a0085d20:  15 00 00 3f  sethi  %hi(0xfc00), %o2
a0085d24:  da 12 60 12  lduh  [ %o1 + 0x12 ], %o5
a0085d28:  a0 12 a3 ff  or  %o2, 0x3ff, %l0
a0085d2c:  80 a3 40 10  cmp  %o5, %l0
a0085d30:  02 bf ff 6b  be  0xa0085adc
a0085d34:  c0 2a 60 11  clrb  [ %o1 + 0x11 ]
a0085d38:  9e 03 60 01  add  %o5, 1, %o7
a0085d3c:  de 32 60 12  sth  %o7, [ %o1 + 0x12 ]
a0085d40:  94 10 22 e0  mov  0x2e0, %o2
a0085d44:  96 10 20 1c  mov  0x1c, %o3
a0085d48:  40 03 14 62  call  0xa014aed0
a0085d4c:  90 10 20 30  mov  0x30, %o0
a0085d50:  30 bf ff 63  b,a   0xa0085adc
a0085d54:  40 01 47 fd  call  0xa00d7d48
a0085d58:  01 00 00 00  nop
a0085d5c:  80 a2 20 00  cmp  %o0, 0
a0085d60:  12 bf ff 59  bne  0xa0085ac4
a0085d64:  01 00 00 00  nop
a0085d68:  da 0c 20 1f  ldub  [ %l0 + 0x1f ], %o5
a0085d6c:  80 a3 60 00  cmp  %o5, 0
a0085d70:  12 bf ff 55  bne  0xa0085ac4
a0085d74:  01 00 00 00  nop
a0085d78:  40 02 f7 a7  call  0xa0143c14
a0085d7c:  01 00 00 00  nop
a0085d80:  a0 0a 20 ff  and  %o0, 0xff, %l0
a0085d84:  80 a4 20 0a  cmp  %l0, 0xa
a0085d88:  12 bf ff 4f  bne  0xa0085ac4
a0085d8c:  01 00 00 00  nop
a0085d90:  40 02 f7 a1  call  0xa0143c14
a0085d94:  90 10 20 01  mov  1, %o0	! 0x1
a0085d98:  92 0a 20 ff  and  %o0, 0xff, %o1
a0085d9c:  80 a2 60 0a  cmp  %o1, 0xa
a0085da0:  12 bf ff 49  bne  0xa0085ac4
a0085da4:  90 10 20 01  mov  1, %o0
a0085da8:  40 03 1d b3  call  0xa014d474
a0085dac:  92 10 20 01  mov  1, %o1
a0085db0:  30 bf ff 45  b,a   0xa0085ac4
a0085db4:  40 00 02 ff  call  0xa00869b0
a0085db8:  92 10 23 e8  mov  0x3e8, %o1
a0085dbc:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0085dc0:  c2 0c 23 44  ldub  [ %l0 + 0x344 ], %g1	! 0xa802af44
a0085dc4:  80 88 60 01  btst  1, %g1
a0085dc8:  12 80 01 d1  bne  0xa008650c
a0085dcc:  01 00 00 00  nop
a0085dd0:  80 88 60 02  btst  2, %g1
a0085dd4:  12 80 01 c8  bne  0xa00864f4
a0085dd8:  90 10 20 30  mov  0x30, %o0
a0085ddc:  80 88 60 04  btst  4, %g1
a0085de0:  12 80 01 c1  bne  0xa00864e4
a0085de4:  01 00 00 00  nop
a0085de8:  80 88 60 08  btst  8, %g1
a0085dec:  12 80 01 ba  bne  0xa00864d4
a0085df0:  01 00 00 00  nop
a0085df4:  10 bf ff 20  b  0xa0085a74
a0085df8:  c0 2c 23 44  clrb  [ %l0 + 0x344 ]
a0085dfc:  40 02 f7 86  call  0xa0143c14
a0085e00:  90 10 20 00  clr  %o0
a0085e04:  98 0a 20 ff  and  %o0, 0xff, %o4
a0085e08:  80 a3 20 08  cmp  %o4, 8
a0085e0c:  08 80 00 07  bleu  0xa0085e28
a0085e10:  01 00 00 00  nop
a0085e14:  40 01 47 cd  call  0xa00d7d48
a0085e18:  01 00 00 00  nop
a0085e1c:  80 a2 20 00  cmp  %o0, 0
a0085e20:  12 80 00 0e  bne  0xa0085e58
a0085e24:  9e 14 a2 90  or  %l2, 0x290, %o7
a0085e28:  40 02 f7 7b  call  0xa0143c14
a0085e2c:  90 10 20 01  mov  1, %o0
a0085e30:  9a 0a 20 ff  and  %o0, 0xff, %o5
a0085e34:  80 a3 60 08  cmp  %o5, 8
a0085e38:  08 bf fe fe  bleu  0xa0085a30
a0085e3c:  98 14 a2 90  or  %l2, 0x290, %o4
a0085e40:  40 02 f6 a7  call  0xa01438dc
a0085e44:  90 10 20 01  mov  1, %o0
a0085e48:  92 0a 20 ff  and  %o0, 0xff, %o1
a0085e4c:  80 a2 60 01  cmp  %o1, 1
a0085e50:  12 80 01 bd  bne  0xa0086544
a0085e54:  9e 14 a2 90  or  %l2, 0x290, %o7
a0085e58:  c0 2b e0 1f  clrb  [ %o7 + 0x1f ]
a0085e5c:  40 01 4c e8  call  0xa00d91fc
a0085e60:  90 10 20 00  clr  %o0
a0085e64:  90 10 20 00  clr  %o0
a0085e68:  40 03 09 00  call  0xa0148268
a0085e6c:  92 10 20 01  mov  1, %o1
a0085e70:  92 10 20 01  mov  1, %o1
a0085e74:  40 03 08 fd  call  0xa0148268
a0085e78:  90 10 20 01  mov  1, %o0
a0085e7c:  40 00 2c 57  call  0xa0090fd8
a0085e80:  01 00 00 00  nop
a0085e84:  17 00 03 fc  sethi  %hi(0xff000), %o3
a0085e88:  40 01 64 ba  call  0xa00df170
a0085e8c:  90 12 e3 40  or  %o3, 0x340, %o0	! 0xff340
a0085e90:  40 01 50 f1  call  0xa00da254
a0085e94:  01 00 00 00  nop
a0085e98:  10 bf fe e6  b  0xa0085a30
a0085e9c:  98 14 a2 90  or  %l2, 0x290, %o4
a0085ea0:  40 00 02 e7  call  0xa0086a3c
a0085ea4:  90 10 20 13  mov  0x13, %o0
a0085ea8:  91 2a 20 10  sll  %o0, 0x10, %o0
a0085eac:  80 a2 20 00  cmp  %o0, 0
a0085eb0:  32 bf fe dc  bne,a   0xa0085a20
a0085eb4:  82 14 a2 90  or  %l2, 0x290, %g1
a0085eb8:  40 01 52 f1  call  0xa00daa7c
a0085ebc:  33 00 00 13  sethi  %hi(0x4c00), %i1
a0085ec0:  92 16 62 20  or  %i1, 0x220, %o1	! 0x4e20
a0085ec4:  40 00 02 bb  call  0xa00869b0
a0085ec8:  90 10 20 13  mov  0x13, %o0
a0085ecc:  10 bf fe d5  b  0xa0085a20
a0085ed0:  82 14 a2 90  or  %l2, 0x290, %g1
a0085ed4:  80 88 40 18  btst  %g1, %i0
a0085ed8:  02 80 00 60  be  0xa0086058
a0085edc:  01 00 00 00  nop
a0085ee0:  a0 14 a2 90  or  %l2, 0x290, %l0
a0085ee4:  d0 0c 21 d5  ldub  [ %l0 + 0x1d5 ], %o0
a0085ee8:  80 a2 20 00  cmp  %o0, 0
a0085eec:  02 80 01 4f  be  0xa0086428
a0085ef0:  01 00 00 00  nop
a0085ef4:  40 02 86 8e  call  0xa012792c
a0085ef8:  01 00 00 00  nop
a0085efc:  80 8a 20 ff  btst  0xff, %o0
a0085f00:  12 80 00 56  bne  0xa0086058
a0085f04:  01 00 00 00  nop
a0085f08:  40 02 86 8f  call  0xa0127944
a0085f0c:  01 00 00 00  nop
a0085f10:  80 8a 20 ff  btst  0xff, %o0
a0085f14:  12 80 00 51  bne  0xa0086058
a0085f18:  03 00 00 20  sethi  %hi(0x8000), %g1
a0085f1c:  d8 04 20 a8  ld  [ %l0 + 0xa8 ], %o4
a0085f20:  80 8b 00 01  btst  %o4, %g1
a0085f24:  02 80 00 07  be  0xa0085f40
a0085f28:  94 14 63 f4  or  %l1, 0x3f4, %o2
a0085f2c:  f2 12 a0 04  lduh  [ %o2 + 4 ], %i1
a0085f30:  1b 00 00 18  sethi  %hi(0x6000), %o5
a0085f34:  80 8b 40 19  btst  %o5, %i1
a0085f38:  12 80 00 48  bne  0xa0086058
a0085f3c:  01 00 00 00  nop
a0085f40:  40 00 02 bf  call  0xa0086a3c
a0085f44:  90 10 20 0b  mov  0xb, %o0	! 0xb
a0085f48:  9f 2a 20 10  sll  %o0, 0x10, %o7
a0085f4c:  80 a3 e0 00  cmp  %o7, 0
a0085f50:  12 80 00 42  bne  0xa0086058
a0085f54:  b2 14 63 f4  or  %l1, 0x3f4, %i1
a0085f58:  e2 16 60 14  lduh  [ %i1 + 0x14 ], %l1
a0085f5c:  80 8e 00 11  btst  %i0, %l1
a0085f60:  12 80 00 3e  bne  0xa0086058
a0085f64:  01 00 00 00  nop
a0085f68:  40 02 7a d2  call  0xa0124ab0
a0085f6c:  01 00 00 00  nop
a0085f70:  40 02 7a e2  call  0xa0124af8
a0085f74:  01 00 00 00  nop
a0085f78:  c2 04 20 a8  ld  [ %l0 + 0xa8 ], %g1
a0085f7c:  90 10 60 40  or  %g1, 0x40, %o0
a0085f80:  40 01 4e 7e  call  0xa00d9978
a0085f84:  d0 24 20 a8  st  %o0, [ %l0 + 0xa8 ]
a0085f88:  17 00 00 15  sethi  %hi(0x5400), %o3
a0085f8c:  f0 14 21 f6  lduh  [ %l0 + 0x1f6 ], %i0
a0085f90:  92 12 e1 aa  or  %o3, 0x1aa, %o1
a0085f94:  80 a6 00 09  cmp  %i0, %o1
a0085f98:  12 80 00 0c  bne  0xa0085fc8
a0085f9c:  01 00 00 00  nop
a0085fa0:  40 01 3a 74  call  0xa00d4970
a0085fa4:  01 00 00 00  nop
a0085fa8:  40 02 7b df  call  0xa0124f24
a0085fac:  01 00 00 00  nop
a0085fb0:  40 02 7e 68  call  0xa0125950
a0085fb4:  01 00 00 00  nop
a0085fb8:  40 02 7e 74  call  0xa0125988
a0085fbc:  01 00 00 00  nop
a0085fc0:  40 02 7f 01  call  0xa0125bc4
a0085fc4:  01 00 00 00  nop
a0085fc8:  40 02 db 78  call  0xa013cda8
a0085fcc:  90 10 20 03  mov  3, %o0	! 0x3
a0085fd0:  92 10 20 00  clr  %o1
a0085fd4:  40 02 09 35  call  0xa01084a8
a0085fd8:  90 0a 20 ff  and  %o0, 0xff, %o0
a0085fdc:  40 02 db 73  call  0xa013cda8
a0085fe0:  90 10 20 03  mov  3, %o0
a0085fe4:  90 0a 20 ff  and  %o0, 0xff, %o0
a0085fe8:  40 02 0d 5b  call  0xa0109554
a0085fec:  92 10 20 00  clr  %o1
a0085ff0:  7f ff f2 c4  call  0xa0082b00
a0085ff4:  01 00 00 00  nop
a0085ff8:  c2 16 60 04  lduh  [ %i1 + 4 ], %g1
a0085ffc:  80 88 62 00  btst  0x200, %g1
a0086000:  32 80 00 05  bne,a   0xa0086014
a0086004:  c2 0c 21 d5  ldub  [ %l0 + 0x1d5 ], %g1
a0086008:  98 10 62 00  or  %g1, 0x200, %o4
a008600c:  d8 36 60 04  sth  %o4, [ %i1 + 4 ]
a0086010:  c2 0c 21 d5  ldub  [ %l0 + 0x1d5 ], %g1
a0086014:  80 a0 60 01  cmp  %g1, 1
a0086018:  02 bf fe e5  be  0xa0085bac
a008601c:  80 a0 60 02  cmp  %g1, 2
a0086020:  02 80 01 66  be  0xa00865b8
a0086024:  90 10 20 0b  mov  0xb, %o0
a0086028:  80 a0 60 03  cmp  %g1, 3
a008602c:  12 80 00 0b  bne  0xa0086058
a0086030:  92 10 25 dc  mov  0x5dc, %o1
a0086034:  40 00 02 5f  call  0xa00869b0
a0086038:  01 00 00 00  nop
a008603c:  30 bf fe e0  b,a   0xa0085bbc
a0086040:  40 00 02 7f  call  0xa0086a3c
a0086044:  90 10 20 03  mov  3, %o0
a0086048:  a3 2a 20 10  sll  %o0, 0x10, %l1
a008604c:  80 a4 60 00  cmp  %l1, 0
a0086050:  02 80 01 33  be  0xa008651c
a0086054:  01 00 00 00  nop
a0086058:  40 02 78 7b  call  0xa0124244
a008605c:  90 10 20 00  clr  %o0	! 0x0
a0086060:  40 01 20 ba  call  0xa00ce348
a0086064:  01 00 00 00  nop
a0086068:  40 00 d6 95  call  0xa00bbabc
a008606c:  01 00 00 00  nop
a0086070:  92 14 a2 90  or  %l2, 0x290, %o1
a0086074:  e4 0a 60 1f  ldub  [ %o1 + 0x1f ], %l2
a0086078:  80 a4 a0 02  cmp  %l2, 2
a008607c:  12 80 02 4b  bne  0xa00869a8
a0086080:  01 00 00 00  nop
a0086084:  10 bf fe da  b  0xa0085bec
a0086088:  d0 0a 60 2f  ldub  [ %o1 + 0x2f ], %o0
a008608c:  40 02 f6 e2  call  0xa0143c14
a0086090:  90 10 20 00  clr  %o0
a0086094:  92 0a 20 ff  and  %o0, 0xff, %o1
a0086098:  80 a2 60 05  cmp  %o1, 5
a008609c:  08 bf fe 5b  bleu  0xa0085a08
a00860a0:  23 2a 00 b3  sethi  %hi(0xa802cc00), %l1
a00860a4:  40 02 86 22  call  0xa012792c
a00860a8:  01 00 00 00  nop
a00860ac:  80 8a 20 ff  btst  0xff, %o0
a00860b0:  12 bf fe 57  bne  0xa0085a0c
a00860b4:  b0 14 63 f4  or  %l1, 0x3f4, %i0
a00860b8:  40 02 86 23  call  0xa0127944
a00860bc:  01 00 00 00  nop
a00860c0:  80 8a 20 ff  btst  0xff, %o0
a00860c4:  32 bf fe 53  bne,a   0xa0085a10
a00860c8:  d6 16 20 04  lduh  [ %i0 + 4 ], %o3
a00860cc:  15 00 03 fc  sethi  %hi(0xff000), %o2
a00860d0:  40 01 64 28  call  0xa00df170
a00860d4:  90 12 a3 58  or  %o2, 0x358, %o0	! 0xff358
a00860d8:  40 02 81 fd  call  0xa01268cc
a00860dc:  90 10 20 00  clr  %o0
a00860e0:  92 10 20 01  mov  1, %o1
a00860e4:  40 02 fc 12  call  0xa014512c
a00860e8:  90 10 20 00  clr  %o0
a00860ec:  40 02 86 39  call  0xa01279d0
a00860f0:  90 10 20 00  clr  %o0
a00860f4:  40 02 85 ff  call  0xa01278f0
a00860f8:  90 10 20 00  clr  %o0
a00860fc:  40 02 86 18  call  0xa012795c
a0086100:  90 10 20 00  clr  %o0
a0086104:  40 02 7a 8f  call  0xa0124b40
a0086108:  23 2a 00 b3  sethi  %hi(0xa802cc00), %l1
a008610c:  40 02 7a 57  call  0xa0124a68
a0086110:  b0 14 63 f4  or  %l1, 0x3f4, %i0	! 0xa802cff4
a0086114:  10 bf fe 3f  b  0xa0085a10
a0086118:  d6 16 20 04  lduh  [ %i0 + 4 ], %o3
a008611c:  40 02 86 2a  call  0xa01279c4
a0086120:  01 00 00 00  nop
a0086124:  82 0a 20 ff  and  %o0, 0xff, %g1
a0086128:  80 a0 60 02  cmp  %g1, 2
a008612c:  02 bf fe 31  be  0xa00859f0
a0086130:  21 2a 00 90  sethi  %hi(0xa8024000), %l0
a0086134:  d8 0c 20 01  ldub  [ %l0 + 1 ], %o4	! 0xa8024001
a0086138:  80 a3 20 ff  cmp  %o4, 0xff
a008613c:  02 80 01 36  be  0xa0086614
a0086140:  13 00 03 fc  sethi  %hi(0xff000), %o1
a0086144:  40 00 02 3e  call  0xa0086a3c
a0086148:  90 10 20 12  mov  0x12, %o0
a008614c:  95 2a 20 10  sll  %o0, 0x10, %o2
a0086150:  80 a2 a0 00  cmp  %o2, 0
a0086154:  12 80 00 11  bne  0xa0086198
a0086158:  f0 0c 20 01  ldub  [ %l0 + 1 ], %i0
a008615c:  c2 0c 20 01  ldub  [ %l0 + 1 ], %g1
a0086160:  80 a0 60 09  cmp  %g1, 9
a0086164:  18 80 00 0e  bgu  0xa008619c
a0086168:  80 a6 20 0a  cmp  %i0, 0xa
a008616c:  a2 00 60 01  add  %g1, 1, %l1
a0086170:  1f 00 03 fc  sethi  %hi(0xff000), %o7
a0086174:  92 0c 60 ff  and  %l1, 0xff, %o1
a0086178:  90 13 e3 b0  or  %o7, 0x3b0, %o0
a008617c:  40 01 63 fd  call  0xa00df170
a0086180:  e2 2c 20 01  stb  %l1, [ %l0 + 1 ]
a0086184:  17 00 00 3a  sethi  %hi(0xe800), %o3
a0086188:  92 12 e2 60  or  %o3, 0x260, %o1	! 0xea60
a008618c:  40 00 02 09  call  0xa00869b0
a0086190:  90 10 20 12  mov  0x12, %o0
a0086194:  f0 0c 20 01  ldub  [ %l0 + 1 ], %i0
a0086198:  80 a6 20 0a  cmp  %i0, 0xa
a008619c:  12 bf fe 15  bne  0xa00859f0
a00861a0:  21 2a 00 90  sethi  %hi(0xa8024000), %l0
a00861a4:  d0 0c 20 00  ldub  [ %l0 ], %o0
a00861a8:  80 a2 20 ff  cmp  %o0, 0xff
a00861ac:  12 bf fe 11  bne  0xa00859f0
a00861b0:  33 00 03 fc  sethi  %hi(0xff000), %i1
a00861b4:  40 01 63 ef  call  0xa00df170
a00861b8:  90 16 63 d0  or  %i1, 0x3d0, %o0	! 0xff3d0
a00861bc:  40 02 7a 61  call  0xa0124b40
a00861c0:  01 00 00 00  nop
a00861c4:  c0 2c 20 00  clrb  [ %l0 ]
a00861c8:  40 02 85 d3  call  0xa0127914
a00861cc:  90 10 20 01  mov  1, %o0
a00861d0:  92 10 20 01  mov  1, %o1
a00861d4:  40 02 fb d6  call  0xa014512c
a00861d8:  90 10 20 01  mov  1, %o0
a00861dc:  40 02 85 c2  call  0xa01278e4
a00861e0:  90 10 20 01  mov  1, %o0
a00861e4:  40 02 85 c6  call  0xa01278fc
a00861e8:  90 10 20 01  mov  1, %o0
a00861ec:  40 02 86 a3  call  0xa0127c78
a00861f0:  01 00 00 00  nop
a00861f4:  40 02 85 f1  call  0xa01279b8
a00861f8:  90 10 20 01  mov  1, %o0	! 0x1
a00861fc:  40 02 85 f5  call  0xa01279d0
a0086200:  90 10 20 00  clr  %o0
a0086204:  40 02 f6 e5  call  0xa0143d98
a0086208:  01 00 00 00  nop
a008620c:  30 bf fd f9  b,a   0xa00859f0
a0086210:  40 02 ee 22  call  0xa0141a98
a0086214:  01 00 00 00  nop
a0086218:  80 8a 20 ff  btst  0xff, %o0
a008621c:  02 bf fd e7  be  0xa00859b8
a0086220:  01 00 00 00  nop
a0086224:  40 02 72 c7  call  0xa0122d40
a0086228:  01 00 00 00  nop
a008622c:  80 8a 20 ff  btst  0xff, %o0
a0086230:  12 bf fd e2  bne  0xa00859b8
a0086234:  01 00 00 00  nop
a0086238:  40 02 85 bd  call  0xa012792c
a008623c:  01 00 00 00  nop
a0086240:  80 8a 20 ff  btst  0xff, %o0
a0086244:  12 bf fd dd  bne  0xa00859b8
a0086248:  01 00 00 00  nop
a008624c:  40 02 85 be  call  0xa0127944
a0086250:  01 00 00 00  nop
a0086254:  80 8a 20 ff  btst  0xff, %o0
a0086258:  12 bf fd d8  bne  0xa00859b8
a008625c:  01 00 00 00  nop
a0086260:  40 02 85 c2  call  0xa0127968
a0086264:  01 00 00 00  nop
a0086268:  80 8a 20 ff  btst  0xff, %o0
a008626c:  12 bf fd d3  bne  0xa00859b8
a0086270:  33 00 03 fc  sethi  %hi(0xff000), %i1
a0086274:  90 16 63 f0  or  %i1, 0x3f0, %o0	! 0xff3f0
a0086278:  40 01 63 be  call  0xa00df170
a008627c:  92 10 20 00  clr  %o1
a0086280:  30 bf fd ce  b,a   0xa00859b8
a0086284:  40 02 79 9b  call  0xa01248f0
a0086288:  01 00 00 00  nop
a008628c:  80 8a 20 ff  btst  0xff, %o0
a0086290:  02 80 00 5f  be  0xa008640c
a0086294:  03 00 03 fd  sethi  %hi(0xff400), %g1
a0086298:  40 02 79 b3  call  0xa0124964
a008629c:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00862a0:  b2 0a 20 ff  and  %o0, 0xff, %i1
a00862a4:  80 a6 60 01  cmp  %i1, 1
a00862a8:  02 80 00 eb  be  0xa0086654
a00862ac:  94 14 a2 90  or  %l2, 0x290, %o2
a00862b0:  40 02 79 ad  call  0xa0124964
a00862b4:  01 00 00 00  nop
a00862b8:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00862bc:  80 a4 20 01  cmp  %l0, 1
a00862c0:  12 bf fd b8  bne  0xa00859a0
a00862c4:  92 14 a2 90  or  %l2, 0x290, %o1
a00862c8:  1b 00 00 15  sethi  %hi(0x5400), %o5
a00862cc:  d8 12 61 f6  lduh  [ %o1 + 0x1f6 ], %o4
a00862d0:  82 13 61 aa  or  %o5, 0x1aa, %g1
a00862d4:  80 a3 00 01  cmp  %o4, %g1
a00862d8:  12 bf fd b2  bne  0xa00859a0
a00862dc:  17 00 03 fd  sethi  %hi(0xff400), %o3
a00862e0:  40 01 63 a4  call  0xa00df170
a00862e4:  90 12 e0 38  or  %o3, 0x38, %o0	! 0xff438
a00862e8:  40 02 81 c4  call  0xa01269f8
a00862ec:  01 00 00 00  nop
a00862f0:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a00862f4:  d4 0b 63 48  ldub  [ %o5 + 0x348 ], %o2	! 0xa802af48
a00862f8:  80 a2 a0 00  cmp  %o2, 0
a00862fc:  12 bf fd a9  bne  0xa00859a0
a0086300:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a0086304:  92 16 22 74  or  %i0, 0x274, %o1	! 0xa802d274
a0086308:  e2 0a 60 15  ldub  [ %o1 + 0x15 ], %l1
a008630c:  9e 04 60 01  add  %l1, 1, %o7
a0086310:  d0 32 60 16  sth  %o0, [ %o1 + 0x16 ]
a0086314:  e0 2b 63 48  stb  %l0, [ %o5 + 0x348 ]
a0086318:  de 2a 60 15  stb  %o7, [ %o1 + 0x15 ]
a008631c:  94 10 22 e0  mov  0x2e0, %o2
a0086320:  96 10 20 1c  mov  0x1c, %o3
a0086324:  40 03 12 eb  call  0xa014aed0
a0086328:  90 10 20 30  mov  0x30, %o0
a008632c:  30 bf fd 9d  b,a   0xa00859a0
a0086330:  40 00 01 c3  call  0xa0086a3c
a0086334:  90 10 20 0b  mov  0xb, %o0
a0086338:  91 2a 20 10  sll  %o0, 0x10, %o0
a008633c:  80 a2 20 00  cmp  %o0, 0
a0086340:  12 bf ff 46  bne  0xa0086058
a0086344:  01 00 00 00  nop
a0086348:  40 02 f6 33  call  0xa0143c14
a008634c:  01 00 00 00  nop
a0086350:  a0 0a 20 ff  and  %o0, 0xff, %l0
a0086354:  80 a4 20 0a  cmp  %l0, 0xa
a0086358:  02 80 00 06  be  0xa0086370
a008635c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0086360:  d6 02 22 90  ld  [ %o0 + 0x290 ], %o3	! 0xa802d290
a0086364:  80 8a e2 00  btst  0x200, %o3
a0086368:  02 80 00 b3  be  0xa0086634
a008636c:  01 00 00 00  nop
a0086370:  a0 14 63 f4  or  %l1, 0x3f4, %l0
a0086374:  c2 14 20 06  lduh  [ %l0 + 6 ], %g1
a0086378:  80 88 60 20  btst  0x20, %g1
a008637c:  12 80 00 e7  bne  0xa0086718
a0086380:  92 14 a2 90  or  %l2, 0x290, %o1
a0086384:  de 02 60 a8  ld  [ %o1 + 0xa8 ], %o7
a0086388:  15 00 00 20  sethi  %hi(0x8000), %o2
a008638c:  80 8b c0 0a  btst  %o7, %o2
a0086390:  02 80 00 d8  be  0xa00866f0
a0086394:  01 00 00 00  nop
a0086398:  da 14 20 04  lduh  [ %l0 + 4 ], %o5
a008639c:  03 00 00 18  sethi  %hi(0x6000), %g1
a00863a0:  80 88 40 0d  btst  %g1, %o5
a00863a4:  12 bf fe 03  bne  0xa0085bb0
a00863a8:  90 10 20 0b  mov  0xb, %o0
a00863ac:  92 2b 40 01  andn  %o5, %g1, %o1
a00863b0:  31 00 00 10  sethi  %hi(0x4000), %i0
a00863b4:  b2 12 40 18  or  %o1, %i0, %i1
a00863b8:  40 02 79 be  call  0xa0124ab0
a00863bc:  f2 34 20 04  sth  %i1, [ %l0 + 4 ]
a00863c0:  40 02 79 ce  call  0xa0124af8
a00863c4:  01 00 00 00  nop
a00863c8:  40 02 7d c0  call  0xa0125ac8
a00863cc:  01 00 00 00  nop
a00863d0:  40 00 2b 02  call  0xa0090fd8
a00863d4:  01 00 00 00  nop
a00863d8:  90 10 20 00  clr  %o0	! 0x0
a00863dc:  40 02 fb 54  call  0xa014512c
a00863e0:  92 10 20 01  mov  1, %o1
a00863e4:  40 02 85 52  call  0xa012792c
a00863e8:  01 00 00 00  nop
a00863ec:  80 8a 20 ff  btst  0xff, %o0
a00863f0:  02 80 00 e2  be  0xa0086778
a00863f4:  01 00 00 00  nop
a00863f8:  40 02 86 20  call  0xa0127c78
a00863fc:  01 00 00 00  nop
a0086400:  90 10 20 0b  mov  0xb, %o0	! 0xb
a0086404:  10 bf fd ec  b  0xa0085bb4
a0086408:  92 10 23 e8  mov  0x3e8, %o1
a008640c:  40 01 63 59  call  0xa00df170
a0086410:  90 10 60 08  or  %g1, 8, %o0
a0086414:  90 10 20 00  clr  %o0
a0086418:  40 02 fb 45  call  0xa014512c
a008641c:  92 10 20 01  mov  1, %o1
a0086420:  10 80 00 00  b  0xa0086420
a0086424:  01 00 00 00  nop
a0086428:  40 00 01 85  call  0xa0086a3c
a008642c:  90 10 20 0b  mov  0xb, %o0	! 0xb
a0086430:  91 2a 20 10  sll  %o0, 0x10, %o0
a0086434:  80 a2 20 00  cmp  %o0, 0
a0086438:  12 bf ff 08  bne  0xa0086058
a008643c:  01 00 00 00  nop
a0086440:  40 02 f5 f5  call  0xa0143c14
a0086444:  01 00 00 00  nop
a0086448:  9a 0a 20 ff  and  %o0, 0xff, %o5
a008644c:  80 a3 60 0a  cmp  %o5, 0xa
a0086450:  02 80 00 06  be  0xa0086468
a0086454:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a0086458:  d4 03 e2 90  ld  [ %o7 + 0x290 ], %o2	! 0xa802d290
a008645c:  80 8a a2 00  btst  0x200, %o2
a0086460:  02 80 00 5e  be  0xa00865d8
a0086464:  01 00 00 00  nop
a0086468:  a0 14 63 f4  or  %l1, 0x3f4, %l0
a008646c:  c2 14 20 06  lduh  [ %l0 + 6 ], %g1
a0086470:  80 88 60 20  btst  0x20, %g1
a0086474:  12 80 00 3e  bne  0xa008656c
a0086478:  9a 14 a2 90  or  %l2, 0x290, %o5
a008647c:  d8 03 60 a8  ld  [ %o5 + 0xa8 ], %o4
a0086480:  03 00 00 20  sethi  %hi(0x8000), %g1
a0086484:  80 8b 00 01  btst  %o4, %g1
a0086488:  32 bf ff c5  bne,a   0xa008639c
a008648c:  da 14 20 04  lduh  [ %l0 + 4 ], %o5
a0086490:  40 02 fd 9a  call  0xa0145af8
a0086494:  90 10 20 02  mov  2, %o0
a0086498:  9f 2a 20 10  sll  %o0, 0x10, %o7
a008649c:  95 33 e0 10  srl  %o7, 0x10, %o2
a00864a0:  80 a2 a0 01  cmp  %o2, 1
a00864a4:  22 bf ff be  be,a   0xa008639c
a00864a8:  da 14 20 04  lduh  [ %l0 + 4 ], %o5
a00864ac:  21 00 03 fd  sethi  %hi(0xff400), %l0
a00864b0:  90 14 20 70  or  %l0, 0x70, %o0	! 0xff470
a00864b4:  40 01 63 2f  call  0xa00df170
a00864b8:  01 00 00 00  nop
a00864bc:  7f ff ee 7b  call  0xa0081ea8
a00864c0:  90 10 20 03  mov  3, %o0	! 0x3
a00864c4:  d6 16 63 42  lduh  [ %i1 + 0x342 ], %o3
a00864c8:  a2 0a ff ef  and  %o3, -17, %l1
a00864cc:  10 bf fe e3  b  0xa0086058
a00864d0:  e2 36 63 42  sth  %l1, [ %i1 + 0x342 ]
a00864d4:  40 02 fb a3  call  0xa0145360
a00864d8:  90 10 20 01  mov  1, %o0
a00864dc:  10 bf fd 66  b  0xa0085a74
a00864e0:  c0 2c 23 44  clrb  [ %l0 + 0x344 ]
a00864e4:  40 02 fb 9f  call  0xa0145360
a00864e8:  90 10 20 00  clr  %o0
a00864ec:  10 bf fe 3f  b  0xa0085de8
a00864f0:  c2 0c 23 44  ldub  [ %l0 + 0x344 ], %g1
a00864f4:  92 14 a2 90  or  %l2, 0x290, %o1
a00864f8:  94 10 20 00  clr  %o2
a00864fc:  40 03 12 75  call  0xa014aed0
a0086500:  96 10 21 fc  mov  0x1fc, %o3
a0086504:  10 bf fe 36  b  0xa0085ddc
a0086508:  c2 0c 23 44  ldub  [ %l0 + 0x344 ], %g1
a008650c:  40 02 fb 95  call  0xa0145360
a0086510:  90 10 20 02  mov  2, %o0
a0086514:  10 bf fe 2f  b  0xa0085dd0
a0086518:  c2 0c 23 44  ldub  [ %l0 + 0x344 ], %g1
a008651c:  40 00 23 8e  call  0xa008f354
a0086520:  01 00 00 00  nop
a0086524:  90 10 20 ff  mov  0xff, %o0	! 0xff
a0086528:  40 00 22 51  call  0xa008ee6c
a008652c:  92 10 20 00  clr  %o1
a0086530:  f2 0c 23 41  ldub  [ %l0 + 0x341 ], %i1
a0086534:  90 0e 7f fe  and  %i1, -2, %o0
a0086538:  40 02 f6 1c  call  0xa0143da8
a008653c:  d0 2c 23 41  stb  %o0, [ %l0 + 0x341 ]
a0086540:  30 bf fe c6  b,a   0xa0086058
a0086544:  40 03 16 0b  call  0xa014bd70
a0086548:  90 10 20 01  mov  1, %o0
a008654c:  94 0a 20 ff  and  %o0, 0xff, %o2
a0086550:  80 a2 a0 01  cmp  %o2, 1
a0086554:  32 bf fd 37  bne,a   0xa0085a30
a0086558:  98 14 a2 90  or  %l2, 0x290, %o4
a008655c:  10 bf fe 3f  b  0xa0085e58
a0086560:  9e 14 a2 90  or  %l2, 0x290, %o7
a0086564:  10 bf fd 5e  b  0xa0085adc
a0086568:  da 2a 60 11  stb  %o5, [ %o1 + 0x11 ]
a008656c:  90 08 7f df  and  %g1, -33, %o0
a0086570:  96 12 20 10  or  %o0, 0x10, %o3
a0086574:  23 00 00 04  sethi  %hi(0x1000), %l1
a0086578:  d6 34 20 06  sth  %o3, [ %l0 + 6 ]
a008657c:  92 14 63 88  or  %l1, 0x388, %o1
a0086580:  40 00 01 0c  call  0xa00869b0
a0086584:  90 10 20 0b  mov  0xb, %o0
a0086588:  40 02 79 4a  call  0xa0124ab0
a008658c:  01 00 00 00  nop
a0086590:  40 02 79 5a  call  0xa0124af8
a0086594:  01 00 00 00  nop
a0086598:  40 02 7d 4c  call  0xa0125ac8
a008659c:  01 00 00 00  nop
a00865a0:  40 00 2a 8e  call  0xa0090fd8
a00865a4:  01 00 00 00  nop
a00865a8:  90 10 20 00  clr  %o0	! 0x0
a00865ac:  40 02 fa e0  call  0xa014512c
a00865b0:  92 10 20 01  mov  1, %o1
a00865b4:  30 bf fe a9  b,a   0xa0086058
a00865b8:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a00865bc:  e0 0e 63 46  ldub  [ %i1 + 0x346 ], %l0	! 0xa802af46
a00865c0:  80 a4 20 02  cmp  %l0, 2
a00865c4:  18 bf fd 7c  bgu  0xa0085bb4
a00865c8:  92 10 20 64  mov  0x64, %o1
a00865cc:  90 10 20 0b  mov  0xb, %o0
a00865d0:  10 bf fd 79  b  0xa0085bb4
a00865d4:  92 10 23 e8  mov  0x3e8, %o1
a00865d8:  40 00 2a 7d  call  0xa0090fcc
a00865dc:  01 00 00 00  nop
a00865e0:  b1 2a 20 10  sll  %o0, 0x10, %i0
a00865e4:  93 36 20 10  srl  %i0, 0x10, %o1
a00865e8:  80 a2 60 fe  cmp  %o1, 0xfe
a00865ec:  32 bf ff a0  bne,a   0xa008646c
a00865f0:  a0 14 63 f4  or  %l1, 0x3f4, %l0
a00865f4:  40 00 c6 6a  call  0xa00b7f9c
a00865f8:  90 10 20 19  mov  0x19, %o0
a00865fc:  40 00 2a 69  call  0xa0090fa0
a0086600:  90 10 20 00  clr  %o0
a0086604:  90 10 20 0b  mov  0xb, %o0
a0086608:  40 00 00 ea  call  0xa00869b0
a008660c:  92 10 2b b8  mov  0xbb8, %o1
a0086610:  30 bf fd 6b  b,a   0xa0085bbc
a0086614:  40 01 62 d7  call  0xa00df170
a0086618:  90 12 63 90  or  %o1, 0x390, %o0
a008661c:  1b 00 00 3a  sethi  %hi(0xe800), %o5
a0086620:  c0 2c 20 01  clrb  [ %l0 + 1 ]
a0086624:  92 13 62 60  or  %o5, 0x260, %o1
a0086628:  40 00 00 e2  call  0xa00869b0
a008662c:  90 10 20 12  mov  0x12, %o0
a0086630:  30 bf fc f0  b,a   0xa00859f0
a0086634:  40 00 2a 66  call  0xa0090fcc
a0086638:  01 00 00 00  nop
a008663c:  99 2a 20 10  sll  %o0, 0x10, %o4
a0086640:  83 33 20 10  srl  %o4, 0x10, %g1
a0086644:  80 a0 60 fe  cmp  %g1, 0xfe
a0086648:  32 bf ff 4b  bne,a   0xa0086374
a008664c:  a0 14 63 f4  or  %l1, 0x3f4, %l0
a0086650:  30 bf ff e9  b,a   0xa00865f4
a0086654:  13 00 00 15  sethi  %hi(0x5400), %o1
a0086658:  d8 12 a1 f6  lduh  [ %o2 + 0x1f6 ], %o4
a008665c:  9a 12 61 aa  or  %o1, 0x1aa, %o5
a0086660:  80 a3 00 0d  cmp  %o4, %o5
a0086664:  02 bf ff 13  be  0xa00862b0
a0086668:  1f 00 03 fd  sethi  %hi(0xff400), %o7
a008666c:  90 13 e0 a0  or  %o7, 0xa0, %o0	! 0xff4a0
a0086670:  40 01 62 c0  call  0xa00df170
a0086674:  01 00 00 00  nop
a0086678:  40 02 80 e0  call  0xa01269f8
a008667c:  01 00 00 00  nop
a0086680:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0086684:  d6 0b 63 48  ldub  [ %o5 + 0x348 ], %o3	! 0xa802af48
a0086688:  80 a2 e0 00  cmp  %o3, 0
a008668c:  12 80 00 0d  bne  0xa00866c0
a0086690:  a0 10 00 08  mov  %o0, %l0
a0086694:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0086698:  92 12 22 74  or  %o0, 0x274, %o1	! 0xa802d274
a008669c:  f0 0a 60 15  ldub  [ %o1 + 0x15 ], %i0
a00866a0:  a2 06 20 01  add  %i0, 1, %l1
a00866a4:  f2 2b 63 48  stb  %i1, [ %o5 + 0x348 ]
a00866a8:  e2 2a 60 15  stb  %l1, [ %o1 + 0x15 ]
a00866ac:  e0 32 60 16  sth  %l0, [ %o1 + 0x16 ]
a00866b0:  90 10 20 30  mov  0x30, %o0
a00866b4:  94 10 22 e0  mov  0x2e0, %o2
a00866b8:  40 03 12 06  call  0xa014aed0
a00866bc:  96 10 20 1c  mov  0x1c, %o3
a00866c0:  b3 2c 20 10  sll  %l0, 0x10, %i1
a00866c4:  93 36 60 10  srl  %i1, 0x10, %o1
a00866c8:  80 a2 60 00  cmp  %o1, 0
a00866cc:  02 bf fc b5  be  0xa00859a0
a00866d0:  21 00 03 fd  sethi  %hi(0xff400), %l0
a00866d4:  40 01 62 a7  call  0xa00df170
a00866d8:  90 14 20 c8  or  %l0, 0xc8, %o0	! 0xff4c8
a00866dc:  40 02 ea f7  call  0xa01412b8
a00866e0:  90 10 20 00  clr  %o0
a00866e4:  7f ff ed f1  call  0xa0081ea8
a00866e8:  90 10 20 01  mov  1, %o0
a00866ec:  30 bf fc ad  b,a   0xa00859a0
a00866f0:  40 02 fd 02  call  0xa0145af8
a00866f4:  90 10 20 02  mov  2, %o0
a00866f8:  97 2a 20 10  sll  %o0, 0x10, %o3
a00866fc:  b1 32 e0 10  srl  %o3, 0x10, %i0
a0086700:  80 a6 20 01  cmp  %i0, 1
a0086704:  22 bf ff 26  be,a   0xa008639c
a0086708:  da 14 20 04  lduh  [ %l0 + 4 ], %o5
a008670c:  21 00 03 fd  sethi  %hi(0xff400), %l0
a0086710:  10 bf ff 69  b  0xa00864b4
a0086714:  90 14 20 d8  or  %l0, 0xd8, %o0	! 0xff4d8
a0086718:  9a 08 7f df  and  %g1, -33, %o5
a008671c:  b2 13 60 10  or  %o5, 0x10, %i1
a0086720:  23 00 00 04  sethi  %hi(0x1000), %l1
a0086724:  92 14 63 88  or  %l1, 0x388, %o1	! 0x1388
a0086728:  90 10 20 0b  mov  0xb, %o0
a008672c:  40 00 00 a1  call  0xa00869b0
a0086730:  f2 34 20 06  sth  %i1, [ %l0 + 6 ]
a0086734:  40 02 78 df  call  0xa0124ab0
a0086738:  01 00 00 00  nop
a008673c:  40 02 78 ef  call  0xa0124af8
a0086740:  01 00 00 00  nop
a0086744:  40 02 7c e1  call  0xa0125ac8
a0086748:  01 00 00 00  nop
a008674c:  10 bf ff 98  b  0xa00865ac
a0086750:  90 10 20 00  clr  %o0	! 0x0
a0086754:  40 02 f4 2c  call  0xa0143804
a0086758:  90 10 23 ff  mov  0x3ff, %o0
a008675c:  f0 14 20 04  lduh  [ %l0 + 4 ], %i0
a0086760:  92 16 22 00  or  %i0, 0x200, %o1
a0086764:  d2 34 20 04  sth  %o1, [ %l0 + 4 ]
a0086768:  c0 2c 20 06  clrb  [ %l0 + 6 ]
a008676c:  90 10 20 0b  mov  0xb, %o0
a0086770:  10 bf fd 11  b  0xa0085bb4
a0086774:  92 10 23 e8  mov  0x3e8, %o1
a0086778:  40 02 84 73  call  0xa0127944
a008677c:  01 00 00 00  nop
a0086780:  80 8a 20 ff  btst  0xff, %o0
a0086784:  12 bf ff 1d  bne  0xa00863f8
a0086788:  01 00 00 00  nop
a008678c:  40 02 84 59  call  0xa01278f0
a0086790:  90 10 20 01  mov  1, %o0	! 0x1
a0086794:  40 02 84 60  call  0xa0127914
a0086798:  90 10 20 01  mov  1, %o0
a008679c:  30 bf ff 17  b,a   0xa00863f8
a00867a0:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a00867a4:  d4 02 e1 a0  ld  [ %o3 + 0x1a0 ], %o2	! 0xa802e1a0
a00867a8:  80 a2 a0 00  cmp  %o2, 0
a00867ac:  06 bf fc ac  bl  0xa0085a5c
a00867b0:  90 10 20 02  mov  2, %o0
a00867b4:  7f ff ed bd  call  0xa0081ea8
a00867b8:  01 00 00 00  nop
a00867bc:  30 bf fc a8  b,a   0xa0085a5c
a00867c0:  31 2a 00 90  sethi  %hi(0xa8024000), %i0
a00867c4:  40 03 03 ef  call  0xa0147780
a00867c8:  90 16 20 18  or  %i0, 0x18, %o0	! 0xa8024018
a00867cc:  30 bf fc a4  b,a   0xa0085a5c
a00867d0:  7f ff ed b6  call  0xa0081ea8
a00867d4:  90 10 20 01  mov  1, %o0
a00867d8:  1f 00 03 fd  sethi  %hi(0xff400), %o7
a00867dc:  90 13 e1 08  or  %o7, 0x108, %o0	! 0xff508
a00867e0:  40 01 62 64  call  0xa00df170
a00867e4:  21 2a 00 90  sethi  %hi(0xa8024000), %l0
a00867e8:  40 03 03 e2  call  0xa0147770
a00867ec:  b2 14 20 10  or  %l0, 0x10, %i1	! 0xa8024010
a00867f0:  40 03 03 e0  call  0xa0147770
a00867f4:  d0 2c 20 10  stb  %o0, [ %l0 + 0x10 ]
a00867f8:  17 00 00 3f  sethi  %hi(0xfc00), %o3
a00867fc:  94 12 e3 ff  or  %o3, 0x3ff, %o2	! 0xffff
a0086800:  92 0a 00 0a  and  %o0, %o2, %o1
a0086804:  9b 32 60 08  srl  %o1, 8, %o5
a0086808:  40 03 03 da  call  0xa0147770
a008680c:  da 2e 60 01  stb  %o5, [ %i1 + 1 ]
a0086810:  99 32 20 10  srl  %o0, 0x10, %o4
a0086814:  40 03 03 d7  call  0xa0147770
a0086818:  d8 2e 60 02  stb  %o4, [ %i1 + 2 ]
a008681c:  83 32 20 18  srl  %o0, 0x18, %g1
a0086820:  10 bf fc 8f  b  0xa0085a5c
a0086824:  c2 2e 60 03  stb  %g1, [ %i1 + 3 ]
a0086828:  40 03 03 fb  call  0xa0147814
a008682c:  33 00 03 fd  sethi  %hi(0xff400), %i1
a0086830:  92 0a 20 ff  and  %o0, 0xff, %o1
a0086834:  82 14 a2 90  or  %l2, 0x290, %g1
a0086838:  d4 08 60 1e  ldub  [ %g1 + 0x1e ], %o2
a008683c:  40 01 62 4d  call  0xa00df170
a0086840:  90 16 61 28  or  %i1, 0x128, %o0
a0086844:  40 03 03 f4  call  0xa0147814
a0086848:  a0 10 20 05  mov  5, %l0
a008684c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0086850:  80 a2 20 10  cmp  %o0, 0x10
a0086854:  02 80 00 16  be  0xa00868ac
a0086858:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a008685c:  40 03 03 ee  call  0xa0147814
a0086860:  01 00 00 00  nop
a0086864:  a0 0a 20 ff  and  %o0, 0xff, %l0
a0086868:  80 a4 20 20  cmp  %l0, 0x20
a008686c:  02 80 00 10  be  0xa00868ac
a0086870:  a0 10 20 06  mov  6, %l0
a0086874:  40 03 03 e8  call  0xa0147814
a0086878:  a0 10 20 07  mov  7, %l0
a008687c:  98 0a 20 ff  and  %o0, 0xff, %o4
a0086880:  80 a3 20 30  cmp  %o4, 0x30
a0086884:  02 80 00 0a  be  0xa00868ac
a0086888:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a008688c:  40 03 03 e2  call  0xa0147814
a0086890:  01 00 00 00  nop
a0086894:  96 0a 20 ff  and  %o0, 0xff, %o3
a0086898:  94 1a e0 40  xor  %o3, 0x40, %o2
a008689c:  80 a0 00 0a  cmp  %g0, %o2
a00868a0:  92 60 20 00  subx  %g0, 0, %o1
a00868a4:  9a 0a 7f fd  and  %o1, -3, %o5
a00868a8:  a0 03 60 08  add  %o5, 8, %l0
a00868ac:  de 06 21 a0  ld  [ %i0 + 0x1a0 ], %o7
a00868b0:  80 a3 e0 00  cmp  %o7, 0
a00868b4:  16 80 00 1a  bge  0xa008691c
a00868b8:  92 14 63 f4  or  %l1, 0x3f4, %o1
a00868bc:  da 12 60 0a  lduh  [ %o1 + 0xa ], %o5
a00868c0:  80 8b 60 40  btst  0x40, %o5
a00868c4:  12 bf fc 66  bne  0xa0085a5c
a00868c8:  33 2a 00 b3  sethi  %hi(0xa802cc00), %i1
a00868cc:  9a 14 a2 90  or  %l2, 0x290, %o5
a00868d0:  d4 0b 60 1e  ldub  [ %o5 + 0x1e ], %o2
a00868d4:  98 0c 20 ff  and  %l0, 0xff, %o4
a00868d8:  80 a2 80 0c  cmp  %o2, %o4
a00868dc:  02 bf fc 60  be  0xa0085a5c
a00868e0:  01 00 00 00  nop
a00868e4:  d6 0b 60 1f  ldub  [ %o5 + 0x1f ], %o3
a00868e8:  80 a2 e0 00  cmp  %o3, 0
a00868ec:  02 80 00 06  be  0xa0086904
a00868f0:  01 00 00 00  nop
a00868f4:  de 0b 60 20  ldub  [ %o5 + 0x20 ], %o7
a00868f8:  80 a3 c0 0c  cmp  %o7, %o4
a00868fc:  02 bf fc 58  be  0xa0085a5c
a0086900:  01 00 00 00  nop
a0086904:  40 01 4a 4d  call  0xa00d9238
a0086908:  e0 2b 60 1e  stb  %l0, [ %o5 + 0x1e ]
a008690c:  d0 16 63 f4  lduh  [ %i1 + 0x3f4 ], %o0
a0086910:  b0 12 24 00  or  %o0, 0x400, %i0
a0086914:  10 bf fc 52  b  0xa0085a5c
a0086918:  f0 36 63 f4  sth  %i0, [ %i1 + 0x3f4 ]
a008691c:  7f ff ed 63  call  0xa0081ea8
a0086920:  90 10 20 02  mov  2, %o0
a0086924:  9a 14 a2 90  or  %l2, 0x290, %o5
a0086928:  d0 0b 60 1e  ldub  [ %o5 + 0x1e ], %o0
a008692c:  98 0c 20 ff  and  %l0, 0xff, %o4
a0086930:  80 a2 00 0c  cmp  %o0, %o4
a0086934:  02 bf fc 4a  be  0xa0085a5c
a0086938:  01 00 00 00  nop
a008693c:  f2 0b 60 1f  ldub  [ %o5 + 0x1f ], %i1
a0086940:  80 a6 60 00  cmp  %i1, 0
a0086944:  02 80 00 06  be  0xa008695c
a0086948:  01 00 00 00  nop
a008694c:  c2 0b 60 20  ldub  [ %o5 + 0x20 ], %g1
a0086950:  80 a0 40 0c  cmp  %g1, %o4
a0086954:  02 bf fc 42  be  0xa0085a5c
a0086958:  01 00 00 00  nop
a008695c:  40 01 4a 37  call  0xa00d9238
a0086960:  e0 2b 60 1e  stb  %l0, [ %o5 + 0x1e ]
a0086964:  d8 14 63 f4  lduh  [ %l1 + 0x3f4 ], %o4
a0086968:  a0 13 24 00  or  %o4, 0x400, %l0
a008696c:  10 bf fc 3c  b  0xa0085a5c
a0086970:  e0 34 63 f4  sth  %l0, [ %l1 + 0x3f4 ]
a0086974:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a0086978:  de 06 21 a0  ld  [ %i0 + 0x1a0 ], %o7	! 0xa802e1a0
a008697c:  80 a3 e0 00  cmp  %o7, 0
a0086980:  16 bf fc 37  bge  0xa0085a5c
a0086984:  01 00 00 00  nop
a0086988:  40 02 f6 c1  call  0xa014448c
a008698c:  90 10 20 00  clr  %o0	! 0x0
a0086990:  40 02 f7 1b  call  0xa01445fc
a0086994:  90 0a 20 ff  and  %o0, 0xff, %o0
a0086998:  80 8a 20 ff  btst  0xff, %o0
a008699c:  12 bf fc 30  bne  0xa0085a5c
a00869a0:  90 10 20 01  mov  1, %o0
a00869a4:  30 bf ff 84  b,a   0xa00867b4
a00869a8:  81 c7 e0 08  ret
a00869ac:  81 e8 00 00  restore
