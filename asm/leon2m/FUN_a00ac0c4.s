# leon2m FUN_a00ac0c4 0xa00ac0c4-0xa00ac138 (116 bytes)
a00ac0c4:  9d e3 bf 98  save  %sp, -104, %sp
a00ac0c8:  7f ff f2 f0  call  0xa00a8c88
a00ac0cc:  a2 10 20 00  clr  %l1
a00ac0d0:  90 10 21 11  mov  0x111, %o0
a00ac0d4:  40 02 6a 9f  call  0xa0146b50
a00ac0d8:  92 10 20 00  clr  %o1
a00ac0dc:  90 10 20 00  clr  %o0
a00ac0e0:  40 02 6a a3  call  0xa0146b6c
a00ac0e4:  92 10 20 00  clr  %o1
a00ac0e8:  a0 10 20 00  clr  %l0
a00ac0ec:  25 00 06 29  sethi  %hi(0x18a400), %l2
a00ac0f0:  92 10 00 10  mov  %l0, %o1
a00ac0f4:  7f ff dd d4  call  0xa00a3844
a00ac0f8:  90 14 a3 58  or  %l2, 0x358, %o0
a00ac0fc:  98 10 00 08  mov  %o0, %o4
a00ac100:  94 04 00 10  add  %l0, %l0, %o2
a00ac104:  94 02 a0 06  add  %o2, 6, %o2
a00ac108:  90 10 20 00  clr  %o0
a00ac10c:  92 10 20 2a  mov  0x2a, %o1
a00ac110:  96 10 20 01  mov  1, %o3
a00ac114:  9a 10 20 00  clr  %o5
a00ac118:  7f ff dc 23  call  0xa00a31a4
a00ac11c:  a2 04 60 01  inc  %l1
a00ac120:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00ac124:  80 a4 20 04  cmp  %l0, 4
a00ac128:  08 bf ff f3  bleu  0xa00ac0f4
a00ac12c:  92 10 00 10  mov  %l0, %o1
a00ac130:  81 c7 e0 08  ret
a00ac134:  81 e8 00 00  restore
