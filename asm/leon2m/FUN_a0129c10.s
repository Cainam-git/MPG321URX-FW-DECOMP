# leon2m FUN_a0129c10 0xa0129c10-0xa0129c64 (84 bytes)  [FUN_a0129c5c = unreachable ret/restore tail, merged]
a0129c10:  9d e3 bf 98  save  %sp, -104, %sp
a0129c14:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0129c18:  90 96 20 00  orcc  %i0, 0, %o0
a0129c1c:  02 80 00 04  be  0xa0129c2c
a0129c20:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a0129c24:  82 10 20 01  mov  1, %g1
a0129c28:  c2 2c 22 04  stb  %g1, [ %l0 + 0x204 ]
a0129c2c:  d2 0c 22 04  ldub  [ %l0 + 0x204 ], %o1
a0129c30:  80 a2 60 00  cmp  %o1, 0
a0129c34:  02 80 00 09  be  0xa0129c58
a0129c38:  01 00 00 00  nop
a0129c3c:  7f ff 5f dd  call  0xa0101bb0
a0129c40:  b0 10 20 01  mov  1, %i0	! 0x1
a0129c44:  80 8a 20 ff  btst  0xff, %o0
a0129c48:  12 80 00 04  bne  0xa0129c58
a0129c4c:  d0 2c 22 04  stb  %o0, [ %l0 + 0x204 ]
a0129c50:  7f ff 60 05  call  0xa0101c64
a0129c54:  81 e8 00 00  restore
a0129c58:  01 00 00 00  nop
a0129c5c:  81 c7 e0 08  ret
a0129c60:  81 e8 00 00  restore
