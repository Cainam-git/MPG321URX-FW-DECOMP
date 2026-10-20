# leon2s FUN_a009498c 0xa009498c-0xa0094a10 (132 bytes)  [FUN_a0094a08 = unreachable ret/restore tail, merged]
a009498c:  9d e3 bf 98  save  %sp, -104, %sp
a0094990:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0094994:  83 2e 20 03  sll  %i0, 3, %g1
a0094998:  82 20 40 18  sub  %g1, %i0, %g1
a009499c:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00949a0:  a2 13 61 80  or  %o5, 0x180, %l1	! 0xa807d580
a00949a4:  a1 28 60 02  sll  %g1, 2, %l0
a00949a8:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00949ac:  90 10 00 18  mov  %i0, %o0
a00949b0:  92 10 20 03  mov  3, %o1
a00949b4:  94 10 20 f1  mov  0xf1, %o2
a00949b8:  96 10 20 01  mov  1, %o3
a00949bc:  98 10 20 01  mov  1, %o4
a00949c0:  b2 10 20 03  mov  3, %i1
a00949c4:  b4 10 20 f2  mov  0xf2, %i2
a00949c8:  b6 10 20 01  mov  1, %i3
a00949cc:  80 88 60 04  btst  4, %g1
a00949d0:  02 80 00 09  be  0xa00949f4
a00949d4:  b8 10 20 00  clr  %i4
a00949d8:  40 00 4d bd  call  0xa00a80cc
a00949dc:  b8 10 20 01  mov  1, %i4
a00949e0:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00949e4:  80 88 60 10  btst  0x10, %g1
a00949e8:  12 80 00 07  bne  0xa0094a04
a00949ec:  01 00 00 00  nop
a00949f0:  30 80 00 03  b,a   0xa00949fc
a00949f4:  40 00 4d b6  call  0xa00a80cc
a00949f8:  98 10 20 00  clr  %o4
a00949fc:  40 00 4d b4  call  0xa00a80cc
a0094a00:  81 e8 00 00  restore
a0094a04:  01 00 00 00  nop
a0094a08:  81 c7 e0 08  ret
a0094a0c:  81 e8 00 00  restore
