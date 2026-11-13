# leon2s MAILBOX_DUMP 0xa0072b04-0xa0072b7c (120 bytes)
a0072b04:  9d e3 be d8  save  %sp, -296, %sp
a0072b08:  a0 07 bf 38  add  %fp, -200, %l0
a0072b0c:  92 10 20 00  clr  %o1
a0072b10:  94 10 20 c0  mov  0xc0, %o2
a0072b14:  40 00 fa a6  call  0xa00b15ac
a0072b18:  90 10 00 10  mov  %l0, %o0
a0072b1c:  94 10 00 10  mov  %l0, %o2
a0072b20:  90 10 20 01  mov  1, %o0
a0072b24:  92 10 20 00  clr  %o1
a0072b28:  7f ff ff 92  call  0xa0072970
a0072b2c:  96 10 20 30  mov  0x30, %o3
a0072b30:  a0 10 20 00  clr  %l0
a0072b34:  82 0c 20 ff  and  %l0, 0xff, %g1
a0072b38:  83 28 60 02  sll  %g1, 2, %g1
a0072b3c:  82 07 80 01  add  %fp, %g1, %g1
a0072b40:  11 28 01 99  sethi  %hi(0xa0066400), %o0
a0072b44:  d2 00 7f 38  ld  [ %g1 + -200 ], %o1
a0072b48:  40 00 01 3f  call  0xa0073044
a0072b4c:  90 12 21 50  or  %o0, 0x150, %o0
a0072b50:  a0 04 20 01  inc  %l0
a0072b54:  92 0c 20 ff  and  %l0, 0xff, %o1
a0072b58:  80 a2 60 2f  cmp  %o1, 0x2f
a0072b5c:  08 bf ff f7  bleu  0xa0072b38
a0072b60:  82 0c 20 ff  and  %l0, 0xff, %g1
a0072b64:  11 28 01 99  sethi  %hi(0xa0066400), %o0
a0072b68:  40 00 01 37  call  0xa0073044
a0072b6c:  90 12 21 60  or  %o0, 0x160, %o0	! 0xa0066560
a0072b70:  01 00 00 00  nop
a0072b74:  81 c7 e0 08  ret
a0072b78:  81 e8 00 00  restore
