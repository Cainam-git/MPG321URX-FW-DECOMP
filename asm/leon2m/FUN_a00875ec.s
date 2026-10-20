# leon2m FUN_a00875ec 0xa00875ec-0xa008767c (144 bytes)
a00875ec:  9d e3 bf 98  save  %sp, -104, %sp
a00875f0:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00875f4:  13 00 03 fd  sethi  %hi(0xff400), %o1
a00875f8:  a0 14 a2 90  or  %l2, 0x290, %l0
a00875fc:  90 12 61 e8  or  %o1, 0x1e8, %o0
a0087600:  40 01 5e dc  call  0xa00df170
a0087604:  e2 0c 20 b3  ldub  [ %l0 + 0xb3 ], %l1
a0087608:  40 02 f0 b0  call  0xa01438c8
a008760c:  90 10 20 00  clr  %o0
a0087610:  90 10 20 01  mov  1, %o0
a0087614:  40 03 24 55  call  0xa0150768
a0087618:  92 10 20 ff  mov  0xff, %o1
a008761c:  92 10 23 ff  mov  0x3ff, %o1
a0087620:  40 03 11 29  call  0xa014bac4
a0087624:  90 10 20 02  mov  2, %o0
a0087628:  40 03 11 8c  call  0xa014bc58
a008762c:  90 10 20 00  clr  %o0
a0087630:  40 03 19 71  call  0xa014dbf4
a0087634:  90 10 20 00  clr  %o0
a0087638:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a008763c:  96 12 23 f4  or  %o0, 0x3f4, %o3	! 0xa802cff4
a0087640:  da 12 e0 3e  lduh  [ %o3 + 0x3e ], %o5
a0087644:  03 00 00 10  sethi  %hi(0x4000), %g1
a0087648:  98 2b 40 01  andn  %o5, %g1, %o4
a008764c:  80 88 40 0d  btst  %g1, %o5
a0087650:  02 80 00 04  be  0xa0087660
a0087654:  c0 24 20 b0  clr  [ %l0 + 0xb0 ]
a0087658:  10 80 00 04  b  0xa0087668
a008765c:  d8 32 e0 3e  sth  %o4, [ %o3 + 0x3e ]
a0087660:  40 01 45 9d  call  0xa00d8cd4
a0087664:  01 00 00 00  nop
a0087668:  94 14 a2 90  or  %l2, 0x290, %o2
a008766c:  96 0c 60 ff  and  %l1, 0xff, %o3
a0087670:  d6 22 a0 b0  st  %o3, [ %o2 + 0xb0 ]
a0087674:  81 c7 e0 08  ret
a0087678:  81 e8 00 00  restore
