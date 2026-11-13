# leon2m FUN_a014489c 0xa014489c-0xa01448fc (96 bytes)
a014489c:  9d e3 bf 98  save  %sp, -104, %sp
a01448a0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01448a4:  9f 2e 20 04  sll  %i0, 4, %o7
a01448a8:  98 23 c0 18  sub  %o7, %i0, %o4
a01448ac:  17 2a 00 b7  sethi  %hi(0xa802dc00), %o3
a01448b0:  9b 2b 20 03  sll  %o4, 3, %o5
a01448b4:  94 12 e3 30  or  %o3, 0x330, %o2
a01448b8:  d2 02 80 0d  ld  [ %o2 + %o5 ], %o1
a01448bc:  83 32 60 0c  srl  %o1, 0xc, %g1
a01448c0:  7f fe e3 d8  call  0xa00fd820
a01448c4:  90 08 60 0f  and  %g1, 0xf, %o0
a01448c8:  90 0a 20 ff  and  %o0, 0xff, %o0
a01448cc:  80 a2 20 b1  cmp  %o0, 0xb1
a01448d0:  12 80 00 08  bne  0xa01448f0
a01448d4:  90 10 20 08  mov  8, %o0
a01448d8:  7f ff ac d2  call  0xa012fc20
a01448dc:  01 00 00 00  nop
a01448e0:  7f ff f6 22  call  0xa0142168
a01448e4:  90 0a 20 ff  and  %o0, 0xff, %o0
a01448e8:  7f ff d2 55  call  0xa013923c
a01448ec:  90 0a 20 ff  and  %o0, 0xff, %o0
a01448f0:  b0 0a 20 ff  and  %o0, 0xff, %i0
a01448f4:  81 c7 e0 08  ret
a01448f8:  81 e8 00 00  restore
