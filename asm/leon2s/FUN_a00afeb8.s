# leon2s FUN_a00afeb8 0xa00afeb8-0xa00b0004 (332 bytes)
a00afeb8:  9d e3 bf 98  save  %sp, -104, %sp
a00afebc:  80 8e 60 ff  btst  0xff, %i1
a00afec0:  22 80 00 08  be,a   0xa00afee0
a00afec4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00afec8:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00afecc:  c0 28 63 3a  clrb  [ %g1 + 0x33a ]	! 0xa807933a
a00afed0:  90 0e 20 ff  and  %i0, 0xff, %o0
a00afed4:  7f ff fb 5f  call  0xa00aec50
a00afed8:  92 10 20 01  mov  1, %o1
a00afedc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00afee0:  90 10 00 18  mov  %i0, %o0
a00afee4:  92 10 24 83  mov  0x483, %o1
a00afee8:  94 10 20 24  mov  0x24, %o2
a00afeec:  7f ff db 6b  call  0xa00a6c98
a00afef0:  96 10 20 01  mov  1, %o3
a00afef4:  90 10 00 18  mov  %i0, %o0
a00afef8:  92 10 24 83  mov  0x483, %o1
a00afefc:  94 10 20 03  mov  3, %o2
a00aff00:  7f ff db 66  call  0xa00a6c98
a00aff04:  96 10 20 00  clr  %o3
a00aff08:  92 10 24 86  mov  0x486, %o1
a00aff0c:  94 10 20 01  mov  1, %o2
a00aff10:  96 10 20 01  mov  1, %o3
a00aff14:  7f ff db 61  call  0xa00a6c98
a00aff18:  90 10 00 18  mov  %i0, %o0
a00aff1c:  7f ff f3 4e  call  0xa00acc54
a00aff20:  90 10 00 18  mov  %i0, %o0
a00aff24:  a0 10 00 08  mov  %o0, %l0
a00aff28:  93 2c 20 10  sll  %l0, 0x10, %o1
a00aff2c:  a0 04 3f 9b  add  %l0, -101, %l0
a00aff30:  93 32 60 10  srl  %o1, 0x10, %o1
a00aff34:  90 10 20 00  clr  %o0
a00aff38:  7f ff d3 e3  call  0xa00a4ec4
a00aff3c:  a1 2c 20 10  sll  %l0, 0x10, %l0
a00aff40:  a1 34 20 10  srl  %l0, 0x10, %l0
a00aff44:  80 a4 20 30  cmp  %l0, 0x30
a00aff48:  18 80 00 12  bgu  0xa00aff90
a00aff4c:  21 2a 01 e4  sethi  %hi(0xa8079000), %l0
a00aff50:  90 10 00 18  mov  %i0, %o0
a00aff54:  7f ff db 19  call  0xa00a6bb8
a00aff58:  92 10 22 1c  mov  0x21c, %o1
a00aff5c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00aff60:  80 a2 20 06  cmp  %o0, 6
a00aff64:  12 80 00 06  bne  0xa00aff7c
a00aff68:  90 10 00 18  mov  %i0, %o0
a00aff6c:  92 10 24 83  mov  0x483, %o1
a00aff70:  94 10 20 01  mov  1, %o2
a00aff74:  10 80 00 05  b  0xa00aff88
a00aff78:  96 10 20 00  clr  %o3
a00aff7c:  92 10 24 83  mov  0x483, %o1
a00aff80:  94 10 20 01  mov  1, %o2
a00aff84:  96 10 20 01  mov  1, %o3
a00aff88:  7f ff db 44  call  0xa00a6c98
a00aff8c:  21 2a 01 e4  sethi  %hi(0xa8079000), %l0
a00aff90:  1b 28 02 d3  sethi  %hi(0xa00b4c00), %o5
a00aff94:  c2 0c 23 3a  ldub  [ %l0 + 0x33a ], %g1
a00aff98:  9a 13 61 f8  or  %o5, 0x1f8, %o5
a00aff9c:  d4 0b 40 01  ldub  [ %o5 + %g1 ], %o2
a00affa0:  90 10 00 18  mov  %i0, %o0
a00affa4:  7f ff db 17  call  0xa00a6c00
a00affa8:  92 10 24 85  mov  0x485, %o1
a00affac:  7f ff fb 19  call  0xa00aec10
a00affb0:  01 00 00 00  nop
a00affb4:  90 10 00 18  mov  %i0, %o0
a00affb8:  7f ff fb 26  call  0xa00aec50
a00affbc:  92 10 20 00  clr  %o1
a00affc0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00affc4:  80 a2 20 01  cmp  %o0, 1
a00affc8:  12 80 00 05  bne  0xa00affdc
a00affcc:  c2 0c 23 3a  ldub  [ %l0 + 0x33a ], %g1
a00affd0:  82 00 60 01  inc  %g1
a00affd4:  c2 2c 23 3a  stb  %g1, [ %l0 + 0x33a ]
a00affd8:  c2 0c 23 3a  ldub  [ %l0 + 0x33a ], %g1
a00affdc:  80 a0 60 0a  cmp  %g1, 0xa
a00affe0:  08 80 00 07  bleu  0xa00afffc
a00affe4:  82 10 20 00  clr  %g1
a00affe8:  c0 2c 23 3a  clrb  [ %l0 + 0x33a ]
a00affec:  90 10 00 18  mov  %i0, %o0
a00afff0:  7f ff ff 81  call  0xa00afdf4
a00afff4:  92 10 20 00  clr  %o1
a00afff8:  82 10 20 01  mov  1, %g1
a00afffc:  81 c7 e0 08  ret
a00b0000:  91 e8 00 01  restore  %g0, %g1, %o0
