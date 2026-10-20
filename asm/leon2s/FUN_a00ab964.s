# leon2s FUN_a00ab964 0xa00ab964-0xa00aba14 (176 bytes)
a00ab964:  82 0a 60 ff  and  %o1, 0xff, %g1
a00ab968:  80 a0 60 09  cmp  %g1, 9
a00ab96c:  18 80 00 27  bgu  0xa00aba08
a00ab970:  1b 28 02 ae  sethi  %hi(0xa00ab800), %o5
a00ab974:  83 28 60 02  sll  %g1, 2, %g1
a00ab978:  9a 13 61 3c  or  %o5, 0x13c, %o5
a00ab97c:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00ab980:  81 c0 40 00  jmp  %g1
a00ab984:  01 00 00 00  nop
a00ab988:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ab98c:  92 10 20 05  mov  5, %o1
a00ab990:  10 80 00 1b  b  0xa00ab9fc
a00ab994:  94 10 20 10  mov  0x10, %o2
a00ab998:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ab99c:  92 10 20 05  mov  5, %o1
a00ab9a0:  10 80 00 17  b  0xa00ab9fc
a00ab9a4:  94 10 20 40  mov  0x40, %o2
a00ab9a8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ab9ac:  92 10 24 e1  mov  0x4e1, %o1
a00ab9b0:  10 80 00 0d  b  0xa00ab9e4
a00ab9b4:  94 10 20 04  mov  4, %o2
a00ab9b8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ab9bc:  92 10 20 05  mov  5, %o1
a00ab9c0:  10 80 00 0f  b  0xa00ab9fc
a00ab9c4:  94 10 20 08  mov  8, %o2
a00ab9c8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ab9cc:  92 10 24 e0  mov  0x4e0, %o1
a00ab9d0:  10 80 00 05  b  0xa00ab9e4
a00ab9d4:  94 10 20 08  mov  8, %o2
a00ab9d8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ab9dc:  92 10 24 e1  mov  0x4e1, %o1
a00ab9e0:  94 10 20 01  mov  1, %o2
a00ab9e4:  82 13 c0 00  mov  %o7, %g1
a00ab9e8:  7f ff ec 86  call  0xa00a6c00
a00ab9ec:  9e 10 40 00  mov  %g1, %o7
a00ab9f0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ab9f4:  92 10 20 05  mov  5, %o1
a00ab9f8:  94 10 20 04  mov  4, %o2
a00ab9fc:  82 13 c0 00  mov  %o7, %g1
a00aba00:  7f ff ed 70  call  0xa00a6fc0
a00aba04:  9e 10 40 00  mov  %g1, %o7
a00aba08:  01 00 00 00  nop
a00aba0c:  81 c3 e0 08  retl
a00aba10:  01 00 00 00  nop
