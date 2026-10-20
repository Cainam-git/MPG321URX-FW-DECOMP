# leon2m FUN_a002ae4c 0xa002ae4c-0xa002b058 (524 bytes)
a002ae4c:  9d e3 bf 98  save  %sp, -104, %sp
a002ae50:  25 2a 00 b6  sethi  %hi(0xa802d800), %l2
a002ae54:  a0 14 a1 92  or  %l2, 0x192, %l0	! 0xa802d992
a002ae58:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002ae5c:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002ae60:  40 00 07 34  call  0xa002cb30
a002ae64:  94 10 20 01  mov  1, %o2
a002ae68:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002ae6c:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002ae70:  94 10 20 01  mov  1, %o2
a002ae74:  40 00 06 7e  call  0xa002c86c
a002ae78:  ac 0e 20 01  and  %i0, 1, %l6
a002ae7c:  a2 10 00 10  mov  %l0, %l1
a002ae80:  b0 10 20 00  clr  %i0
a002ae84:  a8 10 20 00  clr  %l4
a002ae88:  aa 10 00 12  mov  %l2, %l5
a002ae8c:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002ae90:  d2 0c 60 01  ldub  [ %l1 + 1 ], %o1
a002ae94:  40 00 06 76  call  0xa002c86c
a002ae98:  94 10 20 01  mov  1, %o2
a002ae9c:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002aea0:  d2 0c 60 01  ldub  [ %l1 + 1 ], %o1
a002aea4:  40 00 07 23  call  0xa002cb30
a002aea8:  94 10 20 01  mov  1, %o2
a002aeac:  a6 06 00 18  add  %i0, %i0, %l3
a002aeb0:  10 80 00 07  b  0xa002aecc
a002aeb4:  a0 10 3f ff  mov  -1, %l0
a002aeb8:  80 a3 60 00  cmp  %o5, 0
a002aebc:  02 80 00 0d  be  0xa002aef0
a002aec0:  94 10 20 00  clr  %o2
a002aec4:  01 00 00 00  nop
a002aec8:  01 00 00 00  nop
a002aecc:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002aed0:  40 00 07 9a  call  0xa002cd38
a002aed4:  d2 0c 60 01  ldub  [ %l1 + 1 ], %o1
a002aed8:  82 04 3f ff  add  %l0, -1, %g1
a002aedc:  9b 28 60 10  sll  %g1, 0x10, %o5
a002aee0:  80 8a 20 ff  btst  0xff, %o0
a002aee4:  02 bf ff f5  be  0xa002aeb8
a002aee8:  a0 10 00 01  mov  %g1, %l0
a002aeec:  94 10 20 00  clr  %o2
a002aef0:  d2 0c 60 01  ldub  [ %l1 + 1 ], %o1
a002aef4:  40 00 07 0f  call  0xa002cb30
a002aef8:  d0 0d 61 92  ldub  [ %l5 + 0x192 ], %o0
a002aefc:  d2 14 60 04  lduh  [ %l1 + 4 ], %o1
a002af00:  91 2a 60 11  sll  %o1, 0x11, %o0
a002af04:  40 00 08 ce  call  0xa002d23c
a002af08:  91 32 20 10  srl  %o0, 0x10, %o0
a002af0c:  d0 0c 60 02  ldub  [ %l1 + 2 ], %o0
a002af10:  40 00 07 8a  call  0xa002cd38
a002af14:  d2 0c 60 03  ldub  [ %l1 + 3 ], %o1
a002af18:  80 8a 20 ff  btst  0xff, %o0
a002af1c:  02 80 00 03  be  0xa002af28
a002af20:  b0 10 00 13  mov  %l3, %i0
a002af24:  b0 14 e0 01  or  %l3, 1, %i0
a002af28:  a0 14 a1 92  or  %l2, 0x192, %l0
a002af2c:  94 10 20 00  clr  %o2
a002af30:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002af34:  40 00 06 4e  call  0xa002c86c
a002af38:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002af3c:  d8 14 20 04  lduh  [ %l0 + 4 ], %o4
a002af40:  97 2b 20 11  sll  %o4, 0x11, %o3
a002af44:  40 00 08 be  call  0xa002d23c
a002af48:  91 32 e0 10  srl  %o3, 0x10, %o0
a002af4c:  a8 05 20 01  inc  %l4
a002af50:  94 0d 20 ff  and  %l4, 0xff, %o2
a002af54:  80 a2 a0 07  cmp  %o2, 7
a002af58:  08 bf ff ce  bleu  0xa002ae90
a002af5c:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002af60:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002af64:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002af68:  40 00 06 f2  call  0xa002cb30
a002af6c:  94 10 20 00  clr  %o2
a002af70:  80 a5 a0 00  cmp  %l6, 0
a002af74:  12 80 00 24  bne  0xa002b004
a002af78:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002af7c:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002af80:  94 10 20 00  clr  %o2
a002af84:  40 00 06 3a  call  0xa002c86c
a002af88:  a0 14 a1 92  or  %l2, 0x192, %l0
a002af8c:  de 14 20 04  lduh  [ %l0 + 4 ], %o7
a002af90:  9b 2b e0 11  sll  %o7, 0x11, %o5
a002af94:  40 00 08 aa  call  0xa002d23c
a002af98:  91 33 60 10  srl  %o5, 0x10, %o0
a002af9c:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002afa0:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002afa4:  40 00 06 32  call  0xa002c86c
a002afa8:  94 10 20 01  mov  1, %o2
a002afac:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002afb0:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002afb4:  40 00 06 df  call  0xa002cb30
a002afb8:  94 10 20 01  mov  1, %o2
a002afbc:  a2 10 3f ff  mov  -1, %l1
a002afc0:  10 80 00 07  b  0xa002afdc
a002afc4:  27 2a 00 b6  sethi  %hi(0xa802d800), %l3
a002afc8:  80 a3 60 00  cmp  %o5, 0
a002afcc:  22 80 00 11  be,a   0xa002b010
a002afd0:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002afd4:  01 00 00 00  nop
a002afd8:  01 00 00 00  nop
a002afdc:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002afe0:  40 00 07 56  call  0xa002cd38
a002afe4:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002afe8:  a8 04 7f ff  add  %l1, -1, %l4
a002afec:  9b 2d 20 10  sll  %l4, 0x10, %o5
a002aff0:  80 8a 20 ff  btst  0xff, %o0
a002aff4:  02 bf ff f5  be  0xa002afc8
a002aff8:  a2 10 00 14  mov  %l4, %l1
a002affc:  10 80 00 05  b  0xa002b010
a002b000:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002b004:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002b008:  10 bf ff df  b  0xa002af84
a002b00c:  94 10 20 01  mov  1, %o2
a002b010:  94 10 20 00  clr  %o2
a002b014:  40 00 06 c7  call  0xa002cb30
a002b018:  d0 0c e1 92  ldub  [ %l3 + 0x192 ], %o0
a002b01c:  ec 14 20 04  lduh  [ %l0 + 4 ], %l6
a002b020:  ab 2d a0 11  sll  %l6, 0x11, %l5
a002b024:  40 00 08 86  call  0xa002d23c
a002b028:  91 35 60 10  srl  %l5, 0x10, %o0
a002b02c:  d0 0c e1 92  ldub  [ %l3 + 0x192 ], %o0
a002b030:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002b034:  40 00 06 0e  call  0xa002c86c
a002b038:  94 10 20 00  clr  %o2
a002b03c:  e4 14 20 04  lduh  [ %l0 + 4 ], %l2
a002b040:  a3 2c a0 11  sll  %l2, 0x11, %l1
a002b044:  40 00 08 7e  call  0xa002d23c
a002b048:  91 34 60 10  srl  %l1, 0x10, %o0
a002b04c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a002b050:  81 c7 e0 08  ret
a002b054:  81 e8 00 00  restore
