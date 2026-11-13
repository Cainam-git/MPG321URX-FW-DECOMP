# leon2m FUN_a0028ff0 0xa0028ff0-0xa0029054 (100 bytes)
a0028ff0:  91 d0 20 00  ta  0
a0028ff4:  01 00 00 00  nop
a0028ff8:  01 00 00 00  nop
a0028ffc:  01 00 00 00  nop
a0029000:  81 d8 20 00  flush  %g0
a0029004:  81 88 20 cf  wr  %g0, 0xcf, %psr
a0029008:  81 90 00 00  mov  %g0, %wim
a002900c:  81 80 00 00  mov  %g0, %y
a0029010:  82 10 20 01  mov  1, %g1
a0029014:  81 90 40 00  mov  %g1, %wim
a0029018:  03 00 00 04  sethi  %hi(0x1000), %g1
a002901c:  82 10 60 e0  or  %g1, 0xe0, %g1	! 0x10e0
a0029020:  81 88 40 00  mov  %g1, %psr
a0029024:  07 2a 00 ff  sethi  %hi(0xa803fc00), %g3
a0029028:  86 10 e3 50  or  %g3, 0x350, %g3	! 0xa803ff50
a002902c:  bc 10 00 03  mov  %g3, %fp
a0029030:  9c 20 e0 60  sub  %g3, 0x60, %sp
a0029034:  03 28 00 a0  sethi  %hi(0xa0028000), %g1
a0029038:  81 98 40 00  mov  %g1, %tbr
a002903c:  01 00 00 00  nop
a0029040:  40 00 01 59  call  0xa00295a4
a0029044:  01 00 00 00  nop
a0029048:  91 d0 20 01  ta  1
a002904c:  10 bf ff ff  b  0xa0029048
a0029050:  01 00 00 00  nop
