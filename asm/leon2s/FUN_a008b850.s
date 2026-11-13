# leon2s FUN_a008b850 0xa008b850-0xa008b8ac (92 bytes)
a008b850:  9d e3 bf 98  save  %sp, -104, %sp
a008b854:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008b858:  92 10 20 68  mov  0x68, %o1
a008b85c:  40 00 6c d7  call  0xa00a6bb8
a008b860:  90 10 00 18  mov  %i0, %o0
a008b864:  90 0a 20 ff  and  %o0, 0xff, %o0
a008b868:  a1 2a 20 08  sll  %o0, 8, %l0
a008b86c:  92 10 20 67  mov  0x67, %o1
a008b870:  40 00 6c d2  call  0xa00a6bb8
a008b874:  90 10 00 18  mov  %i0, %o0
a008b878:  90 0a 20 ff  and  %o0, 0xff, %o0
a008b87c:  90 14 00 08  or  %l0, %o0, %o0
a008b880:  a1 2a 20 08  sll  %o0, 8, %l0
a008b884:  90 10 00 18  mov  %i0, %o0
a008b888:  40 00 6c cc  call  0xa00a6bb8
a008b88c:  92 10 20 66  mov  0x66, %o1
a008b890:  90 0a 20 ff  and  %o0, 0xff, %o0
a008b894:  90 94 00 08  orcc  %l0, %o0, %o0
a008b898:  12 80 00 03  bne  0xa008b8a4
a008b89c:  01 00 00 00  nop
a008b8a0:  90 10 20 01  mov  1, %o0	! 0x1
a008b8a4:  81 c7 e0 08  ret
a008b8a8:  91 e8 00 08  restore  %g0, %o0, %o0
