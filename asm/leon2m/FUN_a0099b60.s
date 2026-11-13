# leon2m FUN_a0099b60 0xa0099b60-0xa0099bb4 (84 bytes)
a0099b60:  9d e3 bf 98  save  %sp, -104, %sp
a0099b64:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a0099b68:  40 00 3e 15  call  0xa00a93bc
a0099b6c:  d0 0a e3 3c  ldub  [ %o3 + 0x33c ], %o0	! 0xa802d33c
a0099b70:  90 10 20 2a  mov  0x2a, %o0
a0099b74:  40 00 56 36  call  0xa00af44c
a0099b78:  92 10 20 03  mov  3, %o1
a0099b7c:  94 10 20 b3  mov  0xb3, %o2
a0099b80:  13 2a 00 ab  sethi  %hi(0xa802ac00), %o1
a0099b84:  d4 22 63 ec  st  %o2, [ %o1 + 0x3ec ]	! 0xa802afec
a0099b88:  90 10 20 02  mov  2, %o0
a0099b8c:  40 00 3e b1  call  0xa00a9650
a0099b90:  92 10 20 01  mov  1, %o1
a0099b94:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a0099b98:  d0 0b 20 8e  ldub  [ %o4 + 0x8e ], %o0	! 0xa802b08e
a0099b9c:  82 12 20 02  or  %o0, 2, %g1
a0099ba0:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a0099ba4:  c2 2b 20 8e  stb  %g1, [ %o4 + 0x8e ]
a0099ba8:  c0 2b 60 55  clrb  [ %o5 + 0x55 ]
a0099bac:  81 c7 e0 08  ret
a0099bb0:  81 e8 00 00  restore
