# leon2m FUN_a0093bac 0xa0093bac-0xa0093d30 (388 bytes)
a0093bac:  9d e3 bf 98  save  %sp, -104, %sp
a0093bb0:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a0093bb4:  67 ff e6 78  call  0x4008d594
a0093bb8:  d0 14 a0 34  lduh  [ %l2 + 0x34 ], %o0	! 0xa802d034
a0093bbc:  83 2a 20 10  sll  %o0, 0x10, %g1
a0093bc0:  91 30 60 10  srl  %g1, 0x10, %o0
a0093bc4:  80 a2 20 64  cmp  %o0, 0x64
a0093bc8:  a8 10 00 12  mov  %l2, %l4
a0093bcc:  27 2a 00 b3  sethi  %hi(0xa802cc00), %l3
a0093bd0:  18 80 00 4a  bgu  0xa0093cf8
a0093bd4:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a0093bd8:  40 02 ce d3  call  0xa0147724
a0093bdc:  a0 14 e3 f4  or  %l3, 0x3f4, %l0
a0093be0:  d6 0c 20 08  ldub  [ %l0 + 8 ], %o3
a0093be4:  95 32 e0 04  srl  %o3, 4, %o2
a0093be8:  80 a2 a0 02  cmp  %o2, 2
a0093bec:  02 80 00 06  be  0xa0093c04
a0093bf0:  d0 35 20 34  sth  %o0, [ %l4 + 0x34 ]
a0093bf4:  98 10 20 28  mov  0x28, %o4
a0093bf8:  40 02 ce cb  call  0xa0147724
a0093bfc:  d8 2c 20 08  stb  %o4, [ %l0 + 8 ]
a0093c00:  d0 34 60 3a  sth  %o0, [ %l1 + 0x3a ]
a0093c04:  67 ff e6 64  call  0x4008d594
a0093c08:  d0 14 60 3a  lduh  [ %l1 + 0x3a ], %o0
a0093c0c:  91 2a 20 10  sll  %o0, 0x10, %o0
a0093c10:  9f 32 20 10  srl  %o0, 0x10, %o7
a0093c14:  80 a3 e7 d0  cmp  %o7, 0x7d0
a0093c18:  18 80 00 2f  bgu  0xa0093cd4
a0093c1c:  01 00 00 00  nop
a0093c20:  67 ff e6 5d  call  0x4008d594
a0093c24:  d0 14 60 3a  lduh  [ %l1 + 0x3a ], %o0
a0093c28:  95 2a 20 10  sll  %o0, 0x10, %o2
a0093c2c:  13 00 00 04  sethi  %hi(0x1000), %o1
a0093c30:  a3 32 a0 10  srl  %o2, 0x10, %l1
a0093c34:  a0 12 63 88  or  %o1, 0x388, %l0
a0093c38:  80 a4 40 10  cmp  %l1, %l0
a0093c3c:  18 80 00 1b  bgu  0xa0093ca8
a0093c40:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0093c44:  94 12 22 90  or  %o0, 0x290, %o2	! 0xa802d290
a0093c48:  c2 0a a0 31  ldub  [ %o2 + 0x31 ], %g1
a0093c4c:  80 a0 60 00  cmp  %g1, 0
a0093c50:  22 80 00 08  be,a   0xa0093c70
a0093c54:  82 14 e3 f4  or  %l3, 0x3f4, %g1
a0093c58:  80 a0 60 01  cmp  %g1, 1
a0093c5c:  02 80 00 04  be  0xa0093c6c
a0093c60:  80 a0 60 02  cmp  %g1, 2
a0093c64:  12 80 00 2b  bne  0xa0093d10
a0093c68:  01 00 00 00  nop
a0093c6c:  82 14 e3 f4  or  %l3, 0x3f4, %g1
a0093c70:  e8 08 60 08  ldub  [ %g1 + 8 ], %l4
a0093c74:  a6 0d 20 0f  and  %l4, 0xf, %l3
a0093c78:  d8 12 a0 54  lduh  [ %o2 + 0x54 ], %o4
a0093c7c:  80 a4 c0 0c  cmp  %l3, %o4
a0093c80:  18 80 00 05  bgu  0xa0093c94
a0093c84:  82 0c e0 ff  and  %l3, 0xff, %g1
a0093c88:  82 23 00 01  sub  %o4, %g1, %g1
a0093c8c:  10 80 00 21  b  0xa0093d10
a0093c90:  c2 32 a0 54  sth  %g1, [ %o2 + 0x54 ]
a0093c94:  80 a3 20 01  cmp  %o4, 1
a0093c98:  08 80 00 1e  bleu  0xa0093d10
a0093c9c:  82 03 3f fe  add  %o4, -2, %g1
a0093ca0:  10 80 00 1c  b  0xa0093d10
a0093ca4:  c2 32 a0 54  sth  %g1, [ %o2 + 0x54 ]
a0093ca8:  67 ff e6 3b  call  0x4008d594
a0093cac:  d0 14 a0 34  lduh  [ %l2 + 0x34 ], %o0
a0093cb0:  97 2a 20 10  sll  %o0, 0x10, %o3
a0093cb4:  a5 32 e0 10  srl  %o3, 0x10, %l2
a0093cb8:  80 a4 a0 63  cmp  %l2, 0x63
a0093cbc:  18 bf ff e2  bgu  0xa0093c44
a0093cc0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0093cc4:  98 14 e3 f4  or  %l3, 0x3f4, %o4
a0093cc8:  9e 10 20 28  mov  0x28, %o7
a0093ccc:  10 bf ff de  b  0xa0093c44
a0093cd0:  de 2b 20 08  stb  %o7, [ %o4 + 8 ]
a0093cd4:  67 ff e6 30  call  0x4008d594
a0093cd8:  d0 15 20 34  lduh  [ %l4 + 0x34 ], %o0
a0093cdc:  83 2a 20 10  sll  %o0, 0x10, %g1
a0093ce0:  a9 30 60 10  srl  %g1, 0x10, %l4
a0093ce4:  80 a5 20 63  cmp  %l4, 0x63
a0093ce8:  18 bf ff ce  bgu  0xa0093c20
a0093cec:  9a 10 20 28  mov  0x28, %o5
a0093cf0:  10 bf ff cc  b  0xa0093c20
a0093cf4:  da 2c 20 08  stb  %o5, [ %l0 + 8 ]
a0093cf8:  9a 14 e3 f4  or  %l3, 0x3f4, %o5
a0093cfc:  92 10 20 28  mov  0x28, %o1
a0093d00:  40 02 ce 89  call  0xa0147724
a0093d04:  d2 2b 60 08  stb  %o1, [ %o5 + 8 ]
a0093d08:  10 bf ff b4  b  0xa0093bd8
a0093d0c:  d0 34 60 3a  sth  %o0, [ %l1 + 0x3a ]
a0093d10:  40 01 0f 58  call  0xa00d7a70
a0093d14:  90 10 20 00  clr  %o0
a0093d18:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a0093d1c:  e2 0b 60 8e  ldub  [ %o5 + 0x8e ], %l1	! 0xa802b08e
a0093d20:  a0 14 60 02  or  %l1, 2, %l0
a0093d24:  e0 2b 60 8e  stb  %l0, [ %o5 + 0x8e ]
a0093d28:  81 c7 e0 08  ret
a0093d2c:  81 e8 00 00  restore
