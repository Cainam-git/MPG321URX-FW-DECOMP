# leon2s FUN_a00ad320 0xa00ad320-0xa00ad38c (108 bytes)
a00ad320:  9d e3 bf 98  save  %sp, -104, %sp
a00ad324:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ad328:  1b 2a 01 f7  sethi  %hi(0xa807dc00), %o5
a00ad32c:  82 5e 21 2c  smul  %i0, 0x12c, %g1
a00ad330:  9a 13 60 18  or  %o5, 0x18, %o5
a00ad334:  82 00 40 0d  add  %g1, %o5, %g1
a00ad338:  c2 08 61 15  ldub  [ %g1 + 0x115 ], %g1
a00ad33c:  80 a0 60 00  cmp  %g1, 0
a00ad340:  90 10 00 18  mov  %i0, %o0
a00ad344:  a0 10 20 00  clr  %l0
a00ad348:  02 80 00 0f  be  0xa00ad384
a00ad34c:  82 10 20 00  clr  %g1
a00ad350:  7f ff ff cb  call  0xa00ad27c
a00ad354:  01 00 00 00  nop
a00ad358:  82 0a 20 ff  and  %o0, 0xff, %g1
a00ad35c:  92 10 22 23  mov  0x223, %o1
a00ad360:  80 a0 60 01  cmp  %g1, 1
a00ad364:  12 80 00 07  bne  0xa00ad380
a00ad368:  90 10 00 18  mov  %i0, %o0
a00ad36c:  7f ff e6 13  call  0xa00a6bb8
a00ad370:  01 00 00 00  nop
a00ad374:  80 8a 20 80  btst  0x80, %o0
a00ad378:  32 80 00 02  bne,a   0xa00ad380
a00ad37c:  a0 10 20 01  mov  1, %l0
a00ad380:  82 0c 20 ff  and  %l0, 0xff, %g1
a00ad384:  81 c7 e0 08  ret
a00ad388:  91 e8 00 01  restore  %g0, %g1, %o0
