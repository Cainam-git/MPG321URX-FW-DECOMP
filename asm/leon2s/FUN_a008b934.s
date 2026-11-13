# leon2s FUN_a008b934 0xa008b934-0xa008b9b0 (124 bytes)
a008b934:  9d e3 bf 98  save  %sp, -104, %sp
a008b938:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008b93c:  96 10 20 01  mov  1, %o3
a008b940:  90 10 00 18  mov  %i0, %o0
a008b944:  92 10 20 50  mov  0x50, %o1
a008b948:  40 00 6c d4  call  0xa00a6c98
a008b94c:  94 10 20 40  mov  0x40, %o2
a008b950:  90 10 00 18  mov  %i0, %o0
a008b954:  92 10 20 04  mov  4, %o1
a008b958:  40 00 6d 9a  call  0xa00a6fc0
a008b95c:  94 10 20 ff  mov  0xff, %o2
a008b960:  90 10 00 18  mov  %i0, %o0
a008b964:  92 10 20 03  mov  3, %o1
a008b968:  40 00 6d 96  call  0xa00a6fc0
a008b96c:  94 10 20 ff  mov  0xff, %o2
a008b970:  90 10 00 18  mov  %i0, %o0
a008b974:  92 10 20 50  mov  0x50, %o1
a008b978:  94 10 20 10  mov  0x10, %o2
a008b97c:  40 00 6c c7  call  0xa00a6c98
a008b980:  96 10 20 00  clr  %o3
a008b984:  19 2a 01 e2  sethi  %hi(0xa8078800), %o4
a008b988:  9a 10 20 01  mov  1, %o5
a008b98c:  c2 0b 23 54  ldub  [ %o4 + 0x354 ], %g1
a008b990:  9b 2b 40 18  sll  %o5, %i0, %o5
a008b994:  9a 13 40 01  or  %o5, %g1, %o5
a008b998:  82 10 20 10  mov  0x10, %g1
a008b99c:  83 28 40 18  sll  %g1, %i0, %g1
a008b9a0:  82 2b 40 01  andn  %o5, %g1, %g1
a008b9a4:  c2 2b 23 54  stb  %g1, [ %o4 + 0x354 ]
a008b9a8:  81 c7 e0 08  ret
a008b9ac:  81 e8 00 00  restore
