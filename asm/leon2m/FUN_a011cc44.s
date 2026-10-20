# leon2m FUN_a011cc44 0xa011cc44-0xa011cca0 (92 bytes)
a011cc44:  96 0a 20 ff  and  %o0, 0xff, %o3
a011cc48:  80 a2 e0 02  cmp  %o3, 2
a011cc4c:  98 40 20 00  addx  %g0, 0, %o4
a011cc50:  82 20 00 0c  neg  %o4, %g1
a011cc54:  9a 0a c0 01  and  %o3, %g1, %o5
a011cc58:  19 2a 00 9e  sethi  %hi(0xa8027800), %o4
a011cc5c:  82 13 22 a8  or  %o4, 0x2a8, %g1	! 0xa8027aa8
a011cc60:  90 03 40 0d  add  %o5, %o5, %o0
a011cc64:  da 10 40 08  lduh  [ %g1 + %o0 ], %o5
a011cc68:  96 03 60 cc  add  %o5, 0xcc, %o3
a011cc6c:  99 2a e0 02  sll  %o3, 2, %o4
a011cc70:  90 03 60 cd  add  %o5, 0xcd, %o0
a011cc74:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a011cc78:  9b 2a 20 02  sll  %o0, 2, %o5
a011cc7c:  82 0a 60 ff  and  %o1, 0xff, %g1
a011cc80:  98 13 00 0b  or  %o4, %o3, %o4
a011cc84:  91 2a 60 10  sll  %o1, 0x10, %o0
a011cc88:  c2 23 00 00  st  %g1, [ %o4 ]
a011cc8c:  9a 13 40 0b  or  %o5, %o3, %o5
a011cc90:  93 32 20 18  srl  %o0, 0x18, %o1
a011cc94:  d2 23 40 00  st  %o1, [ %o5 ]
a011cc98:  81 c3 e0 08  retl
a011cc9c:  01 00 00 00  nop
