# leon2m FUN_a00954a0 0xa00954a0-0xa0095510 (112 bytes)
a00954a0:  9d e3 bf 98  save  %sp, -104, %sp
a00954a4:  40 00 4d f9  call  0xa00a8c88
a00954a8:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a00954ac:  40 00 89 8e  call  0xa00b7ae4
a00954b0:  01 00 00 00  nop
a00954b4:  9a 10 20 44  mov  0x44, %o5	! 0x44
a00954b8:  1f 2a 00 ab  sethi  %hi(0xa802ac00), %o7
a00954bc:  da 23 e3 ec  st  %o5, [ %o7 + 0x3ec ]	! 0xa802afec
a00954c0:  90 10 20 00  clr  %o0
a00954c4:  40 00 50 63  call  0xa00a9650
a00954c8:  92 10 20 01  mov  1, %o1
a00954cc:  d8 0c 20 56  ldub  [ %l0 + 0x56 ], %o4
a00954d0:  96 03 20 02  add  %o4, 2, %o3
a00954d4:  90 0a e0 ff  and  %o3, 0xff, %o0
a00954d8:  40 00 50 5e  call  0xa00a9650
a00954dc:  92 10 20 02  mov  2, %o1
a00954e0:  d4 0c 20 56  ldub  [ %l0 + 0x56 ], %o2
a00954e4:  92 02 a0 02  add  %o2, 2, %o1
a00954e8:  90 10 20 01  mov  1, %o0
a00954ec:  92 0a 60 ff  and  %o1, 0xff, %o1
a00954f0:  40 00 4b 13  call  0xa00a813c
a00954f4:  94 10 20 01  mov  1, %o2
a00954f8:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00954fc:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a0095500:  82 12 20 02  or  %o0, 2, %g1
a0095504:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a0095508:  81 c7 e0 08  ret
a009550c:  81 e8 00 00  restore
