# leon2m FUN_a00c0adc 0xa00c0adc-0xa00c0b34 (88 bytes)
a00c0adc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c0ae0:  80 a2 20 02  cmp  %o0, 2
a00c0ae4:  02 80 00 0c  be  0xa00c0b14
a00c0ae8:  80 a2 20 03  cmp  %o0, 3
a00c0aec:  02 80 00 0d  be  0xa00c0b20
a00c0af0:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c0af4:  c2 0b 60 d7  ldub  [ %o5 + 0xd7 ], %g1	! 0xa802d0d7
a00c0af8:  90 00 7f d0  add  %g1, -48, %o0
a00c0afc:  82 0a 20 ff  and  %o0, 0xff, %g1
a00c0b00:  80 a0 60 64  cmp  %g1, 0x64
a00c0b04:  18 80 00 0a  bgu  0xa00c0b2c
a00c0b08:  90 10 20 ff  mov  0xff, %o0
a00c0b0c:  10 80 00 08  b  0xa00c0b2c
a00c0b10:  90 10 00 01  mov  %g1, %o0
a00c0b14:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c0b18:  10 bf ff f8  b  0xa00c0af8
a00c0b1c:  c2 08 60 47  ldub  [ %g1 + 0x47 ], %g1	! 0xa802d047
a00c0b20:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c0b24:  10 bf ff f5  b  0xa00c0af8
a00c0b28:  c2 0a 20 9f  ldub  [ %o0 + 0x9f ], %g1	! 0xa802d09f
a00c0b2c:  81 c3 e0 08  retl
a00c0b30:  01 00 00 00  nop
