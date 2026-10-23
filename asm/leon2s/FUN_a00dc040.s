# leon2s FUN_a00dc040 0xa00dc040-0xa00dc078 (56 bytes)
a00dc040:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dc044:  80 8a 20 ff  btst  0xff, %o0
a00dc048:  12 80 00 0a  bne  0xa00dc070
a00dc04c:  d0 28 60 3a  stb  %o0, [ %g1 + 0x3a ]
a00dc050:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00dc054:  c0 28 63 ff  clrb  [ %g1 + 0x3ff ]	! 0xa80787ff
a00dc058:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00dc05c:  c0 28 63 fe  clrb  [ %g1 + 0x3fe ]	! 0xa80787fe
a00dc060:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00dc064:  c0 28 63 fd  clrb  [ %g1 + 0x3fd ]	! 0xa80787fd
a00dc068:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00dc06c:  c0 28 63 fc  clrb  [ %g1 + 0x3fc ]	! 0xa80787fc
a00dc070:  81 c3 e0 08  retl
a00dc074:  01 00 00 00  nop
