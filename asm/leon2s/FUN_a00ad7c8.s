# leon2s FUN_a00ad7c8 0xa00ad7c8-0xa00ad828 (96 bytes)
a00ad7c8:  9d e3 bf 98  save  %sp, -104, %sp
a00ad7cc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ad7d0:  7f ff ff ed  call  0xa00ad784
a00ad7d4:  90 10 00 18  mov  %i0, %o0
a00ad7d8:  80 8a 20 ff  btst  0xff, %o0
a00ad7dc:  92 10 20 70  mov  0x70, %o1
a00ad7e0:  94 10 20 00  clr  %o2
a00ad7e4:  90 10 00 18  mov  %i0, %o0
a00ad7e8:  02 80 00 0e  be  0xa00ad820
a00ad7ec:  82 10 20 00  clr  %g1
a00ad7f0:  7f ff e5 04  call  0xa00a6c00
a00ad7f4:  01 00 00 00  nop
a00ad7f8:  90 10 00 18  mov  %i0, %o0
a00ad7fc:  92 10 20 73  mov  0x73, %o1
a00ad800:  7f ff e5 00  call  0xa00a6c00
a00ad804:  94 10 20 08  mov  8, %o2
a00ad808:  90 10 00 18  mov  %i0, %o0
a00ad80c:  7f ff e4 eb  call  0xa00a6bb8
a00ad810:  92 10 20 7a  mov  0x7a, %o1
a00ad814:  90 0a 20 08  and  %o0, 8, %o0
a00ad818:  80 a0 00 08  cmp  %g0, %o0
a00ad81c:  82 40 20 00  addx  %g0, 0, %g1
a00ad820:  81 c7 e0 08  ret
a00ad824:  91 e8 00 01  restore  %g0, %g1, %o0
