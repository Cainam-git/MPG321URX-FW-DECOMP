# leon2s FUN_a00cdcdc 0xa00cdcdc-0xa00cdde0 (260 bytes)
a00cdcdc:  9d e3 bf 98  save  %sp, -104, %sp
a00cdce0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cdce4:  82 06 00 18  add  %i0, %i0, %g1
a00cdce8:  82 00 40 18  add  %g1, %i0, %g1
a00cdcec:  21 2a 01 e2  sethi  %hi(0xa8078800), %l0
a00cdcf0:  99 28 60 03  sll  %g1, 3, %o4
a00cdcf4:  96 14 23 b0  or  %l0, 0x3b0, %o3
a00cdcf8:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00cdcfc:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cdd00:  82 2b 40 01  andn  %o5, %g1, %g1
a00cdd04:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cdd08:  82 10 40 0d  or  %g1, %o5, %g1
a00cdd0c:  9b 30 60 13  srl  %g1, 0x13, %o5
a00cdd10:  80 8b 60 01  btst  1, %o5
a00cdd14:  12 80 00 1e  bne  0xa00cdd8c
a00cdd18:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cdd1c:  82 03 00 0b  add  %o4, %o3, %g1
a00cdd20:  7f ff f0 49  call  0xa00c9e44
a00cdd24:  d0 08 60 09  ldub  [ %g1 + 9 ], %o0
a00cdd28:  96 10 20 00  clr  %o3
a00cdd2c:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cdd30:  98 0a e0 ff  and  %o3, 0xff, %o4
a00cdd34:  82 10 61 88  or  %g1, 0x188, %g1
a00cdd38:  da 08 40 0c  ldub  [ %g1 + %o4 ], %o5
a00cdd3c:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a00cdd40:  82 10 60 88  or  %g1, 0x88, %g1	! 0xa807d088
a00cdd44:  96 02 e0 01  inc  %o3
a00cdd48:  c2 08 40 0c  ldub  [ %g1 + %o4 ], %g1
a00cdd4c:  80 a0 40 0d  cmp  %g1, %o5
a00cdd50:  02 80 00 0c  be  0xa00cdd80
a00cdd54:  94 0a e0 ff  and  %o3, 0xff, %o2
a00cdd58:  9a 06 00 18  add  %i0, %i0, %o5
a00cdd5c:  9a 03 40 18  add  %o5, %i0, %o5
a00cdd60:  96 14 23 b0  or  %l0, 0x3b0, %o3
a00cdd64:  9b 2b 60 03  sll  %o5, 3, %o5
a00cdd68:  d8 02 c0 0d  ld  [ %o3 + %o5 ], %o4
a00cdd6c:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cdd70:  82 2b 00 01  andn  %o4, %g1, %g1
a00cdd74:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a00cdd78:  7f ff e7 14  call  0xa00c79c8
a00cdd7c:  81 e8 00 00  restore
a00cdd80:  80 a2 a0 1f  cmp  %o2, 0x1f
a00cdd84:  08 bf ff eb  bleu  0xa00cdd30
a00cdd88:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cdd8c:  82 06 00 18  add  %i0, %i0, %g1
a00cdd90:  82 00 40 18  add  %g1, %i0, %g1
a00cdd94:  83 28 60 03  sll  %g1, 3, %g1
a00cdd98:  96 14 23 b0  or  %l0, 0x3b0, %o3
a00cdd9c:  da 02 c0 01  ld  [ %o3 + %g1 ], %o5
a00cdda0:  19 00 02 00  sethi  %hi(0x80000), %o4
a00cdda4:  9a 13 40 0c  or  %o5, %o4, %o5
a00cdda8:  a0 00 40 0b  add  %g1, %o3, %l0
a00cddac:  da 22 c0 01  st  %o5, [ %o3 + %g1 ]
a00cddb0:  13 2a 01 f3  sethi  %hi(0xa807cc00), %o1
a00cddb4:  92 12 62 56  or  %o1, 0x256, %o1	! 0xa807ce56
a00cddb8:  d0 0c 20 09  ldub  [ %l0 + 9 ], %o0
a00cddbc:  7f ff ef b7  call  0xa00c9c98
a00cddc0:  94 10 24 00  mov  0x400, %o2
a00cddc4:  d0 0c 20 09  ldub  [ %l0 + 9 ], %o0
a00cddc8:  7f ff ef 64  call  0xa00c9b58
a00cddcc:  92 10 24 00  mov  0x400, %o1
a00cddd0:  f0 0c 20 09  ldub  [ %l0 + 9 ], %i0
a00cddd4:  7f ff f0 05  call  0xa00c9de8
a00cddd8:  93 e8 24 00  restore  %g0, 0x400, %o1
a00cdddc:  01 00 00 00  nop
