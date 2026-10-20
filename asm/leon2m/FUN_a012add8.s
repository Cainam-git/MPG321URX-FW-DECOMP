# leon2m FUN_a012add8 0xa012add8-0xa012af40 (360 bytes)
a012add8:  9d e3 bf 80  save  %sp, -128, %sp
a012addc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a012ade0:  23 2a 00 b8  sethi  %hi(0xa802e000), %l1
a012ade4:  92 14 61 a0  or  %l1, 0x1a0, %o1	! 0xa802e1a0
a012ade8:  95 2e 20 02  sll  %i0, 2, %o2
a012adec:  a4 10 20 0f  mov  0xf, %l2
a012adf0:  e0 0a 60 2c  ldub  [ %o1 + 0x2c ], %l0
a012adf4:  91 2c 80 0a  sll  %l2, %o2, %o0
a012adf8:  a6 2c 00 08  andn  %l0, %o0, %l3
a012adfc:  25 2a 00 b6  sethi  %hi(0xa802d800), %l2
a012ae00:  96 14 a0 ae  or  %l2, 0xae, %o3	! 0xa802d8ae
a012ae04:  a0 5e 20 16  smul  %i0, 0x16, %l0
a012ae08:  99 2e 40 0a  sll  %i1, %o2, %o4
a012ae0c:  9a 04 00 0b  add  %l0, %o3, %o5
a012ae10:  82 14 c0 0c  or  %l3, %o4, %g1
a012ae14:  f2 2b 60 02  stb  %i1, [ %o5 + 2 ]
a012ae18:  9f 2e 20 03  sll  %i0, 3, %o7
a012ae1c:  90 06 40 19  add  %i1, %i1, %o0
a012ae20:  c2 2a 60 2c  stb  %g1, [ %o1 + 0x2c ]
a012ae24:  80 a6 60 02  cmp  %i1, 2
a012ae28:  18 80 00 0b  bgu  0xa012ae54
a012ae2c:  a6 10 00 0b  mov  %o3, %l3
a012ae30:  d4 0a 60 2f  ldub  [ %o1 + 0x2f ], %o2
a012ae34:  9b 2a a0 08  sll  %o2, 8, %o5
a012ae38:  d8 0a 60 30  ldub  [ %o1 + 0x30 ], %o4
a012ae3c:  82 13 00 0d  or  %o4, %o5, %g1
a012ae40:  97 38 40 0f  sra  %g1, %o7, %o3
a012ae44:  94 0a e0 ff  and  %o3, 0xff, %o2
a012ae48:  93 3a 80 08  sra  %o2, %o0, %o1
a012ae4c:  10 80 00 06  b  0xa012ae64
a012ae50:  9e 0a 60 03  and  %o1, 3, %o7
a012ae54:  de 0a 60 31  ldub  [ %o1 + 0x31 ], %o7
a012ae58:  91 3b c0 0a  sra  %o7, %o2, %o0
a012ae5c:  9e 0a 20 0f  and  %o0, 0xf, %o7
a012ae60:  90 06 40 19  add  %i1, %i1, %o0
a012ae64:  82 14 61 a0  or  %l1, 0x1a0, %g1
a012ae68:  e2 00 60 2c  ld  [ %g1 + 0x2c ], %l1
a012ae6c:  99 2c 60 08  sll  %l1, 8, %o4
a012ae70:  9b 33 20 10  srl  %o4, 0x10, %o5
a012ae74:  95 2e 20 03  sll  %i0, 3, %o2
a012ae78:  d6 08 60 33  ldub  [ %g1 + 0x33 ], %o3
a012ae7c:  e2 08 60 32  ldub  [ %g1 + 0x32 ], %l1
a012ae80:  99 3b 40 0a  sra  %o5, %o2, %o4
a012ae84:  93 2e 20 02  sll  %i0, 2, %o1
a012ae88:  95 3a c0 09  sra  %o3, %o1, %o2
a012ae8c:  9b 3c 40 09  sra  %l1, %o1, %o5
a012ae90:  a2 0a a0 0f  and  %o2, 0xf, %l1
a012ae94:  82 0b 60 0f  and  %o5, 0xf, %g1
a012ae98:  97 3c 40 19  sra  %l1, %i1, %o3
a012ae9c:  9b 38 40 19  sra  %g1, %i1, %o5
a012aea0:  92 0b 20 ff  and  %o4, 0xff, %o1
a012aea4:  99 3a 40 08  sra  %o1, %o0, %o4
a012aea8:  a2 14 a0 ae  or  %l2, 0xae, %l1
a012aeac:  b2 5e 20 16  smul  %i0, 0x16, %i1
a012aeb0:  82 06 40 11  add  %i1, %l1, %g1
a012aeb4:  90 0b 20 03  and  %o4, 3, %o0
a012aeb8:  94 0b 60 01  and  %o5, 1, %o2
a012aebc:  92 0a e0 01  and  %o3, 1, %o1
a012aec0:  de 2c c0 10  stb  %o7, [ %l3 + %l0 ]
a012aec4:  d4 28 60 07  stb  %o2, [ %g1 + 7 ]
a012aec8:  d2 28 60 06  stb  %o1, [ %g1 + 6 ]
a012aecc:  d0 28 60 01  stb  %o0, [ %g1 + 1 ]
a012aed0:  e4 14 40 19  lduh  [ %l1 + %i1 ], %l2
a012aed4:  d2 10 60 0a  lduh  [ %g1 + 0xa ], %o1
a012aed8:  d0 10 60 0c  lduh  [ %g1 + 0xc ], %o0
a012aedc:  f2 10 60 14  lduh  [ %g1 + 0x14 ], %i1
a012aee0:  da 10 60 02  lduh  [ %g1 + 2 ], %o5
a012aee4:  d8 10 60 04  lduh  [ %g1 + 4 ], %o4
a012aee8:  d6 10 60 06  lduh  [ %g1 + 6 ], %o3
a012aeec:  d4 10 60 08  lduh  [ %g1 + 8 ], %o2
a012aef0:  e0 10 60 0e  lduh  [ %g1 + 0xe ], %l0
a012aef4:  e6 10 60 10  lduh  [ %g1 + 0x10 ], %l3
a012aef8:  e2 10 60 12  lduh  [ %g1 + 0x12 ], %l1
a012aefc:  d2 37 bf ea  sth  %o1, [ %fp + -22 ]
a012af00:  d0 37 bf ec  sth  %o0, [ %fp + -20 ]
a012af04:  e4 37 bf e0  sth  %l2, [ %fp + -32 ]
a012af08:  da 37 bf e2  sth  %o5, [ %fp + -30 ]
a012af0c:  d8 37 bf e4  sth  %o4, [ %fp + -28 ]
a012af10:  d6 37 bf e6  sth  %o3, [ %fp + -26 ]
a012af14:  d4 37 bf e8  sth  %o2, [ %fp + -24 ]
a012af18:  e0 37 bf ee  sth  %l0, [ %fp + -18 ]
a012af1c:  e6 37 bf f0  sth  %l3, [ %fp + -16 ]
a012af20:  e2 37 bf f2  sth  %l1, [ %fp + -14 ]
a012af24:  f2 37 bf f4  sth  %i1, [ %fp + -12 ]
a012af28:  90 10 00 18  mov  %i0, %o0
a012af2c:  40 00 32 cf  call  0xa0137a68
a012af30:  92 07 bf e0  add  %fp, -32, %o1
a012af34:  01 00 00 00  nop
a012af38:  81 c7 e0 08  ret
a012af3c:  81 e8 00 00  restore
