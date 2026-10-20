# leon2m FUN_a013bdb8 0xa013bdb8-0xa013beb0 (248 bytes)  [FUN_a013bea8 = unreachable ret/restore tail, merged]
a013bdb8:  9d e3 bf 98  save  %sp, -104, %sp
a013bdbc:  b0 0e 60 ff  and  %i1, 0xff, %i0
a013bdc0:  40 00 03 e3  call  0xa013cd4c
a013bdc4:  90 10 00 18  mov  %i0, %o0
a013bdc8:  d6 12 20 10  lduh  [ %o0 + 0x10 ], %o3
a013bdcc:  de 12 20 14  lduh  [ %o0 + 0x14 ], %o7
a013bdd0:  d8 12 20 0e  lduh  [ %o0 + 0xe ], %o4
a013bdd4:  94 22 c0 0f  sub  %o3, %o7, %o2
a013bdd8:  92 5a 80 0c  smul  %o2, %o4, %o1
a013bddc:  11 00 00 07  sethi  %hi(0x1c00), %o0
a013bde0:  9b 32 60 01  srl  %o1, 1, %o5
a013bde4:  82 12 23 ff  or  %o0, 0x3ff, %g1
a013bde8:  80 a3 40 01  cmp  %o5, %g1
a013bdec:  08 80 00 03  bleu  0xa013bdf8
a013bdf0:  b2 10 20 00  clr  %i1
a013bdf4:  b2 10 20 01  mov  1, %i1
a013bdf8:  7f fe f2 c8  call  0xa00f8918
a013bdfc:  90 10 00 18  mov  %i0, %o0
a013be00:  40 00 03 d3  call  0xa013cd4c
a013be04:  90 10 00 18  mov  %i0, %o0
a013be08:  da 12 20 12  lduh  [ %o0 + 0x12 ], %o5
a013be0c:  c2 12 20 16  lduh  [ %o0 + 0x16 ], %g1
a013be10:  80 a3 40 01  cmp  %o5, %g1
a013be14:  22 80 00 10  be,a   0xa013be54
a013be18:  d4 12 20 14  lduh  [ %o0 + 0x14 ], %o2
a013be1c:  80 8e 60 ff  btst  0xff, %i1
a013be20:  32 80 00 04  bne,a   0xa013be30
a013be24:  da 12 20 20  lduh  [ %o0 + 0x20 ], %o5
a013be28:  7f fe f4 33  call  0xa00f8ef4
a013be2c:  81 e8 00 00  restore
a013be30:  f2 12 20 1c  lduh  [ %o0 + 0x1c ], %i1
a013be34:  80 a6 40 0d  cmp  %i1, %o5
a013be38:  08 80 00 14  bleu  0xa013be88
a013be3c:  98 23 40 19  sub  %o5, %i1, %o4
a013be40:  92 10 00 0d  mov  %o5, %o1
a013be44:  7f fe f2 a9  call  0xa00f88e8
a013be48:  90 10 00 18  mov  %i0, %o0
a013be4c:  7f fe f4 2a  call  0xa00f8ef4
a013be50:  81 e8 00 00  restore
a013be54:  d2 12 20 18  lduh  [ %o0 + 0x18 ], %o1
a013be58:  80 a2 80 09  cmp  %o2, %o1
a013be5c:  12 bf ff f1  bne  0xa013be20
a013be60:  80 8e 60 ff  btst  0xff, %i1
a013be64:  7f ff 97 ba  call  0xa0121d4c
a013be68:  90 10 00 18  mov  %i0, %o0
a013be6c:  96 0a 20 ff  and  %o0, 0xff, %o3
a013be70:  80 a2 e0 01  cmp  %o3, 1
a013be74:  02 80 00 0a  be  0xa013be9c
a013be78:  80 8e 60 ff  btst  0xff, %i1
a013be7c:  02 80 00 0a  be  0xa013bea4
a013be80:  01 00 00 00  nop
a013be84:  30 80 00 04  b,a   0xa013be94
a013be88:  91 2b 20 10  sll  %o4, 0x10, %o0
a013be8c:  10 bf ff ee  b  0xa013be44
a013be90:  93 32 20 10  srl  %o0, 0x10, %o1
a013be94:  7f fe f2 95  call  0xa00f88e8
a013be98:  93 e8 20 00  restore  %g0, 0, %o1
a013be9c:  7f fe f2 9f  call  0xa00f8918
a013bea0:  81 e8 00 00  restore
a013bea4:  01 00 00 00  nop
a013bea8:  81 c7 e0 08  ret
a013beac:  81 e8 00 00  restore
