# leon2m FUN_a00a01b8 0xa00a01b8-0xa00a01fc (68 bytes)
a00a01b8:  9d e3 bf 98  save  %sp, -104, %sp
a00a01bc:  40 00 43 63  call  0xa00b0f48
a00a01c0:  01 00 00 00  nop
a00a01c4:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00a01c8:  d4 0a e0 8e  ldub  [ %o3 + 0x8e ], %o2	! 0xa802b08e
a00a01cc:  9a 12 a0 02  or  %o2, 2, %o5
a00a01d0:  98 10 21 16  mov  0x116, %o4
a00a01d4:  13 2a 00 ab  sethi  %hi(0xa802ac00), %o1
a00a01d8:  11 2a 00 b5  sethi  %hi(0xa802d400), %o0
a00a01dc:  d8 22 63 ec  st  %o4, [ %o1 + 0x3ec ]
a00a01e0:  da 2a e0 8e  stb  %o5, [ %o3 + 0x8e ]
a00a01e4:  67 ff b4 e9  call  0x4008d588
a00a01e8:  c0 2a 20 3a  clrb  [ %o0 + 0x3a ]
a00a01ec:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00a01f0:  d0 30 60 3c  sth  %o0, [ %g1 + 0x3c ]	! 0xa802d03c
a00a01f4:  81 c7 e0 08  ret
a00a01f8:  81 e8 00 00  restore
