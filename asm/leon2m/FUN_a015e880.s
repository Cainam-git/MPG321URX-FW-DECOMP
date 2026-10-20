# leon2m FUN_a015e880 0xa015e880-0xa015e8b0 (48 bytes)
a015e880:  19 2a 00 b9  sethi  %hi(0xa802e400), %o4
a015e884:  da 03 20 10  ld  [ %o4 + 0x10 ], %o5	! 0xa802e410
a015e888:  80 a3 60 00  cmp  %o5, 0
a015e88c:  12 80 00 06  bne  0xa015e8a4
a015e890:  82 03 40 08  add  %o5, %o0, %g1
a015e894:  03 2a 00 b9  sethi  %hi(0xa802e400), %g1
a015e898:  9a 10 60 18  or  %g1, 0x18, %o5	! 0xa802e418
a015e89c:  da 23 20 10  st  %o5, [ %o4 + 0x10 ]
a015e8a0:  82 03 40 08  add  %o5, %o0, %g1
a015e8a4:  c2 23 20 10  st  %g1, [ %o4 + 0x10 ]
a015e8a8:  81 c3 e0 08  retl
a015e8ac:  90 10 00 0d  mov  %o5, %o0
