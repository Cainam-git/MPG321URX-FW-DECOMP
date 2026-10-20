# leon2m FUN_a00bc86c 0xa00bc86c-0xa00bc8c4 (88 bytes)
a00bc86c:  9d e3 bf 98  save  %sp, -104, %sp
a00bc870:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00bc874:  b2 13 62 90  or  %o5, 0x290, %i1	! 0xa802d290
a00bc878:  d0 0e 60 14  ldub  [ %i1 + 0x14 ], %o0
a00bc87c:  de 0e 60 12  ldub  [ %i1 + 0x12 ], %o7
a00bc880:  d2 0e 60 13  ldub  [ %i1 + 0x13 ], %o1
a00bc884:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00bc888:  9a 10 60 78  or  %g1, 0x78, %o5	! 0xa802d078
a00bc88c:  98 02 20 30  add  %o0, 0x30, %o4
a00bc890:  96 03 e0 30  add  %o7, 0x30, %o3
a00bc894:  94 02 60 30  add  %o1, 0x30, %o2
a00bc898:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00bc89c:  d6 2b 60 07  stb  %o3, [ %o5 + 7 ]
a00bc8a0:  d4 2b 60 08  stb  %o2, [ %o5 + 8 ]
a00bc8a4:  7f ff f9 08  call  0xa00bacc4
a00bc8a8:  90 10 20 0a  mov  0xa, %o0
a00bc8ac:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bc8b0:  7f ff f8 28  call  0xa00ba950
a00bc8b4:  90 10 00 18  mov  %i0, %o0
a00bc8b8:  7f ff f8 cb  call  0xa00babe4
a00bc8bc:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bc8c0:  01 00 00 00  nop
