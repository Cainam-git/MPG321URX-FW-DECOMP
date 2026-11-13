# leon2m FUN_a00a8a78 0xa00a8a78-0xa00a8ae0 (76 bytes)
a00a8a78:  9d e3 bf 98  save  %sp, -104, %sp
a00a8a7c:  7f ff a1 54  call  0xa0090fcc
a00a8a80:  01 00 00 00  nop
a00a8a84:  83 2a 20 10  sll  %o0, 0x10, %g1
a00a8a88:  91 30 60 10  srl  %g1, 0x10, %o0
a00a8a8c:  82 02 3f c1  add  %o0, -63, %g1
a00a8a90:  96 10 00 18  mov  %i0, %o3
a00a8a94:  80 a0 60 ba  cmp  %g1, 0xba
a00a8a98:  18 80 00 0f  bgu  0xa00a8ad4
a00a8a9c:  b0 10 20 00  clr  %i0
a00a8aa0:  15 00 01 0e  sethi  %hi(0x43800), %o2
a00a8aa4:  93 28 60 02  sll  %g1, 2, %o1
a00a8aa8:  9a 12 a0 78  or  %o2, 0x78, %o5
a00a8aac:  d8 03 40 09  ld  [ %o5 + %o1 ], %o4
a00a8ab0:  81 c3 00 00  jmp  %o4
a00a8ab4:  01 00 00 00  nop
a00a8ab8:  9e 0a e0 ff  and  %o3, 0xff, %o7
a00a8abc:  80 a3 e0 02  cmp  %o7, 2
a00a8ac0:  32 80 00 06  bne,a   0xa00a8ad8
a00a8ac4:  b0 0e 20 03  and  %i0, 3, %i0
a00a8ac8:  10 80 00 03  b  0xa00a8ad4
a00a8acc:  b0 10 20 01  mov  1, %i0
a00a8ad0:  b0 10 20 02  mov  2, %i0
a00a8ad4:  b0 0e 20 03  and  %i0, 3, %i0
a00a8ad8:  81 c7 e0 08  ret
a00a8adc:  81 e8 00 00  restore
