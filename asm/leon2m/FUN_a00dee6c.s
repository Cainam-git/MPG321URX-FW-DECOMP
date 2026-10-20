# leon2m FUN_a00dee6c 0xa00dee6c-0xa00deea4 (56 bytes)
a00dee6c:  9d e3 bf 98  save  %sp, -104, %sp
a00dee70:  21 30 02 c0  sethi  %hi(0xc00b0000), %l0
a00dee74:  67 fe b4 f7  call  0x4008c250
a00dee78:  90 14 20 14  or  %l0, 0x14, %o0	! 0xc00b0014
a00dee7c:  80 8a 20 01  btst  1, %o0
a00dee80:  90 10 00 10  mov  %l0, %o0
a00dee84:  a0 10 00 18  mov  %i0, %l0
a00dee88:  02 80 00 05  be  0xa00dee9c
a00dee8c:  b0 10 20 00  clr  %i0
a00dee90:  67 fe b4 f0  call  0x4008c250
a00dee94:  b0 10 20 01  mov  1, %i0
a00dee98:  d0 2c 00 00  stb  %o0, [ %l0 ]
a00dee9c:  81 c7 e0 08  ret
a00deea0:  81 e8 00 00  restore
