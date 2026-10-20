# leon2m FUN_a00de53c 0xa00de53c-0xa00de578 (60 bytes)
a00de53c:  9a 10 20 00  clr  %o5
a00de540:  80 a3 40 08  cmp  %o5, %o0
a00de544:  1a 80 00 0b  bcc  0xa00de570
a00de548:  82 10 20 3f  mov  0x3f, %g1
a00de54c:  01 00 00 00  nop
a00de550:  01 00 00 00  nop
a00de554:  82 80 7f ff  addcc  %g1, -1, %g1
a00de558:  1c bf ff fd  bpos  0xa00de54c
a00de55c:  01 00 00 00  nop
a00de560:  9a 03 60 01  inc  %o5
a00de564:  80 a3 40 08  cmp  %o5, %o0
a00de568:  0a bf ff f9  bcs  0xa00de54c
a00de56c:  82 10 20 3f  mov  0x3f, %g1
a00de570:  81 c3 e0 08  retl
a00de574:  01 00 00 00  nop
