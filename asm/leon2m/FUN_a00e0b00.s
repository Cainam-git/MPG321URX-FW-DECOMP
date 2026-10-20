# leon2m FUN_a00e0b00 0xa00e0b00-0xa00e0ba8 (168 bytes)
a00e0b00:  9d e3 bf 88  save  %sp, -120, %sp
a00e0b04:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00e0b08:  9a 10 60 28  or  %g1, 0x28, %o5	! 0xa8026428
a00e0b0c:  b3 2e 60 02  sll  %i1, 2, %i1
a00e0b10:  d4 03 40 19  ld  [ %o5 + %i1 ], %o2
a00e0b14:  96 10 00 18  mov  %i0, %o3
a00e0b18:  90 0a a0 ff  and  %o2, 0xff, %o0
a00e0b1c:  13 2a 00 97  sethi  %hi(0xa8025c00), %o1
a00e0b20:  31 33 c0 8a  sethi  %hi(0xcf022800), %i0
a00e0b24:  23 33 c0 8b  sethi  %hi(0xcf022c00), %l1
a00e0b28:  a1 2a e0 02  sll  %o3, 2, %l0
a00e0b2c:  1f 33 c0 8c  sethi  %hi(0xcf023000), %o7
a00e0b30:  94 12 61 10  or  %o1, 0x110, %o2
a00e0b34:  f0 27 bf e8  st  %i0, [ %fp + -24 ]
a00e0b38:  e2 27 bf ec  st  %l1, [ %fp + -20 ]
a00e0b3c:  98 07 80 10  add  %fp, %l0, %o4
a00e0b40:  c2 0a 80 0b  ldub  [ %o2 + %o3 ], %g1
a00e0b44:  de 27 bf f0  st  %o7, [ %fp + -16 ]
a00e0b48:  9b 2a 20 02  sll  %o0, 2, %o5
a00e0b4c:  d8 03 3f e8  ld  [ %o4 + -24 ], %o4
a00e0b50:  80 a0 60 03  cmp  %g1, 3
a00e0b54:  a2 03 00 0d  add  %o4, %o5, %l1
a00e0b58:  b0 10 20 00  clr  %i0
a00e0b5c:  b2 10 20 00  clr  %i1
a00e0b60:  a0 10 20 00  clr  %l0
a00e0b64:  02 80 00 04  be  0xa00e0b74
a00e0b68:  82 10 20 03  mov  3, %g1
a00e0b6c:  c2 23 23 f8  st  %g1, [ %o4 + 0x3f8 ]
a00e0b70:  c2 2a 80 0b  stb  %g1, [ %o2 + %o3 ]
a00e0b74:  99 2c 20 02  sll  %l0, 2, %o4
a00e0b78:  d6 03 00 11  ld  [ %o4 + %l1 ], %o3
a00e0b7c:  95 2c 20 03  sll  %l0, 3, %o2
a00e0b80:  92 10 00 0b  mov  %o3, %o1
a00e0b84:  40 01 d1 60  call  0xa0155104
a00e0b88:  90 10 20 00  clr  %o0
a00e0b8c:  a0 04 20 01  inc  %l0
a00e0b90:  b0 16 00 08  or  %i0, %o0, %i0
a00e0b94:  80 a4 20 07  cmp  %l0, 7
a00e0b98:  08 bf ff f7  bleu  0xa00e0b74
a00e0b9c:  b2 16 40 09  or  %i1, %o1, %i1
a00e0ba0:  81 c7 e0 08  ret
a00e0ba4:  81 e8 00 00  restore
