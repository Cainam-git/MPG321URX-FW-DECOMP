# leon2m FUN_a014648c 0xa014648c-0xa0146518 (140 bytes)
a014648c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0146490:  80 a2 20 01  cmp  %o0, 1
a0146494:  02 80 00 0a  be  0xa01464bc
a0146498:  82 10 00 09  mov  %o1, %g1
a014649c:  80 a2 20 01  cmp  %o0, 1
a01464a0:  04 80 00 14  ble  0xa01464f0
a01464a4:  80 a2 20 02  cmp  %o0, 2
a01464a8:  02 80 00 0c  be  0xa01464d8
a01464ac:  80 a2 20 03  cmp  %o0, 3
a01464b0:  12 80 00 17  bne  0xa014650c
a01464b4:  92 08 60 ff  and  %g1, 0xff, %o1
a01464b8:  30 80 00 11  b,a   0xa01464fc
a01464bc:  93 2a a0 10  sll  %o2, 0x10, %o1
a01464c0:  90 08 60 ff  and  %g1, 0xff, %o0
a01464c4:  93 32 60 10  srl  %o1, 0x10, %o1
a01464c8:  94 0a e0 ff  and  %o3, 0xff, %o2
a01464cc:  82 13 c0 00  mov  %o7, %g1
a01464d0:  7f ff 59 32  call  0xa011c998
a01464d4:  9e 10 40 00  mov  %g1, %o7
a01464d8:  91 2a a0 10  sll  %o2, 0x10, %o0
a01464dc:  91 32 20 10  srl  %o0, 0x10, %o0
a01464e0:  92 0a e0 ff  and  %o3, 0xff, %o1
a01464e4:  82 13 c0 00  mov  %o7, %g1
a01464e8:  7f ff 59 5c  call  0xa011ca58
a01464ec:  9e 10 40 00  mov  %g1, %o7
a01464f0:  80 a2 20 00  cmp  %o0, 0
a01464f4:  12 80 00 06  bne  0xa014650c
a01464f8:  92 08 60 ff  and  %g1, 0xff, %o1
a01464fc:  90 0a e0 ff  and  %o3, 0xff, %o0
a0146500:  82 13 c0 00  mov  %o7, %g1
a0146504:  7f ff 53 b9  call  0xa011b3e8
a0146508:  9e 10 40 00  mov  %g1, %o7
a014650c:  01 00 00 00  nop
a0146510:  81 c3 e0 08  retl
a0146514:  01 00 00 00  nop
