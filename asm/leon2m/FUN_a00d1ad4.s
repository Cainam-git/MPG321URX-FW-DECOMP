# leon2m FUN_a00d1ad4 0xa00d1ad4-0xa00d1b48 (116 bytes)
a00d1ad4:  9d e3 bf 98  save  %sp, -104, %sp
a00d1ad8:  c2 0e 20 07  ldub  [ %i0 + 7 ], %g1
a00d1adc:  80 a0 60 01  cmp  %g1, 1
a00d1ae0:  02 80 00 0b  be  0xa00d1b0c
a00d1ae4:  80 a0 60 00  cmp  %g1, 0
a00d1ae8:  12 80 00 14  bne  0xa00d1b38
a00d1aec:  01 00 00 00  nop
a00d1af0:  7f ff f3 d5  call  0xa00cea44
a00d1af4:  01 00 00 00  nop
a00d1af8:  17 3f ff ee  sethi  %hi(0xffffb800), %o3
a00d1afc:  94 12 e3 99  or  %o3, 0x399, %o2	! 0xffffbb99
a00d1b00:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00d1b04:  10 80 00 0d  b  0xa00d1b38
a00d1b08:  d4 33 60 86  sth  %o2, [ %o5 + 0x86 ]	! 0xa802d486
a00d1b0c:  7f ff f3 c3  call  0xa00cea18
a00d1b10:  01 00 00 00  nop
a00d1b14:  11 00 00 15  sethi  %hi(0x5400), %o0
a00d1b18:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d1b1c:  82 12 21 aa  or  %o0, 0x1aa, %g1
a00d1b20:  92 12 62 90  or  %o1, 0x290, %o1
a00d1b24:  c2 32 61 f6  sth  %g1, [ %o1 + 0x1f6 ]
a00d1b28:  94 10 20 00  clr  %o2
a00d1b2c:  96 10 21 fc  mov  0x1fc, %o3
a00d1b30:  40 01 e4 e8  call  0xa014aed0
a00d1b34:  90 10 20 30  mov  0x30, %o0
a00d1b38:  40 01 ce 0a  call  0xa0145360
a00d1b3c:  90 10 20 01  mov  1, %o0
a00d1b40:  81 c7 e0 08  ret
a00d1b44:  91 e8 20 e0  restore  %g0, 0xe0, %o0
