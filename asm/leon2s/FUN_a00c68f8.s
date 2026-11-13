# leon2s FUN_a00c68f8 0xa00c68f8-0xa00c6968 (112 bytes)
a00c68f8:  9d e3 bf 98  save  %sp, -104, %sp
a00c68fc:  03 33 c0 63  sethi  %hi(0xcf018c00), %g1
a00c6900:  11 27 c6 dd  sethi  %hi(0x9f1b7400), %o0
a00c6904:  80 8e 20 ff  btst  0xff, %i0
a00c6908:  9a 10 61 00  or  %g1, 0x100, %o5
a00c690c:  90 12 22 08  or  %o0, 0x208, %o0
a00c6910:  02 80 00 0a  be  0xa00c6938
a00c6914:  31 2a 01 e3  sethi  %hi(0xa8078c00), %i0
a00c6918:  c2 03 40 00  ld  [ %o5 ], %g1
a00c691c:  82 08 7f bf  and  %g1, -65, %g1
a00c6920:  c2 23 40 00  st  %g1, [ %o5 ]
a00c6924:  d2 03 40 00  ld  [ %o5 ], %o1
a00c6928:  40 3a f1 c7  call  0xa0f83044
a00c692c:  92 0a 60 ff  and  %o1, 0xff, %o1
a00c6930:  10 80 00 0c  b  0xa00c6960
a00c6934:  c0 2e 20 5a  clrb  [ %i0 + 0x5a ]
a00c6938:  c2 03 40 00  ld  [ %o5 ], %g1
a00c693c:  82 10 60 40  or  %g1, 0x40, %g1
a00c6940:  c2 23 40 00  st  %g1, [ %o5 ]
a00c6944:  d2 03 40 00  ld  [ %o5 ], %o1
a00c6948:  11 27 c6 dd  sethi  %hi(0x9f1b7400), %o0
a00c694c:  90 12 22 30  or  %o0, 0x230, %o0	! 0x9f1b7630
a00c6950:  40 3a f1 bd  call  0xa0f83044
a00c6954:  92 0a 60 ff  and  %o1, 0xff, %o1
a00c6958:  82 10 20 01  mov  1, %g1
a00c695c:  c2 2e 20 5a  stb  %g1, [ %i0 + 0x5a ]
a00c6960:  81 c7 e0 08  ret
a00c6964:  81 e8 00 00  restore
