# leon2s FUN_a00a61d4 0xa00a61d4-0xa00a621c (72 bytes)
a00a61d4:  9d e3 bf 98  save  %sp, -104, %sp
a00a61d8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a61dc:  90 10 20 00  clr  %o0
a00a61e0:  80 a6 20 71  cmp  %i0, 0x71
a00a61e4:  02 80 00 05  be  0xa00a61f8
a00a61e8:  a0 10 20 00  clr  %l0
a00a61ec:  80 a6 20 81  cmp  %i0, 0x81
a00a61f0:  12 80 00 08  bne  0xa00a6210
a00a61f4:  90 10 20 01  mov  1, %o0
a00a61f8:  40 00 1d 63  call  0xa00ad784
a00a61fc:  01 00 00 00  nop
a00a6200:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a6204:  80 a2 20 01  cmp  %o0, 1
a00a6208:  22 80 00 02  be,a   0xa00a6210
a00a620c:  a0 10 20 01  mov  1, %l0
a00a6210:  b0 0c 20 01  and  %l0, 1, %i0
a00a6214:  81 c7 e0 08  ret
a00a6218:  81 e8 00 00  restore
