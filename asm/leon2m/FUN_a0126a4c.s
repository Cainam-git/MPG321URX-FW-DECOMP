# leon2m FUN_a0126a4c 0xa0126a4c-0xa0126ae4 (152 bytes)
a0126a4c:  9d e3 bf 90  save  %sp, -112, %sp
a0126a50:  7f ff f7 9e  call  0xa01248c8
a0126a54:  21 2a 00 b6  sethi  %hi(0xa802d800), %l0
a0126a58:  80 8a 20 ff  btst  0xff, %o0
a0126a5c:  98 10 20 00  clr  %o4
a0126a60:  94 10 20 08  mov  8, %o2
a0126a64:  96 10 20 05  mov  5, %o3
a0126a68:  92 10 20 02  mov  2, %o1
a0126a6c:  02 80 00 06  be  0xa0126a84
a0126a70:  90 10 20 60  mov  0x60, %o0
a0126a74:  82 10 20 02  mov  2, %g1
a0126a78:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a0126a7c:  40 00 84 1b  call  0xa0147ae8
a0126a80:  9a 14 20 88  or  %l0, 0x88, %o5
a0126a84:  de 0c 20 88  ldub  [ %l0 + 0x88 ], %o7
a0126a88:  9a 14 20 88  or  %l0, 0x88, %o5
a0126a8c:  97 2b e0 08  sll  %o7, 8, %o3
a0126a90:  d4 0b 60 01  ldub  [ %o5 + 1 ], %o2
a0126a94:  13 00 06 91  sethi  %hi(0x1a4400), %o1
a0126a98:  a0 12 80 0b  or  %o2, %o3, %l0
a0126a9c:  90 12 61 90  or  %o1, 0x190, %o0
a0126aa0:  7f fe e1 b4  call  0xa00df170
a0126aa4:  92 10 00 10  mov  %l0, %o1
a0126aa8:  40 00 bf 66  call  0xa0156840
a0126aac:  90 10 00 10  mov  %l0, %o0
a0126ab0:  19 00 06 93  sethi  %hi(0x1a4c00), %o4
a0126ab4:  40 00 bd a9  call  0xa0156158
a0126ab8:  d4 1b 22 a0  ldd  [ %o4 + 0x2a0 ], %o2	! 0x1a4ea0
a0126abc:  40 00 b9 a9  call  0xa0155160
a0126ac0:  01 00 00 00  nop
a0126ac4:  b1 2a 20 10  sll  %o0, 0x10, %i0
a0126ac8:  b1 36 20 10  srl  %i0, 0x10, %i0
a0126acc:  11 00 06 91  sethi  %hi(0x1a4400), %o0
a0126ad0:  90 12 21 b0  or  %o0, 0x1b0, %o0	! 0x1a45b0
a0126ad4:  7f fe e1 a7  call  0xa00df170
a0126ad8:  92 10 00 18  mov  %i0, %o1
a0126adc:  81 c7 e0 08  ret
a0126ae0:  81 e8 00 00  restore
