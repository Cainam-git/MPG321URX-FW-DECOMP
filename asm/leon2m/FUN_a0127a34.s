# leon2m FUN_a0127a34 0xa0127a34-0xa0127ab8 (132 bytes)
a0127a34:  9d e3 bf 98  save  %sp, -104, %sp
a0127a38:  40 00 78 30  call  0xa0145af8
a0127a3c:  90 10 20 10  mov  0x10, %o0
a0127a40:  83 2a 20 10  sll  %o0, 0x10, %g1
a0127a44:  80 a0 60 00  cmp  %g1, 0
a0127a48:  12 80 00 09  bne  0xa0127a6c
a0127a4c:  90 10 20 0d  mov  0xd, %o0
a0127a50:  40 00 78 2a  call  0xa0145af8
a0127a54:  01 00 00 00  nop
a0127a58:  93 2a 20 10  sll  %o0, 0x10, %o1
a0127a5c:  91 32 60 10  srl  %o1, 0x10, %o0
a0127a60:  80 a2 20 04  cmp  %o0, 4
a0127a64:  10 80 00 12  b  0xa0127aac
a0127a68:  82 60 3f ff  subx  %g0, -1, %g1
a0127a6c:  40 00 78 23  call  0xa0145af8
a0127a70:  01 00 00 00  nop
a0127a74:  83 2a 20 10  sll  %o0, 0x10, %g1
a0127a78:  9f 30 60 10  srl  %g1, 0x10, %o7
a0127a7c:  9b 2b e0 04  sll  %o7, 4, %o5
a0127a80:  98 23 40 0f  sub  %o5, %o7, %o4
a0127a84:  b1 2b 20 02  sll  %o4, 2, %i0
a0127a88:  40 00 78 1c  call  0xa0145af8
a0127a8c:  90 10 20 0b  mov  0xb, %o0
a0127a90:  97 2a 20 10  sll  %o0, 0x10, %o3
a0127a94:  95 32 e0 10  srl  %o3, 0x10, %o2
a0127a98:  a0 06 00 0a  add  %i0, %o2, %l0
a0127a9c:  80 a4 20 13  cmp  %l0, 0x13
a0127aa0:  14 80 00 03  bg  0xa0127aac
a0127aa4:  82 10 20 01  mov  1, %g1
a0127aa8:  82 10 20 00  clr  %g1
a0127aac:  b0 08 60 01  and  %g1, 1, %i0
a0127ab0:  81 c7 e0 08  ret
a0127ab4:  81 e8 00 00  restore
