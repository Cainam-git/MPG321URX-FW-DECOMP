# leon2m FUN_a0111028 0xa0111028-0xa0111088 (96 bytes)
a0111028:  9d e3 bf 98  save  %sp, -104, %sp
a011102c:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a0111030:  b4 17 21 fc  or  %i4, 0x1fc, %i2	! 0xcf0115fc
a0111034:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0111038:  82 10 20 c0  mov  0xc0, %g1
a011103c:  fa 06 80 00  ld  [ %i2 ], %i5
a0111040:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a0111044:  81 83 60 00  mov  %o5, %y
a0111048:  01 00 00 00  nop
a011104c:  01 00 00 00  nop
a0111050:  01 00 00 00  nop
a0111054:  b6 78 40 18  sdiv  %g1, %i0, %i3
a0111058:  b0 17 60 80  or  %i5, 0x80, %i0
a011105c:  82 06 ff fe  add  %i3, -2, %g1
a0111060:  f0 26 80 00  st  %i0, [ %i2 ]
a0111064:  b6 08 60 ff  and  %g1, 0xff, %i3
a0111068:  ba 17 21 f0  or  %i4, 0x1f0, %i5
a011106c:  b1 28 60 10  sll  %g1, 0x10, %i0
a0111070:  f6 27 40 00  st  %i3, [ %i5 ]
a0111074:  b8 17 21 f4  or  %i4, 0x1f4, %i4
a0111078:  83 36 20 18  srl  %i0, 0x18, %g1
a011107c:  c2 27 00 00  st  %g1, [ %i4 ]
a0111080:  81 c7 e0 08  ret
a0111084:  81 e8 00 00  restore
