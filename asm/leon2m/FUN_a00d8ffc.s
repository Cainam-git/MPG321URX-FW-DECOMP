# leon2m FUN_a00d8ffc 0xa00d8ffc-0xa00d9120 (292 bytes)
a00d8ffc:  9d e3 bf 98  save  %sp, -104, %sp
a00d9000:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00d9004:  96 14 62 90  or  %l1, 0x290, %o3	! 0xa802d290
a00d9008:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d900c:  a1 33 20 1f  srl  %o4, 0x1f, %l0
a00d9010:  94 0c 20 ff  and  %l0, 0xff, %o2
a00d9014:  13 20 00 00  sethi  %hi(0x80000000), %o1
a00d9018:  90 2b 00 09  andn  %o4, %o1, %o0
a00d901c:  9b 2a a0 1f  sll  %o2, 0x1f, %o5
a00d9020:  82 12 00 0d  or  %o0, %o5, %g1
a00d9024:  80 a2 a0 01  cmp  %o2, 1
a00d9028:  02 80 00 32  be  0xa00d90f0
a00d902c:  c2 22 e1 1c  st  %g1, [ %o3 + 0x11c ]
a00d9030:  80 a2 a0 01  cmp  %o2, 1
a00d9034:  04 80 00 31  ble  0xa00d90f8
a00d9038:  80 a2 a0 02  cmp  %o2, 2
a00d903c:  22 80 00 02  be,a   0xa00d9044
a00d9040:  a0 10 20 02  mov  2, %l0
a00d9044:  40 01 cb 4b  call  0xa014bd70
a00d9048:  90 10 20 00  clr  %o0
a00d904c:  94 0a 20 ff  and  %o0, 0xff, %o2
a00d9050:  80 a2 a0 01  cmp  %o2, 1
a00d9054:  22 80 00 1e  be,a   0xa00d90cc
a00d9058:  a0 10 20 00  clr  %l0
a00d905c:  40 01 aa 20  call  0xa01438dc
a00d9060:  90 10 20 00  clr  %o0
a00d9064:  9e 0a 20 ff  and  %o0, 0xff, %o7
a00d9068:  80 a3 e0 01  cmp  %o7, 1
a00d906c:  02 80 00 0a  be  0xa00d9094
a00d9070:  01 00 00 00  nop
a00d9074:  40 01 c0 91  call  0xa01492b8
a00d9078:  90 0c 20 03  and  %l0, 3, %o0
a00d907c:  96 14 62 90  or  %l1, 0x290, %o3
a00d9080:  e0 02 e1 1c  ld  [ %o3 + 0x11c ], %l0
a00d9084:  80 a4 20 00  cmp  %l0, 0
a00d9088:  06 80 00 24  bl  0xa00d9118
a00d908c:  01 00 00 00  nop
a00d9090:  30 80 00 16  b,a   0xa00d90e8
a00d9094:  40 01 ca 75  call  0xa014ba68
a00d9098:  01 00 00 00  nop
a00d909c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d90a0:  80 a2 20 02  cmp  %o0, 2
a00d90a4:  22 80 00 0a  be,a   0xa00d90cc
a00d90a8:  a0 10 20 00  clr  %l0
a00d90ac:  04 80 00 17  ble  0xa00d9108
a00d90b0:  80 a2 20 01  cmp  %o0, 1
a00d90b4:  80 a2 20 03  cmp  %o0, 3
a00d90b8:  02 80 00 04  be  0xa00d90c8
a00d90bc:  80 a2 20 04  cmp  %o0, 4
a00d90c0:  12 bf ff ed  bne  0xa00d9074
a00d90c4:  01 00 00 00  nop
a00d90c8:  a0 10 20 00  clr  %l0	! 0x0
a00d90cc:  40 01 c0 7b  call  0xa01492b8
a00d90d0:  90 0c 20 03  and  %l0, 3, %o0
a00d90d4:  96 14 62 90  or  %l1, 0x290, %o3
a00d90d8:  e0 02 e1 1c  ld  [ %o3 + 0x11c ], %l0
a00d90dc:  80 a4 20 00  cmp  %l0, 0
a00d90e0:  06 80 00 0e  bl  0xa00d9118
a00d90e4:  01 00 00 00  nop
a00d90e8:  7f ff fe fb  call  0xa00d8cd4
a00d90ec:  81 e8 00 00  restore
a00d90f0:  10 bf ff d5  b  0xa00d9044
a00d90f4:  a0 10 20 01  mov  1, %l0
a00d90f8:  80 a2 a0 00  cmp  %o2, 0
a00d90fc:  22 bf ff d2  be,a   0xa00d9044
a00d9100:  a0 10 20 00  clr  %l0
a00d9104:  30 bf ff d0  b,a   0xa00d9044
a00d9108:  12 bf ff db  bne  0xa00d9074
a00d910c:  01 00 00 00  nop
a00d9110:  10 bf ff ef  b  0xa00d90cc
a00d9114:  a0 10 20 00  clr  %l0	! 0x0
a00d9118:  81 c7 e0 08  ret
a00d911c:  81 e8 00 00  restore
