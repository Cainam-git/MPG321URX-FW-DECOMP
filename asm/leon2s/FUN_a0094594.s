# leon2s FUN_a0094594 0xa0094594-0xa00945f0 (92 bytes)
a0094594:  9d e3 bf 98  save  %sp, -104, %sp
a0094598:  b0 0e 20 ff  and  %i0, 0xff, %i0
a009459c:  9b 2e 20 02  sll  %i0, 2, %o5
a00945a0:  9a 03 40 18  add  %o5, %i0, %o5
a00945a4:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00945a8:  82 10 60 fc  or  %g1, 0xfc, %g1	! 0xa807a8fc
a00945ac:  9b 2b 60 02  sll  %o5, 2, %o5
a00945b0:  9a 03 40 01  add  %o5, %g1, %o5
a00945b4:  c2 0b 60 10  ldub  [ %o5 + 0x10 ], %g1
a00945b8:  d6 0b 60 11  ldub  [ %o5 + 0x11 ], %o3
a00945bc:  82 08 60 f0  and  %g1, 0xf0, %g1
a00945c0:  96 0a e0 0f  and  %o3, 0xf, %o3
a00945c4:  f6 0b 60 12  ldub  [ %o5 + 0x12 ], %i3
a00945c8:  96 10 40 0b  or  %g1, %o3, %o3
a00945cc:  90 10 00 18  mov  %i0, %o0
a00945d0:  92 10 20 01  mov  1, %o1
a00945d4:  40 00 4e a0  call  0xa00a8054
a00945d8:  94 10 20 02  mov  2, %o2
a00945dc:  b6 0e e0 ff  and  %i3, 0xff, %i3
a00945e0:  b2 10 20 01  mov  1, %i1
a00945e4:  40 00 4e 9c  call  0xa00a8054
a00945e8:  95 e8 20 0b  restore  %g0, 0xb, %o2
a00945ec:  01 00 00 00  nop
