# leon2m FUN_a00db12c 0xa00db12c-0xa00db170 (68 bytes)
a00db12c:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00db130:  c2 03 60 7c  ld  [ %o5 + 0x7c ], %g1	! 0xa802d47c
a00db134:  90 0a 20 ff  and  %o0, 0xff, %o0
a00db138:  9b 30 60 07  srl  %g1, 7, %o5
a00db13c:  80 a0 00 08  cmp  %g0, %o0
a00db140:  90 1b 60 01  xor  %o5, 1, %o0
a00db144:  82 0a 20 01  and  %o0, 1, %g1
a00db148:  9a 40 20 00  addx  %g0, 0, %o5
a00db14c:  80 90 40 0d  orcc  %g1, %o5, %g0
a00db150:  02 80 00 05  be  0xa00db164
a00db154:  01 00 00 00  nop
a00db158:  82 13 c0 00  mov  %o7, %g1
a00db15c:  40 01 29 e4  call  0xa01258ec
a00db160:  9e 10 40 00  mov  %g1, %o7
a00db164:  82 13 c0 00  mov  %o7, %g1
a00db168:  40 01 29 da  call  0xa01258d0
a00db16c:  9e 10 40 00  mov  %g1, %o7
