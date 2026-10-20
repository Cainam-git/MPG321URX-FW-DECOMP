# leon2m FUN_a015df44 0xa015df44-0xa015df90 (76 bytes)
a015df44:  9d e3 bf 98  save  %sp, -104, %sp
a015df48:  03 2a 00 aa  sethi  %hi(0xa802a800), %g1
a015df4c:  d0 00 62 18  ld  [ %g1 + 0x218 ], %o0	! 0xa802aa18
a015df50:  94 10 00 19  mov  %i1, %o2
a015df54:  96 10 00 1a  mov  %i2, %o3
a015df58:  40 00 01 4b  call  0xa015e484
a015df5c:  d2 56 20 0e  ldsh  [ %i0 + 0xe ], %o1
a015df60:  80 a2 20 00  cmp  %o0, 0
a015df64:  26 80 00 06  bl,a   0xa015df7c
a015df68:  da 16 20 0c  lduh  [ %i0 + 0xc ], %o5
a015df6c:  c2 06 20 50  ld  [ %i0 + 0x50 ], %g1
a015df70:  82 00 40 08  add  %g1, %o0, %g1
a015df74:  10 80 00 05  b  0xa015df88
a015df78:  c2 26 20 50  st  %g1, [ %i0 + 0x50 ]
a015df7c:  03 00 00 04  sethi  %hi(0x1000), %g1
a015df80:  82 2b 40 01  andn  %o5, %g1, %g1
a015df84:  c2 36 20 0c  sth  %g1, [ %i0 + 0xc ]
a015df88:  81 c7 e0 08  ret
a015df8c:  91 e8 00 08  restore  %g0, %o0, %o0
