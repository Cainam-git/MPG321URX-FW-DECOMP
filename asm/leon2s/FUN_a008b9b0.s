# leon2s FUN_a008b9b0 0xa008b9b0-0xa008b9ec (60 bytes)  [FUN_a008b9e4 = unreachable ret/restore tail, merged]
a008b9b0:  9d e3 bf 98  save  %sp, -104, %sp
a008b9b4:  80 8e 60 ff  btst  0xff, %i1
a008b9b8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008b9bc:  b4 10 20 40  mov  0x40, %i2
a008b9c0:  b6 10 20 00  clr  %i3
a008b9c4:  b2 10 20 50  mov  0x50, %i1
a008b9c8:  02 80 00 06  be  0xa008b9e0
a008b9cc:  90 10 00 18  mov  %i0, %o0
a008b9d0:  7f ff ff 49  call  0xa008b6f4
a008b9d4:  01 00 00 00  nop
a008b9d8:  40 00 6c b0  call  0xa00a6c98
a008b9dc:  81 e8 00 00  restore
a008b9e0:  01 00 00 00  nop
a008b9e4:  81 c7 e0 08  ret
a008b9e8:  81 e8 00 00  restore
