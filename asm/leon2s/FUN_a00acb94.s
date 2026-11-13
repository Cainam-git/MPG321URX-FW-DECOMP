# leon2s FUN_a00acb94 0xa00acb94-0xa00acc54 (192 bytes)
a00acb94:  9d e3 bf 98  save  %sp, -104, %sp
a00acb98:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00acb9c:  90 10 00 18  mov  %i0, %o0
a00acba0:  7f ff e8 f6  call  0xa00a6f78
a00acba4:  92 10 20 05  mov  5, %o1
a00acba8:  80 8a 20 04  btst  4, %o0
a00acbac:  02 80 00 10  be  0xa00acbec
a00acbb0:  90 10 00 18  mov  %i0, %o0
a00acbb4:  7f ff e8 01  call  0xa00a6bb8
a00acbb8:  92 10 20 8e  mov  0x8e, %o1
a00acbbc:  80 8a 20 40  btst  0x40, %o0
a00acbc0:  02 80 00 0b  be  0xa00acbec
a00acbc4:  90 10 00 18  mov  %i0, %o0
a00acbc8:  92 10 20 be  mov  0xbe, %o1
a00acbcc:  94 10 20 80  mov  0x80, %o2
a00acbd0:  7f ff e8 32  call  0xa00a6c98
a00acbd4:  96 10 20 01  mov  1, %o3
a00acbd8:  90 10 00 18  mov  %i0, %o0
a00acbdc:  7f ff e7 f7  call  0xa00a6bb8
a00acbe0:  92 10 20 bd  mov  0xbd, %o1
a00acbe4:  10 80 00 06  b  0xa00acbfc
a00acbe8:  82 0a 20 07  and  %o0, 7, %g1
a00acbec:  7f ff e7 f3  call  0xa00a6bb8
a00acbf0:  92 10 20 8d  mov  0x8d, %o1
a00acbf4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00acbf8:  83 32 20 05  srl  %o0, 5, %g1
a00acbfc:  82 08 60 ff  and  %g1, 0xff, %g1
a00acc00:  80 a0 60 04  cmp  %g1, 4
a00acc04:  18 80 00 11  bgu  0xa00acc48
a00acc08:  b0 10 20 08  mov  8, %i0
a00acc0c:  1b 28 02 b2  sethi  %hi(0xa00ac800), %o5
a00acc10:  83 28 60 02  sll  %g1, 2, %g1
a00acc14:  9a 13 63 80  or  %o5, 0x380, %o5
a00acc18:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00acc1c:  81 c0 40 00  jmp  %g1
a00acc20:  01 00 00 00  nop
a00acc24:  10 80 00 09  b  0xa00acc48
a00acc28:  b0 10 20 06  mov  6, %i0	! 0x6
a00acc2c:  10 80 00 07  b  0xa00acc48
a00acc30:  b0 10 20 08  mov  8, %i0
a00acc34:  10 80 00 05  b  0xa00acc48
a00acc38:  b0 10 20 0a  mov  0xa, %i0
a00acc3c:  10 80 00 03  b  0xa00acc48
a00acc40:  b0 10 20 0c  mov  0xc, %i0
a00acc44:  b0 10 20 10  mov  0x10, %i0
a00acc48:  b0 0e 20 1e  and  %i0, 0x1e, %i0
a00acc4c:  81 c7 e0 08  ret
a00acc50:  81 e8 00 00  restore
