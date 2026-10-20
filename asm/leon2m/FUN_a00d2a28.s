# leon2m FUN_a00d2a28 0xa00d2a28-0xa00d2a98 (112 bytes)
a00d2a28:  9d e3 bf 98  save  %sp, -104, %sp
a00d2a2c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d2a30:  92 12 62 90  or  %o1, 0x290, %o1	! 0xa802d290
a00d2a34:  d6 02 61 ec  ld  [ %o1 + 0x1ec ], %o3
a00d2a38:  95 32 e0 07  srl  %o3, 7, %o2
a00d2a3c:  94 0a a0 01  and  %o2, 1, %o2
a00d2a40:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a00d2a44:  d4 28 60 56  stb  %o2, [ %g1 + 0x56 ]	! 0xa8025c56
a00d2a48:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a00d2a4c:  80 a0 00 08  cmp  %g0, %o0
a00d2a50:  b0 40 20 00  addx  %g0, 0, %i0
a00d2a54:  9f 2e 20 07  sll  %i0, 7, %o7
a00d2a58:  9a 0a ff 7f  and  %o3, -129, %o5
a00d2a5c:  96 13 40 0f  or  %o5, %o7, %o3
a00d2a60:  99 32 e0 07  srl  %o3, 7, %o4
a00d2a64:  82 0b 20 01  and  %o4, 1, %g1
a00d2a68:  90 10 20 00  clr  %o0
a00d2a6c:  80 a2 80 01  cmp  %o2, %g1
a00d2a70:  02 80 00 08  be  0xa00d2a90
a00d2a74:  d6 22 61 ec  st  %o3, [ %o1 + 0x1ec ]
a00d2a78:  40 00 21 ad  call  0xa00db12c
a00d2a7c:  01 00 00 00  nop
a00d2a80:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00d2a84:  de 0b 20 8e  ldub  [ %o4 + 0x8e ], %o7	! 0xa802b08e
a00d2a88:  9a 13 e0 02  or  %o7, 2, %o5
a00d2a8c:  da 2b 20 8e  stb  %o5, [ %o4 + 0x8e ]
a00d2a90:  81 c7 e0 08  ret
a00d2a94:  91 e8 20 e0  restore  %g0, 0xe0, %o0
