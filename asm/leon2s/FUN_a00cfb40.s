# leon2s FUN_a00cfb40 0xa00cfb40-0xa00cfd38 (504 bytes)
a00cfb40:  9d e3 bf 88  save  %sp, -120, %sp
a00cfb44:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cfb48:  82 06 00 18  add  %i0, %i0, %g1
a00cfb4c:  82 00 40 18  add  %g1, %i0, %g1
a00cfb50:  27 2a 01 e2  sethi  %hi(0xa8078800), %l3
a00cfb54:  a1 28 60 03  sll  %g1, 3, %l0
a00cfb58:  a2 14 e3 b0  or  %l3, 0x3b0, %l1
a00cfb5c:  da 04 40 10  ld  [ %l1 + %l0 ], %o5
a00cfb60:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cfb64:  82 2b 40 01  andn  %o5, %g1, %g1
a00cfb68:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cfb6c:  82 10 40 0d  or  %g1, %o5, %g1
a00cfb70:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00cfb74:  7f ff ff eb  call  0xa00cfb20
a00cfb78:  90 10 20 0d  mov  0xd, %o0
a00cfb7c:  80 a2 20 32  cmp  %o0, 0x32
a00cfb80:  08 80 00 09  bleu  0xa00cfba4
a00cfb84:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00cfb88:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cfb8c:  82 10 40 0d  or  %g1, %o5, %g1
a00cfb90:  10 80 00 68  b  0xa00cfd30
a00cfb94:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00cfb98:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cfb9c:  10 80 00 60  b  0xa00cfd1c
a00cfba0:  82 2b 40 01  andn  %o5, %g1, %g1
a00cfba4:  a0 07 bf e8  add  %fp, -24, %l0
a00cfba8:  15 00 01 a5  sethi  %hi(0x69400), %o2
a00cfbac:  94 12 a0 73  or  %o2, 0x73, %o2	! 0x69473
a00cfbb0:  90 10 20 00  clr  %o0
a00cfbb4:  92 10 20 90  mov  0x90, %o1
a00cfbb8:  96 10 20 0f  mov  0xf, %o3
a00cfbbc:  40 3b 1a 11  call  0xa0f96400
a00cfbc0:  98 10 00 10  mov  %l0, %o4
a00cfbc4:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cfbc8:  94 10 61 88  or  %g1, 0x188, %o2	! 0xa807cd88
a00cfbcc:  a2 10 20 00  clr  %l1
a00cfbd0:  a4 07 bf f8  add  %fp, -8, %l2
a00cfbd4:  99 2c 60 10  sll  %l1, 0x10, %o4
a00cfbd8:  99 33 20 10  srl  %o4, 0x10, %o4
a00cfbdc:  96 04 60 01  add  %l1, 1, %o3
a00cfbe0:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00cfbe4:  82 04 80 0c  add  %l2, %o4, %g1
a00cfbe8:  c2 08 7f f0  ldub  [ %g1 + -16 ], %g1
a00cfbec:  9b 33 60 10  srl  %o5, 0x10, %o5
a00cfbf0:  c2 2a 80 0c  stb  %g1, [ %o2 + %o4 ]
a00cfbf4:  80 a3 60 0f  cmp  %o5, 0xf
a00cfbf8:  08 bf ff f7  bleu  0xa00cfbd4
a00cfbfc:  a2 10 00 0b  mov  %o3, %l1
a00cfc00:  15 00 01 a5  sethi  %hi(0x69400), %o2
a00cfc04:  94 12 a0 83  or  %o2, 0x83, %o2	! 0x69483
a00cfc08:  98 10 00 10  mov  %l0, %o4
a00cfc0c:  90 10 20 00  clr  %o0
a00cfc10:  92 10 20 90  mov  0x90, %o1
a00cfc14:  40 3b 19 fb  call  0xa0f96400
a00cfc18:  96 10 20 0f  mov  0xf, %o3
a00cfc1c:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cfc20:  94 10 61 88  or  %g1, 0x188, %o2	! 0xa807cd88
a00cfc24:  a2 10 20 00  clr  %l1
a00cfc28:  83 2c 60 10  sll  %l1, 0x10, %g1
a00cfc2c:  83 30 60 10  srl  %g1, 0x10, %g1
a00cfc30:  96 04 60 01  add  %l1, 1, %o3
a00cfc34:  98 04 80 01  add  %l2, %g1, %o4
a00cfc38:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00cfc3c:  d8 0b 3f f0  ldub  [ %o4 + -16 ], %o4
a00cfc40:  9b 33 60 10  srl  %o5, 0x10, %o5
a00cfc44:  82 00 40 0a  add  %g1, %o2, %g1
a00cfc48:  d8 28 60 10  stb  %o4, [ %g1 + 0x10 ]
a00cfc4c:  80 a3 60 0f  cmp  %o5, 0xf
a00cfc50:  08 bf ff f6  bleu  0xa00cfc28
a00cfc54:  a2 10 00 0b  mov  %o3, %l1
a00cfc58:  90 10 00 18  mov  %i0, %o0
a00cfc5c:  92 10 20 0e  mov  0xe, %o1
a00cfc60:  7f ff e2 e2  call  0xa00c87e8
a00cfc64:  15 00 00 20  sethi  %hi(0x8000), %o2
a00cfc68:  a2 10 20 00  clr  %l1
a00cfc6c:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a00cfc70:  a4 10 60 88  or  %g1, 0x88, %l2	! 0xa807d088
a00cfc74:  90 10 00 18  mov  %i0, %o0
a00cfc78:  7f ff de be  call  0xa00c7770
a00cfc7c:  92 10 20 01  mov  1, %o1
a00cfc80:  9a 04 60 01  add  %l1, 1, %o5
a00cfc84:  a1 2c 60 10  sll  %l1, 0x10, %l0
a00cfc88:  83 2b 60 10  sll  %o5, 0x10, %g1
a00cfc8c:  a1 34 20 10  srl  %l0, 0x10, %l0
a00cfc90:  83 30 60 10  srl  %g1, 0x10, %g1
a00cfc94:  d0 2c 80 10  stb  %o0, [ %l2 + %l0 ]
a00cfc98:  80 a0 60 1f  cmp  %g1, 0x1f
a00cfc9c:  08 bf ff f4  bleu  0xa00cfc6c
a00cfca0:  a2 10 00 0d  mov  %o5, %l1
a00cfca4:  82 06 00 18  add  %i0, %i0, %g1
a00cfca8:  90 00 40 18  add  %g1, %i0, %o0
a00cfcac:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cfcb0:  92 10 00 12  mov  %l2, %o1
a00cfcb4:  94 10 61 88  or  %g1, 0x188, %o2
a00cfcb8:  a2 10 20 00  clr  %l1
a00cfcbc:  98 04 60 01  add  %l1, 1, %o4
a00cfcc0:  9b 2b 20 10  sll  %o4, 0x10, %o5
a00cfcc4:  83 2c 60 10  sll  %l1, 0x10, %g1
a00cfcc8:  83 30 60 10  srl  %g1, 0x10, %g1
a00cfccc:  97 33 60 10  srl  %o5, 0x10, %o3
a00cfcd0:  da 0a 80 01  ldub  [ %o2 + %g1 ], %o5
a00cfcd4:  c2 0a 40 01  ldub  [ %o1 + %g1 ], %g1
a00cfcd8:  80 a0 40 0d  cmp  %g1, %o5
a00cfcdc:  02 80 00 12  be  0xa00cfd24
a00cfce0:  a2 10 00 0c  mov  %o4, %l1
a00cfce4:  98 14 e3 b0  or  %l3, 0x3b0, %o4
a00cfce8:  91 2a 20 03  sll  %o0, 3, %o0
a00cfcec:  82 02 00 0c  add  %o0, %o4, %g1
a00cfcf0:  da 00 60 10  ld  [ %g1 + 0x10 ], %o5
a00cfcf4:  03 00 3f ff  sethi  %hi(0xfffc00), %g1
a00cfcf8:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffffff
a00cfcfc:  80 a3 40 01  cmp  %o5, %g1
a00cfd00:  02 bf ff a6  be  0xa00cfb98
a00cfd04:  da 03 00 08  ld  [ %o4 + %o0 ], %o5
a00cfd08:  03 3f ff 3f  sethi  %hi(0xfffcfc00), %g1
a00cfd0c:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xfffcffff
a00cfd10:  82 0b 40 01  and  %o5, %g1, %g1
a00cfd14:  1b 00 00 80  sethi  %hi(0x20000), %o5
a00cfd18:  82 10 40 0d  or  %g1, %o5, %g1
a00cfd1c:  10 80 00 05  b  0xa00cfd30
a00cfd20:  c2 23 00 08  st  %g1, [ %o4 + %o0 ]
a00cfd24:  80 a2 e0 1f  cmp  %o3, 0x1f
a00cfd28:  08 bf ff e6  bleu  0xa00cfcc0
a00cfd2c:  98 04 60 01  add  %l1, 1, %o4
a00cfd30:  81 c7 e0 08  ret
a00cfd34:  81 e8 00 00  restore
