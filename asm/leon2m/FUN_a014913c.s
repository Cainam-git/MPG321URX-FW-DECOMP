# leon2m FUN_a014913c 0xa014913c-0xa0149178 (60 bytes)
a014913c:  9d e3 bf 98  save  %sp, -104, %sp
a0149140:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0149144:  a0 10 63 d0  or  %g1, 0x3d0, %l0	! 0xa802e3d0
a0149148:  9a 0e 20 ff  and  %i0, 0xff, %o5
a014914c:  80 a3 60 05  cmp  %o5, 5
a0149150:  02 80 00 07  be  0xa014916c
a0149154:  f0 2c 20 1c  stb  %i0, [ %l0 + 0x1c ]
a0149158:  7f ff 3d 01  call  0xa011855c
a014915c:  01 00 00 00  nop
a0149160:  f0 0c 20 1c  ldub  [ %l0 + 0x1c ], %i0
a0149164:  7f ff df ea  call  0xa014110c
a0149168:  81 e8 00 00  restore
a014916c:  7f ff 3c fc  call  0xa011855c
a0149170:  81 e8 00 00  restore
a0149174:  01 00 00 00  nop
