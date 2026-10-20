# leon2m FUN_a00dd3d4 0xa00dd3d4-0xa00dd43c (104 bytes)  [FUN_a00dd434 = unreachable ret/restore tail, merged]
a00dd3d4:  9d e3 bf 98  save  %sp, -104, %sp
a00dd3d8:  11 00 06 62  sethi  %hi(0x198800), %o0
a00dd3dc:  a0 96 20 00  orcc  %i0, 0, %l0
a00dd3e0:  02 80 00 14  be  0xa00dd430
a00dd3e4:  90 12 23 88  or  %o0, 0x388, %o0
a00dd3e8:  40 00 06 d6  call  0xa00def40
a00dd3ec:  31 00 06 62  sethi  %hi(0x198800), %i0
a00dd3f0:  40 00 07 03  call  0xa00deffc
a00dd3f4:  90 10 00 10  mov  %l0, %o0
a00dd3f8:  03 00 06 62  sethi  %hi(0x198800), %g1
a00dd3fc:  40 00 06 d1  call  0xa00def40
a00dd400:  90 10 63 a0  or  %g1, 0x3a0, %o0	! 0x198ba0
a00dd404:  90 10 00 19  mov  %i1, %o0
a00dd408:  80 8c 20 03  btst  3, %l0
a00dd40c:  02 80 00 04  be  0xa00dd41c
a00dd410:  b0 16 23 90  or  %i0, 0x390, %i0
a00dd414:  40 00 06 cb  call  0xa00def40
a00dd418:  81 e8 00 00  restore
a00dd41c:  40 00 06 f8  call  0xa00deffc
a00dd420:  f2 24 00 00  st  %i1, [ %l0 ]
a00dd424:  13 00 03 fb  sethi  %hi(0xfec00), %o1
a00dd428:  40 00 06 c6  call  0xa00def40
a00dd42c:  91 ea 63 90  restore  %o1, 0x390, %o0
a00dd430:  01 00 00 00  nop
a00dd434:  81 c7 e0 08  ret
a00dd438:  81 e8 00 00  restore
