# leon2s FUN_a0074fc4 0xa0074fc4-0xa007501c (88 bytes)
a0074fc4:  9d e3 bf 98  save  %sp, -104, %sp
a0074fc8:  90 0e 20 ff  and  %i0, 0xff, %o0
a0074fcc:  82 02 00 08  add  %o0, %o0, %g1
a0074fd0:  82 00 40 08  add  %g1, %o0, %g1
a0074fd4:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a0074fd8:  9a 13 60 64  or  %o5, 0x64, %o5	! 0xa807cc64
a0074fdc:  83 28 60 03  sll  %g1, 3, %g1
a0074fe0:  82 00 40 0d  add  %g1, %o5, %g1
a0074fe4:  7f ff ff df  call  0xa0074f60
a0074fe8:  e0 10 60 0a  lduh  [ %g1 + 0xa ], %l0
a0074fec:  91 2a 20 10  sll  %o0, 0x10, %o0
a0074ff0:  91 32 20 10  srl  %o0, 0x10, %o0
a0074ff4:  a0 24 00 08  sub  %l0, %o0, %l0
a0074ff8:  83 3c 20 1f  sra  %l0, 0x1f, %g1
a0074ffc:  a0 18 40 10  xor  %g1, %l0, %l0
a0075000:  a0 24 00 01  sub  %l0, %g1, %l0
a0075004:  80 a4 20 02  cmp  %l0, 2
a0075008:  14 80 00 03  bg  0xa0075014
a007500c:  b0 10 20 01  mov  1, %i0
a0075010:  b0 10 20 00  clr  %i0
a0075014:  81 c7 e0 08  ret
a0075018:  81 e8 00 00  restore
