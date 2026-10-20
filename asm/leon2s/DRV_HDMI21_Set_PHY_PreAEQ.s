# leon2s DRV_HDMI21_Set_PHY_PreAEQ 0xa007fffc-0xa0080244 (584 bytes)  [FUN_a008023c = unreachable ret/restore tail, merged]
a007fffc:  9d e3 bf 98  save  %sp, -104, %sp
a0080000:  a0 0e 20 ff  and  %i0, 0xff, %l0
a0080004:  80 a4 20 02  cmp  %l0, 2
a0080008:  02 80 00 05  be  0xa008001c
a008000c:  a2 10 20 00  clr  %l1
a0080010:  80 a4 20 03  cmp  %l0, 3
a0080014:  12 80 00 89  bne  0xa0080238
a0080018:  a2 10 20 01  mov  1, %l1
a008001c:  29 2a 01 e1  sethi  %hi(0xa8078400), %l4
a0080020:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1	! 0xa8078634
a0080024:  80 88 68 00  btst  0x800, %g1
a0080028:  02 80 00 08  be  0xa0080048
a008002c:  a4 0c 60 ff  and  %l1, 0xff, %l2
a0080030:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a0080034:  13 28 02 cf  sethi  %hi(0xa00b3c00), %o1
a0080038:  90 12 20 68  or  %o0, 0x68, %o0
a008003c:  7f ff cc 02  call  0xa0073044
a0080040:  92 12 63 b8  or  %o1, 0x3b8, %o1
a0080044:  a4 0c 60 ff  and  %l1, 0xff, %l2
a0080048:  27 2a 01 f5  sethi  %hi(0xa807d400), %l3
a008004c:  82 14 e2 80  or  %l3, 0x280, %g1	! 0xa807d680
a0080050:  9a 5c a0 b0  smul  %l2, 0xb0, %o5
a0080054:  9a 03 40 01  add  %o5, %g1, %o5
a0080058:  c2 0b 60 02  ldub  [ %o5 + 2 ], %g1
a008005c:  82 00 7f fc  add  %g1, -4, %g1
a0080060:  82 08 60 ff  and  %g1, 0xff, %g1
a0080064:  80 a0 60 02  cmp  %g1, 2
a0080068:  18 80 00 05  bgu  0xa008007c
a008006c:  a2 0e 20 ff  and  %i0, 0xff, %l1
a0080070:  7f ff e7 c4  call  0xa0079f80
a0080074:  90 10 00 10  mov  %l0, %o0
a0080078:  a2 0e 20 ff  and  %i0, 0xff, %l1
a008007c:  90 10 00 11  mov  %l1, %o0
a0080080:  92 10 20 01  mov  1, %o1
a0080084:  7f ff e5 bd  call  0xa0079778
a0080088:  94 10 20 01  mov  1, %o2
a008008c:  a0 10 20 00  clr  %l0
a0080090:  9a 0c 20 ff  and  %l0, 0xff, %o5
a0080094:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a0080098:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a008009c:  80 88 68 00  btst  0x800, %g1
a00800a0:  92 10 00 0d  mov  %o5, %o1
a00800a4:  02 80 00 0a  be  0xa00800cc
a00800a8:  90 12 22 60  or  %o0, 0x260, %o0
a00800ac:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00800b0:  82 10 60 50  or  %g1, 0x50, %g1	! 0xa807cc50
a00800b4:  da 08 40 0d  ldub  [ %g1 + %o5 ], %o5
a00800b8:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a00800bc:  9b 2b 60 02  sll  %o5, 2, %o5
a00800c0:  82 10 62 e4  or  %g1, 0x2e4, %g1
a00800c4:  7f ff cb e0  call  0xa0073044
a00800c8:  d4 00 40 0d  ld  [ %g1 + %o5 ], %o2
a00800cc:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00800d0:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00800d4:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1
a00800d8:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a00800dc:  80 88 68 00  btst  0x800, %g1
a00800e0:  92 10 00 0d  mov  %o5, %o1
a00800e4:  02 80 00 0a  be  0xa008010c
a00800e8:  90 12 22 a0  or  %o0, 0x2a0, %o0
a00800ec:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00800f0:  82 10 60 60  or  %g1, 0x60, %g1	! 0xa807cc60
a00800f4:  da 08 40 0d  ldub  [ %g1 + %o5 ], %o5
a00800f8:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a00800fc:  9b 2b 60 02  sll  %o5, 2, %o5
a0080100:  82 10 62 dc  or  %g1, 0x2dc, %g1
a0080104:  7f ff cb d0  call  0xa0073044
a0080108:  d4 00 40 0d  ld  [ %g1 + %o5 ], %o2
a008010c:  98 0c 20 ff  and  %l0, 0xff, %o4
a0080110:  15 3f c0 00  sethi  %hi(0xff000000), %o2
a0080114:  a0 04 20 01  inc  %l0
a0080118:  92 03 00 0c  add  %o4, %o4, %o1
a008011c:  80 a3 20 03  cmp  %o4, 3
a0080120:  94 12 a0 f0  or  %o2, 0xf0, %o2
a0080124:  18 80 00 1a  bgu  0xa008018c
a0080128:  90 10 00 11  mov  %l1, %o0
a008012c:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0080130:  82 10 60 60  or  %g1, 0x60, %g1	! 0xa807cc60
a0080134:  da 08 40 0c  ldub  [ %g1 + %o4 ], %o5
a0080138:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a008013c:  82 10 60 50  or  %g1, 0x50, %g1	! 0xa807cc50
a0080140:  d8 08 40 0c  ldub  [ %g1 + %o4 ], %o4
a0080144:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0080148:  9b 2b 60 02  sll  %o5, 2, %o5
a008014c:  82 10 62 dc  or  %g1, 0x2dc, %g1
a0080150:  d6 00 40 0d  ld  [ %g1 + %o5 ], %o3
a0080154:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0080158:  82 10 62 e4  or  %g1, 0x2e4, %g1	! 0xa00b3ae4
a008015c:  99 2b 20 02  sll  %o4, 2, %o4
a0080160:  da 00 40 0c  ld  [ %g1 + %o4 ], %o5
a0080164:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a0080168:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffff
a008016c:  96 0a c0 01  and  %o3, %g1, %o3
a0080170:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0080174:  9a 0b 60 0f  and  %o5, 0xf, %o5
a0080178:  97 2a e0 08  sll  %o3, 8, %o3
a008017c:  82 10 63 18  or  %g1, 0x318, %g1
a0080180:  d2 10 40 09  lduh  [ %g1 + %o1 ], %o1
a0080184:  40 00 9c c1  call  0xa00a7488
a0080188:  96 13 40 0b  or  %o5, %o3, %o3
a008018c:  82 0c 20 ff  and  %l0, 0xff, %g1
a0080190:  80 a0 60 03  cmp  %g1, 3
a0080194:  08 bf ff c0  bleu  0xa0080094
a0080198:  9a 0c 20 ff  and  %l0, 0xff, %o5
a008019c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00801a0:  90 10 00 18  mov  %i0, %o0
a00801a4:  92 10 20 00  clr  %o1
a00801a8:  7f ff e5 74  call  0xa0079778
a00801ac:  94 10 20 01  mov  1, %o2
a00801b0:  40 00 c5 79  call  0xa00b1794
a00801b4:  90 10 20 01  mov  1, %o0
a00801b8:  82 14 e2 80  or  %l3, 0x280, %g1
a00801bc:  9a 5c a0 b0  smul  %l2, 0xb0, %o5
a00801c0:  9a 03 40 01  add  %o5, %g1, %o5
a00801c4:  c2 0b 60 34  ldub  [ %o5 + 0x34 ], %g1
a00801c8:  80 a0 60 00  cmp  %g1, 0
a00801cc:  02 80 00 1b  be  0xa0080238
a00801d0:  01 00 00 00  nop
a00801d4:  7f ff e9 17  call  0xa007a630
a00801d8:  90 10 00 18  mov  %i0, %o0
a00801dc:  7f ff e9 45  call  0xa007a6f0
a00801e0:  90 10 00 18  mov  %i0, %o0
a00801e4:  80 8e 60 ff  btst  0xff, %i1
a00801e8:  02 80 00 12  be  0xa0080230
a00801ec:  01 00 00 00  nop
a00801f0:  7f ff e4 ec  call  0xa00795a0
a00801f4:  90 10 00 18  mov  %i0, %o0
a00801f8:  7f ff e6 2d  call  0xa0079aac
a00801fc:  90 10 00 18  mov  %i0, %o0
a0080200:  7f ff fd 72  call  0xa007f7c8
a0080204:  90 10 00 18  mov  %i0, %o0
a0080208:  7f ff fe 01  call  0xa007fa0c
a008020c:  90 10 00 18  mov  %i0, %o0
a0080210:  7f ff e5 bb  call  0xa00798fc
a0080214:  90 10 00 18  mov  %i0, %o0
a0080218:  40 00 c5 5f  call  0xa00b1794
a008021c:  90 10 20 01  mov  1, %o0
a0080220:  7f ff e5 e6  call  0xa00799b8
a0080224:  90 10 00 18  mov  %i0, %o0
a0080228:  7f ff e4 de  call  0xa00795a0
a008022c:  90 10 00 18  mov  %i0, %o0
a0080230:  7f ff fd 66  call  0xa007f7c8
a0080234:  81 e8 00 00  restore
a0080238:  01 00 00 00  nop
a008023c:  81 c7 e0 08  ret
a0080240:  81 e8 00 00  restore
