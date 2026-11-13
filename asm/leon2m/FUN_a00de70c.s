# leon2m FUN_a00de70c 0xa00de70c-0xa00de7c4 (184 bytes)
a00de70c:  9d e3 bf 98  save  %sp, -104, %sp
a00de710:  03 2a 00 90  sethi  %hi(0xa8024000), %g1
a00de714:  11 27 c0 80  sethi  %hi(0x9f020000), %o0
a00de718:  a2 10 60 00  mov  %g1, %l1
a00de71c:  67 fe b6 cd  call  0x4008c250
a00de720:  90 12 22 04  or  %o0, 0x204, %o0
a00de724:  a0 10 20 00  clr  %l0
a00de728:  98 10 20 00  clr  %o4
a00de72c:  9a 10 20 00  clr  %o5
a00de730:  93 32 00 0d  srl  %o0, %o5, %o1
a00de734:  98 03 20 01  inc  %o4
a00de738:  80 8a 60 01  btst  1, %o1
a00de73c:  12 80 00 03  bne  0xa00de748
a00de740:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00de744:  a0 04 20 01  inc  %l0
a00de748:  80 a3 60 17  cmp  %o5, 0x17
a00de74c:  08 bf ff fa  bleu  0xa00de734
a00de750:  93 32 00 0d  srl  %o0, %o5, %o1
a00de754:  15 27 c0 80  sethi  %hi(0x9f020000), %o2
a00de758:  67 fe b6 be  call  0x4008c250
a00de75c:  90 12 a2 00  or  %o2, 0x200, %o0	! 0x9f020200
a00de760:  98 10 20 1b  mov  0x1b, %o4
a00de764:  9a 10 20 1b  mov  0x1b, %o5
a00de768:  97 32 00 0d  srl  %o0, %o5, %o3
a00de76c:  98 03 3f ff  add  %o4, -1, %o4
a00de770:  80 8a e0 01  btst  1, %o3
a00de774:  02 80 00 03  be  0xa00de780
a00de778:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00de77c:  a0 04 20 01  inc  %l0
a00de780:  80 a3 60 03  cmp  %o5, 3
a00de784:  18 bf ff fa  bgu  0xa00de76c
a00de788:  97 32 00 0d  srl  %o0, %o5, %o3
a00de78c:  9e 0c 20 ff  and  %l0, 0xff, %o7
a00de790:  99 2b e0 0c  sll  %o7, 0xc, %o4
a00de794:  1b 2a 00 f0  sethi  %hi(0xa803c000), %o5
a00de798:  92 23 40 0c  sub  %o5, %o4, %o1
a00de79c:  80 a2 40 11  cmp  %o1, %l1
a00de7a0:  02 80 00 07  be  0xa00de7bc
a00de7a4:  21 00 06 63  sethi  %hi(0x198c00), %l0
a00de7a8:  90 14 22 70  or  %l0, 0x270, %o0	! 0x198e70
a00de7ac:  40 00 02 71  call  0xa00df170
a00de7b0:  94 10 00 11  mov  %l1, %o2
a00de7b4:  10 80 00 00  b  0xa00de7b4
a00de7b8:  01 00 00 00  nop
a00de7bc:  81 c7 e0 08  ret
a00de7c0:  81 e8 00 00  restore
