# leon2m FUN_a00a9650 0xa00a9650-0xa00a9abc (1132 bytes)
a00a9650:  9d e3 bf 80  save  %sp, -128, %sp
a00a9654:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a9658:  80 a0 00 19  cmp  %g0, %i1
a00a965c:  98 60 3f ff  subx  %g0, -1, %o4
a00a9660:  90 1e 60 02  xor  %i1, 2, %o0
a00a9664:  80 a0 00 08  cmp  %g0, %o0
a00a9668:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a966c:  82 60 3f ff  subx  %g0, -1, %g1
a00a9670:  9a 04 00 10  add  %l0, %l0, %o5
a00a9674:  80 93 00 01  orcc  %o4, %g1, %g0
a00a9678:  12 80 00 a4  bne  0xa00a9908
a00a967c:  a2 03 60 05  add  %o5, 5, %l1
a00a9680:  80 a6 60 01  cmp  %i1, 1
a00a9684:  02 80 00 d5  be  0xa00a99d8
a00a9688:  80 a0 00 19  cmp  %g0, %i1
a00a968c:  b0 40 20 00  addx  %g0, 0, %i0
a00a9690:  96 1e 60 02  xor  %i1, 2, %o3
a00a9694:  80 a0 00 0b  cmp  %g0, %o3
a00a9698:  82 40 20 00  addx  %g0, 0, %g1
a00a969c:  a0 0e 00 01  and  %i0, %g1, %l0
a00a96a0:  80 a0 00 10  cmp  %g0, %l0
a00a96a4:  98 60 3f ff  subx  %g0, -1, %o4
a00a96a8:  9a 03 20 03  add  %o4, 3, %o5
a00a96ac:  b0 0b 60 ff  and  %o5, 0xff, %i0
a00a96b0:  90 10 00 18  mov  %i0, %o0
a00a96b4:  92 10 20 00  clr  %o1
a00a96b8:  40 02 75 62  call  0xa0146c40
a00a96bc:  94 10 20 00  clr  %o2
a00a96c0:  80 a4 20 00  cmp  %l0, 0
a00a96c4:  02 80 00 4a  be  0xa00a97ec
a00a96c8:  90 10 00 18  mov  %i0, %o0
a00a96cc:  92 10 20 00  clr  %o1
a00a96d0:  94 10 20 00  clr  %o2
a00a96d4:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00a96d8:  c0 23 a0 60  clr  [ %sp + 0x60 ]
a00a96dc:  c0 23 a0 64  clr  [ %sp + 0x64 ]
a00a96e0:  c0 23 a0 68  clr  [ %sp + 0x68 ]
a00a96e4:  c0 23 a0 6c  clr  [ %sp + 0x6c ]
a00a96e8:  96 10 20 00  clr  %o3
a00a96ec:  98 10 20 00  clr  %o4
a00a96f0:  40 02 73 e3  call  0xa014667c
a00a96f4:  9a 10 20 04  mov  4, %o5
a00a96f8:  80 a0 00 19  cmp  %g0, %i1
a00a96fc:  92 40 20 00  addx  %g0, 0, %o1
a00a9700:  94 1e 60 02  xor  %i1, 2, %o2
a00a9704:  80 a0 00 0a  cmp  %g0, %o2
a00a9708:  90 40 20 00  addx  %g0, 0, %o0
a00a970c:  80 8a 40 08  btst  %o1, %o0
a00a9710:  02 80 00 4a  be  0xa00a9838
a00a9714:  b4 0c 60 ff  and  %l1, 0xff, %i2
a00a9718:  9b 2e a0 03  sll  %i2, 3, %o5
a00a971c:  a0 03 40 1a  add  %o5, %i2, %l0
a00a9720:  9f 2c 20 02  sll  %l0, 2, %o7
a00a9724:  90 10 00 18  mov  %i0, %o0
a00a9728:  92 10 23 a8  mov  0x3a8, %o1
a00a972c:  98 03 e0 51  add  %o7, 0x51, %o4
a00a9730:  94 03 e0 1a  add  %o7, 0x1a, %o2
a00a9734:  96 10 24 f7  mov  0x4f7, %o3
a00a9738:  40 02 74 4e  call  0xa0146870
a00a973c:  9a 10 20 00  clr  %o5
a00a9740:  80 a0 00 19  cmp  %g0, %i1
a00a9744:  90 40 20 00  addx  %g0, 0, %o0
a00a9748:  92 1e 60 02  xor  %i1, 2, %o1
a00a974c:  80 a0 00 09  cmp  %g0, %o1
a00a9750:  b2 40 20 00  addx  %g0, 0, %i1
a00a9754:  80 8a 00 19  btst  %o0, %i1
a00a9758:  02 80 00 4a  be  0xa00a9880
a00a975c:  90 10 00 18  mov  %i0, %o0
a00a9760:  92 10 20 01  mov  1, %o1
a00a9764:  40 02 75 37  call  0xa0146c40
a00a9768:  94 10 20 00  clr  %o2
a00a976c:  90 10 20 01  mov  1, %o0
a00a9770:  92 10 20 27  mov  0x27, %o1
a00a9774:  94 10 00 1a  mov  %i2, %o2
a00a9778:  40 00 29 d6  call  0xa00b3ed0
a00a977c:  96 10 20 0e  mov  0xe, %o3
a00a9780:  94 10 20 a6  mov  0xa6, %o2
a00a9784:  23 00 00 16  sethi  %hi(0x5800), %l1
a00a9788:  d4 23 a0 5c  st  %o2, [ %sp + 0x5c ]
a00a978c:  90 10 20 00  clr  %o0
a00a9790:  92 10 20 01  mov  1, %o1
a00a9794:  94 14 60 9a  or  %l1, 0x9a, %o2
a00a9798:  96 10 20 27  mov  0x27, %o3
a00a979c:  98 10 00 1a  mov  %i2, %o4
a00a97a0:  40 00 26 d1  call  0xa00b32e4
a00a97a4:  9a 10 20 03  mov  3, %o5
a00a97a8:  b0 10 20 a9  mov  0xa9, %i0
a00a97ac:  f0 23 a0 5c  st  %i0, [ %sp + 0x5c ]
a00a97b0:  94 14 60 9a  or  %l1, 0x9a, %o2
a00a97b4:  98 10 00 1a  mov  %i2, %o4
a00a97b8:  90 10 20 00  clr  %o0
a00a97bc:  92 10 20 01  mov  1, %o1
a00a97c0:  96 10 20 34  mov  0x34, %o3
a00a97c4:  40 00 26 c8  call  0xa00b32e4
a00a97c8:  9a 10 20 03  mov  3, %o5
a00a97cc:  90 10 20 01  mov  1, %o0
a00a97d0:  92 10 20 01  mov  1, %o1
a00a97d4:  40 02 75 1b  call  0xa0146c40
a00a97d8:  94 10 20 00  clr  %o2
a00a97dc:  b0 10 20 02  mov  2, %i0
a00a97e0:  b2 10 20 01  mov  1, %i1
a00a97e4:  40 02 75 17  call  0xa0146c40
a00a97e8:  95 e8 20 00  restore  %g0, 0, %o2
a00a97ec:  92 10 20 00  clr  %o1
a00a97f0:  94 10 20 00  clr  %o2
a00a97f4:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00a97f8:  c0 23 a0 60  clr  [ %sp + 0x60 ]
a00a97fc:  c0 23 a0 64  clr  [ %sp + 0x64 ]
a00a9800:  c0 23 a0 68  clr  [ %sp + 0x68 ]
a00a9804:  c0 23 a0 6c  clr  [ %sp + 0x6c ]
a00a9808:  96 10 20 00  clr  %o3
a00a980c:  98 10 20 00  clr  %o4
a00a9810:  40 02 73 9b  call  0xa014667c
a00a9814:  9a 10 20 0c  mov  0xc, %o5
a00a9818:  80 a0 00 19  cmp  %g0, %i1
a00a981c:  92 40 20 00  addx  %g0, 0, %o1
a00a9820:  94 1e 60 02  xor  %i1, 2, %o2
a00a9824:  80 a0 00 0a  cmp  %g0, %o2
a00a9828:  90 40 20 00  addx  %g0, 0, %o0
a00a982c:  80 8a 40 08  btst  %o1, %o0
a00a9830:  12 bf ff ba  bne  0xa00a9718
a00a9834:  b4 0c 60 ff  and  %l1, 0xff, %i2
a00a9838:  97 2e a0 03  sll  %i2, 3, %o3
a00a983c:  98 02 c0 1a  add  %o3, %i2, %o4
a00a9840:  83 2b 20 02  sll  %o4, 2, %g1
a00a9844:  90 10 00 18  mov  %i0, %o0
a00a9848:  92 10 23 a8  mov  0x3a8, %o1
a00a984c:  98 00 60 55  add  %g1, 0x55, %o4
a00a9850:  94 00 60 16  add  %g1, 0x16, %o2
a00a9854:  96 10 24 f7  mov  0x4f7, %o3
a00a9858:  40 02 74 06  call  0xa0146870
a00a985c:  9a 10 20 00  clr  %o5
a00a9860:  80 a0 00 19  cmp  %g0, %i1
a00a9864:  90 40 20 00  addx  %g0, 0, %o0
a00a9868:  92 1e 60 02  xor  %i1, 2, %o1
a00a986c:  80 a0 00 09  cmp  %g0, %o1
a00a9870:  b2 40 20 00  addx  %g0, 0, %i1
a00a9874:  80 8a 00 19  btst  %o0, %i1
a00a9878:  12 bf ff ba  bne  0xa00a9760
a00a987c:  90 10 00 18  mov  %i0, %o0
a00a9880:  7f ff 9d d3  call  0xa0090fcc
a00a9884:  01 00 00 00  nop
a00a9888:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00a988c:  9f 34 20 10  srl  %l0, 0x10, %o7
a00a9890:  80 a3 e0 57  cmp  %o7, 0x57
a00a9894:  18 80 00 25  bgu  0xa00a9928
a00a9898:  b2 0c 60 ff  and  %l1, 0xff, %i1
a00a989c:  b4 10 20 00  clr  %i2
a00a98a0:  9e 0e a0 ff  and  %i2, 0xff, %o7
a00a98a4:  94 06 40 0f  add  %i1, %o7, %o2
a00a98a8:  93 2a a0 10  sll  %o2, 0x10, %o1
a00a98ac:  a3 32 60 10  srl  %o1, 0x10, %l1
a00a98b0:  90 10 20 00  clr  %o0
a00a98b4:  92 10 20 27  mov  0x27, %o1
a00a98b8:  94 10 00 11  mov  %l1, %o2
a00a98bc:  96 10 20 01  mov  1, %o3
a00a98c0:  98 10 20 00  clr  %o4
a00a98c4:  40 02 74 97  call  0xa0146b20
a00a98c8:  9a 10 20 00  clr  %o5
a00a98cc:  90 10 20 00  clr  %o0
a00a98d0:  94 10 00 11  mov  %l1, %o2
a00a98d4:  92 10 20 34  mov  0x34, %o1
a00a98d8:  96 10 20 01  mov  1, %o3
a00a98dc:  98 10 20 00  clr  %o4
a00a98e0:  40 02 74 90  call  0xa0146b20
a00a98e4:  9a 10 20 00  clr  %o5
a00a98e8:  b4 06 a0 01  inc  %i2
a00a98ec:  90 0e a0 ff  and  %i2, 0xff, %o0
a00a98f0:  80 a2 20 02  cmp  %o0, 2
a00a98f4:  08 bf ff ec  bleu  0xa00a98a4
a00a98f8:  9e 0e a0 ff  and  %i2, 0xff, %o7
a00a98fc:  b2 10 20 01  mov  1, %i1
a00a9900:  40 02 74 d0  call  0xa0146c40
a00a9904:  95 e8 20 00  restore  %g0, 0, %o2
a00a9908:  90 10 20 01  mov  1, %o0
a00a990c:  7f ff fe d7  call  0xa00a9468
a00a9910:  92 10 20 02  mov  2, %o1
a00a9914:  90 10 20 00  clr  %o0
a00a9918:  40 00 26 ef  call  0xa00b34d4
a00a991c:  92 10 20 01  mov  1, %o1
a00a9920:  10 bf ff 5b  b  0xa00a968c
a00a9924:  80 a0 00 19  cmp  %g0, %i1
a00a9928:  7f ff 9d a9  call  0xa0090fcc
a00a992c:  01 00 00 00  nop
a00a9930:  83 2a 20 10  sll  %o0, 0x10, %g1
a00a9934:  9b 30 60 10  srl  %g1, 0x10, %o5
a00a9938:  80 a3 60 5b  cmp  %o5, 0x5b
a00a993c:  38 bf ff d8  bgu,a   0xa00a989c
a00a9940:  b2 0c 60 ff  and  %l1, 0xff, %i1
a00a9944:  98 10 00 1a  mov  %i2, %o4
a00a9948:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00a994c:  90 10 20 01  mov  1, %o0
a00a9950:  92 10 20 00  clr  %o1
a00a9954:  94 10 27 92  mov  0x792, %o2
a00a9958:  96 10 20 27  mov  0x27, %o3
a00a995c:  40 00 26 62  call  0xa00b32e4
a00a9960:  9a 10 20 0e  mov  0xe, %o5
a00a9964:  96 04 60 02  add  %l1, 2, %o3
a00a9968:  98 0a e0 ff  and  %o3, 0xff, %o4
a00a996c:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00a9970:  90 10 20 01  mov  1, %o0
a00a9974:  92 10 20 00  clr  %o1
a00a9978:  94 10 27 92  mov  0x792, %o2
a00a997c:  96 10 20 27  mov  0x27, %o3
a00a9980:  40 00 26 59  call  0xa00b32e4
a00a9984:  9a 10 20 0e  mov  0xe, %o5
a00a9988:  98 04 60 01  add  %l1, 1, %o4
a00a998c:  b4 0b 20 ff  and  %o4, 0xff, %i2
a00a9990:  98 10 00 1a  mov  %i2, %o4
a00a9994:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00a9998:  90 10 20 01  mov  1, %o0
a00a999c:  92 10 20 00  clr  %o1
a00a99a0:  94 10 27 92  mov  0x792, %o2
a00a99a4:  96 10 20 27  mov  0x27, %o3
a00a99a8:  40 00 26 4f  call  0xa00b32e4
a00a99ac:  9a 10 20 01  mov  1, %o5
a00a99b0:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00a99b4:  98 10 00 1a  mov  %i2, %o4
a00a99b8:  90 10 20 01  mov  1, %o0
a00a99bc:  92 10 20 00  clr  %o1
a00a99c0:  94 10 27 92  mov  0x792, %o2
a00a99c4:  96 10 20 34  mov  0x34, %o3
a00a99c8:  40 00 26 47  call  0xa00b32e4
a00a99cc:  9a 10 20 01  mov  1, %o5
a00a99d0:  10 bf ff 85  b  0xa00a97e4
a00a99d4:  b2 10 20 01  mov  1, %i1
a00a99d8:  7f ff 9d 7d  call  0xa0090fcc
a00a99dc:  01 00 00 00  nop
a00a99e0:  95 2a 20 10  sll  %o0, 0x10, %o2
a00a99e4:  93 32 a0 10  srl  %o2, 0x10, %o1
a00a99e8:  82 02 7f c1  add  %o1, -63, %g1
a00a99ec:  80 a0 60 ba  cmp  %g1, 0xba
a00a99f0:  18 80 00 0d  bgu  0xa00a9a24
a00a99f4:  96 10 20 00  clr  %o3
a00a99f8:  19 00 01 0f  sethi  %hi(0x43c00), %o4
a00a99fc:  b5 28 60 02  sll  %g1, 2, %i2
a00a9a00:  9a 13 22 50  or  %o4, 0x250, %o5
a00a9a04:  de 03 40 1a  ld  [ %o5 + %i2 ], %o7
a00a9a08:  81 c3 c0 00  jmp  %o7
a00a9a0c:  01 00 00 00  nop
a00a9a10:  82 0e 20 ff  and  %i0, 0xff, %g1
a00a9a14:  80 a0 60 02  cmp  %g1, 2
a00a9a18:  12 80 00 04  bne  0xa00a9a28
a00a9a1c:  b0 0a e0 03  and  %o3, 3, %i0
a00a9a20:  96 10 20 01  mov  1, %o3
a00a9a24:  b0 0a e0 03  and  %o3, 3, %i0
a00a9a28:  80 a6 20 01  cmp  %i0, 1
a00a9a2c:  02 bf ff b8  be  0xa00a990c
a00a9a30:  90 10 20 01  mov  1, %o0
a00a9a34:  7f ff 9d 66  call  0xa0090fcc
a00a9a38:  01 00 00 00  nop
a00a9a3c:  91 2a 20 10  sll  %o0, 0x10, %o0
a00a9a40:  97 32 20 10  srl  %o0, 0x10, %o3
a00a9a44:  82 02 ff c1  add  %o3, -63, %g1
a00a9a48:  80 a0 60 ba  cmp  %g1, 0xba
a00a9a4c:  08 80 00 0d  bleu  0xa00a9a80
a00a9a50:  96 10 20 00  clr  %o3
a00a9a54:  80 8a e0 ff  btst  0xff, %o3
a00a9a58:  32 bf ff 0d  bne,a   0xa00a968c
a00a9a5c:  80 a0 00 19  cmp  %g0, %i1
a00a9a60:  90 10 20 01  mov  1, %o0
a00a9a64:  7f ff fe 81  call  0xa00a9468
a00a9a68:  92 10 20 03  mov  3, %o1
a00a9a6c:  90 10 20 00  clr  %o0
a00a9a70:  40 00 26 99  call  0xa00b34d4
a00a9a74:  92 10 20 04  mov  4, %o1
a00a9a78:  10 bf ff 05  b  0xa00a968c
a00a9a7c:  80 a0 00 19  cmp  %g0, %i1
a00a9a80:  35 00 01 0e  sethi  %hi(0x43800), %i2
a00a9a84:  95 28 60 02  sll  %g1, 2, %o2
a00a9a88:  9e 16 a3 64  or  %i2, 0x364, %o7
a00a9a8c:  d2 03 c0 0a  ld  [ %o7 + %o2 ], %o1
a00a9a90:  81 c2 40 00  jmp  %o1
a00a9a94:  01 00 00 00  nop
a00a9a98:  10 bf ff e3  b  0xa00a9a24
a00a9a9c:  96 10 20 02  mov  2, %o3	! 0x2
a00a9aa0:  80 a4 20 02  cmp  %l0, 2
a00a9aa4:  12 bf ff ed  bne  0xa00a9a58
a00a9aa8:  80 8a e0 ff  btst  0xff, %o3
a00a9aac:  10 bf ff ea  b  0xa00a9a54
a00a9ab0:  96 10 20 01  mov  1, %o3
a00a9ab4:  10 bf ff e8  b  0xa00a9a54
a00a9ab8:  96 10 20 02  mov  2, %o3
