# leon2s FUN_a00d7ca4 0xa00d7ca4-0xa00d7cd0 (44 bytes)
a00d7ca4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d7ca8:  da 08 60 32  ldub  [ %g1 + 0x32 ], %o5	! 0xa8078832
a00d7cac:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00d7cb0:  82 10 60 a4  or  %g1, 0xa4, %g1	! 0xa80760a4
a00d7cb4:  9b 2b 60 02  sll  %o5, 2, %o5
a00d7cb8:  da 00 40 0d  ld  [ %g1 + %o5 ], %o5
a00d7cbc:  c2 03 60 c0  ld  [ %o5 + 0xc0 ], %g1
a00d7cc0:  82 08 7f 7f  and  %g1, -129, %g1
a00d7cc4:  c2 23 60 c0  st  %g1, [ %o5 + 0xc0 ]
a00d7cc8:  81 c3 e0 08  retl
a00d7ccc:  01 00 00 00  nop
