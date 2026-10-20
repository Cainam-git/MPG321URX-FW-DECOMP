# leon2m FUN_a008ac90 0xa008ac90-0xa008ad20 (144 bytes)  [FUN_a008ad18 = unreachable ret/restore tail, merged]
a008ac90:  9d e3 bf 98  save  %sp, -104, %sp
a008ac94:  92 10 20 00  clr  %o1
a008ac98:  40 02 ef ae  call  0xa0146b50
a008ac9c:  90 10 20 d3  mov  0xd3, %o0
a008aca0:  40 02 eb 96  call  0xa0145af8
a008aca4:  90 10 20 02  mov  2, %o0
a008aca8:  91 2a 20 10  sll  %o0, 0x10, %o0
a008acac:  39 00 04 00  sethi  %hi(0x100000), %i4
a008acb0:  b8 17 22 a8  or  %i4, 0x2a8, %i4	! 0x1002a8
a008acb4:  b0 10 20 00  clr  %i0
a008acb8:  b4 10 20 14  mov  0x14, %i2
a008acbc:  b6 10 20 03  mov  3, %i3
a008acc0:  80 a2 20 00  cmp  %o0, 0
a008acc4:  02 80 00 09  be  0xa008ace8
a008acc8:  ba 10 20 00  clr  %i5
a008accc:  15 00 04 00  sethi  %hi(0x100000), %o2
a008acd0:  d2 0a a2 8a  ldub  [ %o2 + 0x28a ], %o1	! 0x10028a
a008acd4:  82 02 60 0b  add  %o1, 0xb, %g1
a008acd8:  b3 28 60 10  sll  %g1, 0x10, %i1
a008acdc:  b3 36 60 10  srl  %i1, 0x10, %i1
a008ace0:  40 00 61 31  call  0xa00a31a4
a008ace4:  81 e8 00 00  restore
a008ace8:  31 00 04 00  sethi  %hi(0x100000), %i0
a008acec:  de 0e 22 8a  ldub  [ %i0 + 0x28a ], %o7	! 0x10028a
a008acf0:  9a 03 e0 0b  add  %o7, 0xb, %o5
a008acf4:  99 2b 60 10  sll  %o5, 0x10, %o4
a008acf8:  17 00 04 00  sethi  %hi(0x100000), %o3
a008acfc:  b3 33 20 10  srl  %o4, 0x10, %i1
a008ad00:  b8 12 e2 a0  or  %o3, 0x2a0, %i4
a008ad04:  b0 10 20 00  clr  %i0
a008ad08:  b4 10 20 14  mov  0x14, %i2
a008ad0c:  40 00 61 26  call  0xa00a31a4
a008ad10:  97 e8 20 03  restore  %g0, 3, %o3
a008ad14:  01 00 00 00  nop
a008ad18:  81 c7 e0 08  ret
a008ad1c:  81 e8 00 00  restore
