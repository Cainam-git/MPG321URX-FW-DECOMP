# leon2s DRV_HDMI_IF_Disconnect 0xa00a1b08-0xa00a1b58 (80 bytes)
a00a1b08:  9d e3 bf 98  save  %sp, -104, %sp
a00a1b0c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00a1b10:  11 28 01 ae  sethi  %hi(0xa006b800), %o0
a00a1b14:  13 28 02 d3  sethi  %hi(0xa00b4c00), %o1
a00a1b18:  9a 5e 21 90  smul  %i0, 0x190, %o5
a00a1b1c:  82 10 63 e0  or  %g1, 0x3e0, %g1
a00a1b20:  90 12 20 00  mov  %o0, %o0
a00a1b24:  92 12 60 38  or  %o1, 0x38, %o1
a00a1b28:  94 10 20 43  mov  0x43, %o2
a00a1b2c:  80 a6 20 02  cmp  %i0, 2
a00a1b30:  12 80 00 05  bne  0xa00a1b44
a00a1b34:  9a 03 40 01  add  %o5, %g1, %o5
a00a1b38:  7f ff 45 43  call  0xa0073044
a00a1b3c:  b0 10 20 16  mov  0x16, %i0
a00a1b40:  30 80 00 04  b,a   0xa00a1b50
a00a1b44:  7f ff ff cf  call  0xa00a1a80
a00a1b48:  c0 2b 60 03  clrb  [ %o5 + 3 ]
a00a1b4c:  b0 10 20 00  clr  %i0
a00a1b50:  81 c7 e0 08  ret
a00a1b54:  81 e8 00 00  restore
