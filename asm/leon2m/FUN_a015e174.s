# leon2m FUN_a015e174 0xa015e174-0xa015e224 (176 bytes)
a015e174:  9d e3 bf 98  save  %sp, -104, %sp
a015e178:  92 10 00 1a  mov  %i2, %o1
a015e17c:  7f ff e5 1e  call  0xa01575f4
a015e180:  90 10 00 19  mov  %i1, %o0
a015e184:  92 10 00 08  mov  %o0, %o1
a015e188:  7f ff f8 75  call  0xa015c35c
a015e18c:  90 10 00 18  mov  %i0, %o0
a015e190:  b4 92 20 00  orcc  %o0, 0, %i2
a015e194:  02 80 00 22  be  0xa015e21c
a015e198:  b0 10 20 00  clr  %i0
a015e19c:  c2 06 bf fc  ld  [ %i2 + -4 ], %g1
a015e1a0:  82 08 7f fc  and  %g1, -4, %g1
a015e1a4:  82 00 7f fc  add  %g1, -4, %g1
a015e1a8:  80 a0 60 24  cmp  %g1, 0x24
a015e1ac:  94 10 00 01  mov  %g1, %o2
a015e1b0:  9a 10 00 1a  mov  %i2, %o5
a015e1b4:  18 80 00 18  bgu  0xa015e214
a015e1b8:  92 10 20 00  clr  %o1
a015e1bc:  80 a0 60 13  cmp  %g1, 0x13
a015e1c0:  28 80 00 10  bleu,a   0xa015e200
a015e1c4:  c0 23 40 00  clr  [ %o5 ]
a015e1c8:  c0 26 80 00  clr  [ %i2 ]
a015e1cc:  c0 26 a0 04  clr  [ %i2 + 4 ]
a015e1d0:  80 a0 60 1b  cmp  %g1, 0x1b
a015e1d4:  08 80 00 0a  bleu  0xa015e1fc
a015e1d8:  9a 06 a0 08  add  %i2, 8, %o5
a015e1dc:  80 a0 60 23  cmp  %g1, 0x23
a015e1e0:  c0 26 a0 08  clr  [ %i2 + 8 ]
a015e1e4:  c0 26 a0 0c  clr  [ %i2 + 0xc ]
a015e1e8:  08 80 00 05  bleu  0xa015e1fc
a015e1ec:  9a 06 a0 10  add  %i2, 0x10, %o5
a015e1f0:  c0 26 a0 10  clr  [ %i2 + 0x10 ]
a015e1f4:  c0 26 a0 14  clr  [ %i2 + 0x14 ]
a015e1f8:  9a 06 a0 18  add  %i2, 0x18, %o5
a015e1fc:  c0 23 40 00  clr  [ %o5 ]
a015e200:  9a 03 60 04  add  %o5, 4, %o5
a015e204:  c0 23 60 04  clr  [ %o5 + 4 ]
a015e208:  c0 23 40 00  clr  [ %o5 ]
a015e20c:  10 80 00 04  b  0xa015e21c
a015e210:  b0 10 00 1a  mov  %i2, %i0
a015e214:  7f ff e5 35  call  0xa01576e8
a015e218:  b0 10 00 1a  mov  %i2, %i0
a015e21c:  81 c7 e0 08  ret
a015e220:  81 e8 00 00  restore
