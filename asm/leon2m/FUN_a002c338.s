# leon2m FUN_a002c338 0xa002c338-0xa002c364 (44 bytes)
a002c338:  91 2a 20 10  sll  %o0, 0x10, %o0
a002c33c:  83 32 20 10  srl  %o0, 0x10, %g1
a002c340:  92 0a 60 ff  and  %o1, 0xff, %o1
a002c344:  90 00 40 09  add  %g1, %o1, %o0
a002c348:  93 2a 20 02  sll  %o0, 2, %o1
a002c34c:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a002c350:  90 12 40 01  or  %o1, %g1, %o0
a002c354:  94 0a a0 ff  and  %o2, 0xff, %o2
a002c358:  d4 22 00 00  st  %o2, [ %o0 ]
a002c35c:  81 c3 e0 08  retl
a002c360:  01 00 00 00  nop
