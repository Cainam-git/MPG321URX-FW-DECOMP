# leon2s FUN_a00d3670 0xa00d3670-0xa00d36a4 (52 bytes)
a00d3670:  9d e3 bf 98  save  %sp, -104, %sp
a00d3674:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d3678:  40 3b ba 7b  call  0xa0fc2064
a00d367c:  e0 00 60 20  ld  [ %g1 + 0x20 ], %l0	! 0xa8078c20
a00d3680:  9a 22 00 10  sub  %o0, %l0, %o5
a00d3684:  80 a2 00 10  cmp  %o0, %l0
a00d3688:  1a 80 00 03  bcc  0xa00d3694
a00d368c:  82 10 00 0d  mov  %o5, %g1
a00d3690:  82 03 7f ff  add  %o5, -1, %g1
a00d3694:  80 a0 60 c9  cmp  %g1, 0xc9
a00d3698:  b0 60 3f ff  subx  %g0, -1, %i0
a00d369c:  81 c7 e0 08  ret
a00d36a0:  81 e8 00 00  restore
