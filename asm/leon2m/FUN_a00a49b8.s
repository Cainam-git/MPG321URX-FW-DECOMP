# leon2m FUN_a00a49b8 0xa00a49b8-0xa00a4a30 (120 bytes)
a00a49b8:  9d e3 bf 98  save  %sp, -104, %sp
a00a49bc:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00a49c0:  a0 12 22 90  or  %o0, 0x290, %l0	! 0xa802d290
a00a49c4:  da 0c 20 09  ldub  [ %l0 + 9 ], %o5
a00a49c8:  9a 03 7f ff  add  %o5, -1, %o5
a00a49cc:  82 0b 60 ff  and  %o5, 0xff, %g1
a00a49d0:  96 10 20 0c  mov  0xc, %o3
a00a49d4:  90 10 20 05  mov  5, %o0
a00a49d8:  92 10 20 08  mov  8, %o1
a00a49dc:  80 a0 60 64  cmp  %g1, 0x64
a00a49e0:  08 80 00 04  bleu  0xa00a49f0
a00a49e4:  94 10 00 01  mov  %g1, %o2
a00a49e8:  10 80 00 0a  b  0xa00a4a10
a00a49ec:  c0 2c 20 09  clrb  [ %l0 + 9 ]
a00a49f0:  7f ff fe f4  call  0xa00a45c0
a00a49f4:  da 2c 20 09  stb  %o5, [ %l0 + 9 ]
a00a49f8:  d4 0c 20 09  ldub  [ %l0 + 9 ], %o2
a00a49fc:  90 10 20 0a  mov  0xa, %o0
a00a4a00:  40 00 3b 42  call  0xa00b3708
a00a4a04:  92 10 20 06  mov  6, %o1
a00a4a08:  40 00 d0 b3  call  0xa00d8cd4
a00a4a0c:  01 00 00 00  nop
a00a4a10:  40 00 bf e2  call  0xa00d4998
a00a4a14:  01 00 00 00  nop
a00a4a18:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00a4a1c:  d6 0a 60 8e  ldub  [ %o1 + 0x8e ], %o3	! 0xa802b08e
a00a4a20:  94 12 e0 02  or  %o3, 2, %o2
a00a4a24:  d4 2a 60 8e  stb  %o2, [ %o1 + 0x8e ]
a00a4a28:  81 c7 e0 08  ret
a00a4a2c:  81 e8 00 00  restore
