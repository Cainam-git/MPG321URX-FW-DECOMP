# leon2s FUN_a006fd04 0xa006fd04-0xa006fd78 (116 bytes)
a006fd04:  c2 0a 20 03  ldub  [ %o0 + 3 ], %g1
a006fd08:  94 10 00 08  mov  %o0, %o2
a006fd0c:  80 a0 60 55  cmp  %g1, 0x55
a006fd10:  98 10 20 00  clr  %o4
a006fd14:  12 80 00 17  bne  0xa006fd70
a006fd18:  90 10 20 00  clr  %o0
a006fd1c:  92 0a 60 ff  and  %o1, 0xff, %o1
a006fd20:  80 a2 60 00  cmp  %o1, 0
a006fd24:  02 80 00 10  be  0xa006fd64
a006fd28:  96 10 20 00  clr  %o3
a006fd2c:  82 0a e0 ff  and  %o3, 0xff, %g1
a006fd30:  83 28 60 02  sll  %g1, 2, %g1
a006fd34:  da 02 80 01  ld  [ %o2 + %g1 ], %o5
a006fd38:  83 33 60 08  srl  %o5, 8, %g1
a006fd3c:  98 1b 40 0c  xor  %o5, %o4, %o4
a006fd40:  98 1b 00 01  xor  %o4, %g1, %o4
a006fd44:  83 33 60 10  srl  %o5, 0x10, %g1
a006fd48:  98 1b 00 01  xor  %o4, %g1, %o4
a006fd4c:  96 02 e0 01  inc  %o3
a006fd50:  9b 33 60 18  srl  %o5, 0x18, %o5
a006fd54:  82 0a e0 ff  and  %o3, 0xff, %g1
a006fd58:  80 a0 40 09  cmp  %g1, %o1
a006fd5c:  0a bf ff f5  bcs  0xa006fd30
a006fd60:  98 1b 00 0d  xor  %o4, %o5, %o4
a006fd64:  82 0b 20 ff  and  %o4, 0xff, %g1
a006fd68:  80 a0 00 01  cmp  %g0, %g1
a006fd6c:  90 60 3f ff  subx  %g0, -1, %o0
a006fd70:  81 c3 e0 08  retl
a006fd74:  01 00 00 00  nop
