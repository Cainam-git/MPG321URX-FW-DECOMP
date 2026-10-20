# leon2m FUN_a00dfa10 0xa00dfa10-0xa00dfb30 (136 bytes)
a00dfa10:  9d e3 bf 98  save  %sp, -104, %sp
a00dfa14:  82 1e 20 02  xor  %i0, 2, %g1
a00dfa18:  80 a0 00 01  cmp  %g0, %g1
a00dfa1c:  a0 10 00 18  mov  %i0, %l0
a00dfa20:  b0 60 3f ff  subx  %g0, -1, %i0
a00dfa24:  80 a6 20 00  cmp  %i0, 0
a00dfa28:  12 80 00 40  bne  0xa00dfb28
a00dfa2c:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00dfa30:  da 02 e1 30  ld  [ %o3 + 0x130 ], %o5	! 0xa802b530
a00dfa34:  11 00 06 64  sethi  %hi(0x199000), %o0
a00dfa38:  80 a3 60 0c  cmp  %o5, 0xc
a00dfa3c:  18 80 00 0a  bgu  0xa00dfa64
a00dfa40:  92 12 22 88  or  %o0, 0x288, %o1
a00dfa44:  93 2b 60 02  sll  %o5, 2, %o1
a00dfa48:  15 00 01 fd  sethi  %hi(0x7f400), %o2
a00dfa4c:  9a 12 a3 00  or  %o2, 0x300, %o5	! 0x7f700
a00dfa50:  d8 03 40 09  ld  [ %o5 + %o1 ], %o4
a00dfa54:  81 c3 00 00  jmp  %o4
a00dfa58:  01 00 00 00  nop
a00dfa5c:  15 00 06 64  sethi  %hi(0x199000), %o2
a00dfa60:  92 12 a2 90  or  %o2, 0x290, %o1	! 0x199290
a00dfa64:  82 12 e1 30  or  %o3, 0x130, %g1
a00dfa68:  11 00 06 64  sethi  %hi(0x199000), %o0
a00dfa6c:  d6 00 60 08  ld  [ %g1 + 8 ], %o3
a00dfa70:  d4 00 60 04  ld  [ %g1 + 4 ], %o2
a00dfa74:  7f ff fd bf  call  0xa00df170
a00dfa78:  90 12 22 98  or  %o0, 0x298, %o0
a00dfa7c:  40 00 04 57  call  0xa00e0bd8
a00dfa80:  01 00 00 00  nop
a00dfa84:  17 00 06 64  sethi  %hi(0x199000), %o3
a00dfa88:  90 12 e3 40  or  %o3, 0x340, %o0	! 0x199340
a00dfa8c:  7f ff fd b9  call  0xa00df170
a00dfa90:  92 10 00 10  mov  %l0, %o1
a00dfa94:  30 80 00 25  b,a   0xa00dfb28
a00dfa98:  1f 00 06 64  sethi  %hi(0x199000), %o7
a00dfa9c:  10 bf ff f2  b  0xa00dfa64
a00dfaa0:  92 13 e2 b0  or  %o7, 0x2b0, %o1	! 0x1992b0
a00dfaa4:  1f 00 06 64  sethi  %hi(0x199000), %o7
a00dfaa8:  10 bf ff ef  b  0xa00dfa64
a00dfaac:  92 13 e3 20  or  %o7, 0x320, %o1	! 0x199320
a00dfab0:  03 00 06 64  sethi  %hi(0x199000), %g1
a00dfab4:  10 bf ff ec  b  0xa00dfa64
a00dfab8:  92 10 63 10  or  %g1, 0x310, %o1	! 0x199310
a00dfabc:  11 00 06 64  sethi  %hi(0x199000), %o0
a00dfac0:  10 bf ff e9  b  0xa00dfa64
a00dfac4:  92 12 23 08  or  %o0, 0x308, %o1	! 0x199308
a00dfac8:  19 00 06 64  sethi  %hi(0x199000), %o4
a00dfacc:  10 bf ff e6  b  0xa00dfa64
a00dfad0:  92 13 23 00  or  %o4, 0x300, %o1	! 0x199300
a00dfad4:  1b 00 06 64  sethi  %hi(0x199000), %o5
a00dfad8:  10 bf ff e3  b  0xa00dfa64
a00dfadc:  92 13 62 f8  or  %o5, 0x2f8, %o1	! 0x1992f8
a00dfae0:  15 00 06 64  sethi  %hi(0x199000), %o2
a00dfae4:  10 bf ff e0  b  0xa00dfa64
a00dfae8:  92 12 a2 f0  or  %o2, 0x2f0, %o1	! 0x1992f0
a00dfaec:  1f 00 06 64  sethi  %hi(0x199000), %o7
a00dfaf0:  10 bf ff dd  b  0xa00dfa64
a00dfaf4:  92 13 e2 e8  or  %o7, 0x2e8, %o1	! 0x1992e8
a00dfaf8:  03 00 06 64  sethi  %hi(0x199000), %g1
a00dfafc:  10 bf ff da  b  0xa00dfa64
a00dfb00:  92 10 62 d8  or  %g1, 0x2d8, %o1	! 0x1992d8
a00dfb04:  11 00 06 64  sethi  %hi(0x199000), %o0
a00dfb08:  10 bf ff d7  b  0xa00dfa64
a00dfb0c:  92 12 22 d0  or  %o0, 0x2d0, %o1	! 0x1992d0
a00dfb10:  19 00 06 64  sethi  %hi(0x199000), %o4
a00dfb14:  10 bf ff d4  b  0xa00dfa64
a00dfb18:  92 13 22 c8  or  %o4, 0x2c8, %o1	! 0x1992c8
a00dfb1c:  1b 00 06 64  sethi  %hi(0x199000), %o5
a00dfb20:  10 bf ff d1  b  0xa00dfa64
a00dfb24:  92 13 62 b8  or  %o5, 0x2b8, %o1	! 0x1992b8
a00dfb28:  81 c7 e0 08  ret
a00dfb2c:  81 e8 00 00  restore
