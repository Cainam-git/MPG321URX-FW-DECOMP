# leon2s FUN_a00a1638 0xa00a1638-0xa00a16cc (148 bytes)
a00a1638:  9d e3 bf 98  save  %sp, -104, %sp
a00a163c:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a1640:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a1644:  c2 08 63 68  ldub  [ %g1 + 0x368 ], %g1
a00a1648:  a2 10 00 18  mov  %i0, %l1
a00a164c:  92 10 20 00  clr  %o1
a00a1650:  80 a0 60 00  cmp  %g1, 0
a00a1654:  90 10 00 10  mov  %l0, %o0
a00a1658:  02 80 00 1b  be  0xa00a16c4
a00a165c:  b0 10 20 01  mov  1, %i0
a00a1660:  7f ff d3 23  call  0xa00962ec
a00a1664:  01 00 00 00  nop
a00a1668:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00a166c:  82 10 63 e0  or  %g1, 0x3e0, %g1	! 0xa807d7e0
a00a1670:  9a 5c 61 90  smul  %l1, 0x190, %o5
a00a1674:  9a 03 40 01  add  %o5, %g1, %o5
a00a1678:  c0 2b 60 05  clrb  [ %o5 + 5 ]
a00a167c:  c0 2b 60 04  clrb  [ %o5 + 4 ]
a00a1680:  90 10 00 10  mov  %l0, %o0
a00a1684:  7f ff d3 30  call  0xa0096344
a00a1688:  92 10 20 00  clr  %o1
a00a168c:  90 10 00 10  mov  %l0, %o0
a00a1690:  7f ff fd 20  call  0xa00a0b10
a00a1694:  92 10 20 00  clr  %o1
a00a1698:  80 a4 60 00  cmp  %l1, 0
a00a169c:  12 80 00 05  bne  0xa00a16b0
a00a16a0:  01 00 00 00  nop
a00a16a4:  40 00 40 d7  call  0xa00b1a00
a00a16a8:  01 00 00 00  nop
a00a16ac:  30 80 00 03  b,a   0xa00a16b8
a00a16b0:  40 00 41 07  call  0xa00b1acc
a00a16b4:  01 00 00 00  nop
a00a16b8:  7f ff f4 d1  call  0xa009e9fc
a00a16bc:  90 10 00 10  mov  %l0, %o0
a00a16c0:  b0 10 20 00  clr  %i0
a00a16c4:  81 c7 e0 08  ret
a00a16c8:  81 e8 00 00  restore
