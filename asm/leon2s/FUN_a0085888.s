# leon2s FUN_a0085888 0xa0085888-0xa00858cc (68 bytes)
a0085888:  92 0a 60 ff  and  %o1, 0xff, %o1
a008588c:  80 a2 60 00  cmp  %o1, 0
a0085890:  02 80 00 06  be  0xa00858a8
a0085894:  9a 10 20 01  mov  1, %o5
a0085898:  80 a2 60 01  cmp  %o1, 1
a008589c:  02 80 00 03  be  0xa00858a8
a00858a0:  9a 10 20 02  mov  2, %o5
a00858a4:  9a 10 20 04  mov  4, %o5
a00858a8:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00858ac:  80 8a 20 ff  btst  0xff, %o0
a00858b0:  02 80 00 04  be  0xa00858c0
a00858b4:  82 10 61 68  or  %g1, 0x168, %g1
a00858b8:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00858bc:  82 10 61 00  or  %g1, 0x100, %g1	! 0xa807cd00
a00858c0:  da 28 60 01  stb  %o5, [ %g1 + 1 ]
a00858c4:  81 c3 e0 08  retl
a00858c8:  01 00 00 00  nop
