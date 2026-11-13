# leon2s FUN_a00a14c4 0xa00a14c4-0xa00a151c (88 bytes)
a00a14c4:  9d e3 bf 98  save  %sp, -104, %sp
a00a14c8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a14cc:  21 2a 01 f6  sethi  %hi(0xa807d800), %l0
a00a14d0:  a0 14 23 00  or  %l0, 0x300, %l0	! 0xa807db00
a00a14d4:  b0 5e 20 34  smul  %i0, 0x34, %i0
a00a14d8:  d2 04 00 18  ld  [ %l0 + %i0 ], %o1
a00a14dc:  92 02 60 04  add  %o1, 4, %o1
a00a14e0:  40 00 17 b3  call  0xa00a73ac
a00a14e4:  90 10 20 09  mov  9, %o0
a00a14e8:  40 00 40 49  call  0xa00b160c
a00a14ec:  90 10 20 01  mov  1, %o0
a00a14f0:  d2 04 00 18  ld  [ %l0 + %i0 ], %o1
a00a14f4:  92 02 60 04  add  %o1, 4, %o1
a00a14f8:  40 00 17 b7  call  0xa00a73d4
a00a14fc:  90 10 20 09  mov  9, %o0
a00a1500:  40 00 40 a5  call  0xa00b1794
a00a1504:  90 10 20 01  mov  1, %o0
a00a1508:  9a 10 20 01  mov  1, %o5
a00a150c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a1510:  da 28 61 8e  stb  %o5, [ %g1 + 0x18e ]	! 0xa807918e
a00a1514:  81 c7 e0 08  ret
a00a1518:  81 e8 00 00  restore
