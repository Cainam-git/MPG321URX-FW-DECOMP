# leon2m FUN_a00b621c 0xa00b621c-0xa00b6290 (116 bytes)
a00b621c:  9d e3 bf 98  save  %sp, -104, %sp
a00b6220:  7f ff ca 9a  call  0xa00a8c88
a00b6224:  a2 10 20 00  clr  %l1
a00b6228:  90 10 21 11  mov  0x111, %o0
a00b622c:  40 02 42 49  call  0xa0146b50
a00b6230:  92 10 20 00  clr  %o1
a00b6234:  90 10 20 00  clr  %o0
a00b6238:  40 02 42 4d  call  0xa0146b6c
a00b623c:  92 10 20 00  clr  %o1
a00b6240:  a0 10 20 00  clr  %l0
a00b6244:  25 00 06 5a  sethi  %hi(0x196800), %l2
a00b6248:  92 10 00 10  mov  %l0, %o1
a00b624c:  7f ff b5 7e  call  0xa00a3844
a00b6250:  90 14 a3 24  or  %l2, 0x324, %o0
a00b6254:  98 10 00 08  mov  %o0, %o4
a00b6258:  94 04 00 10  add  %l0, %l0, %o2
a00b625c:  94 02 a0 06  add  %o2, 6, %o2
a00b6260:  90 10 20 00  clr  %o0
a00b6264:  92 10 20 2a  mov  0x2a, %o1
a00b6268:  96 10 20 01  mov  1, %o3
a00b626c:  9a 10 20 00  clr  %o5
a00b6270:  7f ff b3 cd  call  0xa00a31a4
a00b6274:  a2 04 60 01  inc  %l1
a00b6278:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00b627c:  80 a4 20 03  cmp  %l0, 3
a00b6280:  08 bf ff f3  bleu  0xa00b624c
a00b6284:  92 10 00 10  mov  %l0, %o1
a00b6288:  81 c7 e0 08  ret
a00b628c:  81 e8 00 00  restore
