# leon2m FUN_a00b3ac8 0xa00b3ac8-0xa00b3b5c (148 bytes)
a00b3ac8:  9d e3 bf 98  save  %sp, -104, %sp
a00b3acc:  90 10 21 11  mov  0x111, %o0
a00b3ad0:  40 02 4c 20  call  0xa0146b50
a00b3ad4:  92 10 20 00  clr  %o1
a00b3ad8:  90 10 20 00  clr  %o0
a00b3adc:  40 02 4c 24  call  0xa0146b6c
a00b3ae0:  92 10 20 00  clr  %o1
a00b3ae4:  a2 10 20 00  clr  %l1
a00b3ae8:  a0 10 20 00  clr  %l0
a00b3aec:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00b3af0:  25 00 06 39  sethi  %hi(0x18e400), %l2
a00b3af4:  95 2c 20 03  sll  %l0, 3, %o2
a00b3af8:  9e 22 80 10  sub  %o2, %l0, %o7
a00b3afc:  99 2b e0 02  sll  %o7, 2, %o4
a00b3b00:  9a 14 e2 90  or  %l3, 0x290, %o5
a00b3b04:  96 03 00 10  add  %o4, %l0, %o3
a00b3b08:  c2 0b 60 08  ldub  [ %o5 + 8 ], %g1
a00b3b0c:  90 02 c0 01  add  %o3, %g1, %o0
a00b3b10:  93 2a 20 10  sll  %o0, 0x10, %o1
a00b3b14:  93 32 60 10  srl  %o1, 0x10, %o1
a00b3b18:  7f ff bf 4b  call  0xa00a3844
a00b3b1c:  90 14 a1 4c  or  %l2, 0x14c, %o0
a00b3b20:  98 10 00 08  mov  %o0, %o4
a00b3b24:  94 04 00 10  add  %l0, %l0, %o2
a00b3b28:  94 02 a0 06  add  %o2, 6, %o2
a00b3b2c:  90 10 20 00  clr  %o0
a00b3b30:  92 10 20 2a  mov  0x2a, %o1
a00b3b34:  96 10 20 01  mov  1, %o3
a00b3b38:  9a 10 20 00  clr  %o5
a00b3b3c:  7f ff bd 9a  call  0xa00a31a4
a00b3b40:  a2 04 60 01  inc  %l1
a00b3b44:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00b3b48:  80 a4 20 02  cmp  %l0, 2
a00b3b4c:  08 bf ff eb  bleu  0xa00b3af8
a00b3b50:  95 2c 20 03  sll  %l0, 3, %o2
a00b3b54:  81 c7 e0 08  ret
a00b3b58:  81 e8 00 00  restore
