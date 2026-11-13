# leon2m FUN_a00def40 0xa00def40-0xa00deffc (188 bytes)
a00def40:  9d e3 bf 98  save  %sp, -104, %sp
a00def44:  c2 4e 00 00  ldsb  [ %i0 ], %g1
a00def48:  80 a0 60 00  cmp  %g1, 0
a00def4c:  02 80 00 2a  be  0xa00deff4
a00def50:  11 00 03 ff  sethi  %hi(0xffc00), %o0
a00def54:  aa 12 23 fe  or  %o0, 0x3fe, %l5	! 0xffffe
a00def58:  27 30 02 c0  sethi  %hi(0xc00b0000), %l3
a00def5c:  a8 10 00 15  mov  %l5, %l4
a00def60:  a0 10 20 00  clr  %l0
a00def64:  67 fe b4 bb  call  0x4008c250
a00def68:  90 14 e0 14  or  %l3, 0x14, %o0
a00def6c:  80 8a 20 20  btst  0x20, %o0
a00def70:  12 80 00 05  bne  0xa00def84
a00def74:  a0 04 20 01  inc  %l0
a00def78:  80 a4 00 14  cmp  %l0, %l4
a00def7c:  08 bf ff fa  bleu  0xa00def64
a00def80:  01 00 00 00  nop
a00def84:  d2 4e 00 00  ldsb  [ %i0 ], %o1
a00def88:  67 fe b4 b5  call  0x4008c25c
a00def8c:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a00def90:  d2 4e 00 00  ldsb  [ %i0 ], %o1
a00def94:  80 a2 60 0a  cmp  %o1, 0xa
a00def98:  a0 10 20 00  clr  %l0
a00def9c:  25 30 02 c0  sethi  %hi(0xc00b0000), %l2
a00defa0:  02 80 00 0b  be  0xa00defcc
a00defa4:  a2 10 00 15  mov  %l5, %l1
a00defa8:  b0 06 20 01  inc  %i0
a00defac:  d4 4e 00 00  ldsb  [ %i0 ], %o2
a00defb0:  80 a2 a0 00  cmp  %o2, 0
a00defb4:  32 bf ff ec  bne,a   0xa00def64
a00defb8:  a0 10 20 00  clr  %l0
a00defbc:  30 80 00 0e  b,a   0xa00deff4
a00defc0:  80 a4 00 11  cmp  %l0, %l1
a00defc4:  18 80 00 08  bgu  0xa00defe4
a00defc8:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a00defcc:  67 fe b4 a1  call  0x4008c250
a00defd0:  90 14 a0 14  or  %l2, 0x14, %o0
a00defd4:  80 8a 20 20  btst  0x20, %o0
a00defd8:  02 bf ff fa  be  0xa00defc0
a00defdc:  a0 04 20 01  inc  %l0
a00defe0:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a00defe4:  67 fe b4 9e  call  0x4008c25c
a00defe8:  92 10 20 0d  mov  0xd, %o1
a00defec:  10 bf ff f0  b  0xa00defac
a00deff0:  b0 06 20 01  inc  %i0
a00deff4:  81 c7 e0 08  ret
a00deff8:  81 e8 00 00  restore
