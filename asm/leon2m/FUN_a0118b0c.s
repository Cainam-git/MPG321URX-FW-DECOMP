# leon2m FUN_a0118b0c 0xa0118b0c-0xa0118b9c (144 bytes)
a0118b0c:  9d e3 bf 98  save  %sp, -104, %sp
a0118b10:  21 33 c0 4b  sethi  %hi(0xcf012c00), %l0
a0118b14:  a2 14 23 f0  or  %l0, 0x3f0, %l1	! 0xcf012ff0
a0118b18:  d6 04 40 00  ld  [ %l1 ], %o3
a0118b1c:  94 0a ff 7f  and  %o3, -129, %o2
a0118b20:  d4 24 40 00  st  %o2, [ %l1 ]
a0118b24:  90 14 22 80  or  %l0, 0x280, %o0
a0118b28:  92 10 20 06  mov  6, %o1
a0118b2c:  d2 22 00 00  st  %o1, [ %o0 ]
a0118b30:  96 10 00 18  mov  %i0, %o3
a0118b34:  90 10 20 f4  mov  0xf4, %o0
a0118b38:  92 10 20 00  clr  %o1
a0118b3c:  7f ff 69 13  call  0xa00f2f88
a0118b40:  94 10 24 00  mov  0x400, %o2
a0118b44:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a0118b48:  da 00 62 a4  ld  [ %g1 + 0x2a4 ], %o5	! 0xa802d6a4
a0118b4c:  c2 13 60 0a  lduh  [ %o5 + 0xa ], %g1
a0118b50:  96 14 23 f4  or  %l0, 0x3f4, %o3
a0118b54:  80 a0 68 6f  cmp  %g1, 0x86f
a0118b58:  08 80 00 08  bleu  0xa0118b78
a0118b5c:  98 14 23 f8  or  %l0, 0x3f8, %o4
a0118b60:  a0 10 20 0b  mov  0xb, %l0
a0118b64:  e0 24 40 00  st  %l0, [ %l1 ]
a0118b68:  c0 22 c0 00  clr  [ %o3 ]
a0118b6c:  9e 10 20 01  mov  1, %o7
a0118b70:  de 23 00 00  st  %o7, [ %o4 ]
a0118b74:  30 80 00 08  b,a   0xa0118b94
a0118b78:  80 a0 64 37  cmp  %g1, 0x437
a0118b7c:  08 80 00 06  bleu  0xa0118b94
a0118b80:  b0 10 20 0a  mov  0xa, %i0
a0118b84:  f0 24 40 00  st  %i0, [ %l1 ]
a0118b88:  a2 10 20 40  mov  0x40, %l1
a0118b8c:  e2 22 c0 00  st  %l1, [ %o3 ]
a0118b90:  c0 23 00 00  clr  [ %o4 ]
a0118b94:  81 c7 e0 08  ret
a0118b98:  81 e8 00 00  restore
