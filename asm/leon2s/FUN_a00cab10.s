# leon2s FUN_a00cab10 0xa00cab10-0xa00cad8c (636 bytes)  [FUN_a00cad84 = unreachable ret/restore tail, merged]
a00cab10:  9d e3 bf 98  save  %sp, -104, %sp
a00cab14:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cab18:  82 06 00 18  add  %i0, %i0, %g1
a00cab1c:  82 00 40 18  add  %g1, %i0, %g1
a00cab20:  33 2a 01 e2  sethi  %hi(0xa8078800), %i1
a00cab24:  99 28 60 03  sll  %g1, 3, %o4
a00cab28:  96 16 63 b0  or  %i1, 0x3b0, %o3
a00cab2c:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00cab30:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cab34:  82 2b 40 01  andn  %o5, %g1, %g1
a00cab38:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cab3c:  82 10 40 0d  or  %g1, %o5, %g1
a00cab40:  9b 30 60 13  srl  %g1, 0x13, %o5
a00cab44:  80 8b 60 01  btst  1, %o5
a00cab48:  12 80 00 1f  bne  0xa00cabc4
a00cab4c:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cab50:  82 03 00 0b  add  %o4, %o3, %g1
a00cab54:  7f ff fc bc  call  0xa00c9e44
a00cab58:  d0 08 60 09  ldub  [ %g1 + 9 ], %o0
a00cab5c:  a0 10 20 00  clr  %l0
a00cab60:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a00cab64:  98 0c 20 ff  and  %l0, 0xff, %o4
a00cab68:  9a 13 63 08  or  %o5, 0x308, %o5
a00cab6c:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a00cab70:  9a 03 00 0d  add  %o4, %o5, %o5
a00cab74:  82 10 60 88  or  %g1, 0x88, %g1
a00cab78:  d8 08 40 0c  ldub  [ %g1 + %o4 ], %o4
a00cab7c:  a0 04 20 01  inc  %l0
a00cab80:  c2 0b 61 60  ldub  [ %o5 + 0x160 ], %g1
a00cab84:  80 a3 00 01  cmp  %o4, %g1
a00cab88:  02 80 00 0c  be  0xa00cabb8
a00cab8c:  96 0c 20 ff  and  %l0, 0xff, %o3
a00cab90:  9a 06 00 18  add  %i0, %i0, %o5
a00cab94:  9a 03 40 18  add  %o5, %i0, %o5
a00cab98:  96 16 63 b0  or  %i1, 0x3b0, %o3
a00cab9c:  9b 2b 60 03  sll  %o5, 3, %o5
a00caba0:  d8 02 c0 0d  ld  [ %o3 + %o5 ], %o4
a00caba4:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00caba8:  82 2b 00 01  andn  %o4, %g1, %g1
a00cabac:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a00cabb0:  7f ff f3 86  call  0xa00c79c8
a00cabb4:  81 e8 00 00  restore
a00cabb8:  80 a2 e0 1f  cmp  %o3, 0x1f
a00cabbc:  08 bf ff ea  bleu  0xa00cab64
a00cabc0:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a00cabc4:  98 06 00 18  add  %i0, %i0, %o4
a00cabc8:  98 03 00 18  add  %o4, %i0, %o4
a00cabcc:  94 16 63 b0  or  %i1, 0x3b0, %o2
a00cabd0:  99 2b 20 03  sll  %o4, 3, %o4
a00cabd4:  da 02 80 0c  ld  [ %o2 + %o4 ], %o5
a00cabd8:  03 00 02 00  sethi  %hi(0x80000), %g1
a00cabdc:  9a 13 40 01  or  %o5, %g1, %o5
a00cabe0:  03 08 00 00  sethi  %hi(0x20000000), %g1
a00cabe4:  9a 13 40 01  or  %o5, %g1, %o5
a00cabe8:  97 2e 20 02  sll  %i0, 2, %o3
a00cabec:  23 2a 01 f3  sethi  %hi(0xa807cc00), %l1
a00cabf0:  96 02 c0 18  add  %o3, %i0, %o3
a00cabf4:  82 14 62 38  or  %l1, 0x238, %g1
a00cabf8:  da 22 80 0c  st  %o5, [ %o2 + %o4 ]
a00cabfc:  94 02 c0 01  add  %o3, %g1, %o2
a00cac00:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cac04:  82 10 61 a8  or  %g1, 0x1a8, %g1	! 0xa807cda8
a00cac08:  96 02 c0 01  add  %o3, %g1, %o3
a00cac0c:  a0 10 20 00  clr  %l0
a00cac10:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cac14:  da 0a 80 01  ldub  [ %o2 + %g1 ], %o5
a00cac18:  a0 04 20 01  inc  %l0
a00cac1c:  c2 0a c0 01  ldub  [ %o3 + %g1 ], %g1
a00cac20:  80 a0 40 0d  cmp  %g1, %o5
a00cac24:  12 80 00 36  bne  0xa00cacfc
a00cac28:  98 0c 20 ff  and  %l0, 0xff, %o4
a00cac2c:  80 a3 20 04  cmp  %o4, 4
a00cac30:  08 bf ff f9  bleu  0xa00cac14
a00cac34:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cac38:  a0 10 20 00  clr  %l0
a00cac3c:  9b 2e 20 02  sll  %i0, 2, %o5
a00cac40:  94 0c 20 ff  and  %l0, 0xff, %o2
a00cac44:  82 14 62 38  or  %l1, 0x238, %g1
a00cac48:  9a 03 40 18  add  %o5, %i0, %o5
a00cac4c:  9a 03 40 01  add  %o5, %g1, %o5
a00cac50:  94 02 a0 10  add  %o2, 0x10, %o2
a00cac54:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cac58:  95 2a a0 10  sll  %o2, 0x10, %o2
a00cac5c:  d6 0b 40 01  ldub  [ %o5 + %g1 ], %o3
a00cac60:  95 32 a0 10  srl  %o2, 0x10, %o2
a00cac64:  90 10 00 18  mov  %i0, %o0
a00cac68:  40 3b b4 fb  call  0xa0fb8054
a00cac6c:  92 10 20 00  clr  %o1
a00cac70:  a0 04 20 01  inc  %l0
a00cac74:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cac78:  80 a0 60 04  cmp  %g1, 4
a00cac7c:  08 bf ff f1  bleu  0xa00cac40
a00cac80:  9b 2e 20 02  sll  %i0, 2, %o5
a00cac84:  90 10 00 18  mov  %i0, %o0
a00cac88:  92 10 20 03  mov  3, %o1
a00cac8c:  7f ff f6 d7  call  0xa00c87e8
a00cac90:  15 00 00 20  sethi  %hi(0x8000), %o2
a00cac94:  a0 10 3f 8b  mov  -117, %l0
a00cac98:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cac9c:  b2 10 62 50  or  %g1, 0x250, %i1	! 0xa807ce50
a00caca0:  82 0c 20 ff  and  %l0, 0xff, %g1
a00caca4:  d4 0e 40 01  ldub  [ %i1 + %g1 ], %o2
a00caca8:  90 10 00 18  mov  %i0, %o0
a00cacac:  7f ff f2 6a  call  0xa00c7654
a00cacb0:  92 10 20 01  mov  1, %o1
a00cacb4:  a0 04 20 01  inc  %l0
a00cacb8:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cacbc:  80 a0 60 95  cmp  %g1, 0x95
a00cacc0:  28 bf ff f7  bleu,a   0xa00cac9c
a00cacc4:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cacc8:  c2 0e 60 93  ldub  [ %i1 + 0x93 ], %g1
a00caccc:  80 a0 60 02  cmp  %g1, 2
a00cacd0:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00cacd4:  02 80 00 13  be  0xa00cad20
a00cacd8:  82 06 00 18  add  %i0, %i0, %g1
a00cacdc:  9a 00 40 18  add  %g1, %i0, %o5
a00cace0:  96 12 e3 b0  or  %o3, 0x3b0, %o3
a00cace4:  9b 2b 60 03  sll  %o5, 3, %o5
a00cace8:  d8 02 c0 0d  ld  [ %o3 + %o5 ], %o4
a00cacec:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cacf0:  82 2b 00 01  andn  %o4, %g1, %g1
a00cacf4:  10 80 00 23  b  0xa00cad80
a00cacf8:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a00cacfc:  9a 06 00 18  add  %i0, %i0, %o5
a00cad00:  9a 03 40 18  add  %o5, %i0, %o5
a00cad04:  96 16 63 b0  or  %i1, 0x3b0, %o3
a00cad08:  9b 2b 60 03  sll  %o5, 3, %o5
a00cad0c:  d8 02 c0 0d  ld  [ %o3 + %o5 ], %o4
a00cad10:  03 08 00 00  sethi  %hi(0x20000000), %g1
a00cad14:  82 2b 00 01  andn  %o4, %g1, %g1
a00cad18:  10 bf ff c8  b  0xa00cac38
a00cad1c:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a00cad20:  82 00 40 18  add  %g1, %i0, %g1
a00cad24:  91 28 60 03  sll  %g1, 3, %o0
a00cad28:  96 12 e3 b0  or  %o3, 0x3b0, %o3
a00cad2c:  da 02 c0 08  ld  [ %o3 + %o0 ], %o5
a00cad30:  03 04 00 00  sethi  %hi(0x10000000), %g1
a00cad34:  9a 2b 40 01  andn  %o5, %g1, %o5
a00cad38:  c2 0e 60 95  ldub  [ %i1 + 0x95 ], %g1
a00cad3c:  80 a0 60 01  cmp  %g1, 1
a00cad40:  12 80 00 05  bne  0xa00cad54
a00cad44:  da 22 c0 08  st  %o5, [ %o3 + %o0 ]
a00cad48:  03 04 00 00  sethi  %hi(0x10000000), %g1
a00cad4c:  82 13 40 01  or  %o5, %g1, %g1
a00cad50:  c2 22 c0 08  st  %g1, [ %o3 + %o0 ]
a00cad54:  a0 02 00 0b  add  %o0, %o3, %l0
a00cad58:  92 06 60 06  add  %i1, 6, %o1
a00cad5c:  d0 0c 20 09  ldub  [ %l0 + 9 ], %o0
a00cad60:  7f ff fb ce  call  0xa00c9c98
a00cad64:  94 10 24 00  mov  0x400, %o2
a00cad68:  d0 0c 20 09  ldub  [ %l0 + 9 ], %o0
a00cad6c:  7f ff fb 7b  call  0xa00c9b58
a00cad70:  92 10 24 00  mov  0x400, %o1
a00cad74:  f0 0c 20 09  ldub  [ %l0 + 9 ], %i0
a00cad78:  7f ff fc 1c  call  0xa00c9de8
a00cad7c:  93 e8 24 00  restore  %g0, 0x400, %o1
a00cad80:  01 00 00 00  nop
a00cad84:  81 c7 e0 08  ret
a00cad88:  81 e8 00 00  restore
