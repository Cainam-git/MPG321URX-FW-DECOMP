# leon2m FUN_a0087458 0xa0087458-0xa00874c8 (112 bytes)
a0087458:  9d e3 bf 98  save  %sp, -104, %sp
a008745c:  40 02 f1 ee  call  0xa0143c14
a0087460:  90 10 20 00  clr  %o0
a0087464:  82 06 3f ac  add  %i0, -84, %g1
a0087468:  b1 28 60 10  sll  %g1, 0x10, %i0
a008746c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0087470:  9b 36 20 10  srl  %i0, 0x10, %o5
a0087474:  80 a2 20 08  cmp  %o0, 8
a0087478:  a0 10 20 00  clr  %l0
a008747c:  08 80 00 11  bleu  0xa00874c0
a0087480:  b0 10 20 00  clr  %i0
a0087484:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a0087488:  80 a3 60 c3  cmp  %o5, 0xc3
a008748c:  08 80 00 0b  bleu  0xa00874b8
a0087490:  c2 02 63 38  ld  [ %o1 + 0x338 ], %g1
a0087494:  80 88 60 80  btst  0x80, %g1
a0087498:  32 80 00 02  bne,a   0xa00874a0
a008749c:  a0 10 20 03  mov  3, %l0
a00874a0:  40 01 42 2a  call  0xa00d7d48
a00874a4:  01 00 00 00  nop
a00874a8:  80 a0 00 08  cmp  %g0, %o0
a00874ac:  94 40 3f ff  addx  %g0, -1, %o2
a00874b0:  10 80 00 04  b  0xa00874c0
a00874b4:  b0 0c 00 0a  and  %l0, %o2, %i0
a00874b8:  10 bf ff f7  b  0xa0087494
a00874bc:  a0 10 20 02  mov  2, %l0
a00874c0:  81 c7 e0 08  ret
a00874c4:  81 e8 00 00  restore
