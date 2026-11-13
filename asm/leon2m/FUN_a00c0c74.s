# leon2m FUN_a00c0c74 0xa00c0c74-0xa00c0cf8 (132 bytes)
a00c0c74:  9d e3 bf 98  save  %sp, -104, %sp
a00c0c78:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0c7c:  80 a6 20 02  cmp  %i0, 2
a00c0c80:  02 80 00 16  be  0xa00c0cd8
a00c0c84:  80 a6 20 03  cmp  %i0, 3
a00c0c88:  02 80 00 17  be  0xa00c0ce4
a00c0c8c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c0c90:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c0c94:  94 08 60 ff  and  %g1, 0xff, %o2
a00c0c98:  98 02 bf d0  add  %o2, -48, %o4
a00c0c9c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00c0ca0:  90 10 00 18  mov  %i0, %o0
a00c0ca4:  80 a3 60 04  cmp  %o5, 4
a00c0ca8:  18 80 00 12  bgu  0xa00c0cf0
a00c0cac:  82 10 20 ff  mov  0xff, %g1
a00c0cb0:  17 2a 00 b3  sethi  %hi(0xa802cc00), %o3
a00c0cb4:  7f ff e7 6e  call  0xa00baa6c
a00c0cb8:  d8 2a e3 fd  stb  %o4, [ %o3 + 0x3fd ]	! 0xa802cffd
a00c0cbc:  7f ff e7 25  call  0xa00ba950
a00c0cc0:  90 10 00 18  mov  %i0, %o0
a00c0cc4:  90 10 00 18  mov  %i0, %o0
a00c0cc8:  7f ff e7 ae  call  0xa00bab80
a00c0ccc:  92 10 20 06  mov  6, %o1
a00c0cd0:  10 80 00 08  b  0xa00c0cf0
a00c0cd4:  82 10 20 00  clr  %g1
a00c0cd8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c0cdc:  10 bf ff ee  b  0xa00c0c94
a00c0ce0:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c0ce4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c0ce8:  10 bf ff eb  b  0xa00c0c94
a00c0cec:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c0cf0:  81 c7 e0 08  ret
a00c0cf4:  91 e8 00 01  restore  %g0, %g1, %o0
