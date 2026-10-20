# leon2m FUN_a00a42f0 0xa00a42f0-0xa00a4348 (88 bytes)
a00a42f0:  9d e3 bf 98  save  %sp, -104, %sp
a00a42f4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00a42f8:  98 12 22 90  or  %o0, 0x290, %o4	! 0xa802d290
a00a42fc:  da 0b 20 0a  ldub  [ %o4 + 0xa ], %o5
a00a4300:  9a 03 60 01  inc  %o5
a00a4304:  82 0b 60 ff  and  %o5, 0xff, %g1
a00a4308:  80 a0 60 64  cmp  %g1, 0x64
a00a430c:  08 80 00 05  bleu  0xa00a4320
a00a4310:  90 10 20 01  mov  1, %o0
a00a4314:  92 10 20 64  mov  0x64, %o1
a00a4318:  10 80 00 06  b  0xa00a4330
a00a431c:  d2 2b 20 0a  stb  %o1, [ %o4 + 0xa ]
a00a4320:  40 00 4b 00  call  0xa00b6f20
a00a4324:  da 2b 20 0a  stb  %o5, [ %o4 + 0xa ]
a00a4328:  40 00 ce ae  call  0xa00d7de0
a00a432c:  01 00 00 00  nop
a00a4330:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00a4334:  d8 0a a0 8e  ldub  [ %o2 + 0x8e ], %o4	! 0xa802b08e
a00a4338:  96 13 20 02  or  %o4, 2, %o3
a00a433c:  d6 2a a0 8e  stb  %o3, [ %o2 + 0x8e ]
a00a4340:  81 c7 e0 08  ret
a00a4344:  81 e8 00 00  restore
