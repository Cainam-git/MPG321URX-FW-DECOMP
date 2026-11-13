# leon2s FUN_a00c8760 0xa00c8760-0xa00c87c0 (96 bytes)
a00c8760:  9d e3 bf 98  save  %sp, -104, %sp
a00c8764:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c8768:  94 10 20 08  mov  8, %o2
a00c876c:  92 10 20 74  mov  0x74, %o1
a00c8770:  96 10 20 02  mov  2, %o3
a00c8774:  7f ff fe 35  call  0xa00c8048
a00c8778:  90 10 00 10  mov  %l0, %o0
a00c877c:  b0 0a 20 ff  and  %o0, 0xff, %i0
a00c8780:  11 27 c7 07  sethi  %hi(0x9f1c1c00), %o0
a00c8784:  90 12 23 e0  or  %o0, 0x3e0, %o0	! 0x9f1c1fe0
a00c8788:  92 10 00 18  mov  %i0, %o1
a00c878c:  80 a6 20 00  cmp  %i0, 0
a00c8790:  02 80 00 06  be  0xa00c87a8
a00c8794:  94 10 20 02  mov  2, %o2
a00c8798:  40 3a ea 2b  call  0xa0f83044
a00c879c:  01 00 00 00  nop
a00c87a0:  10 80 00 06  b  0xa00c87b8
a00c87a4:  92 10 00 18  mov  %i0, %o1
a00c87a8:  92 10 00 19  mov  %i1, %o1
a00c87ac:  7f ff fe 93  call  0xa00c81f8
a00c87b0:  90 10 00 10  mov  %l0, %o0
a00c87b4:  92 10 20 00  clr  %o1
a00c87b8:  81 c7 e0 08  ret
a00c87bc:  91 e8 00 09  restore  %g0, %o1, %o0
