# leon2m FUN_a0132bfc 0xa0132bfc-0xa0132c54 (88 bytes)
a0132bfc:  11 2a 00 b2  sethi  %hi(0xa802c800), %o0
a0132c00:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a0132c04:  d6 0a 23 97  ldub  [ %o0 + 0x397 ], %o3
a0132c08:  da 0b 63 96  ldub  [ %o5 + 0x396 ], %o5
a0132c0c:  82 0a e0 ff  and  %o3, 0xff, %g1
a0132c10:  98 0b 60 ff  and  %o5, 0xff, %o4
a0132c14:  98 23 00 01  sub  %o4, %g1, %o4
a0132c18:  92 0a e0 ff  and  %o3, 0xff, %o1
a0132c1c:  94 0b 60 ff  and  %o5, 0xff, %o2
a0132c20:  80 a2 40 0a  cmp  %o1, %o2
a0132c24:  08 80 00 04  bleu  0xa0132c34
a0132c28:  82 10 20 24  mov  0x24, %g1
a0132c2c:  10 80 00 07  b  0xa0132c48
a0132c30:  82 03 20 24  add  %o4, 0x24, %g1
a0132c34:  9a 0b 60 ff  and  %o5, 0xff, %o5
a0132c38:  1a 80 00 04  bcc  0xa0132c48
a0132c3c:  98 0a e0 ff  and  %o3, 0xff, %o4
a0132c40:  92 23 40 0c  sub  %o5, %o4, %o1
a0132c44:  82 02 7f ff  add  %o1, -1, %g1
a0132c48:  95 28 60 14  sll  %g1, 0x14, %o2
a0132c4c:  81 c3 e0 08  retl
a0132c50:  91 32 a0 10  srl  %o2, 0x10, %o0
