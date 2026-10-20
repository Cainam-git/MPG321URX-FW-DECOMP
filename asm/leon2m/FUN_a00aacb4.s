# leon2m FUN_a00aacb4 0xa00aacb4-0xa00aad30 (124 bytes)  [FUN_a00aad28 = unreachable ret/restore tail, merged]
a00aacb4:  9d e3 bf 98  save  %sp, -104, %sp
a00aacb8:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00aacbc:  7f ff fe 19  call  0xa00aa520
a00aacc0:  90 10 00 19  mov  %i1, %o0
a00aacc4:  92 06 40 19  add  %i1, %i1, %o1
a00aacc8:  80 8a 20 ff  btst  0xff, %o0
a00aaccc:  92 02 60 06  add  %o1, 6, %o1
a00aacd0:  94 10 20 0d  mov  0xd, %o2
a00aacd4:  96 10 22 92  mov  0x292, %o3
a00aacd8:  98 10 20 00  clr  %o4
a00aacdc:  82 06 40 19  add  %i1, %i1, %g1
a00aace0:  02 80 00 07  be  0xa00aacfc
a00aace4:  90 10 20 14  mov  0x14, %o0
a00aace8:  92 00 60 06  add  %g1, 6, %o1
a00aacec:  90 10 20 14  mov  0x14, %o0
a00aacf0:  94 10 20 0d  mov  0xd, %o2
a00aacf4:  96 10 27 92  mov  0x792, %o3
a00aacf8:  98 10 20 00  clr  %o4
a00aacfc:  40 02 6f 61  call  0xa0146a80
a00aad00:  01 00 00 00  nop
a00aad04:  82 0e 20 ff  and  %i0, 0xff, %g1
a00aad08:  80 a0 60 02  cmp  %g1, 2
a00aad0c:  12 80 00 06  bne  0xa00aad24
a00aad10:  80 a6 60 01  cmp  %i1, 1
a00aad14:  12 80 00 04  bne  0xa00aad24
a00aad18:  01 00 00 00  nop
a00aad1c:  40 00 30 0f  call  0xa00b6d58
a00aad20:  81 e8 00 00  restore
a00aad24:  01 00 00 00  nop
a00aad28:  81 c7 e0 08  ret
a00aad2c:  81 e8 00 00  restore
