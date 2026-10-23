# leon2m FUN_a011cd80 0xa011cd80-0xa011cdb8 (56 bytes)
a011cd80:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011cd84:  80 8a 20 ff  btst  0xff, %o0
a011cd88:  02 80 00 04  be  0xa011cd98
a011cd8c:  82 10 63 8c  or  %g1, 0x38c, %g1
a011cd90:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a011cd94:  82 12 23 a0  or  %o0, 0x3a0, %g1	! 0xcf0117a0
a011cd98:  c2 00 40 00  ld  [ %g1 ], %g1
a011cd9c:  9a 10 20 9f  mov  0x9f, %o5
a011cda0:  01 00 00 00  nop
a011cda4:  9a 83 7f ff  addcc  %o5, -1, %o5
a011cda8:  1c bf ff fe  bpos  0xa011cda0
a011cdac:  01 00 00 00  nop
a011cdb0:  81 c3 e0 08  retl
a011cdb4:  90 08 60 ff  and  %g1, 0xff, %o0
