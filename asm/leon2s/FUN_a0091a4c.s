# leon2s FUN_a0091a4c 0xa0091a4c-0xa0091a88 (60 bytes)
a0091a4c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091a50:  9b 2a 20 03  sll  %o0, 3, %o5
a0091a54:  9a 23 40 08  sub  %o5, %o0, %o5
a0091a58:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0091a5c:  9b 2b 60 02  sll  %o5, 2, %o5
a0091a60:  82 10 61 80  or  %g1, 0x180, %g1
a0091a64:  80 a2 20 01  cmp  %o0, 1
a0091a68:  18 80 00 06  bgu  0xa0091a80
a0091a6c:  98 03 40 01  add  %o5, %g1, %o4
a0091a70:  c2 03 20 14  ld  [ %o4 + 0x14 ], %g1
a0091a74:  1b 00 00 10  sethi  %hi(0x4000), %o5
a0091a78:  82 10 40 0d  or  %g1, %o5, %g1
a0091a7c:  c2 23 20 14  st  %g1, [ %o4 + 0x14 ]
a0091a80:  81 c3 e0 08  retl
a0091a84:  01 00 00 00  nop
