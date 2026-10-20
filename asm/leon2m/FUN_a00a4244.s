# leon2m FUN_a00a4244 0xa00a4244-0xa00a429c (88 bytes)
a00a4244:  9d e3 bf 98  save  %sp, -104, %sp
a00a4248:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00a424c:  98 12 22 90  or  %o0, 0x290, %o4	! 0xa802d290
a00a4250:  da 0b 20 09  ldub  [ %o4 + 9 ], %o5
a00a4254:  9a 03 60 01  inc  %o5
a00a4258:  82 0b 60 ff  and  %o5, 0xff, %g1
a00a425c:  80 a0 60 64  cmp  %g1, 0x64
a00a4260:  08 80 00 05  bleu  0xa00a4274
a00a4264:  90 10 20 01  mov  1, %o0
a00a4268:  92 10 20 64  mov  0x64, %o1
a00a426c:  10 80 00 06  b  0xa00a4284
a00a4270:  d2 2b 20 09  stb  %o1, [ %o4 + 9 ]
a00a4274:  40 00 4b 78  call  0xa00b7054
a00a4278:  da 2b 20 09  stb  %o5, [ %o4 + 9 ]
a00a427c:  40 00 d2 96  call  0xa00d8cd4
a00a4280:  01 00 00 00  nop
a00a4284:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00a4288:  d8 0a a0 8e  ldub  [ %o2 + 0x8e ], %o4	! 0xa802b08e
a00a428c:  96 13 20 02  or  %o4, 2, %o3
a00a4290:  d6 2a a0 8e  stb  %o3, [ %o2 + 0x8e ]
a00a4294:  81 c7 e0 08  ret
a00a4298:  81 e8 00 00  restore
