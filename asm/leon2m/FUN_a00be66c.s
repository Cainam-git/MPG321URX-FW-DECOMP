# leon2m FUN_a00be66c 0xa00be66c-0xa00be6b4 (72 bytes)
a00be66c:  9d e3 bf 98  save  %sp, -104, %sp
a00be670:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00be674:  d0 0a a0 79  ldub  [ %o2 + 0x79 ], %o0	! 0xa802d479
a00be678:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00be67c:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00be680:  98 02 20 2f  add  %o0, 0x2f, %o4
a00be684:  82 10 20 30  mov  0x30, %g1
a00be688:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00be68c:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00be690:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00be694:  7f ff f1 6a  call  0xa00bac3c
a00be698:  90 10 20 7d  mov  0x7d, %o0
a00be69c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be6a0:  7f ff f0 ac  call  0xa00ba950
a00be6a4:  90 10 00 18  mov  %i0, %o0
a00be6a8:  7f ff f1 4f  call  0xa00babe4
a00be6ac:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be6b0:  01 00 00 00  nop
