# leon2m FUN_a013bbb8 0xa013bbb8-0xa013bc5c (164 bytes)
a013bbb8:  9d e3 bf 98  save  %sp, -104, %sp
a013bbbc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a013bbc0:  40 00 04 63  call  0xa013cd4c
a013bbc4:  90 10 00 18  mov  %i0, %o0
a013bbc8:  da 12 20 28  lduh  [ %o0 + 0x28 ], %o5
a013bbcc:  93 2b 60 10  sll  %o5, 0x10, %o1
a013bbd0:  a0 10 00 08  mov  %o0, %l0
a013bbd4:  83 32 60 10  srl  %o1, 0x10, %g1
a013bbd8:  90 10 00 18  mov  %i0, %o0
a013bbdc:  80 a0 60 32  cmp  %g1, 0x32
a013bbe0:  08 80 00 03  bleu  0xa013bbec
a013bbe4:  94 10 00 0d  mov  %o5, %o2
a013bbe8:  9a 10 20 32  mov  0x32, %o5
a013bbec:  d6 14 20 2a  lduh  [ %l0 + 0x2a ], %o3
a013bbf0:  83 2a e0 10  sll  %o3, 0x10, %g1
a013bbf4:  98 02 80 0d  add  %o2, %o5, %o4
a013bbf8:  9f 30 60 10  srl  %g1, 0x10, %o7
a013bbfc:  9a 22 80 0d  sub  %o2, %o5, %o5
a013bc00:  80 a3 e0 32  cmp  %o7, 0x32
a013bc04:  da 34 20 2e  sth  %o5, [ %l0 + 0x2e ]
a013bc08:  d8 34 20 30  sth  %o4, [ %l0 + 0x30 ]
a013bc0c:  08 80 00 03  bleu  0xa013bc18
a013bc10:  82 10 00 0b  mov  %o3, %g1
a013bc14:  82 10 20 32  mov  0x32, %g1
a013bc18:  94 02 c0 01  add  %o3, %g1, %o2
a013bc1c:  92 22 c0 01  sub  %o3, %g1, %o1
a013bc20:  d2 34 20 32  sth  %o1, [ %l0 + 0x32 ]
a013bc24:  d4 34 20 34  sth  %o2, [ %l0 + 0x34 ]
a013bc28:  7f ff 95 8c  call  0xa0121258
a013bc2c:  c0 34 20 36  clrh  [ %l0 + 0x36 ]
a013bc30:  80 8a 20 ff  btst  0xff, %o0
a013bc34:  22 80 00 04  be,a   0xa013bc44
a013bc38:  c2 14 20 10  lduh  [ %l0 + 0x10 ], %g1
a013bc3c:  d0 14 20 10  lduh  [ %l0 + 0x10 ], %o0
a013bc40:  82 02 00 08  add  %o0, %o0, %g1
a013bc44:  d8 14 20 18  lduh  [ %l0 + 0x18 ], %o4
a013bc48:  b0 20 40 0c  sub  %g1, %o4, %i0
a013bc4c:  96 06 3f fd  add  %i0, -3, %o3
a013bc50:  d6 34 20 38  sth  %o3, [ %l0 + 0x38 ]
a013bc54:  81 c7 e0 08  ret
a013bc58:  81 e8 00 00  restore
