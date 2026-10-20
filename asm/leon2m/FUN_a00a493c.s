# leon2m FUN_a00a493c 0xa00a493c-0xa00a49b8 (124 bytes)
a00a493c:  9d e3 bf 98  save  %sp, -104, %sp
a00a4940:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00a4944:  a0 12 22 90  or  %o0, 0x290, %l0	! 0xa802d290
a00a4948:  da 0c 20 09  ldub  [ %l0 + 9 ], %o5
a00a494c:  9a 03 60 01  inc  %o5
a00a4950:  82 0b 60 ff  and  %o5, 0xff, %g1
a00a4954:  96 10 20 0c  mov  0xc, %o3
a00a4958:  90 10 20 05  mov  5, %o0
a00a495c:  92 10 20 08  mov  8, %o1
a00a4960:  80 a0 60 64  cmp  %g1, 0x64
a00a4964:  08 80 00 05  bleu  0xa00a4978
a00a4968:  94 10 00 01  mov  %g1, %o2
a00a496c:  92 10 20 64  mov  0x64, %o1
a00a4970:  10 80 00 0a  b  0xa00a4998
a00a4974:  d2 2c 20 09  stb  %o1, [ %l0 + 9 ]
a00a4978:  7f ff ff 12  call  0xa00a45c0
a00a497c:  da 2c 20 09  stb  %o5, [ %l0 + 9 ]
a00a4980:  d4 0c 20 09  ldub  [ %l0 + 9 ], %o2
a00a4984:  90 10 20 0a  mov  0xa, %o0
a00a4988:  40 00 3b 60  call  0xa00b3708
a00a498c:  92 10 20 06  mov  6, %o1
a00a4990:  40 00 d0 d1  call  0xa00d8cd4
a00a4994:  01 00 00 00  nop
a00a4998:  40 00 c0 00  call  0xa00d4998
a00a499c:  01 00 00 00  nop
a00a49a0:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00a49a4:  d8 0a a0 8e  ldub  [ %o2 + 0x8e ], %o4	! 0xa802b08e
a00a49a8:  96 13 20 02  or  %o4, 2, %o3
a00a49ac:  d6 2a a0 8e  stb  %o3, [ %o2 + 0x8e ]
a00a49b0:  81 c7 e0 08  ret
a00a49b4:  81 e8 00 00  restore
