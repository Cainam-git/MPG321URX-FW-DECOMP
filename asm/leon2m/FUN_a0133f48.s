# leon2m FUN_a0133f48 0xa0133f48-0xa0133f80 (56 bytes)
a0133f48:  17 06 d3 a0  sethi  %hi(0x1b4e8000), %o3
a0133f4c:  82 12 e1 b5  or  %o3, 0x1b5, %g1	! 0x1b4e81b5
a0133f50:  80 52 80 01  umul  %o2, %g1, %g0
a0133f54:  99 40 00 00  rd  %y, %o4
a0133f58:  90 0a 20 ff  and  %o0, 0xff, %o0
a0133f5c:  94 0a 60 ff  and  %o1, 0xff, %o2
a0133f60:  97 33 20 07  srl  %o4, 7, %o3
a0133f64:  92 10 00 08  mov  %o0, %o1
a0133f68:  96 0a e0 ff  and  %o3, 0xff, %o3
a0133f6c:  90 10 20 05  mov  5, %o0
a0133f70:  98 10 20 01  mov  1, %o4
a0133f74:  82 13 c0 00  mov  %o7, %g1
a0133f78:  67 fd 6d 1f  call  0x4008f3f4
a0133f7c:  9e 10 40 00  mov  %g1, %o7
