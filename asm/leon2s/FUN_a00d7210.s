# leon2s FUN_a00d7210 0xa00d7210-0xa00d7274 (100 bytes)
a00d7210:  c2 0a 40 00  ldub  [ %o1 ], %g1
a00d7214:  83 30 60 04  srl  %g1, 4, %g1
a00d7218:  82 00 7f ff  add  %g1, -1, %g1
a00d721c:  9b 30 60 1f  srl  %g1, 0x1f, %o5
a00d7220:  9a 00 40 0d  add  %g1, %o5, %o5
a00d7224:  9b 3b 60 01  sra  %o5, 1, %o5
a00d7228:  80 88 60 01  btst  1, %g1
a00d722c:  02 80 00 03  be  0xa00d7238
a00d7230:  98 10 00 0d  mov  %o5, %o4
a00d7234:  98 03 60 01  add  %o5, 1, %o4
a00d7238:  98 0b 20 ff  and  %o4, 0xff, %o4
a00d723c:  98 02 40 0c  add  %o1, %o4, %o4
a00d7240:  da 0b 20 03  ldub  [ %o4 + 3 ], %o5
a00d7244:  c2 0a 00 00  ldub  [ %o0 ], %g1
a00d7248:  9a 0b 60 7f  and  %o5, 0x7f, %o5
a00d724c:  82 08 7f 80  and  %g1, -128, %g1
a00d7250:  82 10 40 0d  or  %g1, %o5, %g1
a00d7254:  c2 2a 00 00  stb  %g1, [ %o0 ]
a00d7258:  da 0b 20 04  ldub  [ %o4 + 4 ], %o5
a00d725c:  c2 0a 20 01  ldub  [ %o0 + 1 ], %g1
a00d7260:  9a 0b 60 f0  and  %o5, 0xf0, %o5
a00d7264:  82 08 60 0f  and  %g1, 0xf, %g1
a00d7268:  82 10 40 0d  or  %g1, %o5, %g1
a00d726c:  81 c3 e0 08  retl
a00d7270:  c2 2a 20 01  stb  %g1, [ %o0 + 1 ]
