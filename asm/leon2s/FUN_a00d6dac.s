# leon2s FUN_a00d6dac 0xa00d6dac-0xa00d6df8 (76 bytes)
a00d6dac:  c2 0a 40 00  ldub  [ %o1 ], %g1
a00d6db0:  83 30 60 04  srl  %g1, 4, %g1
a00d6db4:  82 00 7f ff  add  %g1, -1, %g1
a00d6db8:  9b 30 60 1f  srl  %g1, 0x1f, %o5
a00d6dbc:  9a 00 40 0d  add  %g1, %o5, %o5
a00d6dc0:  9b 3b 60 01  sra  %o5, 1, %o5
a00d6dc4:  80 88 60 01  btst  1, %g1
a00d6dc8:  02 80 00 03  be  0xa00d6dd4
a00d6dcc:  82 10 00 0d  mov  %o5, %g1
a00d6dd0:  82 03 60 01  add  %o5, 1, %g1
a00d6dd4:  82 08 60 ff  and  %g1, 0xff, %g1
a00d6dd8:  82 02 40 01  add  %o1, %g1, %g1
a00d6ddc:  da 08 60 03  ldub  [ %g1 + 3 ], %o5
a00d6de0:  c2 0a 00 00  ldub  [ %o0 ], %g1
a00d6de4:  9a 0b 60 7f  and  %o5, 0x7f, %o5
a00d6de8:  82 08 7f 80  and  %g1, -128, %g1
a00d6dec:  82 10 40 0d  or  %g1, %o5, %g1
a00d6df0:  81 c3 e0 08  retl
a00d6df4:  c2 2a 00 00  stb  %g1, [ %o0 ]
