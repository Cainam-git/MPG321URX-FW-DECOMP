# leon2m FUN_a014ad90 0xa014ad90-0xa014ae1c (140 bytes)
a014ad90:  9d e3 bf 90  save  %sp, -112, %sp
a014ad94:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014ad98:  82 0e 20 f0  and  %i0, 0xf0, %g1
a014ad9c:  80 a0 60 10  cmp  %g1, 0x10
a014ada0:  a0 10 20 00  clr  %l0
a014ada4:  02 80 00 0c  be  0xa014add4
a014ada8:  82 10 3f ff  mov  -1, %g1
a014adac:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a014adb0:  c0 37 bf f2  clrh  [ %fp + -14 ]
a014adb4:  c2 0f bf f0  ldub  [ %fp + -16 ], %g1
a014adb8:  80 a0 60 ff  cmp  %g1, 0xff
a014adbc:  02 80 00 0d  be  0xa014adf0
a014adc0:  90 10 20 40  mov  0x40, %o0
a014adc4:  7f ff d5 cf  call  0xa0140500
a014adc8:  90 10 00 01  mov  %g1, %o0
a014adcc:  10 80 00 11  b  0xa014ae10
a014add0:  a0 10 20 01  mov  1, %l0
a014add4:  80 a6 20 30  cmp  %i0, 0x30
a014add8:  32 bf ff f6  bne,a   0xa014adb0
a014addc:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a014ade0:  11 3f ff e0  sethi  %hi(0xffff8000), %o0
a014ade4:  d0 37 bf f2  sth  %o0, [ %fp + -14 ]
a014ade8:  10 bf ff f3  b  0xa014adb4
a014adec:  c0 2f bf f0  clrb  [ %fp + -16 ]
a014adf0:  7f fe 4a 09  call  0xa00dd614
a014adf4:  01 00 00 00  nop
a014adf8:  80 8a 20 ff  btst  0xff, %o0
a014adfc:  13 00 06 9c  sethi  %hi(0x1a7000), %o1
a014ae00:  02 80 00 04  be  0xa014ae10
a014ae04:  90 12 61 b0  or  %o1, 0x1b0, %o0	! 0x1a71b0
a014ae08:  7f fe 50 da  call  0xa00df170
a014ae0c:  01 00 00 00  nop
a014ae10:  b0 0c 20 01  and  %l0, 1, %i0
a014ae14:  81 c7 e0 08  ret
a014ae18:  81 e8 00 00  restore
