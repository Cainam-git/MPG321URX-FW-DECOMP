# leon2m FUN_a00a7d70 0xa00a7d70-0xa00a7e00 (144 bytes)
a00a7d70:  9d e3 bf 90  save  %sp, -112, %sp
a00a7d74:  67 ff 99 4c  call  0x4008e2a4
a00a7d78:  a0 10 20 06  mov  6, %l0
a00a7d7c:  82 10 20 06  mov  6, %g1
a00a7d80:  80 a0 60 05  cmp  %g1, 5
a00a7d84:  02 80 00 18  be  0xa00a7de4
a00a7d88:  80 a0 60 07  cmp  %g1, 7
a00a7d8c:  02 80 00 16  be  0xa00a7de4
a00a7d90:  90 10 20 01  mov  1, %o0
a00a7d94:  92 10 20 00  clr  %o1
a00a7d98:  94 10 27 c2  mov  0x7c2, %o2
a00a7d9c:  96 10 20 07  mov  7, %o3
a00a7da0:  98 10 20 06  mov  6, %o4
a00a7da4:  80 a0 60 06  cmp  %g1, 6
a00a7da8:  02 80 00 0d  be  0xa00a7ddc
a00a7dac:  9a 10 20 0a  mov  0xa, %o5
a00a7db0:  98 10 00 01  mov  %g1, %o4
a00a7db4:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00a7db8:  90 10 20 01  mov  1, %o0
a00a7dbc:  92 10 20 00  clr  %o1
a00a7dc0:  94 10 27 92  mov  0x792, %o2
a00a7dc4:  96 10 20 07  mov  7, %o3
a00a7dc8:  9a 10 20 0b  mov  0xb, %o5
a00a7dcc:  40 00 2d 46  call  0xa00b32e4
a00a7dd0:  a0 04 20 01  inc  %l0
a00a7dd4:  10 80 00 06  b  0xa00a7dec
a00a7dd8:  82 0c 20 ff  and  %l0, 0xff, %g1
a00a7ddc:  10 bf ff fc  b  0xa00a7dcc
a00a7de0:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00a7de4:  a0 04 20 01  inc  %l0
a00a7de8:  82 0c 20 ff  and  %l0, 0xff, %g1
a00a7dec:  80 a0 60 15  cmp  %g1, 0x15
a00a7df0:  08 bf ff e5  bleu  0xa00a7d84
a00a7df4:  80 a0 60 05  cmp  %g1, 5
a00a7df8:  81 c7 e0 08  ret
a00a7dfc:  81 e8 00 00  restore
