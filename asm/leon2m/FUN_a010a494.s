# leon2m FUN_a010a494 0xa010a494-0xa010a4d0 (60 bytes)
a010a494:  9d e3 bf 98  save  %sp, -104, %sp
a010a498:  13 33 c0 46  sethi  %hi(0xcf011800), %o1
a010a49c:  82 12 62 80  or  %o1, 0x280, %g1	! 0xcf011a80
a010a4a0:  da 00 40 00  ld  [ %g1 ], %o5
a010a4a4:  80 8b 60 80  btst  0x80, %o5
a010a4a8:  12 80 00 04  bne  0xa010a4b8
a010a4ac:  90 12 62 d8  or  %o1, 0x2d8, %o0
a010a4b0:  11 33 c0 47  sethi  %hi(0xcf011c00), %o0
a010a4b4:  90 12 20 18  or  %o0, 0x18, %o0	! 0xcf011c18
a010a4b8:  7f ff a2 f0  call  0xa00f3078
a010a4bc:  01 00 00 00  nop
a010a4c0:  95 2a 20 10  sll  %o0, 0x10, %o2
a010a4c4:  b1 32 a0 10  srl  %o2, 0x10, %i0
a010a4c8:  81 c7 e0 08  ret
a010a4cc:  81 e8 00 00  restore
