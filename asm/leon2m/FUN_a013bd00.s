# leon2m FUN_a013bd00 0xa013bd00-0xa013bdb8 (184 bytes)  [FUN_a013bdb0 = unreachable ret/restore tail, merged]
a013bd00:  9d e3 bf 98  save  %sp, -104, %sp
a013bd04:  b0 0e 20 ff  and  %i0, 0xff, %i0
a013bd08:  40 00 04 11  call  0xa013cd4c
a013bd0c:  90 10 00 18  mov  %i0, %o0
a013bd10:  da 12 20 12  lduh  [ %o0 + 0x12 ], %o5
a013bd14:  c2 12 20 16  lduh  [ %o0 + 0x16 ], %g1
a013bd18:  80 a3 40 01  cmp  %o5, %g1
a013bd1c:  22 80 00 10  be,a   0xa013bd5c
a013bd20:  d4 12 20 14  lduh  [ %o0 + 0x14 ], %o2
a013bd24:  80 8e e0 ff  btst  0xff, %i3
a013bd28:  32 80 00 04  bne,a   0xa013bd38
a013bd2c:  da 12 20 20  lduh  [ %o0 + 0x20 ], %o5
a013bd30:  7f fe f4 71  call  0xa00f8ef4
a013bd34:  81 e8 00 00  restore
a013bd38:  d6 12 20 1c  lduh  [ %o0 + 0x1c ], %o3
a013bd3c:  80 a2 c0 0d  cmp  %o3, %o5
a013bd40:  08 80 00 14  bleu  0xa013bd90
a013bd44:  98 23 40 0b  sub  %o5, %o3, %o4
a013bd48:  92 10 00 0d  mov  %o5, %o1
a013bd4c:  7f fe f2 e7  call  0xa00f88e8
a013bd50:  90 10 00 18  mov  %i0, %o0
a013bd54:  7f fe f4 68  call  0xa00f8ef4
a013bd58:  81 e8 00 00  restore
a013bd5c:  d2 12 20 18  lduh  [ %o0 + 0x18 ], %o1
a013bd60:  80 a2 80 09  cmp  %o2, %o1
a013bd64:  12 bf ff f1  bne  0xa013bd28
a013bd68:  80 8e e0 ff  btst  0xff, %i3
a013bd6c:  7f ff 97 f8  call  0xa0121d4c
a013bd70:  90 10 00 18  mov  %i0, %o0
a013bd74:  9e 0a 20 ff  and  %o0, 0xff, %o7
a013bd78:  80 a3 e0 01  cmp  %o7, 1
a013bd7c:  02 80 00 0a  be  0xa013bda4
a013bd80:  80 8e e0 ff  btst  0xff, %i3
a013bd84:  02 80 00 0a  be  0xa013bdac
a013bd88:  01 00 00 00  nop
a013bd8c:  30 80 00 04  b,a   0xa013bd9c
a013bd90:  91 2b 20 10  sll  %o4, 0x10, %o0
a013bd94:  10 bf ff ee  b  0xa013bd4c
a013bd98:  93 32 20 10  srl  %o0, 0x10, %o1
a013bd9c:  7f fe f2 d3  call  0xa00f88e8
a013bda0:  93 e8 20 00  restore  %g0, 0, %o1
a013bda4:  7f fe f2 dd  call  0xa00f8918
a013bda8:  81 e8 00 00  restore
a013bdac:  01 00 00 00  nop
a013bdb0:  81 c7 e0 08  ret
a013bdb4:  81 e8 00 00  restore
