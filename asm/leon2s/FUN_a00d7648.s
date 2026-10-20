# leon2s FUN_a00d7648 0xa00d7648-0xa00d76ac (100 bytes)
a00d7648:  c2 0a 00 00  ldub  [ %o0 ], %g1
a00d764c:  82 08 60 7f  and  %g1, 0x7f, %g1
a00d7650:  c2 2a 40 00  stb  %g1, [ %o1 ]
a00d7654:  c2 0a 20 01  ldub  [ %o0 + 1 ], %g1
a00d7658:  82 08 60 f0  and  %g1, 0xf0, %g1
a00d765c:  c2 2a 60 01  stb  %g1, [ %o1 + 1 ]
a00d7660:  9a 10 20 02  mov  2, %o5
a00d7664:  94 10 20 00  clr  %o2
a00d7668:  82 0a a0 ff  and  %o2, 0xff, %g1
a00d766c:  98 10 00 0d  mov  %o5, %o4
a00d7670:  82 02 00 01  add  %o0, %g1, %g1
a00d7674:  96 0b 60 ff  and  %o5, 0xff, %o3
a00d7678:  da 08 60 02  ldub  [ %g1 + 2 ], %o5
a00d767c:  94 02 a0 01  inc  %o2
a00d7680:  98 03 20 01  inc  %o4
a00d7684:  82 0a a0 ff  and  %o2, 0xff, %g1
a00d7688:  da 2a 40 0b  stb  %o5, [ %o1 + %o3 ]
a00d768c:  80 a0 60 0f  cmp  %g1, 0xf
a00d7690:  08 bf ff f7  bleu  0xa00d766c
a00d7694:  9a 10 00 0c  mov  %o4, %o5
a00d7698:  c2 0a 20 12  ldub  [ %o0 + 0x12 ], %g1
a00d769c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d76a0:  82 08 60 7f  and  %g1, 0x7f, %g1
a00d76a4:  81 c3 e0 08  retl
a00d76a8:  c2 2a 40 0d  stb  %g1, [ %o1 + %o5 ]
