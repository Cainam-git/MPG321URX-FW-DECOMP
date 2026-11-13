# leon2s FUN_a00c9750 0xa00c9750-0xa00c9798 (72 bytes)
a00c9750:  9d e3 bf 98  save  %sp, -104, %sp
a00c9754:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c9758:  80 a6 20 02  cmp  %i0, 2
a00c975c:  12 80 00 06  bne  0xa00c9774
a00c9760:  82 10 20 00  clr  %g1
a00c9764:  7f ff ff f2  call  0xa00c972c
a00c9768:  01 00 00 00  nop
a00c976c:  10 80 00 08  b  0xa00c978c
a00c9770:  82 10 00 08  mov  %o0, %g1
a00c9774:  80 a6 20 01  cmp  %i0, 1
a00c9778:  18 80 00 05  bgu  0xa00c978c
a00c977c:  90 10 00 18  mov  %i0, %o0
a00c9780:  7f ff fe fc  call  0xa00c9370
a00c9784:  01 00 00 00  nop
a00c9788:  82 10 00 08  mov  %o0, %g1
a00c978c:  b0 08 60 ff  and  %g1, 0xff, %i0
a00c9790:  81 c7 e0 08  ret
a00c9794:  81 e8 00 00  restore
