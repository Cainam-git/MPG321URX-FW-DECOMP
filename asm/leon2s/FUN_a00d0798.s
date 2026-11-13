# leon2s FUN_a00d0798 0xa00d0798-0xa00d0828 (144 bytes)  [FUN_a00d0820 = unreachable ret/restore tail, merged]
a00d0798:  9d e3 bf 98  save  %sp, -104, %sp
a00d079c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00d07a0:  82 06 00 18  add  %i0, %i0, %g1
a00d07a4:  82 00 40 18  add  %g1, %i0, %g1
a00d07a8:  a1 28 60 03  sll  %g1, 3, %l0
a00d07ac:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a00d07b0:  03 3f ff 3f  sethi  %hi(0xfffcfc00), %g1
a00d07b4:  a2 13 63 b0  or  %o5, 0x3b0, %l1
a00d07b8:  a4 10 63 ff  or  %g1, 0x3ff, %l2
a00d07bc:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00d07c0:  82 08 40 12  and  %g1, %l2, %g1
a00d07c4:  27 00 00 40  sethi  %hi(0x10000), %l3
a00d07c8:  82 10 40 13  or  %g1, %l3, %g1
a00d07cc:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00d07d0:  40 3b 20 c8  call  0xa0f98af0
a00d07d4:  90 10 20 00  clr  %o0
a00d07d8:  80 8a 20 ff  btst  0xff, %o0
a00d07dc:  92 10 21 2c  mov  0x12c, %o1
a00d07e0:  b0 10 20 00  clr  %i0
a00d07e4:  12 80 00 06  bne  0xa00d07fc
a00d07e8:  90 10 20 0a  mov  0xa, %o0
a00d07ec:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00d07f0:  82 08 40 12  and  %g1, %l2, %g1
a00d07f4:  10 80 00 0a  b  0xa00d081c
a00d07f8:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00d07fc:  7f ff ff 4d  call  0xa00d0530
a00d0800:  01 00 00 00  nop
a00d0804:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00d0808:  82 08 40 12  and  %g1, %l2, %g1
a00d080c:  82 10 40 13  or  %g1, %l3, %g1
a00d0810:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00d0814:  7f ff f0 89  call  0xa00cca38
a00d0818:  81 e8 00 00  restore
a00d081c:  01 00 00 00  nop
a00d0820:  81 c7 e0 08  ret
a00d0824:  81 e8 00 00  restore
