# leon2s FUN_a00d3eb0 0xa00d3eb0-0xa00d3ef0 (64 bytes)
a00d3eb0:  83 2a 20 10  sll  %o0, 0x10, %g1
a00d3eb4:  9b 30 60 10  srl  %g1, 0x10, %o5
a00d3eb8:  03 00 00 09  sethi  %hi(0x2400), %g1
a00d3ebc:  98 10 63 10  or  %g1, 0x310, %o4	! 0x2710
a00d3ec0:  80 a3 40 0c  cmp  %o5, %o4
a00d3ec4:  08 80 00 04  bleu  0xa00d3ed4
a00d3ec8:  17 2a 01 de  sethi  %hi(0xa8077800), %o3
a00d3ecc:  10 80 00 07  b  0xa00d3ee8
a00d3ed0:  d8 32 e1 dc  sth  %o4, [ %o3 + 0x1dc ]	! 0xa80779dc
a00d3ed4:  80 a3 60 00  cmp  %o5, 0
a00d3ed8:  32 80 00 04  bne,a   0xa00d3ee8
a00d3edc:  d0 32 e1 dc  sth  %o0, [ %o3 + 0x1dc ]
a00d3ee0:  82 10 23 e8  mov  0x3e8, %g1
a00d3ee4:  c2 32 e1 dc  sth  %g1, [ %o3 + 0x1dc ]
a00d3ee8:  81 c3 e0 08  retl
a00d3eec:  01 00 00 00  nop
