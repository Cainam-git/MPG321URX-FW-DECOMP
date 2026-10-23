# leon2m FUN_a00ded78 0xa00ded78-0xa00deda0 (40 bytes)
a00ded78:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00ded7c:  da 08 60 c4  ldub  [ %g1 + 0xc4 ], %o5	! 0xa802b0c4
a00ded80:  91 2a 20 02  sll  %o0, 2, %o0
a00ded84:  82 10 60 c4  or  %g1, 0xc4, %g1
a00ded88:  80 a3 60 00  cmp  %o5, 0
a00ded8c:  02 80 00 03  be  0xa00ded98
a00ded90:  90 02 00 01  add  %o0, %g1, %o0
a00ded94:  d2 22 20 0c  st  %o1, [ %o0 + 0xc ]
a00ded98:  81 c3 e0 08  retl
a00ded9c:  01 00 00 00  nop
