# leon2m FUN_a012e850 0xa012e850-0xa012e8c0 (112 bytes)
a012e850:  9d e3 bf 90  save  %sp, -112, %sp
a012e854:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a012e858:  90 12 61 a0  or  %o1, 0x1a0, %o0	! 0xa802e1a0
a012e85c:  da 0a 20 37  ldub  [ %o0 + 0x37 ], %o5
a012e860:  d8 02 20 34  ld  [ %o0 + 0x34 ], %o4
a012e864:  b0 0e 20 ff  and  %i0, 0xff, %i0
a012e868:  94 10 20 02  mov  2, %o2
a012e86c:  96 07 bf f0  add  %fp, -16, %o3
a012e870:  80 a3 60 01  cmp  %o5, 1
a012e874:  b0 06 00 18  add  %i0, %i0, %i0
a012e878:  99 33 20 08  srl  %o4, 8, %o4
a012e87c:  08 80 00 03  bleu  0xa012e888
a012e880:  92 10 21 20  mov  0x120, %o1
a012e884:  92 10 22 40  mov  0x240, %o1
a012e888:  92 0a 63 60  and  %o1, 0x360, %o1
a012e88c:  82 02 60 70  add  %o1, 0x70, %g1
a012e890:  9a 03 00 01  add  %o4, %g1, %o5
a012e894:  98 03 40 18  add  %o5, %i0, %o4
a012e898:  9f 2b 20 10  sll  %o4, 0x10, %o7
a012e89c:  93 33 e0 10  srl  %o7, 0x10, %o1
a012e8a0:  40 00 46 b0  call  0xa0140360
a012e8a4:  d0 0a 20 34  ldub  [ %o0 + 0x34 ], %o0
a012e8a8:  d6 0f bf f1  ldub  [ %fp + -15 ], %o3
a012e8ac:  91 2a e0 08  sll  %o3, 8, %o0
a012e8b0:  d4 0f bf f0  ldub  [ %fp + -16 ], %o2
a012e8b4:  b0 12 80 08  or  %o2, %o0, %i0
a012e8b8:  81 c7 e0 08  ret
a012e8bc:  81 e8 00 00  restore
