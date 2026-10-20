# leon2m FUN_a0097ad0 0xa0097ad0-0xa0097b7c (172 bytes)
a0097ad0:  9d e3 bf 98  save  %sp, -104, %sp
a0097ad4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0097ad8:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a0097adc:  a0 12 22 90  or  %o0, 0x290, %l0
a0097ae0:  da 0b 60 54  ldub  [ %o5 + 0x54 ], %o5
a0097ae4:  d8 0c 20 2f  ldub  [ %l0 + 0x2f ], %o4
a0097ae8:  82 0b 60 ff  and  %o5, 0xff, %g1
a0097aec:  80 a3 00 01  cmp  %o4, %g1
a0097af0:  02 80 00 04  be  0xa0097b00
a0097af4:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0097af8:  40 01 09 d7  call  0xa00da254
a0097afc:  da 2c 20 2f  stb  %o5, [ %l0 + 0x2f ]
a0097b00:  c2 04 63 ec  ld  [ %l1 + 0x3ec ], %g1
a0097b04:  9e 00 7f 81  add  %g1, -127, %o7
a0097b08:  90 0b e0 ff  and  %o7, 0xff, %o0
a0097b0c:  40 00 46 2c  call  0xa00a93bc
a0097b10:  01 00 00 00  nop
a0097b14:  94 10 20 01  mov  1, %o2	! 0x1
a0097b18:  90 10 20 01  mov  1, %o0
a0097b1c:  40 00 41 88  call  0xa00a813c
a0097b20:  d2 0c 20 2f  ldub  [ %l0 + 0x2f ], %o1
a0097b24:  d0 0c 20 2f  ldub  [ %l0 + 0x2f ], %o0
a0097b28:  40 00 46 ca  call  0xa00a9650
a0097b2c:  92 10 20 00  clr  %o1
a0097b30:  90 10 20 01  mov  1, %o0
a0097b34:  40 00 46 4d  call  0xa00a9468
a0097b38:  92 10 20 02  mov  2, %o1
a0097b3c:  96 10 20 25  mov  0x25, %o3
a0097b40:  d6 24 63 ec  st  %o3, [ %l1 + 0x3ec ]
a0097b44:  90 10 20 02  mov  2, %o0
a0097b48:  40 00 45 31  call  0xa00a900c
a0097b4c:  92 10 20 01  mov  1, %o1
a0097b50:  90 10 20 01  mov  1, %o0
a0097b54:  40 00 46 45  call  0xa00a9468
a0097b58:  92 10 20 02  mov  2, %o1
a0097b5c:  92 10 20 01  mov  1, %o1
a0097b60:  40 00 6e 5d  call  0xa00b34d4
a0097b64:  90 10 20 00  clr  %o0
a0097b68:  94 10 20 05  mov  5, %o2
a0097b6c:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a0097b70:  d4 2a 60 8f  stb  %o2, [ %o1 + 0x8f ]	! 0xa802b08f
a0097b74:  81 c7 e0 08  ret
a0097b78:  81 e8 00 00  restore
