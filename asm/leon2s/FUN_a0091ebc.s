# leon2s FUN_a0091ebc 0xa0091ebc-0xa0091eec (48 bytes)
a0091ebc:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091ec0:  9b 2a 20 03  sll  %o0, 3, %o5
a0091ec4:  9a 23 40 08  sub  %o5, %o0, %o5
a0091ec8:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0091ecc:  9b 2b 60 02  sll  %o5, 2, %o5
a0091ed0:  82 10 61 80  or  %g1, 0x180, %g1
a0091ed4:  9a 03 40 01  add  %o5, %g1, %o5
a0091ed8:  d2 2b 60 02  stb  %o1, [ %o5 + 2 ]
a0091edc:  92 0a 60 ff  and  %o1, 0xff, %o1
a0091ee0:  82 13 c0 00  mov  %o7, %g1
a0091ee4:  7f ff ff e3  call  0xa0091e70
a0091ee8:  9e 10 40 00  mov  %g1, %o7
