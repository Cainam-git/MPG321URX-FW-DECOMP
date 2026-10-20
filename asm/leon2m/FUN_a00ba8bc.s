# leon2m FUN_a00ba8bc 0xa00ba8bc-0xa00ba950 (148 bytes)
a00ba8bc:  9d e3 bf 98  save  %sp, -104, %sp
a00ba8c0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00ba8c4:  82 10 60 d0  or  %g1, 0xd0, %g1	! 0xa802d0d0
a00ba8c8:  98 10 20 00  clr  %o4
a00ba8cc:  9a 10 20 00  clr  %o5
a00ba8d0:  c0 28 40 0d  clrb  [ %g1 + %o5 ]
a00ba8d4:  98 03 20 01  inc  %o4
a00ba8d8:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00ba8dc:  80 a3 60 31  cmp  %o5, 0x31
a00ba8e0:  28 bf ff fd  bleu,a   0xa00ba8d4
a00ba8e4:  c0 28 40 0d  clrb  [ %g1 + %o5 ]
a00ba8e8:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00ba8ec:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00ba8f0:  c0 2a 20 9c  clrb  [ %o0 + 0x9c ]
a00ba8f4:  9a 13 60 78  or  %o5, 0x78, %o5
a00ba8f8:  98 10 20 00  clr  %o4
a00ba8fc:  82 10 20 00  clr  %g1
a00ba900:  c0 2b 40 01  clrb  [ %o5 + %g1 ]
a00ba904:  98 03 20 01  inc  %o4
a00ba908:  82 0b 20 ff  and  %o4, 0xff, %g1
a00ba90c:  80 a0 60 18  cmp  %g1, 0x18
a00ba910:  28 bf ff fd  bleu,a   0xa00ba904
a00ba914:  c0 2b 40 01  clrb  [ %o5 + %g1 ]
a00ba918:  21 00 00 70  sethi  %hi(0x1c000), %l0
a00ba91c:  90 10 20 01  mov  1, %o0
a00ba920:  92 10 20 10  mov  0x10, %o1
a00ba924:  94 10 20 04  mov  4, %o2
a00ba928:  40 02 37 9b  call  0xa0148794
a00ba92c:  96 14 22 00  or  %l0, 0x200, %o3
a00ba930:  96 14 22 00  or  %l0, 0x200, %o3
a00ba934:  90 10 20 01  mov  1, %o0
a00ba938:  92 10 20 04  mov  4, %o1
a00ba93c:  40 02 37 96  call  0xa0148794
a00ba940:  94 10 20 02  mov  2, %o2
a00ba944:  01 00 00 00  nop
a00ba948:  81 c7 e0 08  ret
a00ba94c:  81 e8 00 00  restore
