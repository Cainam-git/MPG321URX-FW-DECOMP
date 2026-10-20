# leon2m FUN_a00bb86c 0xa00bb86c-0xa00bb908 (156 bytes)
a00bb86c:  9d e3 bf 98  save  %sp, -104, %sp
a00bb870:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00bb874:  a6 10 60 40  or  %g1, 0x40, %l3	! 0xa802d040
a00bb878:  a4 10 20 00  clr  %l2
a00bb87c:  b0 10 20 00  clr  %i0
a00bb880:  a2 10 20 02  mov  2, %l1
a00bb884:  a0 10 20 02  mov  2, %l0
a00bb888:  92 10 00 10  mov  %l0, %o1
a00bb88c:  40 02 63 6c  call  0xa015463c
a00bb890:  90 10 00 18  mov  %i0, %o0
a00bb894:  94 0a 20 ff  and  %o0, 0xff, %o2
a00bb898:  a2 04 60 01  inc  %l1
a00bb89c:  92 10 00 10  mov  %l0, %o1
a00bb8a0:  80 a2 a0 ff  cmp  %o2, 0xff
a00bb8a4:  02 80 00 09  be  0xa00bb8c8
a00bb8a8:  90 10 00 18  mov  %i0, %o0
a00bb8ac:  40 02 63 64  call  0xa015463c
a00bb8b0:  01 00 00 00  nop
a00bb8b4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00bb8b8:  d2 0c c0 10  ldub  [ %l3 + %l0 ], %o1
a00bb8bc:  80 a2 00 09  cmp  %o0, %o1
a00bb8c0:  12 80 00 07  bne  0xa00bb8dc
a00bb8c4:  80 a4 20 07  cmp  %l0, 7
a00bb8c8:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00bb8cc:  80 a4 20 06  cmp  %l0, 6
a00bb8d0:  08 bf ff ef  bleu  0xa00bb88c
a00bb8d4:  92 10 00 10  mov  %l0, %o1
a00bb8d8:  80 a4 20 07  cmp  %l0, 7
a00bb8dc:  02 80 00 08  be  0xa00bb8fc
a00bb8e0:  a4 04 a0 01  inc  %l2
a00bb8e4:  b0 0c a0 ff  and  %l2, 0xff, %i0
a00bb8e8:  80 a6 20 82  cmp  %i0, 0x82
a00bb8ec:  28 bf ff e6  bleu,a   0xa00bb884
a00bb8f0:  a2 10 20 02  mov  2, %l1
a00bb8f4:  10 80 00 03  b  0xa00bb900
a00bb8f8:  90 10 20 ff  mov  0xff, %o0
a00bb8fc:  90 10 00 18  mov  %i0, %o0
a00bb900:  81 c7 e0 08  ret
a00bb904:  91 e8 00 08  restore  %g0, %o0, %o0
