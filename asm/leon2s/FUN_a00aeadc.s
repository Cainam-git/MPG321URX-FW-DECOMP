# leon2s FUN_a00aeadc 0xa00aeadc-0xa00aeb24 (72 bytes)
a00aeadc:  9d e3 bf 98  save  %sp, -104, %sp
a00aeae0:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00aeae4:  c2 00 60 04  ld  [ %g1 + 4 ], %g1	! 0xa807dc04
a00aeae8:  c2 00 60 88  ld  [ %g1 + 0x88 ], %g1
a00aeaec:  83 30 60 0f  srl  %g1, 0xf, %g1
a00aeaf0:  92 10 24 63  mov  0x463, %o1
a00aeaf4:  80 88 60 01  btst  1, %g1
a00aeaf8:  02 80 00 07  be  0xa00aeb14
a00aeafc:  90 0e 20 ff  and  %i0, 0xff, %o0
a00aeb00:  7f ff e0 2e  call  0xa00a6bb8
a00aeb04:  b0 10 20 01  mov  1, %i0
a00aeb08:  80 8a 20 01  btst  1, %o0
a00aeb0c:  12 80 00 04  bne  0xa00aeb1c
a00aeb10:  b0 0e 20 01  and  %i0, 1, %i0
a00aeb14:  b0 10 20 00  clr  %i0
a00aeb18:  b0 0e 20 01  and  %i0, 1, %i0
a00aeb1c:  81 c7 e0 08  ret
a00aeb20:  81 e8 00 00  restore
