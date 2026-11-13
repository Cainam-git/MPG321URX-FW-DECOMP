# leon2s FUN_a0061eb4 0xa0061eb4-0xa0061f5c (168 bytes)
a0061eb4:  9d e3 bf 98  save  %sp, -104, %sp
a0061eb8:  83 2e 60 10  sll  %i1, 0x10, %g1
a0061ebc:  83 30 60 10  srl  %g1, 0x10, %g1
a0061ec0:  92 10 20 05  mov  5, %o1
a0061ec4:  90 0e 20 ff  and  %i0, 0xff, %o0
a0061ec8:  80 a0 60 05  cmp  %g1, 5
a0061ecc:  12 80 00 05  bne  0xa0061ee0
a0061ed0:  a0 10 20 00  clr  %l0
a0061ed4:  40 01 14 29  call  0xa00a6f78
a0061ed8:  b0 0c 20 ff  and  %l0, 0xff, %i0
a0061edc:  30 80 00 1e  b,a   0xa0061f54
a0061ee0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0061ee4:  98 10 20 02  mov  2, %o4
a0061ee8:  90 10 20 01  mov  1, %o0
a0061eec:  92 10 00 18  mov  %i0, %o1
a0061ef0:  94 10 21 b7  mov  0x1b7, %o2
a0061ef4:  80 a0 61 b8  cmp  %g1, 0x1b8
a0061ef8:  12 80 00 16  bne  0xa0061f50
a0061efc:  96 10 20 07  mov  7, %o3
a0061f00:  40 01 11 50  call  0xa00a6440
a0061f04:  01 00 00 00  nop
a0061f08:  96 10 20 01  mov  1, %o3	! 0x1
a0061f0c:  90 10 00 18  mov  %i0, %o0
a0061f10:  92 10 21 b7  mov  0x1b7, %o1
a0061f14:  40 01 13 61  call  0xa00a6c98
a0061f18:  94 10 20 40  mov  0x40, %o2
a0061f1c:  94 0e 60 ff  and  %i1, 0xff, %o2
a0061f20:  90 10 00 18  mov  %i0, %o0
a0061f24:  40 01 13 37  call  0xa00a6c00
a0061f28:  92 10 21 b8  mov  0x1b8, %o1
a0061f2c:  92 10 21 b9  mov  0x1b9, %o1
a0061f30:  40 01 13 22  call  0xa00a6bb8
a0061f34:  90 10 00 18  mov  %i0, %o0
a0061f38:  a0 10 00 08  mov  %o0, %l0
a0061f3c:  90 10 00 18  mov  %i0, %o0
a0061f40:  92 10 21 b7  mov  0x1b7, %o1
a0061f44:  94 10 20 40  mov  0x40, %o2
a0061f48:  40 01 13 54  call  0xa00a6c98
a0061f4c:  96 10 20 00  clr  %o3
a0061f50:  b0 0c 20 ff  and  %l0, 0xff, %i0
a0061f54:  81 c7 e0 08  ret
a0061f58:  81 e8 00 00  restore
