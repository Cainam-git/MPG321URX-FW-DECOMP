# leon2m FUN_a00958c4 0xa00958c4-0xa0095930 (108 bytes)
a00958c4:  9d e3 bf 98  save  %sp, -104, %sp
a00958c8:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a00958cc:  d2 04 23 ec  ld  [ %l0 + 0x3ec ], %o1	! 0xa802afec
a00958d0:  90 02 7f c1  add  %o1, -63, %o0
a00958d4:  40 00 4e ba  call  0xa00a93bc
a00958d8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00958dc:  c2 04 23 ec  ld  [ %l0 + 0x3ec ], %g1
a00958e0:  90 10 20 01  mov  1, %o0
a00958e4:  92 10 20 02  mov  2, %o1
a00958e8:  b0 10 20 01  mov  1, %i0
a00958ec:  80 a0 60 42  cmp  %g1, 0x42
a00958f0:  02 80 00 06  be  0xa0095908
a00958f4:  b2 10 20 01  mov  1, %i1
a00958f8:  94 10 20 0c  mov  0xc, %o2
a00958fc:  d4 24 23 ec  st  %o2, [ %l0 + 0x3ec ]
a0095900:  40 00 4d c3  call  0xa00a900c
a0095904:  81 e8 00 00  restore
a0095908:  40 00 4e d8  call  0xa00a9468
a009590c:  01 00 00 00  nop
a0095910:  90 10 20 00  clr  %o0	! 0x0
a0095914:  40 00 76 f0  call  0xa00b34d4
a0095918:  92 10 20 01  mov  1, %o1
a009591c:  94 10 20 0c  mov  0xc, %o2
a0095920:  d4 24 23 ec  st  %o2, [ %l0 + 0x3ec ]
a0095924:  40 00 4d ba  call  0xa00a900c
a0095928:  81 e8 00 00  restore
a009592c:  01 00 00 00  nop
