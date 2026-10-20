# leon2s FUN_a00b229c 0xa00b229c-0xa00b22fc (96 bytes)
a00b229c:  9d e3 bf 98  save  %sp, -104, %sp
a00b22a0:  25 2a 01 f7  sethi  %hi(0xa807dc00), %l2
a00b22a4:  c2 0c a2 92  ldub  [ %l2 + 0x292 ], %g1	! 0xa807de92
a00b22a8:  80 a0 60 00  cmp  %g1, 0
a00b22ac:  02 80 00 12  be  0xa00b22f4
a00b22b0:  a2 10 20 00  clr  %l1
a00b22b4:  a0 10 20 0f  mov  0xf, %l0
a00b22b8:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00b22bc:  82 10 63 b8  or  %g1, 0x3b8, %g1	! 0xa80793b8
a00b22c0:  9a 04 40 01  add  %l1, %g1, %o5
a00b22c4:  c2 0b 60 05  ldub  [ %o5 + 5 ], %g1
a00b22c8:  80 a0 60 00  cmp  %g1, 0
a00b22cc:  02 80 00 06  be  0xa00b22e4
a00b22d0:  a2 04 60 18  add  %l1, 0x18, %l1
a00b22d4:  c0 2b 60 05  clrb  [ %o5 + 5 ]
a00b22d8:  c2 03 60 14  ld  [ %o5 + 0x14 ], %g1
a00b22dc:  9f c0 40 00  call  %g1
a00b22e0:  01 00 00 00  nop
a00b22e4:  a0 84 3f ff  addcc  %l0, -1, %l0
a00b22e8:  1c bf ff f5  bpos  0xa00b22bc
a00b22ec:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00b22f0:  c0 2c a2 92  clrb  [ %l2 + 0x292 ]
a00b22f4:  81 c7 e0 08  ret
a00b22f8:  81 e8 00 00  restore
