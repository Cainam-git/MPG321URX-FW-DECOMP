# leon2m FUN_a014e878 0xa014e878-0xa014e8d8 (96 bytes)  [FUN_a014e8d0 = unreachable ret/restore tail, merged]
a014e878:  9d e3 bf 98  save  %sp, -104, %sp
a014e87c:  82 0e 20 ff  and  %i0, 0xff, %g1
a014e880:  90 10 20 00  clr  %o0
a014e884:  80 a0 60 00  cmp  %g1, 0
a014e888:  02 80 00 0d  be  0xa014e8bc
a014e88c:  b0 10 20 00  clr  %i0
a014e890:  80 a0 60 01  cmp  %g1, 1
a014e894:  02 80 00 06  be  0xa014e8ac
a014e898:  90 10 20 01  mov  1, %o0
a014e89c:  90 10 20 01  mov  1, %o0
a014e8a0:  80 a0 60 02  cmp  %g1, 2
a014e8a4:  12 80 00 0a  bne  0xa014e8cc
a014e8a8:  b0 10 20 01  mov  1, %i0
a014e8ac:  7f fe b5 ac  call  0xa00fbf5c
a014e8b0:  01 00 00 00  nop
a014e8b4:  7f fe b6 2a  call  0xa00fc15c
a014e8b8:  81 e8 00 00  restore
a014e8bc:  7f fe b6 28  call  0xa00fc15c
a014e8c0:  01 00 00 00  nop
a014e8c4:  7f fe b5 a6  call  0xa00fbf5c
a014e8c8:  81 e8 00 00  restore
a014e8cc:  01 00 00 00  nop
a014e8d0:  81 c7 e0 08  ret
a014e8d4:  81 e8 00 00  restore
