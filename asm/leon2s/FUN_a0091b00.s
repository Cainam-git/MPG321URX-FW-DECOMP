# leon2s FUN_a0091b00 0xa0091b00-0xa0091b3c (60 bytes)
a0091b00:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091b04:  9b 2a 20 03  sll  %o0, 3, %o5
a0091b08:  9a 23 40 08  sub  %o5, %o0, %o5
a0091b0c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0091b10:  9b 2b 60 02  sll  %o5, 2, %o5
a0091b14:  82 10 61 80  or  %g1, 0x180, %g1
a0091b18:  80 a2 20 01  cmp  %o0, 1
a0091b1c:  18 80 00 06  bgu  0xa0091b34
a0091b20:  98 03 40 01  add  %o5, %g1, %o4
a0091b24:  da 03 20 04  ld  [ %o4 + 4 ], %o5
a0091b28:  03 20 00 00  sethi  %hi(0x80000000), %g1
a0091b2c:  82 2b 40 01  andn  %o5, %g1, %g1
a0091b30:  c2 23 20 04  st  %g1, [ %o4 + 4 ]
a0091b34:  81 c3 e0 08  retl
a0091b38:  01 00 00 00  nop
