# leon2m FUN_a010a8f0 0xa010a8f0-0xa010a9e8 (248 bytes)
a010a8f0:  9d e3 bf 98  save  %sp, -104, %sp
a010a8f4:  31 33 c0 46  sethi  %hi(0xcf011800), %i0
a010a8f8:  82 16 22 80  or  %i0, 0x280, %g1	! 0xcf011a80
a010a8fc:  da 00 40 00  ld  [ %g1 ], %o5
a010a900:  11 33 c0 47  sethi  %hi(0xcf011c00), %o0
a010a904:  80 8b 60 80  btst  0x80, %o5
a010a908:  02 80 00 25  be  0xa010a99c
a010a90c:  90 12 20 30  or  %o0, 0x30, %o0
a010a910:  40 00 49 9e  call  0xa011cf88
a010a914:  01 00 00 00  nop
a010a918:  92 0a 20 ff  and  %o0, 0xff, %o1
a010a91c:  80 a2 60 82  cmp  %o1, 0x82
a010a920:  08 80 00 07  bleu  0xa010a93c
a010a924:  19 33 c0 47  sethi  %hi(0xcf011c00), %o4
a010a928:  96 13 22 40  or  %o4, 0x240, %o3	! 0xcf011e40
a010a92c:  d4 02 c0 00  ld  [ %o3 ], %o2
a010a930:  80 8a a0 08  btst  8, %o2
a010a934:  12 80 00 27  bne  0xa010a9d0
a010a938:  01 00 00 00  nop
a010a93c:  40 00 49 93  call  0xa011cf88
a010a940:  01 00 00 00  nop
a010a944:  9e 0a 20 ff  and  %o0, 0xff, %o7
a010a948:  80 a3 e0 83  cmp  %o7, 0x83
a010a94c:  08 80 00 07  bleu  0xa010a968
a010a950:  11 33 c0 47  sethi  %hi(0xcf011c00), %o0
a010a954:  9a 12 22 40  or  %o0, 0x240, %o5	! 0xcf011e40
a010a958:  f0 03 40 00  ld  [ %o5 ], %i0
a010a95c:  80 8e 20 04  btst  4, %i0
a010a960:  12 80 00 13  bne  0xa010a9ac
a010a964:  03 33 c0 46  sethi  %hi(0xcf011800), %g1
a010a968:  40 00 49 88  call  0xa011cf88
a010a96c:  01 00 00 00  nop
a010a970:  92 0a 20 ff  and  %o0, 0xff, %o1
a010a974:  80 a2 60 83  cmp  %o1, 0x83
a010a978:  08 80 00 07  bleu  0xa010a994
a010a97c:  19 33 c0 47  sethi  %hi(0xcf011c00), %o4
a010a980:  96 13 22 40  or  %o4, 0x240, %o3	! 0xcf011e40
a010a984:  d4 02 c0 00  ld  [ %o3 ], %o2
a010a988:  80 8a a0 02  btst  2, %o2
a010a98c:  12 80 00 0c  bne  0xa010a9bc
a010a990:  1f 33 c0 46  sethi  %hi(0xcf011800), %o7
a010a994:  31 33 c0 46  sethi  %hi(0xcf011800), %i0
a010a998:  90 16 22 f8  or  %i0, 0x2f8, %o0	! 0xcf011af8
a010a99c:  7f ff a1 b7  call  0xa00f3078
a010a9a0:  01 00 00 00  nop
a010a9a4:  10 80 00 0e  b  0xa010a9dc
a010a9a8:  91 2a 20 10  sll  %o0, 0x10, %o0
a010a9ac:  7f ff a1 b3  call  0xa00f3078
a010a9b0:  90 10 62 f8  or  %g1, 0x2f8, %o0
a010a9b4:  10 80 00 0a  b  0xa010a9dc
a010a9b8:  91 2a 20 12  sll  %o0, 0x12, %o0
a010a9bc:  90 13 e2 f8  or  %o7, 0x2f8, %o0
a010a9c0:  7f ff a1 ae  call  0xa00f3078
a010a9c4:  01 00 00 00  nop
a010a9c8:  10 80 00 05  b  0xa010a9dc
a010a9cc:  91 2a 20 13  sll  %o0, 0x13, %o0
a010a9d0:  7f ff a1 aa  call  0xa00f3078
a010a9d4:  90 16 22 f8  or  %i0, 0x2f8, %o0
a010a9d8:  91 2a 20 11  sll  %o0, 0x11, %o0
a010a9dc:  b1 32 20 10  srl  %o0, 0x10, %i0
a010a9e0:  81 c7 e0 08  ret
a010a9e4:  81 e8 00 00  restore
