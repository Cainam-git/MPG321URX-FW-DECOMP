# leon2m FUN_a0090fd8 0xa0090fd8-0xa0091034 (92 bytes)
a0090fd8:  9d e3 bf 98  save  %sp, -104, %sp
a0090fdc:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a0090fe0:  98 12 a3 f4  or  %o2, 0x3f4, %o4	! 0xa802cff4
a0090fe4:  da 13 20 04  lduh  [ %o4 + 4 ], %o5
a0090fe8:  13 3f ff e0  sethi  %hi(0xffff8000), %o1
a0090fec:  90 0b 40 09  and  %o5, %o1, %o0
a0090ff0:  83 2a 20 10  sll  %o0, 0x10, %g1
a0090ff4:  9a 13 64 00  or  %o5, 0x400, %o5
a0090ff8:  80 a0 60 00  cmp  %g1, 0
a0090ffc:  90 10 20 04  mov  4, %o0
a0091000:  12 80 00 06  bne  0xa0091018
a0091004:  92 10 20 00  clr  %o1
a0091008:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a009100c:  c0 22 e3 ec  clr  [ %o3 + 0x3ec ]	! 0xa802afec
a0091010:  40 00 90 1c  call  0xa00b5080
a0091014:  81 e8 00 00  restore
a0091018:  7f ff be 25  call  0xa00808ac
a009101c:  da 33 20 04  sth  %o5, [ %o4 + 4 ]
a0091020:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a0091024:  c0 22 e3 ec  clr  [ %o3 + 0x3ec ]	! 0xa802afec
a0091028:  40 00 90 16  call  0xa00b5080
a009102c:  81 e8 00 00  restore
a0091030:  01 00 00 00  nop
