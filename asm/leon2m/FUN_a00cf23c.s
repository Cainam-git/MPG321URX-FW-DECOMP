# leon2m FUN_a00cf23c 0xa00cf23c-0xa00cf280 (68 bytes)
a00cf23c:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a00cf240:  94 10 60 58  or  %g1, 0x58, %o2	! 0xa8025c58
a00cf244:  96 10 20 00  clr  %o3
a00cf248:  98 10 20 00  clr  %o4
a00cf24c:  82 10 20 00  clr  %g1
a00cf250:  83 28 60 02  sll  %g1, 2, %g1
a00cf254:  90 00 40 0a  add  %g1, %o2, %o0
a00cf258:  da 12 20 02  lduh  [ %o0 + 2 ], %o5
a00cf25c:  98 03 20 01  inc  %o4
a00cf260:  90 12 c0 0d  or  %o3, %o5, %o0
a00cf264:  82 0b 20 ff  and  %o4, 0xff, %g1
a00cf268:  80 a0 60 02  cmp  %g1, 2
a00cf26c:  08 bf ff f9  bleu  0xa00cf250
a00cf270:  96 10 00 08  mov  %o0, %o3
a00cf274:  95 2a 20 10  sll  %o0, 0x10, %o2
a00cf278:  81 c3 e0 08  retl
a00cf27c:  91 32 a0 10  srl  %o2, 0x10, %o0
