# leon2m FUN_a0124d24 0xa0124d24-0xa0124da4 (128 bytes)
a0124d24:  9d e3 bf 98  save  %sp, -104, %sp
a0124d28:  90 06 20 04  add  %i0, 4, %o0
a0124d2c:  82 0a 20 ff  and  %o0, 0xff, %g1
a0124d30:  80 a0 60 02  cmp  %g1, 2
a0124d34:  98 10 20 00  clr  %o4
a0124d38:  18 80 00 04  bgu  0xa0124d48
a0124d3c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0124d40:  10 80 00 16  b  0xa0124d98
a0124d44:  98 10 20 01  mov  1, %o4
a0124d48:  80 a6 20 ff  cmp  %i0, 0xff
a0124d4c:  02 80 00 13  be  0xa0124d98
a0124d50:  15 00 06 90  sethi  %hi(0x1a4000), %o2
a0124d54:  9a 5e 20 16  smul  %i0, 0x16, %o5
a0124d58:  92 12 a2 a8  or  %o2, 0x2a8, %o1
a0124d5c:  80 a6 20 07  cmp  %i0, 7
a0124d60:  18 80 00 0e  bgu  0xa0124d98
a0124d64:  a0 03 40 09  add  %o5, %o1, %l0
a0124d68:  d6 0c 20 0b  ldub  [ %l0 + 0xb ], %o3
a0124d6c:  80 a2 e0 ff  cmp  %o3, 0xff
a0124d70:  02 80 00 09  be  0xa0124d94
a0124d74:  90 10 00 0b  mov  %o3, %o0
a0124d78:  67 fd 9f f0  call  0x4008cd38
a0124d7c:  d2 0c 20 0c  ldub  [ %l0 + 0xc ], %o1
a0124d80:  d8 0c 20 0d  ldub  [ %l0 + 0xd ], %o4
a0124d84:  9e 0a 20 ff  and  %o0, 0xff, %o7
a0124d88:  80 a3 c0 0c  cmp  %o7, %o4
a0124d8c:  02 80 00 03  be  0xa0124d98
a0124d90:  98 10 20 01  mov  1, %o4
a0124d94:  98 10 20 00  clr  %o4
a0124d98:  b0 0b 20 01  and  %o4, 1, %i0
a0124d9c:  81 c7 e0 08  ret
a0124da0:  81 e8 00 00  restore
