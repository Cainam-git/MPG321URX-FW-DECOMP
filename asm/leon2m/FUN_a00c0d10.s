# leon2m FUN_a00c0d10 0xa00c0d10-0xa00c0db4 (164 bytes)
a00c0d10:  9d e3 bf 98  save  %sp, -104, %sp
a00c0d14:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c0d18:  80 a4 20 02  cmp  %l0, 2
a00c0d1c:  02 80 00 1e  be  0xa00c0d94
a00c0d20:  80 a4 20 03  cmp  %l0, 3
a00c0d24:  02 80 00 1f  be  0xa00c0da0
a00c0d28:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c0d2c:  da 0a 60 d9  ldub  [ %o1 + 0xd9 ], %o5	! 0xa802d0d9
a00c0d30:  9e 0b 60 ff  and  %o5, 0xff, %o7
a00c0d34:  98 03 ff d0  add  %o7, -48, %o4
a00c0d38:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00c0d3c:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c0d40:  96 16 22 90  or  %i0, 0x290, %o3	! 0xa802d290
a00c0d44:  94 0b 60 01  and  %o5, 1, %o2
a00c0d48:  99 2a a0 0c  sll  %o2, 0xc, %o4
a00c0d4c:  80 a3 60 01  cmp  %o5, 1
a00c0d50:  18 80 00 17  bgu  0xa00c0dac
a00c0d54:  b0 10 20 ff  mov  0xff, %i0
a00c0d58:  da 02 e0 a8  ld  [ %o3 + 0xa8 ], %o5
a00c0d5c:  13 00 00 04  sethi  %hi(0x1000), %o1
a00c0d60:  90 2b 40 09  andn  %o5, %o1, %o0
a00c0d64:  82 12 00 0c  or  %o0, %o4, %g1
a00c0d68:  7f ff 40 9c  call  0xa0090fd8
a00c0d6c:  c2 22 e0 a8  st  %g1, [ %o3 + 0xa8 ]
a00c0d70:  7f ff e7 3f  call  0xa00baa6c
a00c0d74:  90 10 00 10  mov  %l0, %o0
a00c0d78:  7f ff e6 f6  call  0xa00ba950
a00c0d7c:  90 10 00 10  mov  %l0, %o0
a00c0d80:  90 10 00 10  mov  %l0, %o0
a00c0d84:  7f ff e7 7f  call  0xa00bab80
a00c0d88:  92 10 20 06  mov  6, %o1
a00c0d8c:  10 80 00 08  b  0xa00c0dac
a00c0d90:  b0 10 20 00  clr  %i0
a00c0d94:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c0d98:  10 bf ff e6  b  0xa00c0d30
a00c0d9c:  da 08 60 49  ldub  [ %g1 + 0x49 ], %o5	! 0xa802d049
a00c0da0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c0da4:  10 bf ff e3  b  0xa00c0d30
a00c0da8:  da 0a 20 a1  ldub  [ %o0 + 0xa1 ], %o5	! 0xa802d0a1
a00c0dac:  81 c7 e0 08  ret
a00c0db0:  81 e8 00 00  restore
