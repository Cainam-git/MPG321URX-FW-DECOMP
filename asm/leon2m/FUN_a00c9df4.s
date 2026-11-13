# leon2m FUN_a00c9df4 0xa00c9df4-0xa00c9e9c (168 bytes)
a00c9df4:  9d e3 bf 98  save  %sp, -104, %sp
a00c9df8:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c9dfc:  80 a4 20 02  cmp  %l0, 2
a00c9e00:  02 80 00 1f  be  0xa00c9e7c
a00c9e04:  80 a4 20 03  cmp  %l0, 3
a00c9e08:  02 80 00 20  be  0xa00c9e88
a00c9e0c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c9e10:  da 0a 60 d9  ldub  [ %o1 + 0xd9 ], %o5	! 0xa802d0d9
a00c9e14:  9e 0b 60 ff  and  %o5, 0xff, %o7
a00c9e18:  96 03 ff d0  add  %o7, -48, %o3
a00c9e1c:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c9e20:  94 0a e0 ff  and  %o3, 0xff, %o2
a00c9e24:  98 16 22 90  or  %i0, 0x290, %o4
a00c9e28:  9a 0a a0 01  and  %o2, 1, %o5
a00c9e2c:  90 10 20 00  clr  %o0
a00c9e30:  9b 2b 60 07  sll  %o5, 7, %o5
a00c9e34:  80 a2 a0 01  cmp  %o2, 1
a00c9e38:  18 80 00 17  bgu  0xa00c9e94
a00c9e3c:  b0 10 20 ff  mov  0xff, %i0
a00c9e40:  d4 03 21 ec  ld  [ %o4 + 0x1ec ], %o2
a00c9e44:  92 0a bf 7f  and  %o2, -129, %o1
a00c9e48:  82 12 40 0d  or  %o1, %o5, %g1
a00c9e4c:  40 00 44 b8  call  0xa00db12c
a00c9e50:  c2 23 21 ec  st  %g1, [ %o4 + 0x1ec ]
a00c9e54:  7f ff ba 9e  call  0xa00b88cc
a00c9e58:  b0 10 20 00  clr  %i0
a00c9e5c:  7f ff c3 04  call  0xa00baa6c
a00c9e60:  90 10 00 10  mov  %l0, %o0
a00c9e64:  7f ff c2 bb  call  0xa00ba950
a00c9e68:  90 10 00 10  mov  %l0, %o0
a00c9e6c:  90 10 00 10  mov  %l0, %o0
a00c9e70:  7f ff c3 44  call  0xa00bab80
a00c9e74:  92 10 20 06  mov  6, %o1
a00c9e78:  30 80 00 07  b,a   0xa00c9e94
a00c9e7c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c9e80:  10 bf ff e5  b  0xa00c9e14
a00c9e84:  da 08 60 49  ldub  [ %g1 + 0x49 ], %o5	! 0xa802d049
a00c9e88:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c9e8c:  10 bf ff e2  b  0xa00c9e14
a00c9e90:  da 0a 20 a1  ldub  [ %o0 + 0xa1 ], %o5	! 0xa802d0a1
a00c9e94:  81 c7 e0 08  ret
a00c9e98:  81 e8 00 00  restore
