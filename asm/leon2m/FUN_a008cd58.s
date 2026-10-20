# leon2m FUN_a008cd58 0xa008cd58-0xa008cdf0 (152 bytes)
a008cd58:  9d e3 bf 90  save  %sp, -112, %sp
a008cd5c:  95 2e a0 10  sll  %i2, 0x10, %o2
a008cd60:  b4 07 bf f0  add  %fp, -16, %i2
a008cd64:  13 00 04 01  sethi  %hi(0x100400), %o1
a008cd68:  92 12 61 10  or  %o1, 0x110, %o1	! 0x100510
a008cd6c:  95 32 a0 10  srl  %o2, 0x10, %o2
a008cd70:  40 03 2a a1  call  0xa01577f4
a008cd74:  90 10 00 1a  mov  %i2, %o0
a008cd78:  98 10 20 00  clr  %o4
a008cd7c:  82 10 20 00  clr  %g1
a008cd80:  10 80 00 08  b  0xa008cda0
a008cd84:  96 07 bf f8  add  %fp, -8, %o3
a008cd88:  c2 2b 7f f8  stb  %g1, [ %o5 + -8 ]
a008cd8c:  98 03 20 01  inc  %o4
a008cd90:  82 0b 20 ff  and  %o4, 0xff, %g1
a008cd94:  80 a0 60 04  cmp  %g1, 4
a008cd98:  18 80 00 0d  bgu  0xa008cdcc
a008cd9c:  92 0e 20 ff  and  %i0, 0xff, %o1
a008cda0:  9a 02 c0 01  add  %o3, %g1, %o5
a008cda4:  c2 0b 7f f8  ldub  [ %o5 + -8 ], %g1
a008cda8:  80 a0 60 20  cmp  %g1, 0x20
a008cdac:  12 bf ff f7  bne  0xa008cd88
a008cdb0:  82 00 7f d1  add  %g1, -47, %g1
a008cdb4:  98 03 20 01  inc  %o4
a008cdb8:  82 0b 20 ff  and  %o4, 0xff, %g1
a008cdbc:  80 a0 60 04  cmp  %g1, 4
a008cdc0:  08 bf ff f8  bleu  0xa008cda0
a008cdc4:  c0 2b 7f f8  clrb  [ %o5 + -8 ]
a008cdc8:  92 0e 20 ff  and  %i0, 0xff, %o1
a008cdcc:  94 0e 60 ff  and  %i1, 0xff, %o2
a008cdd0:  98 10 00 1a  mov  %i2, %o4
a008cdd4:  90 10 20 00  clr  %o0
a008cdd8:  96 10 20 05  mov  5, %o3
a008cddc:  40 02 e7 46  call  0xa0146af4
a008cde0:  9a 10 20 00  clr  %o5
a008cde4:  01 00 00 00  nop
a008cde8:  81 c7 e0 08  ret
a008cdec:  81 e8 00 00  restore
