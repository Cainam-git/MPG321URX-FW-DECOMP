# leon2s FUN_a0091bac 0xa0091bac-0xa0091be8 (60 bytes)
a0091bac:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091bb0:  9b 2a 20 03  sll  %o0, 3, %o5
a0091bb4:  9a 23 40 08  sub  %o5, %o0, %o5
a0091bb8:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0091bbc:  9b 2b 60 02  sll  %o5, 2, %o5
a0091bc0:  82 10 61 80  or  %g1, 0x180, %g1
a0091bc4:  80 a2 20 01  cmp  %o0, 1
a0091bc8:  9a 03 40 01  add  %o5, %g1, %o5
a0091bcc:  18 80 00 05  bgu  0xa0091be0
a0091bd0:  90 10 20 00  clr  %o0
a0091bd4:  c2 03 60 10  ld  [ %o5 + 0x10 ], %g1
a0091bd8:  83 30 60 01  srl  %g1, 1, %g1
a0091bdc:  90 08 60 01  and  %g1, 1, %o0
a0091be0:  81 c3 e0 08  retl
a0091be4:  01 00 00 00  nop
