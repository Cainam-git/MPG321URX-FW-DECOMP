# leon2m FUN_a00f2f88 0xa00f2f88-0xa00f3078 (240 bytes)
a00f2f88:  9d e3 bf 98  save  %sp, -104, %sp
a00f2f8c:  9e 10 00 1b  mov  %i3, %o7
a00f2f90:  b8 10 20 00  clr  %i4
a00f2f94:  01 00 00 00  nop
a00f2f98:  b8 07 20 01  inc  %i4
a00f2f9c:  82 0f 20 ff  and  %i4, 0xff, %g1
a00f2fa0:  80 a0 60 1f  cmp  %g1, 0x1f
a00f2fa4:  08 bf ff fc  bleu  0xa00f2f94
a00f2fa8:  ba 0e 20 ff  and  %i0, 0xff, %i5
a00f2fac:  37 33 c0 45  sethi  %hi(0xcf011400), %i3
a00f2fb0:  b0 16 e3 80  or  %i3, 0x380, %i0	! 0xcf011780
a00f2fb4:  fa 26 00 00  st  %i5, [ %i0 ]
a00f2fb8:  ba 10 20 00  clr  %i5
a00f2fbc:  01 00 00 00  nop
a00f2fc0:  ba 07 60 01  inc  %i5
a00f2fc4:  b8 0f 60 ff  and  %i5, 0xff, %i4
a00f2fc8:  80 a7 20 1f  cmp  %i4, 0x1f
a00f2fcc:  08 bf ff fc  bleu  0xa00f2fbc
a00f2fd0:  82 0e 60 ff  and  %i1, 0xff, %g1
a00f2fd4:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a00f2fd8:  b0 17 63 84  or  %i5, 0x384, %i0	! 0xcf011784
a00f2fdc:  c2 26 00 00  st  %g1, [ %i0 ]
a00f2fe0:  b9 2e 60 10  sll  %i1, 0x10, %i4
a00f2fe4:  b0 17 63 88  or  %i5, 0x388, %i0
a00f2fe8:  b7 37 20 18  srl  %i4, 0x18, %i3
a00f2fec:  03 33 c0 2f  sethi  %hi(0xcf00bc00), %g1
a00f2ff0:  f6 26 00 00  st  %i3, [ %i0 ]
a00f2ff4:  b2 10 63 cc  or  %g1, 0x3cc, %i1
a00f2ff8:  c0 26 40 00  clr  [ %i1 ]
a00f2ffc:  ba 10 20 00  clr  %i5
a00f3000:  01 00 00 00  nop
a00f3004:  ba 07 60 01  inc  %i5
a00f3008:  b2 0f 60 ff  and  %i5, 0xff, %i1
a00f300c:  80 a6 60 1f  cmp  %i1, 0x1f
a00f3010:  08 bf ff fc  bleu  0xa00f3000
a00f3014:  01 00 00 00  nop
a00f3018:  b5 2e a0 10  sll  %i2, 0x10, %i2
a00f301c:  80 a6 a0 00  cmp  %i2, 0
a00f3020:  02 80 00 14  be  0xa00f3070
a00f3024:  b8 10 20 00  clr  %i4
a00f3028:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a00f302c:  b6 17 63 90  or  %i5, 0x390, %i3	! 0xcf011790
a00f3030:  b3 2f 20 10  sll  %i4, 0x10, %i1
a00f3034:  83 36 60 10  srl  %i1, 0x10, %g1
a00f3038:  f0 08 40 0f  ldub  [ %g1 + %o7 ], %i0
a00f303c:  f0 26 c0 00  st  %i0, [ %i3 ]
a00f3040:  ba 10 20 00  clr  %i5
a00f3044:  01 00 00 00  nop
a00f3048:  ba 07 60 01  inc  %i5
a00f304c:  b0 0f 60 ff  and  %i5, 0xff, %i0
a00f3050:  80 a6 20 1f  cmp  %i0, 0x1f
a00f3054:  08 bf ff fc  bleu  0xa00f3044
a00f3058:  01 00 00 00  nop
a00f305c:  ba 07 20 01  add  %i4, 1, %i5
a00f3060:  b9 2f 60 10  sll  %i5, 0x10, %i4
a00f3064:  80 a6 80 1c  cmp  %i2, %i4
a00f3068:  18 bf ff f2  bgu  0xa00f3030
a00f306c:  b8 10 00 1d  mov  %i5, %i4
a00f3070:  81 c7 e0 08  ret
a00f3074:  81 e8 00 00  restore
