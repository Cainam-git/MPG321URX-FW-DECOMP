# leon2s FUN_a00876ec 0xa00876ec-0xa0087710 (36 bytes)
a00876ec:  90 0a 20 ff  and  %o0, 0xff, %o0
a00876f0:  83 2a 20 02  sll  %o0, 2, %g1
a00876f4:  82 00 40 08  add  %g1, %o0, %g1
a00876f8:  1b 2a 01 ea  sethi  %hi(0xa807a800), %o5
a00876fc:  83 28 60 03  sll  %g1, 3, %g1
a0087700:  9a 13 61 28  or  %o5, 0x128, %o5
a0087704:  82 00 40 0d  add  %g1, %o5, %g1
a0087708:  81 c3 e0 08  retl
a008770c:  d0 08 60 15  ldub  [ %g1 + 0x15 ], %o0
