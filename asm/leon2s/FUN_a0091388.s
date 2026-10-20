# leon2s FUN_a0091388 0xa0091388-0xa0091420 (152 bytes)
a0091388:  9d e3 bf 98  save  %sp, -104, %sp
a009138c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0091390:  92 10 21 06  mov  0x106, %o1
a0091394:  90 10 00 18  mov  %i0, %o0
a0091398:  40 00 54 b4  call  0xa00a6668
a009139c:  21 00 03 ff  sethi  %hi(0xffc00), %l0
a00913a0:  a0 14 23 ff  or  %l0, 0x3ff, %l0	! 0xfffff
a00913a4:  a2 0a 00 10  and  %o0, %l0, %l1
a00913a8:  90 10 00 18  mov  %i0, %o0
a00913ac:  40 00 54 af  call  0xa00a6668
a00913b0:  92 10 21 0c  mov  0x10c, %o1
a00913b4:  80 a0 00 11  cmp  %g0, %l1
a00913b8:  a0 0a 00 10  and  %o0, %l0, %l0
a00913bc:  9a 40 20 00  addx  %g0, 0, %o5
a00913c0:  80 a0 00 10  cmp  %g0, %l0
a00913c4:  90 10 00 18  mov  %i0, %o0
a00913c8:  82 40 20 00  addx  %g0, 0, %g1
a00913cc:  80 8b 40 01  btst  %o5, %g1
a00913d0:  02 80 00 10  be  0xa0091410
a00913d4:  b0 10 20 00  clr  %i0
a00913d8:  7f ff ff 79  call  0xa00911bc
a00913dc:  01 00 00 00  nop
a00913e0:  91 2a 20 10  sll  %o0, 0x10, %o0
a00913e4:  91 32 20 10  srl  %o0, 0x10, %o0
a00913e8:  90 5a 00 11  smul  %o0, %l1, %o0
a00913ec:  03 00 00 09  sethi  %hi(0x2400), %g1
a00913f0:  81 80 00 00  mov  %g0, %y
a00913f4:  01 00 00 00  nop
a00913f8:  01 00 00 00  nop
a00913fc:  01 00 00 00  nop
a0091400:  90 72 00 10  udiv  %o0, %l0, %o0
a0091404:  82 10 63 10  or  %g1, 0x310, %g1
a0091408:  90 5a 00 01  smul  %o0, %g1, %o0
a009140c:  b1 32 20 07  srl  %o0, 7, %i0
a0091410:  b1 2e 20 10  sll  %i0, 0x10, %i0
a0091414:  b1 36 20 10  srl  %i0, 0x10, %i0
a0091418:  81 c7 e0 08  ret
a009141c:  81 e8 00 00  restore
