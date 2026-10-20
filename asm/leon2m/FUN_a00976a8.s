# leon2m FUN_a00976a8 0xa00976a8-0xa00976f8 (80 bytes)
a00976a8:  9d e3 bf 98  save  %sp, -104, %sp
a00976ac:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a00976b0:  40 00 46 0e  call  0xa00a8ee8
a00976b4:  d0 0c 20 56  ldub  [ %l0 + 0x56 ], %o0	! 0xa8025c56
a00976b8:  d2 0c 20 56  ldub  [ %l0 + 0x56 ], %o1
a00976bc:  90 10 20 00  clr  %o0
a00976c0:  40 00 42 9f  call  0xa00a813c
a00976c4:  94 10 20 00  clr  %o2
a00976c8:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00976cc:  d2 0a a2 af  ldub  [ %o2 + 0x2af ], %o1	! 0xa802d2af
a00976d0:  90 10 20 00  clr  %o0
a00976d4:  40 00 42 9a  call  0xa00a813c
a00976d8:  94 10 20 00  clr  %o2
a00976dc:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a00976e0:  d0 00 63 ec  ld  [ %g1 + 0x3ec ], %o0	! 0xa802afec
a00976e4:  b0 02 3f dd  add  %o0, -35, %i0
a00976e8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00976ec:  40 00 46 48  call  0xa00a900c
a00976f0:  93 e8 20 02  restore  %g0, 2, %o1
a00976f4:  01 00 00 00  nop
