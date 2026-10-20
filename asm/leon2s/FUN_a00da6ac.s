# leon2s FUN_a00da6ac 0xa00da6ac-0xa00da838 (396 bytes)
a00da6ac:  9d e3 bf 80  save  %sp, -128, %sp
a00da6b0:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00da6b4:  d8 08 63 fc  ldub  [ %g1 + 0x3fc ], %o4	! 0xa80787fc
a00da6b8:  9a 03 00 0c  add  %o4, %o4, %o5
a00da6bc:  9a 03 40 0c  add  %o5, %o4, %o5
a00da6c0:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00da6c4:  9b 2b 60 04  sll  %o5, 4, %o5
a00da6c8:  82 10 60 98  or  %g1, 0x98, %g1
a00da6cc:  a0 03 40 01  add  %o5, %g1, %l0
a00da6d0:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00da6d4:  82 10 60 50  or  %g1, 0x50, %g1	! 0xa8079c50
a00da6d8:  a4 07 bf e0  add  %fp, -32, %l2
a00da6dc:  e2 08 40 0c  ldub  [ %g1 + %o4 ], %l1
a00da6e0:  90 10 00 12  mov  %l2, %o0
a00da6e4:  7f ff f0 10  call  0xa00d6724
a00da6e8:  92 10 00 10  mov  %l0, %o1
a00da6ec:  da 0f bf e0  ldub  [ %fp + -32 ], %o5
a00da6f0:  82 0b 60 f0  and  %o5, 0xf0, %g1
a00da6f4:  80 a0 60 10  cmp  %g1, 0x10
a00da6f8:  02 80 00 17  be  0xa00da754
a00da6fc:  82 0b 60 0f  and  %o5, 0xf, %g1
a00da700:  82 00 7f ff  add  %g1, -1, %g1
a00da704:  80 a0 60 00  cmp  %g1, 0
a00da708:  04 80 00 0f  ble  0xa00da744
a00da70c:  94 10 20 00  clr  %o2
a00da710:  98 07 bf f8  add  %fp, -8, %o4
a00da714:  82 0a a0 ff  and  %o2, 0xff, %g1
a00da718:  82 03 00 01  add  %o4, %g1, %g1
a00da71c:  da 08 7f ea  ldub  [ %g1 + -22 ], %o5
a00da720:  da 28 7f e9  stb  %o5, [ %g1 + -23 ]
a00da724:  c2 0f bf e0  ldub  [ %fp + -32 ], %g1
a00da728:  82 08 60 0f  and  %g1, 0xf, %g1
a00da72c:  94 02 a0 01  inc  %o2
a00da730:  82 00 7f ff  add  %g1, -1, %g1
a00da734:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00da738:  80 a3 40 01  cmp  %o5, %g1
a00da73c:  06 bf ff f7  bl  0xa00da718
a00da740:  82 0a a0 ff  and  %o2, 0xff, %g1
a00da744:  82 0a a0 ff  and  %o2, 0xff, %g1
a00da748:  9a 07 80 01  add  %fp, %g1, %o5
a00da74c:  82 10 20 01  mov  1, %g1
a00da750:  c2 2b 7f e1  stb  %g1, [ %o5 + -31 ]
a00da754:  c2 07 bf e0  ld  [ %fp + -32 ], %g1
a00da758:  9b 30 60 18  srl  %g1, 0x18, %o5
a00da75c:  9a 0b 60 0f  and  %o5, 0xf, %o5
a00da760:  9a 03 7f ff  add  %o5, -1, %o5
a00da764:  9a 0b 60 0f  and  %o5, 0xf, %o5
a00da768:  19 03 c0 00  sethi  %hi(0xf000000), %o4
a00da76c:  98 28 40 0c  andn  %g1, %o4, %o4
a00da770:  9b 2b 60 18  sll  %o5, 0x18, %o5
a00da774:  98 13 00 0d  or  %o4, %o5, %o4
a00da778:  d8 27 bf e0  st  %o4, [ %fp + -32 ]
a00da77c:  90 10 00 12  mov  %l2, %o0
a00da780:  7f ff f0 53  call  0xa00d68cc
a00da784:  92 10 00 10  mov  %l0, %o1
a00da788:  82 0c 60 ff  and  %l1, 0xff, %g1
a00da78c:  80 a0 60 00  cmp  %g1, 0
a00da790:  12 80 00 15  bne  0xa00da7e4
a00da794:  90 0a 20 ff  and  %o0, 0xff, %o0
a00da798:  80 a0 40 08  cmp  %g1, %o0
a00da79c:  1a 80 00 25  bcc  0xa00da830
a00da7a0:  94 10 20 00  clr  %o2
a00da7a4:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00da7a8:  9e 10 60 9c  or  %g1, 0x9c, %o7	! 0xa807609c
a00da7ac:  13 2a 01 e2  sethi  %hi(0xa8078800), %o1
a00da7b0:  c2 0a 60 32  ldub  [ %o1 + 0x32 ], %g1	! 0xa8078832
a00da7b4:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00da7b8:  83 28 60 02  sll  %g1, 2, %g1
a00da7bc:  d6 03 c0 01  ld  [ %o7 + %g1 ], %o3
a00da7c0:  d8 0c 00 0d  ldub  [ %l0 + %o5 ], %o4
a00da7c4:  94 02 a0 01  inc  %o2
a00da7c8:  9b 2b 60 02  sll  %o5, 2, %o5
a00da7cc:  82 0a a0 ff  and  %o2, 0xff, %g1
a00da7d0:  d8 22 c0 0d  st  %o4, [ %o3 + %o5 ]
a00da7d4:  80 a0 40 08  cmp  %g1, %o0
a00da7d8:  0a bf ff f7  bcs  0xa00da7b4
a00da7dc:  c2 0a 60 32  ldub  [ %o1 + 0x32 ], %g1
a00da7e0:  30 80 00 14  b,a   0xa00da830
a00da7e4:  80 a2 20 00  cmp  %o0, 0
a00da7e8:  02 80 00 12  be  0xa00da830
a00da7ec:  94 10 20 00  clr  %o2
a00da7f0:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00da7f4:  92 10 60 9c  or  %g1, 0x9c, %o1	! 0xa807609c
a00da7f8:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00da7fc:  c2 0a e0 32  ldub  [ %o3 + 0x32 ], %g1	! 0xa8078832
a00da800:  83 28 60 02  sll  %g1, 2, %g1
a00da804:  98 0a a0 ff  and  %o2, 0xff, %o4
a00da808:  da 02 40 01  ld  [ %o1 + %g1 ], %o5
a00da80c:  83 2b 20 02  sll  %o4, 2, %g1
a00da810:  82 00 40 0d  add  %g1, %o5, %g1
a00da814:  da 0c 00 0c  ldub  [ %l0 + %o4 ], %o5
a00da818:  94 02 a0 01  inc  %o2
a00da81c:  98 0a a0 ff  and  %o2, 0xff, %o4
a00da820:  da 20 60 c0  st  %o5, [ %g1 + 0xc0 ]
a00da824:  80 a3 00 08  cmp  %o4, %o0
a00da828:  0a bf ff f6  bcs  0xa00da800
a00da82c:  c2 0a e0 32  ldub  [ %o3 + 0x32 ], %g1
a00da830:  81 c7 e0 08  ret
a00da834:  81 e8 00 00  restore
