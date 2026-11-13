# leon2m FUN_a009ad40 0xa009ad40-0xa009ae04 (196 bytes)
a009ad40:  9d e3 bf 98  save  %sp, -104, %sp
a009ad44:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009ad48:  c2 06 a3 ec  ld  [ %i2 + 0x3ec ], %g1	! 0xa802afec
a009ad4c:  90 00 60 30  add  %g1, 0x30, %o0
a009ad50:  40 00 39 9b  call  0xa00a93bc
a009ad54:  90 0a 20 ff  and  %o0, 0xff, %o0
a009ad58:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009ad5c:  96 02 3f 31  add  %o0, -207, %o3
a009ad60:  b3 3a e0 1f  sra  %o3, 0x1f, %i1
a009ad64:  b1 36 60 1e  srl  %i1, 0x1e, %i0
a009ad68:  9e 02 c0 18  add  %o3, %i0, %o7
a009ad6c:  98 0b ff fc  and  %o7, -4, %o4
a009ad70:  94 22 c0 0c  sub  %o3, %o4, %o2
a009ad74:  9a 02 a0 d0  add  %o2, 0xd0, %o5
a009ad78:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009ad7c:  40 00 3f ed  call  0xa00aad30
a009ad80:  90 0a a0 ff  and  %o2, 0xff, %o0
a009ad84:  92 0a 20 ff  and  %o0, 0xff, %o1
a009ad88:  80 a2 60 01  cmp  %o1, 1
a009ad8c:  32 bf ff f4  bne,a   0xa009ad5c
a009ad90:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009ad94:  d6 06 a3 ec  ld  [ %i2 + 0x3ec ], %o3
a009ad98:  9a 02 e0 30  add  %o3, 0x30, %o5
a009ad9c:  90 0b 60 ff  and  %o5, 0xff, %o0
a009ada0:  40 00 3a 2c  call  0xa00a9650
a009ada4:  92 10 20 01  mov  1, %o1
a009ada8:  d4 06 a3 ec  ld  [ %i2 + 0x3ec ], %o2
a009adac:  92 02 a0 30  add  %o2, 0x30, %o1
a009adb0:  40 02 a5 fb  call  0xa014459c
a009adb4:  90 0a 60 ff  and  %o1, 0xff, %o0
a009adb8:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a009adbc:  b4 0a 20 ff  and  %o0, 0xff, %i2
a009adc0:  c2 08 60 55  ldub  [ %g1 + 0x55 ], %g1
a009adc4:  80 a6 80 01  cmp  %i2, %g1
a009adc8:  02 80 00 08  be  0xa009ade8
a009adcc:  01 00 00 00  nop
a009add0:  40 02 a6 0b  call  0xa01445fc
a009add4:  90 10 00 01  mov  %g1, %o0
a009add8:  b2 0a 20 ff  and  %o0, 0xff, %i1
a009addc:  b0 10 20 01  mov  1, %i0
a009ade0:  40 00 34 d7  call  0xa00a813c
a009ade4:  95 e8 20 01  restore  %g0, 1, %o2
a009ade8:  40 02 a6 05  call  0xa01445fc
a009adec:  90 10 00 01  mov  %g1, %o0
a009adf0:  b2 0a 20 ff  and  %o0, 0xff, %i1
a009adf4:  b0 10 20 01  mov  1, %i0
a009adf8:  40 00 34 d1  call  0xa00a813c
a009adfc:  95 e8 20 00  restore  %g0, 0, %o2
a009ae00:  01 00 00 00  nop
