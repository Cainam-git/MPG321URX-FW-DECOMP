# leon2m FUN_a0098c08 0xa0098c08-0xa0098d4c (324 bytes)
a0098c08:  9d e3 bf 98  save  %sp, -104, %sp
a0098c0c:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0098c10:  d0 06 63 ec  ld  [ %i1 + 0x3ec ], %o0	! 0xa802afec
a0098c14:  13 09 24 92  sethi  %hi(0x24924800), %o1
a0098c18:  94 02 3f 6e  add  %o0, -146, %o2
a0098c1c:  82 12 61 25  or  %o1, 0x125, %g1
a0098c20:  80 52 80 01  umul  %o2, %g1, %g0
a0098c24:  a3 40 00 00  rd  %y, %l1
a0098c28:  9a 22 80 11  sub  %o2, %l1, %o5
a0098c2c:  b1 33 60 01  srl  %o5, 1, %i0
a0098c30:  a0 04 40 18  add  %l1, %i0, %l0
a0098c34:  9f 34 20 02  srl  %l0, 2, %o7
a0098c38:  99 2b e0 03  sll  %o7, 3, %o4
a0098c3c:  96 23 00 0f  sub  %o4, %o7, %o3
a0098c40:  92 22 80 0b  sub  %o2, %o3, %o1
a0098c44:  40 00 41 de  call  0xa00a93bc
a0098c48:  90 0a 60 ff  and  %o1, 0xff, %o0
a0098c4c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a0098c50:  11 2a 00 97  sethi  %hi(0xa8025c00), %o0
a0098c54:  d8 0a 20 56  ldub  [ %o0 + 0x56 ], %o4	! 0xa8025c56
a0098c58:  a0 14 62 90  or  %l1, 0x290, %l0
a0098c5c:  da 0c 20 08  ldub  [ %l0 + 8 ], %o5
a0098c60:  82 0b 20 ff  and  %o4, 0xff, %g1
a0098c64:  80 a3 40 01  cmp  %o5, %g1
a0098c68:  22 80 00 15  be,a   0xa0098cbc
a0098c6c:  a2 14 62 90  or  %l1, 0x290, %l1
a0098c70:  40 00 40 06  call  0xa00a8c88
a0098c74:  d8 2c 20 08  stb  %o4, [ %l0 + 8 ]
a0098c78:  c2 0c 20 08  ldub  [ %l0 + 8 ], %g1
a0098c7c:  80 a0 60 1c  cmp  %g1, 0x1c
a0098c80:  02 80 00 0b  be  0xa0098cac
a0098c84:  90 10 20 04  mov  4, %o0
a0098c88:  80 a0 60 14  cmp  %g1, 0x14
a0098c8c:  18 80 00 08  bgu  0xa0098cac
a0098c90:  90 10 20 03  mov  3, %o0
a0098c94:  80 a0 60 0d  cmp  %g1, 0xd
a0098c98:  18 80 00 05  bgu  0xa0098cac
a0098c9c:  90 10 20 02  mov  2, %o0
a0098ca0:  80 a0 60 06  cmp  %g1, 6
a0098ca4:  08 80 00 28  bleu  0xa0098d44
a0098ca8:  90 10 20 01  mov  1, %o0
a0098cac:  40 00 3e c8  call  0xa00a87cc
a0098cb0:  a2 14 62 90  or  %l1, 0x290, %l1
a0098cb4:  40 00 51 eb  call  0xa00ad460
a0098cb8:  01 00 00 00  nop
a0098cbc:  21 09 24 92  sethi  %hi(0x24924800), %l0
a0098cc0:  d4 0c 60 08  ldub  [ %l1 + 8 ], %o2
a0098cc4:  a0 14 21 25  or  %l0, 0x125, %l0
a0098cc8:  80 52 80 10  umul  %o2, %l0, %g0
a0098ccc:  83 40 00 00  rd  %y, %g1
a0098cd0:  92 22 80 01  sub  %o2, %g1, %o1
a0098cd4:  9b 32 60 01  srl  %o1, 1, %o5
a0098cd8:  b0 00 40 0d  add  %g1, %o5, %i0
a0098cdc:  9f 36 20 02  srl  %i0, 2, %o7
a0098ce0:  99 2b e0 03  sll  %o7, 3, %o4
a0098ce4:  96 23 00 0f  sub  %o4, %o7, %o3
a0098ce8:  90 22 80 0b  sub  %o2, %o3, %o0
a0098cec:  90 0a 20 ff  and  %o0, 0xff, %o0
a0098cf0:  40 00 42 58  call  0xa00a9650
a0098cf4:  92 10 20 00  clr  %o1
a0098cf8:  d8 0c 60 08  ldub  [ %l1 + 8 ], %o4
a0098cfc:  80 53 00 10  umul  %o4, %l0, %g0
a0098d00:  9b 40 00 00  rd  %y, %o5
a0098d04:  92 23 00 0d  sub  %o4, %o5, %o1
a0098d08:  83 32 60 01  srl  %o1, 1, %g1
a0098d0c:  b0 03 40 01  add  %o5, %g1, %i0
a0098d10:  a1 36 20 02  srl  %i0, 2, %l0
a0098d14:  a3 2c 20 03  sll  %l0, 3, %l1
a0098d18:  9e 24 40 10  sub  %l1, %l0, %o7
a0098d1c:  96 23 00 0f  sub  %o4, %o7, %o3
a0098d20:  94 10 20 01  mov  1, %o2
a0098d24:  92 0a e0 ff  and  %o3, 0xff, %o1
a0098d28:  40 00 3d 05  call  0xa00a813c
a0098d2c:  90 10 20 01  mov  1, %o0
a0098d30:  94 10 20 2a  mov  0x2a, %o2
a0098d34:  d4 26 63 ec  st  %o2, [ %i1 + 0x3ec ]
a0098d38:  b0 10 20 00  clr  %i0
a0098d3c:  40 00 40 b4  call  0xa00a900c
a0098d40:  93 e8 20 01  restore  %g0, 1, %o1
a0098d44:  10 bf ff da  b  0xa0098cac
a0098d48:  90 10 20 00  clr  %o0
