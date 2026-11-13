# leon2m FUN_a01268cc 0xa01268cc-0xa0126938 (108 bytes)
a01268cc:  9d e3 bf 90  save  %sp, -112, %sp
a01268d0:  03 2a 00 b6  sethi  %hi(0xa802d800), %g1
a01268d4:  a0 10 60 90  or  %g1, 0x90, %l0	! 0xa802d890
a01268d8:  c0 28 60 90  clrb  [ %g1 + 0x90 ]
a01268dc:  7f ff f7 fb  call  0xa01248c8
a01268e0:  f0 2c 20 01  stb  %i0, [ %l0 + 1 ]
a01268e4:  80 8a 20 ff  btst  0xff, %o0
a01268e8:  11 00 06 91  sethi  %hi(0x1a4400), %o0
a01268ec:  92 0e 20 ff  and  %i0, 0xff, %o1
a01268f0:  02 80 00 0f  be  0xa012692c
a01268f4:  90 12 21 40  or  %o0, 0x140, %o0
a01268f8:  7f fe e2 1e  call  0xa00df170
a01268fc:  01 00 00 00  nop
a0126900:  92 10 20 02  mov  2, %o1	! 0x2
a0126904:  9a 10 20 01  mov  1, %o5
a0126908:  d2 23 a0 5c  st  %o1, [ %sp + 0x5c ]
a012690c:  da 23 a0 60  st  %o5, [ %sp + 0x60 ]
a0126910:  9a 10 00 10  mov  %l0, %o5
a0126914:  90 10 20 60  mov  0x60, %o0
a0126918:  92 10 20 02  mov  2, %o1
a012691c:  94 10 20 c0  mov  0xc0, %o2
a0126920:  96 10 20 05  mov  5, %o3
a0126924:  40 00 84 5f  call  0xa0147aa0
a0126928:  98 10 20 00  clr  %o4
a012692c:  01 00 00 00  nop
a0126930:  81 c7 e0 08  ret
a0126934:  81 e8 00 00  restore
