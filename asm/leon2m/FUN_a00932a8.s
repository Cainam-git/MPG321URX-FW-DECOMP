# leon2m FUN_a00932a8 0xa00932a8-0xa0093334 (140 bytes)
a00932a8:  9d e3 bf 98  save  %sp, -104, %sp
a00932ac:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a00932b0:  40 00 58 43  call  0xa00a93bc
a00932b4:  d0 0c 20 56  ldub  [ %l0 + 0x56 ], %o0	! 0xa8025c56
a00932b8:  d2 0c 20 56  ldub  [ %l0 + 0x56 ], %o1
a00932bc:  94 10 20 00  clr  %o2
a00932c0:  40 00 53 9f  call  0xa00a813c
a00932c4:  90 10 20 01  mov  1, %o0
a00932c8:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a00932cc:  da 04 63 ec  ld  [ %l1 + 0x3ec ], %o5	! 0xa802afec
a00932d0:  9e 03 7f b8  add  %o5, -72, %o7
a00932d4:  90 0b e0 ff  and  %o7, 0xff, %o0
a00932d8:  40 00 58 de  call  0xa00a9650
a00932dc:  92 10 20 00  clr  %o1
a00932e0:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00932e4:  a0 13 22 90  or  %o4, 0x290, %l0	! 0xa802d290
a00932e8:  94 10 20 01  mov  1, %o2
a00932ec:  90 10 20 01  mov  1, %o0
a00932f0:  40 00 53 93  call  0xa00a813c
a00932f4:  d2 0c 21 82  ldub  [ %l0 + 0x182 ], %o1
a00932f8:  96 10 20 0e  mov  0xe, %o3
a00932fc:  90 10 20 00  clr  %o0
a0093300:  d6 24 63 ec  st  %o3, [ %l1 + 0x3ec ]
a0093304:  40 00 57 42  call  0xa00a900c
a0093308:  92 10 20 01  mov  1, %o1
a009330c:  d4 04 20 a8  ld  [ %l0 + 0xa8 ], %o2
a0093310:  92 0a b7 ff  and  %o2, -2049, %o1
a0093314:  40 00 66 4b  call  0xa00acc40
a0093318:  d2 24 20 a8  st  %o1, [ %l0 + 0xa8 ]
a009331c:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a0093320:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a0093324:  82 12 20 02  or  %o0, 2, %g1
a0093328:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a009332c:  81 c7 e0 08  ret
a0093330:  81 e8 00 00  restore
