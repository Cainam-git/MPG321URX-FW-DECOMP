# leon2m FUN_a01235b4 0xa01235b4-0xa0123648 (148 bytes)
a01235b4:  9d e3 bf 98  save  %sp, -104, %sp
a01235b8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01235bc:  92 10 20 10  mov  0x10, %o1
a01235c0:  7f ff 3e 1c  call  0xa00f2e30
a01235c4:  90 10 00 18  mov  %i0, %o0
a01235c8:  a0 0a 20 0f  and  %o0, 0xf, %l0
a01235cc:  90 10 00 18  mov  %i0, %o0
a01235d0:  7f ff 3e 18  call  0xa00f2e30
a01235d4:  92 10 20 09  mov  9, %o1
a01235d8:  a0 0c 20 ff  and  %l0, 0xff, %l0
a01235dc:  92 1c 20 08  xor  %l0, 8, %o1
a01235e0:  80 a0 00 09  cmp  %g0, %o1
a01235e4:  90 0a 20 ff  and  %o0, 0xff, %o0
a01235e8:  98 60 3f ff  subx  %g0, -1, %o4
a01235ec:  9a 1a 20 ff  xor  %o0, 0xff, %o5
a01235f0:  80 a0 00 0d  cmp  %g0, %o5
a01235f4:  82 60 3f ff  subx  %g0, -1, %g1
a01235f8:  94 1c 20 04  xor  %l0, 4, %o2
a01235fc:  96 1a 20 0f  xor  %o0, 0xf, %o3
a0123600:  80 8b 00 01  btst  %o4, %g1
a0123604:  12 80 00 0f  bne  0xa0123640
a0123608:  b0 10 20 01  mov  1, %i0
a012360c:  80 a0 00 0a  cmp  %g0, %o2
a0123610:  9e 60 3f ff  subx  %g0, -1, %o7
a0123614:  80 a0 00 0b  cmp  %g0, %o3
a0123618:  94 60 3f ff  subx  %g0, -1, %o2
a012361c:  a0 1c 20 02  xor  %l0, 2, %l0
a0123620:  80 8b c0 0a  btst  %o7, %o2
a0123624:  12 80 00 07  bne  0xa0123640
a0123628:  90 1a 20 03  xor  %o0, 3, %o0
a012362c:  80 a0 00 10  cmp  %g0, %l0
a0123630:  96 60 3f ff  subx  %g0, -1, %o3
a0123634:  80 a0 00 08  cmp  %g0, %o0
a0123638:  90 60 3f ff  subx  %g0, -1, %o0
a012363c:  b0 0a c0 08  and  %o3, %o0, %i0
a0123640:  81 c7 e0 08  ret
a0123644:  81 e8 00 00  restore
