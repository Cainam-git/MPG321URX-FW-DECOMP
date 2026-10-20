# leon2m FUN_a014692c 0xa014692c-0xa014698c (96 bytes)
a014692c:  9d e3 bf 98  save  %sp, -104, %sp
a0146930:  82 0e 20 ff  and  %i0, 0xff, %g1
a0146934:  d6 0f a0 5f  ldub  [ %fp + 0x5f ], %o3
a0146938:  a0 10 00 1d  mov  %i5, %l0
a014693c:  80 a0 60 07  cmp  %g1, 7
a0146940:  18 80 00 0c  bgu  0xa0146970
a0146944:  ba 0a e0 ff  and  %o3, 0xff, %i5
a0146948:  11 00 03 8c  sethi  %hi(0xe3000), %o0
a014694c:  83 28 60 02  sll  %g1, 2, %g1
a0146950:  9a 12 23 20  or  %o0, 0x320, %o5
a0146954:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a0146958:  81 c3 00 00  jmp  %o4
a014695c:  01 00 00 00  nop
a0146960:  ba 0a e0 ff  and  %o3, 0xff, %i5
a0146964:  90 10 20 07  mov  7, %o0
a0146968:  67 fd 1f 5f  call  0x4008e6e4
a014696c:  92 10 00 1d  mov  %i5, %o1
a0146970:  b0 0e 60 ff  and  %i1, 0xff, %i0
a0146974:  b2 0e a0 ff  and  %i2, 0xff, %i1
a0146978:  b4 0e e0 ff  and  %i3, 0xff, %i2
a014697c:  b6 0f 20 ff  and  %i4, 0xff, %i3
a0146980:  b8 0c 20 ff  and  %l0, 0xff, %i4
a0146984:  7f ff 50 18  call  0xa011a9e4
a0146988:  81 e8 00 00  restore
