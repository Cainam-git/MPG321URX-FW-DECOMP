# leon2m FUN_a00fc1a0 0xa00fc1a0-0xa00fc1cc (44 bytes)
a00fc1a0:  9d e3 bf 98  save  %sp, -104, %sp
a00fc1a4:  21 34 01 00  sethi  %hi(0xd0040000), %l0
a00fc1a8:  e2 04 00 00  ld  [ %l0 ], %l1
a00fc1ac:  11 08 00 00  sethi  %hi(0x20000000), %o0
a00fc1b0:  82 14 40 08  or  %l1, %o0, %g1
a00fc1b4:  c2 24 00 00  st  %g1, [ %l0 ]
a00fc1b8:  67 fe 43 fa  call  0x4008d1a0
a00fc1bc:  90 10 20 05  mov  5, %o0
a00fc1c0:  e2 24 00 00  st  %l1, [ %l0 ]
a00fc1c4:  81 c7 e0 08  ret
a00fc1c8:  81 e8 00 00  restore
