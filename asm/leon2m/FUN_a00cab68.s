# leon2m FUN_a00cab68 0xa00cab68-0xa00cabf8 (144 bytes)
a00cab68:  9d e3 bf 98  save  %sp, -104, %sp
a00cab6c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cab70:  80 a6 20 02  cmp  %i0, 2
a00cab74:  02 80 00 19  be  0xa00cabd8
a00cab78:  80 a6 20 03  cmp  %i0, 3
a00cab7c:  02 80 00 1a  be  0xa00cabe4
a00cab80:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cab84:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00cab88:  94 08 60 ff  and  %g1, 0xff, %o2
a00cab8c:  98 02 bf d0  add  %o2, -48, %o4
a00cab90:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00cab94:  80 a3 60 01  cmp  %o5, 1
a00cab98:  18 80 00 16  bgu  0xa00cabf0
a00cab9c:  82 10 20 ff  mov  0xff, %g1
a00caba0:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a00caba4:  40 00 3f df  call  0xa00dab20
a00caba8:  d8 2a e0 71  stb  %o4, [ %o3 + 0x71 ]	! 0xa802d471
a00cabac:  7f ff b7 48  call  0xa00b88cc
a00cabb0:  01 00 00 00  nop
a00cabb4:  7f ff bf ae  call  0xa00baa6c
a00cabb8:  90 10 00 18  mov  %i0, %o0
a00cabbc:  7f ff bf 65  call  0xa00ba950
a00cabc0:  90 10 00 18  mov  %i0, %o0
a00cabc4:  90 10 00 18  mov  %i0, %o0
a00cabc8:  7f ff bf ee  call  0xa00bab80
a00cabcc:  92 10 20 06  mov  6, %o1
a00cabd0:  10 80 00 08  b  0xa00cabf0
a00cabd4:  82 10 20 00  clr  %g1
a00cabd8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00cabdc:  10 bf ff eb  b  0xa00cab88
a00cabe0:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00cabe4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cabe8:  10 bf ff e8  b  0xa00cab88
a00cabec:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00cabf0:  81 c7 e0 08  ret
a00cabf4:  91 e8 00 01  restore  %g0, %g1, %o0
