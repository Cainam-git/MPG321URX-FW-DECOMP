# leon2m FUN_a0127ab8 0xa0127ab8-0xa0127b24 (108 bytes)
a0127ab8:  9d e3 bf 98  save  %sp, -104, %sp
a0127abc:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a0127ac0:  98 12 62 90  or  %o1, 0x290, %o4	! 0xa802d290
a0127ac4:  11 00 00 15  sethi  %hi(0x5400), %o0
a0127ac8:  da 13 21 f6  lduh  [ %o4 + 0x1f6 ], %o5
a0127acc:  82 12 21 aa  or  %o0, 0x1aa, %g1
a0127ad0:  80 a3 40 01  cmp  %o5, %g1
a0127ad4:  22 80 00 04  be,a   0xa0127ae4
a0127ad8:  d4 0b 21 d5  ldub  [ %o4 + 0x1d5 ], %o2
a0127adc:  10 80 00 0f  b  0xa0127b18
a0127ae0:  b0 10 20 00  clr  %i0
a0127ae4:  80 a2 a0 00  cmp  %o2, 0
a0127ae8:  02 bf ff fd  be  0xa0127adc
a0127aec:  90 10 20 11  mov  0x11, %o0
a0127af0:  40 00 78 02  call  0xa0145af8
a0127af4:  b0 10 20 01  mov  1, %i0
a0127af8:  99 2a 20 10  sll  %o0, 0x10, %o4
a0127afc:  91 33 20 10  srl  %o4, 0x10, %o0
a0127b00:  17 2a 00 b6  sethi  %hi(0xa802d800), %o3
a0127b04:  80 a2 20 01  cmp  %o0, 1
a0127b08:  12 bf ff f5  bne  0xa0127adc
a0127b0c:  82 12 e0 96  or  %o3, 0x96, %g1
a0127b10:  d0 28 60 09  stb  %o0, [ %g1 + 9 ]
a0127b14:  c0 28 60 0f  clrb  [ %g1 + 0xf ]
a0127b18:  b0 0e 20 01  and  %i0, 1, %i0
a0127b1c:  81 c7 e0 08  ret
a0127b20:  81 e8 00 00  restore
