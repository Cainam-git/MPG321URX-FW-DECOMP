# leon2m FUN_a0091094 0xa0091094-0xa00911a0 (268 bytes)
a0091094:  9d e3 bf 98  save  %sp, -104, %sp
a0091098:  11 2a 00 ab  sethi  %hi(0xa802ac00), %o0
a009109c:  d6 02 23 ec  ld  [ %o0 + 0x3ec ], %o3	! 0xa802afec
a00910a0:  80 a0 00 0b  cmp  %g0, %o3
a00910a4:  98 60 3f ff  subx  %g0, -1, %o4
a00910a8:  82 1a e1 0b  xor  %o3, 0x10b, %g1
a00910ac:  80 a0 00 01  cmp  %g0, %g1
a00910b0:  9a 60 3f ff  subx  %g0, -1, %o5
a00910b4:  90 10 20 ff  mov  0xff, %o0
a00910b8:  92 10 20 00  clr  %o1
a00910bc:  b0 10 20 42  mov  0x42, %i0
a00910c0:  80 93 00 0d  orcc  %o4, %o5, %g0
a00910c4:  12 80 00 20  bne  0xa0091144
a00910c8:  b2 10 20 43  mov  0x43, %i1
a00910cc:  80 a2 e1 0c  cmp  %o3, 0x10c
a00910d0:  02 80 00 1d  be  0xa0091144
a00910d4:  80 a2 e1 0d  cmp  %o3, 0x10d
a00910d8:  02 80 00 1b  be  0xa0091144
a00910dc:  80 a2 e1 0e  cmp  %o3, 0x10e
a00910e0:  02 80 00 19  be  0xa0091144
a00910e4:  80 a2 e1 0f  cmp  %o3, 0x10f
a00910e8:  02 80 00 17  be  0xa0091144
a00910ec:  80 a2 e1 10  cmp  %o3, 0x110
a00910f0:  02 80 00 15  be  0xa0091144
a00910f4:  82 02 fe f8  add  %o3, -264, %g1
a00910f8:  90 10 20 45  mov  0x45, %o0
a00910fc:  92 10 20 01  mov  1, %o1
a0091100:  b0 10 20 ff  mov  0xff, %i0
a0091104:  80 a0 60 01  cmp  %g1, 1
a0091108:  18 80 00 16  bgu  0xa0091160
a009110c:  b2 10 20 00  clr  %i1
a0091110:  7f ff f6 ce  call  0xa008ec48
a0091114:  01 00 00 00  nop
a0091118:  90 10 20 46  mov  0x46, %o0	! 0x46
a009111c:  7f ff f6 cb  call  0xa008ec48
a0091120:  92 10 20 01  mov  1, %o1
a0091124:  90 10 20 47  mov  0x47, %o0
a0091128:  7f ff f6 c8  call  0xa008ec48
a009112c:  92 10 20 01  mov  1, %o1
a0091130:  90 10 20 48  mov  0x48, %o0
a0091134:  7f ff f6 c5  call  0xa008ec48
a0091138:  92 10 20 01  mov  1, %o1
a009113c:  7f ff f7 1f  call  0xa008edb8
a0091140:  81 e8 00 00  restore
a0091144:  7f ff f6 c1  call  0xa008ec48
a0091148:  01 00 00 00  nop
a009114c:  90 10 20 49  mov  0x49, %o0	! 0x49
a0091150:  7f ff f6 ec  call  0xa008ed00
a0091154:  92 10 20 01  mov  1, %o1
a0091158:  7f ff f7 18  call  0xa008edb8
a009115c:  81 e8 00 00  restore
a0091160:  90 10 20 47  mov  0x47, %o0
a0091164:  7f ff f6 b9  call  0xa008ec48
a0091168:  92 10 20 01  mov  1, %o1
a009116c:  90 10 20 48  mov  0x48, %o0
a0091170:  7f ff f6 b6  call  0xa008ec48
a0091174:  92 10 20 01  mov  1, %o1
a0091178:  90 10 20 45  mov  0x45, %o0
a009117c:  7f ff f6 b3  call  0xa008ec48
a0091180:  92 10 20 01  mov  1, %o1
a0091184:  90 10 20 46  mov  0x46, %o0
a0091188:  7f ff f6 b0  call  0xa008ec48
a009118c:  92 10 20 01  mov  1, %o1
a0091190:  b0 10 20 ff  mov  0xff, %i0
a0091194:  7f ff f7 09  call  0xa008edb8
a0091198:  93 e8 20 00  restore  %g0, 0, %o1
a009119c:  01 00 00 00  nop
