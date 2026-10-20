# leon2s FUN_a00d6c98 0xa00d6c98-0xa00d6cfc (100 bytes)
a00d6c98:  c2 0a 40 00  ldub  [ %o1 ], %g1
a00d6c9c:  83 30 60 04  srl  %g1, 4, %g1
a00d6ca0:  82 00 7f ff  add  %g1, -1, %g1
a00d6ca4:  9b 30 60 1f  srl  %g1, 0x1f, %o5
a00d6ca8:  9a 00 40 0d  add  %g1, %o5, %o5
a00d6cac:  9b 3b 60 01  sra  %o5, 1, %o5
a00d6cb0:  80 88 60 01  btst  1, %g1
a00d6cb4:  02 80 00 03  be  0xa00d6cc0
a00d6cb8:  98 10 00 0d  mov  %o5, %o4
a00d6cbc:  98 03 60 01  add  %o5, 1, %o4
a00d6cc0:  98 0b 20 ff  and  %o4, 0xff, %o4
a00d6cc4:  98 02 40 0c  add  %o1, %o4, %o4
a00d6cc8:  da 0b 20 03  ldub  [ %o4 + 3 ], %o5
a00d6ccc:  c2 0a 00 00  ldub  [ %o0 ], %g1
a00d6cd0:  9a 0b 60 7f  and  %o5, 0x7f, %o5
a00d6cd4:  82 08 7f 80  and  %g1, -128, %g1
a00d6cd8:  82 10 40 0d  or  %g1, %o5, %g1
a00d6cdc:  c2 2a 00 00  stb  %g1, [ %o0 ]
a00d6ce0:  da 0b 20 04  ldub  [ %o4 + 4 ], %o5
a00d6ce4:  c2 0a 20 01  ldub  [ %o0 + 1 ], %g1
a00d6ce8:  9a 0b 60 f0  and  %o5, 0xf0, %o5
a00d6cec:  82 08 60 0f  and  %g1, 0xf, %g1
a00d6cf0:  82 10 40 0d  or  %g1, %o5, %g1
a00d6cf4:  81 c3 e0 08  retl
a00d6cf8:  c2 2a 20 01  stb  %g1, [ %o0 + 1 ]
