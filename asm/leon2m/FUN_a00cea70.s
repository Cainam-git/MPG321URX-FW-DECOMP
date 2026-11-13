# leon2m FUN_a00cea70 0xa00cea70-0xa00cead4 (100 bytes)
a00cea70:  9d e3 bf 98  save  %sp, -104, %sp
a00cea74:  03 00 00 04  sethi  %hi(0x1000), %g1
a00cea78:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cea7c:  9e 10 60 21  or  %g1, 0x21, %o7
a00cea80:  b4 10 20 80  mov  0x80, %i2
a00cea84:  b6 0e 00 1a  and  %i0, %i2, %i3
a00cea88:  80 a0 00 1b  cmp  %g0, %i3
a00cea8c:  83 2e 60 10  sll  %i1, 0x10, %g1
a00cea90:  b6 06 40 19  add  %i1, %i1, %i3
a00cea94:  b2 40 20 00  addx  %g0, 0, %i1
a00cea98:  b9 2e a0 10  sll  %i2, 0x10, %i4
a00cea9c:  bb 30 60 1f  srl  %g1, 0x1f, %i5
a00ceaa0:  80 a7 40 19  cmp  %i5, %i1
a00ceaa4:  b9 37 20 11  srl  %i4, 0x11, %i4
a00ceaa8:  b4 10 00 1c  mov  %i4, %i2
a00ceaac:  02 80 00 03  be  0xa00ceab8
a00ceab0:  b2 10 00 1b  mov  %i3, %i1
a00ceab4:  b2 1e c0 0f  xor  %i3, %o7, %i1
a00ceab8:  80 a7 20 00  cmp  %i4, 0
a00ceabc:  12 bf ff f3  bne  0xa00cea88
a00ceac0:  b6 0e 00 1a  and  %i0, %i2, %i3
a00ceac4:  b1 2e 60 10  sll  %i1, 0x10, %i0
a00ceac8:  b1 36 20 10  srl  %i0, 0x10, %i0
a00ceacc:  81 c7 e0 08  ret
a00cead0:  81 e8 00 00  restore
