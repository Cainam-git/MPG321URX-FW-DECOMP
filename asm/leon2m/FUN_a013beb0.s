# leon2m FUN_a013beb0 0xa013beb0-0xa013bfa8 (248 bytes)  [FUN_a013bfa0 = unreachable ret/restore tail, merged]
a013beb0:  9d e3 bf 98  save  %sp, -104, %sp
a013beb4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a013beb8:  40 00 03 a5  call  0xa013cd4c
a013bebc:  90 10 00 18  mov  %i0, %o0
a013bec0:  d6 12 20 10  lduh  [ %o0 + 0x10 ], %o3
a013bec4:  de 12 20 14  lduh  [ %o0 + 0x14 ], %o7
a013bec8:  d8 12 20 0e  lduh  [ %o0 + 0xe ], %o4
a013becc:  94 22 c0 0f  sub  %o3, %o7, %o2
a013bed0:  92 5a 80 0c  smul  %o2, %o4, %o1
a013bed4:  11 00 00 07  sethi  %hi(0x1c00), %o0
a013bed8:  9b 32 60 01  srl  %o1, 1, %o5
a013bedc:  82 12 23 ff  or  %o0, 0x3ff, %g1
a013bee0:  80 a3 40 01  cmp  %o5, %g1
a013bee4:  08 80 00 03  bleu  0xa013bef0
a013bee8:  b2 10 20 00  clr  %i1
a013beec:  b2 10 20 01  mov  1, %i1
a013bef0:  7f fe f2 8a  call  0xa00f8918
a013bef4:  90 10 00 18  mov  %i0, %o0
a013bef8:  40 00 03 95  call  0xa013cd4c
a013befc:  90 10 00 18  mov  %i0, %o0
a013bf00:  da 12 20 12  lduh  [ %o0 + 0x12 ], %o5
a013bf04:  c2 12 20 16  lduh  [ %o0 + 0x16 ], %g1
a013bf08:  80 a3 40 01  cmp  %o5, %g1
a013bf0c:  22 80 00 10  be,a   0xa013bf4c
a013bf10:  d4 12 20 14  lduh  [ %o0 + 0x14 ], %o2
a013bf14:  80 8e 60 ff  btst  0xff, %i1
a013bf18:  32 80 00 04  bne,a   0xa013bf28
a013bf1c:  da 12 20 20  lduh  [ %o0 + 0x20 ], %o5
a013bf20:  7f fe f3 f5  call  0xa00f8ef4
a013bf24:  81 e8 00 00  restore
a013bf28:  f2 12 20 1c  lduh  [ %o0 + 0x1c ], %i1
a013bf2c:  80 a6 40 0d  cmp  %i1, %o5
a013bf30:  08 80 00 14  bleu  0xa013bf80
a013bf34:  98 23 40 19  sub  %o5, %i1, %o4
a013bf38:  92 10 00 0d  mov  %o5, %o1
a013bf3c:  7f fe f2 6b  call  0xa00f88e8
a013bf40:  90 10 00 18  mov  %i0, %o0
a013bf44:  7f fe f3 ec  call  0xa00f8ef4
a013bf48:  81 e8 00 00  restore
a013bf4c:  d2 12 20 18  lduh  [ %o0 + 0x18 ], %o1
a013bf50:  80 a2 80 09  cmp  %o2, %o1
a013bf54:  12 bf ff f1  bne  0xa013bf18
a013bf58:  80 8e 60 ff  btst  0xff, %i1
a013bf5c:  7f ff 97 7c  call  0xa0121d4c
a013bf60:  90 10 00 18  mov  %i0, %o0
a013bf64:  96 0a 20 ff  and  %o0, 0xff, %o3
a013bf68:  80 a2 e0 01  cmp  %o3, 1
a013bf6c:  02 80 00 0a  be  0xa013bf94
a013bf70:  80 8e 60 ff  btst  0xff, %i1
a013bf74:  02 80 00 0a  be  0xa013bf9c
a013bf78:  01 00 00 00  nop
a013bf7c:  30 80 00 04  b,a   0xa013bf8c
a013bf80:  91 2b 20 10  sll  %o4, 0x10, %o0
a013bf84:  10 bf ff ee  b  0xa013bf3c
a013bf88:  93 32 20 10  srl  %o0, 0x10, %o1
a013bf8c:  7f fe f2 57  call  0xa00f88e8
a013bf90:  93 e8 20 00  restore  %g0, 0, %o1
a013bf94:  7f fe f2 61  call  0xa00f8918
a013bf98:  81 e8 00 00  restore
a013bf9c:  01 00 00 00  nop
a013bfa0:  81 c7 e0 08  ret
a013bfa4:  81 e8 00 00  restore
