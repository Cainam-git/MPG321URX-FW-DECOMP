# leon2m FUN_a0094fc4 0xa0094fc4-0xa0095020 (92 bytes)
a0094fc4:  9d e3 bf 98  save  %sp, -104, %sp
a0094fc8:  9a 10 20 0f  mov  0xf, %o5
a0094fcc:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a0094fd0:  40 00 4f 2e  call  0xa00a8c88
a0094fd4:  da 2a e0 8f  stb  %o5, [ %o3 + 0x8f ]	! 0xa802b08f
a0094fd8:  40 00 4d c4  call  0xa00a86e8
a0094fdc:  01 00 00 00  nop
a0094fe0:  9e 10 20 7c  mov  0x7c, %o7	! 0x7c
a0094fe4:  15 2a 00 ab  sethi  %hi(0xa802ac00), %o2
a0094fe8:  90 10 20 02  mov  2, %o0
a0094fec:  de 22 a3 ec  st  %o7, [ %o2 + 0x3ec ]
a0094ff0:  40 00 51 98  call  0xa00a9650
a0094ff4:  92 10 20 01  mov  1, %o1
a0094ff8:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a0094ffc:  d0 0a e0 8e  ldub  [ %o3 + 0x8e ], %o0	! 0xa802b08e
a0095000:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a0095004:  d8 0a 60 34  ldub  [ %o1 + 0x34 ], %o4	! 0xa802d434
a0095008:  9a 12 20 02  or  %o0, 2, %o5
a009500c:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a0095010:  d8 28 60 55  stb  %o4, [ %g1 + 0x55 ]	! 0xa8025c55
a0095014:  da 2a e0 8e  stb  %o5, [ %o3 + 0x8e ]
a0095018:  81 c7 e0 08  ret
a009501c:  81 e8 00 00  restore
