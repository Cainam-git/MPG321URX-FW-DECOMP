# leon2m FUN_a014eba4 0xa014eba4-0xa014ebf8 (84 bytes)
a014eba4:  9d e3 bf 98  save  %sp, -104, %sp
a014eba8:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a014ebac:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014ebb0:  a2 10 60 80  or  %g1, 0x80, %l1
a014ebb4:  a0 10 20 00  clr  %l0
a014ebb8:  92 10 20 00  clr  %o1
a014ebbc:  d0 0c 40 09  ldub  [ %l1 + %o1 ], %o0
a014ebc0:  80 a6 00 08  cmp  %i0, %o0
a014ebc4:  a0 04 20 01  inc  %l0
a014ebc8:  90 10 00 18  mov  %i0, %o0
a014ebcc:  94 0e 60 ff  and  %i1, 0xff, %o2
a014ebd0:  12 80 00 04  bne  0xa014ebe0
a014ebd4:  96 10 20 01  mov  1, %o3
a014ebd8:  7f ff a6 99  call  0xa013863c
a014ebdc:  01 00 00 00  nop
a014ebe0:  92 0c 20 ff  and  %l0, 0xff, %o1
a014ebe4:  80 a2 60 08  cmp  %o1, 8
a014ebe8:  28 bf ff f6  bleu,a   0xa014ebc0
a014ebec:  d0 0c 40 09  ldub  [ %l1 + %o1 ], %o0
a014ebf0:  81 c7 e0 08  ret
a014ebf4:  81 e8 00 00  restore
