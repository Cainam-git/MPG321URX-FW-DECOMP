/* leon2m FUN_a012e550 @ 0xa012e550-0xa012e6c0 (92 words).
 * Reads one 3-byte colour entry of the FGA colour table in settings storage. r = number of bits of 0x508 below the
 * single bit 'row' (0xff when row is none of 0x008, 0x100, 0x400), c = the same for 'col' against 0x92 (0x002,
 * 0x010, 0x080). When both are valid it reads 3 bytes with FUN_a0140360(dev, addr + fga_off(0x10) + r * 9 + c * 3,
 * 3, rgb) (location fields of the settings record at 0xA802E1A0 and fga_off as in FUN_a012cfac) and returns 1;
 * otherwise returns 0 without a read. Called by FUN_a014c118 and FUN_a014e320.
 * Source form: both counts are written in place and use the same variable c (the first is then copied to r); the
 * validity test is two int flags combined with '&' into an unsigned char ok; the offset r * 9 + c * 3 is an
 * unsigned short local inside the if. Flags -mcpu=v8 -O3 without -g (no nop after the final call).
 */
struct FgaLoc { unsigned char dev; unsigned int addr : 16; unsigned char sel; };
struct Rec1a0 { unsigned char a[0x34]; struct FgaLoc fga; unsigned char rest[0x18]; };
extern struct Rec1a0 DAT_a802e1a0;
extern void FUN_a0140360(unsigned char, unsigned short, unsigned short, void *);

static unsigned short fga_off(unsigned short sub)
{
    unsigned short o;
    if (DAT_a802e1a0.fga.sel <= 1)
        o = 0x120;
    else
        o = 0x240;
    return (o & 0x360) + sub;
}

static unsigned char bit_index(unsigned short bit, unsigned short set)
{
    unsigned char j;
    unsigned char r = 0;

    if (!(bit & set))
        r = 0xff;
    else {
        for (j = 0; (bit >> j) != 1; j++)
            if ((set >> j) & 1)
                r++;
    }
    return r;
}

unsigned char FUN_a012e550(unsigned short row, unsigned short col, unsigned char *rgb)
{
    unsigned char r, c, ok, j;
    int a, b;
    unsigned short pos;

    ok = 0;
    c = 0;
    if (!(row & 0x508))
        c = 0xff;
    else {
        for (j = 0; (row >> j) != 1; j++)
            if ((0x508 >> j) & 1)
                c++;
    }
    r = c;
    c = 0;
    if (!(col & 0x92))
        c = 0xff;
    else {
        for (j = 0; (col >> j) != 1; j++)
            if ((0x92 >> j) & 1)
                c++;
    }
    a = r != 0xff;
    b = c != 0xff;
    if (a & b)
        ok = 1;
    if (ok == 1) {
        pos = r * 9 + c * 3;
        FUN_a0140360(DAT_a802e1a0.fga.dev, DAT_a802e1a0.fga.addr + fga_off(0x10) + pos, 3, rgb);
    }
    return ok;
}
