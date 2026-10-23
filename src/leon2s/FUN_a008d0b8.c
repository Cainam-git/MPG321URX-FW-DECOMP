/* FUN_a008d0b8 (leon2s 0xa008d0b8-0xa008d1d8, 288 bytes), flags -mcpu=v8 -Os -g.
 * Reads indexed words through the hardware registers 0xcf012240 (address low byte), 0xcf012244 (address high
 * byte) and 0xcf012200 (data), with the static helper rd() inlined at every use. base = 0 and row hi = 0 for
 * v <= 0x7ff, else base = 0x800 and hi = 1. Returns 0 when bits 0xa0 of rd(base) are not both set. Otherwise
 * stores n = rd(base) & 0xf in DAT_a8078c02 and, for i = 0 .. n - 1, writes rd(i * 3 + base + 2) |
 * (rd(i * 3 + base + 3) << 8) | base to the halfword table DAT_a807d252[hi][i] (rows of 10 entries, the
 * table FUN_a008d1d8 searches); returns 1. volatile only on the hardware registers.
 * Source form: n is an unsigned short and the table value goes through an unsigned short local.
 */
#define REG_cf012200 (*(volatile unsigned int *)0xcf012200)
#define REG_cf012240 (*(volatile unsigned int *)0xcf012240)
#define REG_cf012244 (*(volatile unsigned int *)0xcf012244)
extern unsigned char DAT_a8078c02;
extern unsigned short DAT_a807d252[][10];

static inline unsigned int rd(unsigned short a)
{
    REG_cf012240 = (unsigned char)a;
    REG_cf012244 = (unsigned char)(a >> 8);
    return REG_cf012200;
}

int FUN_a008d0b8(unsigned short v)
{
    unsigned short base;
    unsigned char hi;
    unsigned int w;
    unsigned short n;
    unsigned char i;
    unsigned int lo;
    unsigned short val;

    if (v <= 0x7ff) {
        base = 0;
        hi = 0;
    } else {
        base = 0x800;
        hi = 1;
    }
    w = rd(base);
    if ((w & 0xa0) != 0xa0)
        return 0;
    n = w & 0xf;
    DAT_a8078c02 = n;
    for (i = 0; i < n; i++) {
        lo = rd(i * 3 + base + 2);
        val = lo | (rd(i * 3 + base + 3) << 8) | base;
        DAT_a807d252[hi][i] = val;
    }
    return 1;
}
