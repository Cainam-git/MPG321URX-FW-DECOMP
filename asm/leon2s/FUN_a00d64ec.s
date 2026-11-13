# leon2s FUN_a00d64ec 0xa00d64ec-0xa00d6560 (116 bytes)
a00d64ec:  9d e3 bf 90  save  %sp, -112, %sp
a00d64f0:  a0 10 20 09  mov  9, %l0
a00d64f4:  03 33 c0 4c  sethi  %hi(0xcf013000), %g1
a00d64f8:  82 10 62 04  or  %g1, 0x204, %g1	! 0xcf013204
a00d64fc:  da 00 40 00  ld  [ %g1 ], %o5
a00d6500:  9a 13 60 01  or  %o5, 1, %o5
a00d6504:  da 20 40 00  st  %o5, [ %g1 ]
a00d6508:  40 3b ac a3  call  0xa0fc1794
a00d650c:  90 10 20 05  mov  5, %o0
a00d6510:  c0 2f bf f7  clrb  [ %fp + -9 ]
a00d6514:  90 10 20 00  clr  %o0
a00d6518:  92 10 20 90  mov  0x90, %o1
a00d651c:  94 10 22 c0  mov  0x2c0, %o2
a00d6520:  40 3a ff 9f  call  0xa0f9639c
a00d6524:  96 07 bf f7  add  %fp, -9, %o3
a00d6528:  82 04 3f ff  add  %l0, -1, %g1
a00d652c:  9a 08 60 ff  and  %g1, 0xff, %o5
a00d6530:  80 8a 20 ff  btst  0xff, %o0
a00d6534:  02 80 00 03  be  0xa00d6540
a00d6538:  a0 10 00 01  mov  %g1, %l0
a00d653c:  c0 2f bf f7  clrb  [ %fp + -9 ]
a00d6540:  c2 0f bf f7  ldub  [ %fp + -9 ], %g1
a00d6544:  80 88 60 02  btst  2, %g1
a00d6548:  12 80 00 04  bne  0xa00d6558
a00d654c:  80 a3 60 ff  cmp  %o5, 0xff
a00d6550:  12 bf ff ea  bne  0xa00d64f8
a00d6554:  03 33 c0 4c  sethi  %hi(0xcf013000), %g1
a00d6558:  81 c7 e0 08  ret
a00d655c:  81 e8 00 00  restore
