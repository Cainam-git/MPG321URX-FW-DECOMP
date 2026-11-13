# leon2m FUN_a00c0ff4 0xa00c0ff4-0xa00c1078 (132 bytes)
a00c0ff4:  9d e3 bf 98  save  %sp, -104, %sp
a00c0ff8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0ffc:  80 a6 20 02  cmp  %i0, 2
a00c1000:  02 80 00 16  be  0xa00c1058
a00c1004:  80 a6 20 03  cmp  %i0, 3
a00c1008:  02 80 00 17  be  0xa00c1064
a00c100c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c1010:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c1014:  98 08 60 ff  and  %g1, 0xff, %o4
a00c1018:  96 03 3f d0  add  %o4, -48, %o3
a00c101c:  94 0a e0 ff  and  %o3, 0xff, %o2
a00c1020:  80 a2 a0 01  cmp  %o2, 1
a00c1024:  18 80 00 13  bgu  0xa00c1070
a00c1028:  82 10 20 ff  mov  0xff, %g1
a00c102c:  7f ff de 28  call  0xa00b88cc
a00c1030:  01 00 00 00  nop
a00c1034:  7f ff e6 8e  call  0xa00baa6c
a00c1038:  90 10 00 18  mov  %i0, %o0
a00c103c:  7f ff e6 45  call  0xa00ba950
a00c1040:  90 10 00 18  mov  %i0, %o0
a00c1044:  90 10 00 18  mov  %i0, %o0
a00c1048:  7f ff e6 ce  call  0xa00bab80
a00c104c:  92 10 20 06  mov  6, %o1
a00c1050:  10 80 00 08  b  0xa00c1070
a00c1054:  82 10 20 00  clr  %g1
a00c1058:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c105c:  10 bf ff ee  b  0xa00c1014
a00c1060:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c1064:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c1068:  10 bf ff eb  b  0xa00c1014
a00c106c:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c1070:  81 c7 e0 08  ret
a00c1074:  91 e8 00 01  restore  %g0, %g1, %o0
