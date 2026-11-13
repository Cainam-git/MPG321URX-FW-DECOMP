# leon2m FUN_a00be250 0xa00be250-0xa00be2a0 (80 bytes)
a00be250:  9d e3 bf 98  save  %sp, -104, %sp
a00be254:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00be258:  d6 03 e3 3c  ld  [ %o7 + 0x33c ], %o3	! 0xa802d33c
a00be25c:  95 32 e0 12  srl  %o3, 0x12, %o2
a00be260:  90 0a a0 03  and  %o2, 3, %o0
a00be264:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00be268:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00be26c:  82 02 20 30  add  %o0, 0x30, %g1
a00be270:  98 10 20 30  mov  0x30, %o4
a00be274:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00be278:  d8 2b 60 08  stb  %o4, [ %o5 + 8 ]
a00be27c:  d8 2b 60 07  stb  %o4, [ %o5 + 7 ]
a00be280:  7f ff f2 6f  call  0xa00bac3c
a00be284:  90 10 20 6a  mov  0x6a, %o0
a00be288:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be28c:  7f ff f1 b1  call  0xa00ba950
a00be290:  90 10 00 18  mov  %i0, %o0
a00be294:  7f ff f2 54  call  0xa00babe4
a00be298:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be29c:  01 00 00 00  nop
