# leon2m FUN_a014af84 0xa014af84-0xa014b01c (152 bytes)
a014af84:  9d e3 bf 98  save  %sp, -104, %sp
a014af88:  7f ff 68 84  call  0xa0125198
a014af8c:  90 0e 20 ff  and  %i0, 0xff, %o0
a014af90:  7f ff dc a2  call  0xa0142218
a014af94:  90 0a 20 ff  and  %o0, 0xff, %o0
a014af98:  7f ff dc 8b  call  0xa01421c4
a014af9c:  90 0a 20 ff  and  %o0, 0xff, %o0
a014afa0:  90 0a 20 ff  and  %o0, 0xff, %o0
a014afa4:  80 a2 20 61  cmp  %o0, 0x61
a014afa8:  02 80 00 0c  be  0xa014afd8
a014afac:  82 10 20 00  clr  %g1
a014afb0:  80 a2 20 61  cmp  %o0, 0x61
a014afb4:  04 80 00 0f  ble  0xa014aff0
a014afb8:  98 08 60 03  and  %g1, 3, %o4
a014afbc:  80 a2 20 71  cmp  %o0, 0x71
a014afc0:  02 80 00 0a  be  0xa014afe8
a014afc4:  80 a2 20 81  cmp  %o0, 0x81
a014afc8:  12 80 00 0b  bne  0xa014aff4
a014afcc:  97 2b 20 03  sll  %o4, 3, %o3
a014afd0:  10 80 00 04  b  0xa014afe0
a014afd4:  82 10 20 03  mov  3, %g1
a014afd8:  10 80 00 05  b  0xa014afec
a014afdc:  82 10 20 01  mov  1, %g1
a014afe0:  10 80 00 04  b  0xa014aff0
a014afe4:  98 08 60 03  and  %g1, 3, %o4
a014afe8:  82 10 20 02  mov  2, %g1
a014afec:  98 08 60 03  and  %g1, 3, %o4
a014aff0:  97 2b 20 03  sll  %o4, 3, %o3
a014aff4:  94 02 c0 0c  add  %o3, %o4, %o2
a014aff8:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a014affc:  90 02 80 0a  add  %o2, %o2, %o0
a014b000:  82 12 61 16  or  %o1, 0x116, %g1
a014b004:  9a 02 00 01  add  %o0, %g1, %o5
a014b008:  7f ff 68 47  call  0xa0125124
a014b00c:  d0 0b 60 10  ldub  [ %o5 + 0x10 ], %o0
a014b010:  b0 0a 20 ff  and  %o0, 0xff, %i0
a014b014:  81 c7 e0 08  ret
a014b018:  81 e8 00 00  restore
