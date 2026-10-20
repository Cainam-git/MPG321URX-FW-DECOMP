# leon2m FUN_a01550a8 0xa01550a8-0xa0155104 (92 bytes)
a01550a8:  9d e3 bf 98  save  %sp, -104, %sp
a01550ac:  82 10 20 20  mov  0x20, %g1
a01550b0:  b8 10 00 18  mov  %i0, %i4
a01550b4:  ba 10 00 19  mov  %i1, %i5
a01550b8:  80 a6 a0 00  cmp  %i2, 0
a01550bc:  02 80 00 10  be  0xa01550fc
a01550c0:  82 20 40 1a  sub  %g1, %i2, %g1
a01550c4:  b0 20 00 01  neg  %g1, %i0
a01550c8:  80 a0 60 00  cmp  %g1, 0
a01550cc:  b3 37 40 1a  srl  %i5, %i2, %i1
a01550d0:  04 80 00 07  ble  0xa01550ec
a01550d4:  83 2f 00 01  sll  %i4, %g1, %g1
a01550d8:  b5 37 00 1a  srl  %i4, %i2, %i2
a01550dc:  b6 16 40 01  or  %i1, %g1, %i3
a01550e0:  b0 10 00 1a  mov  %i2, %i0
a01550e4:  10 80 00 06  b  0xa01550fc
a01550e8:  b2 10 00 1b  mov  %i3, %i1
a01550ec:  b7 37 00 18  srl  %i4, %i0, %i3
a01550f0:  b4 10 20 00  clr  %i2
a01550f4:  b0 10 00 1a  mov  %i2, %i0
a01550f8:  b2 10 00 1b  mov  %i3, %i1
a01550fc:  81 c7 e0 08  ret
a0155100:  81 e8 00 00  restore
