# leon2m FUN_a009b864 0xa009b864-0xa009b8e0 (124 bytes)
a009b864:  9d e3 bf 98  save  %sp, -104, %sp
a009b868:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a009b86c:  a0 14 62 90  or  %l1, 0x290, %l0	! 0xa802d290
a009b870:  40 00 39 16  call  0xa00a9cc8
a009b874:  d0 0c 21 90  ldub  [ %l0 + 0x190 ], %o0
a009b878:  c2 0c 21 90  ldub  [ %l0 + 0x190 ], %g1
a009b87c:  80 a0 60 00  cmp  %g1, 0
a009b880:  12 80 00 03  bne  0xa009b88c
a009b884:  82 00 7f ff  add  %g1, -1, %g1
a009b888:  82 10 20 06  mov  6, %g1
a009b88c:  c2 2c 21 90  stb  %g1, [ %l0 + 0x190 ]
a009b890:  a0 14 62 90  or  %l1, 0x290, %l0
a009b894:  d0 0c 21 90  ldub  [ %l0 + 0x190 ], %o0
a009b898:  40 00 39 45  call  0xa00a9dac
a009b89c:  92 10 20 01  mov  1, %o1
a009b8a0:  11 2a 00 97  sethi  %hi(0xa8025c00), %o0
a009b8a4:  c2 0a 20 56  ldub  [ %o0 + 0x56 ], %g1	! 0xa8025c56
a009b8a8:  da 0c 21 90  ldub  [ %l0 + 0x190 ], %o5
a009b8ac:  92 10 00 01  mov  %g1, %o1
a009b8b0:  90 10 20 02  mov  2, %o0
a009b8b4:  80 a3 40 01  cmp  %o5, %g1
a009b8b8:  02 80 00 05  be  0xa009b8cc
a009b8bc:  94 10 20 00  clr  %o2
a009b8c0:  92 10 00 01  mov  %g1, %o1
a009b8c4:  90 10 20 02  mov  2, %o0
a009b8c8:  94 10 20 01  mov  1, %o2
a009b8cc:  40 00 32 1c  call  0xa00a813c
a009b8d0:  01 00 00 00  nop
a009b8d4:  40 00 73 f9  call  0xa00b88b8
a009b8d8:  81 e8 00 00  restore
a009b8dc:  01 00 00 00  nop
