# leon2m FUN_a00c3ec8 0xa00c3ec8-0xa00c3f54 (140 bytes)
a00c3ec8:  9d e3 bf 98  save  %sp, -104, %sp
a00c3ecc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c3ed0:  80 a6 20 02  cmp  %i0, 2
a00c3ed4:  02 80 00 18  be  0xa00c3f34
a00c3ed8:  80 a6 20 03  cmp  %i0, 3
a00c3edc:  02 80 00 19  be  0xa00c3f40
a00c3ee0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c3ee4:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c3ee8:  94 08 60 ff  and  %g1, 0xff, %o2
a00c3eec:  98 02 bf d0  add  %o2, -48, %o4
a00c3ef0:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00c3ef4:  90 10 20 01  mov  1, %o0
a00c3ef8:  80 a3 60 02  cmp  %o5, 2
a00c3efc:  18 80 00 14  bgu  0xa00c3f4c
a00c3f00:  82 10 20 ff  mov  0xff, %g1
a00c3f04:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c3f08:  40 00 47 e9  call  0xa00d5eac
a00c3f0c:  d8 2a e2 db  stb  %o4, [ %o3 + 0x2db ]	! 0xa802d2db
a00c3f10:  7f ff da d7  call  0xa00baa6c
a00c3f14:  90 10 00 18  mov  %i0, %o0
a00c3f18:  7f ff da 8e  call  0xa00ba950
a00c3f1c:  90 10 00 18  mov  %i0, %o0
a00c3f20:  90 10 00 18  mov  %i0, %o0
a00c3f24:  7f ff db 17  call  0xa00bab80
a00c3f28:  92 10 20 06  mov  6, %o1
a00c3f2c:  10 80 00 08  b  0xa00c3f4c
a00c3f30:  82 10 20 00  clr  %g1
a00c3f34:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c3f38:  10 bf ff ec  b  0xa00c3ee8
a00c3f3c:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c3f40:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c3f44:  10 bf ff e9  b  0xa00c3ee8
a00c3f48:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c3f4c:  81 c7 e0 08  ret
a00c3f50:  91 e8 00 01  restore  %g0, %g1, %o0
