# leon2s FUN_a00624b4 0xa00624b4-0xa006250c (88 bytes)
a00624b4:  9d e3 bf 98  save  %sp, -104, %sp
a00624b8:  23 2a 01 e2  sethi  %hi(0xa8078800), %l1
a00624bc:  c2 0c 62 3a  ldub  [ %l1 + 0x23a ], %g1	! 0xa8078a3a
a00624c0:  80 a0 60 00  cmp  %g1, 0
a00624c4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00624c8:  e0 00 62 3c  ld  [ %g1 + 0x23c ], %l0	! 0xa8078a3c
a00624cc:  02 80 00 0e  be  0xa0062504
a00624d0:  b0 10 20 00  clr  %i0
a00624d4:  40 01 3e e4  call  0xa00b2064
a00624d8:  01 00 00 00  nop
a00624dc:  9a 22 00 10  sub  %o0, %l0, %o5
a00624e0:  80 a2 00 10  cmp  %o0, %l0
a00624e4:  1a 80 00 03  bcc  0xa00624f0
a00624e8:  82 10 00 0d  mov  %o5, %g1
a00624ec:  82 03 7f ff  add  %o5, -1, %g1
a00624f0:  80 a0 60 c8  cmp  %g1, 0xc8
a00624f4:  38 80 00 02  bgu,a   0xa00624fc
a00624f8:  c0 2c 62 3a  clrb  [ %l1 + 0x23a ]
a00624fc:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0062500:  f0 08 62 3a  ldub  [ %g1 + 0x23a ], %i0	! 0xa8078a3a
a0062504:  81 c7 e0 08  ret
a0062508:  81 e8 00 00  restore
