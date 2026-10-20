# leon2m FUN_a00d8c1c 0xa00d8c1c-0xa00d8cd4 (184 bytes)
a00d8c1c:  9d e3 bf 98  save  %sp, -104, %sp
a00d8c20:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00d8c24:  a2 14 a2 90  or  %l2, 0x290, %l1	! 0xa802d290
a00d8c28:  c2 04 60 b0  ld  [ %l1 + 0xb0 ], %g1
a00d8c2c:  92 10 20 01  mov  1, %o1
a00d8c30:  90 10 20 00  clr  %o0
a00d8c34:  80 a0 60 00  cmp  %g1, 0
a00d8c38:  12 80 00 17  bne  0xa00d8c94
a00d8c3c:  e0 0c 60 19  ldub  [ %l1 + 0x19 ], %l0
a00d8c40:  82 0c 20 ff  and  %l0, 0xff, %g1
a00d8c44:  80 a0 60 03  cmp  %g1, 3
a00d8c48:  18 80 00 0c  bgu  0xa00d8c78
a00d8c4c:  9a 10 00 11  mov  %l1, %o5
a00d8c50:  80 a0 60 00  cmp  %g1, 0
a00d8c54:  02 80 00 0e  be  0xa00d8c8c
a00d8c58:  e0 2b 60 8f  stb  %l0, [ %o5 + 0x8f ]
a00d8c5c:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00d8c60:  40 01 c1 37  call  0xa014913c
a00d8c64:  90 10 20 05  mov  5, %o0
a00d8c68:  9e 14 a2 90  or  %l2, 0x290, %o7
a00d8c6c:  e0 0b e0 8f  ldub  [ %o7 + 0x8f ], %l0
a00d8c70:  10 80 00 17  b  0xa00d8ccc
a00d8c74:  e0 2b e0 19  stb  %l0, [ %o7 + 0x19 ]
a00d8c78:  a0 10 20 03  mov  3, %l0
a00d8c7c:  82 10 20 03  mov  3, %g1
a00d8c80:  80 a0 60 00  cmp  %g1, 0
a00d8c84:  12 bf ff f6  bne  0xa00d8c5c
a00d8c88:  e0 2b 60 8f  stb  %l0, [ %o5 + 0x8f ]
a00d8c8c:  10 bf ff f5  b  0xa00d8c60
a00d8c90:  e0 2c 60 19  stb  %l0, [ %l1 + 0x19 ]
a00d8c94:  40 01 b2 73  call  0xa0145660
a00d8c98:  01 00 00 00  nop
a00d8c9c:  9b 2a 20 10  sll  %o0, 0x10, %o5
a00d8ca0:  19 33 33 33  sethi  %hi(0xcccccc00), %o4
a00d8ca4:  95 33 60 10  srl  %o5, 0x10, %o2
a00d8ca8:  96 13 20 cd  or  %o4, 0xcd, %o3
a00d8cac:  80 52 80 0b  umul  %o2, %o3, %g0
a00d8cb0:  93 40 00 00  rd  %y, %o1
a00d8cb4:  91 2a 60 0d  sll  %o1, 0xd, %o0
a00d8cb8:  7f fe b9 e8  call  0xa0087458
a00d8cbc:  91 32 20 10  srl  %o0, 0x10, %o0
a00d8cc0:  80 a2 20 00  cmp  %o0, 0
a00d8cc4:  02 bf ff e0  be  0xa00d8c44
a00d8cc8:  82 0c 20 ff  and  %l0, 0xff, %g1
a00d8ccc:  81 c7 e0 08  ret
a00d8cd0:  81 e8 00 00  restore
