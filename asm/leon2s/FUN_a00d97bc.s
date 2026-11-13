# leon2s FUN_a00d97bc 0xa00d97bc-0xa00d985c (160 bytes)
a00d97bc:  9d e3 bf 80  save  %sp, -128, %sp
a00d97c0:  a0 07 bf e0  add  %fp, -32, %l0
a00d97c4:  94 10 20 13  mov  0x13, %o2
a00d97c8:  90 10 00 10  mov  %l0, %o0
a00d97cc:  40 3b 9f 83  call  0xa0fc15d8
a00d97d0:  92 10 00 18  mov  %i0, %o1
a00d97d4:  d6 0e 00 00  ldub  [ %i0 ], %o3
a00d97d8:  96 0a e0 0f  and  %o3, 0xf, %o3
a00d97dc:  82 02 ff ff  add  %o3, -1, %g1
a00d97e0:  d8 07 bf e0  ld  [ %fp + -32 ], %o4
a00d97e4:  82 08 60 0f  and  %g1, 0xf, %g1
a00d97e8:  1b 03 c0 00  sethi  %hi(0xf000000), %o5
a00d97ec:  9a 2b 00 0d  andn  %o4, %o5, %o5
a00d97f0:  83 28 60 18  sll  %g1, 0x18, %g1
a00d97f4:  9a 13 40 01  or  %o5, %g1, %o5
a00d97f8:  96 02 ff ff  add  %o3, -1, %o3
a00d97fc:  da 27 bf e0  st  %o5, [ %fp + -32 ]
a00d9800:  80 a2 e0 00  cmp  %o3, 0
a00d9804:  04 80 00 0c  ble  0xa00d9834
a00d9808:  94 10 20 00  clr  %o2
a00d980c:  92 07 bf f8  add  %fp, -8, %o1
a00d9810:  82 0a a0 ff  and  %o2, 0xff, %g1
a00d9814:  9a 06 00 01  add  %i0, %g1, %o5
a00d9818:  d8 0b 60 02  ldub  [ %o5 + 2 ], %o4
a00d981c:  94 02 a0 01  inc  %o2
a00d9820:  82 02 40 01  add  %o1, %g1, %g1
a00d9824:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00d9828:  80 a3 40 0b  cmp  %o5, %o3
a00d982c:  06 bf ff f9  bl  0xa00d9810
a00d9830:  d8 28 7f e9  stb  %o4, [ %g1 + -23 ]
a00d9834:  82 0a a0 ff  and  %o2, 0xff, %g1
a00d9838:  82 07 80 01  add  %fp, %g1, %g1
a00d983c:  c0 28 7f e1  clrb  [ %g1 + -31 ]
a00d9840:  90 10 00 10  mov  %l0, %o0
a00d9844:  92 10 20 03  mov  3, %o1
a00d9848:  7f ff f4 83  call  0xa00d6a54
a00d984c:  94 10 20 01  mov  1, %o2
a00d9850:  01 00 00 00  nop
a00d9854:  81 c7 e0 08  ret
a00d9858:  81 e8 00 00  restore
