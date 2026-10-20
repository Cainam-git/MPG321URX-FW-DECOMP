# leon2s FUN_a0091b3c 0xa0091b3c-0xa0091b74 (56 bytes)
a0091b3c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091b40:  9b 2a 20 03  sll  %o0, 3, %o5
a0091b44:  9a 23 40 08  sub  %o5, %o0, %o5
a0091b48:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0091b4c:  9b 2b 60 02  sll  %o5, 2, %o5
a0091b50:  82 10 61 80  or  %g1, 0x180, %g1
a0091b54:  80 a2 20 01  cmp  %o0, 1
a0091b58:  18 80 00 05  bgu  0xa0091b6c
a0091b5c:  9a 03 40 01  add  %o5, %g1, %o5
a0091b60:  c2 03 60 10  ld  [ %o5 + 0x10 ], %g1
a0091b64:  82 10 60 02  or  %g1, 2, %g1
a0091b68:  c2 23 60 10  st  %g1, [ %o5 + 0x10 ]
a0091b6c:  81 c3 e0 08  retl
a0091b70:  01 00 00 00  nop
