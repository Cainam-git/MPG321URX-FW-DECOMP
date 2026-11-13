# leon2m FUN_a0156a0c 0xa0156a0c-0xa0156a6c (96 bytes)
a0156a0c:  9d e3 bf 78  save  %sp, -136, %sp
a0156a10:  90 07 bf d8  add  %fp, -40, %o0
a0156a14:  92 07 bf e0  add  %fp, -32, %o1
a0156a18:  40 00 02 4d  call  0xa015734c
a0156a1c:  f0 3f bf d8  std  %i0, [ %fp + -40 ]
a0156a20:  e0 1f bf f0  ldd  [ %fp + -16 ], %l0
a0156a24:  97 2c 20 02  sll  %l0, 2, %o3
a0156a28:  83 34 60 1e  srl  %l1, 0x1e, %g1
a0156a2c:  9a 12 c0 01  or  %o3, %g1, %o5
a0156a30:  17 0f ff ff  sethi  %hi(0x3ffffc00), %o3
a0156a34:  94 10 20 00  clr  %o2
a0156a38:  96 12 e3 ff  or  %o3, 0x3ff, %o3
a0156a3c:  a0 0c 00 0a  and  %l0, %o2, %l0
a0156a40:  a2 0c 40 0b  and  %l1, %o3, %l1
a0156a44:  d0 1f bf e0  ldd  [ %fp + -32 ], %o0
a0156a48:  d4 07 bf e8  ld  [ %fp + -24 ], %o2
a0156a4c:  80 94 00 11  orcc  %l0, %l1, %g0
a0156a50:  02 80 00 03  be  0xa0156a5c
a0156a54:  96 10 00 0d  mov  %o5, %o3
a0156a58:  96 13 60 01  or  %o5, 1, %o3
a0156a5c:  40 00 01 b5  call  0xa0157130
a0156a60:  01 00 00 00  nop
a0156a64:  81 c7 e0 08  ret
a0156a68:  91 e8 00 08  restore  %g0, %o0, %o0
