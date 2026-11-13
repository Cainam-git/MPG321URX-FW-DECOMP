# leon2s FUN_a00c30e4 0xa00c30e4-0xa00c3144 (96 bytes)
a00c30e4:  9d e3 bf 98  save  %sp, -104, %sp
a00c30e8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c30ec:  92 10 23 19  mov  0x319, %o1
a00c30f0:  90 10 00 18  mov  %i0, %o0
a00c30f4:  80 a6 20 01  cmp  %i0, 1
a00c30f8:  18 80 00 09  bgu  0xa00c311c
a00c30fc:  a0 10 20 00  clr  %l0
a00c3100:  40 3b cd 1f  call  0xa0fb657c
a00c3104:  01 00 00 00  nop
a00c3108:  80 8a 20 10  btst  0x10, %o0
a00c310c:  02 80 00 0c  be  0xa00c313c
a00c3110:  b0 0c 20 01  and  %l0, 1, %i0
a00c3114:  10 80 00 09  b  0xa00c3138
a00c3118:  a0 10 20 01  mov  1, %l0
a00c311c:  80 a6 20 03  cmp  %i0, 3
a00c3120:  28 80 00 06  bleu,a   0xa00c3138
a00c3124:  a0 10 20 01  mov  1, %l0
a00c3128:  80 a6 20 05  cmp  %i0, 5
a00c312c:  18 80 00 04  bgu  0xa00c313c
a00c3130:  b0 0c 20 01  and  %l0, 1, %i0
a00c3134:  a0 10 20 01  mov  1, %l0
a00c3138:  b0 0c 20 01  and  %l0, 1, %i0
a00c313c:  81 c7 e0 08  ret
a00c3140:  81 e8 00 00  restore
