# leon2m FUN_a0120848 0xa0120848-0xa0120998 (336 bytes)  [FUN_a0120990 = unreachable ret/restore tail, merged]
a0120848:  9d e3 bf 98  save  %sp, -104, %sp
a012084c:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a0120850:  96 10 62 ac  or  %g1, 0x2ac, %o3	! 0xa8027aac
a0120854:  da 02 e0 04  ld  [ %o3 + 4 ], %o5
a0120858:  80 a3 60 01  cmp  %o5, 1
a012085c:  a0 10 00 1a  mov  %i2, %l0
a0120860:  02 80 00 19  be  0xa01208c4
a0120864:  a2 10 20 00  clr  %l1
a0120868:  b0 0e 20 ff  and  %i0, 0xff, %i0
a012086c:  80 a6 20 08  cmp  %i0, 8
a0120870:  02 80 00 1b  be  0xa01208dc
a0120874:  9e 0e 60 ff  and  %i1, 0xff, %o7
a0120878:  98 06 00 18  add  %i0, %i0, %o4
a012087c:  b4 03 00 18  add  %o4, %i0, %i2
a0120880:  a7 2e a0 02  sll  %i2, 2, %l3
a0120884:  a4 04 c0 0b  add  %l3, %o3, %l2
a0120888:  e2 04 a0 04  ld  [ %l2 + 4 ], %l1
a012088c:  90 10 00 18  mov  %i0, %o0
a0120890:  92 10 20 29  mov  0x29, %o1
a0120894:  80 a4 60 01  cmp  %l1, 1
a0120898:  02 80 00 31  be  0xa012095c
a012089c:  94 0c 20 e0  and  %l0, 0xe0, %o2
a01208a0:  7f ff 45 d0  call  0xa00f1fe0
a01208a4:  01 00 00 00  nop
a01208a8:  96 0e 60 ff  and  %i1, 0xff, %o3
a01208ac:  95 2a e0 05  sll  %o3, 5, %o2
a01208b0:  9e 0c 20 1e  and  %l0, 0x1e, %o7
a01208b4:  b2 12 80 0f  or  %o2, %o7, %i1
a01208b8:  b4 0e 60 fe  and  %i1, 0xfe, %i2
a01208bc:  7f ff 45 c9  call  0xa00f1fe0
a01208c0:  93 e8 20 1b  restore  %g0, 0x1b, %o1
a01208c4:  90 0e a0 ff  and  %i2, 0xff, %o0
a01208c8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01208cc:  80 a6 20 08  cmp  %i0, 8
a01208d0:  12 bf ff ea  bne  0xa0120878
a01208d4:  a1 2a 20 03  sll  %o0, 3, %l0
a01208d8:  9e 0e 60 ff  and  %i1, 0xff, %o7
a01208dc:  95 2b e0 05  sll  %o7, 5, %o2
a01208e0:  92 0c 20 1e  and  %l0, 0x1e, %o1
a01208e4:  98 0c 3f e0  and  %l0, -32, %o4
a01208e8:  b2 12 80 09  or  %o2, %o1, %i1
a01208ec:  a6 10 00 0b  mov  %o3, %l3
a01208f0:  a4 13 20 04  or  %o4, 4, %l2
a01208f4:  b4 0c 20 ff  and  %l0, 0xff, %i2
a01208f8:  b0 10 20 00  clr  %i0
a01208fc:  90 06 00 18  add  %i0, %i0, %o0
a0120900:  82 02 00 18  add  %o0, %i0, %g1
a0120904:  9b 28 60 02  sll  %g1, 2, %o5
a0120908:  a0 03 40 13  add  %o5, %l3, %l0
a012090c:  d6 04 20 04  ld  [ %l0 + 4 ], %o3
a0120910:  90 10 00 18  mov  %i0, %o0
a0120914:  92 10 20 29  mov  0x29, %o1
a0120918:  80 a2 e0 01  cmp  %o3, 1
a012091c:  02 80 00 05  be  0xa0120930
a0120920:  94 0c a0 ff  and  %l2, 0xff, %o2
a0120924:  90 10 00 18  mov  %i0, %o0
a0120928:  94 0e a0 e0  and  %i2, 0xe0, %o2
a012092c:  92 10 20 29  mov  0x29, %o1
a0120930:  7f ff 45 ac  call  0xa00f1fe0
a0120934:  a2 04 60 01  inc  %l1
a0120938:  90 10 00 18  mov  %i0, %o0
a012093c:  92 10 20 1b  mov  0x1b, %o1
a0120940:  7f ff 45 a8  call  0xa00f1fe0
a0120944:  94 0e 60 ff  and  %i1, 0xff, %o2
a0120948:  b0 0c 60 ff  and  %l1, 0xff, %i0
a012094c:  80 a6 20 07  cmp  %i0, 7
a0120950:  08 bf ff ec  bleu  0xa0120900
a0120954:  90 06 00 18  add  %i0, %i0, %o0
a0120958:  30 80 00 0d  b,a   0xa012098c
a012095c:  92 14 20 04  or  %l0, 4, %o1
a0120960:  94 0a 60 e4  and  %o1, 0xe4, %o2
a0120964:  90 10 00 18  mov  %i0, %o0
a0120968:  7f ff 45 9e  call  0xa00f1fe0
a012096c:  92 10 20 29  mov  0x29, %o1
a0120970:  96 0e 60 ff  and  %i1, 0xff, %o3
a0120974:  95 2a e0 05  sll  %o3, 5, %o2
a0120978:  9e 0c 20 1e  and  %l0, 0x1e, %o7
a012097c:  b2 12 80 0f  or  %o2, %o7, %i1
a0120980:  b4 0e 60 fe  and  %i1, 0xfe, %i2
a0120984:  7f ff 45 97  call  0xa00f1fe0
a0120988:  93 e8 20 1b  restore  %g0, 0x1b, %o1
a012098c:  01 00 00 00  nop
a0120990:  81 c7 e0 08  ret
a0120994:  81 e8 00 00  restore
