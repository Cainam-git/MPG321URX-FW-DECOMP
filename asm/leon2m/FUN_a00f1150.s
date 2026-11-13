# leon2m FUN_a00f1150 0xa00f1150-0xa00f11ac (92 bytes)
a00f1150:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f1154:  80 a2 20 02  cmp  %o0, 2
a00f1158:  02 80 00 0a  be  0xa00f1180
a00f115c:  80 a2 20 03  cmp  %o0, 3
a00f1160:  02 80 00 0d  be  0xa00f1194
a00f1164:  80 a2 20 06  cmp  %o0, 6
a00f1168:  02 80 00 06  be  0xa00f1180
a00f116c:  80 a2 20 07  cmp  %o0, 7
a00f1170:  12 80 00 0d  bne  0xa00f11a4
a00f1174:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00f1178:  10 80 00 09  b  0xa00f119c
a00f117c:  11 2a 00 ad  sethi  %hi(0xa802b400), %o0
a00f1180:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00f1184:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00f1188:  c0 28 63 46  clrb  [ %g1 + 0x346 ]
a00f118c:  10 80 00 06  b  0xa00f11a4
a00f1190:  c0 33 63 44  clrh  [ %o5 + 0x344 ]
a00f1194:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00f1198:  11 2a 00 ad  sethi  %hi(0xa802b400), %o0
a00f119c:  c0 2b 63 42  clrb  [ %o5 + 0x342 ]
a00f11a0:  c0 32 23 40  clrh  [ %o0 + 0x340 ]
a00f11a4:  81 c3 e0 08  retl
a00f11a8:  01 00 00 00  nop
