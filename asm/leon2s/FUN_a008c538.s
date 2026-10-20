# leon2s FUN_a008c538 0xa008c538-0xa008c5d8 (160 bytes)
a008c538:  9d e3 bf 98  save  %sp, -104, %sp
a008c53c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008c540:  7f ff fc be  call  0xa008b838
a008c544:  90 10 00 18  mov  %i0, %o0
a008c548:  a0 10 00 08  mov  %o0, %l0
a008c54c:  7f ff fc c1  call  0xa008b850
a008c550:  90 10 00 18  mov  %i0, %o0
a008c554:  a2 10 00 08  mov  %o0, %l1
a008c558:  40 00 7c 4e  call  0xa00ab690
a008c55c:  90 10 00 18  mov  %i0, %o0
a008c560:  82 5c 22 1c  smul  %l0, 0x21c, %g1
a008c564:  83 30 60 06  srl  %g1, 6, %g1
a008c568:  90 0a 20 ff  and  %o0, 0xff, %o0
a008c56c:  80 a2 20 02  cmp  %o0, 2
a008c570:  02 80 00 12  be  0xa008c5b8
a008c574:  82 58 64 e2  smul  %g1, 0x4e2, %g1
a008c578:  80 a2 20 02  cmp  %o0, 2
a008c57c:  34 80 00 07  bg,a   0xa008c598
a008c580:  82 5c 23 2a  smul  %l0, 0x32a, %g1
a008c584:  82 5c 21 0e  smul  %l0, 0x10e, %g1
a008c588:  83 30 60 06  srl  %g1, 6, %g1
a008c58c:  82 58 64 e2  smul  %g1, 0x4e2, %g1
a008c590:  10 80 00 05  b  0xa008c5a4
a008c594:  80 a2 20 01  cmp  %o0, 1
a008c598:  83 30 60 06  srl  %g1, 6, %g1
a008c59c:  82 58 64 e2  smul  %g1, 0x4e2, %g1
a008c5a0:  80 a2 20 03  cmp  %o0, 3
a008c5a4:  02 80 00 05  be  0xa008c5b8
a008c5a8:  01 00 00 00  nop
a008c5ac:  82 5c 20 a2  smul  %l0, 0xa2, %g1
a008c5b0:  83 30 60 06  srl  %g1, 6, %g1
a008c5b4:  82 58 64 e2  smul  %g1, 0x4e2, %g1
a008c5b8:  81 80 00 00  mov  %g0, %y
a008c5bc:  01 00 00 00  nop
a008c5c0:  01 00 00 00  nop
a008c5c4:  01 00 00 00  nop
a008c5c8:  82 70 40 11  udiv  %g1, %l1, %g1
a008c5cc:  b0 58 60 64  smul  %g1, 0x64, %i0
a008c5d0:  81 c7 e0 08  ret
a008c5d4:  81 e8 00 00  restore
