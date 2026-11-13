# leon2m FUN_a01061c0 0xa01061c0-0xa0106228 (44 bytes)
a01061c0:  82 0a 20 ff  and  %o0, 0xff, %g1
a01061c4:  80 a0 60 04  cmp  %g1, 4
a01061c8:  18 80 00 16  bgu  0xa0106220
a01061cc:  11 00 02 87  sethi  %hi(0xa1c00), %o0
a01061d0:  83 28 60 02  sll  %g1, 2, %g1
a01061d4:  9a 12 21 80  or  %o0, 0x180, %o5
a01061d8:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a01061dc:  81 c3 00 00  jmp  %o4
a01061e0:  01 00 00 00  nop
a01061e4:  9a 10 20 10  mov  0x10, %o5	! 0x10
a01061e8:  19 33 c0 3b  sethi  %hi(0xcf00ec00), %o4
a01061ec:  90 13 21 80  or  %o4, 0x180, %o0	! 0xcf00ed80
a01061f0:  da 22 00 00  st  %o5, [ %o0 ]
a01061f4:  30 80 00 0b  b,a   0xa0106220
a01061f8:  03 33 c0 3b  sethi  %hi(0xcf00ec00), %g1
a01061fc:  98 10 61 80  or  %g1, 0x180, %o4	! 0xcf00ed80
a0106200:  c0 23 00 00  clr  [ %o4 ]
a0106204:  30 80 00 07  b,a   0xa0106220
a0106208:  10 bf ff f8  b  0xa01061e8
a010620c:  9a 10 20 01  mov  1, %o5
a0106210:  10 bf ff f6  b  0xa01061e8
a0106214:  9a 10 20 02  mov  2, %o5
a0106218:  10 bf ff f4  b  0xa01061e8
a010621c:  9a 10 20 04  mov  4, %o5
a0106220:  81 c3 e0 08  retl
a0106224:  01 00 00 00  nop
