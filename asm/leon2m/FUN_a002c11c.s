# leon2m FUN_a002c11c 0xa002c11c-0xa002c194 (120 bytes)
a002c11c:  90 0a 20 ff  and  %o0, 0xff, %o0
a002c120:  80 a2 20 02  cmp  %o0, 2
a002c124:  02 80 00 10  be  0xa002c164
a002c128:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a002c12c:  14 80 00 06  bg  0xa002c144
a002c130:  80 a2 20 03  cmp  %o0, 3
a002c134:  80 a2 20 01  cmp  %o0, 1
a002c138:  12 80 00 15  bne  0xa002c18c
a002c13c:  9a 0a 60 ff  and  %o1, 0xff, %o5
a002c140:  30 80 00 12  b,a   0xa002c188
a002c144:  02 80 00 0c  be  0xa002c174
a002c148:  80 a2 20 04  cmp  %o0, 4
a002c14c:  12 80 00 10  bne  0xa002c18c
a002c150:  9a 0a 60 ff  and  %o1, 0xff, %o5
a002c154:  13 33 c0 f2  sethi  %hi(0xcf03c800), %o1
a002c158:  82 12 60 0c  or  %o1, 0xc, %g1	! 0xcf03c80c
a002c15c:  da 20 40 00  st  %o5, [ %g1 ]
a002c160:  30 80 00 0b  b,a   0xa002c18c
a002c164:  9a 0a 60 ff  and  %o1, 0xff, %o5
a002c168:  82 10 60 04  or  %g1, 4, %g1
a002c16c:  da 20 40 00  st  %o5, [ %g1 ]
a002c170:  30 80 00 07  b,a   0xa002c18c
a002c174:  11 33 c0 f2  sethi  %hi(0xcf03c800), %o0
a002c178:  9a 0a 60 ff  and  %o1, 0xff, %o5
a002c17c:  82 12 20 08  or  %o0, 8, %g1
a002c180:  da 20 40 00  st  %o5, [ %g1 ]
a002c184:  30 80 00 02  b,a   0xa002c18c
a002c188:  da 20 40 00  st  %o5, [ %g1 ]
a002c18c:  81 c3 e0 08  retl
a002c190:  01 00 00 00  nop
