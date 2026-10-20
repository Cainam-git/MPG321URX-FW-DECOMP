# leon2s FUN_a00a47e0 0xa00a47e0-0xa00a486c (140 bytes)
a00a47e0:  9d e3 bf 98  save  %sp, -104, %sp
a00a47e4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a47e8:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00a47ec:  82 10 60 10  or  %g1, 0x10, %g1	! 0xa807dc10
a00a47f0:  b1 2e 20 03  sll  %i0, 3, %i0
a00a47f4:  b0 06 00 01  add  %i0, %g1, %i0
a00a47f8:  c2 0e 20 05  ldub  [ %i0 + 5 ], %g1
a00a47fc:  21 2a 01 e4  sethi  %hi(0xa8079000), %l0
a00a4800:  80 a0 60 01  cmp  %g1, 1
a00a4804:  02 80 00 17  be  0xa00a4860
a00a4808:  b0 10 20 01  mov  1, %i0
a00a480c:  40 00 06 61  call  0xa00a6190
a00a4810:  d0 0c 22 28  ldub  [ %l0 + 0x228 ], %o0
a00a4814:  80 8a 20 ff  btst  0xff, %o0
a00a4818:  12 80 00 07  bne  0xa00a4834
a00a481c:  01 00 00 00  nop
a00a4820:  40 00 06 6d  call  0xa00a61d4
a00a4824:  d0 0c 22 28  ldub  [ %l0 + 0x228 ], %o0
a00a4828:  80 8a 20 ff  btst  0xff, %o0
a00a482c:  02 80 00 0d  be  0xa00a4860
a00a4830:  01 00 00 00  nop
a00a4834:  40 00 06 7a  call  0xa00a621c
a00a4838:  d0 0c 22 28  ldub  [ %l0 + 0x228 ], %o0
a00a483c:  82 0a 20 ff  and  %o0, 0xff, %g1
a00a4840:  11 28 01 b0  sethi  %hi(0xa006c000), %o0
a00a4844:  90 12 20 30  or  %o0, 0x30, %o0	! 0xa006c030
a00a4848:  92 10 20 01  mov  1, %o1
a00a484c:  80 a0 60 01  cmp  %g1, 1
a00a4850:  12 80 00 04  bne  0xa00a4860
a00a4854:  b0 10 20 00  clr  %i0
a00a4858:  7f ff 39 fb  call  0xa0073044
a00a485c:  b0 10 20 01  mov  1, %i0
a00a4860:  01 00 00 00  nop
a00a4864:  81 c7 e0 08  ret
a00a4868:  81 e8 00 00  restore
