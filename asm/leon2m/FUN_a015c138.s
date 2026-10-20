# leon2m FUN_a015c138 0xa015c138-0xa015c1a8 (112 bytes)
a015c138:  9d e3 bf 98  save  %sp, -104, %sp
a015c13c:  21 00 06 a0  sethi  %hi(0x1a8000), %l0
a015c140:  92 14 23 e0  or  %l0, 0x3e0, %o1	! 0x1a83e0
a015c144:  90 10 00 1a  mov  %i2, %o0
a015c148:  80 a6 a0 00  cmp  %i2, 0
a015c14c:  02 80 00 0b  be  0xa015c178
a015c150:  a2 10 00 18  mov  %i0, %l1
a015c154:  40 00 07 c9  call  0xa015e078
a015c158:  01 00 00 00  nop
a015c15c:  13 00 03 fd  sethi  %hi(0xff400), %o1
a015c160:  80 a2 20 00  cmp  %o0, 0
a015c164:  92 12 61 e0  or  %o1, 0x1e0, %o1
a015c168:  12 80 00 06  bne  0xa015c180
a015c16c:  90 10 00 1a  mov  %i2, %o0
a015c170:  f4 24 60 34  st  %i2, [ %l1 + 0x34 ]
a015c174:  f2 24 60 30  st  %i1, [ %l1 + 0x30 ]
a015c178:  10 80 00 0a  b  0xa015c1a0
a015c17c:  b0 14 23 e0  or  %l0, 0x3e0, %i0
a015c180:  40 00 07 be  call  0xa015e078
a015c184:  b0 10 20 00  clr  %i0
a015c188:  80 a2 20 00  cmp  %o0, 0
a015c18c:  12 80 00 05  bne  0xa015c1a0
a015c190:  01 00 00 00  nop
a015c194:  f4 24 60 34  st  %i2, [ %l1 + 0x34 ]
a015c198:  10 bf ff f8  b  0xa015c178
a015c19c:  f2 24 60 30  st  %i1, [ %l1 + 0x30 ]
a015c1a0:  81 c7 e0 08  ret
a015c1a4:  81 e8 00 00  restore
