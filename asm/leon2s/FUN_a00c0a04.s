# leon2s FUN_a00c0a04 0xa00c0a04-0xa00c0a88 (132 bytes)
a00c0a04:  9d e3 bf 98  save  %sp, -104, %sp
a00c0a08:  98 10 20 00  clr  %o4
a00c0a0c:  90 0b 20 ff  and  %o4, 0xff, %o0
a00c0a10:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00c0a14:  83 2a 20 04  sll  %o0, 4, %g1
a00c0a18:  9a 13 61 c8  or  %o5, 0x1c8, %o5
a00c0a1c:  82 00 40 0d  add  %g1, %o5, %g1
a00c0a20:  c2 08 60 04  ldub  [ %g1 + 4 ], %g1
a00c0a24:  83 38 40 18  sra  %g1, %i0, %g1
a00c0a28:  80 88 60 01  btst  1, %g1
a00c0a2c:  22 80 00 10  be,a   0xa00c0a6c
a00c0a30:  98 03 20 01  inc  %o4
a00c0a34:  80 a2 20 03  cmp  %o0, 3
a00c0a38:  38 80 00 08  bgu,a   0xa00c0a58
a00c0a3c:  90 03 3f fc  add  %o4, -4, %o0
a00c0a40:  40 3b dd 16  call  0xa0fb7e98
a00c0a44:  92 10 20 2e  mov  0x2e, %o1
a00c0a48:  90 0a 20 20  and  %o0, 0x20, %o0
a00c0a4c:  80 a0 00 08  cmp  %g0, %o0
a00c0a50:  10 80 00 0c  b  0xa00c0a80
a00c0a54:  b0 40 20 00  addx  %g0, 0, %i0
a00c0a58:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c0a5c:  40 3b d8 57  call  0xa0fb6bb8
a00c0a60:  92 10 22 a9  mov  0x2a9, %o1
a00c0a64:  10 80 00 07  b  0xa00c0a80
a00c0a68:  b0 0a 20 01  and  %o0, 1, %i0
a00c0a6c:  82 0b 20 ff  and  %o4, 0xff, %g1
a00c0a70:  80 a0 60 05  cmp  %g1, 5
a00c0a74:  08 bf ff e7  bleu  0xa00c0a10
a00c0a78:  90 0b 20 ff  and  %o4, 0xff, %o0
a00c0a7c:  b0 10 20 00  clr  %i0
a00c0a80:  81 c7 e0 08  ret
a00c0a84:  81 e8 00 00  restore
