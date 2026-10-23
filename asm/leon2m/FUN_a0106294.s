# leon2m FUN_a0106294 0xa0106294-0xa01062c0 (44 bytes)
a0106294:  90 0a 20 ff  and  %o0, 0xff, %o0
a0106298:  80 a2 20 01  cmp  %o0, 1
a010629c:  02 80 00 04  be  0xa01062ac
a01062a0:  11 33 c0 3b  sethi  %hi(0xcf00ec00), %o0
a01062a4:  c0 22 00 00  clr  [ %o0 ]
a01062a8:  30 80 00 04  b,a   0xa01062b8
a01062ac:  9a 10 20 09  mov  9, %o5
a01062b0:  03 33 c0 3b  sethi  %hi(0xcf00ec00), %g1
a01062b4:  da 20 40 00  st  %o5, [ %g1 ]
a01062b8:  81 c3 e0 08  retl
a01062bc:  01 00 00 00  nop
