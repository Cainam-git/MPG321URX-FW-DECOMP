# leon2m FUN_a00d1a34 0xa00d1a34-0xa00d1ad4 (160 bytes)
a00d1a34:  9d e3 bf 98  save  %sp, -104, %sp
a00d1a38:  c2 0e 20 07  ldub  [ %i0 + 7 ], %g1
a00d1a3c:  80 a0 60 01  cmp  %g1, 1
a00d1a40:  02 80 00 11  be  0xa00d1a84
a00d1a44:  90 10 20 00  clr  %o0
a00d1a48:  80 a0 60 00  cmp  %g1, 0
a00d1a4c:  02 80 00 05  be  0xa00d1a60
a00d1a50:  80 a0 60 02  cmp  %g1, 2
a00d1a54:  12 80 00 19  bne  0xa00d1ab8
a00d1a58:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d1a5c:  30 80 00 10  b,a   0xa00d1a9c
a00d1a60:  40 01 c8 6d  call  0xa0143c14
a00d1a64:  01 00 00 00  nop
a00d1a68:  80 8a 20 ff  btst  0xff, %o0
a00d1a6c:  02 80 00 12  be  0xa00d1ab4
a00d1a70:  90 10 20 01  mov  1, %o0
a00d1a74:  7f fe c1 0d  call  0xa0081ea8
a00d1a78:  01 00 00 00  nop
a00d1a7c:  10 80 00 0f  b  0xa00d1ab8
a00d1a80:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d1a84:  40 01 c8 64  call  0xa0143c14
a00d1a88:  01 00 00 00  nop
a00d1a8c:  80 8a 20 ff  btst  0xff, %o0
a00d1a90:  12 80 00 09  bne  0xa00d1ab4
a00d1a94:  90 10 20 02  mov  2, %o0
a00d1a98:  30 bf ff f7  b,a   0xa00d1a74
a00d1a9c:  40 01 ac f4  call  0xa013ce6c
a00d1aa0:  01 00 00 00  nop
a00d1aa4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d1aa8:  80 a2 20 01  cmp  %o0, 1
a00d1aac:  12 bf ff f2  bne  0xa00d1a74
a00d1ab0:  90 10 20 03  mov  3, %o0
a00d1ab4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d1ab8:  92 12 62 90  or  %o1, 0x290, %o1	! 0xa802d290
a00d1abc:  90 10 20 30  mov  0x30, %o0
a00d1ac0:  94 10 20 00  clr  %o2
a00d1ac4:  40 01 e5 03  call  0xa014aed0
a00d1ac8:  96 10 21 fc  mov  0x1fc, %o3
a00d1acc:  81 c7 e0 08  ret
a00d1ad0:  91 e8 20 e0  restore  %g0, 0xe0, %o0
