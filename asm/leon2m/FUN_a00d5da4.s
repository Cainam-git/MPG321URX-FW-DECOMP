# leon2m FUN_a00d5da4 0xa00d5da4-0xa00d5e0c (104 bytes)
a00d5da4:  9d e3 bf 98  save  %sp, -104, %sp
a00d5da8:  7f fe b3 a9  call  0xa0082c4c
a00d5dac:  01 00 00 00  nop
a00d5db0:  80 8a 20 ff  btst  0xff, %o0
a00d5db4:  02 80 00 0d  be  0xa00d5de8
a00d5db8:  01 00 00 00  nop
a00d5dbc:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d5dc0:  c2 08 62 95  ldub  [ %g1 + 0x295 ], %g1	! 0xa802d295
a00d5dc4:  80 a0 60 01  cmp  %g1, 1
a00d5dc8:  02 80 00 05  be  0xa00d5ddc
a00d5dcc:  b0 10 20 01  mov  1, %i0
a00d5dd0:  80 a0 60 02  cmp  %g1, 2
a00d5dd4:  02 80 00 09  be  0xa00d5df8
a00d5dd8:  b0 10 20 00  clr  %i0
a00d5ddc:  b0 0e 20 03  and  %i0, 3, %i0
a00d5de0:  40 01 cc 5b  call  0xa0148f4c
a00d5de4:  81 e8 00 00  restore
a00d5de8:  40 01 3b 08  call  0xa0124a08
a00d5dec:  01 00 00 00  nop
a00d5df0:  10 bf ff f4  b  0xa00d5dc0
a00d5df4:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d5df8:  b0 10 20 02  mov  2, %i0
a00d5dfc:  b0 0e 20 03  and  %i0, 3, %i0
a00d5e00:  40 01 cc 53  call  0xa0148f4c
a00d5e04:  81 e8 00 00  restore
a00d5e08:  01 00 00 00  nop
