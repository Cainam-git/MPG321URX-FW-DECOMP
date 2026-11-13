# leon2m FUN_a00b5080 0xa00b5080-0xa00b50d8 (88 bytes)
a00b5080:  9d e3 bf 98  save  %sp, -104, %sp
a00b5084:  90 10 20 00  clr  %o0
a00b5088:  40 02 47 4e  call  0xa0146dc0
a00b508c:  92 10 20 00  clr  %o1
a00b5090:  90 10 20 08  mov  8, %o0
a00b5094:  92 10 20 00  clr  %o1
a00b5098:  40 02 46 ea  call  0xa0146c40
a00b509c:  94 10 20 00  clr  %o2
a00b50a0:  96 10 20 24  mov  0x24, %o3
a00b50a4:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00b50a8:  90 10 20 00  clr  %o0
a00b50ac:  92 10 20 01  mov  1, %o1
a00b50b0:  40 02 47 44  call  0xa0146dc0
a00b50b4:  d6 2a a0 8f  stb  %o3, [ %o2 + 0x8f ]
a00b50b8:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a00b50bc:  9a 12 63 f4  or  %o1, 0x3f4, %o5	! 0xa802cff4
a00b50c0:  d8 13 60 3e  lduh  [ %o5 + 0x3e ], %o4
a00b50c4:  11 3f ff e0  sethi  %hi(0xffff8000), %o0
a00b50c8:  82 2b 00 08  andn  %o4, %o0, %g1
a00b50cc:  c2 33 60 3e  sth  %g1, [ %o5 + 0x3e ]
a00b50d0:  81 c7 e0 08  ret
a00b50d4:  81 e8 00 00  restore
