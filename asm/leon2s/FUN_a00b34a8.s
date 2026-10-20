# leon2s FUN_a00b34a8 0xa00b34a8-0xa00b3530 (136 bytes)
a00b34a8:  9d e3 bf 98  save  %sp, -104, %sp
a00b34ac:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b34b0:  c0 28 62 c4  clrb  [ %g1 + 0x2c4 ]	! 0xa807dec4
a00b34b4:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b34b8:  c0 20 62 ac  clr  [ %g1 + 0x2ac ]	! 0xa807deac
a00b34bc:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b34c0:  c0 28 62 a8  clrb  [ %g1 + 0x2a8 ]	! 0xa807dea8
a00b34c4:  03 2a 01 f8  sethi  %hi(0xa807e000), %g1
a00b34c8:  c0 28 60 b0  clrb  [ %g1 + 0xb0 ]	! 0xa807e0b0
a00b34cc:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b34d0:  c0 28 62 b0  clrb  [ %g1 + 0x2b0 ]	! 0xa807deb0
a00b34d4:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b34d8:  82 10 63 f0  or  %g1, 0x3f0, %g1	! 0xa807dff0
a00b34dc:  98 10 20 00  clr  %o4
a00b34e0:  9a 10 20 00  clr  %o5
a00b34e4:  c0 28 40 0d  clrb  [ %g1 + %o5 ]
a00b34e8:  9a 03 60 01  inc  %o5
a00b34ec:  80 a3 60 1f  cmp  %o5, 0x1f
a00b34f0:  24 bf ff fe  ble,a   0xa00b34e8
a00b34f4:  c0 28 40 0d  clrb  [ %g1 + %o5 ]
a00b34f8:  98 03 20 01  inc  %o4
a00b34fc:  80 a3 20 04  cmp  %o4, 4
a00b3500:  04 bf ff f8  ble  0xa00b34e0
a00b3504:  82 00 60 20  add  %g1, 0x20, %g1
a00b3508:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00b350c:  7f fe b7 5d  call  0xa0061280
a00b3510:  90 12 22 f8  or  %o0, 0x2f8, %o0	! 0xa006c6f8
a00b3514:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00b3518:  90 12 23 28  or  %o0, 0x328, %o0	! 0xa006c728
a00b351c:  7f fe b7 59  call  0xa0061280
a00b3520:  31 28 01 b1  sethi  %hi(0xa006c400), %i0
a00b3524:  7f fe b7 57  call  0xa0061280
a00b3528:  91 ee 23 58  restore  %i0, 0x358, %o0
a00b352c:  01 00 00 00  nop
