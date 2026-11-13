# leon2m FUN_a014bd70 0xa014bd70-0xa014be10 (160 bytes)
a014bd70:  9d e3 bf 98  save  %sp, -104, %sp
a014bd74:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014bd78:  80 a6 20 01  cmp  %i0, 1
a014bd7c:  02 80 00 0b  be  0xa014bda8
a014bd80:  82 10 20 01  mov  1, %g1
a014bd84:  80 a6 20 01  cmp  %i0, 1
a014bd88:  04 80 00 11  ble  0xa014bdcc
a014bd8c:  80 a6 20 02  cmp  %i0, 2
a014bd90:  02 80 00 06  be  0xa014bda8
a014bd94:  82 10 20 02  mov  2, %g1
a014bd98:  80 a6 20 03  cmp  %i0, 3
a014bd9c:  02 80 00 03  be  0xa014bda8
a014bda0:  82 10 20 03  mov  3, %g1
a014bda4:  82 10 3f ff  mov  -1, %g1
a014bda8:  9a 08 60 ff  and  %g1, 0xff, %o5
a014bdac:  80 a3 60 03  cmp  %o5, 3
a014bdb0:  08 80 00 0d  bleu  0xa014bde4
a014bdb4:  9f 2b 60 04  sll  %o5, 4, %o7
a014bdb8:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a014bdbc:  7f fe 4c ed  call  0xa00df170
a014bdc0:  90 12 21 d8  or  %o0, 0x1d8, %o0	! 0x1a6dd8
a014bdc4:  10 80 00 07  b  0xa014bde0
a014bdc8:  9a 10 20 00  clr  %o5
a014bdcc:  80 a6 20 00  cmp  %i0, 0
a014bdd0:  02 bf ff f6  be  0xa014bda8
a014bdd4:  82 10 20 00  clr  %g1
a014bdd8:  10 bf ff f4  b  0xa014bda8
a014bddc:  82 10 3f ff  mov  -1, %g1
a014bde0:  9f 2b 60 04  sll  %o5, 4, %o7
a014bde4:  98 23 c0 0d  sub  %o7, %o5, %o4
a014bde8:  17 2a 00 b7  sethi  %hi(0xa802dc00), %o3
a014bdec:  95 2b 20 03  sll  %o4, 3, %o2
a014bdf0:  9a 12 e3 30  or  %o3, 0x330, %o5
a014bdf4:  d2 03 40 0a  ld  [ %o5 + %o2 ], %o1
a014bdf8:  83 32 60 0c  srl  %o1, 0xc, %g1
a014bdfc:  7f ff d0 97  call  0xa0140058
a014be00:  90 08 60 0f  and  %g1, 0xf, %o0
a014be04:  b0 0a 20 ff  and  %o0, 0xff, %i0
a014be08:  81 c7 e0 08  ret
a014be0c:  81 e8 00 00  restore
