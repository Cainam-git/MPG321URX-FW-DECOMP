# leon2m FUN_a010bea4 0xa010bea4-0xa010bee4 (64 bytes)
a010bea4:  82 0a 20 ff  and  %o0, 0xff, %g1
a010bea8:  9b 28 60 02  sll  %g1, 2, %o5
a010beac:  80 8a 60 ff  btst  0xff, %o1
a010beb0:  12 80 00 06  bne  0xa010bec8
a010beb4:  90 10 00 0d  mov  %o5, %o0
a010beb8:  11 00 06 6b  sethi  %hi(0x19ac00), %o0
a010bebc:  92 12 22 d8  or  %o0, 0x2d8, %o1	! 0x19aed8
a010bec0:  10 80 00 05  b  0xa010bed4
a010bec4:  d0 02 40 0d  ld  [ %o1 + %o5 ], %o0
a010bec8:  03 00 06 6b  sethi  %hi(0x19ac00), %g1
a010becc:  9a 10 62 cc  or  %g1, 0x2cc, %o5	! 0x19aecc
a010bed0:  d0 03 40 08  ld  [ %o5 + %o0 ], %o0
a010bed4:  93 2a a0 02  sll  %o2, 2, %o1
a010bed8:  d0 02 00 09  ld  [ %o0 + %o1 ], %o0
a010bedc:  81 c3 e0 08  retl
a010bee0:  01 00 00 00  nop
