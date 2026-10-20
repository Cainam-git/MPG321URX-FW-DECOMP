# leon2m FUN_a012fc70 0xa012fc70-0xa012fcf4 (132 bytes)
a012fc70:  9d e3 bf 98  save  %sp, -104, %sp
a012fc74:  b0 0e 20 ff  and  %i0, 0xff, %i0
a012fc78:  97 2e 20 04  sll  %i0, 4, %o3
a012fc7c:  94 22 c0 18  sub  %o3, %i0, %o2
a012fc80:  1b 2a 00 b7  sethi  %hi(0xa802dc00), %o5
a012fc84:  a0 13 63 30  or  %o5, 0x330, %l0	! 0xa802df30
a012fc88:  83 2a a0 03  sll  %o2, 3, %g1
a012fc8c:  d2 04 00 01  ld  [ %l0 + %g1 ], %o1
a012fc90:  91 32 60 0c  srl  %o1, 0xc, %o0
a012fc94:  7f ff 36 e3  call  0xa00fd820
a012fc98:  90 0a 20 0f  and  %o0, 0xf, %o0
a012fc9c:  b0 0a 20 ff  and  %o0, 0xff, %i0
a012fca0:  80 a6 20 b1  cmp  %i0, 0xb1
a012fca4:  12 80 00 12  bne  0xa012fcec
a012fca8:  96 10 3f ff  mov  -1, %o3
a012fcac:  13 2a 00 a9  sethi  %hi(0xa802a400), %o1
a012fcb0:  d8 0a 60 4c  ldub  [ %o1 + 0x4c ], %o4	! 0xa802a44c
a012fcb4:  91 2b 20 04  sll  %o4, 4, %o0
a012fcb8:  9e 22 00 0c  sub  %o0, %o4, %o7
a012fcbc:  80 a3 20 ff  cmp  %o4, 0xff
a012fcc0:  02 80 00 0a  be  0xa012fce8
a012fcc4:  9b 2b e0 03  sll  %o7, 3, %o5
a012fcc8:  d8 04 00 0d  ld  [ %l0 + %o5 ], %o4
a012fccc:  b1 33 20 0c  srl  %o4, 0xc, %i0
a012fcd0:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a012fcd4:  9a 0e 20 0f  and  %i0, 0xf, %o5
a012fcd8:  82 12 e2 24  or  %o3, 0x224, %g1
a012fcdc:  94 5b 60 2a  smul  %o5, 0x2a, %o2
a012fce0:  a0 02 80 01  add  %o2, %g1, %l0
a012fce4:  d6 0c 20 0a  ldub  [ %l0 + 0xa ], %o3
a012fce8:  b0 0a e0 ff  and  %o3, 0xff, %i0
a012fcec:  81 c7 e0 08  ret
a012fcf0:  81 e8 00 00  restore
