# leon2m FUN_a00deef0 0xa00deef0-0xa00def40 (80 bytes)
a00deef0:  9d e3 bf 98  save  %sp, -104, %sp
a00deef4:  03 00 03 ff  sethi  %hi(0xffc00), %g1
a00deef8:  a4 10 63 fe  or  %g1, 0x3fe, %l2	! 0xffffe
a00deefc:  a0 10 20 00  clr  %l0
a00def00:  10 80 00 05  b  0xa00def14
a00def04:  23 30 02 c0  sethi  %hi(0xc00b0000), %l1
a00def08:  80 a4 00 12  cmp  %l0, %l2
a00def0c:  18 80 00 08  bgu  0xa00def2c
a00def10:  b3 2e 20 18  sll  %i0, 0x18, %i1
a00def14:  67 fe b4 cf  call  0x4008c250
a00def18:  90 14 60 14  or  %l1, 0x14, %o0
a00def1c:  80 8a 20 20  btst  0x20, %o0
a00def20:  02 bf ff fa  be  0xa00def08
a00def24:  a0 04 20 01  inc  %l0
a00def28:  b3 2e 20 18  sll  %i0, 0x18, %i1
a00def2c:  b3 3e 60 18  sra  %i1, 0x18, %i1
a00def30:  31 30 02 c0  sethi  %hi(0xc00b0000), %i0
a00def34:  67 fe b4 ca  call  0x4008c25c
a00def38:  81 e8 00 00  restore
a00def3c:  01 00 00 00  nop
