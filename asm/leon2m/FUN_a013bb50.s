# leon2m FUN_a013bb50 0xa013bb50-0xa013bbb8 (104 bytes)
a013bb50:  9d e3 bf 98  save  %sp, -104, %sp
a013bb54:  b0 0e 20 ff  and  %i0, 0xff, %i0
a013bb58:  40 00 04 7d  call  0xa013cd4c
a013bb5c:  90 10 00 18  mov  %i0, %o0
a013bb60:  80 a6 20 00  cmp  %i0, 0
a013bb64:  02 80 00 08  be  0xa013bb84
a013bb68:  a0 10 00 08  mov  %o0, %l0
a013bb6c:  c2 14 20 08  lduh  [ %l0 + 8 ], %g1
a013bb70:  95 28 60 10  sll  %g1, 0x10, %o2
a013bb74:  93 32 a0 10  srl  %o2, 0x10, %o1
a013bb78:  80 a2 69 93  cmp  %o1, 0x993
a013bb7c:  10 80 00 0d  b  0xa013bbb0
a013bb80:  b0 60 3f ff  subx  %g0, -1, %i0
a013bb84:  c2 02 00 00  ld  [ %o0 ], %g1
a013bb88:  91 30 60 0c  srl  %g1, 0xc, %o0
a013bb8c:  40 00 11 43  call  0xa0140098
a013bb90:  90 0a 20 0f  and  %o0, 0xf, %o0
a013bb94:  80 8a 20 ff  btst  0xff, %o0
a013bb98:  02 bf ff f5  be  0xa013bb6c
a013bb9c:  b0 10 20 01  mov  1, %i0
a013bba0:  c2 14 20 08  lduh  [ %l0 + 8 ], %g1
a013bba4:  80 a0 6b b8  cmp  %g1, 0xbb8
a013bba8:  08 bf ff f3  bleu  0xa013bb74
a013bbac:  95 28 60 10  sll  %g1, 0x10, %o2
a013bbb0:  81 c7 e0 08  ret
a013bbb4:  81 e8 00 00  restore
