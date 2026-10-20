# leon2s FUN_a00b04a8 0xa00b04a8-0xa00b0518 (112 bytes)
a00b04a8:  9d e3 bf 98  save  %sp, -104, %sp
a00b04ac:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00b04b0:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b04b4:  82 10 60 18  or  %g1, 0x18, %g1	! 0xa807dc18
a00b04b8:  a2 5e 21 2c  smul  %i0, 0x12c, %l1
a00b04bc:  a2 04 40 01  add  %l1, %g1, %l1
a00b04c0:  92 10 20 94  mov  0x94, %o1
a00b04c4:  7f ff da 39  call  0xa00a6da8
a00b04c8:  90 10 00 18  mov  %i0, %o0
a00b04cc:  d0 34 61 00  sth  %o0, [ %l1 + 0x100 ]
a00b04d0:  92 10 20 96  mov  0x96, %o1
a00b04d4:  7f ff da 35  call  0xa00a6da8
a00b04d8:  90 10 00 18  mov  %i0, %o0
a00b04dc:  d0 34 61 08  sth  %o0, [ %l1 + 0x108 ]
a00b04e0:  92 10 20 98  mov  0x98, %o1
a00b04e4:  90 10 00 18  mov  %i0, %o0
a00b04e8:  7f ff da 30  call  0xa00a6da8
a00b04ec:  21 00 00 1f  sethi  %hi(0x7c00), %l0
a00b04f0:  a0 14 23 ff  or  %l0, 0x3ff, %l0	! 0x7fff
a00b04f4:  90 0a 00 10  and  %o0, %l0, %o0
a00b04f8:  d0 34 61 06  sth  %o0, [ %l1 + 0x106 ]
a00b04fc:  90 10 00 18  mov  %i0, %o0
a00b0500:  7f ff da 2a  call  0xa00a6da8
a00b0504:  92 10 20 9a  mov  0x9a, %o1
a00b0508:  90 0a 00 10  and  %o0, %l0, %o0
a00b050c:  d0 34 61 0e  sth  %o0, [ %l1 + 0x10e ]
a00b0510:  81 c7 e0 08  ret
a00b0514:  81 e8 00 00  restore
