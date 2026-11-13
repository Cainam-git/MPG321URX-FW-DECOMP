# leon2m FUN_a009db20 0xa009db20-0xa009dbd4 (180 bytes)
a009db20:  9d e3 bf 98  save  %sp, -104, %sp
a009db24:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009db28:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009db2c:  90 02 7f c4  add  %o1, -60, %o0
a009db30:  40 00 2e 23  call  0xa00a93bc
a009db34:  90 0a 20 ff  and  %o0, 0xff, %o0
a009db38:  03 15 55 55  sethi  %hi(0x55555400), %g1
a009db3c:  b2 10 61 56  or  %g1, 0x156, %i1	! 0x55555556
a009db40:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009db44:  9e 02 3f c5  add  %o0, -59, %o7
a009db48:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009db4c:  80 5b c0 19  smul  %o7, %i1, %g0
a009db50:  93 40 00 00  rd  %y, %o1
a009db54:  82 22 40 0a  sub  %o1, %o2, %g1
a009db58:  b0 00 40 01  add  %g1, %g1, %i0
a009db5c:  98 06 00 01  add  %i0, %g1, %o4
a009db60:  96 23 c0 0c  sub  %o7, %o4, %o3
a009db64:  9a 02 e0 3c  add  %o3, 0x3c, %o5
a009db68:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009db6c:  40 00 34 71  call  0xa00aad30
a009db70:  90 0a e0 ff  and  %o3, 0xff, %o0
a009db74:  94 0a 20 ff  and  %o0, 0xff, %o2
a009db78:  80 a2 a0 01  cmp  %o2, 1
a009db7c:  12 bf ff f2  bne  0xa009db44
a009db80:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009db84:  d8 06 a3 ec  ld  [ %i2 + 0x3ec ], %o4
a009db88:  9a 03 3f c4  add  %o4, -60, %o5
a009db8c:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a009db90:  da 2b e0 0c  stb  %o5, [ %o7 + 0xc ]	! 0xa802d40c
a009db94:  90 0b 60 ff  and  %o5, 0xff, %o0
a009db98:  40 00 2e ae  call  0xa00a9650
a009db9c:  92 10 20 01  mov  1, %o1
a009dba0:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a009dba4:  96 06 7f c4  add  %i1, -60, %o3
a009dba8:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009dbac:  f2 0e a0 56  ldub  [ %i2 + 0x56 ], %i1	! 0xa8025c56
a009dbb0:  b0 10 20 01  mov  1, %i0
a009dbb4:  80 a2 c0 19  cmp  %o3, %i1
a009dbb8:  02 80 00 04  be  0xa009dbc8
a009dbbc:  b4 10 20 00  clr  %i2
a009dbc0:  b0 10 20 01  mov  1, %i0
a009dbc4:  b4 10 20 01  mov  1, %i2
a009dbc8:  40 00 29 5d  call  0xa00a813c
a009dbcc:  81 e8 00 00  restore
a009dbd0:  01 00 00 00  nop
