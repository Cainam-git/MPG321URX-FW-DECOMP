# leon2m FUN_a01445fc 0xa01445fc-0xa014464c (80 bytes)
a01445fc:  03 00 06 9b  sethi  %hi(0x1a6c00), %g1
a0144600:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144604:  94 10 61 b2  or  %g1, 0x1b2, %o2
a0144608:  96 10 20 00  clr  %o3
a014460c:  9a 10 20 00  clr  %o5
a0144610:  98 03 40 0d  add  %o5, %o5, %o4
a0144614:  96 02 e0 01  inc  %o3
a0144618:  c2 0a 80 0c  ldub  [ %o2 + %o4 ], %g1
a014461c:  80 a0 40 08  cmp  %g1, %o0
a0144620:  02 80 00 07  be  0xa014463c
a0144624:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0144628:  80 a3 60 03  cmp  %o5, 3
a014462c:  28 bf ff fa  bleu,a   0xa0144614
a0144630:  98 03 40 0d  add  %o5, %o5, %o4
a0144634:  10 80 00 04  b  0xa0144644
a0144638:  90 10 20 ff  mov  0xff, %o0
a014463c:  96 03 00 0a  add  %o4, %o2, %o3
a0144640:  d0 0a e0 01  ldub  [ %o3 + 1 ], %o0
a0144644:  81 c3 e0 08  retl
a0144648:  01 00 00 00  nop
