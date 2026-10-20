# leon2m FUN_a00b0f48 0xa00b0f48-0xa00b1004 (188 bytes)
a00b0f48:  9d e3 bf 98  save  %sp, -104, %sp
a00b0f4c:  7f ff 80 23  call  0xa0090fd8
a00b0f50:  b0 10 20 01  mov  1, %i0
a00b0f54:  67 ff 74 d4  call  0x4008e2a4
a00b0f58:  b2 10 20 00  clr  %i1
a00b0f5c:  67 ff 74 d2  call  0x4008e2a4
a00b0f60:  01 00 00 00  nop
a00b0f64:  67 ff 74 d0  call  0x4008e2a4
a00b0f68:  01 00 00 00  nop
a00b0f6c:  67 ff 74 ce  call  0x4008e2a4
a00b0f70:  01 00 00 00  nop
a00b0f74:  40 00 10 59  call  0xa00b50d8
a00b0f78:  90 10 20 03  mov  3, %o0	! 0x3
a00b0f7c:  90 10 20 28  mov  0x28, %o0
a00b0f80:  92 10 20 0b  mov  0xb, %o1
a00b0f84:  40 00 10 dd  call  0xa00b52f8
a00b0f88:  94 10 27 92  mov  0x792, %o2
a00b0f8c:  7f ff fe c1  call  0xa00b0a90
a00b0f90:  01 00 00 00  nop
a00b0f94:  90 10 20 32  mov  0x32, %o0	! 0x32
a00b0f98:  92 10 20 32  mov  0x32, %o1
a00b0f9c:  40 02 55 5f  call  0xa0146518
a00b0fa0:  94 10 20 00  clr  %o2
a00b0fa4:  7f ff fd 8d  call  0xa00b05d8
a00b0fa8:  01 00 00 00  nop
a00b0fac:  40 00 8d f5  call  0xa00d4780
a00b0fb0:  01 00 00 00  nop
a00b0fb4:  40 02 57 83  call  0xa0146dc0
a00b0fb8:  81 e8 00 00  restore
a00b0fbc:  01 00 00 00  nop
a00b0fc0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00b0fc4:  9a 12 62 90  or  %o1, 0x290, %o5	! 0xa802d290
a00b0fc8:  d8 0b 61 aa  ldub  [ %o5 + 0x1aa ], %o4
a00b0fcc:  90 10 20 01  mov  1, %o0
a00b0fd0:  82 22 00 0c  sub  %o0, %o4, %g1
a00b0fd4:  96 08 60 ff  and  %g1, 0xff, %o3
a00b0fd8:  90 10 20 00  clr  %o0
a00b0fdc:  92 10 20 01  mov  1, %o1
a00b0fe0:  80 a2 e0 01  cmp  %o3, 1
a00b0fe4:  02 80 00 04  be  0xa00b0ff4
a00b0fe8:  c2 2b 61 aa  stb  %g1, [ %o5 + 0x1aa ]
a00b0fec:  90 10 20 00  clr  %o0
a00b0ff0:  92 10 20 00  clr  %o1
a00b0ff4:  82 13 c0 00  mov  %o7, %g1
a00b0ff8:  7f ff fd c6  call  0xa00b0710
a00b0ffc:  9e 10 40 00  mov  %g1, %o7
a00b1000:  01 00 00 00  nop
