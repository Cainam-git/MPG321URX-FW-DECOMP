# leon2m FUN_a0146e2c 0xa0146e2c-0xa0146ef4 (200 bytes)
a0146e2c:  9d e3 bf 98  save  %sp, -104, %sp
a0146e30:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0146e34:  80 a6 20 01  cmp  %i0, 1
a0146e38:  02 80 00 0b  be  0xa0146e64
a0146e3c:  82 10 20 01  mov  1, %g1
a0146e40:  80 a6 20 01  cmp  %i0, 1
a0146e44:  04 80 00 25  ble  0xa0146ed8
a0146e48:  80 a6 20 02  cmp  %i0, 2
a0146e4c:  02 80 00 06  be  0xa0146e64
a0146e50:  82 10 20 02  mov  2, %g1
a0146e54:  80 a6 20 03  cmp  %i0, 3
a0146e58:  02 80 00 03  be  0xa0146e64
a0146e5c:  82 10 20 03  mov  3, %g1
a0146e60:  82 10 3f ff  mov  -1, %g1
a0146e64:  9a 08 60 ff  and  %g1, 0xff, %o5
a0146e68:  80 a3 60 03  cmp  %o5, 3
a0146e6c:  18 80 00 17  bgu  0xa0146ec8
a0146e70:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a0146e74:  9f 2b 60 04  sll  %o5, 4, %o7
a0146e78:  96 23 c0 0d  sub  %o7, %o5, %o3
a0146e7c:  15 2a 00 b7  sethi  %hi(0xa802dc00), %o2
a0146e80:  83 2a e0 03  sll  %o3, 3, %g1
a0146e84:  9a 12 a3 30  or  %o2, 0x330, %o5
a0146e88:  d2 03 40 01  ld  [ %o5 + %g1 ], %o1
a0146e8c:  99 32 60 04  srl  %o1, 4, %o4
a0146e90:  90 0b 20 0f  and  %o4, 0xf, %o0
a0146e94:  80 a2 20 04  cmp  %o0, 4
a0146e98:  02 80 00 15  be  0xa0146eec
a0146e9c:  b1 2e 60 10  sll  %i1, 0x10, %i0
a0146ea0:  b3 2e a0 10  sll  %i2, 0x10, %i1
a0146ea4:  b5 2e e0 10  sll  %i3, 0x10, %i2
a0146ea8:  7f fe bd 45  call  0xa00f63bc
a0146eac:  b7 2f 20 10  sll  %i4, 0x10, %i3
a0146eb0:  b1 36 20 10  srl  %i0, 0x10, %i0
a0146eb4:  b3 36 60 10  srl  %i1, 0x10, %i1
a0146eb8:  b5 36 a0 10  srl  %i2, 0x10, %i2
a0146ebc:  b7 36 e0 10  srl  %i3, 0x10, %i3
a0146ec0:  7f fe bf 90  call  0xa00f6d00
a0146ec4:  81 e8 00 00  restore
a0146ec8:  7f fe 60 aa  call  0xa00df170
a0146ecc:  90 12 21 d8  or  %o0, 0x1d8, %o0
a0146ed0:  10 bf ff e9  b  0xa0146e74
a0146ed4:  9a 10 20 00  clr  %o5
a0146ed8:  80 a6 20 00  cmp  %i0, 0
a0146edc:  02 bf ff e2  be  0xa0146e64
a0146ee0:  82 10 20 00  clr  %g1
a0146ee4:  10 bf ff e0  b  0xa0146e64
a0146ee8:  82 10 3f ff  mov  -1, %g1
a0146eec:  81 c7 e0 08  ret
a0146ef0:  81 e8 00 00  restore
