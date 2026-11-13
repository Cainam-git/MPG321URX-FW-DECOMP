# leon2m FUN_a009eaf8 0xa009eaf8-0xa009eb38 (64 bytes)
a009eaf8:  9d e3 bf 98  save  %sp, -104, %sp
a009eafc:  7f ff b0 89  call  0xa008ad20
a009eb00:  01 00 00 00  nop
a009eb04:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a009eb08:  da 08 62 84  ldub  [ %g1 + 0x284 ], %o5	! 0xa802d284
a009eb0c:  80 a3 60 3f  cmp  %o5, 0x3f
a009eb10:  12 80 00 04  bne  0xa009eb20
a009eb14:  01 00 00 00  nop
a009eb18:  7f ff b1 e9  call  0xa008b2bc
a009eb1c:  01 00 00 00  nop
a009eb20:  40 02 a3 01  call  0xa0147724
a009eb24:  01 00 00 00  nop
a009eb28:  13 2a 00 ab  sethi  %hi(0xa802ac00), %o1
a009eb2c:  d0 32 63 e8  sth  %o0, [ %o1 + 0x3e8 ]	! 0xa802afe8
a009eb30:  81 c7 e0 08  ret
a009eb34:  81 e8 00 00  restore
