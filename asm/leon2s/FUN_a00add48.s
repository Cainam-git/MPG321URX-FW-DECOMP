# leon2s FUN_a00add48 0xa00add48-0xa00add8c (68 bytes)
a00add48:  90 0a 20 ff  and  %o0, 0xff, %o0
a00add4c:  9b 2a 20 02  sll  %o0, 2, %o5
a00add50:  92 0a 60 ff  and  %o1, 0xff, %o1
a00add54:  80 a2 20 02  cmp  %o0, 2
a00add58:  98 03 40 09  add  %o5, %o1, %o4
a00add5c:  90 10 20 09  mov  9, %o0
a00add60:  02 80 00 09  be  0xa00add84
a00add64:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00add68:  90 10 63 68  or  %g1, 0x368, %o0	! 0xa8078768
a00add6c:  80 a3 20 04  cmp  %o4, 4
a00add70:  04 80 00 04  ble  0xa00add80
a00add74:  82 03 40 08  add  %o5, %o0, %g1
a00add78:  10 80 00 03  b  0xa00add84
a00add7c:  d0 0a 00 0d  ldub  [ %o0 + %o5 ], %o0
a00add80:  d0 08 40 09  ldub  [ %g1 + %o1 ], %o0
a00add84:  81 c3 e0 08  retl
a00add88:  01 00 00 00  nop
