# leon2s FUN_a00910ec 0xa00910ec-0xa00911bc (208 bytes)
a00910ec:  9d e3 bf 98  save  %sp, -104, %sp
a00910f0:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00910f4:  a0 0c 60 01  and  %l1, 1, %l0
a00910f8:  7f ff 8f 9a  call  0xa0074f60
a00910fc:  90 10 00 10  mov  %l0, %o0
a0091100:  82 04 00 10  add  %l0, %l0, %g1
a0091104:  82 00 40 10  add  %g1, %l0, %g1
a0091108:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a009110c:  83 28 60 03  sll  %g1, 3, %g1
a0091110:  9a 13 60 64  or  %o5, 0x64, %o5
a0091114:  82 00 40 0d  add  %g1, %o5, %g1
a0091118:  b0 10 00 08  mov  %o0, %i0
a009111c:  c2 08 60 04  ldub  [ %g1 + 4 ], %g1
a0091120:  80 a0 60 00  cmp  %g1, 0
a0091124:  02 80 00 03  be  0xa0091130
a0091128:  90 10 00 11  mov  %l1, %o0
a009112c:  b1 2e 20 02  sll  %i0, 2, %i0
a0091130:  7f ff ff 13  call  0xa0090d7c
a0091134:  01 00 00 00  nop
a0091138:  a0 10 00 08  mov  %o0, %l0
a009113c:  7f ff ff 2c  call  0xa0090dec
a0091140:  90 10 00 11  mov  %l1, %o0
a0091144:  83 2e 20 10  sll  %i0, 0x10, %g1
a0091148:  a0 0c 20 ff  and  %l0, 0xff, %l0
a009114c:  83 30 60 10  srl  %g1, 0x10, %g1
a0091150:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a0091154:  81 83 60 00  mov  %o5, %y
a0091158:  01 00 00 00  nop
a009115c:  01 00 00 00  nop
a0091160:  01 00 00 00  nop
a0091164:  82 78 40 10  sdiv  %g1, %l0, %g1
a0091168:  83 28 60 03  sll  %g1, 3, %g1
a009116c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091170:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a0091174:  81 83 60 00  mov  %o5, %y
a0091178:  01 00 00 00  nop
a009117c:  01 00 00 00  nop
a0091180:  01 00 00 00  nop
a0091184:  a0 78 40 08  sdiv  %g1, %o0, %l0
a0091188:  90 10 00 11  mov  %l1, %o0
a009118c:  40 00 54 fc  call  0xa00a657c
a0091190:  92 10 21 44  mov  0x144, %o1
a0091194:  90 0a 20 e0  and  %o0, 0xe0, %o0
a0091198:  80 a2 20 60  cmp  %o0, 0x60
a009119c:  12 80 00 04  bne  0xa00911ac
a00911a0:  b0 10 00 10  mov  %l0, %i0
a00911a4:  83 2c 20 10  sll  %l0, 0x10, %g1
a00911a8:  b1 30 60 0f  srl  %g1, 0xf, %i0
a00911ac:  b1 2e 20 10  sll  %i0, 0x10, %i0
a00911b0:  b1 36 20 10  srl  %i0, 0x10, %i0
a00911b4:  81 c7 e0 08  ret
a00911b8:  81 e8 00 00  restore
