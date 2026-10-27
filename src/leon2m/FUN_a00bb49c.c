/* FUN_a00bb49c (leon2m 0xa00bb49c-0xa00bb4e8, 76 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores the six bytes 0x35, 0x36, 0x30, 0x30, 0x2d, 0x0d to DAT_a802d128[0..5] and calls FUN_a01487e8(c, 6,
 * DAT_a802d128) as a tail call. Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a00bb454 and FUN_a00bb4e8.
 */
extern unsigned char DAT_a802d128[];
extern void FUN_a01487e8(unsigned char, int, unsigned char *);

void FUN_a00bb49c(unsigned char c)
{
    DAT_a802d128[0] = 0x35;
    DAT_a802d128[1] = 0x36;
    DAT_a802d128[2] = 0x30;
    DAT_a802d128[3] = 0x30;
    DAT_a802d128[4] = 0x2d;
    DAT_a802d128[5] = 0xd;
    FUN_a01487e8(c, 6, DAT_a802d128);
}
