# leon2m FUN_a014110c 0xa014110c-0xa014118c (128 bytes)
a014110c:  9d e3 bf 98  save  %sp, -104, %sp
a0141110:  23 2a 00 a9  sethi  %hi(0xa802a400), %l1
a0141114:  c2 0c 60 7c  ldub  [ %l1 + 0x7c ], %g1	! 0xa802a47c
a0141118:  a0 0e 20 ff  and  %i0, 0xff, %l0
a014111c:  80 a0 40 10  cmp  %g1, %l0
a0141120:  02 80 00 13  be  0xa014116c
a0141124:  17 2a 00 9e  sethi  %hi(0xa8027800), %o3
a0141128:  93 2c 20 02  sll  %l0, 2, %o1
a014112c:  94 12 e3 b0  or  %o3, 0x3b0, %o2
a0141130:  7f ff 5d 6c  call  0xa01186e0
a0141134:  d0 02 80 09  ld  [ %o2 + %o1 ], %o0
a0141138:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a014113c:  da 0a 21 a7  ldub  [ %o0 + 0x1a7 ], %o5	! 0xa802e1a7
a0141140:  90 10 20 02  mov  2, %o0
a0141144:  80 a3 60 00  cmp  %o5, 0
a0141148:  12 80 00 06  bne  0xa0141160
a014114c:  f0 2c 60 7c  stb  %i0, [ %l1 + 0x7c ]
a0141150:  7f ff 5d 36  call  0xa0118628
a0141154:  01 00 00 00  nop
a0141158:  7f ff 5d 1f  call  0xa01185d4
a014115c:  81 e8 00 00  restore
a0141160:  7f ff 5d 32  call  0xa0118628
a0141164:  90 10 20 03  mov  3, %o0
a0141168:  30 bf ff fc  b,a   0xa0141158
a014116c:  7f ff 5e 08  call  0xa011898c
a0141170:  01 00 00 00  nop
a0141174:  80 8a 20 ff  btst  0xff, %o0
a0141178:  12 bf ff ec  bne  0xa0141128
a014117c:  17 2a 00 9e  sethi  %hi(0xa8027800), %o3
a0141180:  7f ff 5d 15  call  0xa01185d4
a0141184:  81 e8 00 00  restore
a0141188:  01 00 00 00  nop
