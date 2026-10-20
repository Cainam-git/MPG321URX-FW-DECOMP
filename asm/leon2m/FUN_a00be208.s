# leon2m FUN_a00be208 0xa00be208-0xa00be250 (72 bytes)
a00be208:  9d e3 bf 98  save  %sp, -104, %sp
a00be20c:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00be210:  d0 0a a0 0c  ldub  [ %o2 + 0xc ], %o0	! 0xa802d40c
a00be214:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00be218:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00be21c:  98 02 20 30  add  %o0, 0x30, %o4
a00be220:  82 10 20 30  mov  0x30, %g1
a00be224:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00be228:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00be22c:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00be230:  7f ff f2 83  call  0xa00bac3c
a00be234:  90 10 20 65  mov  0x65, %o0
a00be238:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be23c:  7f ff f1 c5  call  0xa00ba950
a00be240:  90 10 00 18  mov  %i0, %o0
a00be244:  7f ff f2 68  call  0xa00babe4
a00be248:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be24c:  01 00 00 00  nop
