# leon2s FUN_a0073be8 0xa0073be8-0xa0073c24 (60 bytes)
a0073be8:  9d e3 bf 98  save  %sp, -104, %sp
a0073bec:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0073bf0:  15 00 00 07  sethi  %hi(0x1c00), %o2
a0073bf4:  94 12 a3 0c  or  %o2, 0x30c, %o2	! 0x1f0c
a0073bf8:  92 10 00 18  mov  %i0, %o1
a0073bfc:  40 00 ce 1b  call  0xa00a7468
a0073c00:  90 10 20 0e  mov  0xe, %o0
a0073c04:  80 a2 20 00  cmp  %o0, 0
a0073c08:  12 80 00 04  bne  0xa0073c18
a0073c0c:  b2 10 20 01  mov  1, %i1
a0073c10:  7f ff ff 03  call  0xa007381c
a0073c14:  81 e8 00 00  restore
a0073c18:  01 00 00 00  nop
a0073c1c:  81 c7 e0 08  ret
a0073c20:  81 e8 00 00  restore
