/* leon2m FUN_a012e3ec @ 0xa012e3ec-0xa012e550 (89 words).
 * Reads one FGA table block from settings storage into a zeroed 0xc0-byte buffer and passes it on. The block
 * index n is the number of bits of 0x508 below the single bit 'bit' (0xff when bit is not one of 0x008, 0x100,
 * 0x400); the read is FUN_a0140360(dev, addr + n * 0x60, len, buf) with the location fields of the settings record
 * at 0xA802E1A0 (dev +0x34, addr +0x35..0x36, sel +0x37). len = 0xc0 and flag 1 when bit has 0x200 set, else
 * len = 0x60 with flag 1 when sel == 1, else flag 0. An empty nested loop of (len >> 4) x 16 passes follows. Then
 * FUN_a012e2ac(buf, flag) when sel == 1, else FUN_a012e004(buf, flag). Called by FUN_a012eeb0.
 * Source form: the index count is an inlined static helper with an unsigned char result (0xff for no match); the
 * offset n * 0x60 is computed into an unsigned short local before the length choice.
 */
struct FgaLoc { unsigned char dev; unsigned int addr : 16; unsigned char sel; };
struct Rec1a0 { unsigned char a[0x34]; struct FgaLoc fga; unsigned char rest[0x18]; };
extern struct Rec1a0 DAT_a802e1a0;
extern void *memset(void *, int, unsigned int);
extern void FUN_a0140360(unsigned char, unsigned short, unsigned short, void *);
extern void FUN_a012e2ac(unsigned char *, unsigned char);
extern void FUN_a012e004(unsigned char *, unsigned char);

static unsigned char tbl_index(unsigned short bit)
{
    unsigned char j;
    unsigned char r = 0;

    if (!(bit & 0x508))
        r = 0xff;
    else {
        for (j = 0; (bit >> j) != 1; j++)
            if ((0x508 >> j) & 1)
                r++;
    }
    return r;
}

void FUN_a012e3ec(unsigned int bit)
{
    unsigned char buf[0xc0];
    unsigned char k, m, len;
    unsigned short off;
    unsigned char two;

    memset(buf, 0, sizeof(buf));
    two = 0;
    len = 0x60;
    off = tbl_index(bit) * 0x60;
    if (bit & 0x200) {
        len = 0xc0;
        two = 1;
    } else if (DAT_a802e1a0.fga.sel == 1) {
        len = 0x60;
        two = 1;
    }
    FUN_a0140360(DAT_a802e1a0.fga.dev, DAT_a802e1a0.fga.addr + off, len, buf);
    for (k = 0; k < (len >> 4); k++)
        for (m = 0; m < 16; m++)
            ;
    if (DAT_a802e1a0.fga.sel == 1)
        FUN_a012e2ac(buf, two);
    else
        FUN_a012e004(buf, two);
}
