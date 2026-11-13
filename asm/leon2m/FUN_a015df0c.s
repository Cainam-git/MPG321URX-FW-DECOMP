# leon2m FUN_a015df0c 0xa015df0c-0xa015df44 (56 bytes)
a015df0c:  9d e3 bf 98  save  %sp, -104, %sp
a015df10:  21 2a 00 b9  sethi  %hi(0xa802e400), %l0
a015df14:  c0 24 20 0c  clr  [ %l0 + 0xc ]	! 0xa802e40c
a015df18:  40 00 02 5a  call  0xa015e880
a015df1c:  90 10 00 19  mov  %i1, %o0
a015df20:  80 a2 3f ff  cmp  %o0, -1
a015df24:  12 80 00 06  bne  0xa015df3c
a015df28:  c2 04 20 0c  ld  [ %l0 + 0xc ], %g1
a015df2c:  80 a0 60 00  cmp  %g1, 0
a015df30:  02 80 00 03  be  0xa015df3c
a015df34:  01 00 00 00  nop
a015df38:  c2 26 00 00  st  %g1, [ %i0 ]
a015df3c:  81 c7 e0 08  ret
a015df40:  91 e8 00 08  restore  %g0, %o0, %o0
