# leon2m FUN_a008cdf0 0xa008cdf0-0xa008ce90 (160 bytes)
a008cdf0:  9d e3 bf 90  save  %sp, -112, %sp
a008cdf4:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a008cdf8:  d0 00 61 a8  ld  [ %g1 + 0x1a8 ], %o0	! 0xa802e1a8
a008cdfc:  95 2a 20 08  sll  %o0, 8, %o2
a008ce00:  a0 07 bf f0  add  %fp, -16, %l0
a008ce04:  13 00 04 01  sethi  %hi(0x100400), %o1
a008ce08:  92 12 61 10  or  %o1, 0x110, %o1	! 0x100510
a008ce0c:  95 32 a0 10  srl  %o2, 0x10, %o2
a008ce10:  40 03 2a 79  call  0xa01577f4
a008ce14:  90 10 00 10  mov  %l0, %o0
a008ce18:  98 10 20 00  clr  %o4
a008ce1c:  82 10 20 00  clr  %g1
a008ce20:  10 80 00 08  b  0xa008ce40
a008ce24:  96 07 bf f8  add  %fp, -8, %o3
a008ce28:  c2 2b 7f f8  stb  %g1, [ %o5 + -8 ]
a008ce2c:  98 03 20 01  inc  %o4
a008ce30:  82 0b 20 ff  and  %o4, 0xff, %g1
a008ce34:  80 a0 60 04  cmp  %g1, 4
a008ce38:  18 80 00 0d  bgu  0xa008ce6c
a008ce3c:  92 0e 20 ff  and  %i0, 0xff, %o1
a008ce40:  9a 02 c0 01  add  %o3, %g1, %o5
a008ce44:  de 0b 7f f8  ldub  [ %o5 + -8 ], %o7
a008ce48:  80 a3 e0 20  cmp  %o7, 0x20
a008ce4c:  12 bf ff f7  bne  0xa008ce28
a008ce50:  82 03 ff d1  add  %o7, -47, %g1
a008ce54:  98 03 20 01  inc  %o4
a008ce58:  82 0b 20 ff  and  %o4, 0xff, %g1
a008ce5c:  80 a0 60 04  cmp  %g1, 4
a008ce60:  08 bf ff f8  bleu  0xa008ce40
a008ce64:  c0 2b 7f f8  clrb  [ %o5 + -8 ]
a008ce68:  92 0e 20 ff  and  %i0, 0xff, %o1
a008ce6c:  94 0e 60 ff  and  %i1, 0xff, %o2
a008ce70:  98 10 00 10  mov  %l0, %o4
a008ce74:  90 10 20 00  clr  %o0
a008ce78:  96 10 20 05  mov  5, %o3
a008ce7c:  40 02 e7 1e  call  0xa0146af4
a008ce80:  9a 10 20 00  clr  %o5
a008ce84:  01 00 00 00  nop
a008ce88:  81 c7 e0 08  ret
a008ce8c:  81 e8 00 00  restore
