# leon2m FUN_a009e820 0xa009e820-0xa009e894 (116 bytes)  [FUN_a009e88c = unreachable ret/restore tail, merged]
a009e820:  9d e3 bf 98  save  %sp, -104, %sp
a009e824:  7f ff 88 ed  call  0xa0080bd8
a009e828:  90 10 20 00  clr  %o0
a009e82c:  31 2a 00 b3  sethi  %hi(0xa802cc00), %i0
a009e830:  98 16 23 f4  or  %i0, 0x3f4, %o4	! 0xa802cff4
a009e834:  1f 00 00 1f  sethi  %hi(0x7c00), %o7
a009e838:  d6 13 20 04  lduh  [ %o4 + 4 ], %o3
a009e83c:  94 13 e3 7f  or  %o7, 0x37f, %o2
a009e840:  92 0a 80 0b  and  %o2, %o3, %o1
a009e844:  11 2a 00 ab  sethi  %hi(0xa802ac00), %o0
a009e848:  d2 33 20 04  sth  %o1, [ %o4 + 4 ]
a009e84c:  40 00 5a 0d  call  0xa00b5080
a009e850:  c0 22 23 ec  clr  [ %o0 + 0x3ec ]
a009e854:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a009e858:  da 08 60 65  ldub  [ %g1 + 0x65 ], %o5	! 0xa802d465
a009e85c:  80 a3 60 00  cmp  %o5, 0
a009e860:  02 80 00 0a  be  0xa009e888
a009e864:  90 10 20 00  clr  %o0
a009e868:  40 02 94 eb  call  0xa0143c14
a009e86c:  b0 10 20 04  mov  4, %i0
a009e870:  9a 0a 20 ff  and  %o0, 0xff, %o5
a009e874:  80 a3 60 0a  cmp  %o5, 0xa
a009e878:  02 80 00 04  be  0xa009e888
a009e87c:  b2 10 20 00  clr  %i1
a009e880:  7f ff 88 0b  call  0xa00808ac
a009e884:  81 e8 00 00  restore
a009e888:  01 00 00 00  nop
a009e88c:  81 c7 e0 08  ret
a009e890:  81 e8 00 00  restore
