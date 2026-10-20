# leon2s FUN_a008996c 0xa008996c-0xa0089a38 (204 bytes)
a008996c:  9d e3 bf 98  save  %sp, -104, %sp
a0089970:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0089974:  92 10 20 7b  mov  0x7b, %o1
a0089978:  40 00 77 cf  call  0xa00a78b4
a008997c:  90 10 00 18  mov  %i0, %o0
a0089980:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0089984:  9b 2e 20 03  sll  %i0, 3, %o5
a0089988:  82 10 61 04  or  %g1, 0x104, %g1
a008998c:  80 8a 20 01  btst  1, %o0
a0089990:  02 80 00 28  be  0xa0089a30
a0089994:  a0 03 40 01  add  %o5, %g1, %l0
a0089998:  c2 0c 20 04  ldub  [ %l0 + 4 ], %g1
a008999c:  80 a0 60 00  cmp  %g1, 0
a00899a0:  22 80 00 0d  be,a   0xa00899d4
a00899a4:  c2 0c 20 01  ldub  [ %l0 + 1 ], %g1
a00899a8:  40 00 a1 af  call  0xa00b2064
a00899ac:  01 00 00 00  nop
a00899b0:  c2 14 20 06  lduh  [ %l0 + 6 ], %g1
a00899b4:  82 22 00 01  sub  %o0, %g1, %g1
a00899b8:  92 10 20 73  mov  0x73, %o1
a00899bc:  80 a0 60 64  cmp  %g1, 0x64
a00899c0:  08 80 00 1c  bleu  0xa0089a30
a00899c4:  90 10 00 18  mov  %i0, %o0
a00899c8:  40 00 77 bb  call  0xa00a78b4
a00899cc:  01 00 00 00  nop
a00899d0:  30 80 00 15  b,a   0xa0089a24
a00899d4:  80 a0 60 00  cmp  %g1, 0
a00899d8:  02 80 00 16  be  0xa0089a30
a00899dc:  01 00 00 00  nop
a00899e0:  40 00 a1 a1  call  0xa00b2064
a00899e4:  01 00 00 00  nop
a00899e8:  c2 14 20 02  lduh  [ %l0 + 2 ], %g1
a00899ec:  82 22 00 01  sub  %o0, %g1, %g1
a00899f0:  92 10 20 73  mov  0x73, %o1
a00899f4:  80 a0 60 28  cmp  %g1, 0x28
a00899f8:  08 80 00 0e  bleu  0xa0089a30
a00899fc:  90 10 00 18  mov  %i0, %o0
a0089a00:  40 00 77 ad  call  0xa00a78b4
a0089a04:  01 00 00 00  nop
a0089a08:  94 0a 20 ff  and  %o0, 0xff, %o2
a0089a0c:  90 10 00 18  mov  %i0, %o0
a0089a10:  40 00 77 bb  call  0xa00a78fc
a0089a14:  92 10 20 73  mov  0x73, %o1
a0089a18:  82 10 20 01  mov  1, %g1
a0089a1c:  c2 2c 20 04  stb  %g1, [ %l0 + 4 ]
a0089a20:  c0 2c 20 01  clrb  [ %l0 + 1 ]
a0089a24:  40 00 a1 90  call  0xa00b2064
a0089a28:  01 00 00 00  nop
a0089a2c:  d0 34 20 06  sth  %o0, [ %l0 + 6 ]
a0089a30:  81 c7 e0 08  ret
a0089a34:  81 e8 00 00  restore
