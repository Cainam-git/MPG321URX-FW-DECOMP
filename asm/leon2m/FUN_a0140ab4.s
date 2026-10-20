# leon2m FUN_a0140ab4 0xa0140ab4-0xa0140b78 (196 bytes)
a0140ab4:  9d e3 bf 98  save  %sp, -104, %sp
a0140ab8:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a0140abc:  c2 0c 23 d9  ldub  [ %l0 + 0x3d9 ], %g1	! 0xa802cbd9
a0140ac0:  80 a0 60 00  cmp  %g1, 0
a0140ac4:  02 80 00 2b  be  0xa0140b70
a0140ac8:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a0140acc:  67 fd 32 b2  call  0x4008d594
a0140ad0:  d0 12 a0 04  lduh  [ %o2 + 4 ], %o0	! 0xa802cc04
a0140ad4:  93 2a 20 10  sll  %o0, 0x10, %o1
a0140ad8:  91 32 60 10  srl  %o1, 0x10, %o0
a0140adc:  80 a2 23 e8  cmp  %o0, 0x3e8
a0140ae0:  08 80 00 24  bleu  0xa0140b70
a0140ae4:  23 00 06 9a  sethi  %hi(0x1a6800), %l1
a0140ae8:  17 2a 00 a9  sethi  %hi(0xa802a400), %o3
a0140aec:  9e 14 61 fe  or  %l1, 0x1fe, %o7
a0140af0:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a0140af4:  d4 12 e0 7a  lduh  [ %o3 + 0x7a ], %o2
a0140af8:  1b 00 06 9a  sethi  %hi(0x1a6800), %o5
a0140afc:  92 13 23 dc  or  %o4, 0x3dc, %o1
a0140b00:  a2 13 62 24  or  %o5, 0x224, %l1
a0140b04:  96 10 20 00  clr  %o3
a0140b08:  90 10 20 00  clr  %o0
a0140b0c:  9a 5a 20 26  smul  %o0, 0x26, %o5
a0140b10:  c2 0b c0 0d  ldub  [ %o7 + %o5 ], %g1
a0140b14:  99 28 60 03  sll  %g1, 3, %o4
a0140b18:  9a 00 40 01  add  %g1, %g1, %o5
a0140b1c:  98 03 00 01  add  %o4, %g1, %o4
a0140b20:  9a 03 40 01  add  %o5, %g1, %o5
a0140b24:  83 2b 60 02  sll  %o5, 2, %g1
a0140b28:  da 12 40 01  lduh  [ %o1 + %g1 ], %o5
a0140b2c:  99 2b 20 02  sll  %o4, 2, %o4
a0140b30:  80 a3 40 0a  cmp  %o5, %o2
a0140b34:  18 80 00 07  bgu  0xa0140b50
a0140b38:  96 02 e0 01  inc  %o3
a0140b3c:  c2 14 40 0c  lduh  [ %l1 + %o4 ], %g1
a0140b40:  82 03 40 01  add  %o5, %g1, %g1
a0140b44:  80 a2 80 01  cmp  %o2, %g1
a0140b48:  06 80 00 07  bl  0xa0140b64
a0140b4c:  01 00 00 00  nop
a0140b50:  90 0a e0 ff  and  %o3, 0xff, %o0
a0140b54:  80 a2 20 00  cmp  %o0, 0
a0140b58:  02 bf ff ee  be  0xa0140b10
a0140b5c:  9a 5a 20 26  smul  %o0, 0x26, %o5
a0140b60:  90 10 20 ff  mov  0xff, %o0
a0140b64:  7f ff fe 9b  call  0xa01405d0
a0140b68:  90 0a 20 ff  and  %o0, 0xff, %o0
a0140b6c:  c0 2c 23 d9  clrb  [ %l0 + 0x3d9 ]
a0140b70:  81 c7 e0 08  ret
a0140b74:  81 e8 00 00  restore
