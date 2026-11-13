# leon2m FUN_a00939b0 0xa00939b0-0xa0093b04 (340 bytes)
a00939b0:  9d e3 bf 98  save  %sp, -104, %sp
a00939b4:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a00939b8:  d6 0c 20 56  ldub  [ %l0 + 0x56 ], %o3	! 0xa8025c56
a00939bc:  94 02 e0 01  add  %o3, 1, %o2
a00939c0:  40 00 56 7f  call  0xa00a93bc
a00939c4:  90 0a a0 ff  and  %o2, 0xff, %o0
a00939c8:  23 2a 00 b3  sethi  %hi(0xa802cc00), %l1
a00939cc:  d2 14 63 f4  lduh  [ %l1 + 0x3f4 ], %o1	! 0xa802cff4
a00939d0:  1b 00 00 10  sethi  %hi(0x4000), %o5
a00939d4:  90 12 40 0d  or  %o1, %o5, %o0
a00939d8:  d0 34 63 f4  sth  %o0, [ %l1 + 0x3f4 ]
a00939dc:  90 10 20 00  clr  %o0
a00939e0:  92 10 20 00  clr  %o1
a00939e4:  40 02 cc 97  call  0xa0146c40
a00939e8:  94 10 20 00  clr  %o2
a00939ec:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00939f0:  a2 10 62 90  or  %g1, 0x290, %l1	! 0xa802d290
a00939f4:  de 0c 20 56  ldub  [ %l0 + 0x56 ], %o7
a00939f8:  e0 0c 61 a3  ldub  [ %l1 + 0x1a3 ], %l0
a00939fc:  98 04 20 58  add  %l0, 0x58, %o4
a0093a00:  96 03 e0 01  add  %o7, 1, %o3
a0093a04:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0093a08:  d8 24 23 ec  st  %o4, [ %l0 + 0x3ec ]	! 0xa802afec
a0093a0c:  92 0a e0 ff  and  %o3, 0xff, %o1
a0093a10:  90 10 20 01  mov  1, %o0
a0093a14:  40 00 51 ca  call  0xa00a813c
a0093a18:  94 10 20 00  clr  %o2
a0093a1c:  d4 04 23 ec  ld  [ %l0 + 0x3ec ], %o2
a0093a20:  90 02 bf a9  add  %o2, -87, %o0
a0093a24:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0093a28:  92 02 bf aa  add  %o2, -86, %o1
a0093a2c:  d0 2b 63 ea  stb  %o0, [ %o5 + 0x3ea ]
a0093a30:  d0 2c 61 a0  stb  %o0, [ %l1 + 0x1a0 ]
a0093a34:  90 10 20 01  mov  1, %o0
a0093a38:  92 0a 60 ff  and  %o1, 0xff, %o1
a0093a3c:  40 00 51 c0  call  0xa00a813c
a0093a40:  94 10 20 01  mov  1, %o2
a0093a44:  c2 0c 61 a0  ldub  [ %l1 + 0x1a0 ], %g1
a0093a48:  90 10 20 01  mov  1, %o0
a0093a4c:  80 a0 60 00  cmp  %g1, 0
a0093a50:  02 80 00 06  be  0xa0093a68
a0093a54:  98 00 40 11  add  %g1, %l1, %o4
a0093a58:  de 0b 21 9b  ldub  [ %o4 + 0x19b ], %o7
a0093a5c:  c2 0b 21 97  ldub  [ %o4 + 0x197 ], %g1
a0093a60:  c2 2c 61 a1  stb  %g1, [ %l1 + 0x1a1 ]
a0093a64:  de 2c 61 a2  stb  %o7, [ %l1 + 0x1a2 ]
a0093a68:  40 00 62 48  call  0xa00ac388
a0093a6c:  01 00 00 00  nop
a0093a70:  de 04 23 ec  ld  [ %l0 + 0x3ec ], %o7
a0093a74:  96 03 ff aa  add  %o7, -86, %o3
a0093a78:  90 0a e0 ff  and  %o3, 0xff, %o0
a0093a7c:  40 00 56 f5  call  0xa00a9650
a0093a80:  92 10 20 00  clr  %o1
a0093a84:  d4 0c 61 a0  ldub  [ %l1 + 0x1a0 ], %o2
a0093a88:  9a 02 a0 01  add  %o2, 1, %o5
a0093a8c:  92 0b 60 ff  and  %o5, 0xff, %o1
a0093a90:  94 10 20 01  mov  1, %o2
a0093a94:  40 00 51 aa  call  0xa00a813c
a0093a98:  90 10 20 01  mov  1, %o0
a0093a9c:  92 10 20 12  mov  0x12, %o1
a0093aa0:  d2 24 23 ec  st  %o1, [ %l0 + 0x3ec ]
a0093aa4:  90 10 20 04  mov  4, %o0
a0093aa8:  40 00 55 59  call  0xa00a900c
a0093aac:  92 10 20 01  mov  1, %o1
a0093ab0:  90 10 20 02  mov  2, %o0
a0093ab4:  40 00 56 6d  call  0xa00a9468
a0093ab8:  92 10 20 05  mov  5, %o1
a0093abc:  90 10 20 00  clr  %o0
a0093ac0:  40 00 56 6a  call  0xa00a9468
a0093ac4:  92 10 20 00  clr  %o1
a0093ac8:  92 10 20 02  mov  2, %o1
a0093acc:  40 00 56 67  call  0xa00a9468
a0093ad0:  90 10 20 01  mov  1, %o0
a0093ad4:  40 00 7e 5e  call  0xa00b344c
a0093ad8:  90 10 20 07  mov  7, %o0
a0093adc:  90 10 20 00  clr  %o0
a0093ae0:  40 00 7e 7d  call  0xa00b34d4
a0093ae4:  92 10 20 01  mov  1, %o1
a0093ae8:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a0093aec:  d0 0b 20 8e  ldub  [ %o4 + 0x8e ], %o0	! 0xa802b08e
a0093af0:  a0 12 20 02  or  %o0, 2, %l0
a0093af4:  e0 2b 20 8e  stb  %l0, [ %o4 + 0x8e ]
a0093af8:  c0 2c 61 a3  clrb  [ %l1 + 0x1a3 ]
a0093afc:  81 c7 e0 08  ret
a0093b00:  81 e8 00 00  restore
