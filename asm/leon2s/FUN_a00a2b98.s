# leon2s FUN_a00a2b98 0xa00a2b98-0xa00a2bec (84 bytes)
a00a2b98:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a2b9c:  92 10 63 00  or  %g1, 0x300, %o1	! 0xa807db00
a00a2ba0:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a00a2ba4:  94 10 63 ff  or  %g1, 0x3ff, %o2	! 0xffff
a00a2ba8:  96 10 20 00  clr  %o3
a00a2bac:  82 0a e0 ff  and  %o3, 0xff, %g1
a00a2bb0:  82 58 60 34  smul  %g1, 0x34, %g1
a00a2bb4:  da 02 40 01  ld  [ %o1 + %g1 ], %o5
a00a2bb8:  c2 03 60 b4  ld  [ %o5 + 0xb4 ], %g1
a00a2bbc:  82 08 40 0a  and  %g1, %o2, %g1
a00a2bc0:  c2 23 60 b4  st  %g1, [ %o5 + 0xb4 ]
a00a2bc4:  c2 03 60 b8  ld  [ %o5 + 0xb8 ], %g1
a00a2bc8:  96 02 e0 01  inc  %o3
a00a2bcc:  82 08 7f 00  and  %g1, -256, %g1
a00a2bd0:  98 0a e0 ff  and  %o3, 0xff, %o4
a00a2bd4:  c2 23 60 b8  st  %g1, [ %o5 + 0xb8 ]
a00a2bd8:  80 a3 20 01  cmp  %o4, 1
a00a2bdc:  08 bf ff f5  bleu  0xa00a2bb0
a00a2be0:  82 0a e0 ff  and  %o3, 0xff, %g1
a00a2be4:  81 c3 e0 08  retl
a00a2be8:  90 10 20 00  clr  %o0
