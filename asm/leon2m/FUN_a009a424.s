# leon2m FUN_a009a424 0xa009a424-0xa009a480 (92 bytes)
a009a424:  9d e3 bf 98  save  %sp, -104, %sp
a009a428:  40 00 3b e5  call  0xa00a93bc
a009a42c:  90 10 20 00  clr  %o0
a009a430:  40 00 76 39  call  0xa00b7d14
a009a434:  90 10 20 00  clr  %o0
a009a438:  90 10 20 34  mov  0x34, %o0
a009a43c:  40 00 54 04  call  0xa00af44c
a009a440:  92 10 20 03  mov  3, %o1
a009a444:  96 10 20 bf  mov  0xbf, %o3
a009a448:  15 2a 00 ab  sethi  %hi(0xa802ac00), %o2
a009a44c:  90 10 20 04  mov  4, %o0
a009a450:  d6 22 a3 ec  st  %o3, [ %o2 + 0x3ec ]
a009a454:  40 00 3c 7f  call  0xa00a9650
a009a458:  92 10 20 01  mov  1, %o1
a009a45c:  13 2a 00 97  sethi  %hi(0xa8025c00), %o1
a009a460:  40 01 01 b0  call  0xa00dab20
a009a464:  c0 2a 60 55  clrb  [ %o1 + 0x55 ]	! 0xa8025c55
a009a468:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a009a46c:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a009a470:  82 12 20 02  or  %o0, 2, %g1
a009a474:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a009a478:  81 c7 e0 08  ret
a009a47c:  81 e8 00 00  restore
