# leon2m FUN_a00b867c 0xa00b867c-0xa00b8774 (248 bytes)  [FUN_a00b876c = unreachable ret/restore tail, merged]
a00b867c:  9d e3 bf 98  save  %sp, -104, %sp
a00b8680:  40 02 39 df  call  0xa0146dfc
a00b8684:  90 10 20 00  clr  %o0
a00b8688:  80 8a 20 ff  btst  0xff, %o0
a00b868c:  12 80 00 07  bne  0xa00b86a8
a00b8690:  01 00 00 00  nop
a00b8694:  40 02 39 da  call  0xa0146dfc
a00b8698:  90 10 20 01  mov  1, %o0	! 0x1
a00b869c:  80 8a 20 ff  btst  0xff, %o0
a00b86a0:  02 80 00 0b  be  0xa00b86cc
a00b86a4:  98 10 27 2c  mov  0x72c, %o4
a00b86a8:  40 02 2d 5b  call  0xa0143c14
a00b86ac:  90 10 20 00  clr  %o0
a00b86b0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b86b4:  80 a2 20 0a  cmp  %o0, 0xa
a00b86b8:  02 80 00 05  be  0xa00b86cc
a00b86bc:  98 10 27 2c  mov  0x72c, %o4
a00b86c0:  7f ff 62 46  call  0xa0090fd8
a00b86c4:  01 00 00 00  nop
a00b86c8:  98 10 27 2c  mov  0x72c, %o4	! 0x72c
a00b86cc:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00b86d0:  d8 32 60 92  sth  %o4, [ %o1 + 0x92 ]	! 0xa802b092
a00b86d4:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00b86d8:  c0 33 60 94  clrh  [ %o5 + 0x94 ]	! 0xa802b094
a00b86dc:  90 10 20 00  clr  %o0
a00b86e0:  92 10 20 00  clr  %o1
a00b86e4:  94 10 20 00  clr  %o2
a00b86e8:  40 01 2c 48  call  0xa0103808
a00b86ec:  96 10 20 00  clr  %o3
a00b86f0:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00b86f4:  9a 13 22 90  or  %o4, 0x290, %o5	! 0xa802d290
a00b86f8:  c2 0b 61 d5  ldub  [ %o5 + 0x1d5 ], %g1
a00b86fc:  80 a0 60 00  cmp  %g1, 0
a00b8700:  12 80 00 13  bne  0xa00b874c
a00b8704:  33 2a 00 b3  sethi  %hi(0xa802cc00), %i1
a00b8708:  1f 00 00 15  sethi  %hi(0x5400), %o7
a00b870c:  d6 13 61 f6  lduh  [ %o5 + 0x1f6 ], %o3
a00b8710:  94 13 e1 aa  or  %o7, 0x1aa, %o2
a00b8714:  80 a2 c0 0a  cmp  %o3, %o2
a00b8718:  02 80 00 0d  be  0xa00b874c
a00b871c:  31 00 00 10  sethi  %hi(0x4000), %i0
a00b8720:  d0 03 22 90  ld  [ %o4 + 0x290 ], %o0
a00b8724:  80 8a 00 18  btst  %o0, %i0
a00b8728:  12 80 00 0a  bne  0xa00b8750
a00b872c:  92 16 63 f4  or  %i1, 0x3f4, %o1
a00b8730:  82 16 63 f4  or  %i1, 0x3f4, %g1
a00b8734:  da 10 60 04  lduh  [ %g1 + 4 ], %o5
a00b8738:  80 8b 64 00  btst  0x400, %o5
a00b873c:  12 80 00 0b  bne  0xa00b8768
a00b8740:  01 00 00 00  nop
a00b8744:  7f ff fe 16  call  0xa00b7f9c
a00b8748:  90 10 20 19  mov  0x19, %o0	! 0x19
a00b874c:  92 16 63 f4  or  %i1, 0x3f4, %o1
a00b8750:  f2 12 60 04  lduh  [ %o1 + 4 ], %i1
a00b8754:  80 8e 64 00  btst  0x400, %i1
a00b8758:  12 80 00 04  bne  0xa00b8768
a00b875c:  b0 10 20 01  mov  1, %i0
a00b8760:  40 02 32 73  call  0xa014512c
a00b8764:  93 e8 20 00  restore  %g0, 0, %o1
a00b8768:  01 00 00 00  nop
a00b876c:  81 c7 e0 08  ret
a00b8770:  81 e8 00 00  restore
