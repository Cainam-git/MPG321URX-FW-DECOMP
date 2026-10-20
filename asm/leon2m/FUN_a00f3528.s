# leon2m FUN_a00f3528 0xa00f3528-0xa00f3580 (88 bytes)
a00f3528:  9d e3 bf 98  save  %sp, -104, %sp
a00f352c:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00f3530:  c2 0b 63 70  ldub  [ %o5 + 0x370 ], %g1	! 0xa802b770
a00f3534:  11 33 c0 4a  sethi  %hi(0xcf012800), %o0
a00f3538:  90 12 20 20  or  %o0, 0x20, %o0	! 0xcf012820
a00f353c:  80 a0 60 00  cmp  %g1, 0
a00f3540:  02 80 00 06  be  0xa00f3558
a00f3544:  9a 13 63 70  or  %o5, 0x370, %o5
a00f3548:  da 03 60 08  ld  [ %o5 + 8 ], %o5
a00f354c:  80 a3 60 00  cmp  %o5, 0
a00f3550:  12 80 00 06  bne  0xa00f3568
a00f3554:  01 00 00 00  nop
a00f3558:  7f ff fe c8  call  0xa00f3078
a00f355c:  01 00 00 00  nop
a00f3560:  10 80 00 05  b  0xa00f3574
a00f3564:  93 2a 20 10  sll  %o0, 0x10, %o1
a00f3568:  9f c3 40 00  call  %o5
a00f356c:  01 00 00 00  nop
a00f3570:  93 2a 20 10  sll  %o0, 0x10, %o1
a00f3574:  b1 32 60 10  srl  %o1, 0x10, %i0
a00f3578:  81 c7 e0 08  ret
a00f357c:  81 e8 00 00  restore
