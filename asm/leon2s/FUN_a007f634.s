# leon2s FUN_a007f634 0xa007f634-0xa007f670 (60 bytes)  [FUN_a007f668 = unreachable ret/restore tail, merged]
a007f634:  9d e3 bf 98  save  %sp, -104, %sp
a007f638:  b0 0e 20 ff  and  %i0, 0xff, %i0
a007f63c:  7f ff cf b9  call  0xa0073520
a007f640:  90 10 00 18  mov  %i0, %o0
a007f644:  b0 1e 20 02  xor  %i0, 2, %i0
a007f648:  80 8a 20 ff  btst  0xff, %o0
a007f64c:  02 80 00 06  be  0xa007f664
a007f650:  b2 10 20 01  mov  1, %i1
a007f654:  80 a0 00 18  cmp  %g0, %i0
a007f658:  b0 40 20 00  addx  %g0, 0, %i0
a007f65c:  40 00 73 d6  call  0xa009c5b4
a007f660:  81 e8 00 00  restore
a007f664:  01 00 00 00  nop
a007f668:  81 c7 e0 08  ret
a007f66c:  81 e8 00 00  restore
