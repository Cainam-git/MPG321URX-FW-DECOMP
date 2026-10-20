# leon2m FUN_a00be9a8 0xa00be9a8-0xa00beae0 (312 bytes)
a00be9a8:  9d e3 bf 98  save  %sp, -104, %sp
a00be9ac:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00be9b0:  b2 16 a0 78  or  %i2, 0x78, %i1	! 0xa802d078
a00be9b4:  a0 10 20 30  mov  0x30, %l0
a00be9b8:  e0 2e 60 07  stb  %l0, [ %i1 + 7 ]
a00be9bc:  e0 2e 60 08  stb  %l0, [ %i1 + 8 ]
a00be9c0:  40 02 14 95  call  0xa0143c14
a00be9c4:  90 10 20 00  clr  %o0
a00be9c8:  80 8a 20 ff  btst  0xff, %o0
a00be9cc:  22 80 00 04  be,a   0xa00be9dc
a00be9d0:  e0 2e 60 09  stb  %l0, [ %i1 + 9 ]
a00be9d4:  82 10 20 31  mov  0x31, %g1
a00be9d8:  c2 2e 60 09  stb  %g1, [ %i1 + 9 ]
a00be9dc:  92 10 20 00  clr  %o1
a00be9e0:  40 02 57 17  call  0xa015463c
a00be9e4:  90 10 20 00  clr  %o0
a00be9e8:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00be9ec:  a0 16 a0 78  or  %i2, 0x78, %l0
a00be9f0:  90 10 20 62  mov  0x62, %o0
a00be9f4:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00be9f8:  92 10 20 02  mov  2, %o1
a00be9fc:  40 02 57 10  call  0xa015463c
a00bea00:  90 10 20 00  clr  %o0
a00bea04:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00bea08:  92 10 20 03  mov  3, %o1
a00bea0c:  40 02 57 0c  call  0xa015463c
a00bea10:  90 10 20 00  clr  %o0
a00bea14:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00bea18:  92 10 20 04  mov  4, %o1
a00bea1c:  40 02 57 08  call  0xa015463c
a00bea20:  90 10 20 00  clr  %o0
a00bea24:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00bea28:  92 10 20 05  mov  5, %o1
a00bea2c:  40 02 57 04  call  0xa015463c
a00bea30:  90 10 20 00  clr  %o0
a00bea34:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00bea38:  92 10 20 06  mov  6, %o1
a00bea3c:  40 02 57 00  call  0xa015463c
a00bea40:  90 10 20 00  clr  %o0
a00bea44:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bea48:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bea4c:  92 10 20 0d  mov  0xd, %o1
a00bea50:  9a 13 20 40  or  %o4, 0x40, %o5
a00bea54:  d2 2c 20 0a  stb  %o1, [ %l0 + 0xa ]
a00bea58:  80 a6 20 02  cmp  %i0, 2
a00bea5c:  02 80 00 12  be  0xa00beaa4
a00bea60:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00bea64:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bea68:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bea6c:  96 12 a0 98  or  %o2, 0x98, %o3
a00bea70:  80 a6 20 03  cmp  %i0, 3
a00bea74:  02 80 00 10  be  0xa00beab4
a00bea78:  9a 13 20 d0  or  %o4, 0xd0, %o5
a00bea7c:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00bea80:  c0 2a e0 9c  clrb  [ %o3 + 0x9c ]	! 0xa802b09c
a00bea84:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00bea88:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bea8c:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bea90:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bea94:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bea98:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bea9c:  40 02 27 53  call  0xa01487e8
a00beaa0:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00beaa4:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00beaa8:  c0 2a a0 9a  clrb  [ %o2 + 0x9a ]	! 0xa802b09a
a00beaac:  10 bf ff f7  b  0xa00bea88
a00beab0:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00beab4:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00beab8:  c0 2b 20 98  clrb  [ %o4 + 0x98 ]	! 0xa802b098
a00beabc:  c0 2a a0 98  clrb  [ %o2 + 0x98 ]
a00beac0:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00beac4:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00beac8:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00beacc:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00bead0:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bead4:  40 02 27 45  call  0xa01487e8
a00bead8:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00beadc:  01 00 00 00  nop
