# leon2m FUN_a014b65c 0xa014b65c-0xa014b750 (244 bytes)
a014b65c:  9d e3 bf 98  save  %sp, -104, %sp
a014b660:  7f ff 66 ce  call  0xa0125198
a014b664:  90 0e 20 ff  and  %i0, 0xff, %o0
a014b668:  7f ff da ec  call  0xa0142218
a014b66c:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b670:  7f ff da d5  call  0xa01421c4
a014b674:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b678:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b67c:  80 a2 20 61  cmp  %o0, 0x61
a014b680:  02 80 00 17  be  0xa014b6dc
a014b684:  82 10 20 00  clr  %g1
a014b688:  80 a2 20 61  cmp  %o0, 0x61
a014b68c:  04 80 00 08  ble  0xa014b6ac
a014b690:  98 08 60 03  and  %g1, 3, %o4
a014b694:  80 a2 20 71  cmp  %o0, 0x71
a014b698:  02 80 00 1f  be  0xa014b714
a014b69c:  80 a2 20 81  cmp  %o0, 0x81
a014b6a0:  22 80 00 02  be,a   0xa014b6a8
a014b6a4:  82 10 20 03  mov  3, %g1
a014b6a8:  98 08 60 03  and  %g1, 3, %o4
a014b6ac:  97 2b 20 03  sll  %o4, 3, %o3
a014b6b0:  94 02 c0 0c  add  %o3, %o4, %o2
a014b6b4:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a014b6b8:  90 02 80 0a  add  %o2, %o2, %o0
a014b6bc:  82 12 61 16  or  %o1, 0x116, %g1
a014b6c0:  9a 02 00 01  add  %o0, %g1, %o5
a014b6c4:  7f ff 66 98  call  0xa0125124
a014b6c8:  d0 0b 60 10  ldub  [ %o5 + 0x10 ], %o0
a014b6cc:  b0 0a 20 ff  and  %o0, 0xff, %i0
a014b6d0:  b2 0e 60 ff  and  %i1, 0xff, %i1
a014b6d4:  7f ff 67 3a  call  0xa01253bc
a014b6d8:  81 e8 00 00  restore
a014b6dc:  82 10 20 01  mov  1, %g1
a014b6e0:  98 08 60 03  and  %g1, 3, %o4
a014b6e4:  97 2b 20 03  sll  %o4, 3, %o3
a014b6e8:  94 02 c0 0c  add  %o3, %o4, %o2
a014b6ec:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a014b6f0:  90 02 80 0a  add  %o2, %o2, %o0
a014b6f4:  82 12 61 16  or  %o1, 0x116, %g1
a014b6f8:  9a 02 00 01  add  %o0, %g1, %o5
a014b6fc:  7f ff 66 8a  call  0xa0125124
a014b700:  d0 0b 60 10  ldub  [ %o5 + 0x10 ], %o0
a014b704:  b0 0a 20 ff  and  %o0, 0xff, %i0
a014b708:  b2 0e 60 ff  and  %i1, 0xff, %i1
a014b70c:  7f ff 67 2c  call  0xa01253bc
a014b710:  81 e8 00 00  restore
a014b714:  82 10 20 02  mov  2, %g1
a014b718:  98 08 60 03  and  %g1, 3, %o4
a014b71c:  97 2b 20 03  sll  %o4, 3, %o3
a014b720:  94 02 c0 0c  add  %o3, %o4, %o2
a014b724:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a014b728:  90 02 80 0a  add  %o2, %o2, %o0
a014b72c:  82 12 61 16  or  %o1, 0x116, %g1
a014b730:  9a 02 00 01  add  %o0, %g1, %o5
a014b734:  7f ff 66 7c  call  0xa0125124
a014b738:  d0 0b 60 10  ldub  [ %o5 + 0x10 ], %o0
a014b73c:  b0 0a 20 ff  and  %o0, 0xff, %i0
a014b740:  b2 0e 60 ff  and  %i1, 0xff, %i1
a014b744:  7f ff 67 1e  call  0xa01253bc
a014b748:  81 e8 00 00  restore
a014b74c:  01 00 00 00  nop
