# leon2s FUN_a00cf980 0xa00cf980-0xa00cf9e8 (104 bytes)  [FUN_a00cf9e0 = unreachable ret/restore tail, merged]
a00cf980:  9d e3 bf 98  save  %sp, -104, %sp
a00cf984:  90 0e 20 ff  and  %i0, 0xff, %o0
a00cf988:  98 02 00 08  add  %o0, %o0, %o4
a00cf98c:  98 03 00 08  add  %o4, %o0, %o4
a00cf990:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00cf994:  96 12 e3 b0  or  %o3, 0x3b0, %o3	! 0xa8078bb0
a00cf998:  99 2b 20 03  sll  %o4, 3, %o4
a00cf99c:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00cf9a0:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cf9a4:  82 2b 40 01  andn  %o5, %g1, %g1
a00cf9a8:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cf9ac:  82 10 40 0d  or  %g1, %o5, %g1
a00cf9b0:  7f ff e6 6e  call  0xa00c9368
a00cf9b4:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cf9b8:  7f ff e7 5d  call  0xa00c972c
a00cf9bc:  a0 10 00 08  mov  %o0, %l0
a00cf9c0:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00cf9c4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00cf9c8:  80 a4 00 08  cmp  %l0, %o0
a00cf9cc:  02 80 00 04  be  0xa00cf9dc
a00cf9d0:  b0 10 00 10  mov  %l0, %i0
a00cf9d4:  7f ff f4 19  call  0xa00cca38
a00cf9d8:  81 e8 00 00  restore
a00cf9dc:  01 00 00 00  nop
a00cf9e0:  81 c7 e0 08  ret
a00cf9e4:  81 e8 00 00  restore
