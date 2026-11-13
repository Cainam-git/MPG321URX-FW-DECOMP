# leon2m FUN_a00f8f78 0xa00f8f78-0xa00f90fc (388 bytes)
a00f8f78:  9d e3 bf 98  save  %sp, -104, %sp
a00f8f7c:  40 00 a3 3c  call  0xa0121c6c
a00f8f80:  90 10 20 03  mov  3, %o0
a00f8f84:  67 fe 50 87  call  0x4008d1a0
a00f8f88:  90 10 20 05  mov  5, %o0
a00f8f8c:  90 10 20 03  mov  3, %o0
a00f8f90:  92 10 20 8c  mov  0x8c, %o1
a00f8f94:  7f ff e2 d0  call  0xa00f1ad4
a00f8f98:  94 10 20 80  mov  0x80, %o2
a00f8f9c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f8fa0:  80 a6 20 00  cmp  %i0, 0
a00f8fa4:  12 80 00 3a  bne  0xa00f908c
a00f8fa8:  90 10 20 00  clr  %o0
a00f8fac:  90 10 20 06  mov  6, %o0
a00f8fb0:  b0 0a 20 ff  and  %o0, 0xff, %i0
a00f8fb4:  90 10 00 18  mov  %i0, %o0
a00f8fb8:  92 10 20 36  mov  0x36, %o1
a00f8fbc:  7f ff e2 c6  call  0xa00f1ad4
a00f8fc0:  94 10 20 11  mov  0x11, %o2
a00f8fc4:  67 fe 51 71  call  0x4008d588
a00f8fc8:  01 00 00 00  nop
a00f8fcc:  a0 10 00 08  mov  %o0, %l0
a00f8fd0:  92 10 20 36  mov  0x36, %o1
a00f8fd4:  7f ff e2 af  call  0xa00f1a90
a00f8fd8:  90 10 00 18  mov  %i0, %o0
a00f8fdc:  80 8a 20 01  btst  1, %o0
a00f8fe0:  02 80 00 0b  be  0xa00f900c
a00f8fe4:  92 10 20 41  mov  0x41, %o1
a00f8fe8:  67 fe 51 68  call  0x4008d588
a00f8fec:  01 00 00 00  nop
a00f8ff0:  92 22 00 10  sub  %o0, %l0, %o1
a00f8ff4:  83 2a 60 10  sll  %o1, 0x10, %g1
a00f8ff8:  91 30 60 10  srl  %g1, 0x10, %o0
a00f8ffc:  80 a2 20 63  cmp  %o0, 0x63
a00f9000:  08 bf ff f5  bleu  0xa00f8fd4
a00f9004:  92 10 20 36  mov  0x36, %o1
a00f9008:  92 10 20 41  mov  0x41, %o1
a00f900c:  7f ff e2 a1  call  0xa00f1a90
a00f9010:  90 10 00 18  mov  %i0, %o0
a00f9014:  96 0a 20 ff  and  %o0, 0xff, %o3
a00f9018:  a1 2a e0 08  sll  %o3, 8, %l0
a00f901c:  92 10 20 40  mov  0x40, %o1
a00f9020:  7f ff e2 9c  call  0xa00f1a90
a00f9024:  90 10 00 18  mov  %i0, %o0
a00f9028:  94 0a 20 ff  and  %o0, 0xff, %o2
a00f902c:  a2 14 00 0a  or  %l0, %o2, %l1
a00f9030:  90 10 00 18  mov  %i0, %o0
a00f9034:  92 10 20 36  mov  0x36, %o1
a00f9038:  7f ff e2 a7  call  0xa00f1ad4
a00f903c:  94 10 20 41  mov  0x41, %o2
a00f9040:  67 fe 51 52  call  0x4008d588
a00f9044:  01 00 00 00  nop
a00f9048:  a0 10 00 08  mov  %o0, %l0
a00f904c:  92 10 20 36  mov  0x36, %o1
a00f9050:  7f ff e2 90  call  0xa00f1a90
a00f9054:  90 10 00 18  mov  %i0, %o0
a00f9058:  80 8a 20 01  btst  1, %o0
a00f905c:  02 80 00 11  be  0xa00f90a0
a00f9060:  92 10 20 41  mov  0x41, %o1
a00f9064:  67 fe 51 49  call  0x4008d588
a00f9068:  01 00 00 00  nop
a00f906c:  9e 22 00 10  sub  %o0, %l0, %o7
a00f9070:  9b 2b e0 10  sll  %o7, 0x10, %o5
a00f9074:  99 33 60 10  srl  %o5, 0x10, %o4
a00f9078:  80 a3 20 63  cmp  %o4, 0x63
a00f907c:  28 bf ff f5  bleu,a   0xa00f9050
a00f9080:  92 10 20 36  mov  0x36, %o1
a00f9084:  10 80 00 07  b  0xa00f90a0
a00f9088:  92 10 20 41  mov  0x41, %o1
a00f908c:  80 a6 20 01  cmp  %i0, 1
a00f9090:  22 bf ff c8  be,a   0xa00f8fb0
a00f9094:  90 10 20 07  mov  7, %o0
a00f9098:  10 bf ff c7  b  0xa00f8fb4
a00f909c:  b0 0a 20 ff  and  %o0, 0xff, %i0
a00f90a0:  7f ff e2 7c  call  0xa00f1a90
a00f90a4:  90 10 00 18  mov  %i0, %o0
a00f90a8:  82 0a 20 ff  and  %o0, 0xff, %g1
a00f90ac:  a1 28 60 08  sll  %g1, 8, %l0
a00f90b0:  92 10 20 40  mov  0x40, %o1
a00f90b4:  7f ff e2 77  call  0xa00f1a90
a00f90b8:  90 10 00 18  mov  %i0, %o0
a00f90bc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f90c0:  a0 14 00 08  or  %l0, %o0, %l0
a00f90c4:  40 00 a2 ea  call  0xa0121c6c
a00f90c8:  90 10 20 03  mov  3, %o0
a00f90cc:  67 fe 50 35  call  0x4008d1a0
a00f90d0:  90 10 20 05  mov  5, %o0
a00f90d4:  b0 1c 00 11  xor  %l0, %l1, %i0
a00f90d8:  90 10 20 03  mov  3, %o0
a00f90dc:  92 10 20 8c  mov  0x8c, %o1
a00f90e0:  94 10 20 00  clr  %o2
a00f90e4:  7f ff e2 7c  call  0xa00f1ad4
a00f90e8:  a3 2e 20 10  sll  %i0, 0x10, %l1
a00f90ec:  80 a0 00 11  cmp  %g0, %l1
a00f90f0:  b0 60 3f ff  subx  %g0, -1, %i0
a00f90f4:  81 c7 e0 08  ret
a00f90f8:  81 e8 00 00  restore
