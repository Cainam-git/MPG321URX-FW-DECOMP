# leon2m FUN_a00c1078 0xa00c1078-0xa00c1100 (136 bytes)
a00c1078:  9d e3 bf 98  save  %sp, -104, %sp
a00c107c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c1080:  80 a6 20 02  cmp  %i0, 2
a00c1084:  02 80 00 17  be  0xa00c10e0
a00c1088:  80 a6 20 03  cmp  %i0, 3
a00c108c:  02 80 00 18  be  0xa00c10ec
a00c1090:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c1094:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c1098:  94 08 60 ff  and  %g1, 0xff, %o2
a00c109c:  98 02 bf d0  add  %o2, -48, %o4
a00c10a0:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00c10a4:  80 a3 60 01  cmp  %o5, 1
a00c10a8:  18 80 00 14  bgu  0xa00c10f8
a00c10ac:  82 10 20 ff  mov  0xff, %g1
a00c10b0:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a00c10b4:  7f ff de 06  call  0xa00b88cc
a00c10b8:  d8 2a e0 7e  stb  %o4, [ %o3 + 0x7e ]	! 0xa802d47e
a00c10bc:  7f ff e6 6c  call  0xa00baa6c
a00c10c0:  90 10 00 18  mov  %i0, %o0
a00c10c4:  7f ff e6 23  call  0xa00ba950
a00c10c8:  90 10 00 18  mov  %i0, %o0
a00c10cc:  90 10 00 18  mov  %i0, %o0
a00c10d0:  7f ff e6 ac  call  0xa00bab80
a00c10d4:  92 10 20 06  mov  6, %o1
a00c10d8:  10 80 00 08  b  0xa00c10f8
a00c10dc:  82 10 20 00  clr  %g1
a00c10e0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c10e4:  10 bf ff ed  b  0xa00c1098
a00c10e8:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c10ec:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c10f0:  10 bf ff ea  b  0xa00c1098
a00c10f4:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c10f8:  81 c7 e0 08  ret
a00c10fc:  91 e8 00 01  restore  %g0, %g1, %o0
