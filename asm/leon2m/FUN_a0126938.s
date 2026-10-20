# leon2m FUN_a0126938 0xa0126938-0xa01269a4 (108 bytes)
a0126938:  9d e3 bf 90  save  %sp, -112, %sp
a012693c:  03 2a 00 b6  sethi  %hi(0xa802d800), %g1
a0126940:  a0 10 60 90  or  %g1, 0x90, %l0	! 0xa802d890
a0126944:  c0 28 60 90  clrb  [ %g1 + 0x90 ]
a0126948:  7f ff f7 e0  call  0xa01248c8
a012694c:  f0 2c 20 01  stb  %i0, [ %l0 + 1 ]
a0126950:  80 8a 20 ff  btst  0xff, %o0
a0126954:  11 00 06 91  sethi  %hi(0x1a4400), %o0
a0126958:  92 0e 20 ff  and  %i0, 0xff, %o1
a012695c:  02 80 00 0f  be  0xa0126998
a0126960:  90 12 21 68  or  %o0, 0x168, %o0
a0126964:  7f fe e2 03  call  0xa00df170
a0126968:  01 00 00 00  nop
a012696c:  92 10 20 02  mov  2, %o1	! 0x2
a0126970:  9a 10 20 01  mov  1, %o5
a0126974:  d2 23 a0 5c  st  %o1, [ %sp + 0x5c ]
a0126978:  da 23 a0 60  st  %o5, [ %sp + 0x60 ]
a012697c:  9a 10 00 10  mov  %l0, %o5
a0126980:  90 10 20 60  mov  0x60, %o0
a0126984:  92 10 20 02  mov  2, %o1
a0126988:  94 10 20 c2  mov  0xc2, %o2
a012698c:  96 10 20 05  mov  5, %o3
a0126990:  40 00 84 44  call  0xa0147aa0
a0126994:  98 10 20 00  clr  %o4
a0126998:  01 00 00 00  nop
a012699c:  81 c7 e0 08  ret
a01269a0:  81 e8 00 00  restore
