# leon2m FUN_a009bbe4 0xa009bbe4-0xa009bcbc (216 bytes)
a009bbe4:  9d e3 bf 98  save  %sp, -104, %sp
a009bbe8:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009bbec:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009bbf0:  90 02 60 16  add  %o1, 0x16, %o0
a009bbf4:  40 00 35 f2  call  0xa00a93bc
a009bbf8:  90 0a 20 ff  and  %o0, 0xff, %o0
a009bbfc:  03 15 55 55  sethi  %hi(0x55555400), %g1
a009bc00:  b2 10 61 56  or  %g1, 0x156, %i1	! 0x55555556
a009bc04:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009bc08:  9e 02 3f 17  add  %o0, -233, %o7
a009bc0c:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009bc10:  80 5b c0 19  smul  %o7, %i1, %g0
a009bc14:  93 40 00 00  rd  %y, %o1
a009bc18:  82 22 40 0a  sub  %o1, %o2, %g1
a009bc1c:  b0 00 40 01  add  %g1, %g1, %i0
a009bc20:  98 06 00 01  add  %i0, %g1, %o4
a009bc24:  96 23 c0 0c  sub  %o7, %o4, %o3
a009bc28:  9a 02 e0 ea  add  %o3, 0xea, %o5
a009bc2c:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009bc30:  40 00 3c 40  call  0xa00aad30
a009bc34:  90 0a e0 ff  and  %o3, 0xff, %o0
a009bc38:  94 0a 20 ff  and  %o0, 0xff, %o2
a009bc3c:  80 a2 a0 01  cmp  %o2, 1
a009bc40:  32 bf ff f2  bne,a   0xa009bc08
a009bc44:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009bc48:  d8 06 a3 ec  ld  [ %i2 + 0x3ec ], %o4
a009bc4c:  9a 03 20 16  add  %o4, 0x16, %o5
a009bc50:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a009bc54:  90 0b 60 ff  and  %o5, 0xff, %o0
a009bc58:  da 2b e2 dc  stb  %o5, [ %o7 + 0x2dc ]
a009bc5c:  40 00 36 7d  call  0xa00a9650
a009bc60:  92 10 20 01  mov  1, %o1
a009bc64:  40 00 e8 92  call  0xa00d5eac
a009bc68:  90 10 20 01  mov  1, %o0
a009bc6c:  d6 06 a3 ec  ld  [ %i2 + 0x3ec ], %o3
a009bc70:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009bc74:  b2 02 ff 16  add  %o3, -234, %i1
a009bc78:  d2 0e a0 55  ldub  [ %i2 + 0x55 ], %o1
a009bc7c:  90 10 20 01  mov  1, %o0
a009bc80:  80 a6 40 09  cmp  %i1, %o1
a009bc84:  02 80 00 04  be  0xa009bc94
a009bc88:  94 10 20 00  clr  %o2
a009bc8c:  90 10 20 01  mov  1, %o0
a009bc90:  94 10 20 01  mov  1, %o2
a009bc94:  40 00 31 2a  call  0xa00a813c
a009bc98:  31 2a 00 ac  sethi  %hi(0xa802b000), %i0
a009bc9c:  d2 0e 20 8e  ldub  [ %i0 + 0x8e ], %o1	! 0xa802b08e
a009bca0:  82 12 60 02  or  %o1, 2, %g1
a009bca4:  c2 2e 20 8e  stb  %g1, [ %i0 + 0x8e ]
a009bca8:  b0 10 20 01  mov  1, %i0
a009bcac:  b2 10 20 00  clr  %i1
a009bcb0:  40 02 bb 09  call  0xa014a8d4
a009bcb4:  95 e8 20 00  restore  %g0, 0, %o2
a009bcb8:  01 00 00 00  nop
