# leon2m FUN_a008ac00 0xa008ac00-0xa008ac90 (144 bytes)  [FUN_a008ac88 = unreachable ret/restore tail, merged]
a008ac00:  9d e3 bf 98  save  %sp, -104, %sp
a008ac04:  92 10 20 00  clr  %o1
a008ac08:  40 02 ef d2  call  0xa0146b50
a008ac0c:  90 10 20 f7  mov  0xf7, %o0
a008ac10:  40 02 eb ba  call  0xa0145af8
a008ac14:  90 10 20 10  mov  0x10, %o0
a008ac18:  91 2a 20 10  sll  %o0, 0x10, %o0
a008ac1c:  39 00 04 00  sethi  %hi(0x100000), %i4
a008ac20:  b8 17 22 a8  or  %i4, 0x2a8, %i4	! 0x1002a8
a008ac24:  b0 10 20 00  clr  %i0
a008ac28:  b4 10 20 13  mov  0x13, %i2
a008ac2c:  b6 10 20 03  mov  3, %i3
a008ac30:  80 a2 20 00  cmp  %o0, 0
a008ac34:  02 80 00 09  be  0xa008ac58
a008ac38:  ba 10 20 00  clr  %i5
a008ac3c:  15 00 04 00  sethi  %hi(0x100000), %o2
a008ac40:  d2 0a a2 87  ldub  [ %o2 + 0x287 ], %o1	! 0x100287
a008ac44:  82 02 60 0b  add  %o1, 0xb, %g1
a008ac48:  b3 28 60 10  sll  %g1, 0x10, %i1
a008ac4c:  b3 36 60 10  srl  %i1, 0x10, %i1
a008ac50:  40 00 61 55  call  0xa00a31a4
a008ac54:  81 e8 00 00  restore
a008ac58:  31 00 04 00  sethi  %hi(0x100000), %i0
a008ac5c:  de 0e 22 87  ldub  [ %i0 + 0x287 ], %o7	! 0x100287
a008ac60:  9a 03 e0 0b  add  %o7, 0xb, %o5
a008ac64:  99 2b 60 10  sll  %o5, 0x10, %o4
a008ac68:  17 00 04 00  sethi  %hi(0x100000), %o3
a008ac6c:  b3 33 20 10  srl  %o4, 0x10, %i1
a008ac70:  b8 12 e2 a0  or  %o3, 0x2a0, %i4
a008ac74:  b0 10 20 00  clr  %i0
a008ac78:  b4 10 20 13  mov  0x13, %i2
a008ac7c:  40 00 61 4a  call  0xa00a31a4
a008ac80:  97 e8 20 03  restore  %g0, 3, %o3
a008ac84:  01 00 00 00  nop
a008ac88:  81 c7 e0 08  ret
a008ac8c:  81 e8 00 00  restore
