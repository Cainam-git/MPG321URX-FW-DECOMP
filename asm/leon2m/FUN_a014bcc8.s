# leon2m FUN_a014bcc8 0xa014bcc8-0xa014bce4 (28 bytes)
a014bcc8:  9d e3 bf 98  save  %sp, -104, %sp
a014bccc:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014bcd0:  7f ff d5 4a  call  0xa01411f8
a014bcd4:  d0 08 63 ed  ldub  [ %g1 + 0x3ed ], %o0	! 0xa802e3ed
a014bcd8:  b0 0a 20 ff  and  %o0, 0xff, %i0
a014bcdc:  81 c7 e0 08  ret
a014bce0:  81 e8 00 00  restore
