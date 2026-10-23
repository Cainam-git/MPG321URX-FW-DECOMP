# leon2m FUN_a012bb38 0xa012bb38-0xa012bb94 (92 bytes)
a012bb38:  90 0a 20 ff  and  %o0, 0xff, %o0
a012bb3c:  17 2a 00 b6  sethi  %hi(0xa802d800), %o3
a012bb40:  99 2a 20 03  sll  %o0, 3, %o4
a012bb44:  94 12 e0 dc  or  %o3, 0xdc, %o2
a012bb48:  82 03 00 08  add  %o4, %o0, %g1
a012bb4c:  92 0a 60 01  and  %o1, 1, %o1
a012bb50:  96 10 00 0a  mov  %o2, %o3
a012bb54:  99 28 60 02  sll  %g1, 2, %o4
a012bb58:  80 a2 20 00  cmp  %o0, 0
a012bb5c:  12 80 00 08  bne  0xa012bb7c
a012bb60:  93 2a 60 1e  sll  %o1, 0x1e, %o1
a012bb64:  d6 02 80 08  ld  [ %o2 + %o0 ], %o3
a012bb68:  19 10 00 00  sethi  %hi(0x40000000), %o4
a012bb6c:  82 2a c0 0c  andn  %o3, %o4, %g1
a012bb70:  9a 10 40 09  or  %g1, %o1, %o5
a012bb74:  10 80 00 06  b  0xa012bb8c
a012bb78:  da 22 80 08  st  %o5, [ %o2 + %o0 ]
a012bb7c:  d2 02 80 0c  ld  [ %o2 + %o4 ], %o1
a012bb80:  15 10 00 00  sethi  %hi(0x40000000), %o2
a012bb84:  90 2a 40 0a  andn  %o1, %o2, %o0
a012bb88:  d0 22 c0 0c  st  %o0, [ %o3 + %o4 ]
a012bb8c:  81 c3 e0 08  retl
a012bb90:  01 00 00 00  nop
