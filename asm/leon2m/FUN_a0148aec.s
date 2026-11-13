# leon2m FUN_a0148aec 0xa0148aec-0xa0148bc4 (216 bytes)
a0148aec:  9d e3 bf 98  save  %sp, -104, %sp
a0148af0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0148af4:  80 a6 20 01  cmp  %i0, 1
a0148af8:  02 80 00 0b  be  0xa0148b24
a0148afc:  9a 10 20 01  mov  1, %o5
a0148b00:  80 a6 20 01  cmp  %i0, 1
a0148b04:  04 80 00 2b  ble  0xa0148bb0
a0148b08:  80 a6 20 02  cmp  %i0, 2
a0148b0c:  02 80 00 06  be  0xa0148b24
a0148b10:  9a 10 20 02  mov  2, %o5
a0148b14:  80 a6 20 03  cmp  %i0, 3
a0148b18:  02 80 00 03  be  0xa0148b24
a0148b1c:  9a 10 20 03  mov  3, %o5
a0148b20:  9a 10 3f ff  mov  -1, %o5
a0148b24:  82 0b 60 ff  and  %o5, 0xff, %g1
a0148b28:  80 a0 60 03  cmp  %g1, 3
a0148b2c:  18 80 00 0f  bgu  0xa0148b68
a0148b30:  99 28 60 04  sll  %g1, 4, %o4
a0148b34:  96 23 00 01  sub  %o4, %g1, %o3
a0148b38:  15 2a 00 b7  sethi  %hi(0xa802dc00), %o2
a0148b3c:  9b 2a e0 03  sll  %o3, 3, %o5
a0148b40:  82 12 a3 30  or  %o2, 0x330, %g1
a0148b44:  d2 00 40 0d  ld  [ %g1 + %o5 ], %o1
a0148b48:  b1 32 60 0c  srl  %o1, 0xc, %i0
a0148b4c:  b3 2e 60 10  sll  %i1, 0x10, %i1
a0148b50:  b5 2e a0 10  sll  %i2, 0x10, %i2
a0148b54:  b0 0e 20 0f  and  %i0, 0xf, %i0
a0148b58:  b3 36 60 10  srl  %i1, 0x10, %i1
a0148b5c:  b5 36 a0 10  srl  %i2, 0x10, %i2
a0148b60:  7f fe c2 10  call  0xa00f93a0
a0148b64:  81 e8 00 00  restore
a0148b68:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a0148b6c:  7f fe 59 81  call  0xa00df170
a0148b70:  90 12 21 d8  or  %o0, 0x1d8, %o0	! 0x1a6dd8
a0148b74:  82 10 20 00  clr  %g1
a0148b78:  99 28 60 04  sll  %g1, 4, %o4
a0148b7c:  96 23 00 01  sub  %o4, %g1, %o3
a0148b80:  15 2a 00 b7  sethi  %hi(0xa802dc00), %o2
a0148b84:  9b 2a e0 03  sll  %o3, 3, %o5
a0148b88:  82 12 a3 30  or  %o2, 0x330, %g1
a0148b8c:  d2 00 40 0d  ld  [ %g1 + %o5 ], %o1
a0148b90:  b1 32 60 0c  srl  %o1, 0xc, %i0
a0148b94:  b3 2e 60 10  sll  %i1, 0x10, %i1
a0148b98:  b5 2e a0 10  sll  %i2, 0x10, %i2
a0148b9c:  b0 0e 20 0f  and  %i0, 0xf, %i0
a0148ba0:  b3 36 60 10  srl  %i1, 0x10, %i1
a0148ba4:  b5 36 a0 10  srl  %i2, 0x10, %i2
a0148ba8:  7f fe c1 fe  call  0xa00f93a0
a0148bac:  81 e8 00 00  restore
a0148bb0:  80 a6 20 00  cmp  %i0, 0
a0148bb4:  02 bf ff dc  be  0xa0148b24
a0148bb8:  9a 10 20 00  clr  %o5
a0148bbc:  10 bf ff da  b  0xa0148b24
a0148bc0:  9a 10 3f ff  mov  -1, %o5
