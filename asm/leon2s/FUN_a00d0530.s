# leon2s FUN_a00d0530 0xa00d0530-0xa00d0550 (32 bytes)
a00d0530:  9d e3 bf 98  save  %sp, -104, %sp
a00d0534:  7f ff fd 61  call  0xa00cfab8
a00d0538:  b1 2e 20 02  sll  %i0, 2, %i0
a00d053c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d0540:  82 10 63 60  or  %g1, 0x360, %g1	! 0xa8078b60
a00d0544:  f2 20 40 18  st  %i1, [ %g1 + %i0 ]
a00d0548:  81 c7 e0 08  ret
a00d054c:  81 e8 00 00  restore
