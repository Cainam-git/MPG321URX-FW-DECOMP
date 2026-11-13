# leon2s FUN_a00ad5cc 0xa00ad5cc-0xa00ad644 (120 bytes)  [FUN_a00ad63c = unreachable ret/restore tail, merged]
a00ad5cc:  9d e3 bf 98  save  %sp, -104, %sp
a00ad5d0:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00ad5d4:  c2 08 63 13  ldub  [ %g1 + 0x313 ], %g1	! 0xa8079313
a00ad5d8:  80 a0 60 00  cmp  %g1, 0
a00ad5dc:  02 80 00 17  be  0xa00ad638
a00ad5e0:  90 10 20 00  clr  %o0
a00ad5e4:  7f ff ff 7f  call  0xa00ad3e0
a00ad5e8:  01 00 00 00  nop
a00ad5ec:  82 0a 20 ff  and  %o0, 0xff, %g1
a00ad5f0:  1b 2a 01 e4  sethi  %hi(0xa8079000), %o5
a00ad5f4:  80 a0 60 01  cmp  %g1, 1
a00ad5f8:  12 80 00 05  bne  0xa00ad60c
a00ad5fc:  90 10 20 01  mov  1, %o0
a00ad600:  c2 0b 63 12  ldub  [ %o5 + 0x312 ], %g1
a00ad604:  82 10 60 01  or  %g1, 1, %g1
a00ad608:  c2 2b 63 12  stb  %g1, [ %o5 + 0x312 ]
a00ad60c:  7f ff ff 75  call  0xa00ad3e0
a00ad610:  01 00 00 00  nop
a00ad614:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ad618:  80 a2 20 01  cmp  %o0, 1
a00ad61c:  12 80 00 05  bne  0xa00ad630
a00ad620:  1b 2a 01 e4  sethi  %hi(0xa8079000), %o5
a00ad624:  c2 0b 63 12  ldub  [ %o5 + 0x312 ], %g1	! 0xa8079312
a00ad628:  82 10 60 02  or  %g1, 2, %g1
a00ad62c:  c2 2b 63 12  stb  %g1, [ %o5 + 0x312 ]
a00ad630:  7f ff fe 71  call  0xa00acff4
a00ad634:  81 e8 00 00  restore
a00ad638:  01 00 00 00  nop
a00ad63c:  81 c7 e0 08  ret
a00ad640:  81 e8 00 00  restore
