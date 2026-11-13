# leon2m FUN_a015e970 0xa015e970-0xa015e9a4 (52 bytes)
a015e970:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a015e974:  c2 00 63 34  ld  [ %g1 + 0x334 ], %g1	! 0xa802af34
a015e978:  80 a0 60 00  cmp  %g1, 0
a015e97c:  02 80 00 08  be  0xa015e99c
a015e980:  90 10 20 00  clr  %o0
a015e984:  90 10 00 01  mov  %g1, %o0
a015e988:  c2 02 20 04  ld  [ %o0 + 4 ], %g1
a015e98c:  80 88 60 01  btst  1, %g1
a015e990:  02 bf ff fe  be  0xa015e988
a015e994:  01 00 00 00  nop
a015e998:  d0 02 00 00  ld  [ %o0 ], %o0
a015e99c:  81 c3 e0 08  retl
a015e9a0:  01 00 00 00  nop
