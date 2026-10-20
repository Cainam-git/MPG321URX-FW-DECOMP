# leon2m FUN_a00d29c0 0xa00d29c0-0xa00d2a28 (104 bytes)
a00d29c0:  9d e3 bf 98  save  %sp, -104, %sp
a00d29c4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d29c8:  de 02 62 90  ld  [ %o1 + 0x290 ], %o7	! 0xa802d290
a00d29cc:  95 33 e0 09  srl  %o7, 9, %o2
a00d29d0:  94 0a a0 01  and  %o2, 1, %o2
a00d29d4:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a00d29d8:  d4 28 60 56  stb  %o2, [ %g1 + 0x56 ]	! 0xa8025c56
a00d29dc:  d6 0e 20 07  ldub  [ %i0 + 7 ], %o3
a00d29e0:  80 a0 00 0b  cmp  %g0, %o3
a00d29e4:  b0 40 20 00  addx  %g0, 0, %i0
a00d29e8:  9b 2e 20 09  sll  %i0, 9, %o5
a00d29ec:  98 0b fd ff  and  %o7, -513, %o4
a00d29f0:  96 13 00 0d  or  %o4, %o5, %o3
a00d29f4:  91 32 e0 09  srl  %o3, 9, %o0
a00d29f8:  82 0a 20 01  and  %o0, 1, %g1
a00d29fc:  80 a2 80 01  cmp  %o2, %g1
a00d2a00:  02 80 00 08  be  0xa00d2a20
a00d2a04:  d6 22 62 90  st  %o3, [ %o1 + 0x290 ]
a00d2a08:  40 00 0b c4  call  0xa00d5918
a00d2a0c:  01 00 00 00  nop
a00d2a10:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00d2a14:  d8 0a 60 8e  ldub  [ %o1 + 0x8e ], %o4	! 0xa802b08e
a00d2a18:  90 13 20 02  or  %o4, 2, %o0
a00d2a1c:  d0 2a 60 8e  stb  %o0, [ %o1 + 0x8e ]
a00d2a20:  81 c7 e0 08  ret
a00d2a24:  91 e8 20 e0  restore  %g0, 0xe0, %o0
