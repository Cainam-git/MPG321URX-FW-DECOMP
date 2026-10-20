# leon2m FUN_a00ba068 0xa00ba068-0xa00ba184 (284 bytes)
a00ba068:  9d e3 bf 98  save  %sp, -104, %sp
a00ba06c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ba070:  a4 12 22 90  or  %o0, 0x290, %l2	! 0xa802d290
a00ba074:  de 14 a1 ac  lduh  [ %l2 + 0x1ac ], %o7
a00ba078:  da 14 a1 ae  lduh  [ %l2 + 0x1ae ], %o5
a00ba07c:  a2 03 e0 1e  add  %o7, 0x1e, %l1
a00ba080:  a4 03 60 24  add  %o5, 0x24, %l2
a00ba084:  40 02 38 be  call  0xa014837c
a00ba088:  90 10 20 00  clr  %o0
a00ba08c:  99 2a 20 10  sll  %o0, 0x10, %o4
a00ba090:  a1 33 20 14  srl  %o4, 0x14, %l0
a00ba094:  40 02 38 ba  call  0xa014837c
a00ba098:  90 10 20 01  mov  1, %o0
a00ba09c:  93 2c 20 10  sll  %l0, 0x10, %o1
a00ba0a0:  97 2c 60 10  sll  %l1, 0x10, %o3
a00ba0a4:  83 32 60 11  srl  %o1, 0x11, %g1
a00ba0a8:  95 32 e0 10  srl  %o3, 0x10, %o2
a00ba0ac:  a2 02 80 01  add  %o2, %g1, %l1
a00ba0b0:  a1 32 60 10  srl  %o1, 0x10, %l0
a00ba0b4:  83 3c 60 1f  sra  %l1, 0x1f, %g1
a00ba0b8:  81 80 60 00  mov  %g1, %y
a00ba0bc:  01 00 00 00  nop
a00ba0c0:  01 00 00 00  nop
a00ba0c4:  01 00 00 00  nop
a00ba0c8:  a2 7c 40 10  sdiv  %l1, %l0, %l1
a00ba0cc:  91 2a 20 10  sll  %o0, 0x10, %o0
a00ba0d0:  82 0c 60 ff  and  %l1, 0xff, %g1
a00ba0d4:  80 a0 60 00  cmp  %g1, 0
a00ba0d8:  12 80 00 1d  bne  0xa00ba14c
a00ba0dc:  91 32 20 14  srl  %o0, 0x14, %o0
a00ba0e0:  e2 2e 00 00  stb  %l1, [ %i0 ]
a00ba0e4:  e2 2e 80 00  stb  %l1, [ %i2 ]
a00ba0e8:  83 2a 20 10  sll  %o0, 0x10, %g1
a00ba0ec:  99 2c a0 10  sll  %l2, 0x10, %o4
a00ba0f0:  a3 33 20 10  srl  %o4, 0x10, %l1
a00ba0f4:  a1 30 60 11  srl  %g1, 0x11, %l0
a00ba0f8:  b5 30 60 10  srl  %g1, 0x10, %i2
a00ba0fc:  96 04 40 10  add  %l1, %l0, %o3
a00ba100:  99 3a e0 1f  sra  %o3, 0x1f, %o4
a00ba104:  81 83 20 00  mov  %o4, %y
a00ba108:  01 00 00 00  nop
a00ba10c:  01 00 00 00  nop
a00ba110:  01 00 00 00  nop
a00ba114:  90 7a c0 1a  sdiv  %o3, %i2, %o0
a00ba118:  82 0a 20 ff  and  %o0, 0xff, %g1
a00ba11c:  80 a0 60 00  cmp  %g1, 0
a00ba120:  12 80 00 06  bne  0xa00ba138
a00ba124:  80 a0 60 10  cmp  %g1, 0x10
a00ba128:  d0 2e 40 00  stb  %o0, [ %i1 ]
a00ba12c:  c2 0e 00 00  ldub  [ %i0 ], %g1
a00ba130:  10 80 00 13  b  0xa00ba17c
a00ba134:  c2 2e c0 00  stb  %g1, [ %i3 ]
a00ba138:  02 80 00 0e  be  0xa00ba170
a00ba13c:  b0 02 3f ff  add  %o0, -1, %i0
a00ba140:  f0 2e 40 00  stb  %i0, [ %i1 ]
a00ba144:  10 80 00 0e  b  0xa00ba17c
a00ba148:  d0 2e c0 00  stb  %o0, [ %i3 ]
a00ba14c:  80 a0 60 10  cmp  %g1, 0x10
a00ba150:  02 80 00 04  be  0xa00ba160
a00ba154:  94 04 7f ff  add  %l1, -1, %o2
a00ba158:  10 bf ff e3  b  0xa00ba0e4
a00ba15c:  d4 2e 00 00  stb  %o2, [ %i0 ]
a00ba160:  92 04 7f ff  add  %l1, -1, %o1
a00ba164:  d2 2e 00 00  stb  %o1, [ %i0 ]
a00ba168:  10 bf ff e0  b  0xa00ba0e8
a00ba16c:  d2 2e 80 00  stb  %o1, [ %i2 ]
a00ba170:  82 02 3f ff  add  %o0, -1, %g1
a00ba174:  10 bf ff ef  b  0xa00ba130
a00ba178:  c2 2e 40 00  stb  %g1, [ %i1 ]
a00ba17c:  81 c7 e0 08  ret
a00ba180:  81 e8 00 00  restore
