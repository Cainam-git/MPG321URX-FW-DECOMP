# leon2s FUN_a0088ea0 0xa0088ea0-0xa0088ee0 (64 bytes)
a0088ea0:  9d e3 bf 98  save  %sp, -104, %sp
a0088ea4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0088ea8:  7f ff ff 12  call  0xa0088af0
a0088eac:  90 10 00 18  mov  %i0, %o0
a0088eb0:  80 8a 20 ff  btst  0xff, %o0
a0088eb4:  90 10 00 18  mov  %i0, %o0
a0088eb8:  02 80 00 08  be  0xa0088ed8
a0088ebc:  b0 10 20 00  clr  %i0
a0088ec0:  40 00 86 43  call  0xa00aa7cc
a0088ec4:  01 00 00 00  nop
a0088ec8:  90 0a 20 ff  and  %o0, 0xff, %o0
a0088ecc:  90 1a 20 04  xor  %o0, 4, %o0
a0088ed0:  80 a0 00 08  cmp  %g0, %o0
a0088ed4:  b0 60 3f ff  subx  %g0, -1, %i0
a0088ed8:  81 c7 e0 08  ret
a0088edc:  81 e8 00 00  restore
