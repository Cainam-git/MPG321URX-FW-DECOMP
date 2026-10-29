/* leon2s FUN_a009c09c @ 0xa009c09c-0xa009c188 (-mcpu=v8 -Os -g)
 * p = arg & 0xff. If byte 0x2d of the 0x190-byte record p at 0xa807d7e0 is 0: v = low half of word 0x3c of
 * the register block ARR_a807db00[p].r0. Otherwise, with words w54/w58/w4c at offsets 0x54/0x58/0x4c of the
 * block ARR_a807db00[p].r20: v = w58 >> 16 when that is non-zero, else sh = DAT_a80790a8[p],
 * d = (u16)((w54 >> 2) << sh) and v = ((w4c << sh) + (d >> 1)) / d when both w4c << sh and d are non-zero,
 * 0 otherwise (w4c is read twice). Returns v as an unsigned short, or 1 when v is 0.
 * Source form: one if with '&&' for the two non-zero tests and a single 'v = 0' else arm.
 */
struct Port34 {
    volatile unsigned int *r0;
    unsigned char pad4[0x1c];
    volatile unsigned int *r20;
    unsigned char rest[0x34 - 0x24];
};
extern struct Port34 ARR_a807db00[];
extern unsigned char ARR_a807d7e0[];
extern unsigned char DAT_a80790a8[];

unsigned short FUN_a009c09c(unsigned char p)
{
    unsigned short v;
    unsigned short d;
    unsigned char sh;
    volatile unsigned int *regs;

    if (ARR_a807d7e0[p * 400 + 0x2d]) {
        regs = ARR_a807db00[p].r20;
        if (regs[0x58 / 4] >> 16)
            v = regs[0x58 / 4] >> 16;
        else {
            sh = DAT_a80790a8[p];
            d = (regs[0x54 / 4] >> 2) << sh;
            if ((regs[0x4c / 4] << sh) != 0 && d != 0)
                v = ((regs[0x4c / 4] << sh) + (d >> 1)) / d;
            else
                v = 0;
        }
    } else
        v = ARR_a807db00[p].r0[0x3c / 4];

    if (v == 0)
        return 1;
    return v;
}
