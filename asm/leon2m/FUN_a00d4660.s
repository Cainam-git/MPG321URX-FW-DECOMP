# leon2m FUN_a00d4660 0xa00d4660-0xa00d4690 (48 bytes)
a00d4660:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d4664:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a00d4668:  d0 08 60 0b  ldub  [ %g1 + 0xb ], %o0
a00d466c:  80 a2 20 64  cmp  %o0, 0x64
a00d4670:  38 80 00 02  bgu,a   0xa00d4678
a00d4674:  90 10 20 64  mov  0x64, %o0
a00d4678:  d0 28 60 0b  stb  %o0, [ %g1 + 0xb ]
a00d467c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d4680:  82 13 c0 00  mov  %o7, %g1
a00d4684:  40 01 d3 06  call  0xa014929c
a00d4688:  9e 10 40 00  mov  %g1, %o7
a00d468c:  01 00 00 00  nop
