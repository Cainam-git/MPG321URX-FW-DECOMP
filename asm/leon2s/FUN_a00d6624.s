# leon2s FUN_a00d6624 0xa00d6624-0xa00d6694 (112 bytes)
a00d6624:  9d e3 bf 98  save  %sp, -104, %sp
a00d6628:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00d662c:  90 10 00 18  mov  %i0, %o0
a00d6630:  40 3b 81 62  call  0xa0fb6bb8
a00d6634:  92 10 20 9f  mov  0x9f, %o1
a00d6638:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d663c:  80 a6 20 01  cmp  %i0, 1
a00d6640:  91 32 20 06  srl  %o0, 6, %o0
a00d6644:  82 10 20 00  clr  %g1
a00d6648:  02 80 00 11  be  0xa00d668c
a00d664c:  b0 10 20 00  clr  %i0
a00d6650:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d6654:  80 a2 20 01  cmp  %o0, 1
a00d6658:  22 80 00 0c  be,a   0xa00d6688
a00d665c:  82 10 20 01  mov  1, %g1
a00d6660:  04 80 00 0a  ble  0xa00d6688
a00d6664:  80 a2 20 02  cmp  %o0, 2
a00d6668:  02 80 00 05  be  0xa00d667c
a00d666c:  80 a2 20 03  cmp  %o0, 3
a00d6670:  02 80 00 05  be  0xa00d6684
a00d6674:  b0 08 60 ff  and  %g1, 0xff, %i0
a00d6678:  30 80 00 05  b,a   0xa00d668c
a00d667c:  10 80 00 03  b  0xa00d6688
a00d6680:  82 10 20 02  mov  2, %g1
a00d6684:  82 10 20 03  mov  3, %g1
a00d6688:  b0 08 60 ff  and  %g1, 0xff, %i0
a00d668c:  81 c7 e0 08  ret
a00d6690:  81 e8 00 00  restore
