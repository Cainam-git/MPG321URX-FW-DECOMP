# leon2s FUN_a00858f0 0xa00858f0-0xa0085914 (36 bytes)
a00858f0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00858f4:  83 2a 20 02  sll  %o0, 2, %g1
a00858f8:  82 00 40 08  add  %g1, %o0, %g1
a00858fc:  1b 2a 01 ea  sethi  %hi(0xa807a800), %o5
a0085900:  83 28 60 03  sll  %g1, 3, %g1
a0085904:  9a 13 61 28  or  %o5, 0x128, %o5
a0085908:  82 00 40 0d  add  %g1, %o5, %g1
a008590c:  81 c3 e0 08  retl
a0085910:  d0 08 60 01  ldub  [ %g1 + 1 ], %o0
