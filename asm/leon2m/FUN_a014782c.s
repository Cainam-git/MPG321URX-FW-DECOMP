# leon2m FUN_a014782c 0xa014782c-0xa01478a8 (124 bytes)  [FUN_a01478a0 = unreachable ret/restore tail, merged]
a014782c:  9d e3 bf 98  save  %sp, -104, %sp
a0147830:  82 0e 20 ff  and  %i0, 0xff, %g1
a0147834:  80 a0 60 07  cmp  %g1, 7
a0147838:  18 80 00 19  bgu  0xa014789c
a014783c:  11 00 03 8c  sethi  %hi(0xe3000), %o0
a0147840:  83 28 60 02  sll  %g1, 2, %g1
a0147844:  9a 12 23 f8  or  %o0, 0x3f8, %o5
a0147848:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a014784c:  81 c3 00 00  jmp  %o4
a0147850:  01 00 00 00  nop
a0147854:  7f ff d5 86  call  0xa013ce6c
a0147858:  90 10 20 00  clr  %o0	! 0x0
a014785c:  80 8a 20 ff  btst  0xff, %o0
a0147860:  02 80 00 0f  be  0xa014789c
a0147864:  01 00 00 00  nop
a0147868:  30 80 00 0b  b,a   0xa0147894
a014786c:  7f fe d6 8b  call  0xa00fd298
a0147870:  81 e8 00 00  restore
a0147874:  7f fe d4 aa  call  0xa00fcb1c
a0147878:  81 e8 00 00  restore
a014787c:  7f fe d4 dc  call  0xa00fcbec
a0147880:  81 e8 00 00  restore
a0147884:  7f fe d5 6f  call  0xa00fce40
a0147888:  81 e8 00 00  restore
a014788c:  7f fe d5 fa  call  0xa00fd074
a0147890:  91 e8 20 6d  restore  %g0, 0x6d, %o0
a0147894:  7f fe d4 6e  call  0xa00fca4c
a0147898:  81 e8 00 00  restore
a014789c:  01 00 00 00  nop
a01478a0:  81 c7 e0 08  ret
a01478a4:  81 e8 00 00  restore
