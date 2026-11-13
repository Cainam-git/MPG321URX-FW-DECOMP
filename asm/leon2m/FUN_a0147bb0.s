# leon2m FUN_a0147bb0 0xa0147bb0-0xa0147c38 (92 bytes)
a0147bb0:  9d e3 bf 98  save  %sp, -104, %sp
a0147bb4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0147bb8:  99 2e 20 04  sll  %i0, 4, %o4
a0147bbc:  96 23 00 18  sub  %o4, %i0, %o3
a0147bc0:  15 2a 00 b7  sethi  %hi(0xa802dc00), %o2
a0147bc4:  82 12 a3 30  or  %o2, 0x330, %g1	! 0xa802df30
a0147bc8:  9b 2a e0 03  sll  %o3, 3, %o5
a0147bcc:  d2 00 40 0d  ld  [ %g1 + %o5 ], %o1
a0147bd0:  91 32 60 0c  srl  %o1, 0xc, %o0
a0147bd4:  7f ff ec ae  call  0xa0142e8c
a0147bd8:  90 0a 20 0f  and  %o0, 0xf, %o0
a0147bdc:  82 0a 20 ff  and  %o0, 0xff, %g1
a0147be0:  80 a0 60 05  cmp  %g1, 5
a0147be4:  38 80 00 13  bgu,a   0xa0147c30
a0147be8:  b0 10 20 06  mov  6, %i0
a0147bec:  1b 00 03 8d  sethi  %hi(0xe3400), %o5
a0147bf0:  91 28 60 02  sll  %g1, 2, %o0
a0147bf4:  92 13 60 38  or  %o5, 0x38, %o1
a0147bf8:  de 02 40 08  ld  [ %o1 + %o0 ], %o7
a0147bfc:  81 c3 c0 00  jmp  %o7
a0147c00:  01 00 00 00  nop
a0147c04:  10 80 00 0b  b  0xa0147c30
a0147c08:  b0 10 20 06  mov  6, %i0	! 0x6
a0147c0c:  10 80 00 09  b  0xa0147c30
a0147c10:  b0 10 20 05  mov  5, %i0
a0147c14:  10 80 00 07  b  0xa0147c30
a0147c18:  b0 10 20 01  mov  1, %i0
a0147c1c:  10 80 00 05  b  0xa0147c30
a0147c20:  b0 10 20 02  mov  2, %i0
a0147c24:  10 80 00 03  b  0xa0147c30
a0147c28:  b0 10 20 03  mov  3, %i0
a0147c2c:  b0 10 20 04  mov  4, %i0
a0147c30:  81 c7 e0 08  ret
a0147c34:  81 e8 00 00  restore
