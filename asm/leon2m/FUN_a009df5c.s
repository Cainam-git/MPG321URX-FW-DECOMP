# leon2m FUN_a009df5c 0xa009df5c-0xa009e00c (176 bytes)
a009df5c:  9d e3 bf 98  save  %sp, -104, %sp
a009df60:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009df64:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009df68:  90 02 60 45  add  %o1, 0x45, %o0
a009df6c:  40 00 2d 14  call  0xa00a93bc
a009df70:  90 0a 20 ff  and  %o0, 0xff, %o0
a009df74:  03 19 99 99  sethi  %hi(0x66666400), %g1
a009df78:  b2 10 62 67  or  %g1, 0x267, %i1	! 0x66666667
a009df7c:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009df80:  9e 02 3f 49  add  %o0, -183, %o7
a009df84:  80 5b c0 19  smul  %o7, %i1, %g0
a009df88:  97 40 00 00  rd  %y, %o3
a009df8c:  93 3a e0 01  sra  %o3, 1, %o1
a009df90:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009df94:  82 22 40 0a  sub  %o1, %o2, %g1
a009df98:  b1 28 60 02  sll  %g1, 2, %i0
a009df9c:  98 06 00 01  add  %i0, %g1, %o4
a009dfa0:  96 23 c0 0c  sub  %o7, %o4, %o3
a009dfa4:  9a 02 e0 bb  add  %o3, 0xbb, %o5
a009dfa8:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009dfac:  40 00 33 61  call  0xa00aad30
a009dfb0:  90 0a e0 ff  and  %o3, 0xff, %o0
a009dfb4:  94 0a 20 ff  and  %o0, 0xff, %o2
a009dfb8:  80 a2 a0 01  cmp  %o2, 1
a009dfbc:  12 bf ff f1  bne  0xa009df80
a009dfc0:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009dfc4:  d8 06 a3 ec  ld  [ %i2 + 0x3ec ], %o4
a009dfc8:  9a 03 20 45  add  %o4, 0x45, %o5
a009dfcc:  90 0b 60 ff  and  %o5, 0xff, %o0
a009dfd0:  40 00 2d a0  call  0xa00a9650
a009dfd4:  92 10 20 01  mov  1, %o1
a009dfd8:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a009dfdc:  9e 06 7f 45  add  %i1, -187, %o7
a009dfe0:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009dfe4:  f2 0e a0 56  ldub  [ %i2 + 0x56 ], %i1	! 0xa8025c56
a009dfe8:  b0 10 20 01  mov  1, %i0
a009dfec:  80 a3 c0 19  cmp  %o7, %i1
a009dff0:  02 80 00 04  be  0xa009e000
a009dff4:  b4 10 20 00  clr  %i2
a009dff8:  b0 10 20 01  mov  1, %i0
a009dffc:  b4 10 20 01  mov  1, %i2
a009e000:  40 00 28 4f  call  0xa00a813c
a009e004:  81 e8 00 00  restore
a009e008:  01 00 00 00  nop
