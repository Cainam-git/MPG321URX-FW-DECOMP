# leon2m FUN_a0154580 0xa0154580-0xa015463c (188 bytes)
a0154580:  9d e3 bf 98  save  %sp, -104, %sp
a0154584:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a0154588:  82 10 60 c0  or  %g1, 0xc0, %g1	! 0xa802a4c0
a015458c:  c2 08 40 00  ldub  [ %g1 ], %g1
a0154590:  82 08 60 ff  and  %g1, 0xff, %g1
a0154594:  80 a0 60 01  cmp  %g1, 1
a0154598:  12 80 00 13  bne  0xa01545e4
a015459c:  01 00 00 00  nop
a01545a0:  7f ff 22 7a  call  0xa011cf88
a01545a4:  01 00 00 00  nop
a01545a8:  9a 10 00 08  mov  %o0, %o5
a01545ac:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a01545b0:  82 10 63 9c  or  %g1, 0x39c, %g1	! 0xa802cf9c
a01545b4:  da 28 40 00  stb  %o5, [ %g1 ]
a01545b8:  7f ff 22 bc  call  0xa011d0a8
a01545bc:  01 00 00 00  nop
a01545c0:  9a 10 00 08  mov  %o0, %o5
a01545c4:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a01545c8:  82 10 63 9d  or  %g1, 0x39d, %g1	! 0xa802cf9d
a01545cc:  da 28 40 00  stb  %o5, [ %g1 ]
a01545d0:  7f ff ff c1  call  0xa01544d4
a01545d4:  01 00 00 00  nop
a01545d8:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a01545dc:  82 10 60 c0  or  %g1, 0xc0, %g1	! 0xa802a4c0
a01545e0:  c0 28 40 00  clrb  [ %g1 ]
a01545e4:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a01545e8:  82 10 63 98  or  %g1, 0x398, %g1	! 0xa802cf98
a01545ec:  c2 00 40 00  ld  [ %g1 ], %g1
a01545f0:  80 a0 60 00  cmp  %g1, 0
a01545f4:  02 80 00 0c  be  0xa0154624
a01545f8:  01 00 00 00  nop
a01545fc:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a0154600:  82 10 63 9c  or  %g1, 0x39c, %g1	! 0xa802cf9c
a0154604:  c2 08 40 00  ldub  [ %g1 ], %g1
a0154608:  82 08 60 ff  and  %g1, 0xff, %g1
a015460c:  82 08 60 f0  and  %g1, 0xf0, %g1
a0154610:  80 a0 60 80  cmp  %g1, 0x80
a0154614:  12 80 00 04  bne  0xa0154624
a0154618:  01 00 00 00  nop
a015461c:  7f ff ff d6  call  0xa0154574
a0154620:  01 00 00 00  nop
a0154624:  67 fc e2 2d  call  0x4008ced8
a0154628:  01 00 00 00  nop
a015462c:  82 10 20 00  clr  %g1	! 0x0
a0154630:  b0 10 00 01  mov  %g1, %i0
a0154634:  81 c7 e0 08  ret
a0154638:  81 e8 00 00  restore
