# leon2m FUN_a0109148 0xa0109148-0xa0109278 (304 bytes)  [FUN_a0109270 = unreachable ret/restore tail, merged]
a0109148:  9d e3 bf 98  save  %sp, -104, %sp
a010914c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0109150:  80 a6 20 01  cmp  %i0, 1
a0109154:  02 80 00 0a  be  0xa010917c
a0109158:  91 2e 60 10  sll  %i1, 0x10, %o0
a010915c:  04 80 00 29  ble  0xa0109200
a0109160:  80 a6 20 02  cmp  %i0, 2
a0109164:  02 80 00 16  be  0xa01091bc
a0109168:  80 a6 20 03  cmp  %i0, 3
a010916c:  12 80 00 40  bne  0xa010926c
a0109170:  9b 2e 60 10  sll  %i1, 0x10, %o5
a0109174:  10 80 00 2f  b  0xa0109230
a0109178:  a1 33 60 10  srl  %o5, 0x10, %l0
a010917c:  31 33 c0 46  sethi  %hi(0xcf011800), %i0
a0109180:  a1 32 20 10  srl  %o0, 0x10, %l0
a0109184:  90 16 23 20  or  %i0, 0x320, %o0
a0109188:  7f ff a7 c1  call  0xa00f308c
a010918c:  92 10 00 10  mov  %l0, %o1
a0109190:  83 2e a0 10  sll  %i2, 0x10, %g1
a0109194:  b3 30 60 10  srl  %g1, 0x10, %i1
a0109198:  90 16 23 30  or  %i0, 0x330, %o0
a010919c:  7f ff a7 bc  call  0xa00f308c
a01091a0:  92 10 00 19  mov  %i1, %o1
a01091a4:  90 16 23 80  or  %i0, 0x380, %o0
a01091a8:  7f ff a7 b9  call  0xa00f308c
a01091ac:  92 10 00 10  mov  %l0, %o1
a01091b0:  b0 16 23 90  or  %i0, 0x390, %i0
a01091b4:  7f ff a7 b6  call  0xa00f308c
a01091b8:  81 e8 00 00  restore
a01091bc:  97 2e 60 10  sll  %i1, 0x10, %o3
a01091c0:  a1 32 e0 10  srl  %o3, 0x10, %l0
a01091c4:  31 33 c0 46  sethi  %hi(0xcf011800), %i0
a01091c8:  90 16 23 40  or  %i0, 0x340, %o0	! 0xcf011b40
a01091cc:  7f ff a7 b0  call  0xa00f308c
a01091d0:  92 10 00 10  mov  %l0, %o1
a01091d4:  95 2e a0 10  sll  %i2, 0x10, %o2
a01091d8:  b3 32 a0 10  srl  %o2, 0x10, %i1
a01091dc:  90 16 23 50  or  %i0, 0x350, %o0
a01091e0:  7f ff a7 ab  call  0xa00f308c
a01091e4:  92 10 00 19  mov  %i1, %o1
a01091e8:  90 16 23 a0  or  %i0, 0x3a0, %o0
a01091ec:  7f ff a7 a8  call  0xa00f308c
a01091f0:  92 10 00 10  mov  %l0, %o1
a01091f4:  b0 16 23 b0  or  %i0, 0x3b0, %i0
a01091f8:  7f ff a7 a5  call  0xa00f308c
a01091fc:  81 e8 00 00  restore
a0109200:  80 a6 20 00  cmp  %i0, 0
a0109204:  12 80 00 1a  bne  0xa010926c
a0109208:  93 2e 60 10  sll  %i1, 0x10, %o1
a010920c:  31 33 c0 46  sethi  %hi(0xcf011800), %i0
a0109210:  90 16 23 00  or  %i0, 0x300, %o0	! 0xcf011b00
a0109214:  93 32 60 10  srl  %o1, 0x10, %o1
a0109218:  7f ff a7 9d  call  0xa00f308c
a010921c:  b3 2e a0 10  sll  %i2, 0x10, %i1
a0109220:  b0 16 23 10  or  %i0, 0x310, %i0
a0109224:  b3 36 60 10  srl  %i1, 0x10, %i1
a0109228:  7f ff a7 99  call  0xa00f308c
a010922c:  81 e8 00 00  restore
a0109230:  31 33 c0 46  sethi  %hi(0xcf011800), %i0
a0109234:  90 16 23 60  or  %i0, 0x360, %o0	! 0xcf011b60
a0109238:  7f ff a7 95  call  0xa00f308c
a010923c:  92 10 00 10  mov  %l0, %o1
a0109240:  99 2e a0 10  sll  %i2, 0x10, %o4
a0109244:  b3 33 20 10  srl  %o4, 0x10, %i1
a0109248:  90 16 23 70  or  %i0, 0x370, %o0
a010924c:  7f ff a7 90  call  0xa00f308c
a0109250:  92 10 00 19  mov  %i1, %o1
a0109254:  90 16 23 c0  or  %i0, 0x3c0, %o0
a0109258:  7f ff a7 8d  call  0xa00f308c
a010925c:  92 10 00 10  mov  %l0, %o1
a0109260:  b0 16 23 d0  or  %i0, 0x3d0, %i0
a0109264:  7f ff a7 8a  call  0xa00f308c
a0109268:  81 e8 00 00  restore
a010926c:  01 00 00 00  nop
a0109270:  81 c7 e0 08  ret
a0109274:  81 e8 00 00  restore
