# leon2m FUN_a00b8804 0xa00b8804-0xa00b8848 (68 bytes)
a00b8804:  9d e3 bf 98  save  %sp, -104, %sp
a00b8808:  40 00 82 8c  call  0xa00d9238
a00b880c:  01 00 00 00  nop
a00b8810:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a00b8814:  d6 12 63 f4  lduh  [ %o1 + 0x3f4 ], %o3	! 0xa802cff4
a00b8818:  94 12 e4 00  or  %o3, 0x400, %o2
a00b881c:  d4 32 63 f4  sth  %o2, [ %o1 + 0x3f4 ]
a00b8820:  90 10 20 00  clr  %o0
a00b8824:  7f ff 20 22  call  0xa00808ac
a00b8828:  92 10 20 00  clr  %o1
a00b882c:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00b8830:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a00b8834:  82 12 20 02  or  %o0, 2, %g1
a00b8838:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a00b883c:  7f ff 61 e7  call  0xa0090fd8
a00b8840:  81 e8 00 00  restore
a00b8844:  01 00 00 00  nop
