# leon2m FUN_a00991ec 0xa00991ec-0xa0099244 (88 bytes)
a00991ec:  9d e3 bf 98  save  %sp, -104, %sp
a00991f0:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00991f4:  98 13 22 90  or  %o4, 0x290, %o4	! 0xa802d290
a00991f8:  d0 03 20 ac  ld  [ %o4 + 0xac ], %o0
a00991fc:  95 32 20 16  srl  %o0, 0x16, %o2
a0099200:  92 38 00 0a  xnor  %g0, %o2, %o1
a0099204:  82 0a 60 01  and  %o1, 1, %g1
a0099208:  1b 00 10 00  sethi  %hi(0x400000), %o5
a009920c:  9e 2a 00 0d  andn  %o0, %o5, %o7
a0099210:  97 28 60 16  sll  %g1, 0x16, %o3
a0099214:  94 13 c0 0b  or  %o7, %o3, %o2
a0099218:  93 32 a0 16  srl  %o2, 0x16, %o1
a009921c:  90 10 20 05  mov  5, %o0
a0099220:  d4 23 20 ac  st  %o2, [ %o4 + 0xac ]
a0099224:  40 00 30 7f  call  0xa00a5420
a0099228:  92 0a 60 01  and  %o1, 1, %o1
a009922c:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a0099230:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a0099234:  82 12 20 02  or  %o0, 2, %g1
a0099238:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a009923c:  81 c7 e0 08  ret
a0099240:  81 e8 00 00  restore
