# leon2s FUN_a0079e00 0xa0079e00-0xa0079f80 (384 bytes)
a0079e00:  9d e3 bf 98  save  %sp, -104, %sp
a0079e04:  ae 10 20 00  clr  %l7
a0079e08:  83 2d e0 10  sll  %l7, 0x10, %g1
a0079e0c:  83 30 60 10  srl  %g1, 0x10, %g1
a0079e10:  2d 00 3f ff  sethi  %hi(0xfffc00), %l6
a0079e14:  90 0e 20 ff  and  %i0, 0xff, %o0
a0079e18:  94 15 a3 ff  or  %l6, 0x3ff, %o2
a0079e1c:  17 22 00 00  sethi  %hi(0x88000000), %o3
a0079e20:  3b 3f ff c0  sethi  %hi(0xffff0000), %i5
a0079e24:  39 3f c0 3f  sethi  %hi(0xff00fc00), %i4
a0079e28:  80 a0 60 03  cmp  %g1, 3
a0079e2c:  18 80 00 4d  bgu  0xa0079f60
a0079e30:  a0 00 40 01  add  %g1, %g1, %l0
a0079e34:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0079e38:  82 10 63 40  or  %g1, 0x340, %g1	! 0xa00b3b40
a0079e3c:  e8 10 40 10  lduh  [ %g1 + %l0 ], %l4
a0079e40:  40 00 b5 92  call  0xa00a7488
a0079e44:  92 10 00 14  mov  %l4, %o1
a0079e48:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0079e4c:  82 10 63 50  or  %g1, 0x350, %g1	! 0xa00b3b50
a0079e50:  ea 10 40 10  lduh  [ %g1 + %l0 ], %l5
a0079e54:  90 0e 20 ff  and  %i0, 0xff, %o0
a0079e58:  92 10 00 15  mov  %l5, %o1
a0079e5c:  94 10 3f 00  mov  -256, %o2
a0079e60:  40 00 b5 8a  call  0xa00a7488
a0079e64:  96 10 20 88  mov  0x88, %o3
a0079e68:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0079e6c:  82 10 63 38  or  %g1, 0x338, %g1	! 0xa00b3b38
a0079e70:  e6 10 40 10  lduh  [ %g1 + %l0 ], %l3
a0079e74:  90 0e 20 ff  and  %i0, 0xff, %o0
a0079e78:  92 10 00 13  mov  %l3, %o1
a0079e7c:  94 15 a3 ff  or  %l6, 0x3ff, %o2
a0079e80:  40 00 b5 82  call  0xa00a7488
a0079e84:  17 22 00 00  sethi  %hi(0x88000000), %o3
a0079e88:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0079e8c:  82 10 63 48  or  %g1, 0x348, %g1	! 0xa00b3b48
a0079e90:  e4 10 40 10  lduh  [ %g1 + %l0 ], %l2
a0079e94:  90 0e 20 ff  and  %i0, 0xff, %o0
a0079e98:  92 10 00 12  mov  %l2, %o1
a0079e9c:  94 10 3f 00  mov  -256, %o2
a0079ea0:  40 00 b5 7a  call  0xa00a7488
a0079ea4:  96 10 20 88  mov  0x88, %o3
a0079ea8:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0079eac:  82 10 63 30  or  %g1, 0x330, %g1	! 0xa00b3b30
a0079eb0:  e2 10 40 10  lduh  [ %g1 + %l0 ], %l1
a0079eb4:  90 0e 20 ff  and  %i0, 0xff, %o0
a0079eb8:  92 10 00 11  mov  %l1, %o1
a0079ebc:  94 17 60 ff  or  %i5, 0xff, %o2
a0079ec0:  40 00 b5 72  call  0xa00a7488
a0079ec4:  96 10 20 00  clr  %o3
a0079ec8:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0079ecc:  82 10 63 28  or  %g1, 0x328, %g1	! 0xa00b3b28
a0079ed0:  e0 10 40 10  lduh  [ %g1 + %l0 ], %l0
a0079ed4:  94 17 60 ff  or  %i5, 0xff, %o2
a0079ed8:  90 0e 20 ff  and  %i0, 0xff, %o0
a0079edc:  92 10 00 10  mov  %l0, %o1
a0079ee0:  40 00 b5 6a  call  0xa00a7488
a0079ee4:  96 10 20 00  clr  %o3
a0079ee8:  92 10 00 11  mov  %l1, %o1
a0079eec:  90 0e 20 ff  and  %i0, 0xff, %o0
a0079ef0:  94 17 23 ff  or  %i4, 0x3ff, %o2
a0079ef4:  40 00 b5 65  call  0xa00a7488
a0079ef8:  17 00 3c 00  sethi  %hi(0xf00000), %o3
a0079efc:  92 10 00 10  mov  %l0, %o1
a0079f00:  94 17 23 ff  or  %i4, 0x3ff, %o2
a0079f04:  90 0e 20 ff  and  %i0, 0xff, %o0
a0079f08:  40 00 b5 60  call  0xa00a7488
a0079f0c:  17 00 3c 00  sethi  %hi(0xf00000), %o3
a0079f10:  92 10 00 14  mov  %l4, %o1
a0079f14:  90 0e 20 ff  and  %i0, 0xff, %o0
a0079f18:  94 15 a3 ff  or  %l6, 0x3ff, %o2
a0079f1c:  40 00 b5 5b  call  0xa00a7488
a0079f20:  17 02 00 00  sethi  %hi(0x8000000), %o3
a0079f24:  92 10 00 15  mov  %l5, %o1
a0079f28:  90 0e 20 ff  and  %i0, 0xff, %o0
a0079f2c:  94 10 3f 00  mov  -256, %o2
a0079f30:  40 00 b5 56  call  0xa00a7488
a0079f34:  96 10 20 08  mov  8, %o3
a0079f38:  92 10 00 13  mov  %l3, %o1
a0079f3c:  94 15 a3 ff  or  %l6, 0x3ff, %o2
a0079f40:  90 0e 20 ff  and  %i0, 0xff, %o0
a0079f44:  40 00 b5 51  call  0xa00a7488
a0079f48:  17 02 00 00  sethi  %hi(0x8000000), %o3
a0079f4c:  92 10 00 12  mov  %l2, %o1
a0079f50:  90 0e 20 ff  and  %i0, 0xff, %o0
a0079f54:  94 10 3f 00  mov  -256, %o2
a0079f58:  40 00 b5 4c  call  0xa00a7488
a0079f5c:  96 10 20 08  mov  8, %o3
a0079f60:  9a 05 e0 01  add  %l7, 1, %o5
a0079f64:  83 2b 60 10  sll  %o5, 0x10, %g1
a0079f68:  83 30 60 10  srl  %g1, 0x10, %g1
a0079f6c:  80 a0 60 03  cmp  %g1, 3
a0079f70:  08 bf ff a6  bleu  0xa0079e08
a0079f74:  ae 10 00 0d  mov  %o5, %l7
a0079f78:  81 c7 e0 08  ret
a0079f7c:  81 e8 00 00  restore
