# leon2m FUN_a00d9764 0xa00d9764-0xa00d9978 (464 bytes)
a00d9764:  9d e3 bf 98  save  %sp, -104, %sp
a00d9768:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00d976c:  82 14 a2 90  or  %l2, 0x290, %g1	! 0xa802d290
a00d9770:  e2 08 60 11  ldub  [ %g1 + 0x11 ], %l1
a00d9774:  80 a4 60 0e  cmp  %l1, 0xe
a00d9778:  38 80 00 02  bgu,a   0xa00d9780
a00d977c:  a2 10 20 0e  mov  0xe, %l1
a00d9780:  e2 28 60 11  stb  %l1, [ %g1 + 0x11 ]
a00d9784:  90 10 20 00  clr  %o0
a00d9788:  40 01 b1 d8  call  0xa0145ee8
a00d978c:  92 10 20 00  clr  %o1
a00d9790:  40 01 c9 78  call  0xa014bd70
a00d9794:  90 10 20 00  clr  %o0
a00d9798:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d979c:  80 a2 20 01  cmp  %o0, 1
a00d97a0:  02 80 00 44  be  0xa00d98b0
a00d97a4:  90 10 20 00  clr  %o0
a00d97a8:  40 01 a8 4d  call  0xa01438dc
a00d97ac:  90 10 20 00  clr  %o0
a00d97b0:  82 0a 20 ff  and  %o0, 0xff, %g1
a00d97b4:  80 a0 60 01  cmp  %g1, 1
a00d97b8:  02 80 00 30  be  0xa00d9878
a00d97bc:  a0 14 a2 90  or  %l2, 0x290, %l0
a00d97c0:  d2 0c 20 12  ldub  [ %l0 + 0x12 ], %o1
a00d97c4:  80 a2 60 64  cmp  %o1, 0x64
a00d97c8:  38 80 00 02  bgu,a   0xa00d97d0
a00d97cc:  92 10 20 64  mov  0x64, %o1
a00d97d0:  d2 2c 20 12  stb  %o1, [ %l0 + 0x12 ]
a00d97d4:  92 0a 60 ff  and  %o1, 0xff, %o1
a00d97d8:  40 01 c2 51  call  0xa014a11c
a00d97dc:  90 10 20 00  clr  %o0
a00d97e0:  d2 0c 20 13  ldub  [ %l0 + 0x13 ], %o1
a00d97e4:  80 a2 60 64  cmp  %o1, 0x64
a00d97e8:  38 80 00 02  bgu,a   0xa00d97f0
a00d97ec:  92 10 20 64  mov  0x64, %o1
a00d97f0:  d2 2c 20 13  stb  %o1, [ %l0 + 0x13 ]
a00d97f4:  92 0a 60 ff  and  %o1, 0xff, %o1
a00d97f8:  40 01 c2 49  call  0xa014a11c
a00d97fc:  90 10 20 01  mov  1, %o0
a00d9800:  d2 0c 20 14  ldub  [ %l0 + 0x14 ], %o1
a00d9804:  80 a2 60 64  cmp  %o1, 0x64
a00d9808:  38 80 00 02  bgu,a   0xa00d9810
a00d980c:  92 10 20 64  mov  0x64, %o1
a00d9810:  d2 2c 20 14  stb  %o1, [ %l0 + 0x14 ]
a00d9814:  92 0a 60 ff  and  %o1, 0xff, %o1
a00d9818:  40 01 c2 41  call  0xa014a11c
a00d981c:  90 10 20 02  mov  2, %o0
a00d9820:  7f ff ff 37  call  0xa00d94fc
a00d9824:  01 00 00 00  nop
a00d9828:  82 0c 60 ff  and  %l1, 0xff, %g1
a00d982c:  80 a0 60 09  cmp  %g1, 9
a00d9830:  18 80 00 09  bgu  0xa00d9854
a00d9834:  90 10 20 04  mov  4, %o0
a00d9838:  15 00 01 ce  sethi  %hi(0x73800), %o2
a00d983c:  93 28 60 02  sll  %g1, 2, %o1
a00d9840:  9a 12 a3 1c  or  %o2, 0x31c, %o5
a00d9844:  d8 03 40 09  ld  [ %o5 + %o1 ], %o4
a00d9848:  81 c3 00 00  jmp  %o4
a00d984c:  01 00 00 00  nop
a00d9850:  90 10 20 04  mov  4, %o0	! 0x4
a00d9854:  9a 14 a2 90  or  %l2, 0x290, %o5
a00d9858:  d6 0b 60 11  ldub  [ %o5 + 0x11 ], %o3
a00d985c:  80 a2 e0 01  cmp  %o3, 1
a00d9860:  22 80 00 1e  be,a   0xa00d98d8
a00d9864:  d8 0b 61 81  ldub  [ %o5 + 0x181 ], %o4
a00d9868:  40 01 cb c4  call  0xa014c778
a00d986c:  90 0a 20 1f  and  %o0, 0x1f, %o0
a00d9870:  7f ff ff 23  call  0xa00d94fc
a00d9874:  81 e8 00 00  restore
a00d9878:  40 01 c8 7c  call  0xa014ba68
a00d987c:  01 00 00 00  nop
a00d9880:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d9884:  80 a2 20 02  cmp  %o0, 2
a00d9888:  22 80 00 0a  be,a   0xa00d98b0
a00d988c:  90 10 20 00  clr  %o0
a00d9890:  04 80 00 32  ble  0xa00d9958
a00d9894:  80 a2 20 01  cmp  %o0, 1
a00d9898:  80 a2 20 03  cmp  %o0, 3
a00d989c:  02 80 00 04  be  0xa00d98ac
a00d98a0:  80 a2 20 04  cmp  %o0, 4
a00d98a4:  12 bf ff c7  bne  0xa00d97c0
a00d98a8:  a0 14 a2 90  or  %l2, 0x290, %l0
a00d98ac:  90 10 20 00  clr  %o0
a00d98b0:  40 01 c2 1b  call  0xa014a11c
a00d98b4:  92 10 20 64  mov  0x64, %o1
a00d98b8:  90 10 20 01  mov  1, %o0
a00d98bc:  40 01 c2 18  call  0xa014a11c
a00d98c0:  92 10 20 64  mov  0x64, %o1
a00d98c4:  90 10 20 02  mov  2, %o0
a00d98c8:  40 01 c2 15  call  0xa014a11c
a00d98cc:  92 10 20 64  mov  0x64, %o1
a00d98d0:  10 bf ff d7  b  0xa00d982c
a00d98d4:  82 0c 60 ff  and  %l1, 0xff, %g1
a00d98d8:  80 a3 20 03  cmp  %o4, 3
a00d98dc:  08 bf ff e3  bleu  0xa00d9868
a00d98e0:  80 a3 20 06  cmp  %o4, 6
a00d98e4:  18 bf ff e1  bgu  0xa00d9868
a00d98e8:  01 00 00 00  nop
a00d98ec:  de 03 60 a8  ld  [ %o5 + 0xa8 ], %o7
a00d98f0:  80 8b e8 00  btst  0x800, %o7
a00d98f4:  02 bf ff dd  be  0xa00d9868
a00d98f8:  80 a3 20 04  cmp  %o4, 4
a00d98fc:  02 80 00 1b  be  0xa00d9968
a00d9900:  80 a3 20 05  cmp  %o4, 5
a00d9904:  02 80 00 1b  be  0xa00d9970
a00d9908:  80 a3 20 06  cmp  %o4, 6
a00d990c:  22 bf ff d7  be,a   0xa00d9868
a00d9910:  90 10 20 11  mov  0x11, %o0
a00d9914:  30 bf ff d5  b,a   0xa00d9868
a00d9918:  10 bf ff cf  b  0xa00d9854
a00d991c:  90 10 20 0f  mov  0xf, %o0
a00d9920:  10 bf ff cd  b  0xa00d9854
a00d9924:  90 10 20 08  mov  8, %o0
a00d9928:  10 bf ff cb  b  0xa00d9854
a00d992c:  90 10 20 06  mov  6, %o0
a00d9930:  10 bf ff c9  b  0xa00d9854
a00d9934:  90 10 20 05  mov  5, %o0
a00d9938:  10 bf ff c7  b  0xa00d9854
a00d993c:  90 10 20 18  mov  0x18, %o0
a00d9940:  10 bf ff c5  b  0xa00d9854
a00d9944:  90 10 20 17  mov  0x17, %o0
a00d9948:  10 bf ff c3  b  0xa00d9854
a00d994c:  90 10 20 01  mov  1, %o0
a00d9950:  10 bf ff c1  b  0xa00d9854
a00d9954:  90 10 20 07  mov  7, %o0
a00d9958:  12 bf ff 9a  bne  0xa00d97c0
a00d995c:  a0 14 a2 90  or  %l2, 0x290, %l0
a00d9960:  10 bf ff d4  b  0xa00d98b0
a00d9964:  90 10 20 00  clr  %o0
a00d9968:  10 bf ff c0  b  0xa00d9868
a00d996c:  90 10 20 0f  mov  0xf, %o0
a00d9970:  10 bf ff be  b  0xa00d9868
a00d9974:  90 10 20 10  mov  0x10, %o0
