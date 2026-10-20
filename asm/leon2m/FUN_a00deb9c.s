# leon2m FUN_a00deb9c 0xa00deb9c-0xa00dec90 (244 bytes)  [FUN_a00dec88 = unreachable ret/restore tail, merged]
a00deb9c:  9d e3 bf 98  save  %sp, -104, %sp
a00deba0:  33 2a 00 ac  sethi  %hi(0xa802b000), %i1
a00deba4:  c2 0e 60 c4  ldub  [ %i1 + 0xc4 ], %g1	! 0xa802b0c4
a00deba8:  80 a0 60 00  cmp  %g1, 0
a00debac:  12 80 00 36  bne  0xa00dec84
a00debb0:  98 16 60 c4  or  %i1, 0xc4, %o4
a00debb4:  11 2a 00 b5  sethi  %hi(0xa802d400), %o0
a00debb8:  c0 22 22 48  clr  [ %o0 + 0x248 ]	! 0xa802d648
a00debbc:  9a 03 20 0c  add  %o4, 0xc, %o5
a00debc0:  82 10 20 04  mov  4, %g1
a00debc4:  c0 23 40 00  clr  [ %o5 ]
a00debc8:  82 80 7f ff  addcc  %g1, -1, %g1
a00debcc:  1c bf ff fe  bpos  0xa00debc4
a00debd0:  9a 03 60 04  add  %o5, 4, %o5
a00debd4:  03 04 18 93  sethi  %hi(0x10624c00), %g1
a00debd8:  9e 10 61 d3  or  %g1, 0x1d3, %o7	! 0x10624dd3
a00debdc:  80 56 00 0f  umul  %i0, %o7, %g0
a00debe0:  9b 40 00 00  rd  %y, %o5
a00debe4:  a1 33 60 09  srl  %o5, 9, %l0
a00debe8:  c0 23 20 24  clr  [ %o4 + 0x24 ]
a00debec:  11 30 02 80  sethi  %hi(0xc00a0000), %o0
a00debf0:  67 fe b5 9b  call  0x4008c25c
a00debf4:  92 10 00 10  mov  %l0, %o1
a00debf8:  23 30 02 80  sethi  %hi(0xc00a0000), %l1
a00debfc:  90 14 60 04  or  %l1, 4, %o0	! 0xc00a0004
a00dec00:  67 fe b5 97  call  0x4008c25c
a00dec04:  92 10 20 83  mov  0x83, %o1
a00dec08:  90 14 60 08  or  %l1, 8, %o0
a00dec0c:  67 fe b5 94  call  0x4008c25c
a00dec10:  92 10 20 00  clr  %o1
a00dec14:  92 10 00 10  mov  %l0, %o1
a00dec18:  67 fe b5 91  call  0x4008c25c
a00dec1c:  90 14 60 40  or  %l1, 0x40, %o0
a00dec20:  90 14 60 44  or  %l1, 0x44, %o0
a00dec24:  67 fe b5 8e  call  0x4008c25c
a00dec28:  92 10 20 83  mov  0x83, %o1
a00dec2c:  90 14 60 48  or  %l1, 0x48, %o0
a00dec30:  67 fe b5 8b  call  0x4008c25c
a00dec34:  92 10 20 00  clr  %o1
a00dec38:  98 10 20 01  mov  1, %o4
a00dec3c:  17 00 06 63  sethi  %hi(0x198c00), %o3
a00dec40:  d8 2e 60 c4  stb  %o4, [ %i1 + 0xc4 ]
a00dec44:  90 12 e3 50  or  %o3, 0x350, %o0
a00dec48:  40 00 01 4a  call  0xa00df170
a00dec4c:  92 10 20 01  mov  1, %o1
a00dec50:  13 28 00 b3  sethi  %hi(0xa002cc00), %o1
a00dec54:  94 12 63 b8  or  %o1, 0x3b8, %o2	! 0xa002cfb8
a00dec58:  90 10 20 04  mov  4, %o0
a00dec5c:  67 fe af 09  call  0x4008a880
a00dec60:  92 10 20 01  mov  1, %o1
a00dec64:  15 28 00 b4  sethi  %hi(0xa002d000), %o2
a00dec68:  94 12 a1 74  or  %o2, 0x174, %o2	! 0xa002d174
a00dec6c:  90 10 20 04  mov  4, %o0
a00dec70:  67 fe af 04  call  0x4008a880
a00dec74:  92 10 20 10  mov  0x10, %o1
a00dec78:  b0 10 20 04  mov  4, %i0
a00dec7c:  67 fe aa e9  call  0x40089820
a00dec80:  93 e8 20 10  restore  %g0, 0x10, %o1
a00dec84:  01 00 00 00  nop
a00dec88:  81 c7 e0 08  ret
a00dec8c:  81 e8 00 00  restore
