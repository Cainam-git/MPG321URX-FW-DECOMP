# leon2s FUN_a00b0568 0xa00b0568-0xa00b05e8 (128 bytes)  [FUN_a00b05e0 = unreachable ret/restore tail, merged]
a00b0568:  9d e3 bf 98  save  %sp, -104, %sp
a00b056c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00b0570:  a0 10 63 18  or  %g1, 0x318, %l0	! 0xa8079318
a00b0574:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00b0578:  c2 0c 00 18  ldub  [ %l0 + %i0 ], %g1
a00b057c:  80 a0 60 00  cmp  %g1, 0
a00b0580:  02 80 00 17  be  0xa00b05dc
a00b0584:  a2 10 20 00  clr  %l1
a00b0588:  7f ff ff ee  call  0xa00b0540
a00b058c:  90 10 00 18  mov  %i0, %o0
a00b0590:  7f ff f7 84  call  0xa00ae3a0
a00b0594:  90 10 00 18  mov  %i0, %o0
a00b0598:  7f ff 4f a5  call  0xa008442c
a00b059c:  90 10 00 18  mov  %i0, %o0
a00b05a0:  c0 2c 00 18  clrb  [ %l0 + %i0 ]
a00b05a4:  96 10 00 10  mov  %l0, %o3
a00b05a8:  98 10 20 00  clr  %o4
a00b05ac:  82 0b 20 ff  and  %o4, 0xff, %g1
a00b05b0:  da 0a c0 01  ldub  [ %o3 + %g1 ], %o5
a00b05b4:  98 03 20 01  inc  %o4
a00b05b8:  82 0b 20 ff  and  %o4, 0xff, %g1
a00b05bc:  80 a0 60 01  cmp  %g1, 1
a00b05c0:  08 bf ff fc  bleu  0xa00b05b0
a00b05c4:  a2 14 40 0d  or  %l1, %o5, %l1
a00b05c8:  80 8c 60 ff  btst  0xff, %l1
a00b05cc:  12 80 00 04  bne  0xa00b05dc
a00b05d0:  01 00 00 00  nop
a00b05d4:  7f ff ed 75  call  0xa00abba8
a00b05d8:  81 e8 00 00  restore
a00b05dc:  01 00 00 00  nop
a00b05e0:  81 c7 e0 08  ret
a00b05e4:  81 e8 00 00  restore
