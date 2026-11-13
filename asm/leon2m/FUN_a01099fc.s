# leon2m FUN_a01099fc 0xa01099fc-0xa0109ad0 (212 bytes)  [FUN_a0109ac8 = unreachable ret/restore tail, merged]
a01099fc:  9d e3 bf 98  save  %sp, -104, %sp
a0109a00:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0109a04:  80 a6 20 01  cmp  %i0, 1
a0109a08:  02 80 00 0a  be  0xa0109a30
a0109a0c:  83 2e 60 10  sll  %i1, 0x10, %g1
a0109a10:  04 80 00 1b  ble  0xa0109a7c
a0109a14:  80 a6 20 02  cmp  %i0, 2
a0109a18:  02 80 00 0f  be  0xa0109a54
a0109a1c:  80 a6 20 03  cmp  %i0, 3
a0109a20:  12 80 00 29  bne  0xa0109ac4
a0109a24:  95 2e 60 10  sll  %i1, 0x10, %o2
a0109a28:  10 80 00 1f  b  0xa0109aa4
a0109a2c:  31 33 c0 47  sethi  %hi(0xcf011c00), %i0
a0109a30:  31 33 c0 47  sethi  %hi(0xcf011c00), %i0
a0109a34:  90 16 21 f0  or  %i0, 0x1f0, %o0	! 0xcf011df0
a0109a38:  7f ff a5 95  call  0xa00f308c
a0109a3c:  93 30 60 10  srl  %g1, 0x10, %o1
a0109a40:  b3 2e a0 10  sll  %i2, 0x10, %i1
a0109a44:  b0 16 21 f8  or  %i0, 0x1f8, %i0
a0109a48:  b3 36 60 10  srl  %i1, 0x10, %i1
a0109a4c:  7f ff a5 90  call  0xa00f308c
a0109a50:  81 e8 00 00  restore
a0109a54:  91 2e 60 10  sll  %i1, 0x10, %o0
a0109a58:  31 33 c0 47  sethi  %hi(0xcf011c00), %i0
a0109a5c:  93 32 20 10  srl  %o0, 0x10, %o1
a0109a60:  90 16 22 00  or  %i0, 0x200, %o0
a0109a64:  7f ff a5 8a  call  0xa00f308c
a0109a68:  b3 2e a0 10  sll  %i2, 0x10, %i1
a0109a6c:  b0 16 22 08  or  %i0, 0x208, %i0
a0109a70:  b3 36 60 10  srl  %i1, 0x10, %i1
a0109a74:  7f ff a5 86  call  0xa00f308c
a0109a78:  81 e8 00 00  restore
a0109a7c:  80 a6 20 00  cmp  %i0, 0
a0109a80:  12 80 00 11  bne  0xa0109ac4
a0109a84:  93 2e 60 10  sll  %i1, 0x10, %o1
a0109a88:  31 33 c0 47  sethi  %hi(0xcf011c00), %i0
a0109a8c:  90 16 21 e0  or  %i0, 0x1e0, %o0	! 0xcf011de0
a0109a90:  7f ff a5 7f  call  0xa00f308c
a0109a94:  93 32 60 10  srl  %o1, 0x10, %o1
a0109a98:  b3 2e a0 10  sll  %i2, 0x10, %i1
a0109a9c:  10 bf ff eb  b  0xa0109a48
a0109aa0:  b0 16 21 e8  or  %i0, 0x1e8, %i0
a0109aa4:  90 16 22 10  or  %i0, 0x210, %o0
a0109aa8:  93 32 a0 10  srl  %o2, 0x10, %o1
a0109aac:  7f ff a5 78  call  0xa00f308c
a0109ab0:  b3 2e a0 10  sll  %i2, 0x10, %i1
a0109ab4:  b0 16 22 18  or  %i0, 0x218, %i0
a0109ab8:  b3 36 60 10  srl  %i1, 0x10, %i1
a0109abc:  7f ff a5 74  call  0xa00f308c
a0109ac0:  81 e8 00 00  restore
a0109ac4:  01 00 00 00  nop
a0109ac8:  81 c7 e0 08  ret
a0109acc:  81 e8 00 00  restore
