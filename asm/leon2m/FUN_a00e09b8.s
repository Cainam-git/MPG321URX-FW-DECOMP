# leon2m FUN_a00e09b8 0xa00e09b8-0xa00e0b00 (328 bytes)
a00e09b8:  9d e3 bf 98  save  %sp, -104, %sp
a00e09bc:  b8 0f 20 ff  and  %i4, 0xff, %i4
a00e09c0:  93 2e e0 10  sll  %i3, 0x10, %o1
a00e09c4:  90 0e a0 ff  and  %i2, 0xff, %o0
a00e09c8:  93 32 60 10  srl  %o1, 0x10, %o1
a00e09cc:  7f ff fe d2  call  0xa00e0514
a00e09d0:  94 10 00 1c  mov  %i4, %o2
a00e09d4:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00e09d8:  b4 10 00 08  mov  %o0, %i2
a00e09dc:  80 a6 40 1c  cmp  %i1, %i4
a00e09e0:  02 80 00 25  be  0xa00e0a74
a00e09e4:  b6 10 00 18  mov  %i0, %i3
a00e09e8:  80 a6 40 1c  cmp  %i1, %i4
a00e09ec:  9a 10 20 01  mov  1, %o5
a00e09f0:  08 80 00 12  bleu  0xa00e0a38
a00e09f4:  98 10 20 01  mov  1, %o4
a00e09f8:  83 2f 00 0c  sll  %i4, %o4, %g1
a00e09fc:  80 a6 40 01  cmp  %i1, %g1
a00e0a00:  02 80 00 06  be  0xa00e0a18
a00e0a04:  9a 03 60 01  inc  %o5
a00e0a08:  98 0b 60 ff  and  %o5, 0xff, %o4
a00e0a0c:  80 a3 20 07  cmp  %o4, 7
a00e0a10:  08 bf ff fb  bleu  0xa00e09fc
a00e0a14:  83 2f 00 0c  sll  %i4, %o4, %g1
a00e0a18:  80 a3 20 08  cmp  %o4, 8
a00e0a1c:  02 80 00 29  be  0xa00e0ac0
a00e0a20:  01 00 00 00  nop
a00e0a24:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00e0a28:  b5 2e 80 0c  sll  %i2, %o4, %i2
a00e0a2c:  b0 10 00 1b  mov  %i3, %i0
a00e0a30:  7f ff fa bb  call  0xa00df51c
a00e0a34:  81 e8 00 00  restore
a00e0a38:  9f 3f 00 0c  sra  %i4, %o4, %o7
a00e0a3c:  80 a6 40 0f  cmp  %i1, %o7
a00e0a40:  02 80 00 06  be  0xa00e0a58
a00e0a44:  9a 03 60 01  inc  %o5
a00e0a48:  98 0b 60 ff  and  %o5, 0xff, %o4
a00e0a4c:  80 a3 20 07  cmp  %o4, 7
a00e0a50:  08 bf ff fb  bleu  0xa00e0a3c
a00e0a54:  9f 3f 00 0c  sra  %i4, %o4, %o7
a00e0a58:  80 a3 20 08  cmp  %o4, 8
a00e0a5c:  02 80 00 09  be  0xa00e0a80
a00e0a60:  01 00 00 00  nop
a00e0a64:  b8 0e a0 ff  and  %i2, 0xff, %i4
a00e0a68:  b5 3f 00 0c  sra  %i4, %o4, %i2
a00e0a6c:  10 bf ff f1  b  0xa00e0a30
a00e0a70:  b0 10 00 1b  mov  %i3, %i0
a00e0a74:  b4 0a 20 ff  and  %o0, 0xff, %i2
a00e0a78:  7f ff fa a9  call  0xa00df51c
a00e0a7c:  81 e8 00 00  restore
a00e0a80:  7f ff fb 63  call  0xa00df80c
a00e0a84:  31 00 06 65  sethi  %hi(0x199400), %i0
a00e0a88:  40 00 00 4e  call  0xa00e0bc0
a00e0a8c:  01 00 00 00  nop
a00e0a90:  19 00 06 65  sethi  %hi(0x199400), %o4
a00e0a94:  1b 00 06 65  sethi  %hi(0x199400), %o5
a00e0a98:  96 13 21 a0  or  %o4, 0x1a0, %o3
a00e0a9c:  98 10 00 1c  mov  %i4, %o4
a00e0aa0:  90 16 21 68  or  %i0, 0x168, %o0
a00e0aa4:  92 13 61 b0  or  %o5, 0x1b0, %o1
a00e0aa8:  7f ff f9 b2  call  0xa00df170
a00e0aac:  94 10 00 19  mov  %i1, %o2
a00e0ab0:  98 10 20 00  clr  %o4
a00e0ab4:  b8 0e a0 ff  and  %i2, 0xff, %i4
a00e0ab8:  10 bf ff ed  b  0xa00e0a6c
a00e0abc:  b5 3f 00 0c  sra  %i4, %o4, %i2
a00e0ac0:  7f ff fb 53  call  0xa00df80c
a00e0ac4:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00e0ac8:  40 00 00 3e  call  0xa00e0bc0
a00e0acc:  b0 10 00 1b  mov  %i3, %i0
a00e0ad0:  15 00 06 65  sethi  %hi(0x199400), %o2
a00e0ad4:  92 12 a1 b0  or  %o2, 0x1b0, %o1	! 0x1995b0
a00e0ad8:  11 00 06 65  sethi  %hi(0x199400), %o0
a00e0adc:  17 00 06 65  sethi  %hi(0x199400), %o3
a00e0ae0:  98 10 00 1c  mov  %i4, %o4
a00e0ae4:  90 12 21 68  or  %o0, 0x168, %o0
a00e0ae8:  96 12 e1 a8  or  %o3, 0x1a8, %o3
a00e0aec:  7f ff f9 a1  call  0xa00df170
a00e0af0:  94 10 00 19  mov  %i1, %o2
a00e0af4:  98 10 20 00  clr  %o4
a00e0af8:  10 bf ff ce  b  0xa00e0a30
a00e0afc:  b5 2e 80 0c  sll  %i2, %o4, %i2
