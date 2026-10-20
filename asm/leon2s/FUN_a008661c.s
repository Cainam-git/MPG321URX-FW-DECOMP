# leon2s FUN_a008661c 0xa008661c-0xa0086678 (92 bytes)
a008661c:  9d e3 bf 98  save  %sp, -104, %sp
a0086620:  90 0e 20 ff  and  %i0, 0xff, %o0
a0086624:  9a 02 00 08  add  %o0, %o0, %o5
a0086628:  9a 03 40 08  add  %o5, %o0, %o5
a008662c:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0086630:  9a 03 40 0d  add  %o5, %o5, %o5
a0086634:  82 10 61 2e  or  %g1, 0x12e, %g1
a0086638:  c2 08 40 0d  ldub  [ %g1 + %o5 ], %g1
a008663c:  83 30 60 03  srl  %g1, 3, %g1
a0086640:  82 08 60 01  and  %g1, 1, %g1
a0086644:  80 a0 00 01  cmp  %g0, %g1
a0086648:  96 40 3f ff  addx  %g0, -1, %o3
a008664c:  96 0a ff 80  and  %o3, -128, %o3
a0086650:  96 02 ff 80  add  %o3, -128, %o3
a0086654:  96 0a e0 80  and  %o3, 0x80, %o3
a0086658:  92 10 20 80  mov  0x80, %o1
a008665c:  7f ff ff 41  call  0xa0086360
a0086660:  94 10 21 07  mov  0x107, %o2
a0086664:  90 0a 20 ff  and  %o0, 0xff, %o0
a0086668:  80 a0 00 08  cmp  %g0, %o0
a008666c:  b0 60 3f ff  subx  %g0, -1, %i0
a0086670:  81 c7 e0 08  ret
a0086674:  81 e8 00 00  restore
