# leon2s FUN_a006cb98 0xa006cb98-0xa006cc24 (140 bytes)
a006cb98:  96 0a e0 ff  and  %o3, 0xff, %o3
a006cb9c:  80 a0 00 0b  cmp  %g0, %o3
a006cba0:  83 2b 60 10  sll  %o5, 0x10, %g1
a006cba4:  95 2a a0 10  sll  %o2, 0x10, %o2
a006cba8:  96 60 3f ff  subx  %g0, -1, %o3
a006cbac:  83 30 60 10  srl  %g1, 0x10, %g1
a006cbb0:  95 32 a0 10  srl  %o2, 0x10, %o2
a006cbb4:  80 a0 40 0a  cmp  %g1, %o2
a006cbb8:  82 40 20 00  addx  %g0, 0, %g1
a006cbbc:  80 92 c0 01  orcc  %o3, %g1, %g0
a006cbc0:  c2 03 a0 5c  ld  [ %sp + 0x5c ], %g1
a006cbc4:  93 32 60 03  srl  %o1, 3, %o1
a006cbc8:  83 30 60 05  srl  %g1, 5, %g1
a006cbcc:  9b 2b 60 10  sll  %o5, 0x10, %o5
a006cbd0:  82 00 40 09  add  %g1, %o1, %g1
a006cbd4:  9b 33 60 10  srl  %o5, 0x10, %o5
a006cbd8:  93 2b 60 04  sll  %o5, 4, %o1
a006cbdc:  92 22 40 0d  sub  %o1, %o5, %o1
a006cbe0:  93 2a 60 02  sll  %o1, 2, %o1
a006cbe4:  92 00 40 09  add  %g1, %o1, %o1
a006cbe8:  12 80 00 03  bne  0xa006cbf4
a006cbec:  82 10 21 e0  mov  0x1e0, %g1
a006cbf0:  82 10 00 0c  mov  %o4, %g1
a006cbf4:  83 28 60 10  sll  %g1, 0x10, %g1
a006cbf8:  95 30 60 13  srl  %g1, 0x13, %o2
a006cbfc:  83 30 60 10  srl  %g1, 0x10, %g1
a006cc00:  80 a0 61 e0  cmp  %g1, 0x1e0
a006cc04:  18 80 00 05  bgu  0xa006cc18
a006cc08:  01 00 00 00  nop
a006cc0c:  82 13 c0 00  mov  %o7, %g1
a006cc10:  7f ff ff 6c  call  0xa006c9c0
a006cc14:  9e 10 40 00  mov  %g1, %o7
a006cc18:  01 00 00 00  nop
a006cc1c:  81 c3 e0 08  retl
a006cc20:  01 00 00 00  nop
