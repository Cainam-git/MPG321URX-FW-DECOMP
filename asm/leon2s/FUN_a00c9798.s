# leon2s FUN_a00c9798 0xa00c9798-0xa00c9810 (120 bytes)
a00c9798:  9d e3 bf 98  save  %sp, -104, %sp
a00c979c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c97a0:  94 10 20 70  mov  0x70, %o2
a00c97a4:  92 10 20 74  mov  0x74, %o1
a00c97a8:  96 10 20 02  mov  2, %o3
a00c97ac:  7f ff fa 27  call  0xa00c8048
a00c97b0:  90 10 00 18  mov  %i0, %o0
a00c97b4:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00c97b8:  94 10 20 02  mov  2, %o2
a00c97bc:  92 94 20 00  orcc  %l0, 0, %o1
a00c97c0:  02 80 00 07  be  0xa00c97dc
a00c97c4:  90 10 00 18  mov  %i0, %o0
a00c97c8:  11 27 c7 08  sethi  %hi(0x9f1c2000), %o0
a00c97cc:  40 3a e6 1e  call  0xa0f83044
a00c97d0:  90 12 20 b8  or  %o0, 0xb8, %o0	! 0x9f1c20b8
a00c97d4:  10 80 00 0c  b  0xa00c9804
a00c97d8:  b0 10 00 10  mov  %l0, %i0
a00c97dc:  7f ff fa 87  call  0xa00c81f8
a00c97e0:  92 10 00 19  mov  %i1, %o1
a00c97e4:  b2 0a 20 ff  and  %o0, 0xff, %i1
a00c97e8:  11 27 c7 08  sethi  %hi(0x9f1c2000), %o0
a00c97ec:  90 12 20 d8  or  %o0, 0xd8, %o0	! 0x9f1c20d8
a00c97f0:  92 96 60 00  orcc  %i1, 0, %o1
a00c97f4:  02 80 00 04  be  0xa00c9804
a00c97f8:  b0 10 20 00  clr  %i0
a00c97fc:  40 3a e6 12  call  0xa0f83044
a00c9800:  b0 10 00 19  mov  %i1, %i0
a00c9804:  01 00 00 00  nop
a00c9808:  81 c7 e0 08  ret
a00c980c:  81 e8 00 00  restore
