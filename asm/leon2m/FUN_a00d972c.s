# leon2m FUN_a00d972c 0xa00d972c-0xa00d9764 (56 bytes)
a00d972c:  9d e3 bf 98  save  %sp, -104, %sp
a00d9730:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d9734:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a00d9738:  d2 08 60 14  ldub  [ %g1 + 0x14 ], %o1
a00d973c:  80 a2 60 64  cmp  %o1, 0x64
a00d9740:  08 80 00 03  bleu  0xa00d974c
a00d9744:  90 10 20 02  mov  2, %o0
a00d9748:  92 10 20 64  mov  0x64, %o1
a00d974c:  d2 28 60 14  stb  %o1, [ %g1 + 0x14 ]
a00d9750:  40 01 c2 73  call  0xa014a11c
a00d9754:  92 0a 60 ff  and  %o1, 0xff, %o1
a00d9758:  7f ff ff 69  call  0xa00d94fc
a00d975c:  81 e8 00 00  restore
a00d9760:  01 00 00 00  nop
