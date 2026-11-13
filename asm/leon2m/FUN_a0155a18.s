# leon2m FUN_a0155a18 0xa0155a18-0xa0155b78 (352 bytes)
a0155a18:  9d e3 bf 70  save  %sp, -144, %sp
a0155a1c:  a0 07 bf e8  add  %fp, -24, %l0
a0155a20:  f2 27 bf d0  st  %i1, [ %fp + -48 ]
a0155a24:  90 07 bf d4  add  %fp, -44, %o0
a0155a28:  92 10 00 10  mov  %l0, %o1
a0155a2c:  40 00 05 42  call  0xa0156f34
a0155a30:  f0 27 bf d4  st  %i0, [ %fp + -44 ]
a0155a34:  b2 07 bf d8  add  %fp, -40, %i1
a0155a38:  90 07 bf d0  add  %fp, -48, %o0
a0155a3c:  40 00 05 3e  call  0xa0156f34
a0155a40:  92 10 00 19  mov  %i1, %o1
a0155a44:  d8 07 bf e8  ld  [ %fp + -24 ], %o4
a0155a48:  80 a3 20 01  cmp  %o4, 1
a0155a4c:  08 80 00 47  bleu  0xa0155b68
a0155a50:  90 10 00 10  mov  %l0, %o0
a0155a54:  d6 07 bf d8  ld  [ %fp + -40 ], %o3
a0155a58:  80 a2 e0 01  cmp  %o3, 1
a0155a5c:  08 80 00 43  bleu  0xa0155b68
a0155a60:  90 10 00 19  mov  %i1, %o0
a0155a64:  c2 07 bf ec  ld  [ %fp + -20 ], %g1
a0155a68:  da 07 bf dc  ld  [ %fp + -36 ], %o5
a0155a6c:  82 18 40 0d  xor  %g1, %o5, %g1
a0155a70:  80 a3 20 04  cmp  %o4, 4
a0155a74:  02 80 00 0f  be  0xa0155ab0
a0155a78:  c2 27 bf ec  st  %g1, [ %fp + -20 ]
a0155a7c:  80 a3 20 02  cmp  %o4, 2
a0155a80:  22 80 00 0d  be,a   0xa0155ab4
a0155a84:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0155a88:  80 a2 e0 04  cmp  %o3, 4
a0155a8c:  22 80 00 0f  be,a   0xa0155ac8
a0155a90:  c0 27 bf f4  clr  [ %fp + -12 ]
a0155a94:  80 a2 e0 02  cmp  %o3, 2
a0155a98:  12 80 00 0f  bne  0xa0155ad4
a0155a9c:  d8 07 bf f4  ld  [ %fp + -12 ], %o4
a0155aa0:  82 10 20 04  mov  4, %g1
a0155aa4:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a0155aa8:  10 80 00 30  b  0xa0155b68
a0155aac:  90 10 00 10  mov  %l0, %o0
a0155ab0:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0155ab4:  80 a3 00 0b  cmp  %o4, %o3
a0155ab8:  02 80 00 2c  be  0xa0155b68
a0155abc:  90 10 62 b0  or  %g1, 0x2b0, %o0
a0155ac0:  10 80 00 2a  b  0xa0155b68
a0155ac4:  90 10 00 10  mov  %l0, %o0
a0155ac8:  c0 27 bf f0  clr  [ %fp + -16 ]
a0155acc:  10 80 00 27  b  0xa0155b68
a0155ad0:  90 10 00 10  mov  %l0, %o0
a0155ad4:  d6 07 bf e4  ld  [ %fp + -28 ], %o3
a0155ad8:  da 07 bf f0  ld  [ %fp + -16 ], %o5
a0155adc:  c2 07 bf e0  ld  [ %fp + -32 ], %g1
a0155ae0:  80 a3 00 0b  cmp  %o4, %o3
a0155ae4:  1a 80 00 1f  bcc  0xa0155b60
a0155ae8:  82 23 40 01  sub  %o5, %g1, %g1
a0155aec:  82 00 7f ff  add  %g1, -1, %g1
a0155af0:  c2 27 bf f0  st  %g1, [ %fp + -16 ]
a0155af4:  98 03 00 0c  add  %o4, %o4, %o4
a0155af8:  03 10 00 00  sethi  %hi(0x40000000), %g1
a0155afc:  9a 10 20 00  clr  %o5
a0155b00:  80 a3 00 0b  cmp  %o4, %o3
a0155b04:  2a 80 00 05  bcs,a   0xa0155b18
a0155b08:  83 30 60 01  srl  %g1, 1, %g1
a0155b0c:  9a 13 40 01  or  %o5, %g1, %o5
a0155b10:  98 23 00 0b  sub  %o4, %o3, %o4
a0155b14:  83 30 60 01  srl  %g1, 1, %g1
a0155b18:  80 a0 60 00  cmp  %g1, 0
a0155b1c:  12 bf ff f9  bne  0xa0155b00
a0155b20:  98 03 00 0c  add  %o4, %o4, %o4
a0155b24:  82 0b 60 7f  and  %o5, 0x7f, %g1
a0155b28:  80 a0 60 40  cmp  %g1, 0x40
a0155b2c:  02 80 00 05  be  0xa0155b40
a0155b30:  80 8b 60 80  btst  0x80, %o5
a0155b34:  da 24 20 0c  st  %o5, [ %l0 + 0xc ]
a0155b38:  10 80 00 0c  b  0xa0155b68
a0155b3c:  90 10 00 10  mov  %l0, %o0
a0155b40:  32 80 00 06  bne,a   0xa0155b58
a0155b44:  9a 03 60 40  add  %o5, 0x40, %o5
a0155b48:  80 a3 20 00  cmp  %o4, 0
a0155b4c:  22 bf ff fb  be,a   0xa0155b38
a0155b50:  da 24 20 0c  st  %o5, [ %l0 + 0xc ]
a0155b54:  9a 03 60 40  add  %o5, 0x40, %o5
a0155b58:  10 bf ff f8  b  0xa0155b38
a0155b5c:  da 24 20 0c  st  %o5, [ %l0 + 0xc ]
a0155b60:  10 bf ff e6  b  0xa0155af8
a0155b64:  c2 27 bf f0  st  %g1, [ %fp + -16 ]
a0155b68:  40 00 04 a1  call  0xa0156dec
a0155b6c:  01 00 00 00  nop
a0155b70:  81 c7 e0 08  ret
a0155b74:  91 e8 00 08  restore  %g0, %o0, %o0
