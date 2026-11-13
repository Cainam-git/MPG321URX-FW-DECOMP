# leon2m FUN_a0095020 0xa0095020-0xa00950a8 (136 bytes)
a0095020:  9d e3 bf 98  save  %sp, -104, %sp
a0095024:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a0095028:  a0 13 62 90  or  %o5, 0x290, %l0	! 0xa802d290
a009502c:  e2 04 20 30  ld  [ %l0 + 0x30 ], %l1
a0095030:  94 0c 7f 0f  and  %l1, -241, %o2
a0095034:  9f 34 60 04  srl  %l1, 4, %o7
a0095038:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a009503c:  d6 0c 60 55  ldub  [ %l1 + 0x55 ], %o3	! 0xa8025c55
a0095040:  92 0a e0 0f  and  %o3, 0xf, %o1
a0095044:  91 2a 60 04  sll  %o1, 4, %o0
a0095048:  9a 0b e0 0f  and  %o7, 0xf, %o5
a009504c:  94 12 80 08  or  %o2, %o0, %o2
a0095050:  98 10 20 0f  mov  0xf, %o4
a0095054:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a0095058:  d8 28 60 8f  stb  %o4, [ %g1 + 0x8f ]	! 0xa802b08f
a009505c:  80 a2 c0 0d  cmp  %o3, %o5
a0095060:  02 80 00 04  be  0xa0095070
a0095064:  90 10 20 01  mov  1, %o0
a0095068:  40 01 0a 82  call  0xa00d7a70
a009506c:  d4 24 20 30  st  %o2, [ %l0 + 0x30 ]
a0095070:  40 00 4f 06  call  0xa00a8c88
a0095074:  01 00 00 00  nop
a0095078:  40 00 4d 9c  call  0xa00a86e8
a009507c:  01 00 00 00  nop
a0095080:  82 10 20 7c  mov  0x7c, %g1	! 0x7c
a0095084:  19 2a 00 ab  sethi  %hi(0xa802ac00), %o4
a0095088:  c2 23 23 ec  st  %g1, [ %o4 + 0x3ec ]	! 0xa802afec
a009508c:  90 10 20 02  mov  2, %o0
a0095090:  40 00 51 70  call  0xa00a9650
a0095094:  92 10 20 01  mov  1, %o1
a0095098:  d6 0c 21 a4  ldub  [ %l0 + 0x1a4 ], %o3
a009509c:  d6 2c 60 55  stb  %o3, [ %l1 + 0x55 ]
a00950a0:  81 c7 e0 08  ret
a00950a4:  81 e8 00 00  restore
