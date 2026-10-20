# leon2m FUN_a0145af8 0xa0145af8-0xa0145c5c (48 bytes)
a0145af8:  80 a2 20 11  cmp  %o0, 0x11
a0145afc:  18 80 00 55  bgu  0xa0145c50
a0145b00:  96 10 3f ff  mov  -1, %o3
a0145b04:  83 2a 20 02  sll  %o0, 2, %g1
a0145b08:  11 00 03 8c  sethi  %hi(0xe3000), %o0
a0145b0c:  9a 12 22 38  or  %o0, 0x238, %o5	! 0xe3238
a0145b10:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a0145b14:  81 c3 00 00  jmp  %o4
a0145b18:  01 00 00 00  nop
a0145b1c:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0145b20:  96 10 61 a0  or  %g1, 0x1a0, %o3	! 0xa802e1a0
a0145b24:  d8 0a e0 13  ldub  [ %o3 + 0x13 ], %o4
a0145b28:  9b 2b 20 08  sll  %o4, 8, %o5
a0145b2c:  d8 0a e0 14  ldub  [ %o3 + 0x14 ], %o4
a0145b30:  10 80 00 48  b  0xa0145c50
a0145b34:  96 13 00 0d  or  %o4, %o5, %o3
a0145b38:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a0145b3c:  d6 03 61 b8  ld  [ %o5 + 0x1b8 ], %o3	! 0xa802e1b8
a0145b40:  83 32 e0 16  srl  %o3, 0x16, %g1
a0145b44:  98 08 60 01  and  %g1, 1, %o4
a0145b48:  10 80 00 42  b  0xa0145c50
a0145b4c:  96 0b 20 ff  and  %o4, 0xff, %o3
a0145b50:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a0145b54:  c2 02 21 b8  ld  [ %o0 + 0x1b8 ], %g1	! 0xa802e1b8
a0145b58:  83 30 60 17  srl  %g1, 0x17, %g1
a0145b5c:  98 08 60 01  and  %g1, 1, %o4
a0145b60:  10 80 00 3c  b  0xa0145c50
a0145b64:  96 0b 20 ff  and  %o4, 0xff, %o3
a0145b68:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a0145b6c:  96 13 21 a0  or  %o4, 0x1a0, %o3	! 0xa802e1a0
a0145b70:  da 0a e0 17  ldub  [ %o3 + 0x17 ], %o5
a0145b74:  9b 2b 60 08  sll  %o5, 8, %o5
a0145b78:  d8 0a e0 18  ldub  [ %o3 + 0x18 ], %o4
a0145b7c:  10 80 00 35  b  0xa0145c50
a0145b80:  96 13 00 0d  or  %o4, %o5, %o3
a0145b84:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a0145b88:  da 02 21 b4  ld  [ %o0 + 0x1b4 ], %o5	! 0xa802e1b4
a0145b8c:  10 80 00 31  b  0xa0145c50
a0145b90:  97 33 60 08  srl  %o5, 8, %o3
a0145b94:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a0145b98:  da 02 21 b0  ld  [ %o0 + 0x1b0 ], %o5	! 0xa802e1b0
a0145b9c:  10 80 00 2d  b  0xa0145c50
a0145ba0:  97 33 60 08  srl  %o5, 8, %o3
a0145ba4:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a0145ba8:  10 80 00 2a  b  0xa0145c50
a0145bac:  d6 0b 61 b0  ldub  [ %o5 + 0x1b0 ], %o3	! 0xa802e1b0
a0145bb0:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0145bb4:  10 80 00 27  b  0xa0145c50
a0145bb8:  d6 08 61 af  ldub  [ %g1 + 0x1af ], %o3	! 0xa802e1af
a0145bbc:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a0145bc0:  da 02 e1 ac  ld  [ %o3 + 0x1ac ], %o5	! 0xa802e1ac
a0145bc4:  10 80 00 23  b  0xa0145c50
a0145bc8:  97 33 60 08  srl  %o5, 8, %o3
a0145bcc:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a0145bd0:  10 80 00 20  b  0xa0145c50
a0145bd4:  d6 0b 21 ac  ldub  [ %o4 + 0x1ac ], %o3	! 0xa802e1ac
a0145bd8:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a0145bdc:  da 02 21 a8  ld  [ %o0 + 0x1a8 ], %o5	! 0xa802e1a8
a0145be0:  10 80 00 1c  b  0xa0145c50
a0145be4:  97 33 60 08  srl  %o5, 8, %o3
a0145be8:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a0145bec:  10 80 00 19  b  0xa0145c50
a0145bf0:  d6 0b 61 a8  ldub  [ %o5 + 0x1a8 ], %o3	! 0xa802e1a8
a0145bf4:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0145bf8:  d8 00 61 a0  ld  [ %g1 + 0x1a0 ], %o4	! 0xa802e1a0
a0145bfc:  83 33 20 1a  srl  %o4, 0x1a, %g1
a0145c00:  98 08 60 01  and  %g1, 1, %o4
a0145c04:  10 80 00 13  b  0xa0145c50
a0145c08:  96 0b 20 ff  and  %o4, 0xff, %o3
a0145c0c:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a0145c10:  d0 02 e1 a0  ld  [ %o3 + 0x1a0 ], %o0	! 0xa802e1a0
a0145c14:  83 32 20 1b  srl  %o0, 0x1b, %g1
a0145c18:  98 08 60 01  and  %g1, 1, %o4
a0145c1c:  10 80 00 0d  b  0xa0145c50
a0145c20:  96 0b 20 ff  and  %o4, 0xff, %o3
a0145c24:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a0145c28:  c2 03 61 a0  ld  [ %o5 + 0x1a0 ], %g1	! 0xa802e1a0
a0145c2c:  83 30 60 1d  srl  %g1, 0x1d, %g1
a0145c30:  98 08 60 01  and  %g1, 1, %o4
a0145c34:  10 80 00 07  b  0xa0145c50
a0145c38:  96 0b 20 ff  and  %o4, 0xff, %o3
a0145c3c:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a0145c40:  d6 03 21 a0  ld  [ %o4 + 0x1a0 ], %o3	! 0xa802e1a0
a0145c44:  83 32 e0 1e  srl  %o3, 0x1e, %g1
a0145c48:  98 08 60 01  and  %g1, 1, %o4
a0145c4c:  96 0b 20 ff  and  %o4, 0xff, %o3
a0145c50:  83 2a e0 10  sll  %o3, 0x10, %g1
a0145c54:  81 c3 e0 08  retl
a0145c58:  91 30 60 10  srl  %g1, 0x10, %o0
