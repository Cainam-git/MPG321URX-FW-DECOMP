# leon2s FUN_a00a29b0 0xa00a29b0-0xa00a29d8 (40 bytes)
a00a29b0:  9d e3 bf 98  save  %sp, -104, %sp
a00a29b4:  7f ff fd bd  call  0xa00a20a8
a00a29b8:  90 0e 20 ff  and  %i0, 0xff, %o0
a00a29bc:  80 8a 20 ff  btst  0xff, %o0
a00a29c0:  02 80 00 03  be  0xa00a29cc
a00a29c4:  b0 10 20 00  clr  %i0
a00a29c8:  b0 10 20 01  mov  1, %i0
a00a29cc:  b0 0e 20 01  and  %i0, 1, %i0
a00a29d0:  81 c7 e0 08  ret
a00a29d4:  81 e8 00 00  restore
