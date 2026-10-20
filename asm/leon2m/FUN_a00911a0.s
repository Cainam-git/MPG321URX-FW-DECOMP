# leon2m FUN_a00911a0 0xa00911a0-0xa0091294 (244 bytes)
a00911a0:  9d e3 bf 98  save  %sp, -104, %sp
a00911a4:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00911a8:  da 10 63 f4  lduh  [ %g1 + 0x3f4 ], %o5	! 0xa802cff4
a00911ac:  80 8b 64 00  btst  0x400, %o5
a00911b0:  12 80 00 37  bne  0xa009128c
a00911b4:  90 10 20 00  clr  %o0
a00911b8:  40 02 af 2d  call  0xa013ce6c
a00911bc:  01 00 00 00  nop
a00911c0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00911c4:  80 a2 20 0c  cmp  %o0, 0xc
a00911c8:  12 80 00 31  bne  0xa009128c
a00911cc:  01 00 00 00  nop
a00911d0:  40 00 90 6a  call  0xa00b5378
a00911d4:  01 00 00 00  nop
a00911d8:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00911dc:  d8 02 e2 90  ld  [ %o3 + 0x290 ], %o4	! 0xa802d290
a00911e0:  15 00 00 10  sethi  %hi(0x4000), %o2
a00911e4:  90 10 20 fe  mov  0xfe, %o0
a00911e8:  80 8b 00 0a  btst  %o4, %o2
a00911ec:  02 80 00 21  be  0xa0091270
a00911f0:  92 10 20 00  clr  %o1
a00911f4:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a00911f8:  82 10 20 01  mov  1, %g1
a00911fc:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a0091200:  c2 23 63 ec  st  %g1, [ %o5 + 0x3ec ]
a0091204:  c0 2b e0 8f  clrb  [ %o7 + 0x8f ]
a0091208:  40 02 d6 52  call  0xa0146b50
a009120c:  01 00 00 00  nop
a0091210:  90 10 20 00  clr  %o0	! 0x0
a0091214:  40 02 d6 56  call  0xa0146b6c
a0091218:  92 10 20 00  clr  %o1
a009121c:  94 10 20 01  mov  1, %o2
a0091220:  96 10 25 92  mov  0x592, %o3
a0091224:  98 10 20 00  clr  %o4
a0091228:  90 10 20 01  mov  1, %o0
a009122c:  40 02 d6 15  call  0xa0146a80
a0091230:  92 10 20 04  mov  4, %o1
a0091234:  13 00 06 5f  sethi  %hi(0x197c00), %o1
a0091238:  90 12 62 e4  or  %o1, 0x2e4, %o0	! 0x197ee4
a009123c:  40 00 49 82  call  0xa00a3844
a0091240:  92 10 20 08  mov  8, %o1
a0091244:  98 10 00 08  mov  %o0, %o4
a0091248:  90 10 20 00  clr  %o0
a009124c:  92 10 20 01  mov  1, %o1
a0091250:  94 10 20 04  mov  4, %o2
a0091254:  96 10 20 01  mov  1, %o3
a0091258:  40 00 47 d3  call  0xa00a31a4
a009125c:  9a 10 20 00  clr  %o5
a0091260:  40 00 7b 75  call  0xa00b0034
a0091264:  90 10 20 00  clr  %o0
a0091268:  40 00 4c d0  call  0xa00a45a8
a009126c:  81 e8 00 00  restore
a0091270:  94 10 20 02  mov  2, %o2
a0091274:  11 2a 00 ab  sethi  %hi(0xa802ac00), %o0
a0091278:  d4 22 23 ec  st  %o2, [ %o0 + 0x3ec ]	! 0xa802afec
a009127c:  92 10 20 01  mov  1, %o1
a0091280:  40 00 8b b1  call  0xa00b4144
a0091284:  90 10 20 00  clr  %o0
a0091288:  30 bf ff f6  b,a   0xa0091260
a009128c:  81 c7 e0 08  ret
a0091290:  81 e8 00 00  restore
