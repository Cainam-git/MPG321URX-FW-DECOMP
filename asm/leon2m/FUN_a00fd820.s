# leon2m FUN_a00fd820 0xa00fd820-0xa00fd980 (180 bytes)
a00fd820:  9d e3 bf 98  save  %sp, -104, %sp
a00fd824:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00fd828:  7f ff ee ab  call  0xa00f92d4
a00fd82c:  90 10 00 10  mov  %l0, %o0
a00fd830:  80 8a 20 ff  btst  0xff, %o0
a00fd834:  12 80 00 51  bne  0xa00fd978
a00fd838:  b0 10 20 e8  mov  0xe8, %i0
a00fd83c:  90 10 00 10  mov  %l0, %o0
a00fd840:  7f ff d0 94  call  0xa00f1a90
a00fd844:  92 10 20 03  mov  3, %o1
a00fd848:  80 8a 20 20  btst  0x20, %o0
a00fd84c:  02 80 00 0e  be  0xa00fd884
a00fd850:  90 10 00 10  mov  %l0, %o0
a00fd854:  7f ff d1 6e  call  0xa00f1e0c
a00fd858:  92 10 20 40  mov  0x40, %o1
a00fd85c:  90 8a 20 03  andcc  %o0, 3, %o0
a00fd860:  02 80 00 07  be  0xa00fd87c
a00fd864:  82 10 3f 91  mov  -111, %g1
a00fd868:  9a 1a 20 02  xor  %o0, 2, %o5
a00fd86c:  80 a0 00 0d  cmp  %g0, %o5
a00fd870:  90 60 20 00  subx  %g0, 0, %o0
a00fd874:  82 0a 20 10  and  %o0, 0x10, %g1
a00fd878:  82 00 7f a1  add  %g1, -95, %g1
a00fd87c:  10 80 00 3f  b  0xa00fd978
a00fd880:  b0 08 60 ff  and  %g1, 0xff, %i0
a00fd884:  7f ff d0 83  call  0xa00f1a90
a00fd888:  92 10 20 03  mov  3, %o1
a00fd88c:  80 8a 20 10  btst  0x10, %o0
a00fd890:  12 80 00 3a  bne  0xa00fd978
a00fd894:  b0 10 20 c1  mov  0xc1, %i0
a00fd898:  90 10 00 10  mov  %l0, %o0
a00fd89c:  7f ff d0 7d  call  0xa00f1a90
a00fd8a0:  92 10 20 04  mov  4, %o1
a00fd8a4:  82 0a 20 0f  and  %o0, 0xf, %g1
a00fd8a8:  80 a0 60 0f  cmp  %g1, 0xf
a00fd8ac:  38 bf ff f4  bgu,a   0xa00fd87c
a00fd8b0:  82 10 20 01  mov  1, %g1
a00fd8b4:  17 00 02 75  sethi  %hi(0x9d400), %o3
a00fd8b8:  93 28 60 02  sll  %g1, 2, %o1
a00fd8bc:  94 12 e0 d0  or  %o3, 0xd0, %o2
a00fd8c0:  d8 02 80 09  ld  [ %o2 + %o1 ], %o4
a00fd8c4:  81 c3 00 00  jmp  %o4
a00fd8c8:  01 00 00 00  nop
a00fd8cc:  10 bf ff ec  b  0xa00fd87c
a00fd8d0:  82 10 20 01  mov  1, %g1	! 0x1
a00fd8d4:  90 10 00 10  mov  %l0, %o0
a00fd8d8:  7f ff d0 6e  call  0xa00f1a90
a00fd8dc:  92 10 20 03  mov  3, %o1
a00fd8e0:  b0 0a 20 01  and  %o0, 1, %i0
a00fd8e4:  80 a0 00 18  cmp  %g0, %i0
a00fd8e8:  a0 40 3f ff  addx  %g0, -1, %l0
a00fd8ec:  9e 0c 3f f0  and  %l0, -16, %o7
a00fd8f0:  10 bf ff e3  b  0xa00fd87c
a00fd8f4:  82 03 ff 81  add  %o7, -127, %g1
a00fd8f8:  10 bf ff e1  b  0xa00fd87c
a00fd8fc:  82 10 20 61  mov  0x61, %g1
a00fd900:  10 bf ff df  b  0xa00fd87c
a00fd904:  82 10 20 51  mov  0x51, %g1
a00fd908:  10 bf ff dd  b  0xa00fd87c
a00fd90c:  82 10 20 41  mov  0x41, %g1
a00fd910:  10 bf ff db  b  0xa00fd87c
a00fd914:  82 10 20 31  mov  0x31, %g1
a00fd918:  90 10 00 10  mov  %l0, %o0
a00fd91c:  7f ff d1 a0  call  0xa00f1f9c
a00fd920:  92 10 20 00  clr  %o1
a00fd924:  80 8a 20 08  btst  8, %o0
a00fd928:  02 80 00 0b  be  0xa00fd954
a00fd92c:  19 33 c0 80  sethi  %hi(0xcf020000), %o4
a00fd930:  9a 13 21 14  or  %o4, 0x114, %o5	! 0xcf020114
a00fd934:  d0 03 40 00  ld  [ %o5 ], %o0
a00fd938:  82 0a 20 07  and  %o0, 7, %g1
a00fd93c:  b0 18 60 05  xor  %g1, 5, %i0
a00fd940:  80 a0 00 18  cmp  %g0, %i0
a00fd944:  a0 60 20 00  subx  %g0, 0, %l0
a00fd948:  9e 0c 3f f2  and  %l0, -14, %o7
a00fd94c:  10 bf ff cc  b  0xa00fd87c
a00fd950:  82 03 e0 21  add  %o7, 0x21, %g1
a00fd954:  92 10 20 54  mov  0x54, %o1
a00fd958:  7f ff d0 4e  call  0xa00f1a90
a00fd95c:  90 10 00 10  mov  %l0, %o0
a00fd960:  96 0a 20 01  and  %o0, 1, %o3
a00fd964:  80 a0 00 0b  cmp  %g0, %o3
a00fd968:  94 60 3f ff  subx  %g0, -1, %o2
a00fd96c:  92 10 20 12  mov  0x12, %o1
a00fd970:  10 bf ff c3  b  0xa00fd87c
a00fd974:  82 22 40 0a  sub  %o1, %o2, %g1
a00fd978:  81 c7 e0 08  ret
a00fd97c:  81 e8 00 00  restore
