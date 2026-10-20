# leon2m FUN_a012cd68 0xa012cd68-0xa012ce18 (176 bytes)
a012cd68:  9d e3 bf 98  save  %sp, -104, %sp
a012cd6c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a012cd70:  7f ff e1 78  call  0xa0125350
a012cd74:  90 10 00 10  mov  %l0, %o0
a012cd78:  80 8a 20 ff  btst  0xff, %o0
a012cd7c:  02 80 00 25  be  0xa012ce10
a012cd80:  82 10 20 01  mov  1, %g1
a012cd84:  b1 28 40 10  sll  %g1, %l0, %i0
a012cd88:  90 10 00 10  mov  %l0, %o0
a012cd8c:  80 8e 60 ff  btst  0xff, %i1
a012cd90:  12 80 00 04  bne  0xa012cda0
a012cd94:  b0 0e 20 ff  and  %i0, 0xff, %i0
a012cd98:  40 00 1c 7b  call  0xa0133f84
a012cd9c:  81 e8 00 00  restore
a012cda0:  7f ff e1 78  call  0xa0125380
a012cda4:  01 00 00 00  nop
a012cda8:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a012cdac:  94 12 e1 a0  or  %o3, 0x1a0, %o2	! 0xa802e1a0
a012cdb0:  92 04 00 0a  add  %l0, %o2, %o1
a012cdb4:  da 0a 60 1b  ldub  [ %o1 + 0x1b ], %o5
a012cdb8:  80 a3 60 ff  cmp  %o5, 0xff
a012cdbc:  99 2c 20 02  sll  %l0, 2, %o4
a012cdc0:  02 80 00 0e  be  0xa012cdf8
a012cdc4:  9a 03 40 0d  add  %o5, %o5, %o5
a012cdc8:  03 00 06 9a  sethi  %hi(0x1a6800), %g1
a012cdcc:  b0 10 62 d8  or  %g1, 0x2d8, %i0	! 0x1a6ad8
a012cdd0:  da 16 00 0d  lduh  [ %i0 + %o5 ], %o5
a012cdd4:  96 10 20 01  mov  1, %o3
a012cdd8:  95 2a c0 10  sll  %o3, %l0, %o2
a012cddc:  93 2b 60 10  sll  %o5, 0x10, %o1
a012cde0:  a1 32 20 07  srl  %o0, 7, %l0
a012cde4:  b0 0a a0 ff  and  %o2, 0xff, %i0
a012cde8:  b3 32 60 10  srl  %o1, 0x10, %i1
a012cdec:  b4 0c 20 ff  and  %l0, 0xff, %i2
a012cdf0:  40 00 1c 73  call  0xa0133fbc
a012cdf4:  81 e8 00 00  restore
a012cdf8:  35 2a 00 b2  sethi  %hi(0xa802c800), %i2
a012cdfc:  f2 06 a3 08  ld  [ %i2 + 0x308 ], %i1	! 0xa802cb08
a012ce00:  9f 36 40 0c  srl  %i1, %o4, %o7
a012ce04:  98 0b e0 0f  and  %o7, 0xf, %o4
a012ce08:  10 bf ff f3  b  0xa012cdd4
a012ce0c:  9b 2b 20 07  sll  %o4, 7, %o5
a012ce10:  81 c7 e0 08  ret
a012ce14:  81 e8 00 00  restore
