# leon2s FUN_a008fea8 0xa008fea8-0xa008ff08 (96 bytes)
a008fea8:  9d e3 bf 98  save  %sp, -104, %sp
a008feac:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008feb0:  92 10 21 34  mov  0x134, %o1
a008feb4:  40 00 59 b2  call  0xa00a657c
a008feb8:  90 10 00 18  mov  %i0, %o0
a008febc:  80 8a 20 02  btst  2, %o0
a008fec0:  92 10 21 40  mov  0x140, %o1
a008fec4:  02 80 00 0d  be  0xa008fef8
a008fec8:  90 10 00 18  mov  %i0, %o0
a008fecc:  40 00 59 ac  call  0xa00a657c
a008fed0:  01 00 00 00  nop
a008fed4:  82 0a 20 ff  and  %o0, 0xff, %g1
a008fed8:  80 a0 60 82  cmp  %g1, 0x82
a008fedc:  12 80 00 07  bne  0xa008fef8
a008fee0:  90 10 00 18  mov  %i0, %o0
a008fee4:  7f ff ff 1e  call  0xa008fb5c
a008fee8:  b0 10 20 01  mov  1, %i0
a008feec:  80 8a 20 ff  btst  0xff, %o0
a008fef0:  12 80 00 04  bne  0xa008ff00
a008fef4:  b0 0e 20 01  and  %i0, 1, %i0
a008fef8:  b0 10 20 00  clr  %i0
a008fefc:  b0 0e 20 01  and  %i0, 1, %i0
a008ff00:  81 c7 e0 08  ret
a008ff04:  81 e8 00 00  restore
