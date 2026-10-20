# leon2m FUN_a00f35d0 0xa00f35d0-0xa00f36b8 (232 bytes)
a00f35d0:  9d e3 bf 98  save  %sp, -104, %sp
a00f35d4:  21 33 c0 49  sethi  %hi(0xcf012400), %l0
a00f35d8:  82 14 20 5c  or  %l0, 0x5c, %g1	! 0xcf01245c
a00f35dc:  9a 14 20 58  or  %l0, 0x58, %o5
a00f35e0:  80 a6 20 08  cmp  %i0, 8
a00f35e4:  12 80 00 2a  bne  0xa00f368c
a00f35e8:  90 10 20 05  mov  5, %o0
a00f35ec:  c0 20 40 00  clr  [ %g1 ]
a00f35f0:  98 10 20 05  mov  5, %o4
a00f35f4:  d8 23 40 00  st  %o4, [ %o5 ]
a00f35f8:  67 fe 66 ea  call  0x4008d1a0
a00f35fc:  b0 10 20 07  mov  7, %i0
a00f3600:  7f ff fe 9e  call  0xa00f3078
a00f3604:  90 14 20 60  or  %l0, 0x60, %o0
a00f3608:  97 2a 20 10  sll  %o0, 0x10, %o3
a00f360c:  91 32 e0 10  srl  %o3, 0x10, %o0
a00f3610:  15 00 06 00  sethi  %hi(0x180000), %o2
a00f3614:  9b 3a a0 1f  sra  %o2, 0x1f, %o5
a00f3618:  81 83 60 00  mov  %o5, %y
a00f361c:  01 00 00 00  nop
a00f3620:  01 00 00 00  nop
a00f3624:  01 00 00 00  nop
a00f3628:  92 7a 80 08  sdiv  %o2, %o0, %o1
a00f362c:  83 2a 60 10  sll  %o1, 0x10, %g1
a00f3630:  83 30 60 10  srl  %g1, 0x10, %g1
a00f3634:  80 a0 60 24  cmp  %g1, 0x24
a00f3638:  28 80 00 16  bleu,a   0xa00f3690
a00f363c:  21 33 c0 80  sethi  %hi(0xcf020000), %l0
a00f3640:  80 a0 60 36  cmp  %g1, 0x36
a00f3644:  08 80 00 12  bleu  0xa00f368c
a00f3648:  b0 10 20 06  mov  6, %i0
a00f364c:  80 a0 60 4f  cmp  %g1, 0x4f
a00f3650:  08 80 00 0f  bleu  0xa00f368c
a00f3654:  b0 10 20 05  mov  5, %i0
a00f3658:  80 a0 60 59  cmp  %g1, 0x59
a00f365c:  08 80 00 0c  bleu  0xa00f368c
a00f3660:  b0 10 20 04  mov  4, %i0
a00f3664:  80 a0 60 6d  cmp  %g1, 0x6d
a00f3668:  08 80 00 09  bleu  0xa00f368c
a00f366c:  b0 10 20 03  mov  3, %i0
a00f3670:  80 a0 60 8b  cmp  %g1, 0x8b
a00f3674:  08 80 00 06  bleu  0xa00f368c
a00f3678:  b0 10 20 02  mov  2, %i0
a00f367c:  80 a0 60 b3  cmp  %g1, 0xb3
a00f3680:  08 80 00 03  bleu  0xa00f368c
a00f3684:  b0 10 20 01  mov  1, %i0
a00f3688:  b0 10 20 00  clr  %i0
a00f368c:  21 33 c0 80  sethi  %hi(0xcf020000), %l0
a00f3690:  93 2e 20 05  sll  %i0, 5, %o1
a00f3694:  9e 0a 60 ff  and  %o1, 0xff, %o7
a00f3698:  82 14 20 24  or  %l0, 0x24, %g1
a00f369c:  de 20 40 00  st  %o7, [ %g1 ]
a00f36a0:  b0 14 20 2c  or  %l0, 0x2c, %i0
a00f36a4:  de 26 00 00  st  %o7, [ %i0 ]
a00f36a8:  9a 14 20 34  or  %l0, 0x34, %o5
a00f36ac:  de 23 40 00  st  %o7, [ %o5 ]
a00f36b0:  81 c7 e0 08  ret
a00f36b4:  81 e8 00 00  restore
