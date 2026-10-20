# leon2m FUN_a012b884 0xa012b884-0xa012b8a4 (32 bytes)
a012b884:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a012b888:  d2 00 61 a0  ld  [ %g1 + 0x1a0 ], %o1	! 0xa802e1a0
a012b88c:  93 32 60 1b  srl  %o1, 0x1b, %o1
a012b890:  90 0a 20 ff  and  %o0, 0xff, %o0
a012b894:  92 0a 60 01  and  %o1, 1, %o1
a012b898:  82 13 c0 00  mov  %o7, %g1
a012b89c:  40 00 34 bf  call  0xa0138b98
a012b8a0:  9e 10 40 00  mov  %g1, %o7
