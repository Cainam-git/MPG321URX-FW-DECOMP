# leon2s bch_en_flag 0xa0075190-0xa0075278 (232 bytes)  [FUN_a0075270 = unreachable ret/restore tail, merged]
a0075190:  9d e3 bf 98  save  %sp, -104, %sp
a0075194:  80 a6 60 00  cmp  %i1, 0
a0075198:  02 80 00 06  be  0xa00751b0
a007519c:  80 a6 60 03  cmp  %i1, 3
a00751a0:  02 80 00 25  be  0xa0075234
a00751a4:  82 0e 20 ff  and  %i0, 0xff, %g1
a00751a8:  10 80 00 2a  b  0xa0075250
a00751ac:  31 2a 01 ea  sethi  %hi(0xa807a800), %i0
a00751b0:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00751b4:  23 2a 01 ea  sethi  %hi(0xa807a800), %l1
a00751b8:  82 14 61 f0  or  %l1, 0x1f0, %g1	! 0xa807a9f0
a00751bc:  90 5c 28 98  smul  %l0, 0x898, %o0
a00751c0:  c0 30 40 08  clrh  [ %g1 + %o0 ]
a00751c4:  b4 02 00 01  add  %o0, %g1, %i2
a00751c8:  9a 00 60 31  add  %g1, 0x31, %o5
a00751cc:  90 02 00 0d  add  %o0, %o5, %o0
a00751d0:  c0 2e a0 02  clrb  [ %i2 + 2 ]
a00751d4:  92 10 20 00  clr  %o1
a00751d8:  40 00 f0 f5  call  0xa00b15ac
a00751dc:  94 10 20 03  mov  3, %o2
a00751e0:  c2 0e a0 29  ldub  [ %i2 + 0x29 ], %g1
a00751e4:  80 a0 60 00  cmp  %g1, 0
a00751e8:  02 80 00 04  be  0xa00751f8
a00751ec:  82 10 20 01  mov  1, %g1
a00751f0:  10 80 00 03  b  0xa00751fc
a00751f4:  c0 2e a0 29  clrb  [ %i2 + 0x29 ]
a00751f8:  c2 2e a0 29  stb  %g1, [ %i2 + 0x29 ]
a00751fc:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0075200:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0075204:  80 88 60 02  btst  2, %g1
a0075208:  02 80 00 19  be  0xa007526c
a007520c:  b2 06 20 41  add  %i0, 0x41, %i1
a0075210:  9a 14 61 f0  or  %l1, 0x1f0, %o5
a0075214:  82 5c 28 98  smul  %l0, 0x898, %g1
a0075218:  82 00 40 0d  add  %g1, %o5, %g1
a007521c:  b3 2e 60 18  sll  %i1, 0x18, %i1
a0075220:  31 28 01 9a  sethi  %hi(0xa0066800), %i0
a0075224:  b3 3e 60 18  sra  %i1, 0x18, %i1
a0075228:  f4 08 60 29  ldub  [ %g1 + 0x29 ], %i2
a007522c:  7f ff f7 86  call  0xa0073044
a0075230:  91 ee 22 f8  restore  %i0, 0x2f8, %o0
a0075234:  31 2a 01 ea  sethi  %hi(0xa807a800), %i0
a0075238:  82 58 68 98  smul  %g1, 0x898, %g1
a007523c:  b0 16 22 21  or  %i0, 0x221, %i0
a0075240:  b0 00 40 18  add  %g1, %i0, %i0
a0075244:  b2 10 20 00  clr  %i1
a0075248:  10 80 00 07  b  0xa0075264
a007524c:  b4 10 20 03  mov  3, %i2
a0075250:  82 58 68 98  smul  %g1, 0x898, %g1
a0075254:  b0 16 21 f0  or  %i0, 0x1f0, %i0
a0075258:  b0 00 40 18  add  %g1, %i0, %i0
a007525c:  b2 10 20 00  clr  %i1
a0075260:  b4 10 28 98  mov  0x898, %i2
a0075264:  40 00 f0 d2  call  0xa00b15ac
a0075268:  81 e8 00 00  restore
a007526c:  01 00 00 00  nop
a0075270:  81 c7 e0 08  ret
a0075274:  81 e8 00 00  restore
