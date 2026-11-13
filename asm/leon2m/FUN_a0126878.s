# leon2m FUN_a0126878 0xa0126878-0xa01268cc (84 bytes)
a0126878:  9d e3 bf 90  save  %sp, -112, %sp
a012687c:  7f ff f8 13  call  0xa01248c8
a0126880:  21 2a 00 b6  sethi  %hi(0xa802d800), %l0
a0126884:  80 8a 20 ff  btst  0xff, %o0
a0126888:  90 10 20 60  mov  0x60, %o0
a012688c:  92 10 20 02  mov  2, %o1
a0126890:  94 10 20 b2  mov  0xb2, %o2
a0126894:  96 10 20 05  mov  5, %o3
a0126898:  02 80 00 06  be  0xa01268b0
a012689c:  98 10 20 00  clr  %o4
a01268a0:  82 10 20 02  mov  2, %g1
a01268a4:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a01268a8:  40 00 84 90  call  0xa0147ae8
a01268ac:  9a 14 20 88  or  %l0, 0x88, %o5
a01268b0:  d2 0c 20 88  ldub  [ %l0 + 0x88 ], %o1
a01268b4:  9a 14 20 88  or  %l0, 0x88, %o5
a01268b8:  b1 2a 60 08  sll  %o1, 8, %i0
a01268bc:  d0 0b 60 01  ldub  [ %o5 + 1 ], %o0
a01268c0:  b0 12 00 18  or  %o0, %i0, %i0
a01268c4:  81 c7 e0 08  ret
a01268c8:  81 e8 00 00  restore
