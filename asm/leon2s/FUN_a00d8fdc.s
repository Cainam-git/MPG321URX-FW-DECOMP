# leon2s FUN_a00d8fdc 0xa00d8fdc-0xa00d904c (112 bytes)
a00d8fdc:  9d e3 bf 88  save  %sp, -120, %sp
a00d8fe0:  90 07 bf f0  add  %fp, -16, %o0
a00d8fe4:  92 10 20 00  clr  %o1
a00d8fe8:  94 10 20 01  mov  1, %o2
a00d8fec:  96 10 20 1b  mov  0x1b, %o3
a00d8ff0:  c0 37 bf f0  clrh  [ %fp + -16 ]
a00d8ff4:  7f ff f8 f0  call  0xa00d73b4
a00d8ff8:  c0 37 bf e8  clrh  [ %fp + -24 ]
a00d8ffc:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a00d9000:  19 1f c0 00  sethi  %hi(0x7f000000), %o4
a00d9004:  98 28 40 0c  andn  %g1, %o4, %o4
a00d9008:  03 09 00 00  sethi  %hi(0x24000000), %g1
a00d900c:  98 13 00 01  or  %o4, %g1, %o4
a00d9010:  03 00 3c 00  sethi  %hi(0xf00000), %g1
a00d9014:  da 07 bf f0  ld  [ %fp + -16 ], %o5
a00d9018:  9a 0b 40 01  and  %o5, %g1, %o5
a00d901c:  82 2b 00 01  andn  %o4, %g1, %g1
a00d9020:  82 10 40 0d  or  %g1, %o5, %g1
a00d9024:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a00d9028:  90 07 bf e8  add  %fp, -24, %o0
a00d902c:  92 10 20 02  mov  2, %o1
a00d9030:  94 10 20 01  mov  1, %o2
a00d9034:  96 10 20 0b  mov  0xb, %o3
a00d9038:  7f ff fa 39  call  0xa00d791c
a00d903c:  98 10 20 02  mov  2, %o4
a00d9040:  01 00 00 00  nop
a00d9044:  81 c7 e0 08  ret
a00d9048:  81 e8 00 00  restore
