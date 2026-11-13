# leon2m FUN_a00c3e3c 0xa00c3e3c-0xa00c3ec8 (140 bytes)
a00c3e3c:  9d e3 bf 98  save  %sp, -104, %sp
a00c3e40:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c3e44:  80 a6 20 02  cmp  %i0, 2
a00c3e48:  02 80 00 18  be  0xa00c3ea8
a00c3e4c:  80 a6 20 03  cmp  %i0, 3
a00c3e50:  02 80 00 19  be  0xa00c3eb4
a00c3e54:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c3e58:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c3e5c:  94 08 60 ff  and  %g1, 0xff, %o2
a00c3e60:  98 02 bf d0  add  %o2, -48, %o4
a00c3e64:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00c3e68:  90 10 20 01  mov  1, %o0
a00c3e6c:  80 a3 60 02  cmp  %o5, 2
a00c3e70:  18 80 00 14  bgu  0xa00c3ec0
a00c3e74:  82 10 20 ff  mov  0xff, %g1
a00c3e78:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c3e7c:  40 00 48 0c  call  0xa00d5eac
a00c3e80:  d8 2a e2 dc  stb  %o4, [ %o3 + 0x2dc ]	! 0xa802d2dc
a00c3e84:  7f ff da fa  call  0xa00baa6c
a00c3e88:  90 10 00 18  mov  %i0, %o0
a00c3e8c:  7f ff da b1  call  0xa00ba950
a00c3e90:  90 10 00 18  mov  %i0, %o0
a00c3e94:  90 10 00 18  mov  %i0, %o0
a00c3e98:  7f ff db 3a  call  0xa00bab80
a00c3e9c:  92 10 20 06  mov  6, %o1
a00c3ea0:  10 80 00 08  b  0xa00c3ec0
a00c3ea4:  82 10 20 00  clr  %g1
a00c3ea8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c3eac:  10 bf ff ec  b  0xa00c3e5c
a00c3eb0:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c3eb4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c3eb8:  10 bf ff e9  b  0xa00c3e5c
a00c3ebc:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c3ec0:  81 c7 e0 08  ret
a00c3ec4:  91 e8 00 01  restore  %g0, %g1, %o0
