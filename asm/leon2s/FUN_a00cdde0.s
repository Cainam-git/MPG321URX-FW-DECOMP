# leon2s FUN_a00cdde0 0xa00cdde0-0xa00ce420 (1600 bytes)
a00cdde0:  9d e3 bf 90  save  %sp, -112, %sp
a00cdde4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cdde8:  9a 06 00 18  add  %i0, %i0, %o5
a00cddec:  9a 03 40 18  add  %o5, %i0, %o5
a00cddf0:  27 2a 01 e2  sethi  %hi(0xa8078800), %l3
a00cddf4:  9b 2b 60 03  sll  %o5, 3, %o5
a00cddf8:  96 14 e3 b0  or  %l3, 0x3b0, %o3
a00cddfc:  d8 02 c0 0d  ld  [ %o3 + %o5 ], %o4
a00cde00:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cde04:  82 2b 00 01  andn  %o4, %g1, %g1
a00cde08:  19 00 00 40  sethi  %hi(0x10000), %o4
a00cde0c:  82 10 40 0c  or  %g1, %o4, %g1
a00cde10:  a0 03 40 0b  add  %o5, %o3, %l0
a00cde14:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a00cde18:  7f ff e6 71  call  0xa00c77dc
a00cde1c:  d0 0c 20 09  ldub  [ %l0 + 9 ], %o0
a00cde20:  7f ff ef aa  call  0xa00c9cc8
a00cde24:  d0 0c 20 09  ldub  [ %l0 + 9 ], %o0
a00cde28:  10 80 00 0c  b  0xa00cde58
a00cde2c:  a4 10 20 1e  mov  0x1e, %l2
a00cde30:  40 3b ce 59  call  0xa0fc1794
a00cde34:  01 00 00 00  nop
a00cde38:  80 8c a0 ff  btst  0xff, %l2
a00cde3c:  12 80 00 08  bne  0xa00cde5c
a00cde40:  82 06 00 18  add  %i0, %i0, %g1
a00cde44:  da 04 40 10  ld  [ %l1 + %l0 ], %o5
a00cde48:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cde4c:  82 2b 40 01  andn  %o5, %g1, %g1
a00cde50:  10 80 00 0f  b  0xa00cde8c
a00cde54:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00cde58:  82 06 00 18  add  %i0, %i0, %g1
a00cde5c:  82 00 40 18  add  %g1, %i0, %g1
a00cde60:  a1 28 60 03  sll  %g1, 3, %l0
a00cde64:  a2 14 e3 b0  or  %l3, 0x3b0, %l1
a00cde68:  82 04 00 11  add  %l0, %l1, %g1
a00cde6c:  13 2a 01 f3  sethi  %hi(0xa807cc00), %o1
a00cde70:  92 12 62 50  or  %o1, 0x250, %o1	! 0xa807ce50
a00cde74:  7f ff d1 85  call  0xa00c2488
a00cde78:  d0 08 60 09  ldub  [ %g1 + 9 ], %o0
a00cde7c:  80 8a 20 ff  btst  0xff, %o0
a00cde80:  a4 04 bf ff  add  %l2, -1, %l2
a00cde84:  02 bf ff eb  be  0xa00cde30
a00cde88:  90 10 20 0a  mov  0xa, %o0
a00cde8c:  03 00 01 a4  sethi  %hi(0x69000), %g1
a00cde90:  a0 10 62 20  or  %g1, 0x220, %l0	! 0x69220
a00cde94:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cde98:  94 10 62 50  or  %g1, 0x250, %o2	! 0xa807ce50
a00cde9c:  9a 10 20 00  clr  %o5
a00cdea0:  a4 07 bf f8  add  %fp, -8, %l2
a00cdea4:  96 03 60 01  add  %o5, 1, %o3
a00cdea8:  83 2b 60 10  sll  %o5, 0x10, %g1
a00cdeac:  83 30 60 10  srl  %g1, 0x10, %g1
a00cdeb0:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00cdeb4:  d8 0a 80 01  ldub  [ %o2 + %g1 ], %o4
a00cdeb8:  9b 33 60 10  srl  %o5, 0x10, %o5
a00cdebc:  82 04 80 01  add  %l2, %g1, %g1
a00cdec0:  80 a3 60 07  cmp  %o5, 7
a00cdec4:  d8 28 7f f8  stb  %o4, [ %g1 + -8 ]
a00cdec8:  08 bf ff f7  bleu  0xa00cdea4
a00cdecc:  9a 10 00 0b  mov  %o3, %o5
a00cded0:  a2 07 bf f0  add  %fp, -16, %l1
a00cded4:  94 10 00 10  mov  %l0, %o2
a00cded8:  90 10 20 00  clr  %o0
a00cdedc:  92 10 20 80  mov  0x80, %o1
a00cdee0:  96 10 20 07  mov  7, %o3
a00cdee4:  40 3b 21 3c  call  0xa0f963d4
a00cdee8:  98 10 00 11  mov  %l1, %o4
a00cdeec:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cdef0:  a0 04 20 08  add  %l0, 8, %l0
a00cdef4:  94 10 62 50  or  %g1, 0x250, %o2
a00cdef8:  9a 10 20 00  clr  %o5
a00cdefc:  83 2b 60 10  sll  %o5, 0x10, %g1
a00cdf00:  96 03 60 01  add  %o5, 1, %o3
a00cdf04:  83 30 60 10  srl  %g1, 0x10, %g1
a00cdf08:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00cdf0c:  98 00 40 0a  add  %g1, %o2, %o4
a00cdf10:  9b 33 60 10  srl  %o5, 0x10, %o5
a00cdf14:  d8 0b 20 08  ldub  [ %o4 + 8 ], %o4
a00cdf18:  82 04 80 01  add  %l2, %g1, %g1
a00cdf1c:  80 a3 60 07  cmp  %o5, 7
a00cdf20:  d8 28 7f f8  stb  %o4, [ %g1 + -8 ]
a00cdf24:  08 bf ff f6  bleu  0xa00cdefc
a00cdf28:  9a 10 00 0b  mov  %o3, %o5
a00cdf2c:  94 10 00 10  mov  %l0, %o2
a00cdf30:  90 10 20 00  clr  %o0
a00cdf34:  92 10 20 80  mov  0x80, %o1
a00cdf38:  96 10 20 07  mov  7, %o3
a00cdf3c:  40 3b 21 26  call  0xa0f963d4
a00cdf40:  98 10 00 11  mov  %l1, %o4
a00cdf44:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cdf48:  a0 04 20 08  add  %l0, 8, %l0
a00cdf4c:  94 10 62 50  or  %g1, 0x250, %o2
a00cdf50:  9a 10 20 00  clr  %o5
a00cdf54:  83 2b 60 10  sll  %o5, 0x10, %g1
a00cdf58:  96 03 60 01  add  %o5, 1, %o3
a00cdf5c:  83 30 60 10  srl  %g1, 0x10, %g1
a00cdf60:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00cdf64:  98 00 40 0a  add  %g1, %o2, %o4
a00cdf68:  9b 33 60 10  srl  %o5, 0x10, %o5
a00cdf6c:  d8 0b 20 10  ldub  [ %o4 + 0x10 ], %o4
a00cdf70:  82 04 80 01  add  %l2, %g1, %g1
a00cdf74:  80 a3 60 07  cmp  %o5, 7
a00cdf78:  d8 28 7f f8  stb  %o4, [ %g1 + -8 ]
a00cdf7c:  08 bf ff f6  bleu  0xa00cdf54
a00cdf80:  9a 10 00 0b  mov  %o3, %o5
a00cdf84:  94 10 00 10  mov  %l0, %o2
a00cdf88:  90 10 20 00  clr  %o0
a00cdf8c:  92 10 20 80  mov  0x80, %o1
a00cdf90:  96 10 20 07  mov  7, %o3
a00cdf94:  40 3b 21 10  call  0xa0f963d4
a00cdf98:  98 10 00 11  mov  %l1, %o4
a00cdf9c:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cdfa0:  a0 04 20 08  add  %l0, 8, %l0
a00cdfa4:  94 10 62 50  or  %g1, 0x250, %o2
a00cdfa8:  9a 10 20 00  clr  %o5
a00cdfac:  83 2b 60 10  sll  %o5, 0x10, %g1
a00cdfb0:  96 03 60 01  add  %o5, 1, %o3
a00cdfb4:  83 30 60 10  srl  %g1, 0x10, %g1
a00cdfb8:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00cdfbc:  98 00 40 0a  add  %g1, %o2, %o4
a00cdfc0:  9b 33 60 10  srl  %o5, 0x10, %o5
a00cdfc4:  d8 0b 20 18  ldub  [ %o4 + 0x18 ], %o4
a00cdfc8:  82 04 80 01  add  %l2, %g1, %g1
a00cdfcc:  80 a3 60 07  cmp  %o5, 7
a00cdfd0:  d8 28 7f f8  stb  %o4, [ %g1 + -8 ]
a00cdfd4:  08 bf ff f6  bleu  0xa00cdfac
a00cdfd8:  9a 10 00 0b  mov  %o3, %o5
a00cdfdc:  94 10 00 10  mov  %l0, %o2
a00cdfe0:  90 10 20 00  clr  %o0
a00cdfe4:  92 10 20 80  mov  0x80, %o1
a00cdfe8:  96 10 20 07  mov  7, %o3
a00cdfec:  40 3b 20 fa  call  0xa0f963d4
a00cdff0:  98 10 00 11  mov  %l1, %o4
a00cdff4:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cdff8:  a0 04 20 08  add  %l0, 8, %l0
a00cdffc:  94 10 62 50  or  %g1, 0x250, %o2
a00ce000:  9a 10 20 00  clr  %o5
a00ce004:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ce008:  96 03 60 01  add  %o5, 1, %o3
a00ce00c:  83 30 60 10  srl  %g1, 0x10, %g1
a00ce010:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00ce014:  98 00 40 0a  add  %g1, %o2, %o4
a00ce018:  9b 33 60 10  srl  %o5, 0x10, %o5
a00ce01c:  d8 0b 20 20  ldub  [ %o4 + 0x20 ], %o4
a00ce020:  82 04 80 01  add  %l2, %g1, %g1
a00ce024:  80 a3 60 07  cmp  %o5, 7
a00ce028:  d8 28 7f f8  stb  %o4, [ %g1 + -8 ]
a00ce02c:  08 bf ff f6  bleu  0xa00ce004
a00ce030:  9a 10 00 0b  mov  %o3, %o5
a00ce034:  94 10 00 10  mov  %l0, %o2
a00ce038:  90 10 20 00  clr  %o0
a00ce03c:  92 10 20 80  mov  0x80, %o1
a00ce040:  96 10 20 07  mov  7, %o3
a00ce044:  40 3b 20 e4  call  0xa0f963d4
a00ce048:  98 10 00 11  mov  %l1, %o4
a00ce04c:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00ce050:  a0 04 20 08  add  %l0, 8, %l0
a00ce054:  94 10 62 50  or  %g1, 0x250, %o2
a00ce058:  9a 10 20 00  clr  %o5
a00ce05c:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ce060:  96 03 60 01  add  %o5, 1, %o3
a00ce064:  83 30 60 10  srl  %g1, 0x10, %g1
a00ce068:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00ce06c:  98 00 40 0a  add  %g1, %o2, %o4
a00ce070:  9b 33 60 10  srl  %o5, 0x10, %o5
a00ce074:  d8 0b 20 28  ldub  [ %o4 + 0x28 ], %o4
a00ce078:  82 04 80 01  add  %l2, %g1, %g1
a00ce07c:  80 a3 60 07  cmp  %o5, 7
a00ce080:  d8 28 7f f8  stb  %o4, [ %g1 + -8 ]
a00ce084:  08 bf ff f6  bleu  0xa00ce05c
a00ce088:  9a 10 00 0b  mov  %o3, %o5
a00ce08c:  94 10 00 10  mov  %l0, %o2
a00ce090:  90 10 20 00  clr  %o0
a00ce094:  92 10 20 80  mov  0x80, %o1
a00ce098:  96 10 20 07  mov  7, %o3
a00ce09c:  40 3b 20 ce  call  0xa0f963d4
a00ce0a0:  98 10 00 11  mov  %l1, %o4
a00ce0a4:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00ce0a8:  a0 04 20 08  add  %l0, 8, %l0
a00ce0ac:  94 10 62 50  or  %g1, 0x250, %o2
a00ce0b0:  9a 10 20 00  clr  %o5
a00ce0b4:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ce0b8:  96 03 60 01  add  %o5, 1, %o3
a00ce0bc:  83 30 60 10  srl  %g1, 0x10, %g1
a00ce0c0:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00ce0c4:  98 00 40 0a  add  %g1, %o2, %o4
a00ce0c8:  9b 33 60 10  srl  %o5, 0x10, %o5
a00ce0cc:  d8 0b 20 30  ldub  [ %o4 + 0x30 ], %o4
a00ce0d0:  82 04 80 01  add  %l2, %g1, %g1
a00ce0d4:  80 a3 60 07  cmp  %o5, 7
a00ce0d8:  d8 28 7f f8  stb  %o4, [ %g1 + -8 ]
a00ce0dc:  08 bf ff f6  bleu  0xa00ce0b4
a00ce0e0:  9a 10 00 0b  mov  %o3, %o5
a00ce0e4:  94 10 00 10  mov  %l0, %o2
a00ce0e8:  90 10 20 00  clr  %o0
a00ce0ec:  92 10 20 80  mov  0x80, %o1
a00ce0f0:  96 10 20 07  mov  7, %o3
a00ce0f4:  40 3b 20 b8  call  0xa0f963d4
a00ce0f8:  98 10 00 11  mov  %l1, %o4
a00ce0fc:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00ce100:  a0 04 20 08  add  %l0, 8, %l0
a00ce104:  94 10 62 50  or  %g1, 0x250, %o2
a00ce108:  9a 10 20 00  clr  %o5
a00ce10c:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ce110:  96 03 60 01  add  %o5, 1, %o3
a00ce114:  83 30 60 10  srl  %g1, 0x10, %g1
a00ce118:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00ce11c:  98 00 40 0a  add  %g1, %o2, %o4
a00ce120:  9b 33 60 10  srl  %o5, 0x10, %o5
a00ce124:  d8 0b 20 38  ldub  [ %o4 + 0x38 ], %o4
a00ce128:  82 04 80 01  add  %l2, %g1, %g1
a00ce12c:  80 a3 60 07  cmp  %o5, 7
a00ce130:  d8 28 7f f8  stb  %o4, [ %g1 + -8 ]
a00ce134:  08 bf ff f6  bleu  0xa00ce10c
a00ce138:  9a 10 00 0b  mov  %o3, %o5
a00ce13c:  94 10 00 10  mov  %l0, %o2
a00ce140:  90 10 20 00  clr  %o0
a00ce144:  92 10 20 80  mov  0x80, %o1
a00ce148:  96 10 20 07  mov  7, %o3
a00ce14c:  40 3b 20 a2  call  0xa0f963d4
a00ce150:  98 10 00 11  mov  %l1, %o4
a00ce154:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00ce158:  a0 04 20 08  add  %l0, 8, %l0
a00ce15c:  94 10 62 50  or  %g1, 0x250, %o2
a00ce160:  9a 10 20 00  clr  %o5
a00ce164:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ce168:  96 03 60 01  add  %o5, 1, %o3
a00ce16c:  83 30 60 10  srl  %g1, 0x10, %g1
a00ce170:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00ce174:  98 00 40 0a  add  %g1, %o2, %o4
a00ce178:  9b 33 60 10  srl  %o5, 0x10, %o5
a00ce17c:  d8 0b 20 40  ldub  [ %o4 + 0x40 ], %o4
a00ce180:  82 04 80 01  add  %l2, %g1, %g1
a00ce184:  80 a3 60 07  cmp  %o5, 7
a00ce188:  d8 28 7f f8  stb  %o4, [ %g1 + -8 ]
a00ce18c:  08 bf ff f6  bleu  0xa00ce164
a00ce190:  9a 10 00 0b  mov  %o3, %o5
a00ce194:  94 10 00 10  mov  %l0, %o2
a00ce198:  90 10 20 00  clr  %o0
a00ce19c:  92 10 20 80  mov  0x80, %o1
a00ce1a0:  96 10 20 07  mov  7, %o3
a00ce1a4:  40 3b 20 8c  call  0xa0f963d4
a00ce1a8:  98 10 00 11  mov  %l1, %o4
a00ce1ac:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00ce1b0:  a0 04 20 08  add  %l0, 8, %l0
a00ce1b4:  94 10 62 50  or  %g1, 0x250, %o2
a00ce1b8:  9a 10 20 00  clr  %o5
a00ce1bc:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ce1c0:  96 03 60 01  add  %o5, 1, %o3
a00ce1c4:  83 30 60 10  srl  %g1, 0x10, %g1
a00ce1c8:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00ce1cc:  98 00 40 0a  add  %g1, %o2, %o4
a00ce1d0:  9b 33 60 10  srl  %o5, 0x10, %o5
a00ce1d4:  d8 0b 20 48  ldub  [ %o4 + 0x48 ], %o4
a00ce1d8:  82 04 80 01  add  %l2, %g1, %g1
a00ce1dc:  80 a3 60 07  cmp  %o5, 7
a00ce1e0:  d8 28 7f f8  stb  %o4, [ %g1 + -8 ]
a00ce1e4:  08 bf ff f6  bleu  0xa00ce1bc
a00ce1e8:  9a 10 00 0b  mov  %o3, %o5
a00ce1ec:  94 10 00 10  mov  %l0, %o2
a00ce1f0:  90 10 20 00  clr  %o0
a00ce1f4:  92 10 20 80  mov  0x80, %o1
a00ce1f8:  96 10 20 07  mov  7, %o3
a00ce1fc:  40 3b 20 76  call  0xa0f963d4
a00ce200:  98 10 00 11  mov  %l1, %o4
a00ce204:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00ce208:  a0 04 20 08  add  %l0, 8, %l0
a00ce20c:  94 10 62 50  or  %g1, 0x250, %o2
a00ce210:  9a 10 20 00  clr  %o5
a00ce214:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ce218:  96 03 60 01  add  %o5, 1, %o3
a00ce21c:  83 30 60 10  srl  %g1, 0x10, %g1
a00ce220:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00ce224:  98 00 40 0a  add  %g1, %o2, %o4
a00ce228:  9b 33 60 10  srl  %o5, 0x10, %o5
a00ce22c:  d8 0b 20 50  ldub  [ %o4 + 0x50 ], %o4
a00ce230:  82 04 80 01  add  %l2, %g1, %g1
a00ce234:  80 a3 60 07  cmp  %o5, 7
a00ce238:  d8 28 7f f8  stb  %o4, [ %g1 + -8 ]
a00ce23c:  08 bf ff f6  bleu  0xa00ce214
a00ce240:  9a 10 00 0b  mov  %o3, %o5
a00ce244:  94 10 00 10  mov  %l0, %o2
a00ce248:  90 10 20 00  clr  %o0
a00ce24c:  92 10 20 80  mov  0x80, %o1
a00ce250:  96 10 20 07  mov  7, %o3
a00ce254:  40 3b 20 60  call  0xa0f963d4
a00ce258:  98 10 00 11  mov  %l1, %o4
a00ce25c:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00ce260:  a0 04 20 08  add  %l0, 8, %l0
a00ce264:  94 10 62 50  or  %g1, 0x250, %o2
a00ce268:  9a 10 20 00  clr  %o5
a00ce26c:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ce270:  96 03 60 01  add  %o5, 1, %o3
a00ce274:  83 30 60 10  srl  %g1, 0x10, %g1
a00ce278:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00ce27c:  98 00 40 0a  add  %g1, %o2, %o4
a00ce280:  9b 33 60 10  srl  %o5, 0x10, %o5
a00ce284:  d8 0b 20 58  ldub  [ %o4 + 0x58 ], %o4
a00ce288:  82 04 80 01  add  %l2, %g1, %g1
a00ce28c:  80 a3 60 07  cmp  %o5, 7
a00ce290:  d8 28 7f f8  stb  %o4, [ %g1 + -8 ]
a00ce294:  08 bf ff f6  bleu  0xa00ce26c
a00ce298:  9a 10 00 0b  mov  %o3, %o5
a00ce29c:  94 10 00 10  mov  %l0, %o2
a00ce2a0:  90 10 20 00  clr  %o0
a00ce2a4:  92 10 20 80  mov  0x80, %o1
a00ce2a8:  96 10 20 07  mov  7, %o3
a00ce2ac:  40 3b 20 4a  call  0xa0f963d4
a00ce2b0:  98 10 00 11  mov  %l1, %o4
a00ce2b4:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00ce2b8:  a0 04 20 08  add  %l0, 8, %l0
a00ce2bc:  94 10 62 50  or  %g1, 0x250, %o2
a00ce2c0:  9a 10 20 00  clr  %o5
a00ce2c4:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ce2c8:  96 03 60 01  add  %o5, 1, %o3
a00ce2cc:  83 30 60 10  srl  %g1, 0x10, %g1
a00ce2d0:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00ce2d4:  98 00 40 0a  add  %g1, %o2, %o4
a00ce2d8:  9b 33 60 10  srl  %o5, 0x10, %o5
a00ce2dc:  d8 0b 20 60  ldub  [ %o4 + 0x60 ], %o4
a00ce2e0:  82 04 80 01  add  %l2, %g1, %g1
a00ce2e4:  80 a3 60 07  cmp  %o5, 7
a00ce2e8:  d8 28 7f f8  stb  %o4, [ %g1 + -8 ]
a00ce2ec:  08 bf ff f6  bleu  0xa00ce2c4
a00ce2f0:  9a 10 00 0b  mov  %o3, %o5
a00ce2f4:  94 10 00 10  mov  %l0, %o2
a00ce2f8:  90 10 20 00  clr  %o0
a00ce2fc:  92 10 20 80  mov  0x80, %o1
a00ce300:  96 10 20 07  mov  7, %o3
a00ce304:  40 3b 20 34  call  0xa0f963d4
a00ce308:  98 10 00 11  mov  %l1, %o4
a00ce30c:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00ce310:  a0 04 20 08  add  %l0, 8, %l0
a00ce314:  94 10 62 50  or  %g1, 0x250, %o2
a00ce318:  9a 10 20 00  clr  %o5
a00ce31c:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ce320:  96 03 60 01  add  %o5, 1, %o3
a00ce324:  83 30 60 10  srl  %g1, 0x10, %g1
a00ce328:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00ce32c:  98 00 40 0a  add  %g1, %o2, %o4
a00ce330:  9b 33 60 10  srl  %o5, 0x10, %o5
a00ce334:  d8 0b 20 68  ldub  [ %o4 + 0x68 ], %o4
a00ce338:  82 04 80 01  add  %l2, %g1, %g1
a00ce33c:  80 a3 60 07  cmp  %o5, 7
a00ce340:  d8 28 7f f8  stb  %o4, [ %g1 + -8 ]
a00ce344:  08 bf ff f6  bleu  0xa00ce31c
a00ce348:  9a 10 00 0b  mov  %o3, %o5
a00ce34c:  94 10 00 10  mov  %l0, %o2
a00ce350:  90 10 20 00  clr  %o0
a00ce354:  92 10 20 80  mov  0x80, %o1
a00ce358:  96 10 20 07  mov  7, %o3
a00ce35c:  40 3b 20 1e  call  0xa0f963d4
a00ce360:  98 10 00 11  mov  %l1, %o4
a00ce364:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00ce368:  a0 04 20 08  add  %l0, 8, %l0
a00ce36c:  94 10 62 50  or  %g1, 0x250, %o2
a00ce370:  9a 10 20 00  clr  %o5
a00ce374:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ce378:  96 03 60 01  add  %o5, 1, %o3
a00ce37c:  83 30 60 10  srl  %g1, 0x10, %g1
a00ce380:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00ce384:  98 00 40 0a  add  %g1, %o2, %o4
a00ce388:  9b 33 60 10  srl  %o5, 0x10, %o5
a00ce38c:  d8 0b 20 70  ldub  [ %o4 + 0x70 ], %o4
a00ce390:  82 04 80 01  add  %l2, %g1, %g1
a00ce394:  80 a3 60 07  cmp  %o5, 7
a00ce398:  d8 28 7f f8  stb  %o4, [ %g1 + -8 ]
a00ce39c:  08 bf ff f6  bleu  0xa00ce374
a00ce3a0:  9a 10 00 0b  mov  %o3, %o5
a00ce3a4:  94 10 00 10  mov  %l0, %o2
a00ce3a8:  90 10 20 00  clr  %o0
a00ce3ac:  92 10 20 80  mov  0x80, %o1
a00ce3b0:  96 10 20 07  mov  7, %o3
a00ce3b4:  40 3b 20 08  call  0xa0f963d4
a00ce3b8:  98 10 00 11  mov  %l1, %o4
a00ce3bc:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00ce3c0:  a0 04 20 08  add  %l0, 8, %l0
a00ce3c4:  94 10 62 50  or  %g1, 0x250, %o2
a00ce3c8:  9a 10 20 00  clr  %o5
a00ce3cc:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ce3d0:  96 03 60 01  add  %o5, 1, %o3
a00ce3d4:  83 30 60 10  srl  %g1, 0x10, %g1
a00ce3d8:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00ce3dc:  98 00 40 0a  add  %g1, %o2, %o4
a00ce3e0:  9b 33 60 10  srl  %o5, 0x10, %o5
a00ce3e4:  d8 0b 20 78  ldub  [ %o4 + 0x78 ], %o4
a00ce3e8:  82 04 80 01  add  %l2, %g1, %g1
a00ce3ec:  80 a3 60 07  cmp  %o5, 7
a00ce3f0:  d8 28 7f f8  stb  %o4, [ %g1 + -8 ]
a00ce3f4:  08 bf ff f6  bleu  0xa00ce3cc
a00ce3f8:  9a 10 00 0b  mov  %o3, %o5
a00ce3fc:  94 10 00 10  mov  %l0, %o2
a00ce400:  98 10 00 11  mov  %l1, %o4
a00ce404:  90 10 20 00  clr  %o0
a00ce408:  92 10 20 80  mov  0x80, %o1
a00ce40c:  40 3b 1f f2  call  0xa0f963d4
a00ce410:  96 10 20 07  mov  7, %o3
a00ce414:  01 00 00 00  nop
a00ce418:  81 c7 e0 08  ret
a00ce41c:  81 e8 00 00  restore
