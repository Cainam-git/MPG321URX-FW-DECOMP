# leon2m FUN_a00fdf44 0xa00fdf44-0xa00fdf74 (48 bytes)
a00fdf44:  82 0a 20 ff  and  %o0, 0xff, %g1
a00fdf48:  80 a0 60 07  cmp  %g1, 7
a00fdf4c:  9a 10 20 00  clr  %o5
a00fdf50:  18 80 00 03  bgu  0xa00fdf5c
a00fdf54:  83 2a 20 04  sll  %o0, 4, %g1
a00fdf58:  9a 10 40 08  or  %g1, %o0, %o5
a00fdf5c:  03 33 c0 80  sethi  %hi(0xcf020000), %g1
a00fdf60:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00fdf64:  90 10 61 0c  or  %g1, 0x10c, %o0
a00fdf68:  da 22 00 00  st  %o5, [ %o0 ]
a00fdf6c:  81 c3 e0 08  retl
a00fdf70:  01 00 00 00  nop
