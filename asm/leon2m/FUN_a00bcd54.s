# leon2m FUN_a00bcd54 0xa00bcd54-0xa00bcd9c (72 bytes)
a00bcd54:  9d e3 bf 98  save  %sp, -104, %sp
a00bcd58:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bcd5c:  d0 0a a3 cf  ldub  [ %o2 + 0x3cf ], %o0	! 0xa802d3cf
a00bcd60:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bcd64:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bcd68:  98 02 20 30  add  %o0, 0x30, %o4
a00bcd6c:  82 10 20 30  mov  0x30, %g1
a00bcd70:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00bcd74:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00bcd78:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00bcd7c:  7f ff f7 b0  call  0xa00bac3c
a00bcd80:  90 10 20 1d  mov  0x1d, %o0
a00bcd84:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bcd88:  7f ff f6 f2  call  0xa00ba950
a00bcd8c:  90 10 00 18  mov  %i0, %o0
a00bcd90:  7f ff f7 95  call  0xa00babe4
a00bcd94:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bcd98:  01 00 00 00  nop
