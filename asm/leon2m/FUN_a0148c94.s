# leon2m FUN_a0148c94 0xa0148c94-0xa0148d34 (160 bytes)
a0148c94:  9d e3 bf 98  save  %sp, -104, %sp
a0148c98:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0148c9c:  80 a6 20 01  cmp  %i0, 1
a0148ca0:  02 80 00 0b  be  0xa0148ccc
a0148ca4:  82 10 20 01  mov  1, %g1
a0148ca8:  80 a6 20 01  cmp  %i0, 1
a0148cac:  04 80 00 11  ble  0xa0148cf0
a0148cb0:  80 a6 20 02  cmp  %i0, 2
a0148cb4:  02 80 00 06  be  0xa0148ccc
a0148cb8:  82 10 20 02  mov  2, %g1
a0148cbc:  80 a6 20 03  cmp  %i0, 3
a0148cc0:  02 80 00 03  be  0xa0148ccc
a0148cc4:  82 10 20 03  mov  3, %g1
a0148cc8:  82 10 3f ff  mov  -1, %g1
a0148ccc:  9a 08 60 ff  and  %g1, 0xff, %o5
a0148cd0:  80 a3 60 03  cmp  %o5, 3
a0148cd4:  08 80 00 0d  bleu  0xa0148d08
a0148cd8:  9f 2b 60 04  sll  %o5, 4, %o7
a0148cdc:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a0148ce0:  7f fe 59 24  call  0xa00df170
a0148ce4:  90 12 21 d8  or  %o0, 0x1d8, %o0	! 0x1a6dd8
a0148ce8:  10 80 00 07  b  0xa0148d04
a0148cec:  9a 10 20 00  clr  %o5
a0148cf0:  80 a6 20 00  cmp  %i0, 0
a0148cf4:  02 bf ff f6  be  0xa0148ccc
a0148cf8:  82 10 20 00  clr  %g1
a0148cfc:  10 bf ff f4  b  0xa0148ccc
a0148d00:  82 10 3f ff  mov  -1, %g1
a0148d04:  9f 2b 60 04  sll  %o5, 4, %o7
a0148d08:  98 23 c0 0d  sub  %o7, %o5, %o4
a0148d0c:  17 2a 00 b7  sethi  %hi(0xa802dc00), %o3
a0148d10:  95 2b 20 03  sll  %o4, 3, %o2
a0148d14:  9a 12 e3 30  or  %o3, 0x330, %o5
a0148d18:  d2 03 40 0a  ld  [ %o5 + %o2 ], %o1
a0148d1c:  83 32 60 0c  srl  %o1, 0xc, %g1
a0148d20:  7f ff 61 4e  call  0xa0121258
a0148d24:  90 08 60 0f  and  %g1, 0xf, %o0
a0148d28:  b0 0a 20 ff  and  %o0, 0xff, %i0
a0148d2c:  81 c7 e0 08  ret
a0148d30:  81 e8 00 00  restore
