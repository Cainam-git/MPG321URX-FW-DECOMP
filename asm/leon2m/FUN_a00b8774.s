# leon2m FUN_a00b8774 0xa00b8774-0xa00b87d4 (96 bytes)
a00b8774:  9d e3 bf 98  save  %sp, -104, %sp
a00b8778:  9e 10 27 2c  mov  0x72c, %o7
a00b877c:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00b8780:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00b8784:  de 32 e0 92  sth  %o7, [ %o3 + 0x92 ]
a00b8788:  c0 32 a0 94  clrh  [ %o2 + 0x94 ]
a00b878c:  92 10 20 00  clr  %o1
a00b8790:  94 10 20 00  clr  %o2
a00b8794:  96 10 20 00  clr  %o3
a00b8798:  40 01 2c 1c  call  0xa0103808
a00b879c:  90 10 20 00  clr  %o0
a00b87a0:  7f ff fd ff  call  0xa00b7f9c
a00b87a4:  90 10 20 1b  mov  0x1b, %o0
a00b87a8:  90 10 20 01  mov  1, %o0
a00b87ac:  40 02 32 60  call  0xa014512c
a00b87b0:  92 10 20 00  clr  %o1
a00b87b4:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a00b87b8:  9a 12 63 f4  or  %o1, 0x3f4, %o5	! 0xa802cff4
a00b87bc:  d0 13 60 18  lduh  [ %o5 + 0x18 ], %o0
a00b87c0:  19 00 00 04  sethi  %hi(0x1000), %o4
a00b87c4:  82 12 00 0c  or  %o0, %o4, %g1
a00b87c8:  c2 33 60 18  sth  %g1, [ %o5 + 0x18 ]
a00b87cc:  81 c7 e0 08  ret
a00b87d0:  81 e8 00 00  restore
