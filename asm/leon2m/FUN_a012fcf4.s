# leon2m FUN_a012fcf4 0xa012fcf4-0xa01302a4 (648 bytes)
a012fcf4:  9d e3 bf 98  save  %sp, -104, %sp
a012fcf8:  23 2a 00 b8  sethi  %hi(0xa802e000), %l1
a012fcfc:  25 2a 00 b7  sethi  %hi(0xa802dc00), %l2
a012fd00:  a0 14 61 a0  or  %l1, 0x1a0, %l0
a012fd04:  d4 04 a3 30  ld  [ %l2 + 0x330 ], %o2
a012fd08:  11 00 06 94  sethi  %hi(0x1a5000), %o0
a012fd0c:  90 12 22 40  or  %o0, 0x240, %o0	! 0x1a5240
a012fd10:  94 0a a0 01  and  %o2, 1, %o2
a012fd14:  7f fe bd 17  call  0xa00df170
a012fd18:  d2 0c 20 07  ldub  [ %l0 + 7 ], %o1
a012fd1c:  c2 0c 20 07  ldub  [ %l0 + 7 ], %g1
a012fd20:  80 a0 60 07  cmp  %g1, 7
a012fd24:  18 80 00 0c  bgu  0xa012fd54
a012fd28:  13 00 03 3c  sethi  %hi(0xcf000), %o1
a012fd2c:  83 28 60 02  sll  %g1, 2, %g1
a012fd30:  9a 12 61 ac  or  %o1, 0x1ac, %o5
a012fd34:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a012fd38:  81 c3 00 00  jmp  %o4
a012fd3c:  01 00 00 00  nop
a012fd40:  9e 14 61 a0  or  %l1, 0x1a0, %o7
a012fd44:  d6 0b e0 07  ldub  [ %o7 + 7 ], %o3
a012fd48:  80 a2 e0 01  cmp  %o3, 1
a012fd4c:  02 80 01 4f  be  0xa0130288
a012fd50:  01 00 00 00  nop
a012fd54:  40 00 34 15  call  0xa013cda8
a012fd58:  90 10 20 01  mov  1, %o0	! 0x1
a012fd5c:  90 0a 20 ff  and  %o0, 0xff, %o0
a012fd60:  92 10 20 00  clr  %o1
a012fd64:  7f ff 65 c4  call  0xa0109474
a012fd68:  01 00 00 00  nop
a012fd6c:  40 00 34 0f  call  0xa013cda8
a012fd70:  90 10 20 01  mov  1, %o0	! 0x1
a012fd74:  90 0a 20 ff  and  %o0, 0xff, %o0
a012fd78:  92 10 20 00  clr  %o1
a012fd7c:  7f ff 65 8b  call  0xa01093a8
a012fd80:  01 00 00 00  nop
a012fd84:  40 00 34 09  call  0xa013cda8
a012fd88:  90 10 20 02  mov  2, %o0	! 0x2
a012fd8c:  90 0a 20 ff  and  %o0, 0xff, %o0
a012fd90:  92 10 20 00  clr  %o1
a012fd94:  7f ff 65 b8  call  0xa0109474
a012fd98:  01 00 00 00  nop
a012fd9c:  40 00 34 03  call  0xa013cda8
a012fda0:  90 10 20 02  mov  2, %o0	! 0x2
a012fda4:  90 0a 20 ff  and  %o0, 0xff, %o0
a012fda8:  92 10 20 00  clr  %o1
a012fdac:  7f ff 65 7f  call  0xa01093a8
a012fdb0:  01 00 00 00  nop
a012fdb4:  40 00 33 fd  call  0xa013cda8
a012fdb8:  90 10 20 03  mov  3, %o0	! 0x3
a012fdbc:  90 0a 20 ff  and  %o0, 0xff, %o0
a012fdc0:  92 10 20 00  clr  %o1
a012fdc4:  7f ff 65 ac  call  0xa0109474
a012fdc8:  01 00 00 00  nop
a012fdcc:  40 00 33 f7  call  0xa013cda8
a012fdd0:  90 10 20 03  mov  3, %o0	! 0x3
a012fdd4:  90 0a 20 ff  and  %o0, 0xff, %o0
a012fdd8:  92 10 20 00  clr  %o1
a012fddc:  7f ff 65 73  call  0xa01093a8
a012fde0:  01 00 00 00  nop
a012fde4:  40 00 34 ed  call  0xa013d198
a012fde8:  01 00 00 00  nop
a012fdec:  a6 0a 20 ff  and  %o0, 0xff, %l3
a012fdf0:  80 a4 e0 01  cmp  %l3, 1
a012fdf4:  02 80 00 08  be  0xa012fe14
a012fdf8:  01 00 00 00  nop
a012fdfc:  40 00 34 df  call  0xa013d178
a012fe00:  01 00 00 00  nop
a012fe04:  a0 0a 20 ff  and  %o0, 0xff, %l0
a012fe08:  80 a4 20 01  cmp  %l0, 1
a012fe0c:  12 80 00 4d  bne  0xa012ff40
a012fe10:  01 00 00 00  nop
a012fe14:  40 00 33 e5  call  0xa013cda8
a012fe18:  90 10 20 00  clr  %o0	! 0x0
a012fe1c:  92 10 20 01  mov  1, %o1
a012fe20:  7f ff 65 62  call  0xa01093a8
a012fe24:  90 0a 20 ff  and  %o0, 0xff, %o0
a012fe28:  40 00 62 8b  call  0xa0148854
a012fe2c:  01 00 00 00  nop
a012fe30:  7f ff 8c e9  call  0xa01131d4
a012fe34:  90 0a 20 ff  and  %o0, 0xff, %o0
a012fe38:  7f ff 66 83  call  0xa0109844
a012fe3c:  01 00 00 00  nop
a012fe40:  40 00 49 5a  call  0xa01423a8
a012fe44:  01 00 00 00  nop
a012fe48:  80 8a 20 ff  btst  0xff, %o0
a012fe4c:  12 80 00 4d  bne  0xa012ff80
a012fe50:  01 00 00 00  nop
a012fe54:  94 14 61 a0  or  %l1, 0x1a0, %o2
a012fe58:  c2 0a a0 07  ldub  [ %o2 + 7 ], %g1
a012fe5c:  80 a0 60 07  cmp  %g1, 7
a012fe60:  18 80 00 23  bgu  0xa012feec
a012fe64:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a012fe68:  13 00 03 3c  sethi  %hi(0xcf000), %o1
a012fe6c:  99 28 60 02  sll  %g1, 2, %o4
a012fe70:  9a 12 61 8c  or  %o1, 0x18c, %o5
a012fe74:  d0 03 40 0c  ld  [ %o5 + %o4 ], %o0
a012fe78:  81 c2 00 00  jmp  %o0
a012fe7c:  01 00 00 00  nop
a012fe80:  7f ff 64 a4  call  0xa0109110
a012fe84:  90 10 20 01  mov  1, %o0	! 0x1
a012fe88:  40 00 33 c8  call  0xa013cda8
a012fe8c:  90 10 20 00  clr  %o0
a012fe90:  92 10 20 01  mov  1, %o1
a012fe94:  7f ff 61 85  call  0xa01084a8
a012fe98:  90 0a 20 ff  and  %o0, 0xff, %o0
a012fe9c:  40 00 33 c3  call  0xa013cda8
a012fea0:  90 10 20 01  mov  1, %o0
a012fea4:  92 10 20 01  mov  1, %o1
a012fea8:  7f ff 61 80  call  0xa01084a8
a012feac:  90 0a 20 ff  and  %o0, 0xff, %o0
a012feb0:  40 00 33 be  call  0xa013cda8
a012feb4:  90 10 20 02  mov  2, %o0
a012feb8:  92 10 20 01  mov  1, %o1
a012febc:  7f ff 61 7b  call  0xa01084a8
a012fec0:  90 0a 20 ff  and  %o0, 0xff, %o0
a012fec4:  40 00 33 b9  call  0xa013cda8
a012fec8:  90 10 20 03  mov  3, %o0
a012fecc:  90 0a 20 ff  and  %o0, 0xff, %o0
a012fed0:  92 10 20 01  mov  1, %o1
a012fed4:  7f ff 61 75  call  0xa01084a8
a012fed8:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a012fedc:  d6 04 23 d0  ld  [ %l0 + 0x3d0 ], %o3	! 0xa802e3d0
a012fee0:  a5 32 e0 1a  srl  %o3, 0x1a, %l2
a012fee4:  7f ff 65 b6  call  0xa01095bc
a012fee8:  90 0c a0 01  and  %l2, 1, %o0
a012feec:  e6 04 23 d0  ld  [ %l0 + 0x3d0 ], %l3
a012fef0:  1f 00 08 00  sethi  %hi(0x200000), %o7
a012fef4:  80 8c c0 0f  btst  %l3, %o7
a012fef8:  12 80 00 26  bne  0xa012ff90
a012fefc:  27 2a 00 b8  sethi  %hi(0xa802e000), %l3
a012ff00:  a2 14 61 a0  or  %l1, 0x1a0, %l1
a012ff04:  25 2a 00 b2  sethi  %hi(0xa802c800), %l2
a012ff08:  e0 0c a3 80  ldub  [ %l2 + 0x380 ], %l0	! 0xa802cb80
a012ff0c:  d4 0c 60 07  ldub  [ %l1 + 7 ], %o2
a012ff10:  80 a2 80 10  cmp  %o2, %l0
a012ff14:  02 80 00 30  be  0xa012ffd4
a012ff18:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a012ff1c:  40 00 7a 2d  call  0xa014e7d0
a012ff20:  01 00 00 00  nop
a012ff24:  de 04 e3 d0  ld  [ %l3 + 0x3d0 ], %o7
a012ff28:  d6 0c 60 07  ldub  [ %l1 + 7 ], %o3
a012ff2c:  83 33 e0 1a  srl  %o7, 0x1a, %g1
a012ff30:  a2 08 60 01  and  %g1, 1, %l1
a012ff34:  d6 2c a3 80  stb  %o3, [ %l2 + 0x380 ]
a012ff38:  10 80 00 d9  b  0xa013029c
a012ff3c:  e2 2c 23 81  stb  %l1, [ %l0 + 0x381 ]
a012ff40:  40 00 33 9a  call  0xa013cda8
a012ff44:  90 10 20 00  clr  %o0
a012ff48:  92 10 20 00  clr  %o1
a012ff4c:  7f ff 65 17  call  0xa01093a8
a012ff50:  90 0a 20 ff  and  %o0, 0xff, %o0
a012ff54:  40 00 62 40  call  0xa0148854
a012ff58:  01 00 00 00  nop
a012ff5c:  7f ff 8c 9e  call  0xa01131d4
a012ff60:  90 0a 20 ff  and  %o0, 0xff, %o0
a012ff64:  7f ff 66 38  call  0xa0109844
a012ff68:  01 00 00 00  nop
a012ff6c:  40 00 49 0f  call  0xa01423a8
a012ff70:  01 00 00 00  nop
a012ff74:  80 8a 20 ff  btst  0xff, %o0
a012ff78:  22 bf ff b8  be,a   0xa012fe58
a012ff7c:  94 14 61 a0  or  %l1, 0x1a0, %o2
a012ff80:  7f ff 8d c8  call  0xa01136a0
a012ff84:  01 00 00 00  nop
a012ff88:  10 bf ff b4  b  0xa012fe58
a012ff8c:  94 14 61 a0  or  %l1, 0x1a0, %o2
a012ff90:  40 00 33 86  call  0xa013cda8
a012ff94:  90 10 20 03  mov  3, %o0
a012ff98:  92 10 20 01  mov  1, %o1
a012ff9c:  7f ff 61 43  call  0xa01084a8
a012ffa0:  90 0a 20 ff  and  %o0, 0xff, %o0
a012ffa4:  40 00 33 81  call  0xa013cda8
a012ffa8:  90 10 20 03  mov  3, %o0
a012ffac:  90 0a 20 ff  and  %o0, 0xff, %o0
a012ffb0:  7f ff 65 69  call  0xa0109554
a012ffb4:  92 10 20 00  clr  %o1
a012ffb8:  a2 14 61 a0  or  %l1, 0x1a0, %l1
a012ffbc:  25 2a 00 b2  sethi  %hi(0xa802c800), %l2
a012ffc0:  e0 0c a3 80  ldub  [ %l2 + 0x380 ], %l0	! 0xa802cb80
a012ffc4:  d4 0c 60 07  ldub  [ %l1 + 7 ], %o2
a012ffc8:  80 a2 80 10  cmp  %o2, %l0
a012ffcc:  12 bf ff d4  bne  0xa012ff1c
a012ffd0:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a012ffd4:  d2 04 e3 d0  ld  [ %l3 + 0x3d0 ], %o1
a012ffd8:  9b 32 60 1a  srl  %o1, 0x1a, %o5
a012ffdc:  90 0b 60 01  and  %o5, 1, %o0
a012ffe0:  d8 0c 23 81  ldub  [ %l0 + 0x381 ], %o4
a012ffe4:  80 a3 00 08  cmp  %o4, %o0
a012ffe8:  12 bf ff cd  bne  0xa012ff1c
a012ffec:  01 00 00 00  nop
a012fff0:  30 80 00 ab  b,a   0xa013029c
a012fff4:  7f ff 64 47  call  0xa0109110
a012fff8:  90 10 20 01  mov  1, %o0
a012fffc:  40 00 33 6b  call  0xa013cda8
a0130000:  90 10 20 00  clr  %o0
a0130004:  92 10 20 01  mov  1, %o1
a0130008:  7f ff 61 28  call  0xa01084a8
a013000c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130010:  40 00 33 66  call  0xa013cda8
a0130014:  90 10 20 01  mov  1, %o0
a0130018:  92 10 20 01  mov  1, %o1
a013001c:  7f ff 61 23  call  0xa01084a8
a0130020:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130024:  40 00 33 61  call  0xa013cda8
a0130028:  90 10 20 02  mov  2, %o0
a013002c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130030:  92 10 20 01  mov  1, %o1
a0130034:  7f ff 61 1d  call  0xa01084a8
a0130038:  01 00 00 00  nop
a013003c:  40 00 33 5b  call  0xa013cda8
a0130040:  90 10 20 03  mov  3, %o0	! 0x3
a0130044:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130048:  10 bf ff a3  b  0xa012fed4
a013004c:  92 10 20 00  clr  %o1
a0130050:  7f ff 64 30  call  0xa0109110
a0130054:  90 10 20 01  mov  1, %o0
a0130058:  40 00 33 54  call  0xa013cda8
a013005c:  90 10 20 00  clr  %o0
a0130060:  92 10 20 01  mov  1, %o1
a0130064:  7f ff 61 11  call  0xa01084a8
a0130068:  90 0a 20 ff  and  %o0, 0xff, %o0
a013006c:  40 00 33 4f  call  0xa013cda8
a0130070:  90 10 20 01  mov  1, %o0
a0130074:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130078:  92 10 20 01  mov  1, %o1
a013007c:  7f ff 61 0b  call  0xa01084a8
a0130080:  01 00 00 00  nop
a0130084:  40 00 33 49  call  0xa013cda8
a0130088:  90 10 20 02  mov  2, %o0	! 0x2
a013008c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130090:  10 bf ff e9  b  0xa0130034
a0130094:  92 10 20 00  clr  %o1
a0130098:  40 00 33 44  call  0xa013cda8
a013009c:  90 10 20 01  mov  1, %o0
a01300a0:  92 10 20 01  mov  1, %o1
a01300a4:  7f ff 64 f4  call  0xa0109474
a01300a8:  90 0a 20 ff  and  %o0, 0xff, %o0
a01300ac:  40 00 33 3f  call  0xa013cda8
a01300b0:  90 10 20 01  mov  1, %o0
a01300b4:  92 10 20 00  clr  %o1
a01300b8:  7f ff 64 bc  call  0xa01093a8
a01300bc:  90 0a 20 ff  and  %o0, 0xff, %o0
a01300c0:  40 00 33 3a  call  0xa013cda8
a01300c4:  90 10 20 02  mov  2, %o0
a01300c8:  90 0a 20 ff  and  %o0, 0xff, %o0
a01300cc:  10 bf ff 32  b  0xa012fd94
a01300d0:  92 10 20 01  mov  1, %o1
a01300d4:  40 00 33 35  call  0xa013cda8
a01300d8:  90 10 20 01  mov  1, %o0
a01300dc:  92 10 20 01  mov  1, %o1
a01300e0:  7f ff 64 e5  call  0xa0109474
a01300e4:  90 0a 20 ff  and  %o0, 0xff, %o0
a01300e8:  40 00 33 30  call  0xa013cda8
a01300ec:  90 10 20 01  mov  1, %o0
a01300f0:  92 10 20 00  clr  %o1
a01300f4:  7f ff 64 ad  call  0xa01093a8
a01300f8:  90 0a 20 ff  and  %o0, 0xff, %o0
a01300fc:  40 00 33 2b  call  0xa013cda8
a0130100:  90 10 20 02  mov  2, %o0
a0130104:  92 10 20 01  mov  1, %o1
a0130108:  7f ff 64 db  call  0xa0109474
a013010c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130110:  40 00 33 26  call  0xa013cda8
a0130114:  90 10 20 02  mov  2, %o0
a0130118:  92 10 20 00  clr  %o1
a013011c:  7f ff 64 a3  call  0xa01093a8
a0130120:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130124:  40 00 33 21  call  0xa013cda8
a0130128:  90 10 20 03  mov  3, %o0
a013012c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130130:  10 bf ff 25  b  0xa012fdc4
a0130134:  92 10 20 01  mov  1, %o1
a0130138:  40 00 33 1c  call  0xa013cda8
a013013c:  90 10 20 01  mov  1, %o0
a0130140:  92 10 20 00  clr  %o1
a0130144:  7f ff 64 cc  call  0xa0109474
a0130148:  90 0a 20 ff  and  %o0, 0xff, %o0
a013014c:  40 00 33 17  call  0xa013cda8
a0130150:  90 10 20 01  mov  1, %o0
a0130154:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130158:  10 bf ff 09  b  0xa012fd7c
a013015c:  92 10 20 01  mov  1, %o1
a0130160:  40 00 33 12  call  0xa013cda8
a0130164:  90 10 20 01  mov  1, %o0
a0130168:  92 10 20 00  clr  %o1
a013016c:  7f ff 64 c2  call  0xa0109474
a0130170:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130174:  40 00 33 0d  call  0xa013cda8
a0130178:  90 10 20 01  mov  1, %o0
a013017c:  92 10 20 01  mov  1, %o1
a0130180:  7f ff 64 8a  call  0xa01093a8
a0130184:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130188:  40 00 33 08  call  0xa013cda8
a013018c:  90 10 20 02  mov  2, %o0
a0130190:  92 10 20 00  clr  %o1
a0130194:  7f ff 64 b8  call  0xa0109474
a0130198:  90 0a 20 ff  and  %o0, 0xff, %o0
a013019c:  40 00 33 03  call  0xa013cda8
a01301a0:  90 10 20 02  mov  2, %o0
a01301a4:  90 0a 20 ff  and  %o0, 0xff, %o0
a01301a8:  10 bf ff 01  b  0xa012fdac
a01301ac:  92 10 20 01  mov  1, %o1
a01301b0:  40 00 32 fe  call  0xa013cda8
a01301b4:  90 10 20 01  mov  1, %o0
a01301b8:  92 10 20 00  clr  %o1
a01301bc:  7f ff 64 ae  call  0xa0109474
a01301c0:  90 0a 20 ff  and  %o0, 0xff, %o0
a01301c4:  40 00 32 f9  call  0xa013cda8
a01301c8:  90 10 20 01  mov  1, %o0
a01301cc:  92 10 20 01  mov  1, %o1
a01301d0:  7f ff 64 76  call  0xa01093a8
a01301d4:  90 0a 20 ff  and  %o0, 0xff, %o0
a01301d8:  40 00 32 f4  call  0xa013cda8
a01301dc:  90 10 20 02  mov  2, %o0
a01301e0:  92 10 20 00  clr  %o1
a01301e4:  7f ff 64 a4  call  0xa0109474
a01301e8:  90 0a 20 ff  and  %o0, 0xff, %o0
a01301ec:  40 00 32 ef  call  0xa013cda8
a01301f0:  90 10 20 02  mov  2, %o0
a01301f4:  92 10 20 01  mov  1, %o1
a01301f8:  7f ff 64 6c  call  0xa01093a8
a01301fc:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130200:  40 00 32 ea  call  0xa013cda8
a0130204:  90 10 20 03  mov  3, %o0
a0130208:  92 10 20 00  clr  %o1
a013020c:  7f ff 64 9a  call  0xa0109474
a0130210:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130214:  40 00 32 e5  call  0xa013cda8
a0130218:  90 10 20 03  mov  3, %o0
a013021c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130220:  10 bf fe ef  b  0xa012fddc
a0130224:  92 10 20 01  mov  1, %o1
a0130228:  c2 04 a3 30  ld  [ %l2 + 0x330 ], %g1
a013022c:  80 88 60 01  btst  1, %g1
a0130230:  02 80 00 0f  be  0xa013026c
a0130234:  01 00 00 00  nop
a0130238:  40 00 32 dc  call  0xa013cda8
a013023c:  90 10 20 00  clr  %o0	! 0x0
a0130240:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130244:  7f ff 60 99  call  0xa01084a8
a0130248:  92 10 20 00  clr  %o1
a013024c:  90 10 20 00  clr  %o0
a0130250:  7f ff 63 b0  call  0xa0109110
a0130254:  01 00 00 00  nop
a0130258:  40 00 32 d4  call  0xa013cda8
a013025c:  90 10 20 01  mov  1, %o0	! 0x1
a0130260:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130264:  10 bf ff 86  b  0xa013007c
a0130268:  92 10 20 00  clr  %o1
a013026c:  40 00 32 cf  call  0xa013cda8
a0130270:  90 10 20 00  clr  %o0
a0130274:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130278:  7f ff 60 8c  call  0xa01084a8
a013027c:  92 10 20 01  mov  1, %o1
a0130280:  10 bf ff f4  b  0xa0130250
a0130284:  90 10 20 01  mov  1, %o0
a0130288:  40 00 32 c8  call  0xa013cda8
a013028c:  90 10 20 01  mov  1, %o0
a0130290:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130294:  10 bf fe b4  b  0xa012fd64
a0130298:  92 10 20 01  mov  1, %o1
a013029c:  81 c7 e0 08  ret
a01302a0:  81 e8 00 00  restore
