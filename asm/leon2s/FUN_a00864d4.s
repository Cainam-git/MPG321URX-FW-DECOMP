# leon2s FUN_a00864d4 0xa00864d4-0xa0086540 (108 bytes)
a00864d4:  9d e3 bf 90  save  %sp, -112, %sp
a00864d8:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00864dc:  80 a6 60 00  cmp  %i1, 0
a00864e0:  02 80 00 0c  be  0xa0086510
a00864e4:  82 10 20 21  mov  0x21, %g1
a00864e8:  80 a6 60 01  cmp  %i1, 1
a00864ec:  02 80 00 09  be  0xa0086510
a00864f0:  82 10 20 22  mov  0x22, %g1
a00864f4:  80 a6 60 02  cmp  %i1, 2
a00864f8:  02 80 00 06  be  0xa0086510
a00864fc:  82 10 20 23  mov  0x23, %g1
a0086500:  80 a6 60 03  cmp  %i1, 3
a0086504:  32 80 00 04  bne,a   0xa0086514
a0086508:  c0 2f bf f7  clrb  [ %fp + -9 ]
a008650c:  82 10 20 27  mov  0x27, %g1
a0086510:  c2 2f bf f7  stb  %g1, [ %fp + -9 ]
a0086514:  90 0e 20 ff  and  %i0, 0xff, %o0
a0086518:  92 10 20 80  mov  0x80, %o1
a008651c:  94 10 21 02  mov  0x102, %o2
a0086520:  96 10 20 00  clr  %o3
a0086524:  7f ff ff ac  call  0xa00863d4
a0086528:  98 07 bf f7  add  %fp, -9, %o4
a008652c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0086530:  80 a0 00 08  cmp  %g0, %o0
a0086534:  b0 40 20 00  addx  %g0, 0, %i0
a0086538:  81 c7 e0 08  ret
a008653c:  81 e8 00 00  restore
