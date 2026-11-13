# leon2m FUN_a00df450 0xa00df450-0xa00df4d4 (132 bytes)
a00df450:  9d e3 bf 98  save  %sp, -104, %sp
a00df454:  c2 4e 00 00  ldsb  [ %i0 ], %g1
a00df458:  80 a0 60 00  cmp  %g1, 0
a00df45c:  02 80 00 1c  be  0xa00df4cc
a00df460:  01 00 00 00  nop
a00df464:  67 fe b3 7b  call  0x4008c250
a00df468:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a00df46c:  80 8a 20 20  btst  0x20, %o0
a00df470:  02 bf ff fd  be  0xa00df464
a00df474:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a00df478:  67 fe b3 79  call  0x4008c25c
a00df47c:  d2 4e 00 00  ldsb  [ %i0 ], %o1
a00df480:  d0 4e 00 00  ldsb  [ %i0 ], %o0
a00df484:  80 a2 20 0a  cmp  %o0, 0xa
a00df488:  02 80 00 08  be  0xa00df4a8
a00df48c:  01 00 00 00  nop
a00df490:  b0 06 20 01  inc  %i0
a00df494:  d2 4e 00 00  ldsb  [ %i0 ], %o1
a00df498:  80 a2 60 00  cmp  %o1, 0
a00df49c:  12 bf ff f2  bne  0xa00df464
a00df4a0:  01 00 00 00  nop
a00df4a4:  30 80 00 0a  b,a   0xa00df4cc
a00df4a8:  67 fe b3 6a  call  0x4008c250
a00df4ac:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a00df4b0:  80 8a 20 20  btst  0x20, %o0
a00df4b4:  02 bf ff fd  be  0xa00df4a8
a00df4b8:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a00df4bc:  67 fe b3 68  call  0x4008c25c
a00df4c0:  92 10 20 0d  mov  0xd, %o1
a00df4c4:  10 bf ff f4  b  0xa00df494
a00df4c8:  b0 06 20 01  inc  %i0
a00df4cc:  81 c7 e0 08  ret
a00df4d0:  81 e8 00 00  restore
