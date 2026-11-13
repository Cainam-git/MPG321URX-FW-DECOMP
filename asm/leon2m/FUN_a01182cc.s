# leon2m FUN_a01182cc 0xa01182cc-0xa0118324 (88 bytes)
a01182cc:  90 0a 20 ff  and  %o0, 0xff, %o0
a01182d0:  80 a2 20 02  cmp  %o0, 2
a01182d4:  02 80 00 0f  be  0xa0118310
a01182d8:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a01182dc:  14 80 00 08  bg  0xa01182fc
a01182e0:  80 a2 20 03  cmp  %o0, 3
a01182e4:  80 a2 20 01  cmp  %o0, 1
a01182e8:  02 80 00 0c  be  0xa0118318
a01182ec:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a01182f0:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a01182f4:  10 80 00 0a  b  0xa011831c
a01182f8:  d0 08 62 90  ldub  [ %g1 + 0x290 ], %o0	! 0xa8027a90
a01182fc:  12 bf ff fe  bne  0xa01182f4
a0118300:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a0118304:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a0118308:  10 80 00 05  b  0xa011831c
a011830c:  d0 08 62 93  ldub  [ %g1 + 0x293 ], %o0	! 0xa8027a93
a0118310:  10 80 00 03  b  0xa011831c
a0118314:  d0 08 62 92  ldub  [ %g1 + 0x292 ], %o0
a0118318:  d0 08 62 91  ldub  [ %g1 + 0x291 ], %o0
a011831c:  81 c3 e0 08  retl
a0118320:  90 0a 20 ff  and  %o0, 0xff, %o0
