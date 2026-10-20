# leon2m FUN_a0148aa8 0xa0148aa8-0xa0148aec (68 bytes)
a0148aa8:  9d e3 bf 98  save  %sp, -104, %sp
a0148aac:  b2 0e 20 ff  and  %i0, 0xff, %i1
a0148ab0:  15 00 06 9b  sethi  %hi(0x1a6c00), %o2
a0148ab4:  92 10 00 19  mov  %i1, %o1
a0148ab8:  7f fe 59 ae  call  0xa00df170
a0148abc:  90 12 a3 28  or  %o2, 0x328, %o0
a0148ac0:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a0148ac4:  da 06 21 a0  ld  [ %i0 + 0x1a0 ], %o5	! 0xa802e1a0
a0148ac8:  13 20 00 00  sethi  %hi(0x80000000), %o1
a0148acc:  a1 2e 60 1f  sll  %i1, 0x1f, %l0
a0148ad0:  90 2b 40 09  andn  %o5, %o1, %o0
a0148ad4:  82 12 00 10  or  %o0, %l0, %g1
a0148ad8:  c2 26 21 a0  st  %g1, [ %i0 + 0x1a0 ]
a0148adc:  b0 16 21 a0  or  %i0, 0x1a0, %i0
a0148ae0:  40 00 2b a4  call  0xa0153970
a0148ae4:  93 e8 20 01  restore  %g0, 1, %o1
a0148ae8:  01 00 00 00  nop
