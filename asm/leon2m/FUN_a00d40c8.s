# leon2m FUN_a00d40c8 0xa00d40c8-0xa00d4108 (64 bytes)
a00d40c8:  9d e3 bf 98  save  %sp, -104, %sp
a00d40cc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00d40d0:  92 10 20 14  mov  0x14, %o1
a00d40d4:  40 01 c5 63  call  0xa0145660
a00d40d8:  90 10 00 18  mov  %i0, %o0
a00d40dc:  91 2a 20 10  sll  %o0, 0x10, %o0
a00d40e0:  83 32 20 10  srl  %o0, 0x10, %g1
a00d40e4:  b2 10 20 14  mov  0x14, %i1
a00d40e8:  80 a0 60 3f  cmp  %g1, 0x3f
a00d40ec:  08 80 00 03  bleu  0xa00d40f8
a00d40f0:  b6 10 20 01  mov  1, %i3
a00d40f4:  11 00 0f c0  sethi  %hi(0x3f0000), %o0
a00d40f8:  b5 32 20 10  srl  %o0, 0x10, %i2
a00d40fc:  40 01 c5 c3  call  0xa0145808
a00d4100:  81 e8 00 00  restore
a00d4104:  01 00 00 00  nop
