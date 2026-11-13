# leon2m FUN_a00decf4 0xa00decf4-0xa00ded78 (132 bytes)  [FUN_a00ded70 = unreachable ret/restore tail, merged]
a00decf4:  9d e3 bf 98  save  %sp, -104, %sp
a00decf8:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00decfc:  c2 0b 60 c4  ldub  [ %o5 + 0xc4 ], %g1	! 0xa802b0c4
a00ded00:  21 30 02 80  sethi  %hi(0xc00a0000), %l0
a00ded04:  94 10 20 80  mov  0x80, %o2
a00ded08:  90 14 20 24  or  %l0, 0x24, %o0
a00ded0c:  92 10 20 00  clr  %o1
a00ded10:  80 a0 60 00  cmp  %g1, 0
a00ded14:  a2 10 00 18  mov  %i0, %l1
a00ded18:  02 80 00 15  be  0xa00ded6c
a00ded1c:  9a 13 60 c4  or  %o5, 0xc4, %o5
a00ded20:  f2 23 60 20  st  %i1, [ %o5 + 0x20 ]
a00ded24:  67 fe b5 51  call  0x4008c268
a00ded28:  f6 23 60 24  st  %i3, [ %o5 + 0x24 ]
a00ded2c:  99 2e a0 02  sll  %i2, 2, %o4
a00ded30:  96 03 00 1a  add  %o4, %i2, %o3
a00ded34:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a00ded38:  90 02 c0 0b  add  %o3, %o3, %o0
a00ded3c:  92 12 a3 ff  or  %o2, 0x3ff, %o1
a00ded40:  92 0a 00 09  and  %o0, %o1, %o1
a00ded44:  90 14 20 20  or  %l0, 0x20, %o0
a00ded48:  b0 14 20 24  or  %l0, 0x24, %i0
a00ded4c:  b2 10 20 80  mov  0x80, %i1
a00ded50:  80 8c 60 ff  btst  0xff, %l1
a00ded54:  02 80 00 06  be  0xa00ded6c
a00ded58:  b4 10 20 80  mov  0x80, %i2
a00ded5c:  67 fe b5 40  call  0x4008c25c
a00ded60:  01 00 00 00  nop
a00ded64:  67 fe b5 41  call  0x4008c268
a00ded68:  81 e8 00 00  restore
a00ded6c:  01 00 00 00  nop
a00ded70:  81 c7 e0 08  ret
a00ded74:  81 e8 00 00  restore
