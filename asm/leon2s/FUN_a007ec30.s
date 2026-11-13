# leon2s FUN_a007ec30 0xa007ec30-0xa007ed0c (220 bytes)
a007ec30:  9d e3 bf 98  save  %sp, -104, %sp
a007ec34:  b0 0e 20 ff  and  %i0, 0xff, %i0
a007ec38:  7f ff d2 3a  call  0xa0073520
a007ec3c:  90 10 00 18  mov  %i0, %o0
a007ec40:  b6 0e a0 ff  and  %i2, 0xff, %i3
a007ec44:  80 8a 20 ff  btst  0xff, %o0
a007ec48:  96 0e 60 ff  and  %i1, 0xff, %o3
a007ec4c:  98 1e 20 02  xor  %i0, 2, %o4
a007ec50:  92 10 22 f6  mov  0x2f6, %o1
a007ec54:  94 10 20 01  mov  1, %o2
a007ec58:  90 10 00 18  mov  %i0, %o0
a007ec5c:  b2 10 22 f6  mov  0x2f6, %i1
a007ec60:  b4 10 20 04  mov  4, %i2
a007ec64:  a2 10 00 1b  mov  %i3, %l1
a007ec68:  02 80 00 24  be  0xa007ecf8
a007ec6c:  1f 2a 01 f6  sethi  %hi(0xa807d800), %o7
a007ec70:  80 a0 00 0c  cmp  %g0, %o4
a007ec74:  82 40 20 00  addx  %g0, 0, %g1
a007ec78:  80 a2 e0 01  cmp  %o3, 1
a007ec7c:  b6 10 00 01  mov  %g1, %i3
a007ec80:  96 08 60 ff  and  %g1, 0xff, %o3
a007ec84:  9a 13 e3 00  or  %o7, 0x300, %o5
a007ec88:  82 5a e0 34  smul  %o3, 0x34, %g1
a007ec8c:  90 10 20 10  mov  0x10, %o0
a007ec90:  12 80 00 07  bne  0xa007ecac
a007ec94:  9a 00 40 0d  add  %g1, %o5, %o5
a007ec98:  d2 03 60 0c  ld  [ %o5 + 0xc ], %o1
a007ec9c:  40 00 a1 c4  call  0xa00a73ac
a007eca0:  92 02 60 74  add  %o1, 0x74, %o1
a007eca4:  10 80 00 07  b  0xa007ecc0
a007eca8:  96 0e e0 ff  and  %i3, 0xff, %o3
a007ecac:  d2 03 60 0c  ld  [ %o5 + 0xc ], %o1
a007ecb0:  92 02 60 74  add  %o1, 0x74, %o1
a007ecb4:  40 00 a1 c8  call  0xa00a73d4
a007ecb8:  90 10 20 10  mov  0x10, %o0
a007ecbc:  96 0e e0 ff  and  %i3, 0xff, %o3
a007ecc0:  1f 2a 01 f6  sethi  %hi(0xa807d800), %o7
a007ecc4:  98 5a e0 34  smul  %o3, 0x34, %o4
a007ecc8:  82 13 e3 00  or  %o7, 0x300, %g1
a007eccc:  b0 10 20 12  mov  0x12, %i0
a007ecd0:  80 a4 60 01  cmp  %l1, 1
a007ecd4:  12 80 00 05  bne  0xa007ece8
a007ecd8:  98 03 00 01  add  %o4, %g1, %o4
a007ecdc:  f2 03 20 0c  ld  [ %o4 + 0xc ], %i1
a007ece0:  40 00 a1 b3  call  0xa00a73ac
a007ece4:  93 ee 60 74  restore  %i1, 0x74, %o1
a007ece8:  f2 03 20 0c  ld  [ %o4 + 0xc ], %i1
a007ecec:  b2 06 60 74  add  %i1, 0x74, %i1
a007ecf0:  40 00 a1 b9  call  0xa00a73d4
a007ecf4:  91 e8 20 12  restore  %g0, 0x12, %o0
a007ecf8:  40 00 9e b0  call  0xa00a67b8
a007ecfc:  01 00 00 00  nop
a007ed00:  40 00 9e ae  call  0xa00a67b8
a007ed04:  81 e8 00 00  restore
a007ed08:  01 00 00 00  nop
