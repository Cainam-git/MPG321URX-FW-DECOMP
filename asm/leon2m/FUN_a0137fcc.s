# leon2m FUN_a0137fcc 0xa0137fcc-0xa013805c (144 bytes)
a0137fcc:  9d e3 bf 90  save  %sp, -112, %sp
a0137fd0:  c0 27 bf f0  clr  [ %fp + -16 ]
a0137fd4:  92 10 20 04  mov  4, %o1
a0137fd8:  94 07 bf f0  add  %fp, -16, %o2
a0137fdc:  96 10 20 00  clr  %o3
a0137fe0:  f0 2f bf f0  stb  %i0, [ %fp + -16 ]
a0137fe4:  7f ff fc 3e  call  0xa01370dc
a0137fe8:  90 10 20 45  mov  0x45, %o0
a0137fec:  7f ff fc d6  call  0xa0137344
a0137ff0:  90 10 20 01  mov  1, %o0
a0137ff4:  1f 2a 00 b2  sethi  %hi(0xa802c800), %o7
a0137ff8:  94 13 e3 9c  or  %o7, 0x39c, %o2	! 0xa802cb9c
a0137ffc:  da 02 a0 04  ld  [ %o2 + 4 ], %o5
a0138000:  d8 02 a0 08  ld  [ %o2 + 8 ], %o4
a0138004:  93 33 60 08  srl  %o5, 8, %o1
a0138008:  91 33 60 10  srl  %o5, 0x10, %o0
a013800c:  b1 33 20 08  srl  %o4, 8, %i0
a0138010:  96 0a 60 ff  and  %o1, 0xff, %o3
a0138014:  94 0a 20 ff  and  %o0, 0xff, %o2
a0138018:  83 33 20 10  srl  %o4, 0x10, %g1
a013801c:  9f 33 60 18  srl  %o5, 0x18, %o7
a0138020:  92 0e 20 ff  and  %i0, 0xff, %o1
a0138024:  91 33 20 18  srl  %o4, 0x18, %o0
a0138028:  b0 08 60 ff  and  %g1, 0xff, %i0
a013802c:  9a 0b 60 ff  and  %o5, 0xff, %o5
a0138030:  98 0b 20 ff  and  %o4, 0xff, %o4
a0138034:  9a 03 40 0b  add  %o5, %o3, %o5
a0138038:  94 02 80 0f  add  %o2, %o7, %o2
a013803c:  98 03 00 09  add  %o4, %o1, %o4
a0138040:  82 06 00 08  add  %i0, %o0, %g1
a0138044:  c2 36 60 06  sth  %g1, [ %i1 + 6 ]
a0138048:  da 36 40 00  sth  %o5, [ %i1 ]
a013804c:  d4 36 60 02  sth  %o2, [ %i1 + 2 ]
a0138050:  d8 36 60 04  sth  %o4, [ %i1 + 4 ]
a0138054:  81 c7 e0 08  ret
a0138058:  81 e8 00 00  restore
