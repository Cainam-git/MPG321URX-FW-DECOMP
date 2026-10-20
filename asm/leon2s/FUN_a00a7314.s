# leon2s FUN_a00a7314 0xa00a7314-0xa00a7368 (84 bytes)
a00a7314:  1b 00 00 3d  sethi  %hi(0xf400), %o5
a00a7318:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a731c:  9a 13 60 01  or  %o5, 1, %o5
a00a7320:  9a 02 00 0d  add  %o0, %o5, %o5
a00a7324:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00a7328:  9b 2b 60 02  sll  %o5, 2, %o5
a00a732c:  9a 13 40 01  or  %o5, %g1, %o5
a00a7330:  83 2a 60 10  sll  %o1, 0x10, %g1
a00a7334:  d8 03 40 00  ld  [ %o5 ], %o4
a00a7338:  83 30 60 18  srl  %g1, 0x18, %g1
a00a733c:  c2 23 40 00  st  %g1, [ %o5 ]
a00a7340:  92 0a 60 ff  and  %o1, 0xff, %o1
a00a7344:  91 2a 20 08  sll  %o0, 8, %o0
a00a7348:  03 33 80 20  sethi  %hi(0xce008000), %g1
a00a734c:  90 02 00 09  add  %o0, %o1, %o0
a00a7350:  82 10 61 00  or  %g1, 0x100, %g1
a00a7354:  d0 02 00 01  ld  [ %o0 + %g1 ], %o0
a00a7358:  98 0b 20 ff  and  %o4, 0xff, %o4
a00a735c:  d8 23 40 00  st  %o4, [ %o5 ]
a00a7360:  81 c3 e0 08  retl
a00a7364:  01 00 00 00  nop
