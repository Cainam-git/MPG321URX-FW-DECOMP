# leon2m FUN_a00c9e9c 0xa00c9e9c-0xa00c9f44 (168 bytes)
a00c9e9c:  9d e3 bf 98  save  %sp, -104, %sp
a00c9ea0:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c9ea4:  80 a4 20 02  cmp  %l0, 2
a00c9ea8:  02 80 00 1f  be  0xa00c9f24
a00c9eac:  80 a4 20 03  cmp  %l0, 3
a00c9eb0:  02 80 00 20  be  0xa00c9f30
a00c9eb4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c9eb8:  da 0a 60 d9  ldub  [ %o1 + 0xd9 ], %o5	! 0xa802d0d9
a00c9ebc:  9e 0b 60 ff  and  %o5, 0xff, %o7
a00c9ec0:  98 03 ff d0  add  %o7, -48, %o4
a00c9ec4:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00c9ec8:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c9ecc:  96 16 22 90  or  %i0, 0x290, %o3	! 0xa802d290
a00c9ed0:  94 0b 60 01  and  %o5, 1, %o2
a00c9ed4:  99 2a a0 0f  sll  %o2, 0xf, %o4
a00c9ed8:  80 a3 60 01  cmp  %o5, 1
a00c9edc:  18 80 00 18  bgu  0xa00c9f3c
a00c9ee0:  b0 10 20 ff  mov  0xff, %i0
a00c9ee4:  da 02 e1 74  ld  [ %o3 + 0x174 ], %o5
a00c9ee8:  13 00 00 20  sethi  %hi(0x8000), %o1
a00c9eec:  90 2b 40 09  andn  %o5, %o1, %o0
a00c9ef0:  82 12 00 0c  or  %o0, %o4, %g1
a00c9ef4:  40 00 45 e7  call  0xa00db690
a00c9ef8:  c2 22 e1 74  st  %g1, [ %o3 + 0x174 ]
a00c9efc:  7f ff ba 74  call  0xa00b88cc
a00c9f00:  b0 10 20 00  clr  %i0
a00c9f04:  7f ff c2 da  call  0xa00baa6c
a00c9f08:  90 10 00 10  mov  %l0, %o0
a00c9f0c:  7f ff c2 91  call  0xa00ba950
a00c9f10:  90 10 00 10  mov  %l0, %o0
a00c9f14:  90 10 00 10  mov  %l0, %o0
a00c9f18:  7f ff c3 1a  call  0xa00bab80
a00c9f1c:  92 10 20 06  mov  6, %o1
a00c9f20:  30 80 00 07  b,a   0xa00c9f3c
a00c9f24:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c9f28:  10 bf ff e5  b  0xa00c9ebc
a00c9f2c:  da 08 60 49  ldub  [ %g1 + 0x49 ], %o5	! 0xa802d049
a00c9f30:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c9f34:  10 bf ff e2  b  0xa00c9ebc
a00c9f38:  da 0a 20 a1  ldub  [ %o0 + 0xa1 ], %o5	! 0xa802d0a1
a00c9f3c:  81 c7 e0 08  ret
a00c9f40:  81 e8 00 00  restore
