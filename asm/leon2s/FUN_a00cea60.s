# leon2s FUN_a00cea60 0xa00cea60-0xa00cec18 (440 bytes)
a00cea60:  9d e3 bf 88  save  %sp, -120, %sp
a00cea64:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cea68:  98 06 00 18  add  %i0, %i0, %o4
a00cea6c:  98 03 00 18  add  %o4, %i0, %o4
a00cea70:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00cea74:  96 12 e3 b0  or  %o3, 0x3b0, %o3	! 0xa8078bb0
a00cea78:  99 2b 20 03  sll  %o4, 3, %o4
a00cea7c:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00cea80:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cea84:  82 2b 40 01  andn  %o5, %g1, %g1
a00cea88:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cea8c:  82 10 40 0d  or  %g1, %o5, %g1
a00cea90:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cea94:  90 10 00 18  mov  %i0, %o0
a00cea98:  92 10 20 09  mov  9, %o1
a00cea9c:  7f ff e7 53  call  0xa00c87e8
a00ceaa0:  15 00 00 20  sethi  %hi(0x8000), %o2
a00ceaa4:  a2 10 20 00  clr  %l1
a00ceaa8:  90 10 00 18  mov  %i0, %o0
a00ceaac:  7f ff e3 31  call  0xa00c7770
a00ceab0:  92 10 20 01  mov  1, %o1
a00ceab4:  98 04 60 01  add  %l1, 1, %o4
a00ceab8:  a1 2c 60 10  sll  %l1, 0x10, %l0
a00ceabc:  9b 2b 20 10  sll  %o4, 0x10, %o5
a00ceac0:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a00ceac4:  a1 34 20 10  srl  %l0, 0x10, %l0
a00ceac8:  9b 33 60 10  srl  %o5, 0x10, %o5
a00ceacc:  82 10 60 88  or  %g1, 0x88, %g1
a00cead0:  d0 28 40 10  stb  %o0, [ %g1 + %l0 ]
a00cead4:  80 a3 60 1f  cmp  %o5, 0x1f
a00cead8:  08 bf ff f4  bleu  0xa00ceaa8
a00ceadc:  a2 10 00 0c  mov  %o4, %l1
a00ceae0:  a0 07 bf e8  add  %fp, -24, %l0
a00ceae4:  15 00 01 a4  sethi  %hi(0x69000), %o2
a00ceae8:  94 12 a2 f8  or  %o2, 0x2f8, %o2	! 0x692f8
a00ceaec:  90 10 20 00  clr  %o0
a00ceaf0:  92 10 20 90  mov  0x90, %o1
a00ceaf4:  96 10 20 0f  mov  0xf, %o3
a00ceaf8:  40 3b 1e 42  call  0xa0f96400
a00ceafc:  98 10 00 10  mov  %l0, %o4
a00ceb00:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00ceb04:  94 10 61 88  or  %g1, 0x188, %o2	! 0xa807cd88
a00ceb08:  a2 10 20 00  clr  %l1
a00ceb0c:  a4 07 bf f8  add  %fp, -8, %l2
a00ceb10:  99 2c 60 10  sll  %l1, 0x10, %o4
a00ceb14:  99 33 20 10  srl  %o4, 0x10, %o4
a00ceb18:  96 04 60 01  add  %l1, 1, %o3
a00ceb1c:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00ceb20:  82 04 80 0c  add  %l2, %o4, %g1
a00ceb24:  c2 08 7f f0  ldub  [ %g1 + -16 ], %g1
a00ceb28:  9b 33 60 10  srl  %o5, 0x10, %o5
a00ceb2c:  c2 2a 80 0c  stb  %g1, [ %o2 + %o4 ]
a00ceb30:  80 a3 60 0f  cmp  %o5, 0xf
a00ceb34:  08 bf ff f7  bleu  0xa00ceb10
a00ceb38:  a2 10 00 0b  mov  %o3, %l1
a00ceb3c:  15 00 01 a4  sethi  %hi(0x69000), %o2
a00ceb40:  94 12 a3 08  or  %o2, 0x308, %o2	! 0x69308
a00ceb44:  98 10 00 10  mov  %l0, %o4
a00ceb48:  90 10 20 00  clr  %o0
a00ceb4c:  92 10 20 90  mov  0x90, %o1
a00ceb50:  40 3b 1e 2c  call  0xa0f96400
a00ceb54:  96 10 20 0f  mov  0xf, %o3
a00ceb58:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00ceb5c:  94 10 61 88  or  %g1, 0x188, %o2	! 0xa807cd88
a00ceb60:  a2 10 20 00  clr  %l1
a00ceb64:  83 2c 60 10  sll  %l1, 0x10, %g1
a00ceb68:  83 30 60 10  srl  %g1, 0x10, %g1
a00ceb6c:  96 04 60 01  add  %l1, 1, %o3
a00ceb70:  98 04 80 01  add  %l2, %g1, %o4
a00ceb74:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00ceb78:  d8 0b 3f f0  ldub  [ %o4 + -16 ], %o4
a00ceb7c:  9b 33 60 10  srl  %o5, 0x10, %o5
a00ceb80:  82 00 40 0a  add  %g1, %o2, %g1
a00ceb84:  d8 28 60 10  stb  %o4, [ %g1 + 0x10 ]
a00ceb88:  80 a3 60 0f  cmp  %o5, 0xf
a00ceb8c:  08 bf ff f6  bleu  0xa00ceb64
a00ceb90:  a2 10 00 0b  mov  %o3, %l1
a00ceb94:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a00ceb98:  9e 10 60 88  or  %g1, 0x88, %o7	! 0xa807d088
a00ceb9c:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00ceba0:  9a 06 00 18  add  %i0, %i0, %o5
a00ceba4:  92 10 61 88  or  %g1, 0x188, %o1
a00ceba8:  9a 03 40 18  add  %o5, %i0, %o5
a00cebac:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00cebb0:  94 10 63 b0  or  %g1, 0x3b0, %o2	! 0xa8078bb0
a00cebb4:  91 2b 60 03  sll  %o5, 3, %o0
a00cebb8:  a2 10 20 00  clr  %l1
a00cebbc:  98 04 60 01  add  %l1, 1, %o4
a00cebc0:  9b 2b 20 10  sll  %o4, 0x10, %o5
a00cebc4:  83 2c 60 10  sll  %l1, 0x10, %g1
a00cebc8:  83 30 60 10  srl  %g1, 0x10, %g1
a00cebcc:  97 33 60 10  srl  %o5, 0x10, %o3
a00cebd0:  da 0a 40 01  ldub  [ %o1 + %g1 ], %o5
a00cebd4:  c2 0b c0 01  ldub  [ %o7 + %g1 ], %g1
a00cebd8:  80 a0 40 0d  cmp  %g1, %o5
a00cebdc:  02 80 00 0a  be  0xa00cec04
a00cebe0:  a2 10 00 0c  mov  %o4, %l1
a00cebe4:  1b 3f ff 3f  sethi  %hi(0xfffcfc00), %o5
a00cebe8:  c2 02 80 08  ld  [ %o2 + %o0 ], %g1
a00cebec:  9a 13 63 ff  or  %o5, 0x3ff, %o5
a00cebf0:  82 08 40 0d  and  %g1, %o5, %g1
a00cebf4:  1b 00 00 80  sethi  %hi(0x20000), %o5
a00cebf8:  82 10 40 0d  or  %g1, %o5, %g1
a00cebfc:  10 80 00 05  b  0xa00cec10
a00cec00:  c2 22 80 08  st  %g1, [ %o2 + %o0 ]
a00cec04:  80 a2 e0 1f  cmp  %o3, 0x1f
a00cec08:  08 bf ff ee  bleu  0xa00cebc0
a00cec0c:  98 04 60 01  add  %l1, 1, %o4
a00cec10:  81 c7 e0 08  ret
a00cec14:  81 e8 00 00  restore
