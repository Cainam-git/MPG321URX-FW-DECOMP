# leon2s FUN_a00cdb0c 0xa00cdb0c-0xa00cdc40 (308 bytes)
a00cdb0c:  9d e3 bf 98  save  %sp, -104, %sp
a00cdb10:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00cdb14:  82 04 00 10  add  %l0, %l0, %g1
a00cdb18:  82 00 40 10  add  %g1, %l0, %g1
a00cdb1c:  25 2a 01 e2  sethi  %hi(0xa8078800), %l2
a00cdb20:  99 28 60 03  sll  %g1, 3, %o4
a00cdb24:  96 14 a3 b0  or  %l2, 0x3b0, %o3
a00cdb28:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00cdb2c:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cdb30:  82 2b 40 01  andn  %o5, %g1, %g1
a00cdb34:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cdb38:  82 10 40 0d  or  %g1, %o5, %g1
a00cdb3c:  9b 30 60 1c  srl  %g1, 0x1c, %o5
a00cdb40:  80 8b 60 01  btst  1, %o5
a00cdb44:  12 80 00 22  bne  0xa00cdbcc
a00cdb48:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cdb4c:  82 03 00 0b  add  %o4, %o3, %g1
a00cdb50:  15 00 00 10  sethi  %hi(0x4000), %o2
a00cdb54:  c0 28 60 06  clrb  [ %g1 + 6 ]
a00cdb58:  c0 28 60 03  clrb  [ %g1 + 3 ]
a00cdb5c:  c0 28 60 04  clrb  [ %g1 + 4 ]
a00cdb60:  c0 28 60 05  clrb  [ %g1 + 5 ]
a00cdb64:  94 12 a0 15  or  %o2, 0x15, %o2
a00cdb68:  90 10 00 10  mov  %l0, %o0
a00cdb6c:  7f ff eb 1f  call  0xa00c87e8
a00cdb70:  92 10 20 0b  mov  0xb, %o1
a00cdb74:  a2 10 20 00  clr  %l1
a00cdb78:  03 00 00 18  sethi  %hi(0x6000), %g1
a00cdb7c:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00cdb80:  82 10 63 50  or  %g1, 0x350, %g1
a00cdb84:  9a 03 40 01  add  %o5, %g1, %o5
a00cdb88:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00cdb8c:  9b 2b 60 02  sll  %o5, 2, %o5
a00cdb90:  9a 13 40 01  or  %o5, %g1, %o5
a00cdb94:  d4 03 40 00  ld  [ %o5 ], %o2
a00cdb98:  94 0a a0 ff  and  %o2, 0xff, %o2
a00cdb9c:  90 10 00 10  mov  %l0, %o0
a00cdba0:  7f ff e6 ad  call  0xa00c7654
a00cdba4:  92 10 20 01  mov  1, %o1
a00cdba8:  a2 04 60 01  inc  %l1
a00cdbac:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cdbb0:  80 a0 60 04  cmp  %g1, 4
a00cdbb4:  08 bf ff f2  bleu  0xa00cdb7c
a00cdbb8:  03 00 00 18  sethi  %hi(0x6000), %g1
a00cdbbc:  90 10 00 10  mov  %l0, %o0
a00cdbc0:  92 10 20 00  clr  %o1
a00cdbc4:  7f ff eb 09  call  0xa00c87e8
a00cdbc8:  94 10 20 00  clr  %o2
a00cdbcc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cdbd0:  82 06 00 18  add  %i0, %i0, %g1
a00cdbd4:  82 00 40 18  add  %g1, %i0, %g1
a00cdbd8:  83 28 60 03  sll  %g1, 3, %g1
a00cdbdc:  9a 14 a3 b0  or  %l2, 0x3b0, %o5
a00cdbe0:  9a 00 40 0d  add  %g1, %o5, %o5
a00cdbe4:  c2 0b 60 03  ldub  [ %o5 + 3 ], %g1
a00cdbe8:  80 a0 60 7e  cmp  %g1, 0x7e
a00cdbec:  08 80 00 05  bleu  0xa00cdc00
a00cdbf0:  82 00 60 01  inc  %g1
a00cdbf4:  82 10 20 01  mov  1, %g1
a00cdbf8:  10 80 00 03  b  0xa00cdc04
a00cdbfc:  c2 2b 60 05  stb  %g1, [ %o5 + 5 ]
a00cdc00:  c2 2b 60 03  stb  %g1, [ %o5 + 3 ]
a00cdc04:  82 06 00 18  add  %i0, %i0, %g1
a00cdc08:  82 00 40 18  add  %g1, %i0, %g1
a00cdc0c:  83 28 60 03  sll  %g1, 3, %g1
a00cdc10:  9a 14 a3 b0  or  %l2, 0x3b0, %o5
a00cdc14:  9a 00 40 0d  add  %g1, %o5, %o5
a00cdc18:  c2 0b 60 04  ldub  [ %o5 + 4 ], %g1
a00cdc1c:  80 a0 60 06  cmp  %g1, 6
a00cdc20:  08 80 00 05  bleu  0xa00cdc34
a00cdc24:  82 00 60 01  inc  %g1
a00cdc28:  82 10 20 01  mov  1, %g1
a00cdc2c:  10 80 00 03  b  0xa00cdc38
a00cdc30:  c2 2b 60 06  stb  %g1, [ %o5 + 6 ]
a00cdc34:  c2 2b 60 04  stb  %g1, [ %o5 + 4 ]
a00cdc38:  81 c7 e0 08  ret
a00cdc3c:  81 e8 00 00  restore
