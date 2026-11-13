# leon2s FUN_a0091ac4 0xa0091ac4-0xa0091b00 (60 bytes)
a0091ac4:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091ac8:  9b 2a 20 03  sll  %o0, 3, %o5
a0091acc:  9a 23 40 08  sub  %o5, %o0, %o5
a0091ad0:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0091ad4:  9b 2b 60 02  sll  %o5, 2, %o5
a0091ad8:  82 10 61 80  or  %g1, 0x180, %g1
a0091adc:  80 a2 20 01  cmp  %o0, 1
a0091ae0:  18 80 00 06  bgu  0xa0091af8
a0091ae4:  98 03 40 01  add  %o5, %g1, %o4
a0091ae8:  c2 03 20 04  ld  [ %o4 + 4 ], %g1
a0091aec:  1b 20 00 00  sethi  %hi(0x80000000), %o5
a0091af0:  82 10 40 0d  or  %g1, %o5, %g1
a0091af4:  c2 23 20 04  st  %g1, [ %o4 + 4 ]
a0091af8:  81 c3 e0 08  retl
a0091afc:  01 00 00 00  nop
