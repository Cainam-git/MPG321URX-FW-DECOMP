# leon2m FUN_a00cce80 0xa00cce80-0xa00ccef4 (116 bytes)
a00cce80:  9d e3 bf 98  save  %sp, -104, %sp
a00cce84:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cce88:  80 a6 20 02  cmp  %i0, 2
a00cce8c:  02 80 00 06  be  0xa00ccea4
a00cce90:  80 a6 20 03  cmp  %i0, 3
a00cce94:  02 80 00 07  be  0xa00cceb0
a00cce98:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cce9c:  10 80 00 07  b  0xa00cceb8
a00ccea0:  da 0a 60 d9  ldub  [ %o1 + 0xd9 ], %o5	! 0xa802d0d9
a00ccea4:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00ccea8:  10 80 00 04  b  0xa00cceb8
a00cceac:  da 08 60 49  ldub  [ %g1 + 0x49 ], %o5	! 0xa802d049
a00cceb0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cceb4:  da 0a 20 a1  ldub  [ %o0 + 0xa1 ], %o5	! 0xa802d0a1
a00cceb8:  9a 03 7f d0  add  %o5, -48, %o5
a00ccebc:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00ccec0:  40 00 1e 72  call  0xa00d4888
a00ccec4:  da 2a a2 98  stb  %o5, [ %o2 + 0x298 ]	! 0xa802d298
a00ccec8:  7f ff ae 81  call  0xa00b88cc
a00ccecc:  01 00 00 00  nop
a00cced0:  7f ff b6 e7  call  0xa00baa6c
a00cced4:  90 10 00 18  mov  %i0, %o0
a00cced8:  7f ff b6 9e  call  0xa00ba950
a00ccedc:  90 10 00 18  mov  %i0, %o0
a00ccee0:  90 10 00 18  mov  %i0, %o0
a00ccee4:  7f ff b7 27  call  0xa00bab80
a00ccee8:  92 10 20 06  mov  6, %o1
a00cceec:  81 c7 e0 08  ret
a00ccef0:  91 e8 20 00  restore  %g0, 0, %o0
