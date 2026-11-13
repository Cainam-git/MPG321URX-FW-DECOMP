# leon2m FUN_a00fbfd4 0xa00fbfd4-0xa00fc044 (112 bytes)
a00fbfd4:  9d e3 bf 98  save  %sp, -104, %sp
a00fbfd8:  92 10 20 01  mov  1, %o1
a00fbfdc:  94 10 20 00  clr  %o2
a00fbfe0:  7f ff ff 7b  call  0xa00fbdcc
a00fbfe4:  90 10 20 00  clr  %o0
a00fbfe8:  96 10 20 01  mov  1, %o3
a00fbfec:  13 2a 00 ad  sethi  %hi(0xa802b400), %o1
a00fbff0:  d6 32 63 ea  sth  %o3, [ %o1 + 0x3ea ]	! 0xa802b7ea
a00fbff4:  92 10 20 04  mov  4, %o1
a00fbff8:  94 10 20 00  clr  %o2
a00fbffc:  7f ff ff 74  call  0xa00fbdcc
a00fc000:  90 10 20 00  clr  %o0
a00fc004:  19 34 01 00  sethi  %hi(0xd0040000), %o4
a00fc008:  d0 03 00 00  ld  [ %o4 ], %o0
a00fc00c:  1b 20 00 00  sethi  %hi(0x80000000), %o5
a00fc010:  82 12 00 0d  or  %o0, %o5, %g1
a00fc014:  15 00 02 6a  sethi  %hi(0x9a800), %o2
a00fc018:  90 10 20 0c  mov  0xc, %o0
a00fc01c:  92 10 21 00  mov  0x100, %o1
a00fc020:  c2 23 00 00  st  %g1, [ %o4 ]
a00fc024:  67 fe 3a 17  call  0x4008a880
a00fc028:  94 12 a0 14  or  %o2, 0x14, %o2
a00fc02c:  90 10 20 0c  mov  0xc, %o0
a00fc030:  67 fe 35 fc  call  0x40089820
a00fc034:  92 10 21 00  mov  0x100, %o1
a00fc038:  01 00 00 00  nop
a00fc03c:  81 c7 e0 08  ret
a00fc040:  81 e8 00 00  restore
