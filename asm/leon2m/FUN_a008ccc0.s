# leon2m FUN_a008ccc0 0xa008ccc0-0xa008cd58 (152 bytes)
a008ccc0:  9d e3 bf 90  save  %sp, -112, %sp
a008ccc4:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a008ccc8:  a0 07 bf f0  add  %fp, -16, %l0
a008cccc:  13 00 04 01  sethi  %hi(0x100400), %o1
a008ccd0:  d4 08 61 a8  ldub  [ %g1 + 0x1a8 ], %o2
a008ccd4:  92 12 61 08  or  %o1, 0x108, %o1
a008ccd8:  40 03 2a c7  call  0xa01577f4
a008ccdc:  90 10 00 10  mov  %l0, %o0
a008cce0:  98 10 20 00  clr  %o4
a008cce4:  82 10 20 00  clr  %g1
a008cce8:  10 80 00 08  b  0xa008cd08
a008ccec:  96 07 bf f8  add  %fp, -8, %o3
a008ccf0:  c2 2b 7f f8  stb  %g1, [ %o5 + -8 ]
a008ccf4:  98 03 20 01  inc  %o4
a008ccf8:  82 0b 20 ff  and  %o4, 0xff, %g1
a008ccfc:  80 a0 60 01  cmp  %g1, 1
a008cd00:  18 80 00 0d  bgu  0xa008cd34
a008cd04:  92 0e 20 ff  and  %i0, 0xff, %o1
a008cd08:  9a 02 c0 01  add  %o3, %g1, %o5
a008cd0c:  d0 0b 7f f8  ldub  [ %o5 + -8 ], %o0
a008cd10:  80 a2 20 20  cmp  %o0, 0x20
a008cd14:  12 bf ff f7  bne  0xa008ccf0
a008cd18:  82 02 3f d1  add  %o0, -47, %g1
a008cd1c:  98 03 20 01  inc  %o4
a008cd20:  82 0b 20 ff  and  %o4, 0xff, %g1
a008cd24:  80 a0 60 01  cmp  %g1, 1
a008cd28:  08 bf ff f8  bleu  0xa008cd08
a008cd2c:  c0 2b 7f f8  clrb  [ %o5 + -8 ]
a008cd30:  92 0e 20 ff  and  %i0, 0xff, %o1
a008cd34:  94 0e 60 ff  and  %i1, 0xff, %o2
a008cd38:  98 10 00 10  mov  %l0, %o4
a008cd3c:  90 10 20 00  clr  %o0
a008cd40:  96 10 20 02  mov  2, %o3
a008cd44:  40 02 e7 6c  call  0xa0146af4
a008cd48:  9a 10 20 00  clr  %o5
a008cd4c:  01 00 00 00  nop
a008cd50:  81 c7 e0 08  ret
a008cd54:  81 e8 00 00  restore
