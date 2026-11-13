# leon2m FUN_a01518c8 0xa01518c8-0xa01519b4 (236 bytes)
a01518c8:  9d e3 bf 98  save  %sp, -104, %sp
a01518cc:  7f ff 4a 4c  call  0xa01241fc
a01518d0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01518d4:  80 a6 20 02  cmp  %i0, 2
a01518d8:  02 80 00 32  be  0xa01519a0
a01518dc:  23 2a 00 b7  sethi  %hi(0xa802dc00), %l1
a01518e0:  14 80 00 23  bg  0xa015196c
a01518e4:  80 a6 20 03  cmp  %i0, 3
a01518e8:  80 a6 20 01  cmp  %i0, 1
a01518ec:  02 80 00 30  be  0xa01519ac
a01518f0:  9a 14 63 30  or  %l1, 0x330, %o5
a01518f4:  23 2a 00 b7  sethi  %hi(0xa802dc00), %l1
a01518f8:  c2 04 63 30  ld  [ %l1 + 0x330 ], %g1	! 0xa802df30
a01518fc:  95 30 60 0c  srl  %g1, 0xc, %o2
a0151900:  92 0a a0 0f  and  %o2, 0xf, %o1
a0151904:  a0 0a 60 ff  and  %o1, 0xff, %l0
a0151908:  90 10 00 10  mov  %l0, %o0
a015190c:  92 10 20 00  clr  %o1
a0151910:  94 10 20 00  clr  %o2
a0151914:  7f ff 1c 5b  call  0xa0118a80
a0151918:  96 10 20 00  clr  %o3
a015191c:  90 10 00 10  mov  %l0, %o0
a0151920:  94 10 20 00  clr  %o2
a0151924:  96 10 20 00  clr  %o3
a0151928:  7f fe e4 70  call  0xa010aae8
a015192c:  92 10 20 00  clr  %o1
a0151930:  7f fe d4 9e  call  0xa0106ba8
a0151934:  90 10 00 10  mov  %l0, %o0
a0151938:  91 2e 20 04  sll  %i0, 4, %o0
a015193c:  9a 22 00 18  sub  %o0, %i0, %o5
a0151940:  a0 14 63 30  or  %l1, 0x330, %l0
a0151944:  9f 2b 60 03  sll  %o5, 3, %o7
a0151948:  94 03 c0 10  add  %o7, %l0, %o2
a015194c:  d8 02 a0 68  ld  [ %o2 + 0x68 ], %o4
a0151950:  17 00 04 00  sethi  %hi(0x100000), %o3
a0151954:  82 2b 00 0b  andn  %o4, %o3, %g1
a0151958:  80 a6 20 00  cmp  %i0, 0
a015195c:  02 80 00 09  be  0xa0151980
a0151960:  c2 22 a0 68  st  %g1, [ %o2 + 0x68 ]
a0151964:  7f fe d2 17  call  0xa01061c0
a0151968:  91 e8 20 00  restore  %g0, 0, %o0
a015196c:  12 bf ff e3  bne  0xa01518f8
a0151970:  23 2a 00 b7  sethi  %hi(0xa802dc00), %l1
a0151974:  92 14 63 30  or  %l1, 0x330, %o1	! 0xa802df30
a0151978:  10 bf ff e1  b  0xa01518fc
a015197c:  c2 02 61 68  ld  [ %o1 + 0x168 ], %g1
a0151980:  23 2a 00 b8  sethi  %hi(0xa802e000), %l1
a0151984:  d6 14 63 ca  lduh  [ %l1 + 0x3ca ], %o3	! 0xa802e3ca
a0151988:  90 10 20 00  clr  %o0
a015198c:  92 10 20 00  clr  %o1
a0151990:  7f fe e0 8b  call  0xa0109bbc
a0151994:  94 10 20 00  clr  %o2
a0151998:  7f fe d2 0a  call  0xa01061c0
a015199c:  91 e8 20 00  restore  %g0, 0, %o0
a01519a0:  90 14 63 30  or  %l1, 0x330, %o0
a01519a4:  10 bf ff d6  b  0xa01518fc
a01519a8:  c2 02 20 f0  ld  [ %o0 + 0xf0 ], %g1
a01519ac:  10 bf ff d4  b  0xa01518fc
a01519b0:  c2 03 60 78  ld  [ %o5 + 0x78 ], %g1
