# leon2m FUN_a008b330 0xa008b330-0xa008b380 (80 bytes)
a008b330:  9d e3 bf 98  save  %sp, -104, %sp
a008b334:  40 00 17 26  call  0xa0090fcc
a008b338:  01 00 00 00  nop
a008b33c:  83 2a 20 10  sll  %o0, 0x10, %g1
a008b340:  91 30 60 10  srl  %g1, 0x10, %o0
a008b344:  80 a2 21 13  cmp  %o0, 0x113
a008b348:  02 80 00 09  be  0xa008b36c
a008b34c:  01 00 00 00  nop
a008b350:  40 00 17 1f  call  0xa0090fcc
a008b354:  01 00 00 00  nop
a008b358:  95 2a 20 10  sll  %o0, 0x10, %o2
a008b35c:  93 32 a0 10  srl  %o2, 0x10, %o1
a008b360:  80 a2 61 14  cmp  %o1, 0x114
a008b364:  12 80 00 04  bne  0xa008b374
a008b368:  01 00 00 00  nop
a008b36c:  40 00 17 1b  call  0xa0090fd8
a008b370:  81 e8 00 00  restore
a008b374:  01 00 00 00  nop
a008b378:  81 c7 e0 08  ret
a008b37c:  81 e8 00 00  restore
