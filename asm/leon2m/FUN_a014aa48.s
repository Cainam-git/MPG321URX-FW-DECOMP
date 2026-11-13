# leon2m FUN_a014aa48 0xa014aa48-0xa014aa7c (52 bytes)
a014aa48:  90 0a 20 ff  and  %o0, 0xff, %o0
a014aa4c:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a014aa50:  80 a2 20 01  cmp  %o0, 1
a014aa54:  02 80 00 08  be  0xa014aa74
a014aa58:  82 10 61 90  or  %g1, 0x190, %g1
a014aa5c:  80 a2 20 02  cmp  %o0, 2
a014aa60:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a014aa64:  12 80 00 04  bne  0xa014aa74
a014aa68:  82 12 22 90  or  %o0, 0x290, %g1	! 0xa802ce90
a014aa6c:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a014aa70:  82 10 60 90  or  %g1, 0x90, %g1	! 0xa802cc90
a014aa74:  81 c3 e0 08  retl
a014aa78:  90 10 00 01  mov  %g1, %o0
