# leon2s FUN_a0091b74 0xa0091b74-0xa0091bac (56 bytes)
a0091b74:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091b78:  9b 2a 20 03  sll  %o0, 3, %o5
a0091b7c:  9a 23 40 08  sub  %o5, %o0, %o5
a0091b80:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0091b84:  9b 2b 60 02  sll  %o5, 2, %o5
a0091b88:  82 10 61 80  or  %g1, 0x180, %g1
a0091b8c:  80 a2 20 01  cmp  %o0, 1
a0091b90:  18 80 00 05  bgu  0xa0091ba4
a0091b94:  9a 03 40 01  add  %o5, %g1, %o5
a0091b98:  c2 03 60 10  ld  [ %o5 + 0x10 ], %g1
a0091b9c:  82 08 7f fd  and  %g1, -3, %g1
a0091ba0:  c2 23 60 10  st  %g1, [ %o5 + 0x10 ]
a0091ba4:  81 c3 e0 08  retl
a0091ba8:  01 00 00 00  nop
