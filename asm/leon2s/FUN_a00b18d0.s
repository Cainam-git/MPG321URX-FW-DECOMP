# leon2s FUN_a00b18d0 0xa00b18d0-0xa00b192c (92 bytes)
a00b18d0:  9d e3 bf 98  save  %sp, -104, %sp
a00b18d4:  7f ff 92 4c  call  0xa0096204
a00b18d8:  01 00 00 00  nop
a00b18dc:  7f ff ff c3  call  0xa00b17e8
a00b18e0:  01 00 00 00  nop
a00b18e4:  7f ff 04 a6  call  0xa0072b7c
a00b18e8:  01 00 00 00  nop
a00b18ec:  40 00 01 61  call  0xa00b1e70
a00b18f0:  01 00 00 00  nop
a00b18f4:  7f ff ff ee  call  0xa00b18ac
a00b18f8:  01 00 00 00  nop
a00b18fc:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00b1900:  13 28 01 b1  sethi  %hi(0xa006c400), %o1
a00b1904:  90 12 21 80  or  %o0, 0x180, %o0
a00b1908:  7f ff 05 cf  call  0xa0073044
a00b190c:  92 12 61 b8  or  %o1, 0x1b8, %o1
a00b1910:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00b1914:  9a 13 60 fc  or  %o5, 0xfc, %o5	! 0xcf0114fc
a00b1918:  c2 03 40 00  ld  [ %o5 ], %g1
a00b191c:  82 10 60 80  or  %g1, 0x80, %g1
a00b1920:  c2 23 40 00  st  %g1, [ %o5 ]
a00b1924:  81 c7 e0 08  ret
a00b1928:  81 e8 00 00  restore
