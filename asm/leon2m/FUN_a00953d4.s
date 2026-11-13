# leon2m FUN_a00953d4 0xa00953d4-0xa0095430 (92 bytes)
a00953d4:  9d e3 bf 98  save  %sp, -104, %sp
a00953d8:  9a 10 20 0f  mov  0xf, %o5
a00953dc:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00953e0:  40 00 4e 2a  call  0xa00a8c88
a00953e4:  da 2a e0 8f  stb  %o5, [ %o3 + 0x8f ]	! 0xa802b08f
a00953e8:  40 00 4c c0  call  0xa00a86e8
a00953ec:  01 00 00 00  nop
a00953f0:  9e 10 20 7b  mov  0x7b, %o7	! 0x7b
a00953f4:  15 2a 00 ab  sethi  %hi(0xa802ac00), %o2
a00953f8:  90 10 20 01  mov  1, %o0
a00953fc:  de 22 a3 ec  st  %o7, [ %o2 + 0x3ec ]
a0095400:  40 00 50 94  call  0xa00a9650
a0095404:  92 10 20 01  mov  1, %o1
a0095408:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a009540c:  d0 0a e0 8e  ldub  [ %o3 + 0x8e ], %o0	! 0xa802b08e
a0095410:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a0095414:  d8 0a 60 34  ldub  [ %o1 + 0x34 ], %o4	! 0xa802d434
a0095418:  9a 12 20 02  or  %o0, 2, %o5
a009541c:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a0095420:  d8 28 60 55  stb  %o4, [ %g1 + 0x55 ]	! 0xa8025c55
a0095424:  da 2a e0 8e  stb  %o5, [ %o3 + 0x8e ]
a0095428:  81 c7 e0 08  ret
a009542c:  81 e8 00 00  restore
