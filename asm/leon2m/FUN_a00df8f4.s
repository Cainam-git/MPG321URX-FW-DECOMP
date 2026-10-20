# leon2m FUN_a00df8f4 0xa00df8f4-0xa00dfa10 (132 bytes)
a00df8f4:  9d e3 bf 98  save  %sp, -104, %sp
a00df8f8:  80 a6 20 02  cmp  %i0, 2
a00df8fc:  18 80 00 04  bgu  0xa00df90c
a00df900:  a0 10 20 00  clr  %l0
a00df904:  10 80 00 41  b  0xa00dfa08
a00df908:  a0 10 20 01  mov  1, %l0
a00df90c:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00df910:  da 02 e1 30  ld  [ %o3 + 0x130 ], %o5	! 0xa802b530
a00df914:  03 00 06 64  sethi  %hi(0x199000), %g1
a00df918:  80 a3 60 0c  cmp  %o5, 0xc
a00df91c:  18 80 00 0a  bgu  0xa00df944
a00df920:  92 10 62 88  or  %g1, 0x288, %o1
a00df924:  91 2b 60 02  sll  %o5, 2, %o0
a00df928:  13 00 01 fd  sethi  %hi(0x7f400), %o1
a00df92c:  9a 12 62 cc  or  %o1, 0x2cc, %o5	! 0x7f6cc
a00df930:  d8 03 40 08  ld  [ %o5 + %o0 ], %o4
a00df934:  81 c3 00 00  jmp  %o4
a00df938:  01 00 00 00  nop
a00df93c:  1b 00 06 64  sethi  %hi(0x199000), %o5
a00df940:  92 13 62 90  or  %o5, 0x290, %o1	! 0x199290
a00df944:  9e 12 e1 30  or  %o3, 0x130, %o7
a00df948:  03 00 06 64  sethi  %hi(0x199000), %g1
a00df94c:  d6 03 e0 08  ld  [ %o7 + 8 ], %o3
a00df950:  d4 03 e0 04  ld  [ %o7 + 4 ], %o2
a00df954:  7f ff fe 07  call  0xa00df170
a00df958:  90 10 62 98  or  %g1, 0x298, %o0
a00df95c:  40 00 04 9f  call  0xa00e0bd8
a00df960:  01 00 00 00  nop
a00df964:  17 00 06 64  sethi  %hi(0x199000), %o3
a00df968:  90 12 e3 28  or  %o3, 0x328, %o0	! 0x199328
a00df96c:  7f ff fe 01  call  0xa00df170
a00df970:  92 10 00 18  mov  %i0, %o1
a00df974:  30 80 00 25  b,a   0xa00dfa08
a00df978:  15 00 06 64  sethi  %hi(0x199000), %o2
a00df97c:  10 bf ff f2  b  0xa00df944
a00df980:  92 12 a2 b0  or  %o2, 0x2b0, %o1	! 0x1992b0
a00df984:  15 00 06 64  sethi  %hi(0x199000), %o2
a00df988:  10 bf ff ef  b  0xa00df944
a00df98c:  92 12 a3 20  or  %o2, 0x320, %o1	! 0x199320
a00df990:  1f 00 06 64  sethi  %hi(0x199000), %o7
a00df994:  10 bf ff ec  b  0xa00df944
a00df998:  92 13 e3 10  or  %o7, 0x310, %o1	! 0x199310
a00df99c:  03 00 06 64  sethi  %hi(0x199000), %g1
a00df9a0:  10 bf ff e9  b  0xa00df944
a00df9a4:  92 10 63 08  or  %g1, 0x308, %o1	! 0x199308
a00df9a8:  19 00 06 64  sethi  %hi(0x199000), %o4
a00df9ac:  10 bf ff e6  b  0xa00df944
a00df9b0:  92 13 23 00  or  %o4, 0x300, %o1	! 0x199300
a00df9b4:  11 00 06 64  sethi  %hi(0x199000), %o0
a00df9b8:  10 bf ff e3  b  0xa00df944
a00df9bc:  92 12 22 f8  or  %o0, 0x2f8, %o1	! 0x1992f8
a00df9c0:  1b 00 06 64  sethi  %hi(0x199000), %o5
a00df9c4:  10 bf ff e0  b  0xa00df944
a00df9c8:  92 13 62 f0  or  %o5, 0x2f0, %o1	! 0x1992f0
a00df9cc:  15 00 06 64  sethi  %hi(0x199000), %o2
a00df9d0:  10 bf ff dd  b  0xa00df944
a00df9d4:  92 12 a2 e8  or  %o2, 0x2e8, %o1	! 0x1992e8
a00df9d8:  1f 00 06 64  sethi  %hi(0x199000), %o7
a00df9dc:  10 bf ff da  b  0xa00df944
a00df9e0:  92 13 e2 d8  or  %o7, 0x2d8, %o1	! 0x1992d8
a00df9e4:  03 00 06 64  sethi  %hi(0x199000), %g1
a00df9e8:  10 bf ff d7  b  0xa00df944
a00df9ec:  92 10 62 d0  or  %g1, 0x2d0, %o1	! 0x1992d0
a00df9f0:  19 00 06 64  sethi  %hi(0x199000), %o4
a00df9f4:  10 bf ff d4  b  0xa00df944
a00df9f8:  92 13 22 c8  or  %o4, 0x2c8, %o1	! 0x1992c8
a00df9fc:  11 00 06 64  sethi  %hi(0x199000), %o0
a00dfa00:  10 bf ff d1  b  0xa00df944
a00dfa04:  92 12 22 b8  or  %o0, 0x2b8, %o1	! 0x1992b8
a00dfa08:  81 c7 e0 08  ret
a00dfa0c:  91 e8 00 10  restore  %g0, %l0, %o0
