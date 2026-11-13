# leon2m FUN_a00dec90 0xa00dec90-0xa00decf4 (100 bytes)
a00dec90:  9d e3 bf 98  save  %sp, -104, %sp
a00dec94:  67 fe b5 6f  call  0x4008c250
a00dec98:  11 30 02 80  sethi  %hi(0xc00a0000), %o0
a00dec9c:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00deca0:  c2 0b 60 c4  ldub  [ %o5 + 0xc4 ], %g1	! 0xa802b0c4
a00deca4:  80 a0 60 00  cmp  %g1, 0
a00deca8:  98 13 60 c4  or  %o5, 0xc4, %o4
a00decac:  02 80 00 10  be  0xa00decec
a00decb0:  82 10 20 00  clr  %g1
a00decb4:  d2 03 20 04  ld  [ %o4 + 4 ], %o1
a00decb8:  9a 22 40 18  sub  %o1, %i0, %o5
a00decbc:  80 a2 40 18  cmp  %o1, %i0
a00decc0:  08 80 00 09  bleu  0xa00dece4
a00decc4:  b0 10 00 0d  mov  %o5, %i0
a00decc8:  de 03 20 08  ld  [ %o4 + 8 ], %o7
a00deccc:  03 00 00 09  sethi  %hi(0x2400), %g1
a00decd0:  98 10 63 10  or  %g1, 0x310, %o4	! 0x2710
a00decd4:  94 5e 00 0c  smul  %i0, %o4, %o2
a00decd8:  96 22 00 0f  sub  %o0, %o7, %o3
a00decdc:  10 80 00 04  b  0xa00decec
a00dece0:  82 02 80 0b  add  %o2, %o3, %g1
a00dece4:  10 bf ff f9  b  0xa00decc8
a00dece8:  b0 03 7f ff  add  %o5, -1, %i0
a00decec:  81 c7 e0 08  ret
a00decf0:  91 e8 00 01  restore  %g0, %g1, %o0
