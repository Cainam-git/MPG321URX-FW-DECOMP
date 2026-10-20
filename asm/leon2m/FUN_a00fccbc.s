# leon2m FUN_a00fccbc 0xa00fccbc-0xa00fcdd8 (284 bytes)
a00fccbc:  9d e3 bf 68  save  %sp, -152, %sp
a00fccc0:  13 00 06 69  sethi  %hi(0x19a400), %o1
a00fccc4:  92 12 60 66  or  %o1, 0x66, %o1	! 0x19a466
a00fccc8:  94 10 20 30  mov  0x30, %o2
a00fcccc:  40 00 ff 11  call  0xa013c910
a00fccd0:  90 07 bf c8  add  %fp, -56, %o0
a00fccd4:  94 06 00 18  add  %i0, %i0, %o2
a00fccd8:  9a 02 80 18  add  %o2, %i0, %o5
a00fccdc:  15 33 c0 48  sethi  %hi(0xcf012000), %o2
a00fcce0:  96 07 bf f8  add  %fp, -8, %o3
a00fcce4:  92 03 40 0b  add  %o5, %o3, %o1
a00fcce8:  90 12 a0 84  or  %o2, 0x84, %o0
a00fccec:  82 10 20 32  mov  0x32, %g1
a00fccf0:  c2 22 00 00  st  %g1, [ %o0 ]
a00fccf4:  d8 0a 7f d0  ldub  [ %o1 + -48 ], %o4
a00fccf8:  b0 12 a0 88  or  %o2, 0x88, %i0
a00fccfc:  d8 26 00 00  st  %o4, [ %i0 ]
a00fcd00:  9e 12 a0 8c  or  %o2, 0x8c, %o7
a00fcd04:  e0 0a 7f d1  ldub  [ %o1 + -47 ], %l0
a00fcd08:  e0 23 c0 00  st  %l0, [ %o7 ]
a00fcd0c:  d6 0a 7f d2  ldub  [ %o1 + -46 ], %o3
a00fcd10:  90 12 a0 90  or  %o2, 0x90, %o0
a00fcd14:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a00fcd18:  d6 22 00 00  st  %o3, [ %o0 ]
a00fcd1c:  da 03 61 70  ld  [ %o5 + 0x170 ], %o5
a00fcd20:  98 12 a0 34  or  %o2, 0x34, %o4
a00fcd24:  82 10 20 2e  mov  0x2e, %g1
a00fcd28:  c2 23 00 00  st  %g1, [ %o4 ]
a00fcd2c:  80 a3 60 00  cmp  %o5, 0
a00fcd30:  12 80 00 1f  bne  0xa00fcdac
a00fcd34:  b0 12 a0 80  or  %o2, 0x80, %i0
a00fcd38:  98 10 20 0f  mov  0xf, %o4
a00fcd3c:  d8 26 00 00  st  %o4, [ %i0 ]
a00fcd40:  9e 12 a0 40  or  %o2, 0x40, %o7
a00fcd44:  a0 10 20 04  mov  4, %l0
a00fcd48:  e0 23 c0 00  st  %l0, [ %o7 ]
a00fcd4c:  67 fe 42 0f  call  0x4008d588
a00fcd50:  01 00 00 00  nop
a00fcd54:  03 33 c0 48  sethi  %hi(0xcf012000), %g1
a00fcd58:  82 10 60 34  or  %g1, 0x34, %g1	! 0xcf012034
a00fcd5c:  da 00 40 00  ld  [ %g1 ], %o5
a00fcd60:  80 8b 60 2e  btst  0x2e, %o5
a00fcd64:  12 80 00 16  bne  0xa00fcdbc
a00fcd68:  b1 2a 20 10  sll  %o0, 0x10, %i0
a00fcd6c:  a0 10 00 01  mov  %g1, %l0
a00fcd70:  67 fe 40 5a  call  0x4008ced8
a00fcd74:  01 00 00 00  nop
a00fcd78:  67 fe 42 07  call  0x4008d594
a00fcd7c:  91 36 20 10  srl  %i0, 0x10, %o0
a00fcd80:  97 2a 20 10  sll  %o0, 0x10, %o3
a00fcd84:  91 32 e0 10  srl  %o3, 0x10, %o0
a00fcd88:  80 a2 23 e8  cmp  %o0, 0x3e8
a00fcd8c:  38 80 00 0d  bgu,a   0xa00fcdc0
a00fcd90:  21 33 c0 48  sethi  %hi(0xcf012000), %l0
a00fcd94:  d4 04 00 00  ld  [ %l0 ], %o2
a00fcd98:  80 8a a0 2e  btst  0x2e, %o2
a00fcd9c:  02 bf ff f5  be  0xa00fcd70
a00fcda0:  01 00 00 00  nop
a00fcda4:  10 80 00 07  b  0xa00fcdc0
a00fcda8:  21 33 c0 48  sethi  %hi(0xcf012000), %l0
a00fcdac:  90 10 20 0f  mov  0xf, %o0
a00fcdb0:  9f c3 40 00  call  %o5
a00fcdb4:  92 10 20 04  mov  4, %o1
a00fcdb8:  30 bf ff e5  b,a   0xa00fcd4c
a00fcdbc:  21 33 c0 48  sethi  %hi(0xcf012000), %l0
a00fcdc0:  92 14 20 34  or  %l0, 0x34, %o1	! 0xcf012034
a00fcdc4:  d8 02 40 00  ld  [ %o1 ], %o4
a00fcdc8:  9e 10 20 2e  mov  0x2e, %o7
a00fcdcc:  de 22 40 00  st  %o7, [ %o1 ]
a00fcdd0:  81 c7 e0 08  ret
a00fcdd4:  81 e8 00 00  restore
