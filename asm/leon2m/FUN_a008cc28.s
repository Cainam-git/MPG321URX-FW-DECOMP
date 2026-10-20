# leon2m FUN_a008cc28 0xa008cc28-0xa008ccc0 (152 bytes)
a008cc28:  9d e3 bf 90  save  %sp, -112, %sp
a008cc2c:  95 2e a0 10  sll  %i2, 0x10, %o2
a008cc30:  b4 07 bf f0  add  %fp, -16, %i2
a008cc34:  13 00 04 01  sethi  %hi(0x100400), %o1
a008cc38:  92 12 61 08  or  %o1, 0x108, %o1	! 0x100508
a008cc3c:  95 32 a0 10  srl  %o2, 0x10, %o2
a008cc40:  40 03 2a ed  call  0xa01577f4
a008cc44:  90 10 00 1a  mov  %i2, %o0
a008cc48:  98 10 20 00  clr  %o4
a008cc4c:  82 10 20 00  clr  %g1
a008cc50:  10 80 00 08  b  0xa008cc70
a008cc54:  96 07 bf f8  add  %fp, -8, %o3
a008cc58:  c2 2b 7f f8  stb  %g1, [ %o5 + -8 ]
a008cc5c:  98 03 20 01  inc  %o4
a008cc60:  82 0b 20 ff  and  %o4, 0xff, %g1
a008cc64:  80 a0 60 01  cmp  %g1, 1
a008cc68:  18 80 00 0d  bgu  0xa008cc9c
a008cc6c:  92 0e 20 ff  and  %i0, 0xff, %o1
a008cc70:  9a 02 c0 01  add  %o3, %g1, %o5
a008cc74:  c2 0b 7f f8  ldub  [ %o5 + -8 ], %g1
a008cc78:  80 a0 60 20  cmp  %g1, 0x20
a008cc7c:  12 bf ff f7  bne  0xa008cc58
a008cc80:  82 00 7f d1  add  %g1, -47, %g1
a008cc84:  98 03 20 01  inc  %o4
a008cc88:  82 0b 20 ff  and  %o4, 0xff, %g1
a008cc8c:  80 a0 60 01  cmp  %g1, 1
a008cc90:  08 bf ff f8  bleu  0xa008cc70
a008cc94:  c0 2b 7f f8  clrb  [ %o5 + -8 ]
a008cc98:  92 0e 20 ff  and  %i0, 0xff, %o1
a008cc9c:  94 0e 60 ff  and  %i1, 0xff, %o2
a008cca0:  98 10 00 1a  mov  %i2, %o4
a008cca4:  90 10 20 00  clr  %o0
a008cca8:  96 10 20 02  mov  2, %o3
a008ccac:  40 02 e7 92  call  0xa0146af4
a008ccb0:  9a 10 20 00  clr  %o5
a008ccb4:  01 00 00 00  nop
a008ccb8:  81 c7 e0 08  ret
a008ccbc:  81 e8 00 00  restore
