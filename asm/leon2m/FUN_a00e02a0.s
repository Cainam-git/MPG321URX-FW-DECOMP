# leon2m FUN_a00e02a0 0xa00e02a0-0xa00e02d8 (56 bytes)
a00e02a0:  9c 03 bf 88  add  %sp, -120, %sp
a00e02a4:  1b 30 00 80  sethi  %hi(0xc0020000), %o5
a00e02a8:  da 23 a0 60  st  %o5, [ %sp + 0x60 ]
a00e02ac:  03 30 00 c0  sethi  %hi(0xc0030000), %g1
a00e02b0:  c2 23 a0 64  st  %g1, [ %sp + 0x64 ]
a00e02b4:  1b 30 01 00  sethi  %hi(0xc0040000), %o5
a00e02b8:  da 23 a0 68  st  %o5, [ %sp + 0x68 ]
a00e02bc:  82 03 a0 78  add  %sp, 0x78, %g1
a00e02c0:  91 2a 20 02  sll  %o0, 2, %o0
a00e02c4:  9a 00 40 08  add  %g1, %o0, %o5
a00e02c8:  c2 03 7f e8  ld  [ %o5 + -24 ], %g1
a00e02cc:  d4 20 40 09  st  %o2, [ %g1 + %o1 ]
a00e02d0:  81 c3 e0 08  retl
a00e02d4:  9c 23 bf 88  sub  %sp, -120, %sp
