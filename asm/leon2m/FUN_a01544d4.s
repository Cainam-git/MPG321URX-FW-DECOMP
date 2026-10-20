# leon2m FUN_a01544d4 0xa01544d4-0xa0154574 (160 bytes)
a01544d4:  9d e3 bf 98  save  %sp, -104, %sp
a01544d8:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a01544dc:  82 10 63 9c  or  %g1, 0x39c, %g1	! 0xa802cf9c
a01544e0:  c2 08 40 00  ldub  [ %g1 ], %g1
a01544e4:  82 08 60 ff  and  %g1, 0xff, %g1
a01544e8:  82 08 60 f0  and  %g1, 0xf0, %g1
a01544ec:  80 a0 60 80  cmp  %g1, 0x80
a01544f0:  12 80 00 1e  bne  0xa0154568
a01544f4:  01 00 00 00  nop
a01544f8:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a01544fc:  82 10 63 9d  or  %g1, 0x39d, %g1	! 0xa802cf9d
a0154500:  c2 08 40 00  ldub  [ %g1 ], %g1
a0154504:  82 08 60 ff  and  %g1, 0xff, %g1
a0154508:  80 a0 60 03  cmp  %g1, 3
a015450c:  02 80 00 04  be  0xa015451c
a0154510:  01 00 00 00  nop
a0154514:  10 80 00 0d  b  0xa0154548
a0154518:  01 00 00 00  nop
a015451c:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a0154520:  9a 10 63 98  or  %g1, 0x398, %o5	! 0xa802cf98
a0154524:  82 10 20 03  mov  3, %g1
a0154528:  c2 23 40 00  st  %g1, [ %o5 ]
a015452c:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a0154530:  82 10 63 98  or  %g1, 0x398, %g1	! 0xa802cf98
a0154534:  d0 00 40 00  ld  [ %g1 ], %o0
a0154538:  7f fe af e5  call  0xa01004cc
a015453c:  01 00 00 00  nop
a0154540:  10 80 00 0a  b  0xa0154568
a0154544:  01 00 00 00  nop
a0154548:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a015454c:  82 10 63 98  or  %g1, 0x398, %g1	! 0xa802cf98
a0154550:  c0 20 40 00  clr  [ %g1 ]
a0154554:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a0154558:  82 10 63 98  or  %g1, 0x398, %g1	! 0xa802cf98
a015455c:  d0 00 40 00  ld  [ %g1 ], %o0
a0154560:  7f fe af db  call  0xa01004cc
a0154564:  01 00 00 00  nop
a0154568:  01 00 00 00  nop
a015456c:  81 c7 e0 08  ret
a0154570:  81 e8 00 00  restore
