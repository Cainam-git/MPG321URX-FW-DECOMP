# leon2s FUN_a00b1794 0xa00b1794-0xa00b17e8 (84 bytes)
a00b1794:  83 2a 20 10  sll  %o0, 0x10, %g1
a00b1798:  80 a0 60 00  cmp  %g1, 0
a00b179c:  03 00 00 30  sethi  %hi(0xc000), %g1
a00b17a0:  96 10 63 50  or  %g1, 0x350, %o3	! 0xc350
a00b17a4:  02 80 00 0f  be  0xa00b17e0
a00b17a8:  98 10 20 00  clr  %o4
a00b17ac:  9a 10 20 00  clr  %o5
a00b17b0:  01 00 00 00  nop
a00b17b4:  9a 03 60 01  inc  %o5
a00b17b8:  83 2b 60 10  sll  %o5, 0x10, %g1
a00b17bc:  83 30 60 10  srl  %g1, 0x10, %g1
a00b17c0:  80 a0 40 0b  cmp  %g1, %o3
a00b17c4:  0a bf ff fb  bcs  0xa00b17b0
a00b17c8:  83 2a 20 10  sll  %o0, 0x10, %g1
a00b17cc:  98 03 20 01  inc  %o4
a00b17d0:  9b 2b 20 10  sll  %o4, 0x10, %o5
a00b17d4:  80 a0 40 0d  cmp  %g1, %o5
a00b17d8:  18 bf ff f6  bgu  0xa00b17b0
a00b17dc:  9a 10 20 00  clr  %o5
a00b17e0:  81 c3 e0 08  retl
a00b17e4:  01 00 00 00  nop
