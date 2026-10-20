# leon2s FUN_a00d01f4 0xa00d01f4-0xa00d0260 (108 bytes)  [FUN_a00d0258 = unreachable ret/restore tail, merged]
a00d01f4:  9d e3 bf 98  save  %sp, -104, %sp
a00d01f8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00d01fc:  82 06 00 18  add  %i0, %i0, %g1
a00d0200:  82 00 40 18  add  %g1, %i0, %g1
a00d0204:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a00d0208:  a1 28 60 03  sll  %g1, 3, %l0
a00d020c:  a2 13 63 b0  or  %o5, 0x3b0, %l1
a00d0210:  da 04 40 10  ld  [ %l1 + %l0 ], %o5
a00d0214:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00d0218:  82 2b 40 01  andn  %o5, %g1, %g1
a00d021c:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00d0220:  82 10 40 0d  or  %g1, %o5, %g1
a00d0224:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00d0228:  7f ff fe 3e  call  0xa00cfb20
a00d022c:  90 06 20 08  add  %i0, 8, %o0
a00d0230:  80 a2 20 00  cmp  %o0, 0
a00d0234:  02 80 00 06  be  0xa00d024c
a00d0238:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00d023c:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00d0240:  82 10 40 0d  or  %g1, %o5, %g1
a00d0244:  10 80 00 04  b  0xa00d0254
a00d0248:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00d024c:  7f ff e0 db  call  0xa00c85b8
a00d0250:  81 e8 00 00  restore
a00d0254:  01 00 00 00  nop
a00d0258:  81 c7 e0 08  ret
a00d025c:  81 e8 00 00  restore
