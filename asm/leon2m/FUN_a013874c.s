# leon2m FUN_a013874c 0xa013874c-0xa01387a4 (88 bytes)
a013874c:  9d e3 bf 90  save  %sp, -112, %sp
a0138750:  c0 27 bf f4  clr  [ %fp + -12 ]
a0138754:  a2 07 bf f4  add  %fp, -12, %l1
a0138758:  21 00 06 95  sethi  %hi(0x1a5400), %l0
a013875c:  92 10 20 0c  mov  0xc, %o1
a0138760:  94 10 00 11  mov  %l1, %o2
a0138764:  96 10 20 01  mov  1, %o3
a0138768:  67 fd 4f 5a  call  0x4008c4d0
a013876c:  90 10 20 01  mov  1, %o0
a0138770:  7f fe 93 a9  call  0xa00dd614
a0138774:  90 10 20 20  mov  0x20, %o0
a0138778:  80 8a 20 ff  btst  0xff, %o0
a013877c:  02 80 00 04  be  0xa013878c
a0138780:  90 14 22 18  or  %l0, 0x218, %o0
a0138784:  7f fe 9a 7b  call  0xa00df170
a0138788:  01 00 00 00  nop
a013878c:  c2 0f bf f4  ldub  [ %fp + -12 ], %g1
a0138790:  80 88 60 40  btst  0x40, %g1
a0138794:  02 bf ff f3  be  0xa0138760
a0138798:  92 10 20 0c  mov  0xc, %o1
a013879c:  81 c7 e0 08  ret
a01387a0:  81 e8 00 00  restore
