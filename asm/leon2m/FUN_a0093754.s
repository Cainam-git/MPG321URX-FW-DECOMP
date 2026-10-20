# leon2m FUN_a0093754 0xa0093754-0xa0093808 (180 bytes)
a0093754:  9d e3 bf 98  save  %sp, -104, %sp
a0093758:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a009375c:  d8 0c 20 56  ldub  [ %l0 + 0x56 ], %o4	! 0xa8025c56
a0093760:  96 03 20 01  add  %o4, 1, %o3
a0093764:  40 00 57 16  call  0xa00a93bc
a0093768:  90 0a e0 ff  and  %o3, 0xff, %o0
a009376c:  d4 0c 20 56  ldub  [ %l0 + 0x56 ], %o2
a0093770:  a2 02 a0 01  add  %o2, 1, %l1
a0093774:  92 0c 60 ff  and  %l1, 0xff, %o1
a0093778:  94 10 20 00  clr  %o2
a009377c:  40 00 52 70  call  0xa00a813c
a0093780:  90 10 20 01  mov  1, %o0
a0093784:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0093788:  d2 04 63 ec  ld  [ %l1 + 0x3ec ], %o1	! 0xa802afec
a009378c:  90 02 7f aa  add  %o1, -86, %o0
a0093790:  90 0a 20 ff  and  %o0, 0xff, %o0
a0093794:  40 00 57 af  call  0xa00a9650
a0093798:  92 10 20 00  clr  %o1
a009379c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00937a0:  a0 10 62 90  or  %g1, 0x290, %l0	! 0xa802d290
a00937a4:  da 0c 21 a0  ldub  [ %l0 + 0x1a0 ], %o5
a00937a8:  9e 03 60 01  add  %o5, 1, %o7
a00937ac:  92 0b e0 ff  and  %o7, 0xff, %o1
a00937b0:  90 10 20 01  mov  1, %o0
a00937b4:  40 00 52 62  call  0xa00a813c
a00937b8:  94 10 20 00  clr  %o2
a00937bc:  d8 0c 21 a0  ldub  [ %l0 + 0x1a0 ], %o4
a00937c0:  94 03 20 01  add  %o4, 1, %o2
a00937c4:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a00937c8:  92 0a a0 ff  and  %o2, 0xff, %o1
a00937cc:  d8 2a e3 ea  stb  %o4, [ %o3 + 0x3ea ]
a00937d0:  90 10 20 01  mov  1, %o0
a00937d4:  40 00 52 5a  call  0xa00a813c
a00937d8:  94 10 20 01  mov  1, %o2
a00937dc:  92 10 20 12  mov  0x12, %o1
a00937e0:  d2 24 63 ec  st  %o1, [ %l1 + 0x3ec ]
a00937e4:  90 10 20 04  mov  4, %o0
a00937e8:  40 00 56 09  call  0xa00a900c
a00937ec:  92 10 20 01  mov  1, %o1
a00937f0:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00937f4:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a00937f8:  82 12 20 02  or  %o0, 2, %g1
a00937fc:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a0093800:  81 c7 e0 08  ret
a0093804:  81 e8 00 00  restore
