/* FUN_a00baa20 (leon2m 0xa00baa20-0xa00baa6c, 76 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores the six bytes 0x35, 0x36, 0x30, 0x30, 0x2d, 0x0d to DAT_a802d078[0..5] and calls FUN_a01487e8(c, 6,
 * DAT_a802d078) as a tail call. Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a00ba9d8 and FUN_a00baa6c.
 */
extern unsigned char DAT_a802d078[];
extern void FUN_a01487e8(unsigned char, int, unsigned char *);

void FUN_a00baa20(unsigned char c)
{
    DAT_a802d078[0] = 0x35;
    DAT_a802d078[1] = 0x36;
    DAT_a802d078[2] = 0x30;
    DAT_a802d078[3] = 0x30;
    DAT_a802d078[4] = 0x2d;
    DAT_a802d078[5] = 0xd;
    FUN_a01487e8(c, 6, DAT_a802d078);
}
