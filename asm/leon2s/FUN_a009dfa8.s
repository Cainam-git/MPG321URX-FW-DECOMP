# leon2s FUN_a009dfa8 0xa009dfa8-0xa009e00c (100 bytes)
a009dfa8:  90 0a 20 ff  and  %o0, 0xff, %o0
a009dfac:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009dfb0:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009dfb4:  9a 5a 20 34  smul  %o0, 0x34, %o5
a009dfb8:  9a 03 40 01  add  %o5, %g1, %o5
a009dfbc:  d6 03 60 20  ld  [ %o5 + 0x20 ], %o3
a009dfc0:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009dfc4:  82 10 60 a8  or  %g1, 0xa8, %g1	! 0xa80790a8
a009dfc8:  da 02 e0 54  ld  [ %o3 + 0x54 ], %o5
a009dfcc:  d8 08 40 08  ldub  [ %g1 + %o0 ], %o4
a009dfd0:  9b 33 60 02  srl  %o5, 2, %o5
a009dfd4:  9b 2b 40 0c  sll  %o5, %o4, %o5
a009dfd8:  80 a3 60 00  cmp  %o5, 0
a009dfdc:  02 80 00 09  be  0xa009e000
a009dfe0:  82 10 20 00  clr  %g1
a009dfe4:  c2 02 e0 50  ld  [ %o3 + 0x50 ], %g1
a009dfe8:  83 28 40 0c  sll  %g1, %o4, %g1
a009dfec:  81 80 00 00  mov  %g0, %y
a009dff0:  01 00 00 00  nop
a009dff4:  01 00 00 00  nop
a009dff8:  01 00 00 00  nop
a009dffc:  82 70 40 0d  udiv  %g1, %o5, %g1
a009e000:  91 28 60 10  sll  %g1, 0x10, %o0
a009e004:  81 c3 e0 08  retl
a009e008:  91 32 20 10  srl  %o0, 0x10, %o0
