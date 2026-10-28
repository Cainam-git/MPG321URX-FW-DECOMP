/* leon2m FUN_a012e928 @ 0xa012e928-0xa012eb4c (137 words), -mcpu=v8 -O3 -g.
 * bit = row_bit(m) (0x10 -> 2, 0x11 -> 4, 0x13 -> 0x10, 0x14 -> 0x20, 0x15 -> 0x40, 0x16 -> 0x80, other values -> 1;
 * the switch of FUN_a012e8c0, inlined here as a static copy; jump table 0xccebc). flags bit 0: FUN_a0140360 reads 0x36
 * bytes of device DAT_a802e1a0 byte +0x34 at its 16-bit address +0x35 plus fga_off(0x30) into DAT_a802cb40, where
 * fga_off(s) = (0x120 when byte +0x37 <= 1, else 0x240) + s. n = 0xff when bit has none of bits 0..2 set, else the
 * number of set bits of 7 below the lowest set bit of bit; for n != 0xff the 18 bytes src[0..17] are copied to
 * DAT_a802cb40[n * 18 ..]. flags bit 2: FUN_a0140e74 writes the 0x36 bytes back (last argument 1), then writes the
 * single byte 0x79 from the stack at fga_off(0) (last argument 0), then calls FUN_a01405d0(device). Called by
 * FUN_a0149178.
 * Source form: in the inlined switch the default arm comes first and value 0x12 has no case of its own (it takes
 * the default 1); with an explicit case 0x12 the result gets its own register.
 */
struct FgaLoc { unsigned char dev; unsigned int addr : 16; unsigned char sel; };
struct Rec1a0 { unsigned char a[0x34]; struct FgaLoc fga; unsigned char rest[0x18]; };
extern struct Rec1a0 DAT_a802e1a0;
extern unsigned char DAT_a802cb40[0x36];
extern void FUN_a0140360(unsigned char, unsigned short, unsigned short, void *);
extern void FUN_a0140e74(unsigned char, unsigned short, unsigned short, void *, unsigned char);
extern void FUN_a01405d0(unsigned char);

static unsigned short fga_off(unsigned short sub)
{
    unsigned short o;
    if (DAT_a802e1a0.fga.sel <= 1)
        o = 0x120;
    else
        o = 0x240;
    return (o & 0x360) + sub;
}

static int row_bit(unsigned char v)
{
    unsigned char r;

    switch (v) {
    default:
        r = 1;
        break;
    case 0x10:
        r = 0x2;
        break;
    case 0x11:
        r = 0x4;
        break;
    case 0x13:
        r = 0x10;
        break;
    case 0x14:
        r = 0x20;
        break;
    case 0x15:
        r = 0x40;
        break;
    case 0x16:
        r = 0x80;
        break;
    }
    return r;
}

void FUN_a012e928(unsigned char m, unsigned char *src, unsigned char flags)
{
    unsigned char bit, n, j, k;
    unsigned char mark;

    bit = row_bit(m);
    if (flags & 1)
        FUN_a0140360(DAT_a802e1a0.fga.dev, DAT_a802e1a0.fga.addr + fga_off(0x30), 0x36, DAT_a802cb40);
    n = 0;
    if (!(bit & 7))
        n = 0xff;
    else {
        for (j = 0; (bit >> j) != 1; j++)
            if ((7 >> j) & 1)
                n++;
    }
    if (n != 0xff)
        for (k = 0; k < 18; k++)
            DAT_a802cb40[n * 18 + k] = src[k];
    if (flags & 4) {
        mark = 0x79;
        FUN_a0140e74(DAT_a802e1a0.fga.dev, DAT_a802e1a0.fga.addr + fga_off(0x30), 0x36, DAT_a802cb40, 1);
        FUN_a0140e74(DAT_a802e1a0.fga.dev, DAT_a802e1a0.fga.addr + fga_off(0), 1, &mark, 0);
        FUN_a01405d0(DAT_a802e1a0.fga.dev);
    }
}
