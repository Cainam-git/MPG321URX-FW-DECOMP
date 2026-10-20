# leon2m FUN_a00bab80 0xa00bab80-0xa00babe0 (96 bytes)
a00bab80:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00bab84:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bab88:  82 10 00 09  mov  %o1, %g1
a00bab8c:  94 12 a1 28  or  %o2, 0x128, %o2
a00bab90:  90 10 20 02  mov  2, %o0
a00bab94:  80 a3 60 02  cmp  %o5, 2
a00bab98:  02 80 00 0b  be  0xa00babc4
a00bab9c:  92 0a 60 ff  and  %o1, 0xff, %o1
a00baba0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00baba4:  94 12 21 08  or  %o0, 0x108, %o2	! 0xa802d108
a00baba8:  92 08 60 ff  and  %g1, 0xff, %o1
a00babac:  80 a3 60 03  cmp  %o5, 3
a00babb0:  02 80 00 08  be  0xa00babd0
a00babb4:  90 10 00 0d  mov  %o5, %o0
a00babb8:  92 08 60 ff  and  %g1, 0xff, %o1
a00babbc:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00babc0:  94 10 60 78  or  %g1, 0x78, %o2	! 0xa802d078
a00babc4:  82 13 c0 00  mov  %o7, %g1
a00babc8:  40 02 37 08  call  0xa01487e8
a00babcc:  9e 10 40 00  mov  %g1, %o7
a00babd0:  90 10 20 03  mov  3, %o0
a00babd4:  82 13 c0 00  mov  %o7, %g1
a00babd8:  40 02 37 04  call  0xa01487e8
a00babdc:  9e 10 40 00  mov  %g1, %o7
