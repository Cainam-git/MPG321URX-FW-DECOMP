# leon2m FUN_a0105d58 0xa0105d58-0xa0105e60 (264 bytes)
a0105d58:  9d e3 bf 98  save  %sp, -104, %sp
a0105d5c:  b5 2e a0 10  sll  %i2, 0x10, %i2
a0105d60:  92 10 00 18  mov  %i0, %o1
a0105d64:  03 00 06 69  sethi  %hi(0x19a400), %g1
a0105d68:  1b 33 33 33  sethi  %hi(0xcccccc00), %o5
a0105d6c:  94 10 62 40  or  %g1, 0x240, %o2
a0105d70:  96 13 60 cd  or  %o5, 0xcd, %o3
a0105d74:  b0 10 20 00  clr  %i0
a0105d78:  90 10 20 00  clr  %o0
a0105d7c:  9e 10 20 00  clr  %o7
a0105d80:  a1 36 a0 10  srl  %i2, 0x10, %l0
a0105d84:  83 2b e0 03  sll  %o7, 3, %g1
a0105d88:  98 00 40 0f  add  %g1, %o7, %o4
a0105d8c:  9a 03 00 0c  add  %o4, %o4, %o5
a0105d90:  98 03 40 0a  add  %o5, %o2, %o4
a0105d94:  da 13 20 06  lduh  [ %o4 + 6 ], %o5
a0105d98:  83 2b 60 10  sll  %o5, 0x10, %g1
a0105d9c:  83 30 60 10  srl  %g1, 0x10, %g1
a0105da0:  80 50 40 0b  umul  %g1, %o3, %g0
a0105da4:  83 40 00 00  rd  %y, %g1
a0105da8:  9a 23 40 09  sub  %o5, %o1, %o5
a0105dac:  9b 2b 60 10  sll  %o5, 0x10, %o5
a0105db0:  83 28 60 0d  sll  %g1, 0xd, %g1
a0105db4:  9b 33 60 10  srl  %o5, 0x10, %o5
a0105db8:  83 30 60 10  srl  %g1, 0x10, %g1
a0105dbc:  80 a3 40 01  cmp  %o5, %g1
a0105dc0:  1a 80 00 15  bcc  0xa0105e14
a0105dc4:  90 02 20 01  inc  %o0
a0105dc8:  da 13 20 0e  lduh  [ %o4 + 0xe ], %o5
a0105dcc:  83 2b 60 10  sll  %o5, 0x10, %g1
a0105dd0:  83 30 60 10  srl  %g1, 0x10, %g1
a0105dd4:  80 50 40 0b  umul  %g1, %o3, %g0
a0105dd8:  83 40 00 00  rd  %y, %g1
a0105ddc:  9a 23 40 19  sub  %o5, %i1, %o5
a0105de0:  9b 2b 60 10  sll  %o5, 0x10, %o5
a0105de4:  83 28 60 0d  sll  %g1, 0xd, %g1
a0105de8:  9b 33 60 10  srl  %o5, 0x10, %o5
a0105dec:  83 30 60 10  srl  %g1, 0x10, %g1
a0105df0:  80 a3 40 01  cmp  %o5, %g1
a0105df4:  3a 80 00 09  bcc,a   0xa0105e18
a0105df8:  9e 0a 20 ff  and  %o0, 0xff, %o7
a0105dfc:  c2 13 20 10  lduh  [ %o4 + 0x10 ], %g1
a0105e00:  9a 20 40 10  sub  %g1, %l0, %o5
a0105e04:  98 03 60 09  add  %o5, 9, %o4
a0105e08:  80 a3 20 12  cmp  %o4, 0x12
a0105e0c:  28 80 00 08  bleu,a   0xa0105e2c
a0105e10:  b0 10 20 01  mov  1, %i0
a0105e14:  9e 0a 20 ff  and  %o0, 0xff, %o7
a0105e18:  80 a3 e0 07  cmp  %o7, 7
a0105e1c:  08 bf ff db  bleu  0xa0105d88
a0105e20:  83 2b e0 03  sll  %o7, 3, %g1
a0105e24:  10 80 00 03  b  0xa0105e30
a0105e28:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0105e2c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0105e30:  93 2a 60 10  sll  %o1, 0x10, %o1
a0105e34:  95 2e 60 10  sll  %i1, 0x10, %o2
a0105e38:  11 00 06 6a  sethi  %hi(0x19a800), %o0
a0105e3c:  90 12 20 90  or  %o0, 0x90, %o0	! 0x19a890
a0105e40:  93 32 60 10  srl  %o1, 0x10, %o1
a0105e44:  95 32 a0 10  srl  %o2, 0x10, %o2
a0105e48:  97 36 a0 10  srl  %i2, 0x10, %o3
a0105e4c:  9a 10 00 0f  mov  %o7, %o5
a0105e50:  7f ff 64 c8  call  0xa00df170
a0105e54:  98 10 00 18  mov  %i0, %o4
a0105e58:  81 c7 e0 08  ret
a0105e5c:  81 e8 00 00  restore
