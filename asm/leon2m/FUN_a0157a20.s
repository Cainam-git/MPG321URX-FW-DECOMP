# leon2m FUN_a0157a20 0xa0157a20-0xa0157a60 (64 bytes)
a0157a20:  9d e3 bf 98  save  %sp, -104, %sp
a0157a24:  c2 06 60 08  ld  [ %i1 + 8 ], %g1
a0157a28:  90 10 00 18  mov  %i0, %o0
a0157a2c:  92 10 00 19  mov  %i1, %o1
a0157a30:  80 a0 60 00  cmp  %g1, 0
a0157a34:  12 80 00 04  bne  0xa0157a44
a0157a38:  b0 10 20 00  clr  %i0
a0157a3c:  10 80 00 07  b  0xa0157a58
a0157a40:  c0 26 60 04  clr  [ %i1 + 4 ]
a0157a44:  40 00 10 40  call  0xa015bb44
a0157a48:  01 00 00 00  nop
a0157a4c:  c0 26 60 04  clr  [ %i1 + 4 ]
a0157a50:  c0 26 60 08  clr  [ %i1 + 8 ]
a0157a54:  b0 10 00 08  mov  %o0, %i0
a0157a58:  81 c7 e0 08  ret
a0157a5c:  81 e8 00 00  restore
