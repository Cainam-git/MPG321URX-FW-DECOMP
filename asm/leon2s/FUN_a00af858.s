# leon2s FUN_a00af858 0xa00af858-0xa00af8bc (100 bytes)
a00af858:  9d e3 bf 98  save  %sp, -104, %sp
a00af85c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00af860:  7f c4 5b 71  call  0x9f1c6624
a00af864:  90 10 00 18  mov  %i0, %o0
a00af868:  92 0a 20 ff  and  %o0, 0xff, %o1
a00af86c:  7f ff f9 37  call  0xa00add48
a00af870:  90 10 00 18  mov  %i0, %o0
a00af874:  03 33 c0 49  sethi  %hi(0xcf012400), %g1
a00af878:  94 10 60 48  or  %g1, 0x48, %o2	! 0xcf012448
a00af87c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00af880:  90 0a 20 ff  and  %o0, 0xff, %o0
a00af884:  82 10 20 01  mov  1, %g1
a00af888:  99 2e 40 08  sll  %i1, %o0, %o4
a00af88c:  80 a6 60 01  cmp  %i1, 1
a00af890:  12 80 00 06  bne  0xa00af8a8
a00af894:  9b 28 40 08  sll  %g1, %o0, %o5
a00af898:  c2 02 80 00  ld  [ %o2 ], %g1
a00af89c:  82 10 40 0c  or  %g1, %o4, %g1
a00af8a0:  c2 22 80 00  st  %g1, [ %o2 ]
a00af8a4:  30 80 00 04  b,a   0xa00af8b4
a00af8a8:  c2 02 80 00  ld  [ %o2 ], %g1
a00af8ac:  82 28 40 0d  andn  %g1, %o5, %g1
a00af8b0:  c2 22 80 00  st  %g1, [ %o2 ]
a00af8b4:  81 c7 e0 08  ret
a00af8b8:  81 e8 00 00  restore
