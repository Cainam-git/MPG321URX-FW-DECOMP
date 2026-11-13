# leon2m FUN_a00a09f8 0xa00a09f8-0xa00a0c70 (632 bytes)
a00a09f8:  9d e3 bf 98  save  %sp, -104, %sp
a00a09fc:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00a0a00:  a2 14 22 90  or  %l0, 0x290, %l1	! 0xa802d290
a00a0a04:  19 00 00 15  sethi  %hi(0x5400), %o4
a00a0a08:  da 14 61 f6  lduh  [ %l1 + 0x1f6 ], %o5
a00a0a0c:  82 13 21 aa  or  %o4, 0x1aa, %g1
a00a0a10:  80 a3 40 01  cmp  %o5, %g1
a00a0a14:  02 80 00 12  be  0xa00a0a5c
a00a0a18:  1b 2a 00 b3  sethi  %hi(0xa802cc00), %o5
a00a0a1c:  c2 13 63 f4  lduh  [ %o5 + 0x3f4 ], %g1	! 0xa802cff4
a00a0a20:  80 88 64 00  btst  0x400, %g1
a00a0a24:  12 80 00 91  bne  0xa00a0c68
a00a0a28:  98 13 63 f4  or  %o5, 0x3f4, %o4
a00a0a2c:  d0 0c 61 a9  ldub  [ %l1 + 0x1a9 ], %o0
a00a0a30:  80 a2 20 01  cmp  %o0, 1
a00a0a34:  22 80 00 3a  be,a   0xa00a0b1c
a00a0a38:  d2 0c 61 8b  ldub  [ %l1 + 0x18b ], %o1
a00a0a3c:  40 02 71 0c  call  0xa013ce6c
a00a0a40:  90 10 20 00  clr  %o0
a00a0a44:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00a0a48:  80 a4 60 0c  cmp  %l1, 0xc
a00a0a4c:  12 80 00 87  bne  0xa00a0c68
a00a0a50:  9a 14 22 90  or  %l0, 0x290, %o5
a00a0a54:  10 80 00 16  b  0xa00a0aac
a00a0a58:  c2 0b 61 8b  ldub  [ %o5 + 0x18b ], %g1
a00a0a5c:  17 00 3f ff  sethi  %hi(0xfffc00), %o3
a00a0a60:  d2 04 61 d4  ld  [ %l1 + 0x1d4 ], %o1
a00a0a64:  94 12 e3 00  or  %o3, 0x300, %o2
a00a0a68:  90 0a 40 0a  and  %o1, %o2, %o0
a00a0a6c:  98 13 21 00  or  %o4, 0x100, %o4
a00a0a70:  80 a2 00 0c  cmp  %o0, %o4
a00a0a74:  12 bf ff f2  bne  0xa00a0a3c
a00a0a78:  01 00 00 00  nop
a00a0a7c:  40 02 8e c8  call  0xa014459c
a00a0a80:  90 10 20 03  mov  3, %o0	! 0x3
a00a0a84:  40 00 e1 ed  call  0xa00d9238
a00a0a88:  d0 2c 60 1e  stb  %o0, [ %l1 + 0x1e ]
a00a0a8c:  90 10 20 04  mov  4, %o0
a00a0a90:  7f ff 7f 87  call  0xa00808ac
a00a0a94:  92 10 20 00  clr  %o1
a00a0a98:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00a0a9c:  e2 0b e0 8e  ldub  [ %o7 + 0x8e ], %l1	! 0xa802b08e
a00a0aa0:  a0 14 60 02  or  %l1, 2, %l0
a00a0aa4:  10 80 00 71  b  0xa00a0c68
a00a0aa8:  e0 2b e0 8e  stb  %l0, [ %o7 + 0x8e ]
a00a0aac:  80 a0 60 00  cmp  %g1, 0
a00a0ab0:  02 80 00 6e  be  0xa00a0c68
a00a0ab4:  80 a0 60 01  cmp  %g1, 1
a00a0ab8:  22 80 00 39  be,a   0xa00a0b9c
a00a0abc:  de 03 61 1c  ld  [ %o5 + 0x11c ], %o7
a00a0ac0:  a0 14 22 90  or  %l0, 0x290, %l0
a00a0ac4:  da 0c 21 8b  ldub  [ %l0 + 0x18b ], %o5
a00a0ac8:  80 a3 60 06  cmp  %o5, 6
a00a0acc:  02 80 00 48  be  0xa00a0bec
a00a0ad0:  01 00 00 00  nop
a00a0ad4:  82 0b 60 ff  and  %o5, 0xff, %g1
a00a0ad8:  80 a0 60 06  cmp  %g1, 6
a00a0adc:  02 80 00 2a  be  0xa00a0b84
a00a0ae0:  80 a0 60 09  cmp  %g1, 9
a00a0ae4:  02 80 00 56  be  0xa00a0c3c
a00a0ae8:  01 00 00 00  nop
a00a0aec:  92 0b 60 ff  and  %o5, 0xff, %o1
a00a0af0:  80 a2 60 0a  cmp  %o1, 0xa
a00a0af4:  02 80 00 4c  be  0xa00a0c24
a00a0af8:  01 00 00 00  nop
a00a0afc:  40 00 60 e0  call  0xa00b8e7c
a00a0b00:  90 10 20 01  mov  1, %o0	! 0x1
a00a0b04:  e2 0c 21 8b  ldub  [ %l0 + 0x18b ], %l1
a00a0b08:  94 04 60 f9  add  %l1, 0xf9, %o2
a00a0b0c:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a00a0b10:  d4 24 23 ec  st  %o2, [ %l0 + 0x3ec ]	! 0xa802afec
a00a0b14:  40 00 0e a5  call  0xa00a45a8
a00a0b18:  81 e8 00 00  restore
a00a0b1c:  80 a2 60 02  cmp  %o1, 2
a00a0b20:  12 bf ff c7  bne  0xa00a0a3c
a00a0b24:  1b 3f ff e0  sethi  %hi(0xffff8000), %o5
a00a0b28:  d6 13 20 04  lduh  [ %o4 + 4 ], %o3
a00a0b2c:  a0 0a c0 0d  and  %o3, %o5, %l0
a00a0b30:  95 2c 20 10  sll  %l0, 0x10, %o2
a00a0b34:  9e 10 20 05  mov  5, %o7
a00a0b38:  80 a2 a0 00  cmp  %o2, 0
a00a0b3c:  12 80 00 33  bne  0xa00a0c08
a00a0b40:  de 2b 20 0a  stb  %o7, [ %o4 + 0xa ]
a00a0b44:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a00a0b48:  40 00 51 4e  call  0xa00b5080
a00a0b4c:  c0 24 23 ec  clr  [ %l0 + 0x3ec ]	! 0xa802afec
a00a0b50:  40 00 40 fe  call  0xa00b0f48
a00a0b54:  01 00 00 00  nop
a00a0b58:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00a0b5c:  d4 0a e0 8e  ldub  [ %o3 + 0x8e ], %o2	! 0xa802b08e
a00a0b60:  90 12 a0 02  or  %o2, 2, %o0
a00a0b64:  92 10 21 16  mov  0x116, %o1
a00a0b68:  d2 24 23 ec  st  %o1, [ %l0 + 0x3ec ]
a00a0b6c:  d0 2a e0 8e  stb  %o0, [ %o3 + 0x8e ]
a00a0b70:  67 ff b2 86  call  0x4008d588
a00a0b74:  c0 2c 61 aa  clrb  [ %l1 + 0x1aa ]
a00a0b78:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00a0b7c:  10 80 00 3b  b  0xa00a0c68
a00a0b80:  d0 33 20 3c  sth  %o0, [ %o4 + 0x3c ]	! 0xa802d03c
a00a0b84:  d8 04 21 f4  ld  [ %l0 + 0x1f4 ], %o4
a00a0b88:  80 a3 20 00  cmp  %o4, 0
a00a0b8c:  06 80 00 37  bl  0xa00a0c68
a00a0b90:  92 0b 60 ff  and  %o5, 0xff, %o1
a00a0b94:  10 bf ff d8  b  0xa00a0af4
a00a0b98:  80 a2 60 0a  cmp  %o1, 0xa
a00a0b9c:  80 a3 e0 00  cmp  %o7, 0
a00a0ba0:  06 80 00 32  bl  0xa00a0c68
a00a0ba4:  01 00 00 00  nop
a00a0ba8:  c2 03 60 b0  ld  [ %o5 + 0xb0 ], %g1
a00a0bac:  80 a0 60 00  cmp  %g1, 0
a00a0bb0:  02 80 00 08  be  0xa00a0bd0
a00a0bb4:  01 00 00 00  nop
a00a0bb8:  40 00 e0 08  call  0xa00d8bd8
a00a0bbc:  01 00 00 00  nop
a00a0bc0:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00a0bc4:  80 a3 60 01  cmp  %o5, 1
a00a0bc8:  02 80 00 28  be  0xa00a0c68
a00a0bcc:  01 00 00 00  nop
a00a0bd0:  40 00 dc 5e  call  0xa00d7d48
a00a0bd4:  01 00 00 00  nop
a00a0bd8:  80 a2 20 00  cmp  %o0, 0
a00a0bdc:  12 80 00 23  bne  0xa00a0c68
a00a0be0:  a0 14 22 90  or  %l0, 0x290, %l0
a00a0be4:  10 bf ff b9  b  0xa00a0ac8
a00a0be8:  da 0c 21 8b  ldub  [ %l0 + 0x18b ], %o5
a00a0bec:  40 00 dc 57  call  0xa00d7d48
a00a0bf0:  01 00 00 00  nop
a00a0bf4:  80 a2 20 00  cmp  %o0, 0
a00a0bf8:  12 80 00 1c  bne  0xa00a0c68
a00a0bfc:  01 00 00 00  nop
a00a0c00:  10 bf ff b5  b  0xa00a0ad4
a00a0c04:  da 0c 21 8b  ldub  [ %l0 + 0x18b ], %o5
a00a0c08:  82 12 e4 00  or  %o3, 0x400, %g1
a00a0c0c:  c2 33 20 04  sth  %g1, [ %o4 + 4 ]
a00a0c10:  90 10 20 04  mov  4, %o0
a00a0c14:  7f ff 7f 26  call  0xa00808ac
a00a0c18:  92 10 20 00  clr  %o1
a00a0c1c:  10 bf ff cb  b  0xa00a0b48
a00a0c20:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a00a0c24:  40 00 dc 49  call  0xa00d7d48
a00a0c28:  01 00 00 00  nop
a00a0c2c:  80 a2 20 00  cmp  %o0, 0
a00a0c30:  02 bf ff b3  be  0xa00a0afc
a00a0c34:  01 00 00 00  nop
a00a0c38:  30 80 00 0c  b,a   0xa00a0c68
a00a0c3c:  40 00 dc 43  call  0xa00d7d48
a00a0c40:  01 00 00 00  nop
a00a0c44:  80 a2 20 00  cmp  %o0, 0
a00a0c48:  12 80 00 08  bne  0xa00a0c68
a00a0c4c:  17 00 00 20  sethi  %hi(0x8000), %o3
a00a0c50:  d0 04 21 74  ld  [ %l0 + 0x174 ], %o0
a00a0c54:  80 8a 00 0b  btst  %o0, %o3
a00a0c58:  12 80 00 04  bne  0xa00a0c68
a00a0c5c:  01 00 00 00  nop
a00a0c60:  10 bf ff a3  b  0xa00a0aec
a00a0c64:  da 0c 21 8b  ldub  [ %l0 + 0x18b ], %o5
a00a0c68:  81 c7 e0 08  ret
a00a0c6c:  81 e8 00 00  restore
