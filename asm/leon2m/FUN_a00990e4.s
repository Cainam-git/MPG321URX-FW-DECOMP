# leon2m FUN_a00990e4 0xa00990e4-0xa0099168 (132 bytes)
a00990e4:  9d e3 bf 98  save  %sp, -104, %sp
a00990e8:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a00990ec:  40 00 40 b4  call  0xa00a93bc
a00990f0:  d0 0c 20 56  ldub  [ %l0 + 0x56 ], %o0	! 0xa8025c56
a00990f4:  d2 0c 20 56  ldub  [ %l0 + 0x56 ], %o1
a00990f8:  94 10 20 00  clr  %o2
a00990fc:  40 00 3c 10  call  0xa00a813c
a0099100:  90 10 20 01  mov  1, %o0
a0099104:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a0099108:  a0 10 62 90  or  %g1, 0x290, %l0	! 0xa802d290
a009910c:  da 04 20 a8  ld  [ %l0 + 0xa8 ], %o5
a0099110:  9f 33 60 0f  srl  %o5, 0xf, %o7
a0099114:  90 0b e0 01  and  %o7, 1, %o0
a0099118:  40 00 41 4e  call  0xa00a9650
a009911c:  92 10 20 00  clr  %o1
a0099120:  d8 04 20 a8  ld  [ %l0 + 0xa8 ], %o4
a0099124:  97 33 20 0f  srl  %o4, 0xf, %o3
a0099128:  92 0a e0 01  and  %o3, 1, %o1
a009912c:  90 10 20 01  mov  1, %o0
a0099130:  40 00 3c 03  call  0xa00a813c
a0099134:  94 10 20 01  mov  1, %o2
a0099138:  94 10 20 2e  mov  0x2e, %o2
a009913c:  13 2a 00 ab  sethi  %hi(0xa802ac00), %o1
a0099140:  d4 22 63 ec  st  %o2, [ %o1 + 0x3ec ]	! 0xa802afec
a0099144:  90 10 20 04  mov  4, %o0
a0099148:  40 00 3f b1  call  0xa00a900c
a009914c:  92 10 20 01  mov  1, %o1
a0099150:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a0099154:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a0099158:  82 12 20 02  or  %o0, 2, %g1
a009915c:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a0099160:  81 c7 e0 08  ret
a0099164:  81 e8 00 00  restore
