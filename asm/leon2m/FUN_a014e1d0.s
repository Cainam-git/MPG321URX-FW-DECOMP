# leon2m FUN_a014e1d0 0xa014e1d0-0xa014e26c (156 bytes)  [FUN_a014e264 = unreachable ret/restore tail, merged]
a014e1d0:  9d e3 bf 98  save  %sp, -104, %sp
a014e1d4:  7f fe f3 7d  call  0xa010afc8
a014e1d8:  01 00 00 00  nop
a014e1dc:  7f fe f3 ef  call  0xa010b198
a014e1e0:  01 00 00 00  nop
a014e1e4:  67 fc fb ef  call  0x4008d1a0
a014e1e8:  90 10 20 0a  mov  0xa, %o0	! 0xa
a014e1ec:  82 0e 20 ff  and  %i0, 0xff, %g1
a014e1f0:  80 a0 60 04  cmp  %g1, 4
a014e1f4:  18 80 00 1b  bgu  0xa014e260
a014e1f8:  11 00 03 8d  sethi  %hi(0xe3400), %o0
a014e1fc:  83 28 60 02  sll  %g1, 2, %g1
a014e200:  9a 12 22 a0  or  %o0, 0x2a0, %o5
a014e204:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a014e208:  81 c3 00 00  jmp  %o4
a014e20c:  01 00 00 00  nop
a014e210:  7f fe f3 c1  call  0xa010b114
a014e214:  90 10 20 00  clr  %o0	! 0x0
a014e218:  7f fe f4 33  call  0xa010b2e4
a014e21c:  91 e8 20 00  restore  %g0, 0, %o0
a014e220:  7f fe f3 84  call  0xa010b030
a014e224:  90 10 20 00  clr  %o0
a014e228:  7f fe f3 f6  call  0xa010b200
a014e22c:  91 e8 20 00  restore  %g0, 0, %o0
a014e230:  7f fe f3 93  call  0xa010b07c
a014e234:  90 10 20 00  clr  %o0
a014e238:  7f fe f4 05  call  0xa010b24c
a014e23c:  91 e8 20 00  restore  %g0, 0, %o0
a014e240:  7f fe f3 69  call  0xa010afe4
a014e244:  90 10 20 00  clr  %o0
a014e248:  7f fe f3 db  call  0xa010b1b4
a014e24c:  91 e8 20 00  restore  %g0, 0, %o0
a014e250:  7f fe f3 9e  call  0xa010b0c8
a014e254:  90 10 20 00  clr  %o0
a014e258:  7f fe f4 10  call  0xa010b298
a014e25c:  91 e8 20 00  restore  %g0, 0, %o0
a014e260:  01 00 00 00  nop
a014e264:  81 c7 e0 08  ret
a014e268:  81 e8 00 00  restore
