# leon2m FUN_a0140a0c 0xa0140a0c-0xa0140ab4 (168 bytes)
a0140a0c:  9d e3 bf 98  save  %sp, -104, %sp
a0140a10:  23 2a 00 b2  sethi  %hi(0xa802c800), %l1
a0140a14:  c2 0c 63 d9  ldub  [ %l1 + 0x3d9 ], %g1	! 0xa802cbd9
a0140a18:  80 a0 60 00  cmp  %g1, 0
a0140a1c:  02 80 00 24  be  0xa0140aac
a0140a20:  13 00 06 9a  sethi  %hi(0x1a6800), %o1
a0140a24:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a0140a28:  9e 12 61 fe  or  %o1, 0x1fe, %o7
a0140a2c:  11 2a 00 a9  sethi  %hi(0xa802a400), %o0
a0140a30:  92 12 a3 dc  or  %o2, 0x3dc, %o1
a0140a34:  d4 12 20 7a  lduh  [ %o0 + 0x7a ], %o2
a0140a38:  1b 00 06 9a  sethi  %hi(0x1a6800), %o5
a0140a3c:  a0 13 62 24  or  %o5, 0x224, %l0	! 0x1a6a24
a0140a40:  96 10 20 00  clr  %o3
a0140a44:  90 10 20 00  clr  %o0
a0140a48:  9a 5a 20 26  smul  %o0, 0x26, %o5
a0140a4c:  c2 0b c0 0d  ldub  [ %o7 + %o5 ], %g1
a0140a50:  99 28 60 03  sll  %g1, 3, %o4
a0140a54:  9a 00 40 01  add  %g1, %g1, %o5
a0140a58:  98 03 00 01  add  %o4, %g1, %o4
a0140a5c:  9a 03 40 01  add  %o5, %g1, %o5
a0140a60:  83 2b 60 02  sll  %o5, 2, %g1
a0140a64:  da 12 40 01  lduh  [ %o1 + %g1 ], %o5
a0140a68:  99 2b 20 02  sll  %o4, 2, %o4
a0140a6c:  80 a3 40 0a  cmp  %o5, %o2
a0140a70:  18 80 00 07  bgu  0xa0140a8c
a0140a74:  96 02 e0 01  inc  %o3
a0140a78:  c2 14 00 0c  lduh  [ %l0 + %o4 ], %g1
a0140a7c:  82 03 40 01  add  %o5, %g1, %g1
a0140a80:  80 a2 80 01  cmp  %o2, %g1
a0140a84:  06 80 00 07  bl  0xa0140aa0
a0140a88:  01 00 00 00  nop
a0140a8c:  90 0a e0 ff  and  %o3, 0xff, %o0
a0140a90:  80 a2 20 00  cmp  %o0, 0
a0140a94:  02 bf ff ee  be  0xa0140a4c
a0140a98:  9a 5a 20 26  smul  %o0, 0x26, %o5
a0140a9c:  90 10 20 ff  mov  0xff, %o0
a0140aa0:  7f ff fe cc  call  0xa01405d0
a0140aa4:  90 0a 20 ff  and  %o0, 0xff, %o0
a0140aa8:  c0 2c 63 d9  clrb  [ %l1 + 0x3d9 ]
a0140aac:  81 c7 e0 08  ret
a0140ab0:  81 e8 00 00  restore
