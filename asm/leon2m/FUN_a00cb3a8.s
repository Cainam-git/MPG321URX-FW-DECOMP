# leon2m FUN_a00cb3a8 0xa00cb3a8-0xa00cb438 (144 bytes)
a00cb3a8:  9d e3 bf 98  save  %sp, -104, %sp
a00cb3ac:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cb3b0:  80 a6 20 02  cmp  %i0, 2
a00cb3b4:  02 80 00 19  be  0xa00cb418
a00cb3b8:  80 a6 20 03  cmp  %i0, 3
a00cb3bc:  02 80 00 1a  be  0xa00cb424
a00cb3c0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cb3c4:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00cb3c8:  94 08 60 ff  and  %g1, 0xff, %o2
a00cb3cc:  98 02 bf d0  add  %o2, -48, %o4
a00cb3d0:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00cb3d4:  80 a3 60 01  cmp  %o5, 1
a00cb3d8:  18 80 00 16  bgu  0xa00cb430
a00cb3dc:  82 10 20 ff  mov  0xff, %g1
a00cb3e0:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a00cb3e4:  40 00 3e 07  call  0xa00dac00
a00cb3e8:  d8 2a e0 78  stb  %o4, [ %o3 + 0x78 ]	! 0xa802d478
a00cb3ec:  7f ff b5 38  call  0xa00b88cc
a00cb3f0:  01 00 00 00  nop
a00cb3f4:  7f ff bd 9e  call  0xa00baa6c
a00cb3f8:  90 10 00 18  mov  %i0, %o0
a00cb3fc:  7f ff bd 55  call  0xa00ba950
a00cb400:  90 10 00 18  mov  %i0, %o0
a00cb404:  90 10 00 18  mov  %i0, %o0
a00cb408:  7f ff bd de  call  0xa00bab80
a00cb40c:  92 10 20 06  mov  6, %o1
a00cb410:  10 80 00 08  b  0xa00cb430
a00cb414:  82 10 20 00  clr  %g1
a00cb418:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00cb41c:  10 bf ff eb  b  0xa00cb3c8
a00cb420:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00cb424:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cb428:  10 bf ff e8  b  0xa00cb3c8
a00cb42c:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00cb430:  81 c7 e0 08  ret
a00cb434:  91 e8 00 01  restore  %g0, %g1, %o0
