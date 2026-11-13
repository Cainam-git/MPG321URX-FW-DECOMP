# leon2m FUN_a00a012c 0xa00a012c-0xa00a01b8 (140 bytes)
a00a012c:  9d e3 bf 98  save  %sp, -104, %sp
a00a0130:  7f ff fc bf  call  0xa009f42c
a00a0134:  b0 10 3f 84  mov  -124, %i0
a00a0138:  40 00 53 b7  call  0xa00b5014
a00a013c:  01 00 00 00  nop
a00a0140:  80 8a 20 ff  btst  0xff, %o0
a00a0144:  02 80 00 06  be  0xa00a015c
a00a0148:  01 00 00 00  nop
a00a014c:  b0 10 3f 80  mov  -128, %i0	! 0xffffff80
a00a0150:  b0 0e 20 87  and  %i0, 0x87, %i0
a00a0154:  7f ff a8 0c  call  0xa008a184
a00a0158:  81 e8 00 00  restore
a00a015c:  40 00 53 b5  call  0xa00b5030
a00a0160:  01 00 00 00  nop
a00a0164:  80 8a 20 ff  btst  0xff, %o0
a00a0168:  02 80 00 06  be  0xa00a0180
a00a016c:  01 00 00 00  nop
a00a0170:  b0 10 3f 82  mov  -126, %i0	! 0xffffff82
a00a0174:  b0 0e 20 87  and  %i0, 0x87, %i0
a00a0178:  7f ff a8 03  call  0xa008a184
a00a017c:  81 e8 00 00  restore
a00a0180:  40 00 53 b2  call  0xa00b5048
a00a0184:  01 00 00 00  nop
a00a0188:  80 8a 20 ff  btst  0xff, %o0
a00a018c:  02 80 00 04  be  0xa00a019c
a00a0190:  01 00 00 00  nop
a00a0194:  10 bf ff ef  b  0xa00a0150
a00a0198:  b0 10 3f 81  mov  -127, %i0	! 0xffffff81
a00a019c:  40 00 53 b2  call  0xa00b5064
a00a01a0:  01 00 00 00  nop
a00a01a4:  80 8a 20 ff  btst  0xff, %o0
a00a01a8:  32 bf ff ea  bne,a   0xa00a0150
a00a01ac:  b0 10 3f 83  mov  -125, %i0
a00a01b0:  10 bf ff e9  b  0xa00a0154
a00a01b4:  b0 0e 20 87  and  %i0, 0x87, %i0
