# leon2m FUN_a0096230 0xa0096230-0xa00962ac (124 bytes)
a0096230:  9d e3 bf 98  save  %sp, -104, %sp
a0096234:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a0096238:  40 00 4c 61  call  0xa00a93bc
a009623c:  d0 0c 20 56  ldub  [ %l0 + 0x56 ], %o0	! 0xa8025c56
a0096240:  d2 0c 20 56  ldub  [ %l0 + 0x56 ], %o1
a0096244:  94 10 20 00  clr  %o2
a0096248:  40 00 47 bd  call  0xa00a813c
a009624c:  90 10 20 01  mov  1, %o0
a0096250:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0096254:  de 04 23 ec  ld  [ %l0 + 0x3ec ], %o7	! 0xa802afec
a0096258:  98 03 ff 9c  add  %o7, -100, %o4
a009625c:  90 0b 20 ff  and  %o4, 0xff, %o0
a0096260:  40 00 4c fc  call  0xa00a9650
a0096264:  92 10 20 00  clr  %o1
a0096268:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a009626c:  d4 12 e2 c4  lduh  [ %o3 + 0x2c4 ], %o2	! 0xa802d2c4
a0096270:  92 0a a0 0f  and  %o2, 0xf, %o1
a0096274:  90 10 20 01  mov  1, %o0
a0096278:  40 00 47 b1  call  0xa00a813c
a009627c:  94 10 20 01  mov  1, %o2
a0096280:  92 10 20 17  mov  0x17, %o1
a0096284:  d2 24 23 ec  st  %o1, [ %l0 + 0x3ec ]
a0096288:  90 10 20 02  mov  2, %o0
a009628c:  40 00 4b 60  call  0xa00a900c
a0096290:  92 10 20 01  mov  1, %o1
a0096294:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a0096298:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a009629c:  82 12 20 02  or  %o0, 2, %g1
a00962a0:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a00962a4:  81 c7 e0 08  ret
a00962a8:  81 e8 00 00  restore
