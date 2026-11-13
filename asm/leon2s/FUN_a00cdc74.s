# leon2s FUN_a00cdc74 0xa00cdc74-0xa00cdcdc (104 bytes)  [FUN_a00cdcd4 = unreachable ret/restore tail, merged]
a00cdc74:  9d e3 bf 98  save  %sp, -104, %sp
a00cdc78:  90 0e 20 ff  and  %i0, 0xff, %o0
a00cdc7c:  98 02 00 08  add  %o0, %o0, %o4
a00cdc80:  98 03 00 08  add  %o4, %o0, %o4
a00cdc84:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00cdc88:  96 12 e3 b0  or  %o3, 0x3b0, %o3	! 0xa8078bb0
a00cdc8c:  99 2b 20 03  sll  %o4, 3, %o4
a00cdc90:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00cdc94:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cdc98:  82 2b 40 01  andn  %o5, %g1, %g1
a00cdc9c:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cdca0:  82 10 40 0d  or  %g1, %o5, %g1
a00cdca4:  7f ff ed b1  call  0xa00c9368
a00cdca8:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cdcac:  7f ff ee a0  call  0xa00c972c
a00cdcb0:  a0 10 00 08  mov  %o0, %l0
a00cdcb4:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00cdcb8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00cdcbc:  80 a4 00 08  cmp  %l0, %o0
a00cdcc0:  02 80 00 04  be  0xa00cdcd0
a00cdcc4:  b0 10 00 10  mov  %l0, %i0
a00cdcc8:  7f ff fb 5c  call  0xa00cca38
a00cdccc:  81 e8 00 00  restore
a00cdcd0:  01 00 00 00  nop
a00cdcd4:  81 c7 e0 08  ret
a00cdcd8:  81 e8 00 00  restore
