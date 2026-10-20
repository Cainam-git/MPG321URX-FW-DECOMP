# leon2m FUN_a0146518 0xa0146518-0xa0146548 (48 bytes)
a0146518:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a014651c:  82 12 e3 78  or  %o3, 0x378, %g1	! 0xa802e378
a0146520:  98 0a a0 ff  and  %o2, 0xff, %o4
a0146524:  91 2a 20 10  sll  %o0, 0x10, %o0
a0146528:  93 2a 60 10  sll  %o1, 0x10, %o1
a014652c:  91 32 20 10  srl  %o0, 0x10, %o0
a0146530:  d6 10 60 0a  lduh  [ %g1 + 0xa ], %o3
a0146534:  d4 10 60 08  lduh  [ %g1 + 8 ], %o2
a0146538:  93 32 60 10  srl  %o1, 0x10, %o1
a014653c:  82 13 c0 00  mov  %o7, %g1
a0146540:  7f ff 4d 1b  call  0xa01199ac
a0146544:  9e 10 40 00  mov  %g1, %o7
