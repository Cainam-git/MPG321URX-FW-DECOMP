# leon2m FUN_a014512c 0xa014512c-0xa01451fc (208 bytes)
a014512c:  9d e3 bf 98  save  %sp, -104, %sp
a0145130:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0145134:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a0145138:  90 12 21 f8  or  %o0, 0x1f8, %o0	! 0x1a6df8
a014513c:  7f fe 68 0d  call  0xa00df170
a0145140:  92 10 00 18  mov  %i0, %o1
a0145144:  80 a6 20 01  cmp  %i0, 1
a0145148:  02 80 00 17  be  0xa01451a4
a014514c:  01 00 00 00  nop
a0145150:  7f ff f0 5a  call  0xa01412b8
a0145154:  90 10 20 00  clr  %o0	! 0x0
a0145158:  7f ff f0 9e  call  0xa01413d0
a014515c:  01 00 00 00  nop
a0145160:  92 0e 60 ff  and  %i1, 0xff, %o1
a0145164:  80 a2 60 01  cmp  %o1, 1
a0145168:  12 80 00 23  bne  0xa01451f4
a014516c:  01 00 00 00  nop
a0145170:  30 80 00 07  b,a   0xa014518c
a0145174:  7f ff f0 97  call  0xa01413d0
a0145178:  01 00 00 00  nop
a014517c:  7f ff 91 1a  call  0xa01295e4
a0145180:  01 00 00 00  nop
a0145184:  67 fd 1f 55  call  0x4008ced8
a0145188:  01 00 00 00  nop
a014518c:  7f ff f2 51  call  0xa0141ad0
a0145190:  01 00 00 00  nop
a0145194:  80 8a 20 ff  btst  0xff, %o0
a0145198:  02 bf ff f7  be  0xa0145174
a014519c:  01 00 00 00  nop
a01451a0:  30 80 00 15  b,a   0xa01451f4
a01451a4:  7f ff f0 45  call  0xa01412b8
a01451a8:  90 10 20 01  mov  1, %o0
a01451ac:  7f ff f0 89  call  0xa01413d0
a01451b0:  01 00 00 00  nop
a01451b4:  82 0e 60 ff  and  %i1, 0xff, %g1
a01451b8:  80 a0 60 01  cmp  %g1, 1
a01451bc:  12 80 00 0e  bne  0xa01451f4
a01451c0:  01 00 00 00  nop
a01451c4:  30 80 00 07  b,a   0xa01451e0
a01451c8:  7f ff f0 82  call  0xa01413d0
a01451cc:  01 00 00 00  nop
a01451d0:  7f ff 91 05  call  0xa01295e4
a01451d4:  01 00 00 00  nop
a01451d8:  67 fd 1f 40  call  0x4008ced8
a01451dc:  01 00 00 00  nop
a01451e0:  7f ff f2 2e  call  0xa0141a98
a01451e4:  01 00 00 00  nop
a01451e8:  80 8a 20 ff  btst  0xff, %o0
a01451ec:  02 bf ff f7  be  0xa01451c8
a01451f0:  01 00 00 00  nop
a01451f4:  81 c7 e0 08  ret
a01451f8:  81 e8 00 00  restore
