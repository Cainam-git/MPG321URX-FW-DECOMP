# leon2m FUN_a012eb4c 0xa012eb4c-0xa012eba4 (88 bytes)
a012eb4c:  9d e3 bf 90  save  %sp, -112, %sp
a012eb50:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a012eb54:  90 12 61 a0  or  %o1, 0x1a0, %o0	! 0xa802e1a0
a012eb58:  da 0a 20 37  ldub  [ %o0 + 0x37 ], %o5
a012eb5c:  d8 02 20 34  ld  [ %o0 + 0x34 ], %o4
a012eb60:  94 10 20 01  mov  1, %o2
a012eb64:  96 07 bf f7  add  %fp, -9, %o3
a012eb68:  80 a3 60 01  cmp  %o5, 1
a012eb6c:  99 33 20 08  srl  %o4, 8, %o4
a012eb70:  c0 2f bf f7  clrb  [ %fp + -9 ]
a012eb74:  08 80 00 03  bleu  0xa012eb80
a012eb78:  92 10 21 20  mov  0x120, %o1
a012eb7c:  92 10 22 40  mov  0x240, %o1
a012eb80:  9a 0a 63 60  and  %o1, 0x360, %o5
a012eb84:  b0 03 00 0d  add  %o4, %o5, %i0
a012eb88:  9f 2e 20 10  sll  %i0, 0x10, %o7
a012eb8c:  93 33 e0 10  srl  %o7, 0x10, %o1
a012eb90:  40 00 45 f4  call  0xa0140360
a012eb94:  d0 0a 20 34  ldub  [ %o0 + 0x34 ], %o0
a012eb98:  f0 0f bf f7  ldub  [ %fp + -9 ], %i0
a012eb9c:  81 c7 e0 08  ret
a012eba0:  81 e8 00 00  restore
