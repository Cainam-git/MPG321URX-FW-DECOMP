# leon2m FUN_a010baac 0xa010baac-0xa010baf4 (72 bytes)
a010baac:  82 0a 20 ff  and  %o0, 0xff, %g1
a010bab0:  99 2a a0 02  sll  %o2, 2, %o4
a010bab4:  9b 28 60 02  sll  %g1, 2, %o5
a010bab8:  80 8a 60 ff  btst  0xff, %o1
a010babc:  94 10 00 0c  mov  %o4, %o2
a010bac0:  12 80 00 07  bne  0xa010badc
a010bac4:  90 10 00 0d  mov  %o5, %o0
a010bac8:  13 00 06 6b  sethi  %hi(0x19ac00), %o1
a010bacc:  90 12 62 d8  or  %o1, 0x2d8, %o0	! 0x19aed8
a010bad0:  da 02 00 0d  ld  [ %o0 + %o5 ], %o5
a010bad4:  d6 23 40 0c  st  %o3, [ %o5 + %o4 ]
a010bad8:  30 80 00 05  b,a   0xa010baec
a010badc:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010bae0:  82 13 62 cc  or  %o5, 0x2cc, %g1	! 0x19aecc
a010bae4:  d8 00 40 08  ld  [ %g1 + %o0 ], %o4
a010bae8:  d6 23 00 0a  st  %o3, [ %o4 + %o2 ]
a010baec:  81 c3 e0 08  retl
a010baf0:  01 00 00 00  nop
