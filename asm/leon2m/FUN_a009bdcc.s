# leon2m FUN_a009bdcc 0xa009bdcc-0xa009bedc (272 bytes)
a009bdcc:  9d e3 bf 98  save  %sp, -104, %sp
a009bdd0:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a009bdd4:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1	! 0xa802afec
a009bdd8:  90 02 60 28  add  %o1, 0x28, %o0
a009bddc:  40 00 35 78  call  0xa00a93bc
a009bde0:  90 0a 20 ff  and  %o0, 0xff, %o0
a009bde4:  03 19 99 99  sethi  %hi(0x66666400), %g1
a009bde8:  b0 10 62 67  or  %g1, 0x267, %i0	! 0x66666667
a009bdec:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a009bdf0:  9e 02 3f 29  add  %o0, -215, %o7
a009bdf4:  80 5b c0 18  smul  %o7, %i0, %g0
a009bdf8:  9b 40 00 00  rd  %y, %o5
a009bdfc:  95 3b 60 01  sra  %o5, 1, %o2
a009be00:  97 3b e0 1f  sra  %o7, 0x1f, %o3
a009be04:  92 22 80 0b  sub  %o2, %o3, %o1
a009be08:  83 2a 60 02  sll  %o1, 2, %g1
a009be0c:  98 00 40 09  add  %g1, %o1, %o4
a009be10:  96 23 c0 0c  sub  %o7, %o4, %o3
a009be14:  9a 02 e0 d8  add  %o3, 0xd8, %o5
a009be18:  da 26 63 ec  st  %o5, [ %i1 + 0x3ec ]
a009be1c:  40 00 3b c5  call  0xa00aad30
a009be20:  90 0a e0 ff  and  %o3, 0xff, %o0
a009be24:  94 0a 20 ff  and  %o0, 0xff, %o2
a009be28:  80 a2 a0 01  cmp  %o2, 1
a009be2c:  32 bf ff f1  bne,a   0xa009bdf0
a009be30:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a009be34:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4
a009be38:  90 03 20 28  add  %o4, 0x28, %o0
a009be3c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a009be40:  92 13 e2 90  or  %o7, 0x290, %o1	! 0xa802d290
a009be44:  90 0a 20 ff  and  %o0, 0xff, %o0
a009be48:  da 02 60 30  ld  [ %o1 + 0x30 ], %o5
a009be4c:  b0 0a 20 0f  and  %o0, 0xf, %i0
a009be50:  83 2e 20 04  sll  %i0, 4, %g1
a009be54:  96 0b 7f 0f  and  %o5, -241, %o3
a009be58:  94 12 c0 01  or  %o3, %g1, %o2
a009be5c:  d4 22 60 30  st  %o2, [ %o1 + 0x30 ]
a009be60:  40 00 35 fc  call  0xa00a9650
a009be64:  92 10 20 01  mov  1, %o1
a009be68:  40 00 ef 02  call  0xa00d7a70
a009be6c:  90 10 20 01  mov  1, %o0
a009be70:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4
a009be74:  1f 2a 00 97  sethi  %hi(0xa8025c00), %o7
a009be78:  b0 03 3f 28  add  %o4, -216, %i0
a009be7c:  d2 0b e0 55  ldub  [ %o7 + 0x55 ], %o1
a009be80:  90 10 20 01  mov  1, %o0
a009be84:  80 a6 00 09  cmp  %i0, %o1
a009be88:  02 80 00 04  be  0xa009be98
a009be8c:  94 10 20 00  clr  %o2
a009be90:  90 10 20 01  mov  1, %o0
a009be94:  94 10 20 01  mov  1, %o2
a009be98:  40 00 30 a9  call  0xa00a813c
a009be9c:  01 00 00 00  nop
a009bea0:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1
a009bea4:  80 a2 60 dc  cmp  %o1, 0xdc
a009bea8:  02 80 00 07  be  0xa009bec4
a009beac:  90 10 20 01  mov  1, %o0
a009beb0:  40 00 35 6e  call  0xa00a9468
a009beb4:  92 10 20 03  mov  3, %o1
a009beb8:  b0 10 20 00  clr  %i0
a009bebc:  40 00 5d 86  call  0xa00b34d4
a009bec0:  93 e8 20 04  restore  %g0, 4, %o1
a009bec4:  40 00 35 69  call  0xa00a9468
a009bec8:  92 10 20 02  mov  2, %o1
a009becc:  b0 10 20 00  clr  %i0
a009bed0:  40 00 5d 81  call  0xa00b34d4
a009bed4:  93 e8 20 01  restore  %g0, 1, %o1
a009bed8:  01 00 00 00  nop
