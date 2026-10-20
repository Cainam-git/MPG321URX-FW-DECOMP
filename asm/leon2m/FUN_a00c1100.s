# leon2m FUN_a00c1100 0xa00c1100-0xa00c1188 (136 bytes)
a00c1100:  9d e3 bf 98  save  %sp, -104, %sp
a00c1104:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c1108:  80 a6 20 02  cmp  %i0, 2
a00c110c:  02 80 00 17  be  0xa00c1168
a00c1110:  80 a6 20 03  cmp  %i0, 3
a00c1114:  02 80 00 18  be  0xa00c1174
a00c1118:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c111c:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c1120:  94 08 60 ff  and  %g1, 0xff, %o2
a00c1124:  98 02 bf d0  add  %o2, -48, %o4
a00c1128:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00c112c:  80 a3 60 02  cmp  %o5, 2
a00c1130:  18 80 00 14  bgu  0xa00c1180
a00c1134:  82 10 20 ff  mov  0xff, %g1
a00c1138:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a00c113c:  7f ff dd e4  call  0xa00b88cc
a00c1140:  d8 2a e0 0c  stb  %o4, [ %o3 + 0xc ]	! 0xa802d40c
a00c1144:  7f ff e6 4a  call  0xa00baa6c
a00c1148:  90 10 00 18  mov  %i0, %o0
a00c114c:  7f ff e6 01  call  0xa00ba950
a00c1150:  90 10 00 18  mov  %i0, %o0
a00c1154:  90 10 00 18  mov  %i0, %o0
a00c1158:  7f ff e6 8a  call  0xa00bab80
a00c115c:  92 10 20 06  mov  6, %o1
a00c1160:  10 80 00 08  b  0xa00c1180
a00c1164:  82 10 20 00  clr  %g1
a00c1168:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c116c:  10 bf ff ed  b  0xa00c1120
a00c1170:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c1174:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c1178:  10 bf ff ea  b  0xa00c1120
a00c117c:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c1180:  81 c7 e0 08  ret
a00c1184:  91 e8 00 01  restore  %g0, %g1, %o0
