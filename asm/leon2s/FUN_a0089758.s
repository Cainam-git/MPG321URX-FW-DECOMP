# leon2s FUN_a0089758 0xa0089758-0xa008983c (228 bytes)  [FUN_a0089834 = unreachable ret/restore tail, merged]
a0089758:  9d e3 bf 98  save  %sp, -104, %sp
a008975c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0089760:  80 a6 20 00  cmp  %i0, 0
a0089764:  12 80 00 29  bne  0xa0089808
a0089768:  b2 0e 60 ff  and  %i1, 0xff, %i1
a008976c:  80 a6 60 01  cmp  %i1, 1
a0089770:  12 80 00 11  bne  0xa00897b4
a0089774:  90 10 20 00  clr  %o0
a0089778:  92 10 20 70  mov  0x70, %o1
a008977c:  94 10 20 10  mov  0x10, %o2
a0089780:  40 00 78 70  call  0xa00a7940
a0089784:  96 10 20 01  mov  1, %o3
a0089788:  7f ff ff f2  call  0xa0089750
a008978c:  01 00 00 00  nop
a0089790:  90 0a 20 ff  and  %o0, 0xff, %o0
a0089794:  80 a2 20 01  cmp  %o0, 1
a0089798:  12 80 00 26  bne  0xa0089830
a008979c:  1b 33 c0 63  sethi  %hi(0xcf018c00), %o5
a00897a0:  9a 13 62 80  or  %o5, 0x280, %o5	! 0xcf018e80
a00897a4:  c2 03 40 00  ld  [ %o5 ], %g1
a00897a8:  82 10 60 01  or  %g1, 1, %g1
a00897ac:  c2 23 40 00  st  %g1, [ %o5 ]
a00897b0:  30 80 00 20  b,a   0xa0089830
a00897b4:  92 10 20 70  mov  0x70, %o1
a00897b8:  94 10 20 10  mov  0x10, %o2
a00897bc:  40 00 78 61  call  0xa00a7940
a00897c0:  96 10 20 00  clr  %o3
a00897c4:  7f ff f5 05  call  0xa0086bd8
a00897c8:  01 00 00 00  nop
a00897cc:  80 8a 20 ff  btst  0xff, %o0
a00897d0:  12 80 00 18  bne  0xa0089830
a00897d4:  01 00 00 00  nop
a00897d8:  7f ff ff de  call  0xa0089750
a00897dc:  01 00 00 00  nop
a00897e0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00897e4:  80 a2 20 01  cmp  %o0, 1
a00897e8:  12 80 00 12  bne  0xa0089830
a00897ec:  1b 33 c0 63  sethi  %hi(0xcf018c00), %o5
a00897f0:  9a 13 62 80  or  %o5, 0x280, %o5	! 0xcf018e80
a00897f4:  c2 03 40 00  ld  [ %o5 ], %g1
a00897f8:  82 08 7f fe  and  %g1, -2, %g1
a00897fc:  c2 23 40 00  st  %g1, [ %o5 ]
a0089800:  7f ff fd d3  call  0xa0088f4c
a0089804:  91 e8 20 01  restore  %g0, 1, %o0
a0089808:  80 a6 60 01  cmp  %i1, 1
a008980c:  12 80 00 05  bne  0xa0089820
a0089810:  b2 10 20 70  mov  0x70, %i1
a0089814:  b4 10 20 10  mov  0x10, %i2
a0089818:  10 80 00 04  b  0xa0089828
a008981c:  b6 10 20 01  mov  1, %i3
a0089820:  b4 10 20 10  mov  0x10, %i2
a0089824:  b6 10 20 00  clr  %i3
a0089828:  40 00 78 46  call  0xa00a7940
a008982c:  81 e8 00 00  restore
a0089830:  01 00 00 00  nop
a0089834:  81 c7 e0 08  ret
a0089838:  81 e8 00 00  restore
