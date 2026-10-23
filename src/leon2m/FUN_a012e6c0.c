/* leon2m FUN_a012e6c0 @ 0xa012e6c0-0xa012e82c (91 words).
 * Reads one 18-byte row of the FGA tables from settings storage into a zeroed local row: n = number of bits of 7
 * below the single bit 'bit' (0xff when bit is none of 1, 2, 4); FUN_a0140360(dev, addr + fga_off(0x30) + n * 18,
 * 0x12, row) with the location fields of the settings record at 0xA802E1A0 (fga_off as in FUN_a012cfac). The row
 * is unpacked into three groups of four halfwords: bytes 6i..6i+5 as three little-endian halfwords and 0x80 as the
 * fourth; then FUN_a00f6fe4(1, 1, groups, 0xff). Called by FUN_a014c118.
 * Source form: the offset n * 18 is an unsigned short local; row is declared before the group array (frame
 * layout).
 */
struct FgaLoc { unsigned char dev; unsigned int addr : 16; unsigned char sel; };
struct Rec1a0 { unsigned char a[0x34]; struct FgaLoc fga; unsigned char rest[0x18]; };
extern struct Rec1a0 DAT_a802e1a0;
extern void FUN_a0140360(unsigned char, unsigned short, unsigned short, void *);
extern void FUN_a00f6fe4(unsigned char, unsigned char, unsigned short *, int);

static unsigned short fga_off(unsigned short sub)
{
    unsigned short o;
    if (DAT_a802e1a0.fga.sel <= 1)
        o = 0x120;
    else
        o = 0x240;
    return (o & 0x360) + sub;
}

void FUN_a012e6c0(unsigned char bit)
{
    unsigned char row[18] = { 0 };
    unsigned short out[3][4];
    unsigned char n, j, i;
    unsigned short off;

    n = 0;
    if (!(bit & 7))
        n = 0xff;
    else {
        for (j = 0; (bit >> j) != 1; j++)
            if ((7 >> j) & 1)
                n++;
    }
    off = n * 18;
    FUN_a0140360(DAT_a802e1a0.fga.dev, DAT_a802e1a0.fga.addr + fga_off(0x30) + off, 0x12, row);
    for (i = 0; i < 3; i++) {
        out[i][0] = row[i * 6] | (row[i * 6 + 1] << 8);
        out[i][1] = row[i * 6 + 2] | (row[i * 6 + 3] << 8);
        out[i][2] = row[i * 6 + 4] | (row[i * 6 + 5] << 8);
        out[i][3] = 0x80;
    }
    FUN_a00f6fe4(1, 1, out[0], 0xff);
}
