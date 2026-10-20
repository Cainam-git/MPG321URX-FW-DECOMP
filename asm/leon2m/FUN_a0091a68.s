# leon2m FUN_a0091a68 0xa0091a68-0xa0091b94 (300 bytes)
a0091a68:  9d e3 bf 98  save  %sp, -104, %sp
a0091a6c:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0091a70:  d0 06 63 ec  ld  [ %i1 + 0x3ec ], %o0	! 0xa802afec
a0091a74:  82 02 3f f2  add  %o0, -14, %g1
a0091a78:  40 00 5d 1c  call  0xa00a8ee8
a0091a7c:  90 08 60 ff  and  %g1, 0xff, %o0
a0091a80:  da 06 63 ec  ld  [ %i1 + 0x3ec ], %o5
a0091a84:  b0 03 7f f2  add  %o5, -14, %i0
a0091a88:  90 0e 20 ff  and  %i0, 0xff, %o0
a0091a8c:  40 00 61 97  call  0xa00aa0e8
a0091a90:  92 10 20 00  clr  %o1
a0091a94:  e0 06 63 ec  ld  [ %i1 + 0x3ec ], %l0
a0091a98:  1f 09 24 92  sethi  %hi(0x24924800), %o7
a0091a9c:  96 04 3f f2  add  %l0, -14, %o3
a0091aa0:  98 13 e1 25  or  %o7, 0x125, %o4
a0091aa4:  80 52 c0 0c  umul  %o3, %o4, %g0
a0091aa8:  91 40 00 00  rd  %y, %o0
a0091aac:  94 22 c0 08  sub  %o3, %o0, %o2
a0091ab0:  93 32 a0 01  srl  %o2, 1, %o1
a0091ab4:  82 02 00 09  add  %o0, %o1, %g1
a0091ab8:  1b 24 92 49  sethi  %hi(0x92492400), %o5
a0091abc:  a1 30 60 02  srl  %g1, 2, %l0
a0091ac0:  b0 13 60 93  or  %o5, 0x93, %i0
a0091ac4:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a0091ac8:  9e 02 3f f8  add  %o0, -8, %o7
a0091acc:  80 5b c0 18  smul  %o7, %i0, %g0
a0091ad0:  99 40 00 00  rd  %y, %o4
a0091ad4:  96 03 00 0f  add  %o4, %o7, %o3
a0091ad8:  93 3a e0 02  sra  %o3, 2, %o1
a0091adc:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a0091ae0:  82 22 40 0a  sub  %o1, %o2, %g1
a0091ae4:  9b 28 60 03  sll  %g1, 3, %o5
a0091ae8:  98 23 40 01  sub  %o5, %g1, %o4
a0091aec:  94 23 c0 0c  sub  %o7, %o4, %o2
a0091af0:  96 02 a0 0e  add  %o2, 0xe, %o3
a0091af4:  d6 26 63 ec  st  %o3, [ %i1 + 0x3ec ]
a0091af8:  40 00 62 8a  call  0xa00aa520
a0091afc:  90 0a a0 ff  and  %o2, 0xff, %o0
a0091b00:  92 0a 20 ff  and  %o0, 0xff, %o1
a0091b04:  80 a2 60 01  cmp  %o1, 1
a0091b08:  12 bf ff f0  bne  0xa0091ac8
a0091b0c:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a0091b10:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4
a0091b14:  17 09 24 92  sethi  %hi(0x24924800), %o3
a0091b18:  94 03 3f f2  add  %o4, -14, %o2
a0091b1c:  9a 12 e1 25  or  %o3, 0x125, %o5
a0091b20:  80 52 80 0d  umul  %o2, %o5, %g0
a0091b24:  9f 40 00 00  rd  %y, %o7
a0091b28:  92 22 80 0f  sub  %o2, %o7, %o1
a0091b2c:  83 32 60 01  srl  %o1, 1, %g1
a0091b30:  b0 03 c0 01  add  %o7, %g1, %i0
a0091b34:  b2 0c 20 ff  and  %l0, 0xff, %i1
a0091b38:  91 36 20 02  srl  %i0, 2, %o0
a0091b3c:  80 a6 40 08  cmp  %i1, %o0
a0091b40:  02 80 00 05  be  0xa0091b54
a0091b44:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0091b48:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091b4c:  40 00 6d 38  call  0xa00ad02c
a0091b50:  92 10 20 01  mov  1, %o1
a0091b54:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1
a0091b58:  82 02 7f f2  add  %o1, -14, %g1
a0091b5c:  90 08 60 ff  and  %g1, 0xff, %o0
a0091b60:  40 00 5d 2b  call  0xa00a900c
a0091b64:  92 10 20 01  mov  1, %o1
a0091b68:  de 06 63 ec  ld  [ %i1 + 0x3ec ], %o7
a0091b6c:  b0 03 ff f2  add  %o7, -14, %i0
a0091b70:  90 0e 20 ff  and  %i0, 0xff, %o0
a0091b74:  40 00 61 5d  call  0xa00aa0e8
a0091b78:  92 10 20 01  mov  1, %o1
a0091b7c:  d0 06 63 ec  ld  [ %i1 + 0x3ec ], %o0
a0091b80:  a0 02 3f f2  add  %o0, -14, %l0
a0091b84:  b2 0c 20 ff  and  %l0, 0xff, %i1
a0091b88:  40 00 76 31  call  0xa00af44c
a0091b8c:  91 e8 20 0e  restore  %g0, 0xe, %o0
a0091b90:  01 00 00 00  nop
