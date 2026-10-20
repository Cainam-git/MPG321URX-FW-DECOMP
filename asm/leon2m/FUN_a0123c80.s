# leon2m FUN_a0123c80 0xa0123c80-0xa0123cf0 (112 bytes)
a0123c80:  9d e3 bf 98  save  %sp, -104, %sp
a0123c84:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0123c88:  80 a6 60 00  cmp  %i1, 0
a0123c8c:  02 80 00 11  be  0xa0123cd0
a0123c90:  96 10 20 00  clr  %o3
a0123c94:  03 2a 00 b6  sethi  %hi(0xa802d800), %g1
a0123c98:  92 10 60 50  or  %g1, 0x50, %o1	! 0xa802d850
a0123c9c:  98 10 20 00  clr  %o4
a0123ca0:  94 06 7f ff  add  %i1, -1, %o2
a0123ca4:  da 0b 00 18  ldub  [ %o4 + %i0 ], %o5
a0123ca8:  d0 0a 40 0c  ldub  [ %o1 + %o4 ], %o0
a0123cac:  80 a3 40 08  cmp  %o5, %o0
a0123cb0:  12 80 00 08  bne  0xa0123cd0
a0123cb4:  96 02 e0 01  inc  %o3
a0123cb8:  80 a3 00 0a  cmp  %o4, %o2
a0123cbc:  02 80 00 07  be  0xa0123cd8
a0123cc0:  98 0a e0 ff  and  %o3, 0xff, %o4
a0123cc4:  80 a3 00 19  cmp  %o4, %i1
a0123cc8:  2a bf ff f8  bcs,a   0xa0123ca8
a0123ccc:  da 0b 00 18  ldub  [ %o4 + %i0 ], %o5
a0123cd0:  10 80 00 06  b  0xa0123ce8
a0123cd4:  b0 10 20 00  clr  %i0
a0123cd8:  13 00 06 8c  sethi  %hi(0x1a3000), %o1
a0123cdc:  7f fe ed 25  call  0xa00df170
a0123ce0:  90 12 60 a8  or  %o1, 0xa8, %o0	! 0x1a30a8
a0123ce4:  b0 10 20 01  mov  1, %i0
a0123ce8:  81 c7 e0 08  ret
a0123cec:  81 e8 00 00  restore
