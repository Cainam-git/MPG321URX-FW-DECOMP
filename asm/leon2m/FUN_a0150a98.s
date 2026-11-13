# leon2m FUN_a0150a98 0xa0150a98-0xa0150b08 (112 bytes)
a0150a98:  9d e3 bf 78  save  %sp, -136, %sp
a0150a9c:  94 0e 20 ff  and  %i0, 0xff, %o2
a0150aa0:  92 02 80 0a  add  %o2, %o2, %o1
a0150aa4:  9a 02 40 0a  add  %o1, %o2, %o5
a0150aa8:  11 20 20 20  sethi  %hi(0x80808000), %o0
a0150aac:  97 2b 60 04  sll  %o5, 4, %o3
a0150ab0:  82 12 20 81  or  %o0, 0x81, %g1
a0150ab4:  80 5a c0 01  smul  %o3, %g1, %g0
a0150ab8:  99 40 00 00  rd  %y, %o4
a0150abc:  b0 03 00 0b  add  %o4, %o3, %i0
a0150ac0:  83 3e 20 07  sra  %i0, 7, %g1
a0150ac4:  91 28 60 10  sll  %g1, 0x10, %o0
a0150ac8:  9f 32 20 10  srl  %o0, 0x10, %o7
a0150acc:  94 03 c0 0f  add  %o7, %o7, %o2
a0150ad0:  92 02 80 0f  add  %o2, %o7, %o1
a0150ad4:  99 3a 60 02  sra  %o1, 2, %o4
a0150ad8:  97 32 20 11  srl  %o0, 0x11, %o3
a0150adc:  9a 10 20 0f  mov  0xf, %o5
a0150ae0:  da 27 bf d8  st  %o5, [ %fp + -40 ]
a0150ae4:  d6 2f bf dc  stb  %o3, [ %fp + -36 ]
a0150ae8:  c2 2f bf de  stb  %g1, [ %fp + -34 ]
a0150aec:  d8 2f bf df  stb  %o4, [ %fp + -33 ]
a0150af0:  d8 2f bf dd  stb  %o4, [ %fp + -35 ]
a0150af4:  7f fe 96 52  call  0xa00f643c
a0150af8:  90 07 bf d8  add  %fp, -40, %o0
a0150afc:  01 00 00 00  nop
a0150b00:  81 c7 e0 08  ret
a0150b04:  81 e8 00 00  restore
