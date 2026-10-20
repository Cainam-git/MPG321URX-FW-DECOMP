# leon2m FUN_a00df4d4 0xa00df4d4-0xa00df504 (48 bytes)
a00df4d4:  9d e3 bf 98  save  %sp, -104, %sp
a00df4d8:  21 30 02 c0  sethi  %hi(0xc00b0000), %l0
a00df4dc:  67 fe b3 5d  call  0x4008c250
a00df4e0:  90 14 20 14  or  %l0, 0x14, %o0	! 0xc00b0014
a00df4e4:  80 8a 20 20  btst  0x20, %o0
a00df4e8:  02 bf ff fd  be  0xa00df4dc
a00df4ec:  b3 2e 20 18  sll  %i0, 0x18, %i1
a00df4f0:  b3 3e 60 18  sra  %i1, 0x18, %i1
a00df4f4:  31 30 02 c0  sethi  %hi(0xc00b0000), %i0
a00df4f8:  67 fe b3 59  call  0x4008c25c
a00df4fc:  81 e8 00 00  restore
a00df500:  01 00 00 00  nop
