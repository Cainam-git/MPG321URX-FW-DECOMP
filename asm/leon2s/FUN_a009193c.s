# leon2s FUN_a009193c 0xa009193c-0xa0091960 (36 bytes)
a009193c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091940:  83 2a 20 03  sll  %o0, 3, %g1
a0091944:  82 20 40 08  sub  %g1, %o0, %g1
a0091948:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a009194c:  83 28 60 02  sll  %g1, 2, %g1
a0091950:  9a 13 61 80  or  %o5, 0x180, %o5
a0091954:  82 00 40 0d  add  %g1, %o5, %g1
a0091958:  81 c3 e0 08  retl
a009195c:  d0 08 60 15  ldub  [ %g1 + 0x15 ], %o0
