# leon2m FUN_a015e408 0xa015e408-0xa015e444 (60 bytes)
a015e408:  9d e3 bf 98  save  %sp, -104, %sp
a015e40c:  21 2a 00 b9  sethi  %hi(0xa802e400), %l0
a015e410:  c0 24 20 0c  clr  [ %l0 + 0xc ]	! 0xa802e40c
a015e414:  90 10 00 19  mov  %i1, %o0
a015e418:  40 00 00 f2  call  0xa015e7e0
a015e41c:  92 10 00 1a  mov  %i2, %o1
a015e420:  80 a2 3f ff  cmp  %o0, -1
a015e424:  12 80 00 06  bne  0xa015e43c
a015e428:  c2 04 20 0c  ld  [ %l0 + 0xc ], %g1
a015e42c:  80 a0 60 00  cmp  %g1, 0
a015e430:  02 80 00 03  be  0xa015e43c
a015e434:  01 00 00 00  nop
a015e438:  c2 26 00 00  st  %g1, [ %i0 ]
a015e43c:  81 c7 e0 08  ret
a015e440:  91 e8 00 08  restore  %g0, %o0, %o0
