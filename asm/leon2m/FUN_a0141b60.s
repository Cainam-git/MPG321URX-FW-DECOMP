# leon2m FUN_a0141b60 0xa0141b60-0xa0141c48 (232 bytes)
a0141b60:  9d e3 bf 98  save  %sp, -104, %sp
a0141b64:  25 2a 00 b8  sethi  %hi(0xa802e000), %l2
a0141b68:  96 10 20 00  clr  %o3
a0141b6c:  98 10 20 00  clr  %o4
a0141b70:  a0 14 a1 16  or  %l2, 0x116, %l0
a0141b74:  95 2b 20 03  sll  %o4, 3, %o2
a0141b78:  92 02 80 0c  add  %o2, %o4, %o1
a0141b7c:  82 02 40 09  add  %o1, %o1, %g1
a0141b80:  d0 14 00 01  lduh  [ %l0 + %g1 ], %o0
a0141b84:  96 02 e0 01  inc  %o3
a0141b88:  9a 0a 3f 7f  and  %o0, -129, %o5
a0141b8c:  98 0a e0 ff  and  %o3, 0xff, %o4
a0141b90:  80 a3 20 06  cmp  %o4, 6
a0141b94:  08 bf ff f8  bleu  0xa0141b74
a0141b98:  da 34 00 01  sth  %o5, [ %l0 + %g1 ]
a0141b9c:  98 10 20 03  mov  3, %o4
a0141ba0:  96 10 20 04  mov  4, %o3
a0141ba4:  d8 2c 20 10  stb  %o4, [ %l0 + 0x10 ]
a0141ba8:  7f ff a4 71  call  0xa012ad6c
a0141bac:  d6 2c 20 22  stb  %o3, [ %l0 + 0x22 ]
a0141bb0:  80 8a 20 ff  btst  0xff, %o0
a0141bb4:  02 80 00 07  be  0xa0141bd0
a0141bb8:  a2 10 00 10  mov  %l0, %l1
a0141bbc:  a0 10 20 06  mov  6, %l0
a0141bc0:  9e 10 20 05  mov  5, %o7
a0141bc4:  e0 2c 60 46  stb  %l0, [ %l1 + 0x46 ]
a0141bc8:  10 80 00 06  b  0xa0141be0
a0141bcc:  de 2c 60 34  stb  %o7, [ %l1 + 0x34 ]
a0141bd0:  82 10 20 05  mov  5, %g1
a0141bd4:  a2 10 20 06  mov  6, %l1
a0141bd8:  c2 2c 20 46  stb  %g1, [ %l0 + 0x46 ]
a0141bdc:  e2 2c 20 34  stb  %l1, [ %l0 + 0x34 ]
a0141be0:  90 14 a1 16  or  %l2, 0x116, %o0
a0141be4:  de 14 a1 16  lduh  [ %l2 + 0x116 ], %o7
a0141be8:  d8 12 20 36  lduh  [ %o0 + 0x36 ], %o4
a0141bec:  23 00 00 08  sethi  %hi(0x2000), %l1
a0141bf0:  96 0b ef ff  and  %o7, 0xfff, %o3
a0141bf4:  d4 12 20 12  lduh  [ %o0 + 0x12 ], %o2
a0141bf8:  d2 12 20 24  lduh  [ %o0 + 0x24 ], %o1
a0141bfc:  9a 0b 2f ff  and  %o4, 0xfff, %o5
a0141c00:  9e 12 c0 11  or  %o3, %l1, %o7
a0141c04:  de 34 a1 16  sth  %o7, [ %l2 + 0x116 ]
a0141c08:  98 13 40 11  or  %o5, %l1, %o4
a0141c0c:  82 0a af ff  and  %o2, 0xfff, %g1
a0141c10:  a0 0a 6f ff  and  %o1, 0xfff, %l0
a0141c14:  94 10 40 11  or  %g1, %l1, %o2
a0141c18:  92 14 00 11  or  %l0, %l1, %o1
a0141c1c:  96 10 3f fc  mov  -4, %o3
a0141c20:  9a 10 3f fd  mov  -3, %o5
a0141c24:  a4 10 3f fe  mov  -2, %l2
a0141c28:  d8 32 20 36  sth  %o4, [ %o0 + 0x36 ]
a0141c2c:  d6 2a 20 58  stb  %o3, [ %o0 + 0x58 ]
a0141c30:  da 2a 20 6a  stb  %o5, [ %o0 + 0x6a ]
a0141c34:  e4 2a 20 7c  stb  %l2, [ %o0 + 0x7c ]
a0141c38:  d4 32 20 12  sth  %o2, [ %o0 + 0x12 ]
a0141c3c:  d2 32 20 24  sth  %o1, [ %o0 + 0x24 ]
a0141c40:  81 c7 e0 08  ret
a0141c44:  81 e8 00 00  restore
