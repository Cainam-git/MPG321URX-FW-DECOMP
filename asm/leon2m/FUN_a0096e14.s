# leon2m FUN_a0096e14 0xa0096e14-0xa0096e9c (136 bytes)
a0096e14:  9d e3 bf 98  save  %sp, -104, %sp
a0096e18:  15 2a 00 97  sethi  %hi(0xa8025c00), %o2
a0096e1c:  e2 0a a0 56  ldub  [ %o2 + 0x56 ], %l1	! 0xa8025c56
a0096e20:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a0096e24:  a0 14 22 90  or  %l0, 0x290, %l0	! 0xa802d290
a0096e28:  92 0c 60 03  and  %l1, 3, %o1
a0096e2c:  03 00 03 00  sethi  %hi(0xc0000), %g1
a0096e30:  d0 04 20 ac  ld  [ %l0 + 0xac ], %o0
a0096e34:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0096e38:  b2 2a 00 01  andn  %o0, %g1, %i1
a0096e3c:  9b 2a 60 12  sll  %o1, 0x12, %o5
a0096e40:  f0 04 63 ec  ld  [ %l1 + 0x3ec ], %i0
a0096e44:  9e 16 40 0d  or  %i1, %o5, %o7
a0096e48:  98 06 3f 89  add  %i0, -119, %o4
a0096e4c:  de 24 20 ac  st  %o7, [ %l0 + 0xac ]
a0096e50:  40 00 49 5b  call  0xa00a93bc
a0096e54:  90 0b 20 ff  and  %o4, 0xff, %o0
a0096e58:  d6 04 20 ac  ld  [ %l0 + 0xac ], %o3
a0096e5c:  95 32 e0 12  srl  %o3, 0x12, %o2
a0096e60:  90 0a a0 03  and  %o2, 3, %o0
a0096e64:  40 00 49 fb  call  0xa00a9650
a0096e68:  92 10 20 00  clr  %o1
a0096e6c:  d0 04 20 ac  ld  [ %l0 + 0xac ], %o0
a0096e70:  93 32 20 12  srl  %o0, 0x12, %o1
a0096e74:  92 0a 60 03  and  %o1, 3, %o1
a0096e78:  90 10 20 01  mov  1, %o0
a0096e7c:  40 00 44 b0  call  0xa00a813c
a0096e80:  94 10 20 01  mov  1, %o2
a0096e84:  82 10 20 1d  mov  0x1d, %g1
a0096e88:  c2 24 63 ec  st  %g1, [ %l1 + 0x3ec ]
a0096e8c:  b0 10 20 05  mov  5, %i0
a0096e90:  40 00 48 5f  call  0xa00a900c
a0096e94:  93 e8 20 01  restore  %g0, 1, %o1
a0096e98:  01 00 00 00  nop
