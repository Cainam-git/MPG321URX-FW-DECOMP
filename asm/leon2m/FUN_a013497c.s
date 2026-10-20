# leon2m FUN_a013497c 0xa013497c-0xa0134de0 (212 bytes)
a013497c:  9d e3 bf 88  save  %sp, -120, %sp
a0134980:  c2 06 00 00  ld  [ %i0 ], %g1
a0134984:  a1 30 60 10  srl  %g1, 0x10, %l0
a0134988:  94 10 20 00  clr  %o2
a013498c:  96 10 20 00  clr  %o3
a0134990:  99 30 60 04  srl  %g1, 4, %o4
a0134994:  9a 0c 20 ff  and  %l0, 0xff, %o5
a0134998:  d4 3f bf f0  std  %o2, [ %fp + -16 ]
a013499c:  80 a3 60 10  cmp  %o5, 0x10
a01349a0:  aa 0b 20 0f  and  %o4, 0xf, %l5
a01349a4:  a5 30 60 18  srl  %g1, 0x18, %l2
a01349a8:  d4 3f bf e8  std  %o2, [ %fp + -24 ]
a01349ac:  a2 08 60 0f  and  %g1, 0xf, %l1
a01349b0:  08 80 00 03  bleu  0xa01349bc
a01349b4:  a9 30 60 08  srl  %g1, 8, %l4
a01349b8:  a0 10 20 10  mov  0x10, %l0
a01349bc:  a6 0c 20 ff  and  %l0, 0xff, %l3
a01349c0:  90 0c e0 ff  and  %l3, 0xff, %o0
a01349c4:  92 02 20 03  add  %o0, 3, %o1
a01349c8:  91 32 60 02  srl  %o1, 2, %o0
a01349cc:  b0 06 20 04  add  %i0, 4, %i0
a01349d0:  80 a2 20 00  cmp  %o0, 0
a01349d4:  9e 07 bf e8  add  %fp, -24, %o7
a01349d8:  02 80 00 11  be  0xa0134a1c
a01349dc:  92 10 20 00  clr  %o1
a01349e0:  94 10 20 00  clr  %o2
a01349e4:  83 2a a0 02  sll  %o2, 2, %g1
a01349e8:  da 06 00 01  ld  [ %i0 + %g1 ], %o5
a01349ec:  95 33 60 18  srl  %o5, 0x18, %o2
a01349f0:  d4 2b c0 01  stb  %o2, [ %o7 + %g1 ]
a01349f4:  92 02 60 01  inc  %o1
a01349f8:  ac 00 40 0f  add  %g1, %o7, %l6
a01349fc:  af 33 60 10  srl  %o5, 0x10, %l7
a0134a00:  97 33 60 08  srl  %o5, 8, %o3
a0134a04:  94 0a 60 ff  and  %o1, 0xff, %o2
a0134a08:  da 2d a0 03  stb  %o5, [ %l6 + 3 ]
a0134a0c:  ee 2d a0 01  stb  %l7, [ %l6 + 1 ]
a0134a10:  80 a2 80 08  cmp  %o2, %o0
a0134a14:  0a bf ff f4  bcs  0xa01349e4
a0134a18:  d6 2d a0 02  stb  %o3, [ %l6 + 2 ]
a0134a1c:  9e 0c a0 ff  and  %l2, 0xff, %o7
a0134a20:  9a 0c 60 ff  and  %l1, 0xff, %o5
a0134a24:  80 a3 60 05  cmp  %o5, 5
a0134a28:  18 80 00 ec  bgu  0xa0134dd8
a0134a2c:  a5 2b e0 04  sll  %o7, 4, %l2
a0134a30:  13 00 03 4a  sethi  %hi(0xd2800), %o1
a0134a34:  b1 2b 60 02  sll  %o5, 2, %i0
a0134a38:  98 12 63 74  or  %o1, 0x374, %o4
a0134a3c:  e2 03 00 18  ld  [ %o4 + %i0 ], %l1
a0134a40:  81 c4 40 00  jmp  %l1
a0134a44:  01 00 00 00  nop
a0134a48:  92 0c 20 ff  and  %l0, 0xff, %o1
a0134a4c:  80 a2 60 00  cmp  %o1, 0
a0134a50:  02 80 00 10  be  0xa0134a90
a0134a54:  96 10 20 00  clr  %o3
a0134a58:  15 2a 00 b7  sethi  %hi(0xa802dc00), %o2
a0134a5c:  9a 0c af f0  and  %l2, 0xff0, %o5
a0134a60:  9e 12 a2 40  or  %o2, 0x240, %o7
a0134a64:  94 03 40 0f  add  %o5, %o7, %o2
a0134a68:  98 10 20 00  clr  %o4
a0134a6c:  90 07 bf f8  add  %fp, -8, %o0
a0134a70:  b0 02 00 0c  add  %o0, %o4, %i0
a0134a74:  e2 0e 3f f0  ldub  [ %i0 + -16 ], %l1
a0134a78:  e2 2a 80 0c  stb  %l1, [ %o2 + %o4 ]
a0134a7c:  96 02 e0 01  inc  %o3
a0134a80:  98 0a e0 ff  and  %o3, 0xff, %o4
a0134a84:  80 a3 00 09  cmp  %o4, %o1
a0134a88:  0a bf ff fb  bcs  0xa0134a74
a0134a8c:  b0 02 00 0c  add  %o0, %o4, %i0
a0134a90:  80 8d 60 01  btst  1, %l5
a0134a94:  02 80 00 d1  be  0xa0134dd8
a0134a98:  01 00 00 00  nop
a0134a9c:  7f fe a2 de  call  0xa00dd614
a0134aa0:  90 10 20 20  mov  0x20, %o0	! 0x20
a0134aa4:  80 8a 20 ff  btst  0xff, %o0
a0134aa8:  12 80 00 c6  bne  0xa0134dc0
a0134aac:  a0 04 80 13  add  %l2, %l3, %l0
a0134ab0:  2d 2a 00 b2  sethi  %hi(0xa802c800), %l6
a0134ab4:  90 10 20 01  mov  1, %o0
a0134ab8:  13 2a 00 b2  sethi  %hi(0xa802c800), %o1
a0134abc:  e0 2d a3 92  stb  %l0, [ %l6 + 0x392 ]
a0134ac0:  10 80 00 c6  b  0xa0134dd8
a0134ac4:  d0 2a 63 93  stb  %o0, [ %o1 + 0x393 ]
a0134ac8:  a2 0c 20 ff  and  %l0, 0xff, %l1
a0134acc:  80 a4 60 00  cmp  %l1, 0
a0134ad0:  02 80 00 15  be  0xa0134b24
a0134ad4:  92 10 20 00  clr  %o1
a0134ad8:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a0134adc:  25 2a 00 b7  sethi  %hi(0xa802dc00), %l2
a0134ae0:  9e 14 a1 50  or  %l2, 0x150, %o7	! 0xa802dd50
a0134ae4:  90 07 bf f8  add  %fp, -8, %o0
a0134ae8:  d6 14 23 94  lduh  [ %l0 + 0x394 ], %o3
a0134aec:  a9 2a e0 10  sll  %o3, 0x10, %l4
a0134af0:  95 35 20 10  srl  %l4, 0x10, %o2
a0134af4:  80 a2 a0 3f  cmp  %o2, 0x3f
a0134af8:  18 80 00 0a  bgu  0xa0134b20
a0134afc:  9a 0a 60 ff  and  %o1, 0xff, %o5
a0134b00:  98 02 00 0d  add  %o0, %o5, %o4
a0134b04:  92 02 60 01  inc  %o1
a0134b08:  f0 0b 3f f0  ldub  [ %o4 + -16 ], %i0
a0134b0c:  aa 0a 60 ff  and  %o1, 0xff, %l5
a0134b10:  f0 2b c0 0a  stb  %i0, [ %o7 + %o2 ]
a0134b14:  80 a5 40 11  cmp  %l5, %l1
a0134b18:  0a bf ff f5  bcs  0xa0134aec
a0134b1c:  96 02 e0 01  inc  %o3
a0134b20:  d6 34 23 94  sth  %o3, [ %l0 + 0x394 ]
a0134b24:  7f fe a2 bc  call  0xa00dd614
a0134b28:  90 10 20 20  mov  0x20, %o0
a0134b2c:  80 8a 20 ff  btst  0xff, %o0
a0134b30:  12 80 00 96  bne  0xa0134d88
a0134b34:  21 00 06 95  sethi  %hi(0x1a5400), %l0
a0134b38:  80 a4 60 00  cmp  %l1, 0
a0134b3c:  02 80 00 83  be  0xa0134d48
a0134b40:  a0 10 20 00  clr  %l0
a0134b44:  a6 07 bf f8  add  %fp, -8, %l3
a0134b48:  10 80 00 06  b  0xa0134b60
a0134b4c:  25 00 06 95  sethi  %hi(0x1a5400), %l2
a0134b50:  ac 0c 20 ff  and  %l0, 0xff, %l6
a0134b54:  80 a5 80 11  cmp  %l6, %l1
a0134b58:  1a 80 00 7c  bcc  0xa0134d48
a0134b5c:  01 00 00 00  nop
a0134b60:  7f fe a2 ad  call  0xa00dd614
a0134b64:  90 10 20 20  mov  0x20, %o0	! 0x20
a0134b68:  80 8a 20 ff  btst  0xff, %o0
a0134b6c:  22 bf ff f9  be,a   0xa0134b50
a0134b70:  a0 04 20 01  inc  %l0
a0134b74:  92 0c 20 ff  and  %l0, 0xff, %o1
a0134b78:  9e 04 c0 09  add  %l3, %o1, %o7
a0134b7c:  d2 0b ff f0  ldub  [ %o7 + -16 ], %o1
a0134b80:  7f fe a9 7c  call  0xa00df170
a0134b84:  90 14 a0 b8  or  %l2, 0xb8, %o0
a0134b88:  10 bf ff f2  b  0xa0134b50
a0134b8c:  a0 04 20 01  inc  %l0
a0134b90:  90 0c 20 ff  and  %l0, 0xff, %o0
a0134b94:  80 a2 20 00  cmp  %o0, 0
a0134b98:  02 80 00 10  be  0xa0134bd8
a0134b9c:  94 10 20 00  clr  %o2
a0134ba0:  13 2a 00 b6  sethi  %hi(0xa802d800), %o1
a0134ba4:  9e 12 61 c6  or  %o1, 0x1c6, %o7	! 0xa802d9c6
a0134ba8:  a2 0c af f0  and  %l2, 0xff0, %l1
a0134bac:  92 04 40 0f  add  %l1, %o7, %o1
a0134bb0:  96 10 20 00  clr  %o3
a0134bb4:  9e 07 bf f8  add  %fp, -8, %o7
a0134bb8:  82 03 c0 0b  add  %o7, %o3, %g1
a0134bbc:  ac 02 40 0b  add  %o1, %o3, %l6
a0134bc0:  94 02 a0 01  inc  %o2
a0134bc4:  ee 08 7f f0  ldub  [ %g1 + -16 ], %l7
a0134bc8:  96 0a a0 ff  and  %o2, 0xff, %o3
a0134bcc:  80 a2 c0 08  cmp  %o3, %o0
a0134bd0:  0a bf ff fa  bcs  0xa0134bb8
a0134bd4:  ee 2d a0 04  stb  %l7, [ %l6 + 4 ]
a0134bd8:  80 8d 60 01  btst  1, %l5
a0134bdc:  02 80 00 7f  be  0xa0134dd8
a0134be0:  17 2a 00 b6  sethi  %hi(0xa802d800), %o3
a0134be4:  94 04 c0 12  add  %l3, %l2, %o2
a0134be8:  a6 12 e1 c6  or  %o3, 0x1c6, %l3
a0134bec:  90 10 20 01  mov  1, %o0
a0134bf0:  e8 2a e1 c6  stb  %l4, [ %o3 + 0x1c6 ]
a0134bf4:  d0 2c e0 84  stb  %o0, [ %l3 + 0x84 ]
a0134bf8:  10 80 00 78  b  0xa0134dd8
a0134bfc:  d4 34 e0 02  sth  %o2, [ %l3 + 2 ]
a0134c00:  92 0d 20 ff  and  %l4, 0xff, %o1
a0134c04:  80 a2 60 04  cmp  %o1, 4
a0134c08:  18 80 00 65  bgu  0xa0134d9c
a0134c0c:  a2 0c 20 ff  and  %l0, 0xff, %l1
a0134c10:  80 a4 60 00  cmp  %l1, 0
a0134c14:  02 80 00 71  be  0xa0134dd8
a0134c18:  90 10 20 00  clr  %o0
a0134c1c:  a5 2a 60 03  sll  %o1, 3, %l2
a0134c20:  a0 04 80 09  add  %l2, %o1, %l0
a0134c24:  83 2c 20 02  sll  %l0, 2, %g1
a0134c28:  2f 2a 00 b7  sethi  %hi(0xa802dc00), %l7
a0134c2c:  92 20 40 09  sub  %g1, %o1, %o1
a0134c30:  9e 15 e1 90  or  %l7, 0x190, %o7
a0134c34:  94 02 40 0f  add  %o1, %o7, %o2
a0134c38:  9a 10 20 00  clr  %o5
a0134c3c:  a4 07 bf f8  add  %fp, -8, %l2
a0134c40:  e0 0a a0 01  ldub  [ %o2 + 1 ], %l0
a0134c44:  10 80 00 07  b  0xa0134c60
a0134c48:  a6 10 20 01  mov  1, %l3
a0134c4c:  90 02 20 01  inc  %o0
a0134c50:  9a 0a 20 ff  and  %o0, 0xff, %o5
a0134c54:  80 a3 40 11  cmp  %o5, %l1
a0134c58:  1a 80 00 60  bcc  0xa0134dd8
a0134c5c:  d8 2b c0 09  stb  %o4, [ %o7 + %o1 ]
a0134c60:  f0 0b c0 09  ldub  [ %o7 + %o1 ], %i0
a0134c64:  9a 04 80 0d  add  %l2, %o5, %o5
a0134c68:  98 06 20 01  add  %i0, 1, %o4
a0134c6c:  ea 0b 7f f0  ldub  [ %o5 + -16 ], %l5
a0134c70:  98 0b 20 1f  and  %o4, 0x1f, %o4
a0134c74:  a8 02 80 18  add  %o2, %i0, %l4
a0134c78:  80 a3 00 10  cmp  %o4, %l0
a0134c7c:  12 bf ff f4  bne  0xa0134c4c
a0134c80:  ea 2d 20 02  stb  %l5, [ %l4 + 2 ]
a0134c84:  10 bf ff f2  b  0xa0134c4c
a0134c88:  e6 2a a0 22  stb  %l3, [ %o2 + 0x22 ]
a0134c8c:  a8 0c 20 ff  and  %l0, 0xff, %l4
a0134c90:  a0 0c af f0  and  %l2, 0xff0, %l0
a0134c94:  90 04 00 14  add  %l0, %l4, %o0
a0134c98:  80 a2 27 fe  cmp  %o0, 0x7fe
a0134c9c:  14 80 00 22  bg  0xa0134d24
a0134ca0:  01 00 00 00  nop
a0134ca4:  7f fe a2 5c  call  0xa00dd614
a0134ca8:  90 10 20 20  mov  0x20, %o0	! 0x20
a0134cac:  80 8a 20 ff  btst  0xff, %o0
a0134cb0:  12 80 00 3f  bne  0xa0134dac
a0134cb4:  2d 00 06 95  sethi  %hi(0x1a5400), %l6
a0134cb8:  80 a5 20 00  cmp  %l4, 0
a0134cbc:  02 80 00 2a  be  0xa0134d64
a0134cc0:  a2 10 20 00  clr  %l1
a0134cc4:  2f 2a 00 b7  sethi  %hi(0xa802dc00), %l7
a0134cc8:  96 15 e2 40  or  %l7, 0x240, %o3	! 0xa802de40
a0134ccc:  b0 04 00 0b  add  %l0, %o3, %i0
a0134cd0:  9a 10 20 00  clr  %o5
a0134cd4:  ac 07 bf f8  add  %fp, -8, %l6
a0134cd8:  10 80 00 06  b  0xa0134cf0
a0134cdc:  2f 00 06 95  sethi  %hi(0x1a5400), %l7
a0134ce0:  9a 0c 60 ff  and  %l1, 0xff, %o5
a0134ce4:  80 a3 40 14  cmp  %o5, %l4
a0134ce8:  1a 80 00 20  bcc  0xa0134d68
a0134cec:  80 8d 60 01  btst  1, %l5
a0134cf0:  a0 05 80 0d  add  %l6, %o5, %l0
a0134cf4:  c2 0c 3f f0  ldub  [ %l0 + -16 ], %g1
a0134cf8:  c2 2e 00 0d  stb  %g1, [ %i0 + %o5 ]
a0134cfc:  7f fe a2 46  call  0xa00dd614
a0134d00:  90 10 20 20  mov  0x20, %o0
a0134d04:  80 8a 20 ff  btst  0xff, %o0
a0134d08:  22 bf ff f6  be,a   0xa0134ce0
a0134d0c:  a2 04 60 01  inc  %l1
a0134d10:  d2 0c 3f f0  ldub  [ %l0 + -16 ], %o1
a0134d14:  7f fe a9 17  call  0xa00df170
a0134d18:  90 15 e0 b8  or  %l7, 0xb8, %o0
a0134d1c:  10 bf ff f1  b  0xa0134ce0
a0134d20:  a2 04 60 01  inc  %l1
a0134d24:  7f fe a2 3c  call  0xa00dd614
a0134d28:  90 10 20 20  mov  0x20, %o0
a0134d2c:  80 8a 20 ff  btst  0xff, %o0
a0134d30:  02 80 00 2a  be  0xa0134dd8
a0134d34:  2b 00 06 95  sethi  %hi(0x1a5400), %l5
a0134d38:  90 15 60 d0  or  %l5, 0xd0, %o0	! 0x1a54d0
a0134d3c:  7f fe a9 0d  call  0xa00df170
a0134d40:  92 10 20 01  mov  1, %o1
a0134d44:  30 80 00 25  b,a   0xa0134dd8
a0134d48:  7f fe a2 33  call  0xa00dd614
a0134d4c:  90 10 20 20  mov  0x20, %o0
a0134d50:  80 8a 20 ff  btst  0xff, %o0
a0134d54:  02 80 00 21  be  0xa0134dd8
a0134d58:  23 00 06 95  sethi  %hi(0x1a5400), %l1
a0134d5c:  10 bf ff f8  b  0xa0134d3c
a0134d60:  90 14 61 08  or  %l1, 0x108, %o0	! 0x1a5508
a0134d64:  80 8d 60 01  btst  1, %l5
a0134d68:  02 80 00 1c  be  0xa0134dd8
a0134d6c:  a8 04 80 13  add  %l2, %l3, %l4
a0134d70:  27 2a 00 b2  sethi  %hi(0xa802c800), %l3
a0134d74:  a4 10 20 01  mov  1, %l2
a0134d78:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a0134d7c:  e8 2c e3 8e  stb  %l4, [ %l3 + 0x38e ]
a0134d80:  10 80 00 16  b  0xa0134dd8
a0134d84:  e4 2c 23 8f  stb  %l2, [ %l0 + 0x38f ]
a0134d88:  90 14 20 b0  or  %l0, 0xb0, %o0
a0134d8c:  7f fe a8 f9  call  0xa00df170
a0134d90:  92 10 20 00  clr  %o1
a0134d94:  10 bf ff 6a  b  0xa0134b3c
a0134d98:  80 a4 60 00  cmp  %l1, 0
a0134d9c:  17 00 06 94  sethi  %hi(0x1a5000), %o3
a0134da0:  7f fe a8 f4  call  0xa00df170
a0134da4:  90 12 e3 e0  or  %o3, 0x3e0, %o0	! 0x1a53e0
a0134da8:  30 80 00 0c  b,a   0xa0134dd8
a0134dac:  90 15 a0 c0  or  %l6, 0xc0, %o0
a0134db0:  7f fe a8 f0  call  0xa00df170
a0134db4:  92 10 20 01  mov  1, %o1
a0134db8:  10 bf ff c1  b  0xa0134cbc
a0134dbc:  80 a5 20 00  cmp  %l4, 0
a0134dc0:  19 00 06 95  sethi  %hi(0x1a5400), %o4
a0134dc4:  90 13 20 f0  or  %o4, 0xf0, %o0	! 0x1a54f0
a0134dc8:  7f fe a8 ea  call  0xa00df170
a0134dcc:  92 0d 20 ff  and  %l4, 0xff, %o1
a0134dd0:  10 bf ff 39  b  0xa0134ab4
a0134dd4:  2d 2a 00 b2  sethi  %hi(0xa802c800), %l6
a0134dd8:  81 c7 e0 08  ret
a0134ddc:  81 e8 00 00  restore
