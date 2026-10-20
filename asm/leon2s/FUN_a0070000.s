# leon2s FUN_a0070000 0xa0070000-0xa00700cc (204 bytes)
a0070000:  9d e3 bf 98  save  %sp, -104, %sp
a0070004:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0070008:  c0 20 60 d8  clr  [ %g1 + 0xd8 ]	! 0xa80788d8
a007000c:  98 10 00 01  mov  %g1, %o4
a0070010:  b2 10 20 00  clr  %i1
a0070014:  9e 10 20 01  mov  1, %o7
a0070018:  b5 36 20 08  srl  %i0, 8, %i2
a007001c:  9b 36 20 10  srl  %i0, 0x10, %o5
a0070020:  b8 10 20 00  clr  %i4
a0070024:  b6 0e 60 ff  and  %i1, 0xff, %i3
a0070028:  bb 2b c0 1b  sll  %o7, %i3, %i5
a007002c:  82 0e 00 1d  and  %i0, %i5, %g1
a0070030:  80 88 60 ff  btst  0xff, %g1
a0070034:  32 80 00 08  bne,a   0xa0070054
a0070038:  b8 17 00 1d  or  %i4, %i5, %i4
a007003c:  82 0e 80 1d  and  %i2, %i5, %g1
a0070040:  80 88 60 ff  btst  0xff, %g1
a0070044:  02 80 00 05  be  0xa0070058
a0070048:  82 0b 40 1d  and  %o5, %i5, %g1
a007004c:  b8 17 00 1d  or  %i4, %i5, %i4
a0070050:  bb 2b c0 1b  sll  %o7, %i3, %i5
a0070054:  82 0b 40 1d  and  %o5, %i5, %g1
a0070058:  80 88 60 ff  btst  0xff, %g1
a007005c:  02 80 00 05  be  0xa0070070
a0070060:  82 0e 00 1d  and  %i0, %i5, %g1
a0070064:  83 2f 60 08  sll  %i5, 8, %g1
a0070068:  b8 17 00 01  or  %i4, %g1, %i4
a007006c:  82 0e 00 1d  and  %i0, %i5, %g1
a0070070:  80 88 60 ff  btst  0xff, %g1
a0070074:  22 80 00 09  be,a   0xa0070098
a0070078:  bb 2b c0 1b  sll  %o7, %i3, %i5
a007007c:  82 0e 80 1d  and  %i2, %i5, %g1
a0070080:  80 88 60 ff  btst  0xff, %g1
a0070084:  22 80 00 05  be,a   0xa0070098
a0070088:  bb 2b c0 1b  sll  %o7, %i3, %i5
a007008c:  83 2f 60 10  sll  %i5, 0x10, %g1
a0070090:  b8 17 00 01  or  %i4, %g1, %i4
a0070094:  bb 2b c0 1b  sll  %o7, %i3, %i5
a0070098:  82 0e 80 1d  and  %i2, %i5, %g1
a007009c:  80 88 60 ff  btst  0xff, %g1
a00700a0:  02 80 00 04  be  0xa00700b0
a00700a4:  b2 06 60 01  inc  %i1
a00700a8:  83 2f 60 18  sll  %i5, 0x18, %g1
a00700ac:  b8 17 00 01  or  %i4, %g1, %i4
a00700b0:  82 0e 60 ff  and  %i1, 0xff, %g1
a00700b4:  80 a0 60 02  cmp  %g1, 2
a00700b8:  08 bf ff dc  bleu  0xa0070028
a00700bc:  b6 0e 60 ff  and  %i1, 0xff, %i3
a00700c0:  f8 23 20 d8  st  %i4, [ %o4 + 0xd8 ]
a00700c4:  81 c7 e0 08  ret
a00700c8:  81 e8 00 00  restore
