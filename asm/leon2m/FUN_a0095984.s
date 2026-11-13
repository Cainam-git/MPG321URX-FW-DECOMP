# leon2m FUN_a0095984 0xa0095984-0xa0095a20 (156 bytes)
a0095984:  9d e3 bf 98  save  %sp, -104, %sp
a0095988:  40 00 4c c0  call  0xa00a8c88
a009598c:  01 00 00 00  nop
a0095990:  90 10 20 03  mov  3, %o0	! 0x3
a0095994:  92 10 20 00  clr  %o1
a0095998:  40 02 c4 aa  call  0xa0146c40
a009599c:  94 10 20 00  clr  %o2
a00959a0:  94 10 20 00  clr  %o2
a00959a4:  90 10 20 04  mov  4, %o0
a00959a8:  40 02 c4 a6  call  0xa0146c40
a00959ac:  92 10 20 00  clr  %o1
a00959b0:  40 00 4a 45  call  0xa00a82c4
a00959b4:  01 00 00 00  nop
a00959b8:  94 10 20 3f  mov  0x3f, %o2	! 0x3f
a00959bc:  13 2a 00 ab  sethi  %hi(0xa802ac00), %o1
a00959c0:  d4 22 63 ec  st  %o2, [ %o1 + 0x3ec ]	! 0xa802afec
a00959c4:  90 10 20 00  clr  %o0
a00959c8:  40 00 4f 22  call  0xa00a9650
a00959cc:  92 10 20 01  mov  1, %o1
a00959d0:  90 10 20 02  mov  2, %o0
a00959d4:  40 00 4e a5  call  0xa00a9468
a00959d8:  92 10 20 05  mov  5, %o1
a00959dc:  90 10 20 00  clr  %o0
a00959e0:  40 00 4e a2  call  0xa00a9468
a00959e4:  92 10 20 00  clr  %o1
a00959e8:  90 10 20 01  mov  1, %o0
a00959ec:  40 00 4e 9f  call  0xa00a9468
a00959f0:  92 10 20 02  mov  2, %o1
a00959f4:  90 10 20 00  clr  %o0
a00959f8:  40 00 76 b7  call  0xa00b34d4
a00959fc:  92 10 20 01  mov  1, %o1
a0095a00:  40 00 76 93  call  0xa00b344c
a0095a04:  90 10 20 07  mov  7, %o0
a0095a08:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a0095a0c:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a0095a10:  82 12 20 02  or  %o0, 2, %g1
a0095a14:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a0095a18:  81 c7 e0 08  ret
a0095a1c:  81 e8 00 00  restore
