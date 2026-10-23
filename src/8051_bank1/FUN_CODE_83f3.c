/* 8051_bank1 FUN_CODE_83f3 @ 0x83f3..0x8512 (287 bytes), OPTIMIZE(8,SPEED) LARGE.
 * FUN_CODE_83f3(ch, ctl, reg, buf, n): ok = 1; XDATA 0xF00A = 0x55; p = one register of channel ch (0..5: XDATA
 * 0xF03B, 0xF043, 0xF08B, 0xF093, 0xF09D, 0xF0BA; any other ch leaves p 0); a[0] = low byte of reg; *p = 0;
 * ok &= FUN_CODE_482e(ch, ctl, 1, a); ok &= FUN_CODE_3c4d(ch, ctl, n, buf); *p = 0xF8; returns ok (carry).
 * Same channel register blocks as the module FUN_CODE_482e.
 * LARGE slots: ch 0xA4A9, ctl 0xA4AA, reg 0xA4AB, buf 0xA4AD, n 0xA4B0, a 0xA4B2 (2 bytes), p 0xA4B4; ok = bit
 * 0x00. The initialised local array a is copied with ?C?COPY from its 2-byte initializer at CODE 0xDD61 (00 00).
 */
extern unsigned char volatile xdata DAT_EXTMEM_f00a;
bit FUN_CODE_482e(unsigned char ch, unsigned char ctl, unsigned int n, unsigned char *buf);
bit FUN_CODE_3c4d(unsigned char ch, unsigned char ctl, unsigned int n, unsigned char *buf);

bit FUN_CODE_83f3(unsigned char ch, unsigned char ctl, unsigned int reg, unsigned char *buf, unsigned int n)
{
    bit ok = 1;
    unsigned char a[2] = {0, 0};
    unsigned char *p = 0;

    DAT_EXTMEM_f00a = 0x55;
    switch (ch) {
    case 0: p = (unsigned char xdata *)0xf03b; break;
    case 1: p = (unsigned char xdata *)0xf043; break;
    case 2: p = (unsigned char xdata *)0xf08b; break;
    case 3: p = (unsigned char xdata *)0xf093; break;
    case 4: p = (unsigned char xdata *)0xf09d; break;
    case 5: p = (unsigned char xdata *)0xf0ba; break;
    }
    a[0] = reg;
    *p = 0;
    ok &= FUN_CODE_482e(ch, ctl, 1, a);
    ok &= FUN_CODE_3c4d(ch, ctl, n, buf);
    *p = 0xf8;
    return ok;
}
