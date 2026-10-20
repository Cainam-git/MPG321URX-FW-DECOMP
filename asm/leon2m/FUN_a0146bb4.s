# leon2m FUN_a0146bb4 0xa0146bb4-0xa0146be8 (52 bytes)
a0146bb4:  9d e3 bf 98  save  %sp, -104, %sp
a0146bb8:  7f ff 51 f3  call  0xa011b384
a0146bbc:  90 0e 20 ff  and  %i0, 0xff, %o0
a0146bc0:  90 0a 20 ff  and  %o0, 0xff, %o0
a0146bc4:  9a 1a 20 02  xor  %o0, 2, %o5
a0146bc8:  80 a2 20 01  cmp  %o0, 1
a0146bcc:  02 80 00 05  be  0xa0146be0
a0146bd0:  b0 10 20 01  mov  1, %i0
a0146bd4:  80 a0 00 0d  cmp  %g0, %o5
a0146bd8:  82 60 3f ff  subx  %g0, -1, %g1
a0146bdc:  b0 00 40 01  add  %g1, %g1, %i0
a0146be0:  81 c7 e0 08  ret
a0146be4:  81 e8 00 00  restore
