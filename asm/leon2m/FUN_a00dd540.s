# leon2m FUN_a00dd540 0xa00dd540-0xa00dd5b8 (120 bytes)  [FUN_a00dd5b0 = unreachable ret/restore tail, merged]
a00dd540:  9d e3 bf 98  save  %sp, -104, %sp
a00dd544:  80 a6 20 00  cmp  %i0, 0
a00dd548:  12 80 00 19  bne  0xa00dd5ac
a00dd54c:  01 00 00 00  nop
a00dd550:  40 00 05 1c  call  0xa00de9c0
a00dd554:  31 00 06 62  sethi  %hi(0x198800), %i0
a00dd558:  40 00 05 14  call  0xa00de9a8
a00dd55c:  a2 10 00 08  mov  %o0, %l1
a00dd560:  40 00 05 1e  call  0xa00de9d8
a00dd564:  a0 10 00 08  mov  %o0, %l0
a00dd568:  96 10 00 08  mov  %o0, %o3
a00dd56c:  11 00 06 62  sethi  %hi(0x198800), %o0
a00dd570:  94 10 00 10  mov  %l0, %o2
a00dd574:  92 10 00 11  mov  %l1, %o1
a00dd578:  40 00 06 fe  call  0xa00df170
a00dd57c:  90 12 23 c0  or  %o0, 0x3c0, %o0
a00dd580:  40 00 05 0a  call  0xa00de9a8
a00dd584:  b0 16 23 b8  or  %i0, 0x3b8, %i0
a00dd588:  40 00 05 16  call  0xa00de9e0
a00dd58c:  a0 10 00 08  mov  %o0, %l0
a00dd590:  80 a4 00 08  cmp  %l0, %o0
a00dd594:  08 80 00 04  bleu  0xa00dd5a4
a00dd598:  03 00 06 62  sethi  %hi(0x198800), %g1
a00dd59c:  40 00 06 f5  call  0xa00df170
a00dd5a0:  81 e8 00 00  restore
a00dd5a4:  40 00 06 f3  call  0xa00df170
a00dd5a8:  91 e8 63 f0  restore  %g1, 0x3f0, %o0
a00dd5ac:  01 00 00 00  nop
a00dd5b0:  81 c7 e0 08  ret
a00dd5b4:  81 e8 00 00  restore
