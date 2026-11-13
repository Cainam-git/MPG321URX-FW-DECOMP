# leon2m FUN_a0148bc4 0xa0148bc4-0xa0148c84 (192 bytes)
a0148bc4:  9d e3 bf 98  save  %sp, -104, %sp
a0148bc8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0148bcc:  80 a6 20 01  cmp  %i0, 1
a0148bd0:  02 80 00 0b  be  0xa0148bfc
a0148bd4:  82 10 20 01  mov  1, %g1
a0148bd8:  80 a6 20 01  cmp  %i0, 1
a0148bdc:  04 80 00 25  ble  0xa0148c70
a0148be0:  80 a6 20 02  cmp  %i0, 2
a0148be4:  02 80 00 06  be  0xa0148bfc
a0148be8:  82 10 20 02  mov  2, %g1
a0148bec:  80 a6 20 03  cmp  %i0, 3
a0148bf0:  02 80 00 03  be  0xa0148bfc
a0148bf4:  82 10 20 03  mov  3, %g1
a0148bf8:  82 10 3f ff  mov  -1, %g1
a0148bfc:  9a 08 60 ff  and  %g1, 0xff, %o5
a0148c00:  80 a3 60 03  cmp  %o5, 3
a0148c04:  18 80 00 0c  bgu  0xa0148c34
a0148c08:  99 2b 60 04  sll  %o5, 4, %o4
a0148c0c:  96 23 00 0d  sub  %o4, %o5, %o3
a0148c10:  15 2a 00 b7  sethi  %hi(0xa802dc00), %o2
a0148c14:  83 2a e0 03  sll  %o3, 3, %g1
a0148c18:  9a 12 a3 30  or  %o2, 0x330, %o5
a0148c1c:  d2 03 40 01  ld  [ %o5 + %g1 ], %o1
a0148c20:  b1 32 60 0c  srl  %o1, 0xc, %i0
a0148c24:  b0 0e 20 0f  and  %i0, 0xf, %i0
a0148c28:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0148c2c:  7f fe c2 3f  call  0xa00f9528
a0148c30:  81 e8 00 00  restore
a0148c34:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a0148c38:  7f fe 59 4e  call  0xa00df170
a0148c3c:  90 12 21 d8  or  %o0, 0x1d8, %o0	! 0x1a6dd8
a0148c40:  9a 10 20 00  clr  %o5
a0148c44:  99 2b 60 04  sll  %o5, 4, %o4
a0148c48:  96 23 00 0d  sub  %o4, %o5, %o3
a0148c4c:  15 2a 00 b7  sethi  %hi(0xa802dc00), %o2
a0148c50:  83 2a e0 03  sll  %o3, 3, %g1
a0148c54:  9a 12 a3 30  or  %o2, 0x330, %o5
a0148c58:  d2 03 40 01  ld  [ %o5 + %g1 ], %o1
a0148c5c:  b1 32 60 0c  srl  %o1, 0xc, %i0
a0148c60:  b0 0e 20 0f  and  %i0, 0xf, %i0
a0148c64:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0148c68:  7f fe c2 30  call  0xa00f9528
a0148c6c:  81 e8 00 00  restore
a0148c70:  80 a6 20 00  cmp  %i0, 0
a0148c74:  02 bf ff e2  be  0xa0148bfc
a0148c78:  82 10 20 00  clr  %g1
a0148c7c:  10 bf ff e0  b  0xa0148bfc
a0148c80:  82 10 3f ff  mov  -1, %g1
