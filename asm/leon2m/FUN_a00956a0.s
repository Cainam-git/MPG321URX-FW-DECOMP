# leon2m FUN_a00956a0 0xa00956a0-0xa0095704 (100 bytes)
a00956a0:  9d e3 bf 98  save  %sp, -104, %sp
a00956a4:  40 00 4d 79  call  0xa00a8c88
a00956a8:  01 00 00 00  nop
a00956ac:  40 00 4b 06  call  0xa00a82c4
a00956b0:  01 00 00 00  nop
a00956b4:  40 00 92 b4  call  0xa00ba184
a00956b8:  90 10 20 01  mov  1, %o0	! 0x1
a00956bc:  94 10 20 40  mov  0x40, %o2
a00956c0:  13 2a 00 ab  sethi  %hi(0xa802ac00), %o1
a00956c4:  d4 22 63 ec  st  %o2, [ %o1 + 0x3ec ]	! 0xa802afec
a00956c8:  90 10 20 01  mov  1, %o0
a00956cc:  40 00 4f e1  call  0xa00a9650
a00956d0:  92 10 20 01  mov  1, %o1
a00956d4:  90 10 20 01  mov  1, %o0
a00956d8:  40 00 4f 64  call  0xa00a9468
a00956dc:  92 10 20 02  mov  2, %o1
a00956e0:  90 10 20 00  clr  %o0
a00956e4:  40 00 77 7c  call  0xa00b34d4
a00956e8:  92 10 20 01  mov  1, %o1
a00956ec:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00956f0:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a00956f4:  82 12 20 02  or  %o0, 2, %g1
a00956f8:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a00956fc:  81 c7 e0 08  ret
a0095700:  81 e8 00 00  restore
