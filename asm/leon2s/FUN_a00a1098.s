# leon2s FUN_a00a1098 0xa00a1098-0xa00a10ec (84 bytes)
a00a1098:  9d e3 bf 98  save  %sp, -104, %sp
a00a109c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a10a0:  80 a6 60 00  cmp  %i1, 0
a00a10a4:  02 80 00 10  be  0xa00a10e4
a00a10a8:  a0 10 20 00  clr  %l0
a00a10ac:  83 3e 40 10  sra  %i1, %l0, %g1
a00a10b0:  80 88 60 01  btst  1, %g1
a00a10b4:  02 80 00 08  be  0xa00a10d4
a00a10b8:  a0 04 20 01  inc  %l0
a00a10bc:  c2 06 80 00  ld  [ %i2 ], %g1
a00a10c0:  80 a0 60 00  cmp  %g1, 0
a00a10c4:  02 80 00 04  be  0xa00a10d4
a00a10c8:  90 0e 20 ff  and  %i0, 0xff, %o0
a00a10cc:  9f c0 40 00  call  %g1
a00a10d0:  01 00 00 00  nop
a00a10d4:  82 0c 20 ff  and  %l0, 0xff, %g1
a00a10d8:  80 a0 60 07  cmp  %g1, 7
a00a10dc:  08 bf ff f4  bleu  0xa00a10ac
a00a10e0:  b4 06 a0 04  add  %i2, 4, %i2
a00a10e4:  81 c7 e0 08  ret
a00a10e8:  81 e8 00 00  restore
