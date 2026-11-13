# leon2m FUN_a00e29a4 0xa00e29a4-0xa00e2aec (328 bytes)
a00e29a4:  9d e3 bf 98  save  %sp, -104, %sp
a00e29a8:  80 a6 60 09  cmp  %i1, 9
a00e29ac:  18 80 00 38  bgu  0xa00e2a8c
a00e29b0:  82 10 00 19  mov  %i1, %g1
a00e29b4:  80 a6 a0 09  cmp  %i2, 9
a00e29b8:  18 80 00 2e  bgu  0xa00e2a70
a00e29bc:  b2 10 00 1a  mov  %i2, %i1
a00e29c0:  13 2a 00 97  sethi  %hi(0xa8025c00), %o1
a00e29c4:  15 2a 00 97  sethi  %hi(0xa8025c00), %o2
a00e29c8:  17 2a 00 97  sethi  %hi(0xa8025c00), %o3
a00e29cc:  b5 28 60 02  sll  %g1, 2, %i2
a00e29d0:  98 10 00 1d  mov  %i5, %o4
a00e29d4:  90 10 00 18  mov  %i0, %o0
a00e29d8:  92 12 63 70  or  %o1, 0x370, %o1
a00e29dc:  94 12 a3 48  or  %o2, 0x348, %o2
a00e29e0:  80 a0 7f ff  cmp  %g1, -1
a00e29e4:  02 80 00 30  be  0xa00e2aa4
a00e29e8:  96 12 e3 20  or  %o3, 0x320, %o3
a00e29ec:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a00e29f0:  17 2a 00 97  sethi  %hi(0xa8025c00), %o3
a00e29f4:  3b 2a 00 97  sethi  %hi(0xa8025c00), %i5
a00e29f8:  82 12 e3 48  or  %o3, 0x348, %g1
a00e29fc:  b2 13 63 70  or  %o5, 0x370, %i1
a00e2a00:  a2 17 63 20  or  %i5, 0x320, %l1
a00e2a04:  d4 00 40 1a  ld  [ %g1 + %i2 ], %o2
a00e2a08:  d2 06 40 1a  ld  [ %i1 + %i2 ], %o1
a00e2a0c:  7f ff f7 5a  call  0xa00e0774
a00e2a10:  d6 04 40 1a  ld  [ %l1 + %i2 ], %o3
a00e2a14:  13 2a 00 97  sethi  %hi(0xa8025c00), %o1
a00e2a18:  15 2a 00 97  sethi  %hi(0xa8025c00), %o2
a00e2a1c:  19 2a 00 97  sethi  %hi(0xa8025c00), %o4
a00e2a20:  b2 13 22 a8  or  %o4, 0x2a8, %i1	! 0xa8025ea8
a00e2a24:  9e 12 62 f8  or  %o1, 0x2f8, %o7
a00e2a28:  9a 12 a2 d0  or  %o2, 0x2d0, %o5
a00e2a2c:  d6 06 40 1a  ld  [ %i1 + %i2 ], %o3
a00e2a30:  90 10 00 18  mov  %i0, %o0
a00e2a34:  d2 03 c0 1a  ld  [ %o7 + %i2 ], %o1
a00e2a38:  d4 03 40 1a  ld  [ %o5 + %i2 ], %o2
a00e2a3c:  7f ff f7 4e  call  0xa00e0774
a00e2a40:  98 10 00 1b  mov  %i3, %o4
a00e2a44:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00e2a48:  3b 2a 00 97  sethi  %hi(0xa8025c00), %i5
a00e2a4c:  82 12 e1 80  or  %o3, 0x180, %g1
a00e2a50:  a2 17 62 80  or  %i5, 0x280, %l1
a00e2a54:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a00e2a58:  f6 00 40 1a  ld  [ %g1 + %i2 ], %i3
a00e2a5c:  f2 04 40 1a  ld  [ %l1 + %i2 ], %i1
a00e2a60:  90 14 22 58  or  %l0, 0x258, %o0
a00e2a64:  f4 02 00 1a  ld  [ %o0 + %i2 ], %i2
a00e2a68:  7f ff f7 43  call  0xa00e0774
a00e2a6c:  81 e8 00 00  restore
a00e2a70:  7f ff f3 67  call  0xa00df80c
a00e2a74:  01 00 00 00  nop
a00e2a78:  7f ff f8 52  call  0xa00e0bc0
a00e2a7c:  01 00 00 00  nop
a00e2a80:  03 00 06 65  sethi  %hi(0x199400), %g1
a00e2a84:  7f ff f1 bb  call  0xa00df170
a00e2a88:  91 e8 63 68  restore  %g1, 0x368, %o0
a00e2a8c:  7f ff f3 60  call  0xa00df80c
a00e2a90:  31 00 06 65  sethi  %hi(0x199400), %i0
a00e2a94:  7f ff f8 4b  call  0xa00e0bc0
a00e2a98:  b0 16 23 88  or  %i0, 0x388, %i0	! 0x199788
a00e2a9c:  7f ff f1 b5  call  0xa00df170
a00e2aa0:  81 e8 00 00  restore
a00e2aa4:  7f ff f7 34  call  0xa00e0774
a00e2aa8:  33 2a 00 97  sethi  %hi(0xa8025c00), %i1
a00e2aac:  19 2a 00 97  sethi  %hi(0xa8025c00), %o4
a00e2ab0:  96 13 22 a8  or  %o4, 0x2a8, %o3	! 0xa8025ea8
a00e2ab4:  1f 2a 00 97  sethi  %hi(0xa8025c00), %o7
a00e2ab8:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a00e2abc:  98 10 00 1b  mov  %i3, %o4
a00e2ac0:  90 10 00 18  mov  %i0, %o0
a00e2ac4:  92 13 e2 f8  or  %o7, 0x2f8, %o1
a00e2ac8:  94 13 62 d0  or  %o5, 0x2d0, %o2
a00e2acc:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a00e2ad0:  7f ff f7 29  call  0xa00e0774
a00e2ad4:  37 2a 00 ad  sethi  %hi(0xa802b400), %i3
a00e2ad8:  b2 16 62 80  or  %i1, 0x280, %i1
a00e2adc:  b4 16 a2 58  or  %i2, 0x258, %i2
a00e2ae0:  7f ff f7 25  call  0xa00e0774
a00e2ae4:  97 ee e1 80  restore  %i3, 0x180, %o3
a00e2ae8:  01 00 00 00  nop
