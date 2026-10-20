# leon2s FUN_a00b1fe0 0xa00b1fe0-0xa00b2064 (132 bytes)
a00b1fe0:  9d e3 bf 98  save  %sp, -104, %sp
a00b1fe4:  03 27 c4 00  sethi  %hi(0x9f100000), %g1
a00b1fe8:  90 10 60 90  or  %g1, 0x90, %o0	! 0x9f100090
a00b1fec:  3b 00 00 3f  sethi  %hi(0xfc00), %i5
a00b1ff0:  03 27 c4 80  sethi  %hi(0x9f120000), %g1
a00b1ff4:  96 10 60 28  or  %g1, 0x28, %o3	! 0x9f120028
a00b1ff8:  9e 17 63 ef  or  %i5, 0x3ef, %o7
a00b1ffc:  9a 10 60 44  or  %g1, 0x44, %o5
a00b2000:  b2 17 63 fd  or  %i5, 0x3fd, %i1
a00b2004:  92 10 60 38  or  %g1, 0x38, %o1
a00b2008:  94 17 63 ff  or  %i5, 0x3ff, %o2
a00b200c:  98 10 20 10  mov  0x10, %o4
a00b2010:  b6 10 00 0b  mov  %o3, %i3
a00b2014:  b4 10 00 0d  mov  %o5, %i2
a00b2018:  80 8e 20 ff  btst  0xff, %i0
a00b201c:  02 80 00 0a  be  0xa00b2044
a00b2020:  ba 10 00 09  mov  %o1, %i5
a00b2024:  d8 22 00 00  st  %o4, [ %o0 ]
a00b2028:  de 22 c0 00  st  %o7, [ %o3 ]
a00b202c:  f2 23 40 00  st  %i1, [ %o5 ]
a00b2030:  d4 22 40 00  st  %o2, [ %o1 ]
a00b2034:  d8 22 00 00  st  %o4, [ %o0 ]
a00b2038:  de 22 c0 00  st  %o7, [ %o3 ]
a00b203c:  f2 23 40 00  st  %i1, [ %o5 ]
a00b2040:  30 80 00 07  b,a   0xa00b205c
a00b2044:  03 27 c4 00  sethi  %hi(0x9f100000), %g1
a00b2048:  82 10 60 90  or  %g1, 0x90, %g1	! 0x9f100090
a00b204c:  c0 20 40 00  clr  [ %g1 ]
a00b2050:  d4 26 c0 00  st  %o2, [ %i3 ]
a00b2054:  d4 26 80 00  st  %o2, [ %i2 ]
a00b2058:  d4 27 40 00  st  %o2, [ %i5 ]
a00b205c:  81 c7 e0 08  ret
a00b2060:  81 e8 00 00  restore
