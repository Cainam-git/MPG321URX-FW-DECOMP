# leon2s FUN_a00c0f88 0xa00c0f88-0xa00c10c4 (316 bytes)
a00c0f88:  9d e3 bf 98  save  %sp, -104, %sp
a00c0f8c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0f90:  90 10 00 18  mov  %i0, %o0
a00c0f94:  92 10 23 10  mov  0x310, %o1
a00c0f98:  40 3b d5 8b  call  0xa0fb65c4
a00c0f9c:  94 10 20 21  mov  0x21, %o2
a00c0fa0:  a0 10 20 00  clr  %l0
a00c0fa4:  83 2c 20 10  sll  %l0, 0x10, %g1
a00c0fa8:  83 30 60 10  srl  %g1, 0x10, %g1
a00c0fac:  d4 0e 40 01  ldub  [ %i1 + %g1 ], %o2
a00c0fb0:  90 10 00 18  mov  %i0, %o0
a00c0fb4:  40 3b d5 84  call  0xa0fb65c4
a00c0fb8:  92 10 23 12  mov  0x312, %o1
a00c0fbc:  9a 04 20 01  add  %l0, 1, %o5
a00c0fc0:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c0fc4:  83 30 60 10  srl  %g1, 0x10, %g1
a00c0fc8:  80 a0 60 0f  cmp  %g1, 0xf
a00c0fcc:  08 bf ff f6  bleu  0xa00c0fa4
a00c0fd0:  a0 10 00 0d  mov  %o5, %l0
a00c0fd4:  92 10 23 09  mov  0x309, %o1
a00c0fd8:  40 3b d5 69  call  0xa0fb657c
a00c0fdc:  90 10 00 18  mov  %i0, %o0
a00c0fe0:  94 0a 3f fc  and  %o0, -4, %o2
a00c0fe4:  94 12 a0 01  or  %o2, 1, %o2
a00c0fe8:  94 0a a0 fd  and  %o2, 0xfd, %o2
a00c0fec:  90 10 00 18  mov  %i0, %o0
a00c0ff0:  40 3b d5 75  call  0xa0fb65c4
a00c0ff4:  92 10 23 09  mov  0x309, %o1
a00c0ff8:  a0 10 20 00  clr  %l0
a00c0ffc:  83 2c 20 10  sll  %l0, 0x10, %g1
a00c1000:  83 30 60 10  srl  %g1, 0x10, %g1
a00c1004:  d4 0e 80 01  ldub  [ %i2 + %g1 ], %o2
a00c1008:  90 10 00 18  mov  %i0, %o0
a00c100c:  40 3b d5 6e  call  0xa0fb65c4
a00c1010:  92 10 23 0b  mov  0x30b, %o1
a00c1014:  9a 04 20 01  add  %l0, 1, %o5
a00c1018:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c101c:  83 30 60 10  srl  %g1, 0x10, %g1
a00c1020:  80 a0 62 09  cmp  %g1, 0x209
a00c1024:  08 bf ff f6  bleu  0xa00c0ffc
a00c1028:  a0 10 00 0d  mov  %o5, %l0
a00c102c:  90 10 00 18  mov  %i0, %o0
a00c1030:  92 10 23 10  mov  0x310, %o1
a00c1034:  40 3b d5 64  call  0xa0fb65c4
a00c1038:  94 10 20 2d  mov  0x2d, %o2
a00c103c:  a0 10 20 00  clr  %l0
a00c1040:  9b 2c 20 10  sll  %l0, 0x10, %o5
a00c1044:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00c1048:  9b 33 60 10  srl  %o5, 0x10, %o5
a00c104c:  82 10 62 20  or  %g1, 0x220, %g1
a00c1050:  d4 08 40 0d  ldub  [ %g1 + %o5 ], %o2
a00c1054:  90 10 00 18  mov  %i0, %o0
a00c1058:  40 3b d5 5b  call  0xa0fb65c4
a00c105c:  92 10 23 12  mov  0x312, %o1
a00c1060:  9a 04 20 01  add  %l0, 1, %o5
a00c1064:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c1068:  83 30 60 10  srl  %g1, 0x10, %g1
a00c106c:  80 a0 60 0a  cmp  %g1, 0xa
a00c1070:  08 bf ff f4  bleu  0xa00c1040
a00c1074:  a0 10 00 0d  mov  %o5, %l0
a00c1078:  90 10 00 18  mov  %i0, %o0
a00c107c:  92 10 23 10  mov  0x310, %o1
a00c1080:  40 3b d5 51  call  0xa0fb65c4
a00c1084:  94 10 20 20  mov  0x20, %o2
a00c1088:  a0 10 20 00  clr  %l0
a00c108c:  83 2c 20 10  sll  %l0, 0x10, %g1
a00c1090:  83 30 60 10  srl  %g1, 0x10, %g1
a00c1094:  d4 0f 00 01  ldub  [ %i4 + %g1 ], %o2
a00c1098:  90 10 00 18  mov  %i0, %o0
a00c109c:  40 3b d5 4a  call  0xa0fb65c4
a00c10a0:  92 10 23 12  mov  0x312, %o1
a00c10a4:  9a 04 20 01  add  %l0, 1, %o5
a00c10a8:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c10ac:  83 30 60 10  srl  %g1, 0x10, %g1
a00c10b0:  80 a0 61 3f  cmp  %g1, 0x13f
a00c10b4:  08 bf ff f6  bleu  0xa00c108c
a00c10b8:  a0 10 00 0d  mov  %o5, %l0
a00c10bc:  81 c7 e0 08  ret
a00c10c0:  81 e8 00 00  restore
