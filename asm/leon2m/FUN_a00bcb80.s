# leon2m FUN_a00bcb80 0xa00bcb80-0xa00bcbcc (76 bytes)
a00bcb80:  9d e3 bf 98  save  %sp, -104, %sp
a00bcb84:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00bcb88:  d4 02 e3 ac  ld  [ %o3 + 0x3ac ], %o2	! 0xa802d3ac
a00bcb8c:  91 32 a0 1f  srl  %o2, 0x1f, %o0
a00bcb90:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bcb94:  82 12 60 78  or  %o1, 0x78, %g1	! 0xa802d078
a00bcb98:  9a 02 20 30  add  %o0, 0x30, %o5
a00bcb9c:  98 10 20 30  mov  0x30, %o4
a00bcba0:  da 28 60 09  stb  %o5, [ %g1 + 9 ]
a00bcba4:  d8 28 60 08  stb  %o4, [ %g1 + 8 ]
a00bcba8:  d8 28 60 07  stb  %o4, [ %g1 + 7 ]
a00bcbac:  7f ff f8 24  call  0xa00bac3c
a00bcbb0:  90 10 20 17  mov  0x17, %o0
a00bcbb4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bcbb8:  7f ff f7 66  call  0xa00ba950
a00bcbbc:  90 10 00 18  mov  %i0, %o0
a00bcbc0:  7f ff f8 09  call  0xa00babe4
a00bcbc4:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bcbc8:  01 00 00 00  nop
