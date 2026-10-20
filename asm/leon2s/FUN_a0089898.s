# leon2s FUN_a0089898 0xa0089898-0xa008996c (212 bytes)
a0089898:  9d e3 bf 98  save  %sp, -104, %sp
a008989c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00898a0:  92 10 20 50  mov  0x50, %o1
a00898a4:  40 00 78 6e  call  0xa00a7a5c
a00898a8:  90 10 00 10  mov  %l0, %o0
a00898ac:  a2 10 00 08  mov  %o0, %l1
a00898b0:  92 10 20 53  mov  0x53, %o1
a00898b4:  40 00 78 00  call  0xa00a78b4
a00898b8:  90 10 00 10  mov  %l0, %o0
a00898bc:  b0 0a 20 ff  and  %o0, 0xff, %i0
a00898c0:  92 10 20 54  mov  0x54, %o1
a00898c4:  40 00 77 fc  call  0xa00a78b4
a00898c8:  90 10 00 10  mov  %l0, %o0
a00898cc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00898d0:  b1 2e 20 08  sll  %i0, 8, %i0
a00898d4:  b0 16 00 08  or  %i0, %o0, %i0
a00898d8:  90 10 00 10  mov  %l0, %o0
a00898dc:  40 00 77 f6  call  0xa00a78b4
a00898e0:  92 10 20 55  mov  0x55, %o1
a00898e4:  b1 2e 20 08  sll  %i0, 8, %i0
a00898e8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00898ec:  b0 96 00 08  orcc  %i0, %o0, %i0
a00898f0:  22 80 00 02  be,a   0xa00898f8
a00898f4:  b0 10 20 01  mov  1, %i0
a00898f8:  90 10 00 10  mov  %l0, %o0
a00898fc:  40 00 77 ee  call  0xa00a78b4
a0089900:  92 10 20 02  mov  2, %o1
a0089904:  90 0a 20 ff  and  %o0, 0xff, %o0
a0089908:  80 a2 20 0a  cmp  %o0, 0xa
a008990c:  02 80 00 0f  be  0xa0089948
a0089910:  82 5c 61 0e  smul  %l1, 0x10e, %g1
a0089914:  80 a2 20 0a  cmp  %o0, 0xa
a0089918:  14 80 00 07  bg  0xa0089934
a008991c:  80 a2 20 14  cmp  %o0, 0x14
a0089920:  80 a2 20 06  cmp  %o0, 6
a0089924:  02 80 00 09  be  0xa0089948
a0089928:  82 5c 60 a2  smul  %l1, 0xa2, %g1
a008992c:  10 80 00 07  b  0xa0089948
a0089930:  82 5c 62 1c  smul  %l1, 0x21c, %g1
a0089934:  02 80 00 04  be  0xa0089944
a0089938:  80 a2 20 1e  cmp  %o0, 0x1e
a008993c:  02 80 00 03  be  0xa0089948
a0089940:  82 5c 63 2a  smul  %l1, 0x32a, %g1
a0089944:  82 5c 62 1c  smul  %l1, 0x21c, %g1
a0089948:  81 80 00 00  mov  %g0, %y
a008994c:  01 00 00 00  nop
a0089950:  01 00 00 00  nop
a0089954:  01 00 00 00  nop
a0089958:  82 70 40 18  udiv  %g1, %i0, %g1
a008995c:  b1 28 60 10  sll  %g1, 0x10, %i0
a0089960:  b1 36 20 10  srl  %i0, 0x10, %i0
a0089964:  81 c7 e0 08  ret
a0089968:  81 e8 00 00  restore
