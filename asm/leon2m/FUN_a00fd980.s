# leon2m FUN_a00fd980 0xa00fd980-0xa00fd9a0 (32 bytes)
a00fd980:  80 8a 20 ff  btst  0xff, %o0
a00fd984:  02 80 00 05  be  0xa00fd998
a00fd988:  82 10 20 00  clr  %g1
a00fd98c:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a00fd990:  d0 28 61 80  stb  %o0, [ %g1 + 0x180 ]	! 0xa802c980
a00fd994:  82 10 20 01  mov  1, %g1
a00fd998:  81 c3 e0 08  retl
a00fd99c:  90 10 00 01  mov  %g1, %o0
