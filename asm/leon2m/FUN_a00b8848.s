# leon2m FUN_a00b8848 0xa00b8848-0xa00b88b8 (112 bytes)
a00b8848:  9d e3 bf 98  save  %sp, -104, %sp
a00b884c:  92 10 20 00  clr  %o1
a00b8850:  40 02 38 c7  call  0xa0146b6c
a00b8854:  90 10 20 00  clr  %o0
a00b8858:  7f ff 61 e0  call  0xa0090fd8
a00b885c:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00b8860:  40 00 8e df  call  0xa00dc3dc
a00b8864:  01 00 00 00  nop
a00b8868:  d2 0c 20 8e  ldub  [ %l0 + 0x8e ], %o1
a00b886c:  90 12 60 06  or  %o1, 6, %o0
a00b8870:  d0 2c 20 8e  stb  %o0, [ %l0 + 0x8e ]
a00b8874:  40 02 29 86  call  0xa0142e8c
a00b8878:  90 10 20 00  clr  %o0
a00b887c:  82 0a 20 ff  and  %o0, 0xff, %g1
a00b8880:  92 10 20 16  mov  0x16, %o1
a00b8884:  80 a0 60 05  cmp  %g1, 5
a00b8888:  02 80 00 0a  be  0xa00b88b0
a00b888c:  90 10 20 00  clr  %o0
a00b8890:  40 02 33 74  call  0xa0145660
a00b8894:  01 00 00 00  nop
a00b8898:  95 2a 20 10  sll  %o0, 0x10, %o2
a00b889c:  80 a2 a0 00  cmp  %o2, 0
a00b88a0:  02 80 00 04  be  0xa00b88b0
a00b88a4:  d8 0c 20 8e  ldub  [ %l0 + 0x8e ], %o4
a00b88a8:  96 13 20 01  or  %o4, 1, %o3
a00b88ac:  d6 2c 20 8e  stb  %o3, [ %l0 + 0x8e ]
a00b88b0:  81 c7 e0 08  ret
a00b88b4:  81 e8 00 00  restore
