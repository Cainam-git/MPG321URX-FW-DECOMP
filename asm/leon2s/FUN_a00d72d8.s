# leon2s FUN_a00d72d8 0xa00d72d8-0xa00d73b4 (220 bytes)
a00d72d8:  c2 0a 40 00  ldub  [ %o1 ], %g1
a00d72dc:  83 30 60 04  srl  %g1, 4, %g1
a00d72e0:  82 00 7f ff  add  %g1, -1, %g1
a00d72e4:  9b 30 60 1f  srl  %g1, 0x1f, %o5
a00d72e8:  9a 00 40 0d  add  %g1, %o5, %o5
a00d72ec:  9b 3b 60 01  sra  %o5, 1, %o5
a00d72f0:  80 88 60 01  btst  1, %g1
a00d72f4:  94 10 00 09  mov  %o1, %o2
a00d72f8:  02 80 00 03  be  0xa00d7304
a00d72fc:  82 10 00 0d  mov  %o5, %g1
a00d7300:  82 03 60 01  add  %o5, 1, %g1
a00d7304:  92 08 60 ff  and  %g1, 0xff, %o1
a00d7308:  98 02 80 09  add  %o2, %o1, %o4
a00d730c:  da 0b 20 03  ldub  [ %o4 + 3 ], %o5
a00d7310:  c2 0a 00 00  ldub  [ %o0 ], %g1
a00d7314:  9a 0b 60 7f  and  %o5, 0x7f, %o5
a00d7318:  82 08 7f 80  and  %g1, -128, %g1
a00d731c:  82 10 40 0d  or  %g1, %o5, %g1
a00d7320:  c2 2a 00 00  stb  %g1, [ %o0 ]
a00d7324:  c2 0b 20 04  ldub  [ %o4 + 4 ], %g1
a00d7328:  c2 2a 20 01  stb  %g1, [ %o0 + 1 ]
a00d732c:  96 10 20 00  clr  %o3
a00d7330:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00d7334:  82 02 40 0d  add  %o1, %o5, %g1
a00d7338:  82 00 40 0a  add  %g1, %o2, %g1
a00d733c:  d8 08 60 05  ldub  [ %g1 + 5 ], %o4
a00d7340:  96 02 e0 01  inc  %o3
a00d7344:  9a 02 00 0d  add  %o0, %o5, %o5
a00d7348:  82 0a e0 ff  and  %o3, 0xff, %g1
a00d734c:  80 a0 60 06  cmp  %g1, 6
a00d7350:  08 bf ff f8  bleu  0xa00d7330
a00d7354:  d8 2b 60 02  stb  %o4, [ %o5 + 2 ]
a00d7358:  98 02 80 09  add  %o2, %o1, %o4
a00d735c:  da 0b 20 0c  ldub  [ %o4 + 0xc ], %o5
a00d7360:  c2 0a 20 09  ldub  [ %o0 + 9 ], %g1
a00d7364:  9a 0b 60 c0  and  %o5, 0xc0, %o5
a00d7368:  82 08 60 3f  and  %g1, 0x3f, %g1
a00d736c:  82 10 40 0d  or  %g1, %o5, %g1
a00d7370:  c2 2a 20 09  stb  %g1, [ %o0 + 9 ]
a00d7374:  da 0b 20 0c  ldub  [ %o4 + 0xc ], %o5
a00d7378:  9a 0b 60 20  and  %o5, 0x20, %o5
a00d737c:  82 08 7f df  and  %g1, -33, %g1
a00d7380:  82 10 40 0d  or  %g1, %o5, %g1
a00d7384:  c2 2a 20 09  stb  %g1, [ %o0 + 9 ]
a00d7388:  da 0b 20 0c  ldub  [ %o4 + 0xc ], %o5
a00d738c:  9a 0b 60 18  and  %o5, 0x18, %o5
a00d7390:  82 08 7f e7  and  %g1, -25, %g1
a00d7394:  82 10 40 0d  or  %g1, %o5, %g1
a00d7398:  c2 2a 20 09  stb  %g1, [ %o0 + 9 ]
a00d739c:  da 0b 20 0c  ldub  [ %o4 + 0xc ], %o5
a00d73a0:  9a 0b 60 04  and  %o5, 4, %o5
a00d73a4:  82 08 7f fb  and  %g1, -5, %g1
a00d73a8:  82 10 40 0d  or  %g1, %o5, %g1
a00d73ac:  81 c3 e0 08  retl
a00d73b0:  c2 2a 20 09  stb  %g1, [ %o0 + 9 ]
