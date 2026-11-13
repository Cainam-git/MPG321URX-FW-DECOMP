# leon2m FUN_a00a1a68 0xa00a1a68-0xa00a1cf0 (508 bytes)
a00a1a68:  9d e3 bf 98  save  %sp, -104, %sp
a00a1a6c:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a00a1a70:  40 00 1e 53  call  0xa00a93bc
a00a1a74:  d0 08 60 56  ldub  [ %g1 + 0x56 ], %o0	! 0xa8025c56
a00a1a78:  40 00 1c 84  call  0xa00a8c88
a00a1a7c:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a00a1a80:  c2 06 63 ec  ld  [ %i1 + 0x3ec ], %g1	! 0xa802afec
a00a1a84:  80 a0 60 c1  cmp  %g1, 0xc1
a00a1a88:  02 80 00 8f  be  0xa00a1cc4
a00a1a8c:  b0 10 00 19  mov  %i1, %i0
a00a1a90:  80 a0 60 c1  cmp  %g1, 0xc1
a00a1a94:  08 80 00 10  bleu  0xa00a1ad4
a00a1a98:  80 a0 60 c0  cmp  %g1, 0xc0
a00a1a9c:  80 a0 60 c2  cmp  %g1, 0xc2
a00a1aa0:  22 80 00 8f  be,a   0xa00a1cdc
a00a1aa4:  17 00 04 20  sethi  %hi(0x108000), %o3
a00a1aa8:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4
a00a1aac:  82 03 3f 40  add  %o4, -192, %g1
a00a1ab0:  80 a0 60 39  cmp  %g1, 0x39
a00a1ab4:  18 80 00 14  bgu  0xa00a1b04
a00a1ab8:  96 10 20 00  clr  %o3
a00a1abc:  11 00 00 bf  sethi  %hi(0x2fc00), %o0
a00a1ac0:  b1 28 60 02  sll  %g1, 2, %i0
a00a1ac4:  9a 12 23 c8  or  %o0, 0x3c8, %o5
a00a1ac8:  de 03 40 18  ld  [ %o5 + %i0 ], %o7
a00a1acc:  81 c3 c0 00  jmp  %o7
a00a1ad0:  01 00 00 00  nop
a00a1ad4:  12 bf ff f6  bne  0xa00a1aac
a00a1ad8:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4
a00a1adc:  11 00 04 20  sethi  %hi(0x108000), %o0
a00a1ae0:  40 00 f5 a4  call  0xa00df170
a00a1ae4:  90 12 21 d0  or  %o0, 0x1d0, %o0	! 0x1081d0
a00a1ae8:  82 10 20 f7  mov  0xf7, %g1
a00a1aec:  c2 26 23 ec  st  %g1, [ %i0 + 0x3ec ]
a00a1af0:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4
a00a1af4:  82 03 3f 40  add  %o4, -192, %g1
a00a1af8:  80 a0 60 39  cmp  %g1, 0x39
a00a1afc:  08 bf ff f0  bleu  0xa00a1abc
a00a1b00:  96 10 20 00  clr  %o3
a00a1b04:  94 10 20 00  clr  %o2
a00a1b08:  d6 06 63 ec  ld  [ %i1 + 0x3ec ], %o3
a00a1b0c:  82 02 ff 40  add  %o3, -192, %g1
a00a1b10:  94 0a a0 ff  and  %o2, 0xff, %o2
a00a1b14:  80 a0 60 39  cmp  %g1, 0x39
a00a1b18:  18 80 00 08  bgu  0xa00a1b38
a00a1b1c:  96 10 20 00  clr  %o3
a00a1b20:  11 00 00 bf  sethi  %hi(0x2fc00), %o0
a00a1b24:  b1 28 60 02  sll  %g1, 2, %i0
a00a1b28:  9a 12 22 e0  or  %o0, 0x2e0, %o5
a00a1b2c:  de 03 40 18  ld  [ %o5 + %i0 ], %o7
a00a1b30:  81 c3 c0 00  jmp  %o7
a00a1b34:  01 00 00 00  nop
a00a1b38:  98 10 20 00  clr  %o4	! 0x0
a00a1b3c:  d6 06 63 ec  ld  [ %i1 + 0x3ec ], %o3
a00a1b40:  82 02 ff 40  add  %o3, -192, %g1
a00a1b44:  92 0b 20 ff  and  %o4, 0xff, %o1
a00a1b48:  80 a0 60 39  cmp  %g1, 0x39
a00a1b4c:  18 80 00 08  bgu  0xa00a1b6c
a00a1b50:  96 10 20 00  clr  %o3
a00a1b54:  19 00 00 bf  sethi  %hi(0x2fc00), %o4
a00a1b58:  91 28 60 02  sll  %g1, 2, %o0
a00a1b5c:  9a 13 21 f8  or  %o4, 0x1f8, %o5
a00a1b60:  f0 03 40 08  ld  [ %o5 + %o0 ], %i0
a00a1b64:  81 c6 00 00  jmp  %i0
a00a1b68:  01 00 00 00  nop
a00a1b6c:  82 10 20 00  clr  %g1	! 0x0
a00a1b70:  b0 22 40 01  sub  %o1, %g1, %i0
a00a1b74:  96 06 00 18  add  %i0, %i0, %o3
a00a1b78:  82 02 c0 18  add  %o3, %i0, %g1
a00a1b7c:  de 06 63 ec  ld  [ %i1 + 0x3ec ], %o7
a00a1b80:  9a 03 ff 40  add  %o7, -192, %o5
a00a1b84:  93 28 60 05  sll  %g1, 5, %o1
a00a1b88:  9e 00 40 09  add  %g1, %o1, %o7
a00a1b8c:  80 a3 60 39  cmp  %o5, 0x39
a00a1b90:  18 80 00 08  bgu  0xa00a1bb0
a00a1b94:  96 10 20 00  clr  %o3
a00a1b98:  99 2b 60 02  sll  %o5, 2, %o4
a00a1b9c:  13 00 00 bf  sethi  %hi(0x2fc00), %o1
a00a1ba0:  9a 12 61 10  or  %o1, 0x110, %o5	! 0x2fd10
a00a1ba4:  d0 03 40 0c  ld  [ %o5 + %o4 ], %o0
a00a1ba8:  81 c2 00 00  jmp  %o0
a00a1bac:  01 00 00 00  nop
a00a1bb0:  92 10 20 00  clr  %o1	! 0x0
a00a1bb4:  c2 06 63 ec  ld  [ %i1 + 0x3ec ], %g1
a00a1bb8:  82 00 7f 40  add  %g1, -192, %g1
a00a1bbc:  90 0a 60 ff  and  %o1, 0xff, %o0
a00a1bc0:  80 a0 60 39  cmp  %g1, 0x39
a00a1bc4:  18 80 00 08  bgu  0xa00a1be4
a00a1bc8:  96 10 20 00  clr  %o3
a00a1bcc:  13 00 00 bf  sethi  %hi(0x2fc00), %o1
a00a1bd0:  99 28 60 02  sll  %g1, 2, %o4
a00a1bd4:  9a 12 60 28  or  %o1, 0x28, %o5
a00a1bd8:  f0 03 40 0c  ld  [ %o5 + %o4 ], %i0
a00a1bdc:  81 c6 00 00  jmp  %i0
a00a1be0:  01 00 00 00  nop
a00a1be4:  92 10 20 00  clr  %o1	! 0x0
a00a1be8:  b0 22 00 09  sub  %o0, %o1, %i0
a00a1bec:  83 3b e0 1f  sra  %o7, 0x1f, %g1
a00a1bf0:  81 80 60 00  mov  %g1, %y
a00a1bf4:  01 00 00 00  nop
a00a1bf8:  01 00 00 00  nop
a00a1bfc:  01 00 00 00  nop
a00a1c00:  96 7b c0 18  sdiv  %o7, %i0, %o3
a00a1c04:  9e 02 e0 01  add  %o3, 1, %o7
a00a1c08:  92 0b e0 ff  and  %o7, 0xff, %o1
a00a1c0c:  40 00 58 97  call  0xa00b7e68
a00a1c10:  90 10 20 01  mov  1, %o0
a00a1c14:  90 10 20 00  clr  %o0
a00a1c18:  40 00 1e 8e  call  0xa00a9650
a00a1c1c:  92 10 20 01  mov  1, %o1
a00a1c20:  f0 0e 63 ef  ldub  [ %i1 + 0x3ef ], %i0
a00a1c24:  40 00 34 88  call  0xa00aee44
a00a1c28:  93 e8 20 00  restore  %g0, 0, %o1
a00a1c2c:  96 10 20 01  mov  1, %o3
a00a1c30:  10 bf ff ee  b  0xa00a1be8
a00a1c34:  92 0a e0 ff  and  %o3, 0xff, %o1
a00a1c38:  96 10 20 01  mov  1, %o3
a00a1c3c:  10 bf ff cd  b  0xa00a1b70
a00a1c40:  82 0a e0 ff  and  %o3, 0xff, %g1
a00a1c44:  96 10 20 03  mov  3, %o3
a00a1c48:  10 bf ff db  b  0xa00a1bb4
a00a1c4c:  92 0a e0 ff  and  %o3, 0xff, %o1
a00a1c50:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a00a1c54:  d6 0b e0 7d  ldub  [ %o7 + 0x7d ], %o3	! 0xa802d47d
a00a1c58:  10 bf ff b9  b  0xa00a1b3c
a00a1c5c:  98 0a e0 ff  and  %o3, 0xff, %o4
a00a1c60:  19 2a 00 b5  sethi  %hi(0xa802d400), %o4
a00a1c64:  d6 0b 20 7d  ldub  [ %o4 + 0x7d ], %o3	! 0xa802d47d
a00a1c68:  10 bf ff a8  b  0xa00a1b08
a00a1c6c:  94 0a e0 ff  and  %o3, 0xff, %o2
a00a1c70:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00a1c74:  92 12 a2 90  or  %o2, 0x290, %o1	! 0xa802d290
a00a1c78:  d6 0a 61 eb  ldub  [ %o1 + 0x1eb ], %o3
a00a1c7c:  10 bf ff a3  b  0xa00a1b08
a00a1c80:  94 0a e0 ff  and  %o3, 0xff, %o2
a00a1c84:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00a1c88:  92 13 22 90  or  %o4, 0x290, %o1	! 0xa802d290
a00a1c8c:  d6 0a 61 eb  ldub  [ %o1 + 0x1eb ], %o3
a00a1c90:  10 bf ff ab  b  0xa00a1b3c
a00a1c94:  98 0a e0 ff  and  %o3, 0xff, %o4
a00a1c98:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00a1c9c:  d6 08 60 79  ldub  [ %g1 + 0x79 ], %o3	! 0xa802d479
a00a1ca0:  10 bf ff a7  b  0xa00a1b3c
a00a1ca4:  98 0a e0 ff  and  %o3, 0xff, %o4
a00a1ca8:  96 10 20 02  mov  2, %o3
a00a1cac:  10 bf ff c2  b  0xa00a1bb4
a00a1cb0:  92 0a e0 ff  and  %o3, 0xff, %o1
a00a1cb4:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00a1cb8:  d6 08 60 79  ldub  [ %g1 + 0x79 ], %o3	! 0xa802d479
a00a1cbc:  10 bf ff 93  b  0xa00a1b08
a00a1cc0:  94 0a e0 ff  and  %o3, 0xff, %o2
a00a1cc4:  15 00 04 20  sethi  %hi(0x108000), %o2
a00a1cc8:  40 00 f5 2a  call  0xa00df170
a00a1ccc:  90 12 a1 e0  or  %o2, 0x1e0, %o0	! 0x1081e0
a00a1cd0:  92 10 20 f8  mov  0xf8, %o1
a00a1cd4:  10 bf ff 75  b  0xa00a1aa8
a00a1cd8:  d2 26 63 ec  st  %o1, [ %i1 + 0x3ec ]
a00a1cdc:  40 00 f5 25  call  0xa00df170
a00a1ce0:  90 12 e1 c0  or  %o3, 0x1c0, %o0
a00a1ce4:  82 10 20 f9  mov  0xf9, %g1
a00a1ce8:  10 bf ff 82  b  0xa00a1af0
a00a1cec:  c2 26 23 ec  st  %g1, [ %i0 + 0x3ec ]
