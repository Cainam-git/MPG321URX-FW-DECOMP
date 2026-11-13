# leon2m FUN_a014d504 0xa014d504-0xa014d544 (64 bytes)
a014d504:  9d e3 bf 98  save  %sp, -104, %sp
a014d508:  7f fe ee 53  call  0xa0108e54
a014d50c:  b0 10 20 00  clr  %i0
a014d510:  90 0a 20 ff  and  %o0, 0xff, %o0
a014d514:  80 a2 20 01  cmp  %o0, 1
a014d518:  32 80 00 09  bne,a   0xa014d53c
a014d51c:  b0 0e 20 01  and  %i0, 1, %i0
a014d520:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014d524:  d8 00 63 d0  ld  [ %g1 + 0x3d0 ], %o4	! 0xa802e3d0
a014d528:  1b 03 00 00  sethi  %hi(0xc000000), %o5
a014d52c:  80 8b 00 0d  btst  %o4, %o5
a014d530:  22 80 00 02  be,a   0xa014d538
a014d534:  b0 10 20 01  mov  1, %i0
a014d538:  b0 0e 20 01  and  %i0, 1, %i0
a014d53c:  81 c7 e0 08  ret
a014d540:  81 e8 00 00  restore
