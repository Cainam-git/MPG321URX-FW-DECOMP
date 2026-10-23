# leon2m FUN_a002c42c 0xa002c42c-0xa002c464 (56 bytes)
a002c42c:  91 2a 20 10  sll  %o0, 0x10, %o0
a002c430:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a002c434:  91 32 20 0e  srl  %o0, 0xe, %o0
a002c438:  90 12 00 01  or  %o0, %g1, %o0
a002c43c:  c2 02 00 00  ld  [ %o0 ], %g1
a002c440:  94 0a a0 ff  and  %o2, 0xff, %o2
a002c444:  94 28 40 0a  andn  %g1, %o2, %o2
a002c448:  92 0a 60 ff  and  %o1, 0xff, %o1
a002c44c:  94 12 80 09  or  %o2, %o1, %o2
a002c450:  83 2a a0 10  sll  %o2, 0x10, %g1
a002c454:  95 30 60 10  srl  %g1, 0x10, %o2
a002c458:  d4 22 00 00  st  %o2, [ %o0 ]
a002c45c:  81 c3 e0 08  retl
a002c460:  01 00 00 00  nop
