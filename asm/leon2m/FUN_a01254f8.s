# leon2m FUN_a01254f8 0xa01254f8-0xa0125530 (56 bytes)
a01254f8:  19 2a 00 b6  sethi  %hi(0xa802d800), %o4
a01254fc:  9a 0a 20 ff  and  %o0, 0xff, %o5
a0125500:  82 13 20 80  or  %o4, 0x80, %g1
a0125504:  d8 08 40 0d  ldub  [ %g1 + %o5 ], %o4
a0125508:  11 00 06 90  sethi  %hi(0x1a4000), %o0
a012550c:  82 12 22 a8  or  %o0, 0x2a8, %g1	! 0x1a42a8
a0125510:  9a 5b 20 16  smul  %o4, 0x16, %o5
a0125514:  9a 03 40 01  add  %o5, %g1, %o5
a0125518:  80 a3 20 ff  cmp  %o4, 0xff
a012551c:  02 80 00 03  be  0xa0125528
a0125520:  90 10 3f ff  mov  -1, %o0
a0125524:  d0 0b 60 08  ldub  [ %o5 + 8 ], %o0
a0125528:  81 c3 e0 08  retl
a012552c:  90 0a 20 ff  and  %o0, 0xff, %o0
