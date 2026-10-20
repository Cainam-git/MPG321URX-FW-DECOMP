/* leon2s FUN_a0086030 @ 0xa0086030-0xa0086154 (73 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0/73 mismatches.
 * Code facts: (port, mode, val, n, buf) word params; ch = (u8) port; len = (signed char) n. Through
 * FUN_a00a78fc(ch, reg, byte): reg 0x31 = 0x71; reg 0x30 = (mode & 0xf0) | (val >> 16 & 0xf), then
 * val >> 8 & 0xff, then val & 0xff. mode &= 0xff. mode 0x80 / 0x40 / 0: reg 0x30 = len, then
 * buf[0..len] (u8 i, signed compare, no bytes when len < 0), then reg 0x31 = 0xb (this call re-converts
 * the port param: 'and %i0,0xff'). Other modes: reg 0x30 = len, reg 0x31 = len == 0 ? 3 : 0xb. Then the
 * sibcall FUN_a00b1794(1). void.
 * Fixes vs the autoc draft (78.08, did not compile): a 'signed char len = n' local (fw 'mov %i3,%i2' copy,
 * sll/sra 24 compares, and the loop counter takes %i3); a plain for loop whose rotated entry guard
 * 'len >= 0' is the fw btst 0x80 (an explicit if (!(len & 0x80)) + do/while is predicted the other way
 * and reorg threads the exit branch); the 3/0xb pick in its own else arm. Aids: none.
 */
extern void FUN_a00a78fc(unsigned char, unsigned short, unsigned char);
extern void FUN_a00b1794(unsigned char);

void FUN_a0086030(unsigned int param_1, unsigned int mode, unsigned int val, unsigned int n,
                  unsigned char *buf)
{
    unsigned char ch = param_1;
    unsigned char i;
    signed char len = n;

    FUN_a00a78fc(ch, 0x31, 0x71);
    FUN_a00a78fc(ch, 0x30, (mode & 0xf0) | ((val >> 16) & 0xf));
    FUN_a00a78fc(ch, 0x30, (val >> 8) & 0xff);
    FUN_a00a78fc(ch, 0x30, val & 0xff);
    mode &= 0xff;
    if (mode == 0x80 || mode == 0x40 || mode == 0) {
        FUN_a00a78fc(ch, 0x30, len);
        for (i = 0; i <= len; i++)
            FUN_a00a78fc(ch, 0x30, buf[i]);
        FUN_a00a78fc(param_1 & 0xff, 0x31, 0xb);
    } else {
        FUN_a00a78fc(ch, 0x30, len);
        if (len == 0)
            FUN_a00a78fc(ch, 0x31, 3);
        else
            FUN_a00a78fc(ch, 0x31, 0xb);
    }
    FUN_a00b1794(1);
}
