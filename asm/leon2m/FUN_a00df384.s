# leon2m FUN_a00df384 0xa00df384-0xa00df3d0 (76 bytes)
a00df384:  9d e3 bf 98  save  %sp, -104, %sp
a00df388:  b0 10 20 00  clr  %i0
a00df38c:  a0 10 20 00  clr  %l0
a00df390:  10 80 00 05  b  0xa00df3a4
a00df394:  23 30 02 c0  sethi  %hi(0xc00b0000), %l1
a00df398:  80 a4 23 e7  cmp  %l0, 0x3e7
a00df39c:  34 80 00 0b  bg,a   0xa00df3c8
a00df3a0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00df3a4:  67 fe b3 ab  call  0x4008c250
a00df3a8:  90 14 60 14  or  %l1, 0x14, %o0
a00df3ac:  80 8a 20 01  btst  1, %o0
a00df3b0:  02 bf ff fa  be  0xa00df398
a00df3b4:  a0 04 20 01  inc  %l0
a00df3b8:  67 fe b3 a6  call  0x4008c250
a00df3bc:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a00df3c0:  b0 10 00 08  mov  %o0, %i0
a00df3c4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00df3c8:  81 c7 e0 08  ret
a00df3cc:  81 e8 00 00  restore
