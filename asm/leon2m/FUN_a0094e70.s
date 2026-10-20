# leon2m FUN_a0094e70 0xa0094e70-0xa0094ed8 (104 bytes)
a0094e70:  9d e3 bf 98  save  %sp, -104, %sp
a0094e74:  31 2a 00 97  sethi  %hi(0xa8025c00), %i0
a0094e78:  d8 0e 20 55  ldub  [ %i0 + 0x55 ], %o4	! 0xa8025c55
a0094e7c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a0094e80:  d8 2b e3 ce  stb  %o4, [ %o7 + 0x3ce ]	! 0xa802d3ce
a0094e84:  40 00 4f 81  call  0xa00a8c88
a0094e88:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a0094e8c:  40 00 4d 6d  call  0xa00a8440
a0094e90:  b0 10 20 00  clr  %i0
a0094e94:  d6 0c 20 56  ldub  [ %l0 + 0x56 ], %o3
a0094e98:  94 02 e0 01  add  %o3, 1, %o2
a0094e9c:  92 0a a0 ff  and  %o2, 0xff, %o1
a0094ea0:  90 10 20 01  mov  1, %o0
a0094ea4:  40 00 4c a6  call  0xa00a813c
a0094ea8:  94 10 20 01  mov  1, %o2
a0094eac:  d2 0c 20 56  ldub  [ %l0 + 0x56 ], %o1
a0094eb0:  90 02 60 01  add  %o1, 1, %o0
a0094eb4:  90 0a 20 ff  and  %o0, 0xff, %o0
a0094eb8:  40 00 51 e6  call  0xa00a9650
a0094ebc:  92 10 20 00  clr  %o1
a0094ec0:  9a 10 20 53  mov  0x53, %o5
a0094ec4:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a0094ec8:  da 20 63 ec  st  %o5, [ %g1 + 0x3ec ]	! 0xa802afec
a0094ecc:  40 00 51 e1  call  0xa00a9650
a0094ed0:  93 e8 20 01  restore  %g0, 1, %o1
a0094ed4:  01 00 00 00  nop
