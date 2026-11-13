# leon2m FUN_a012b9a8 0xa012b9a8-0xa012bae0 (312 bytes)
a012b9a8:  9d e3 bf 98  save  %sp, -104, %sp
a012b9ac:  7f ff d6 2b  call  0xa0121258
a012b9b0:  90 0e 20 ff  and  %i0, 0xff, %o0
a012b9b4:  7f ff 6a 1d  call  0xa0106228
a012b9b8:  01 00 00 00  nop
a012b9bc:  82 0a 20 ff  and  %o0, 0xff, %g1
a012b9c0:  80 a0 60 04  cmp  %g1, 4
a012b9c4:  02 80 00 22  be  0xa012ba4c
a012b9c8:  90 10 20 04  mov  4, %o0
a012b9cc:  7f ff 7b a6  call  0xa010a864
a012b9d0:  01 00 00 00  nop
a012b9d4:  80 8a 20 ff  btst  0xff, %o0
a012b9d8:  12 80 00 12  bne  0xa012ba20
a012b9dc:  90 10 20 00  clr  %o0
a012b9e0:  7f ff 6b c0  call  0xa01068e0
a012b9e4:  01 00 00 00  nop
a012b9e8:  d0 36 40 00  sth  %o0, [ %i1 ]
a012b9ec:  7f ff 6b c5  call  0xa0106900
a012b9f0:  90 10 20 00  clr  %o0
a012b9f4:  d0 36 60 02  sth  %o0, [ %i1 + 2 ]
a012b9f8:  7f ff 6a 32  call  0xa01062c0
a012b9fc:  90 10 20 00  clr  %o0
a012ba00:  d0 36 60 04  sth  %o0, [ %i1 + 4 ]
a012ba04:  90 10 20 00  clr  %o0
a012ba08:  7f ff 6a 1b  call  0xa0106274
a012ba0c:  01 00 00 00  nop
a012ba10:  96 10 00 08  mov  %o0, %o3
a012ba14:  d0 36 60 06  sth  %o0, [ %i1 + 6 ]
a012ba18:  10 80 00 18  b  0xa012ba78
a012ba1c:  d0 16 60 02  lduh  [ %i1 + 2 ], %o0
a012ba20:  7f ff 7a 9d  call  0xa010a494
a012ba24:  01 00 00 00  nop
a012ba28:  7f ff 7b 97  call  0xa010a884
a012ba2c:  d0 36 60 04  sth  %o0, [ %i1 + 4 ]
a012ba30:  7f ff 7b b0  call  0xa010a8f0
a012ba34:  d0 36 40 00  sth  %o0, [ %i1 ]
a012ba38:  7f ff 7b ec  call  0xa010a9e8
a012ba3c:  d0 36 60 06  sth  %o0, [ %i1 + 6 ]
a012ba40:  d0 36 60 02  sth  %o0, [ %i1 + 2 ]
a012ba44:  10 80 00 0d  b  0xa012ba78
a012ba48:  d6 16 60 06  lduh  [ %i1 + 6 ], %o3
a012ba4c:  7f ff 6b a5  call  0xa01068e0
a012ba50:  01 00 00 00  nop
a012ba54:  d0 36 40 00  sth  %o0, [ %i1 ]
a012ba58:  7f ff 6b aa  call  0xa0106900
a012ba5c:  90 10 20 04  mov  4, %o0
a012ba60:  d0 36 60 02  sth  %o0, [ %i1 + 2 ]
a012ba64:  7f ff 6a 17  call  0xa01062c0
a012ba68:  90 10 20 04  mov  4, %o0
a012ba6c:  d0 36 60 04  sth  %o0, [ %i1 + 4 ]
a012ba70:  10 bf ff e6  b  0xa012ba08
a012ba74:  90 10 20 04  mov  4, %o0
a012ba78:  9b 2a e0 10  sll  %o3, 0x10, %o5
a012ba7c:  99 2a 20 10  sll  %o0, 0x10, %o4
a012ba80:  91 33 20 10  srl  %o4, 0x10, %o0
a012ba84:  93 33 60 10  srl  %o5, 0x10, %o1
a012ba88:  de 16 40 00  lduh  [ %i1 ], %o7
a012ba8c:  f0 16 60 04  lduh  [ %i1 + 4 ], %i0
a012ba90:  17 15 55 55  sethi  %hi(0x55555400), %o3
a012ba94:  94 22 00 09  sub  %o0, %o1, %o2
a012ba98:  9a 23 c0 18  sub  %o7, %i0, %o5
a012ba9c:  82 12 e1 56  or  %o3, 0x156, %g1
a012baa0:  80 5a 80 01  smul  %o2, %g1, %g0
a012baa4:  93 40 00 00  rd  %y, %o1
a012baa8:  99 3a a0 1f  sra  %o2, 0x1f, %o4
a012baac:  b1 3b 60 1f  sra  %o5, 0x1f, %i0
a012bab0:  80 5b 40 01  smul  %o5, %g1, %g0
a012bab4:  9f 40 00 00  rd  %y, %o7
a012bab8:  9a 23 c0 18  sub  %o7, %i0, %o5
a012babc:  96 22 40 0c  sub  %o1, %o4, %o3
a012bac0:  94 03 40 0d  add  %o5, %o5, %o2
a012bac4:  90 02 c0 0b  add  %o3, %o3, %o0
a012bac8:  d0 36 60 0e  sth  %o0, [ %i1 + 0xe ]
a012bacc:  d4 36 60 0a  sth  %o2, [ %i1 + 0xa ]
a012bad0:  da 36 60 08  sth  %o5, [ %i1 + 8 ]
a012bad4:  d6 36 60 0c  sth  %o3, [ %i1 + 0xc ]
a012bad8:  81 c7 e0 08  ret
a012badc:  81 e8 00 00  restore
