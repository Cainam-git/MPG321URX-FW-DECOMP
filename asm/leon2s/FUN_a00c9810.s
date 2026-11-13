# leon2s FUN_a00c9810 0xa00c9810-0xa00c9968 (344 bytes)
a00c9810:  9d e3 bf 98  save  %sp, -104, %sp
a00c9814:  40 3b df e0  call  0xa0fc1794
a00c9818:  90 10 20 02  mov  2, %o0
a00c981c:  92 10 20 00  clr  %o1
a00c9820:  94 10 20 f4  mov  0xf4, %o2
a00c9824:  40 3b b9 ed  call  0xa0fb7fd8
a00c9828:  90 0e 20 ff  and  %i0, 0xff, %o0
a00c982c:  93 2e a0 10  sll  %i2, 0x10, %o1
a00c9830:  83 32 60 14  srl  %o1, 0x14, %g1
a00c9834:  d0 2e 40 00  stb  %o0, [ %i1 ]
a00c9838:  82 00 60 01  inc  %g1
a00c983c:  11 27 c7 08  sethi  %hi(0x9f1c2000), %o0
a00c9840:  a0 10 00 01  mov  %g1, %l0
a00c9844:  90 12 20 f8  or  %o0, 0xf8, %o0
a00c9848:  93 32 60 10  srl  %o1, 0x10, %o1
a00c984c:  aa 10 00 01  mov  %g1, %l5
a00c9850:  40 3a e5 fd  call  0xa0f83044
a00c9854:  94 10 00 01  mov  %g1, %o2
a00c9858:  80 a4 20 00  cmp  %l0, 0
a00c985c:  ae 10 20 14  mov  0x14, %l7
a00c9860:  a6 10 20 00  clr  %l3
a00c9864:  a4 10 20 00  clr  %l2
a00c9868:  a2 10 20 00  clr  %l1
a00c986c:  02 80 00 3d  be  0xa00c9960
a00c9870:  ac 10 20 00  clr  %l6
a00c9874:  a8 0e 20 ff  and  %i0, 0xff, %l4
a00c9878:  90 10 00 14  mov  %l4, %o0
a00c987c:  92 10 20 00  clr  %o1
a00c9880:  40 3b b9 d6  call  0xa0fb7fd8
a00c9884:  94 10 20 f5  mov  0xf5, %o2
a00c9888:  83 2e a0 10  sll  %i2, 0x10, %g1
a00c988c:  83 30 60 10  srl  %g1, 0x10, %g1
a00c9890:  80 a0 60 10  cmp  %g1, 0x10
a00c9894:  18 80 00 05  bgu  0xa00c98a8
a00c9898:  90 0a 20 1f  and  %o0, 0x1f, %o0
a00c989c:  82 00 7f ff  add  %g1, -1, %g1
a00c98a0:  10 80 00 03  b  0xa00c98ac
a00c98a4:  80 a2 00 01  cmp  %o0, %g1
a00c98a8:  80 a2 20 10  cmp  %o0, 0x10
a00c98ac:  32 bf ff f3  bne,a   0xa00c9878
a00c98b0:  a8 0e 20 ff  and  %i0, 0xff, %l4
a00c98b4:  9a 05 ff ff  add  %l7, -1, %o5
a00c98b8:  82 0b 60 ff  and  %o5, 0xff, %g1
a00c98bc:  80 a0 60 ff  cmp  %g1, 0xff
a00c98c0:  12 bf ff ed  bne  0xa00c9874
a00c98c4:  ae 10 00 0d  mov  %o5, %l7
a00c98c8:  a0 10 20 00  clr  %l0
a00c98cc:  90 10 00 14  mov  %l4, %o0
a00c98d0:  92 10 20 00  clr  %o1
a00c98d4:  40 3b b9 c1  call  0xa0fb7fd8
a00c98d8:  94 10 20 f4  mov  0xf4, %o2
a00c98dc:  82 04 7f 75  add  %l1, -139, %g1
a00c98e0:  83 28 60 10  sll  %g1, 0x10, %g1
a00c98e4:  9a 10 00 12  mov  %l2, %o5
a00c98e8:  83 30 60 10  srl  %g1, 0x10, %g1
a00c98ec:  9b 2b 60 10  sll  %o5, 0x10, %o5
a00c98f0:  98 0c e0 ff  and  %l3, 0xff, %o4
a00c98f4:  80 a0 61 7f  cmp  %g1, 0x17f
a00c98f8:  08 80 00 05  bleu  0xa00c990c
a00c98fc:  9b 33 60 10  srl  %o5, 0x10, %o5
a00c9900:  d0 2e 40 0c  stb  %o0, [ %i1 + %o4 ]
a00c9904:  10 80 00 06  b  0xa00c991c
a00c9908:  a6 04 e0 01  inc  %l3
a00c990c:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00c9910:  82 10 63 08  or  %g1, 0x308, %g1	! 0xa807cf08
a00c9914:  a4 04 a0 01  inc  %l2
a00c9918:  d0 28 40 0d  stb  %o0, [ %g1 + %o5 ]
a00c991c:  9a 06 bf ff  add  %i2, -1, %o5
a00c9920:  a0 04 20 01  inc  %l0
a00c9924:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c9928:  98 0c 20 ff  and  %l0, 0xff, %o4
a00c992c:  80 a0 60 00  cmp  %g1, 0
a00c9930:  a2 04 60 01  inc  %l1
a00c9934:  02 80 00 0b  be  0xa00c9960
a00c9938:  b4 10 00 0d  mov  %o5, %i2
a00c993c:  80 a3 20 0f  cmp  %o4, 0xf
a00c9940:  08 bf ff e4  bleu  0xa00c98d0
a00c9944:  90 10 00 14  mov  %l4, %o0
a00c9948:  98 05 a0 01  add  %l6, 1, %o4
a00c994c:  9b 2b 20 10  sll  %o4, 0x10, %o5
a00c9950:  83 2d 60 10  sll  %l5, 0x10, %g1
a00c9954:  80 a0 40 0d  cmp  %g1, %o5
a00c9958:  18 bf ff c7  bgu  0xa00c9874
a00c995c:  ac 10 00 0c  mov  %o4, %l6
a00c9960:  81 c7 e0 08  ret
a00c9964:  81 e8 00 00  restore
