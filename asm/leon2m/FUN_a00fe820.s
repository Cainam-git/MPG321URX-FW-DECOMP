# leon2m FUN_a00fe820 0xa00fe820-0xa00fe880 (96 bytes)  [FUN_a00fe878 = unreachable ret/restore tail, merged]
a00fe820:  9d e3 bf 98  save  %sp, -104, %sp
a00fe824:  90 06 3f fa  add  %i0, -6, %o0
a00fe828:  82 0a 20 ff  and  %o0, 0xff, %g1
a00fe82c:  b4 10 00 19  mov  %i1, %i2
a00fe830:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00fe834:  92 10 20 05  mov  5, %o1
a00fe838:  80 a0 60 01  cmp  %g1, 1
a00fe83c:  b2 10 20 05  mov  5, %i1
a00fe840:  18 80 00 0d  bgu  0xa00fe874
a00fe844:  90 10 00 18  mov  %i0, %o0
a00fe848:  7f ff cc 92  call  0xa00f1a90
a00fe84c:  01 00 00 00  nop
a00fe850:  92 0a 3f f7  and  %o0, -9, %o1
a00fe854:  80 8e a0 ff  btst  0xff, %i2
a00fe858:  82 12 60 01  or  %o1, 1, %g1
a00fe85c:  02 80 00 03  be  0xa00fe868
a00fe860:  90 0a 3f fe  and  %o0, -2, %o0
a00fe864:  82 12 20 08  or  %o0, 8, %g1
a00fe868:  b4 08 60 ff  and  %g1, 0xff, %i2
a00fe86c:  7f ff cc 9a  call  0xa00f1ad4
a00fe870:  81 e8 00 00  restore
a00fe874:  01 00 00 00  nop
a00fe878:  81 c7 e0 08  ret
a00fe87c:  81 e8 00 00  restore
