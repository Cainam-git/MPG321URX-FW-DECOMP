# leon2m FUN_a0148e34 0xa0148e34-0xa0148eb4 (128 bytes)
a0148e34:  9d e3 bf 98  save  %sp, -104, %sp
a0148e38:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0148e3c:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a0148e40:  90 12 23 48  or  %o0, 0x348, %o0	! 0x1a6f48
a0148e44:  7f fe 58 cb  call  0xa00df170
a0148e48:  92 10 00 18  mov  %i0, %o1
a0148e4c:  80 a6 20 00  cmp  %i0, 0
a0148e50:  02 80 00 0f  be  0xa0148e8c
a0148e54:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a0148e58:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a0148e5c:  94 10 00 0c  mov  %o4, %o2
a0148e60:  96 10 00 0c  mov  %o4, %o3
a0148e64:  da 00 62 a4  ld  [ %g1 + 0x2a4 ], %o5
a0148e68:  d8 13 60 0a  lduh  [ %o5 + 0xa ], %o4
a0148e6c:  80 a3 2f ff  cmp  %o4, 0xfff
a0148e70:  18 80 00 0c  bgu  0xa0148ea0
a0148e74:  d0 02 a3 d0  ld  [ %o2 + 0x3d0 ], %o0
a0148e78:  d6 02 a3 d0  ld  [ %o2 + 0x3d0 ], %o3
a0148e7c:  1f 02 00 00  sethi  %hi(0x8000000), %o7
a0148e80:  92 12 c0 0f  or  %o3, %o7, %o1
a0148e84:  10 80 00 0a  b  0xa0148eac
a0148e88:  d2 22 a3 d0  st  %o1, [ %o2 + 0x3d0 ]
a0148e8c:  da 03 23 d0  ld  [ %o4 + 0x3d0 ], %o5
a0148e90:  13 02 00 00  sethi  %hi(0x8000000), %o1
a0148e94:  82 2b 40 09  andn  %o5, %o1, %g1
a0148e98:  10 80 00 05  b  0xa0148eac
a0148e9c:  c2 23 23 d0  st  %g1, [ %o4 + 0x3d0 ]
a0148ea0:  31 02 00 00  sethi  %hi(0x8000000), %i0
a0148ea4:  94 2a 00 18  andn  %o0, %i0, %o2
a0148ea8:  d4 22 e3 d0  st  %o2, [ %o3 + 0x3d0 ]
a0148eac:  81 c7 e0 08  ret
a0148eb0:  81 e8 00 00  restore
