# leon2s FUN_a00d714c 0xa00d714c-0xa00d7210 (196 bytes)
a00d714c:  9d e3 bf 98  save  %sp, -104, %sp
a00d7150:  c2 0e 40 00  ldub  [ %i1 ], %g1
a00d7154:  83 30 60 04  srl  %g1, 4, %g1
a00d7158:  82 00 7f ff  add  %g1, -1, %g1
a00d715c:  bb 30 60 1f  srl  %g1, 0x1f, %i5
a00d7160:  ba 00 40 1d  add  %g1, %i5, %i5
a00d7164:  bb 3f 60 01  sra  %i5, 1, %i5
a00d7168:  80 88 60 01  btst  1, %g1
a00d716c:  02 80 00 03  be  0xa00d7178
a00d7170:  82 10 00 1d  mov  %i5, %g1
a00d7174:  82 07 60 01  add  %i5, 1, %g1
a00d7178:  9e 08 60 ff  and  %g1, 0xff, %o7
a00d717c:  b8 06 40 0f  add  %i1, %o7, %i4
a00d7180:  fa 0f 20 03  ldub  [ %i4 + 3 ], %i5
a00d7184:  c2 0e 00 00  ldub  [ %i0 ], %g1
a00d7188:  ba 0f 60 7f  and  %i5, 0x7f, %i5
a00d718c:  82 08 7f 80  and  %g1, -128, %g1
a00d7190:  82 10 40 1d  or  %g1, %i5, %g1
a00d7194:  c2 2e 00 00  stb  %g1, [ %i0 ]
a00d7198:  fa 0f 20 04  ldub  [ %i4 + 4 ], %i5
a00d719c:  c2 0e 20 01  ldub  [ %i0 + 1 ], %g1
a00d71a0:  ba 0f 60 f0  and  %i5, 0xf0, %i5
a00d71a4:  82 08 60 0f  and  %g1, 0xf, %g1
a00d71a8:  82 10 40 1d  or  %g1, %i5, %g1
a00d71ac:  c2 2e 20 01  stb  %g1, [ %i0 + 1 ]
a00d71b0:  fa 0f 20 05  ldub  [ %i4 + 5 ], %i5
a00d71b4:  c2 0e 20 02  ldub  [ %i0 + 2 ], %g1
a00d71b8:  ba 0f 60 7f  and  %i5, 0x7f, %i5
a00d71bc:  82 08 7f 80  and  %g1, -128, %g1
a00d71c0:  82 10 40 1d  or  %g1, %i5, %g1
a00d71c4:  c2 2e 20 02  stb  %g1, [ %i0 + 2 ]
a00d71c8:  c2 0f 20 06  ldub  [ %i4 + 6 ], %g1
a00d71cc:  c2 2e 20 03  stb  %g1, [ %i0 + 3 ]
a00d71d0:  80 a0 60 00  cmp  %g1, 0
a00d71d4:  02 80 00 0d  be  0xa00d7208
a00d71d8:  b6 10 20 00  clr  %i3
a00d71dc:  b4 10 00 01  mov  %g1, %i2
a00d71e0:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00d71e4:  82 03 c0 1d  add  %o7, %i5, %g1
a00d71e8:  82 00 40 19  add  %g1, %i1, %g1
a00d71ec:  f8 08 60 07  ldub  [ %g1 + 7 ], %i4
a00d71f0:  b6 06 e0 01  inc  %i3
a00d71f4:  ba 06 00 1d  add  %i0, %i5, %i5
a00d71f8:  82 0e e0 ff  and  %i3, 0xff, %g1
a00d71fc:  80 a0 40 1a  cmp  %g1, %i2
a00d7200:  0a bf ff f8  bcs  0xa00d71e0
a00d7204:  f8 2f 60 04  stb  %i4, [ %i5 + 4 ]
a00d7208:  81 c7 e0 08  ret
a00d720c:  81 e8 00 00  restore
