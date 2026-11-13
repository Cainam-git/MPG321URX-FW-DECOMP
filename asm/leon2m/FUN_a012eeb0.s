# leon2m FUN_a012eeb0 0xa012eeb0-0xa012f12c (636 bytes)
a012eeb0:  9d e3 bf 98  save  %sp, -104, %sp
a012eeb4:  a2 0e 20 ff  and  %i0, 0xff, %l1
a012eeb8:  11 00 06 94  sethi  %hi(0x1a5000), %o0
a012eebc:  90 12 22 20  or  %o0, 0x220, %o0	! 0x1a5220
a012eec0:  7f fe c0 ac  call  0xa00df170
a012eec4:  92 10 00 11  mov  %l1, %o1
a012eec8:  82 04 7f ef  add  %l1, -17, %g1
a012eecc:  80 a0 60 1f  cmp  %g1, 0x1f
a012eed0:  18 80 00 07  bgu  0xa012eeec
a012eed4:  13 00 03 3a  sethi  %hi(0xce800), %o1
a012eed8:  83 28 60 02  sll  %g1, 2, %g1
a012eedc:  9a 12 63 a4  or  %o1, 0x3a4, %o5
a012eee0:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a012eee4:  81 c3 00 00  jmp  %o4
a012eee8:  01 00 00 00  nop
a012eeec:  7f ff 6f e1  call  0xa010ae70
a012eef0:  01 00 00 00  nop
a012eef4:  7f ff 70 17  call  0xa010af50
a012eef8:  01 00 00 00  nop
a012eefc:  7f ff 70 33  call  0xa010afc8
a012ef00:  01 00 00 00  nop
a012ef04:  7f ff 70 a5  call  0xa010b198
a012ef08:  81 e8 00 00  restore
a012ef0c:  7f ff 70 03  call  0xa010af18
a012ef10:  01 00 00 00  nop
a012ef14:  80 8a 20 ff  btst  0xff, %o0
a012ef18:  12 80 00 6c  bne  0xa012f0c8
a012ef1c:  01 00 00 00  nop
a012ef20:  7f ff 6f d4  call  0xa010ae70
a012ef24:  01 00 00 00  nop
a012ef28:  7f ff 70 28  call  0xa010afc8
a012ef2c:  01 00 00 00  nop
a012ef30:  7f ff 70 9a  call  0xa010b198
a012ef34:  01 00 00 00  nop
a012ef38:  19 2a 00 9e  sethi  %hi(0xa8027800), %o4
a012ef3c:  90 0c 60 0f  and  %l1, 0xf, %o0
a012ef40:  b0 13 23 a8  or  %o4, 0x3a8, %i0
a012ef44:  a3 2a 20 02  sll  %o0, 2, %l1
a012ef48:  90 10 20 00  clr  %o0
a012ef4c:  7f ff 70 08  call  0xa010af6c
a012ef50:  d2 06 00 11  ld  [ %i0 + %l1 ], %o1
a012ef54:  de 06 00 11  ld  [ %i0 + %l1 ], %o7
a012ef58:  92 03 e0 40  add  %o7, 0x40, %o1
a012ef5c:  7f ff 70 04  call  0xa010af6c
a012ef60:  90 10 20 01  mov  1, %o0
a012ef64:  d6 06 00 11  ld  [ %i0 + %l1 ], %o3
a012ef68:  92 02 e0 80  add  %o3, 0x80, %o1
a012ef6c:  7f ff 70 00  call  0xa010af6c
a012ef70:  90 10 20 02  mov  2, %o0
a012ef74:  7f ff 6f f0  call  0xa010af34
a012ef78:  81 e8 00 00  restore
a012ef7c:  7f ff 6f af  call  0xa010ae38
a012ef80:  01 00 00 00  nop
a012ef84:  80 8a 20 ff  btst  0xff, %o0
a012ef88:  12 80 00 5a  bne  0xa012f0f0
a012ef8c:  01 00 00 00  nop
a012ef90:  7f ff 6f f0  call  0xa010af50
a012ef94:  01 00 00 00  nop
a012ef98:  90 10 20 00  clr  %o0	! 0x0
a012ef9c:  7f ff 6f 89  call  0xa010adc0
a012efa0:  92 10 20 01  mov  1, %o1
a012efa4:  7f ff fd 12  call  0xa012e3ec
a012efa8:  90 10 22 00  mov  0x200, %o0
a012efac:  7f ff 6f aa  call  0xa010ae54
a012efb0:  81 e8 00 00  restore
a012efb4:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a012efb8:  d4 0a e1 d7  ldub  [ %o3 + 0x1d7 ], %o2	! 0xa802e1d7
a012efbc:  80 a2 a0 00  cmp  %o2, 0
a012efc0:  12 80 00 32  bne  0xa012f088
a012efc4:  01 00 00 00  nop
a012efc8:  7f ff 6f d4  call  0xa010af18
a012efcc:  01 00 00 00  nop
a012efd0:  80 8a 20 ff  btst  0xff, %o0
a012efd4:  12 80 00 51  bne  0xa012f118
a012efd8:  01 00 00 00  nop
a012efdc:  7f ff 6f a5  call  0xa010ae70
a012efe0:  b0 0c 60 0f  and  %l1, 0xf, %i0
a012efe4:  7f ff 6f f9  call  0xa010afc8
a012efe8:  21 00 00 40  sethi  %hi(0x10000), %l0
a012efec:  7f ff 70 6b  call  0xa010b198
a012eff0:  01 00 00 00  nop
a012eff4:  9f 2c 00 18  sll  %l0, %i0, %o7
a012eff8:  91 33 e0 10  srl  %o7, 0x10, %o0
a012effc:  7f ff fc fc  call  0xa012e3ec
a012f000:  01 00 00 00  nop
a012f004:  7f ff 6f cc  call  0xa010af34
a012f008:  81 e8 00 00  restore
a012f00c:  7f ff 6f 8b  call  0xa010ae38
a012f010:  01 00 00 00  nop
a012f014:  80 8a 20 ff  btst  0xff, %o0
a012f018:  12 80 00 31  bne  0xa012f0dc
a012f01c:  01 00 00 00  nop
a012f020:  7f ff 6f cc  call  0xa010af50
a012f024:  01 00 00 00  nop
a012f028:  7f ff 6f e8  call  0xa010afc8
a012f02c:  01 00 00 00  nop
a012f030:  7f ff 70 5a  call  0xa010b198
a012f034:  01 00 00 00  nop
a012f038:  90 10 20 01  mov  1, %o0	! 0x1
a012f03c:  7f ff 6f 61  call  0xa010adc0
a012f040:  92 10 20 01  mov  1, %o1
a012f044:  15 2a 00 9e  sethi  %hi(0xa8027800), %o2
a012f048:  92 0c 60 0f  and  %l1, 0xf, %o1
a012f04c:  a0 12 a3 ac  or  %o2, 0x3ac, %l0
a012f050:  b1 2a 60 02  sll  %o1, 2, %i0
a012f054:  90 10 20 00  clr  %o0
a012f058:  7f ff fe f3  call  0xa012ec24
a012f05c:  d2 04 00 18  ld  [ %l0 + %i0 ], %o1
a012f060:  da 04 00 18  ld  [ %l0 + %i0 ], %o5
a012f064:  92 03 61 40  add  %o5, 0x140, %o1
a012f068:  7f ff fe ef  call  0xa012ec24
a012f06c:  90 10 20 01  mov  1, %o0
a012f070:  c2 04 00 18  ld  [ %l0 + %i0 ], %g1
a012f074:  92 00 62 80  add  %g1, 0x280, %o1
a012f078:  7f ff fe eb  call  0xa012ec24
a012f07c:  90 10 20 02  mov  2, %o0
a012f080:  7f ff 6f 75  call  0xa010ae54
a012f084:  81 e8 00 00  restore
a012f088:  7f ff 6f 6c  call  0xa010ae38
a012f08c:  01 00 00 00  nop
a012f090:  80 8a 20 ff  btst  0xff, %o0
a012f094:  12 80 00 1c  bne  0xa012f104
a012f098:  01 00 00 00  nop
a012f09c:  7f ff 6f ad  call  0xa010af50
a012f0a0:  01 00 00 00  nop
a012f0a4:  90 10 20 00  clr  %o0	! 0x0
a012f0a8:  7f ff 6f 46  call  0xa010adc0
a012f0ac:  92 10 20 01  mov  1, %o1
a012f0b0:  98 0c 60 0f  and  %l1, 0xf, %o4
a012f0b4:  11 00 00 40  sethi  %hi(0x10000), %o0
a012f0b8:  a3 2a 00 0c  sll  %o0, %o4, %l1
a012f0bc:  7f ff fc cc  call  0xa012e3ec
a012f0c0:  91 34 60 10  srl  %l1, 0x10, %o0
a012f0c4:  30 bf ff ba  b,a   0xa012efac
a012f0c8:  7f ff 6f a2  call  0xa010af50
a012f0cc:  01 00 00 00  nop
a012f0d0:  67 fd 78 34  call  0x4008d1a0
a012f0d4:  90 10 20 32  mov  0x32, %o0	! 0x32
a012f0d8:  30 bf ff 92  b,a   0xa012ef20
a012f0dc:  7f ff 6f 65  call  0xa010ae70
a012f0e0:  01 00 00 00  nop
a012f0e4:  67 fd 78 2f  call  0x4008d1a0
a012f0e8:  90 10 20 32  mov  0x32, %o0	! 0x32
a012f0ec:  30 bf ff cd  b,a   0xa012f020
a012f0f0:  7f ff 6f 60  call  0xa010ae70
a012f0f4:  01 00 00 00  nop
a012f0f8:  67 fd 78 2a  call  0x4008d1a0
a012f0fc:  90 10 20 32  mov  0x32, %o0	! 0x32
a012f100:  30 bf ff a4  b,a   0xa012ef90
a012f104:  7f ff 6f 5b  call  0xa010ae70
a012f108:  01 00 00 00  nop
a012f10c:  67 fd 78 25  call  0x4008d1a0
a012f110:  90 10 20 32  mov  0x32, %o0	! 0x32
a012f114:  30 bf ff e2  b,a   0xa012f09c
a012f118:  7f ff 6f 8e  call  0xa010af50
a012f11c:  01 00 00 00  nop
a012f120:  67 fd 78 20  call  0x4008d1a0
a012f124:  90 10 20 32  mov  0x32, %o0	! 0x32
a012f128:  30 bf ff ad  b,a   0xa012efdc
