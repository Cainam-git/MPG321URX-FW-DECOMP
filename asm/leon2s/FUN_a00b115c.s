# leon2s FUN_a00b115c 0xa00b115c-0xa00b1224 (200 bytes)  [FUN_a00b121c = unreachable ret/restore tail, merged]
a00b115c:  9d e3 bf 98  save  %sp, -104, %sp
a00b1160:  82 0e 60 ff  and  %i1, 0xff, %g1
a00b1164:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00b1168:  92 10 20 56  mov  0x56, %o1
a00b116c:  94 10 20 02  mov  2, %o2
a00b1170:  96 10 20 00  clr  %o3
a00b1174:  b2 10 20 57  mov  0x57, %i1
a00b1178:  b4 10 20 07  mov  7, %i2
a00b117c:  80 a0 60 01  cmp  %g1, 1
a00b1180:  02 80 00 14  be  0xa00b11d0
a00b1184:  90 10 00 10  mov  %l0, %o0
a00b1188:  80 a0 60 01  cmp  %g1, 1
a00b118c:  14 80 00 08  bg  0xa00b11ac
a00b1190:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00b1194:  b0 10 00 10  mov  %l0, %i0
a00b1198:  94 10 20 03  mov  3, %o2
a00b119c:  80 a0 60 00  cmp  %g1, 0
a00b11a0:  02 80 00 1a  be  0xa00b1208
a00b11a4:  b4 10 20 03  mov  3, %i2
a00b11a8:  30 80 00 1c  b,a   0xa00b1218
a00b11ac:  90 10 00 18  mov  %i0, %o0
a00b11b0:  92 10 20 56  mov  0x56, %o1
a00b11b4:  94 10 20 02  mov  2, %o2
a00b11b8:  96 10 20 01  mov  1, %o3
a00b11bc:  b2 10 20 57  mov  0x57, %i1
a00b11c0:  80 a0 60 02  cmp  %g1, 2
a00b11c4:  02 80 00 0b  be  0xa00b11f0
a00b11c8:  b4 10 20 03  mov  3, %i2
a00b11cc:  30 80 00 13  b,a   0xa00b1218
a00b11d0:  7f ff d6 b2  call  0xa00a6c98
a00b11d4:  b0 10 00 10  mov  %l0, %i0
a00b11d8:  90 10 00 10  mov  %l0, %o0
a00b11dc:  92 10 20 56  mov  0x56, %o1
a00b11e0:  94 10 20 01  mov  1, %o2
a00b11e4:  7f ff d6 ad  call  0xa00a6c98
a00b11e8:  96 10 20 01  mov  1, %o3
a00b11ec:  30 80 00 09  b,a   0xa00b1210
a00b11f0:  7f ff d6 aa  call  0xa00a6c98
a00b11f4:  01 00 00 00  nop
a00b11f8:  90 10 00 18  mov  %i0, %o0
a00b11fc:  92 10 20 56  mov  0x56, %o1
a00b1200:  94 10 20 01  mov  1, %o2
a00b1204:  96 10 20 00  clr  %o3
a00b1208:  7f ff d6 a4  call  0xa00a6c98
a00b120c:  01 00 00 00  nop
a00b1210:  7f ff d6 7c  call  0xa00a6c00
a00b1214:  81 e8 00 00  restore
a00b1218:  01 00 00 00  nop
a00b121c:  81 c7 e0 08  ret
a00b1220:  81 e8 00 00  restore
