# leon2m FUN_a015c058 0xa015c058-0xa015c138 (224 bytes)
a015c058:  9d e3 bf 98  save  %sp, -104, %sp
a015c05c:  7f ff fd 66  call  0xa015b5f4
a015c060:  a6 10 20 00  clr  %l3
a015c064:  a4 86 22 e0  addcc  %i0, 0x2e0, %l2
a015c068:  02 80 00 2f  be  0xa015c124
a015c06c:  01 00 00 00  nop
a015c070:  e2 04 a0 04  ld  [ %l2 + 4 ], %l1
a015c074:  a2 84 7f ff  addcc  %l1, -1, %l1
a015c078:  0c 80 00 1e  bneg  0xa015c0f0
a015c07c:  e0 04 a0 08  ld  [ %l2 + 8 ], %l0
a015c080:  da 14 20 0c  lduh  [ %l0 + 0xc ], %o5
a015c084:  83 2b 60 10  sll  %o5, 0x10, %g1
a015c088:  80 a0 60 00  cmp  %g1, 0
a015c08c:  02 80 00 15  be  0xa015c0e0
a015c090:  99 30 60 10  srl  %g1, 0x10, %o4
a015c094:  80 8b 22 00  btst  0x200, %o4
a015c098:  02 80 00 1f  be  0xa015c114
a015c09c:  90 04 20 58  add  %l0, 0x58, %o0
a015c0a0:  83 2b 60 10  sll  %o5, 0x10, %g1
a015c0a4:  80 a0 60 00  cmp  %g1, 0
a015c0a8:  02 80 00 0c  be  0xa015c0d8
a015c0ac:  80 8b 62 00  btst  0x200, %o5
a015c0b0:  c2 54 20 0e  ldsh  [ %l0 + 0xe ], %g1
a015c0b4:  92 10 00 10  mov  %l0, %o1
a015c0b8:  80 a0 7f ff  cmp  %g1, -1
a015c0bc:  02 80 00 06  be  0xa015c0d4
a015c0c0:  90 10 00 18  mov  %i0, %o0
a015c0c4:  9f c6 40 00  call  %i1
a015c0c8:  01 00 00 00  nop
a015c0cc:  a6 14 c0 08  or  %l3, %o0, %l3
a015c0d0:  da 14 20 0c  lduh  [ %l0 + 0xc ], %o5
a015c0d4:  80 8b 62 00  btst  0x200, %o5
a015c0d8:  02 80 00 0b  be  0xa015c104
a015c0dc:  90 04 20 58  add  %l0, 0x58, %o0
a015c0e0:  a0 04 20 cc  add  %l0, 0xcc, %l0
a015c0e4:  a2 84 7f ff  addcc  %l1, -1, %l1
a015c0e8:  3c bf ff e7  bpos,a   0xa015c084
a015c0ec:  da 14 20 0c  lduh  [ %l0 + 0xc ], %o5
a015c0f0:  e4 04 80 00  ld  [ %l2 ], %l2
a015c0f4:  80 a4 a0 00  cmp  %l2, 0
a015c0f8:  32 bf ff df  bne,a   0xa015c074
a015c0fc:  e2 04 a0 04  ld  [ %l2 + 4 ], %l1
a015c100:  30 80 00 09  b,a   0xa015c124
a015c104:  40 00 0a 59  call  0xa015ea68
a015c108:  a0 04 20 cc  add  %l0, 0xcc, %l0
a015c10c:  10 bf ff f7  b  0xa015c0e8
a015c110:  a2 84 7f ff  addcc  %l1, -1, %l1
a015c114:  40 00 0a 3d  call  0xa015ea08
a015c118:  01 00 00 00  nop
a015c11c:  10 bf ff e1  b  0xa015c0a0
a015c120:  da 14 20 0c  lduh  [ %l0 + 0xc ], %o5
a015c124:  7f ff fd 3a  call  0xa015b60c
a015c128:  b0 10 00 13  mov  %l3, %i0
a015c12c:  01 00 00 00  nop
a015c130:  81 c7 e0 08  ret
a015c134:  81 e8 00 00  restore
