# leon2s FUN_a00ad784 0xa00ad784-0xa00ad7c8 (68 bytes)
a00ad784:  9d e3 bf 98  save  %sp, -104, %sp
a00ad788:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ad78c:  90 10 00 18  mov  %i0, %o0
a00ad790:  7f ff e5 0a  call  0xa00a6bb8
a00ad794:  92 10 20 8f  mov  0x8f, %o1
a00ad798:  80 8a 20 40  btst  0x40, %o0
a00ad79c:  90 10 00 18  mov  %i0, %o0
a00ad7a0:  02 80 00 07  be  0xa00ad7bc
a00ad7a4:  b0 10 20 00  clr  %i0
a00ad7a8:  7f ff ff b0  call  0xa00ad668
a00ad7ac:  01 00 00 00  nop
a00ad7b0:  80 8a 20 ff  btst  0xff, %o0
a00ad7b4:  32 80 00 02  bne,a   0xa00ad7bc
a00ad7b8:  b0 10 20 01  mov  1, %i0
a00ad7bc:  b0 0e 20 01  and  %i0, 1, %i0
a00ad7c0:  81 c7 e0 08  ret
a00ad7c4:  81 e8 00 00  restore
