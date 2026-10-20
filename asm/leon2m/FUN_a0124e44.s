# leon2m FUN_a0124e44 0xa0124e44-0xa0124ea4 (96 bytes)
a0124e44:  9d e3 bf 98  save  %sp, -104, %sp
a0124e48:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0124e4c:  11 00 06 90  sethi  %hi(0x1a4000), %o0
a0124e50:  9a 5e 20 16  smul  %i0, 0x16, %o5
a0124e54:  82 12 22 a8  or  %o0, 0x2a8, %g1
a0124e58:  80 a6 20 07  cmp  %i0, 7
a0124e5c:  a0 03 40 01  add  %o5, %g1, %l0
a0124e60:  18 80 00 0e  bgu  0xa0124e98
a0124e64:  b0 10 20 01  mov  1, %i0
a0124e68:  d2 0c 20 0e  ldub  [ %l0 + 0xe ], %o1
a0124e6c:  80 a2 60 ff  cmp  %o1, 0xff
a0124e70:  02 80 00 0a  be  0xa0124e98
a0124e74:  90 10 00 09  mov  %o1, %o0
a0124e78:  67 fd 9f b0  call  0x4008cd38
a0124e7c:  d2 0c 20 0f  ldub  [ %l0 + 0xf ], %o1
a0124e80:  98 0a 20 ff  and  %o0, 0xff, %o4
a0124e84:  de 0c 20 10  ldub  [ %l0 + 0x10 ], %o7
a0124e88:  96 1b 00 0f  xor  %o4, %o7, %o3
a0124e8c:  80 a0 00 0b  cmp  %g0, %o3
a0124e90:  94 60 3f ff  subx  %g0, -1, %o2
a0124e94:  b0 10 00 0a  mov  %o2, %i0
a0124e98:  b0 0e 20 01  and  %i0, 1, %i0
a0124e9c:  81 c7 e0 08  ret
a0124ea0:  81 e8 00 00  restore
