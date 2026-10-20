# leon2s FUN_a00858cc 0xa00858cc-0xa00858f0 (36 bytes)
a00858cc:  80 8a 20 ff  btst  0xff, %o0
a00858d0:  12 80 00 05  bne  0xa00858e4
a00858d4:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00858d8:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00858dc:  d2 28 61 02  stb  %o1, [ %g1 + 0x102 ]	! 0xa807cd02
a00858e0:  30 80 00 02  b,a   0xa00858e8
a00858e4:  d2 28 61 2c  stb  %o1, [ %g1 + 0x12c ]
a00858e8:  81 c3 e0 08  retl
a00858ec:  01 00 00 00  nop
