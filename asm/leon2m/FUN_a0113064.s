# leon2m FUN_a0113064 0xa0113064-0xa0113138 (212 bytes)
a0113064:  9d e3 bf 98  save  %sp, -104, %sp
a0113068:  25 33 c0 46  sethi  %hi(0xcf011800), %l2
a011306c:  a6 14 a2 00  or  %l2, 0x200, %l3	! 0xcf011a00
a0113070:  c2 04 c0 00  ld  [ %l3 ], %g1
a0113074:  40 00 15 3a  call  0xa011855c
a0113078:  a0 10 00 01  mov  %g1, %l0
a011307c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0113080:  80 a6 20 ff  cmp  %i0, 0xff
a0113084:  02 80 00 0e  be  0xa01130bc
a0113088:  90 10 00 18  mov  %i0, %o0
a011308c:  67 fd ec ce  call  0x4008e3c4
a0113090:  92 10 20 01  mov  1, %o1
a0113094:  98 10 20 01  mov  1, %o4
a0113098:  83 2b 00 18  sll  %o4, %i0, %g1
a011309c:  d4 04 80 00  ld  [ %l2 ], %o2
a01130a0:  a8 38 00 01  xnor  %g0, %g1, %l4
a01130a4:  b0 0a 80 14  and  %o2, %l4, %i0
a01130a8:  f0 24 80 00  st  %i0, [ %l2 ]
a01130ac:  e2 04 c0 00  ld  [ %l3 ], %l1
a01130b0:  a0 0c 40 14  and  %l1, %l4, %l0
a01130b4:  e0 24 c0 00  st  %l0, [ %l3 ]
a01130b8:  30 80 00 1e  b,a   0xa0113130
a01130bc:  a8 10 00 12  mov  %l2, %l4
a01130c0:  a2 0c 20 ff  and  %l0, 0xff, %l1
a01130c4:  a4 10 00 13  mov  %l3, %l2
a01130c8:  a0 10 20 00  clr  %l0
a01130cc:  b0 10 20 00  clr  %i0
a01130d0:  10 80 00 06  b  0xa01130e8
a01130d4:  a6 10 20 01  mov  1, %l3
a01130d8:  b0 0c 20 ff  and  %l0, 0xff, %i0
a01130dc:  80 a6 20 04  cmp  %i0, 4
a01130e0:  18 80 00 14  bgu  0xa0113130
a01130e4:  01 00 00 00  nop
a01130e8:  95 3c 40 18  sra  %l1, %i0, %o2
a01130ec:  90 10 00 18  mov  %i0, %o0
a01130f0:  92 10 20 01  mov  1, %o1
a01130f4:  80 8a a0 01  btst  1, %o2
a01130f8:  02 bf ff f8  be  0xa01130d8
a01130fc:  a0 04 20 01  inc  %l0
a0113100:  67 fd ec b1  call  0x4008e3c4
a0113104:  01 00 00 00  nop
a0113108:  9f 2c c0 18  sll  %l3, %i0, %o7
a011310c:  d6 05 00 00  ld  [ %l4 ], %o3
a0113110:  92 38 00 0f  xnor  %g0, %o7, %o1
a0113114:  9a 0a c0 09  and  %o3, %o1, %o5
a0113118:  da 25 00 00  st  %o5, [ %l4 ]
a011311c:  d0 04 80 00  ld  [ %l2 ], %o0
a0113120:  98 0a 00 09  and  %o0, %o1, %o4
a0113124:  d8 24 80 00  st  %o4, [ %l2 ]
a0113128:  10 bf ff ed  b  0xa01130dc
a011312c:  b0 0c 20 ff  and  %l0, 0xff, %i0
a0113130:  81 c7 e0 08  ret
a0113134:  81 e8 00 00  restore
