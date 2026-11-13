# leon2m FUN_a00df3d0 0xa00df3d0-0xa00df420 (80 bytes)
a00df3d0:  9d e3 bf 98  save  %sp, -104, %sp
a00df3d4:  91 2e 20 18  sll  %i0, 0x18, %o0
a00df3d8:  83 3a 20 18  sra  %o0, 0x18, %g1
a00df3dc:  80 a0 60 0a  cmp  %g1, 0xa
a00df3e0:  02 80 00 0c  be  0xa00df410
a00df3e4:  01 00 00 00  nop
a00df3e8:  21 30 02 c0  sethi  %hi(0xc00b0000), %l0
a00df3ec:  67 fe b3 99  call  0x4008c250
a00df3f0:  90 14 20 14  or  %l0, 0x14, %o0	! 0xc00b0014
a00df3f4:  80 8a 20 20  btst  0x20, %o0
a00df3f8:  02 bf ff fd  be  0xa00df3ec
a00df3fc:  b3 2e 20 18  sll  %i0, 0x18, %i1
a00df400:  b3 3e 60 18  sra  %i1, 0x18, %i1
a00df404:  31 30 02 c0  sethi  %hi(0xc00b0000), %i0
a00df408:  67 fe b3 95  call  0x4008c25c
a00df40c:  81 e8 00 00  restore
a00df410:  7f ff ff f0  call  0xa00df3d0
a00df414:  90 10 20 0d  mov  0xd, %o0
a00df418:  10 bf ff f5  b  0xa00df3ec
a00df41c:  21 30 02 c0  sethi  %hi(0xc00b0000), %l0
