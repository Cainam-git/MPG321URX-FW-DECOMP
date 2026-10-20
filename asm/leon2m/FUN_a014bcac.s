# leon2m FUN_a014bcac 0xa014bcac-0xa014bcc8 (28 bytes)
a014bcac:  9d e3 bf 98  save  %sp, -104, %sp
a014bcb0:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014bcb4:  7f ff d5 45  call  0xa01411c8
a014bcb8:  d0 08 63 ed  ldub  [ %g1 + 0x3ed ], %o0	! 0xa802e3ed
a014bcbc:  b0 0a 20 ff  and  %o0, 0xff, %i0
a014bcc0:  81 c7 e0 08  ret
a014bcc4:  81 e8 00 00  restore
