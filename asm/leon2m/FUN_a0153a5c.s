# leon2m FUN_a0153a5c 0xa0153a5c-0xa0153b00 (164 bytes)
a0153a5c:  9d e3 bf 88  save  %sp, -120, %sp
a0153a60:  a2 07 bf e8  add  %fp, -24, %l1
a0153a64:  13 00 06 9d  sethi  %hi(0x1a7400), %o1
a0153a68:  92 12 61 e6  or  %o1, 0x1e6, %o1	! 0x1a75e6
a0153a6c:  90 10 00 11  mov  %l1, %o0
a0153a70:  7f ff a3 a8  call  0xa013c910
a0153a74:  94 10 20 10  mov  0x10, %o2
a0153a78:  a0 10 20 00  clr  %l0
a0153a7c:  99 2c 20 10  sll  %l0, 0x10, %o4
a0153a80:  97 33 20 0c  srl  %o4, 0xc, %o3
a0153a84:  94 02 e3 00  add  %o3, 0x300, %o2
a0153a88:  91 2a a0 10  sll  %o2, 0x10, %o0
a0153a8c:  93 32 20 10  srl  %o0, 0x10, %o1
a0153a90:  90 10 20 00  clr  %o0
a0153a94:  94 10 20 10  mov  0x10, %o2
a0153a98:  96 10 00 11  mov  %l1, %o3
a0153a9c:  7f ff b4 f6  call  0xa0140e74
a0153aa0:  98 10 20 00  clr  %o4
a0153aa4:  9a 04 20 01  add  %l0, 1, %o5
a0153aa8:  83 2b 60 10  sll  %o5, 0x10, %g1
a0153aac:  83 30 60 10  srl  %g1, 0x10, %g1
a0153ab0:  80 a0 60 1c  cmp  %g1, 0x1c
a0153ab4:  0a bf ff f2  bcs  0xa0153a7c
a0153ab8:  a0 10 00 0d  mov  %o5, %l0
a0153abc:  93 28 60 04  sll  %g1, 4, %o1
a0153ac0:  9a 10 21 c0  mov  0x1c0, %o5
a0153ac4:  a0 23 40 09  sub  %o5, %o1, %l0
a0153ac8:  9f 2c 20 10  sll  %l0, 0x10, %o7
a0153acc:  95 33 e0 10  srl  %o7, 0x10, %o2
a0153ad0:  80 a2 a0 00  cmp  %o2, 0
a0153ad4:  02 80 00 08  be  0xa0153af4
a0153ad8:  82 02 63 00  add  %o1, 0x300, %g1
a0153adc:  93 28 60 10  sll  %g1, 0x10, %o1
a0153ae0:  93 32 60 10  srl  %o1, 0x10, %o1
a0153ae4:  96 10 00 11  mov  %l1, %o3
a0153ae8:  90 10 20 00  clr  %o0
a0153aec:  7f ff b4 e2  call  0xa0140e74
a0153af0:  98 10 20 00  clr  %o4
a0153af4:  01 00 00 00  nop
a0153af8:  81 c7 e0 08  ret
a0153afc:  81 e8 00 00  restore
