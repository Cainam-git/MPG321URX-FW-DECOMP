# leon2m FUN_a0097b7c 0xa0097b7c-0xa0097bec (112 bytes)
a0097b7c:  9d e3 bf 98  save  %sp, -104, %sp
a0097b80:  9a 10 20 05  mov  5, %o5
a0097b84:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a0097b88:  da 2b e0 8f  stb  %o5, [ %o7 + 0x8f ]	! 0xa802b08f
a0097b8c:  40 00 79 a4  call  0xa00b621c
a0097b90:  b2 10 20 01  mov  1, %i1
a0097b94:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a0097b98:  a0 13 22 90  or  %o4, 0x290, %l0	! 0xa802d290
a0097b9c:  d4 0c 20 20  ldub  [ %l0 + 0x20 ], %o2
a0097ba0:  17 2a 00 97  sethi  %hi(0xa8025c00), %o3
a0097ba4:  d4 2a e0 55  stb  %o2, [ %o3 + 0x55 ]	! 0xa8025c55
a0097ba8:  40 02 b2 95  call  0xa01445fc
a0097bac:  90 0a a0 ff  and  %o2, 0xff, %o0
a0097bb0:  92 0a 20 ff  and  %o0, 0xff, %o1
a0097bb4:  90 02 60 d0  add  %o1, 0xd0, %o0
a0097bb8:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a0097bbc:  d0 20 63 ec  st  %o0, [ %g1 + 0x3ec ]	! 0xa802afec
a0097bc0:  40 02 b2 8f  call  0xa01445fc
a0097bc4:  d0 0c 20 20  ldub  [ %l0 + 0x20 ], %o0
a0097bc8:  90 0a 20 ff  and  %o0, 0xff, %o0
a0097bcc:  40 00 46 a1  call  0xa00a9650
a0097bd0:  92 10 20 00  clr  %o1
a0097bd4:  40 02 b2 8a  call  0xa01445fc
a0097bd8:  d0 0c 20 20  ldub  [ %l0 + 0x20 ], %o0
a0097bdc:  b0 0a 20 ff  and  %o0, 0xff, %i0
a0097be0:  40 00 46 9c  call  0xa00a9650
a0097be4:  81 e8 00 00  restore
a0097be8:  01 00 00 00  nop
