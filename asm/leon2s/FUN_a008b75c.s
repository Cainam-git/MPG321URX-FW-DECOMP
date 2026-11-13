# leon2s FUN_a008b75c 0xa008b75c-0xa008b838 (220 bytes)  [FUN_a008b830 = unreachable ret/restore tail, merged]
a008b75c:  9d e3 bf 98  save  %sp, -104, %sp
a008b760:  a2 0e 20 ff  and  %i0, 0xff, %l1
a008b764:  80 a4 60 03  cmp  %l1, 3
a008b768:  18 80 00 31  bgu  0xa008b82c
a008b76c:  82 10 00 19  mov  %i1, %g1
a008b770:  92 10 20 02  mov  2, %o1
a008b774:  90 10 00 11  mov  %l1, %o0
a008b778:  b0 10 00 11  mov  %l1, %i0
a008b77c:  b2 10 20 02  mov  2, %i1
a008b780:  b4 10 20 04  mov  4, %i2
a008b784:  80 88 60 ff  btst  0xff, %g1
a008b788:  02 80 00 27  be  0xa008b824
a008b78c:  b6 10 20 00  clr  %i3
a008b790:  40 00 6e 89  call  0xa00a71b4
a008b794:  01 00 00 00  nop
a008b798:  80 8a 20 04  btst  4, %o0
a008b79c:  12 80 00 0e  bne  0xa008b7d4
a008b7a0:  92 10 20 01  mov  1, %o1
a008b7a4:  80 a0 00 11  cmp  %g0, %l1
a008b7a8:  a0 40 20 00  addx  %g0, 0, %l0
a008b7ac:  7f ff ff ba  call  0xa008b694
a008b7b0:  90 10 00 10  mov  %l0, %o0
a008b7b4:  90 10 00 11  mov  %l1, %o0
a008b7b8:  94 10 20 04  mov  4, %o2
a008b7bc:  96 10 20 04  mov  4, %o3
a008b7c0:  40 00 6e 8f  call  0xa00a71fc
a008b7c4:  92 10 20 02  mov  2, %o1
a008b7c8:  7f ff ff cb  call  0xa008b6f4
a008b7cc:  90 10 00 10  mov  %l0, %o0
a008b7d0:  92 10 20 01  mov  1, %o1
a008b7d4:  40 00 6e 78  call  0xa00a71b4
a008b7d8:  90 10 00 11  mov  %l1, %o0
a008b7dc:  82 0a 20 0e  and  %o0, 0xe, %g1
a008b7e0:  92 10 20 0f  mov  0xf, %o1
a008b7e4:  80 a0 60 02  cmp  %g1, 2
a008b7e8:  02 80 00 11  be  0xa008b82c
a008b7ec:  90 10 00 11  mov  %l1, %o0
a008b7f0:  40 00 6e 71  call  0xa00a71b4
a008b7f4:  b2 10 20 03  mov  3, %i1
a008b7f8:  82 0a 20 ff  and  %o0, 0xff, %g1
a008b7fc:  92 10 20 03  mov  3, %o1
a008b800:  94 10 20 02  mov  2, %o2
a008b804:  96 10 20 00  clr  %o3
a008b808:  90 10 00 11  mov  %l1, %o0
a008b80c:  b4 10 20 02  mov  2, %i2
a008b810:  80 a0 60 f0  cmp  %g1, 0xf0
a008b814:  12 80 00 06  bne  0xa008b82c
a008b818:  b6 10 20 02  mov  2, %i3
a008b81c:  40 00 6e 78  call  0xa00a71fc
a008b820:  b0 10 00 11  mov  %l1, %i0
a008b824:  40 00 6e 76  call  0xa00a71fc
a008b828:  81 e8 00 00  restore
a008b82c:  01 00 00 00  nop
a008b830:  81 c7 e0 08  ret
a008b834:  81 e8 00 00  restore
