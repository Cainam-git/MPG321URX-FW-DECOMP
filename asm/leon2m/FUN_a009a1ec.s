# leon2m FUN_a009a1ec 0xa009a1ec-0xa009a270 (132 bytes)
a009a1ec:  9d e3 bf 98  save  %sp, -104, %sp
a009a1f0:  1f 2a 00 97  sethi  %hi(0xa8025c00), %o7
a009a1f4:  d2 0b e0 55  ldub  [ %o7 + 0x55 ], %o1	! 0xa8025c55
a009a1f8:  94 10 20 00  clr  %o2
a009a1fc:  40 00 37 d0  call  0xa00a813c
a009a200:  90 10 20 01  mov  1, %o0
a009a204:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a009a208:  d8 04 63 ec  ld  [ %l1 + 0x3ec ], %o4	! 0xa802afec
a009a20c:  96 03 20 0f  add  %o4, 0xf, %o3
a009a210:  40 00 3c 6b  call  0xa00a93bc
a009a214:  90 0a e0 ff  and  %o3, 0xff, %o0
a009a218:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a009a21c:  a0 12 a2 90  or  %o2, 0x290, %l0	! 0xa802d290
a009a220:  d0 0c 21 dd  ldub  [ %l0 + 0x1dd ], %o0
a009a224:  40 00 3d 0b  call  0xa00a9650
a009a228:  92 10 20 02  mov  2, %o1
a009a22c:  94 10 20 01  mov  1, %o2
a009a230:  d2 0c 21 dd  ldub  [ %l0 + 0x1dd ], %o1
a009a234:  40 00 37 c2  call  0xa00a813c
a009a238:  90 10 20 01  mov  1, %o0
a009a23c:  92 10 20 34  mov  0x34, %o1
a009a240:  d2 24 63 ec  st  %o1, [ %l1 + 0x3ec ]
a009a244:  90 10 20 00  clr  %o0
a009a248:  40 00 3b 71  call  0xa00a900c
a009a24c:  92 10 20 01  mov  1, %o1
a009a250:  40 01 02 2e  call  0xa00dab08
a009a254:  01 00 00 00  nop
a009a258:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a009a25c:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a009a260:  82 12 20 02  or  %o0, 2, %g1
a009a264:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a009a268:  81 c7 e0 08  ret
a009a26c:  81 e8 00 00  restore
