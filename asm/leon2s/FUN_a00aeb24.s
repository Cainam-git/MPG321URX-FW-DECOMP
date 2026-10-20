# leon2s FUN_a00aeb24 0xa00aeb24-0xa00aeb6c (72 bytes)
a00aeb24:  9d e3 bf 98  save  %sp, -104, %sp
a00aeb28:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00aeb2c:  c2 00 60 04  ld  [ %g1 + 4 ], %g1	! 0xa807dc04
a00aeb30:  c2 00 60 88  ld  [ %g1 + 0x88 ], %g1
a00aeb34:  90 0e 20 ff  and  %i0, 0xff, %o0
a00aeb38:  92 10 24 63  mov  0x463, %o1
a00aeb3c:  80 88 60 80  btst  0x80, %g1
a00aeb40:  12 80 00 07  bne  0xa00aeb5c
a00aeb44:  b0 10 20 00  clr  %i0
a00aeb48:  7f ff e0 1c  call  0xa00a6bb8
a00aeb4c:  01 00 00 00  nop
a00aeb50:  80 8a 20 04  btst  4, %o0
a00aeb54:  02 80 00 04  be  0xa00aeb64
a00aeb58:  b0 0e 20 01  and  %i0, 1, %i0
a00aeb5c:  b0 10 20 01  mov  1, %i0
a00aeb60:  b0 0e 20 01  and  %i0, 1, %i0
a00aeb64:  81 c7 e0 08  ret
a00aeb68:  81 e8 00 00  restore
